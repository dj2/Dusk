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

#include "src/example_06/args.h"

#include <sstream>

namespace dusk {

Args::Args() = default;

Args::~Args() = default;

std::optional<std::string> Args::Parse(std::span<const char*> args,
        std::unordered_map<std::string, Type> options) {

  if (args.empty()) {
    return {};
  }

  exe_name_ = std::string(args[0]);

  // If no options are requested, then treat everything after the program name
  // as a file.
  if (options.empty()) {
    for (uint32_t i = 1; i < args.size(); ++i) {
      files_.emplace_back(std::string(args[i]));
    }
    return {};
  }

  for (uint32_t i = 1; i < args.size(); ++i) {
    auto name = std::string(args[i]);

    if (name.length() > 1) {
      if (name[0] == '-') {
        name.erase(0, 1);
      }
      if (name.empty()) {
        return {"Missing flag for '-'"};
      }
      if (name[0] == '-') {
        name.erase(0, 1);
        if (name.empty()) {
          return {"Missing flag for '--'"};
        }
      }

      auto it = options.find(name);
      if (it == options.end()) {
        std::stringstream str;
        str << "Unknown option: " << name;
        return {str.str()};
      }

      switch (it->second) {
        case Type::kBoolean:
          bool_args_[name] = true;
          break;
        case Type::kString:
          if (i >= (args.size() - 1)) {
            std::stringstream str;
            str << "Missing value for: " << name;
            return {str.str()};
          }

          auto value = std::string(args[i + 1]);
          if (value.length() > 2 && value[0] == '-' && value[1] == '-') {
            std::stringstream str;
            str << "Missing value for: " << name;
            return {str.str()};
          }

          string_args_[name] = value;
          ++i;
          break;
      }
    } else {
      files_.emplace_back(name);
    }
  }

  return {};
}

}  // namespace dusk
