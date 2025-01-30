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

/// Callbacks which are common over all of the examples.
namespace dusk::cb {

/// Callback when making a WebGPU Adapter Request
///
/// @param status reports if the adapter request was successful or not
/// @param adapter the selected adapter
/// @param message if the request failed, a message about the failure
/// @param data the user data attached to the request.

/// @note, the type of the `data` member matches the type of data attached when
/// calling `instance.requestAdapter`. We happen to be passing a `wgpu::Adapter`
/// so our type is `wgpu::Adapter*` but if you used a custom `struct MyStruct`
/// for example you'd use `MyStruct*`.
void adapter_request(wgpu::RequestAdapterStatus status,
                     wgpu::Adapter adapter,
                     wgpu::StringView message,
                     wgpu::Adapter* data);

/// Callback when the GPU is lost to WebGPU
///
/// @param device the device associated to the lost GPU
/// @param reason the reason the device was lost
/// @param message any context information
void device_lost(const wgpu::Device& device,
                 wgpu::DeviceLostReason reason,
                 struct wgpu::StringView message);

/// Callback for any error not captured in an error scope.
///
/// @param device the device where the error originated
/// @param type the type of error
/// @param message any context information on the error
void uncaptured_error [[noreturn]] (const wgpu::Device& device,
                                    wgpu::ErrorType type,
                                    struct wgpu::StringView message);

/// Callback for a GLFW error
///
/// @param code the error code
/// @param message any context information for the error.
void glfw_error [[noreturn]] (int code, const char* message);

}  // namespace dusk::cb
