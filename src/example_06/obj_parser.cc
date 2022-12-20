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
    s << e.line << ":" << e.column << ": " << e.msg << "\n\n";
  }
  return s.str();
}

std::string Parser::WarningString() const {
  std::stringstream s;
  for (const auto& w : warnings_) {
    s << w.line << ":" << w.column << ": " << w.msg << "\n\n";
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
    if (tok.IsEof()) {
      break;
    }
    if (tok.IsEol()) {
      continue;
    }

    if (tok.IsError()) {
      AddError(tok, "Error when parsing token");
      break;
    }
    if (!tok.IsString()) {
      AddError(tok, "Expected starting token, got " + tok.to_string());
      Resync();
      continue;
    }

    auto val = tok.String();
    if (val == "v") {
      if (!ParseGeometricVertex()) {
        Resync();
      }
    } else if (val == "vn") {
      if (!ParseVertexNormal()) {
        Resync();
      }
    } else if (val == "vt") {
      if (!ParseTextureVertex()) {
        Resync();
      }
    } else if (val == "g" || val == "o") {
      // Ignore group and object statements. Don't seem to be involved in
      // rendering.
      AddWarning(tok, "Skipping '" + val + "' statement");
      Resync();
    } else {
      AddWarning(tok, "Unhandled command: " + std::string(val) + ". Skipping.");
      Resync();
    }
  }

  return {std::move(mesh_)};
}

std::optional<float> Parser::ParseNumber(const std::string& command_name,
                                         const std::string& component_name,
                                         const std::string& command_format) {
  if (IsEol()) {
    AddError("Found the end of the line, expected the " + component_name +
             " component for '" + command_name + "'.\n" + "    Format is " +
             command_format + ".\n" +
             "    Lines may be continued by adding a \\ before the newline.");
    return std::nullopt;
  }

  auto v = Next();
  if (v.IsError() || v.IsEol()) {
    AddError(v, "Missing " + component_name + " component for '" +
                    command_name + "'.\n" + "    Format is " + command_format +
                    ".");
    return std::nullopt;
  }
  if (!v.IsNumeric()) {
    AddError(v, "Invalid " + component_name + " component for '" +
                    command_name + "'.\n" + "    Expected number, got " +
                    v.to_string() + ".");
    return 0.f;
  }
  return v.Float();
}

// This will always return a vertex. The parser attempts to continue after
// an error by finding the next newline, but that requires the vertex to have
// been added to the list to keep indexes correct when specifying faces and
// other things.
bool Parser::ParseGeometricVertex() {
  float xv = 0.f;
  float yv = 0.f;
  float zv = 0.f;
  float wv = 1.f;

  bool ret = true;

  static const auto fmt =
      "'v x y z w' where w is optional with default value of 1";
  static const auto cmd = "v";

  auto x = ParseNumber(cmd, "x", fmt);
  if (x.has_value()) {
    xv = x.value();

    auto y = ParseNumber(cmd, "y", fmt);
    if (y.has_value()) {
      yv = y.value();

      auto z = ParseNumber(cmd, "z", fmt);
      if (z.has_value()) {
        zv = z.value();

        std::optional<float> w = 1.f;
        if (!IsEol()) {
          w = ParseNumber(cmd, "w", fmt);
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

// This will always return a normal. The parser attempts to continue after
// an error by finding the next newline, but that requires the normal to have
// been added to the list to keep indexes correct when specifying faces and
// other things.
bool Parser::ParseVertexNormal() {
  float iv = 0.f;
  float jv = 0.f;
  float kv = 0.f;

  bool ret = true;

  static const auto fmt = "'vn i j k'";
  static const auto cmd = "vn";

  auto i = ParseNumber(cmd, "i", fmt);
  if (i.has_value()) {
    iv = i.value();

    auto j = ParseNumber(cmd, "j", fmt);
    if (j.has_value()) {
      jv = j.value();

      auto k = ParseNumber(cmd, "k", fmt);
      if (k.has_value()) {
        kv = k.value();
      } else {
        ret = false;
      }
    } else {
      ret = false;
    }
  } else {
    ret = false;
  }
  mesh_.VertexNormals().push_back(Vec3{iv, jv, kv});
  return ret;
}

// This will always return a texture vertex. The parser attempts to continue
// after an error by finding the next newline, but that requires the texture
// vertex to have been added to the list to keep indexes correct when
// specifying faces and other things.
bool Parser::ParseTextureVertex() {
  float uv = 0.f;
  float vv = 0.f;
  float wv = 0.f;

  bool ret = true;

  static const auto fmt =
      "'vt u v w' where v and w are optional with default values of 0";
  static const auto cmd = "vt";

  auto u = ParseNumber(cmd, "u", fmt);
  if (u.has_value()) {
    uv = u.value();

    std::optional<float> v = 0.f;
    if (!IsEol()) {
      v = ParseNumber(cmd, "v", fmt);
      if (v.has_value()) {
        vv = v.value();

        std::optional<float> w = 0.f;
        if (!IsEol()) {
          w = ParseNumber(cmd, "w", fmt);
          if (w.has_value()) {
            wv = w.value();
          } else {
            ret = false;
          }
        }
      }
    } else {
      ret = false;
    }
  } else {
    ret = false;
  }
  mesh_.TextureVertices().push_back(Vec3{uv, vv, wv});
  return ret;
}

void Parser::SkipCommentsAndWhitespace() {
  while (position_ < data_.size()) {
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
  auto tok = Next();
  while (!tok.IsError() && !tok.IsEol() && !tok.IsEof()) {
    tok = Next();
  }
}

Parser::Token Parser::Next() {
  if (last_was_eol_) {
    ++line_;
    column_ = 1;
    last_was_eol_ = false;
  }

  SkipCommentsAndWhitespace();

  // End of string, no more tokens to parse
  if (IsEof()) {
    return Token{
        .type = Token::Type::kEof,
        .line = line_,
        .column = column_,
    };
  }

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
  while (!IsEof()) {
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
    auto [ptr, ec] = std::from_chars(data_.data() + start_idx,
                                     data_.data() + position_, result);
    if (ec != std::errc()) {
      auto segment =
          std::string_view(data_.data() + start_idx, position_ - start_idx);
      AddError(start_line, start_column,
               "Attempt to parse string to float. Source '" +
                   std::string(segment) + "'");
      return Token{
          .type = Token::Type::kError,
          .line = start_line,
          .column = start_column,
      };
    }
    return Token{
        .type = Token::Type::kNumeric,
        .value =
            {
                .f = result,
            },
        .line = start_line,
        .column = start_column,
    };
  }

  return Token{
      .type = Token::Type::kString,
      .value =
          {
              .s = std::string_view{data_.data() + start_idx,
                                    position_ - start_idx},
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
