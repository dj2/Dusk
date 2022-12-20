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

#pragma once

#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
#include <variant>
#include <vector>

#include "src/example_06/vec3.h"
#include "src/example_06/vec4.h"

namespace dusk::obj {

struct Indices {
  uint32_t vertex;
  std::optional<uint32_t> texture;
  std::optional<uint32_t> normal;
};

/// A mesh object defined in the obj file
class Mesh {
 public:
  Mesh();
  Mesh(Mesh&&);
  ~Mesh();

  Mesh& operator=(Mesh&&);

  /// @returns the geometric vertices
  const std::vector<Vec4>& GeometricVertices() const {
    return geometric_vertices_;
  }
  /// @returns the geometric vertices
  std::vector<Vec4>& GeometricVertices() { return geometric_vertices_; }

  /// @returns the texture vertices
  const std::vector<Vec3> TextureVertices() const { return texture_vertices_; }
  /// @returns the texture vertices
  std::vector<Vec3>& TextureVertices() { return texture_vertices_; }

  /// @returns the vertex normals
  const std::vector<Vec3>& VertexNormals() const { return vertex_normals_; }
  /// @returns the vertex normals
  std::vector<Vec3>& VertexNormals() { return vertex_normals_; }

 private:
  std::vector<Vec4> geometric_vertices_;  // v
  std::vector<Vec3> texture_vertices_;    // vt
  std::vector<Vec3> vertex_normals_;      // vn

  std::vector<Indices> indices_;  // f values

  std::unordered_map<std::string, size_t> group_name_to_group_;
};

class Parser {
 public:
  struct Token {
    enum class Type {
      kError = 0,
      kEol,
      kEof,
      kNumeric,
      kString,
    };

    bool IsNumeric() const { return type == Token::Type::kNumeric; }
    bool IsString() const { return type == Token::Type::kString; }
    bool IsEol() const { return type == Token::Type::kEol; }
    bool IsEof() const { return type == Token::Type::kEof; }
    bool IsError() const { return type == Token::Type::kError; }

    std::string_view String() const { return value.s; }
    float Float() const { return value.f; }

    std::string to_string() const;

    Type type;
    union {
      float f;
      std::string_view s;
    } value;
    size_t line = 0;
    size_t column = 0;
  };

  struct Options {
    std::string resource_path;
  };

  struct Error {
    size_t line = 0;
    size_t column = 0;
    std::string msg;
  };

  Parser(const std::string_view& data, Options = {});
  ~Parser();

  /// @returns true if the parser is at the end of input
  bool IsEof() const { return position_ >= data_.size(); }

  /// @returns true if the parse is at the end of a line. This will skip over
  /// spaces and tabs to determine if there are any more non-comment characters
  /// on this line.
  bool IsEol() const;

  bool HasErrors() const { return !errors_.empty(); }
  const std::vector<Error>& Errors() const { return errors_; }
  std::string ErrorString() const;

  bool HasWarnings() const { return !warnings_.empty(); }
  const std::vector<Error>& Warnings() const { return warnings_; }
  std::string WarningString() const;

  std::optional<Mesh> Parse();

 private:
  void AddError(const std::string& err) { AddError(line_, column_, err); }
  void AddError(const Token& token, const std::string& err) {
    AddError(token.line, token.column, err);
  }
  void AddError(size_t line, size_t column, const std::string& err) {
    errors_.push_back(Error{.line = line, .column = column, .msg = err});
  }

  void AddWarning(const std::string& warn) { AddWarning(line_, column_, warn); }
  void AddWarning(const Token& token, const std::string& warn) {
    AddWarning(token.line, token.column, warn);
  }
  void AddWarning(size_t line, size_t column, const std::string& warn) {
    warnings_.push_back(Error{.line = line, .column = column, .msg = warn});
  }

  std::optional<float> ParseNumber(const std::string& command_name,
                                   const std::string& component_name,
                                   const std::string& command_format);

  bool ParseGeometricVertex();
  bool ParseVertexNormal();
  bool ParseTextureVertex();

  void Resync();
  void SkipCommentsAndWhitespace();
  Token Next();

  Mesh mesh_;

  const std::string_view data_;
  Options options_;

  size_t line_ = 1;
  size_t column_ = 1;
  size_t position_ = 0;
  bool last_was_eol_ = false;

  std::vector<size_t> current_groups_;
  std::vector<Error> errors_;
  std::vector<Error> warnings_;
};

}  // namespace dusk::obj
