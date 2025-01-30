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

#include "src/common/webgpu_helpers.h"

namespace dusk::webgpu {

wgpu::Buffer create_buffer(const wgpu::Device& device,
                           std::string_view label,
                           uint64_t size_in_bytes,
                           wgpu::BufferUsage usage) {
  wgpu::BufferDescriptor desc{
      .label = label,
      .usage = usage | wgpu::BufferUsage::CopyDst,
      .size = size_in_bytes,
  };
  return device.CreateBuffer(&desc);
}

wgpu::Buffer create_buffer(const wgpu::Device& device,
                           std::string_view label,
                           const void* data,
                           uint64_t size_in_bytes,
                           wgpu::BufferUsage usage) {
  auto buffer = create_buffer(device, label, size_in_bytes, usage);
  device.GetQueue().WriteBuffer(buffer, 0, data, size_in_bytes);
  return buffer;
}

wgpu::Texture create_texture(const wgpu::Device& device,
                             std::string_view label,
                             wgpu::Extent3D extent,
                             wgpu::TextureFormat format,
                             wgpu::TextureUsage usage) {
  wgpu::TextureDescriptor desc{
      .label = label,
      .usage = usage,
      .size = extent,
      .format = format,
  };

  return device.CreateTexture(&desc);
}

wgpu::ShaderModule create_shader_module(const wgpu::Device& device,
                                        std::string_view label,
                                        std::string_view src) {
  wgpu::ShaderSourceWGSL wgslDesc;
  wgslDesc.code = src;

  wgpu::ShaderModuleDescriptor desc{
      .nextInChain = &wgslDesc,
      .label = label,
  };
  return device.CreateShaderModule(&desc);
}

}  // namespace dusk::webgpu
