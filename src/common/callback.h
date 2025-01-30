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

#include "src/common/wgpu.h"

namespace dusk::cb {

void adapter_request(wgpu::RequestAdapterStatus status,
                     wgpu::Adapter a,
                     wgpu::StringView message,
                     wgpu::Adapter* data);

void device_lost([[maybe_unused]] const wgpu::Device& device,
                 wgpu::DeviceLostReason reason,
                 struct wgpu::StringView message);

void uncaptured_error [[noreturn]] ([[maybe_unused]] const wgpu::Device& device,
                                    wgpu::ErrorType type,
                                    struct wgpu::StringView message);

void glfw_error [[noreturn]] (int code, const char* message);

}  // namespace dusk::cb
