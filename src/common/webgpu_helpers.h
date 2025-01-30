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

#include <string_view>

#include "src/common/wgpu.h"

/// Helper methods for interacting with the WebGPU API.
namespace dusk::webgpu {

/// Creates a new GPU buffer
///
/// @param device the device to associate the buffer too
/// @param label the label to attach to the buffer
/// @param size_in_bytes the byte size of the buffer
/// @param usage the usage of the buffer
/// @returns a new WebGPU buffer of the selected size
wgpu::Buffer create_buffer(const wgpu::Device& device,
                           std::string_view label,
                           uint64_t size_in_bytes,
                           wgpu::BufferUsage usage);

/// Creates a new GPU buffer initialized with the given data
///
/// @param device the device to associate the buffer too
/// @param label the label to attach to the buffer
/// @param data the initial data to write to the buffer
/// @param size_in_bytes the byte size of the buffer
/// @param usage the usage of the buffer
/// @returns a new WebGPU buffer of the selected size
wgpu::Buffer create_buffer(const wgpu::Device& device,
                           std::string_view label,
                           const void* data,
                           uint64_t size_in_bytes,
                           wgpu::BufferUsage usage);

/// Creates a new GPU texture
///
/// @param device the device to associate the buffer too
/// @param label the label to attach to the texture
/// @param extent the extent of the texture
/// @param format the texture format
/// @param usage the texture usage
/// @returns a new WebGPU texture
wgpu::Texture create_texture(const wgpu::Device& device,
                             std::string_view label,
                             wgpu::Extent3D extent,
                             wgpu::TextureFormat format,
                             wgpu::TextureUsage usage);

/// Creates a shader module from the given shader
///
/// @param device the device to create the module on
/// @param label the label to attach to the shader
/// @param src the shader source
/// @returns a new WebGPU ShaderModule
wgpu::ShaderModule create_shader_module(const wgpu::Device& device,
                                        std::string_view label,
                                        std::string_view src);

}  // namespace dusk::webgpu
