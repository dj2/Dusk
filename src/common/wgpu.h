// Copyright 2025 The Dusk Authors
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

#include <expected>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
#pragma clang diagnostic ignored "-Wdouble-promotion"
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wshadow-field-in-constructor"
#pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#include <webgpu/webgpu_cpp.h>  // IWYU pragma: export
#pragma clang diagnostic pop

/// Tries to run `expr`. If the status is not `Successes` then returns an
/// unexpected result with the error information.
#define WGPU_TRY(expr)                                            \
  do {                                                            \
    wgpu::Status status = (expr);                                 \
    if (status != wgpu::Status::Success) {                        \
      return std::unexpected(std::format("Failed: " #expr "\n")); \
    }                                                             \
  } while (false)

#define WGPU_TRY_EXIT(expr)                        \
  do {                                             \
    wgpu::Status status = (expr);                  \
    if (status != wgpu::Status::Success) {         \
      std::println(stderr, "Failed: " #expr "\n"); \
      exit(1);                                     \
    }                                              \
  } while (false)
