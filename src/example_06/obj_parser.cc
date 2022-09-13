// Copyright 2022 The Dusk Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "src/example_06/obj_parser.h"

#include <charconv>
#include <sstream>

namespace dusk::obj {
namespace {

bool IsLineEnd(char c) {
  return c == '\n';
}

bool IsSeparator(char c) {
  return c == ' ' || c == '\t' || c == '\r' || IsLineEnd(c);
}

}  // namespace

Group::Group(const std::string_view& name) : name_(name) {}

Group::Group(Group&&) = default;

Group::~Group() = default;

Group& Group::operator=(Group&&) = default;

Mesh::Mesh() {
  groups_.emplace_back(Group("default"));
}

Mesh::Mesh(Mesh&&) = default;

Mesh::~Mesh() = default;

Mesh& Mesh::operator=(Mesh&&) = default;

std::string Parser::Token::to_string() const {
  switch (type) {
    case Token::Type::kError:
      return "Error";
    case Token::Type::kEof:
      return "End of File";
    case Token::Type::kEol:
      return "End of line";
    case Token::Type::kNumeric:
      return "Numeric (" + std::to_string(value.f) + ")";
    case Token::Type::kString:
      return "String (" + std::string(value.s) + ")";
  }
}

Parser::Parser(const std::string_view& data, Options options)
    : data_(data), options_(options) {}

Parser::~Parser() = default;

std::string Parser::ErrorString() const {
  std::stringstream s;
  for (const auto& e : errors_) {
    s << e.line << ":" << e.column << ": " << e.msg << "\n";
  }
  return s.str();
}

std::optional<Mesh> Parser::Parse() {
  if (data_.empty()) {
    return Mesh{};
  }

  mesh_ = {};
  while (!IsEof()) {
    auto tok = Next();

    std::cerr << tok.to_string() << std::endl;

    if (tok.IsEof()) {
      break;
    }

    if (tok.IsError()) {
      AddError(tok, "Error when parsing token");
      break;
    }
    if (!tok.IsString()) {
      AddError(tok, "Expected starting token, got '" + tok.to_string() + "'");
      Resync();
      continue;
    }

    auto val = tok.String();
    if (val == "v") {
      if (!ParseGeometricVertex()) {
        Resync();
      }
    } else {
      AddError(tok, "Unhandled token: " + tok.to_string());
      Resync();
    }
  }

  return {std::move(mesh_)};
}

// This will always return a vertex. The parser attempts to continue after
// an error by finding the next newline, but that requires the vertex to have
// been added to the list to keep indexes correct when specifying faces and
// other things.
bool Parser::ParseGeometricVertex() {
  auto comp = [this](const std::string& name) -> std::optional<float> {
    auto v = Next();
    if (v.IsError() || v.IsEol()) {
      AddError(v, "Missing " + name + " component for 'v'. Expected 'v x y z w' where w is optional.");
      return std::nullopt;
    }
    if (!v.IsNumeric()) {
      AddError(v, "Invalid " + name + " component for 'v'. Expected number, got '" + v.to_string() + "'");
      return 0.f;
    }
    return v.Float();
  };

  float xv = 0.f;
  float yv = 0.f;
  float zv = 0.f;
  float wv = 1.f;

  bool ret = true;

  auto x = comp("x");
  if (x.has_value()) {
    xv = x.value();

    auto y = comp("y");
    if (y.has_value()) {
      yv = y.value();

      auto z = comp("z");
      if (z.has_value()) {
        zv = z.value();

        std::optional<float> w = 1.f;
        if (!IsEol()) {
          w = comp("w");
          if (w.has_value()) {
            wv = w.value();
          } else {
            ret = false;
          }
        }
      } else {
        ret = false;
      }
    } else {
      ret = false;
    }
  } else {
    ret = false;
  }
  mesh_.GeometricVertices().push_back(Vec4{xv, yv, zv, wv});
  return ret;
}

void Parser::SkipCommentsAndWhitespace() {
  while(position_ < data_.size()) {
    // Comment, skip to end of line
    if (data_[position_] == '#') {
      while (data_[position_] != '\n') {
        ++position_;
        ++column_;
      }
      continue;
    }

    // Skip continuation character, will be handled in the separator code below
    if (position_ + 1 < data_.size() && data_[position_] == '\\' &&
        data_[position_ + 1] == '\n') {
      ++position_;
      ++column_;
    }

    // Skip separator characters
    if (IsSeparator(data_[position_])) {
      if (data_[position_] == '\n') {
        // If the newline was a continuation we want to skip over it and
        // keep looking.
        if (position_ > 0 && data_[position_ - 1] != '\\') {
          break;
        }

        column_ = 1;
        ++line_;
      }
      ++position_;
      ++column_;

      continue;
    }
    break;
  }
}

// Skips to the end of the current line as the file is line oriented.
void Parser::Resync() {
  if (IsEol()) {
    return;
  }

  auto tok = Next();
  while (!tok.IsError() && !tok.IsEol() && !tok.IsEof()) {
    std::cerr << "RESYNC: " << tok.to_string() << std::endl;
    tok = Next();
  }
}

Parser::Token Parser::Next() {
  // End of string, no more tokens to parse
  if (IsEof()) {
    return Token{
      .type = Token::Type::kEof,
      .line = line_,
      .column = column_,
    };
  }

  if (last_was_eol_) {
    ++line_;
    column_ = 1;
    last_was_eol_ = false;
  }

  SkipCommentsAndWhitespace();

  size_t start_line = line_;
  size_t start_column = column_;

  if (data_[position_] == '\n') {
    ++position_;
    last_was_eol_ = true;
    return Token{
      .type = Token::Type::kEol,
      .line = start_line,
      .column = start_column,
    };
  }

  size_t start_idx = position_;
  bool is_numeric = true;
  while(!IsEof()) {
    if (IsSeparator(data_[position_])) {
      break;
    }

    if (!std::isdigit(data_[position_]) && data_[position_] != '-' &&
        data_[position_] != '.') {
      is_numeric = false;
    }
    ++position_;
    ++column_;
  }

  if (is_numeric) {
    float result{};
    auto [ptr, ec ] = std::from_chars(data_.data() + start_idx, data_.data() + position_, result);
    if (ec != std::errc()) {
      auto segment = std::string_view(data_.data() + start_idx, position_ - start_idx);
      AddError(start_line, start_column, "Attempt to parse string to float. Source '" + std::string(segment) + "'");
      return Token{
        .type = Token::Type::kError,
        .line = start_line,
        .column = start_column,
      };
    }
    return Token{
      .type = Token::Type::kNumeric,
      .value = {
        .f = result,
      },
      .line = start_line,
      .column = start_column,
    };
  }

  return Token{
    .type = Token::Type::kString,
    .value = {
      .s = std::string_view{data_.data() + start_idx, position_ - start_idx},
    },
    .line = start_line,
    .column = start_column,
  };
}

bool Parser::IsEol() const {
  if (IsEof()) {
    return true;
  }

  size_t idx = position_;
  while (idx < data_.size()) {
    if (idx == '#') {
      return true;
    }
    if (!IsSeparator(data_[idx])) {
      return false;
    }
    if (IsLineEnd(data_[idx])) {
      return true;
    }
    ++idx;
  }
  return true;
}

}  // namespace dusk::obj

