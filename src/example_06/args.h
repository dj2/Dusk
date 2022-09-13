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

#include <optional>
#include <span>
#include <string>
#include <unordered_map>
#include <vector>

namespace dusk {

/// Provides high level access to the program arguments.
class Args {
 public:
  /// The type of the argument option.
  enum class Type { kBoolean = 0, kString, };

  Args();
  ~Args();

  /// Parses |args| based on the provided |options|.
  /// @param args the list of arguments to parse
  /// @param options the program options that determine how the
  ///        |args| are parsed.
  /// @returns an empty optional on success, an error string on failure
  std::optional<std::string> Parse(std::span<const char*> args,
        std::unordered_map<std::string, Type> options);

  /// @returns the name of the executable
  const std::string& ExeName() const { return exe_name_; }

  /// @returns the files passed on the command line.
  const std::vector<std::string>& Files() const { return files_; }

  /// @param name the name of the flag
  /// @returns true if the given flag was passed on the command line
  bool HasFlag(const std::string& name) const {
    return string_args_.count(name) || bool_args_.count(name);
  }

  /// @param name the name of the flag
  /// @returns the string value provided for the flag
  std::string StringForFlag(const std::string& name) const {
    if (!HasFlag(name)) {
      return {};
    }
    return string_args_.at(name);
  }

 private:
  std::string exe_name_;
  std::vector<std::string> files_;
  std::unordered_map<std::string, std::string> string_args_;
  std::unordered_map<std::string, bool> bool_args_;
};

}  // namespace dusk
