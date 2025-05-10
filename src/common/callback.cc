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

#include "src/common/callback.h"

#include <cassert>
#include <print>

#include "src/common/log.h"

namespace dusk::cb {

void adapter_request(wgpu::RequestAdapterStatus status,
                     wgpu::Adapter adapter,
                     wgpu::StringView message,
                     wgpu::Adapter* data) {
  if (status != wgpu::RequestAdapterStatus::Success) {
    std::println(stderr, "Adapter request failed: {}",
                 std::string_view(message));
    exit(1);
  }
  *data = adapter;
}

void device_lost([[maybe_unused]] const wgpu::Device& device,
                 wgpu::DeviceLostReason reason,
                 struct wgpu::StringView message) {
  if (message == std::string_view(
                     "A valid external Instance reference no longer exists.")) {
    return;
  }

  std::print(stderr, "device lost: {}", dusk::log::to_str(reason));
  if (message.length > 0) {
    std::print(stderr, ": {}", std::string_view(message));
  }
  std::println(stderr, "");
}

void uncaptured_error [[noreturn]] ([[maybe_unused]] const wgpu::Device& device,
                                    wgpu::ErrorType type,
                                    struct wgpu::StringView message) {
  std::print(stderr, "uncaptured error: {}", dusk::log::to_str(type));
  if (message.length > 0) {
    std::print(stderr, ": {}", std::string_view(message));
  }

  std::println(stderr, "");
  assert(false);
};

void glfw_error [[noreturn]] (int code, const char* message) {
  std::println(stderr, "GLFW error: {}: {}", code, message);
  assert(false);
}

}  // namespace dusk::cb
