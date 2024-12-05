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

#include "src/example_02/webgpu_helpers.h"

namespace dusk::webgpu {

wgpu::Buffer createBufferFromData(const wgpu::Device& device,
                                  const std::string& label,
                                  const void* data,
                                  uint64_t size,
                                  wgpu::BufferUsage usage) {
  wgpu::BufferDescriptor desc{
      .label = label.c_str(),
      .usage = usage | wgpu::BufferUsage::CopyDst,
      .size = size,
  };
  auto buffer = device.CreateBuffer(&desc);
  device.GetQueue().WriteBuffer(buffer, 0, data, size);
  return buffer;
}

wgpu::ShaderModule createShaderModule(const wgpu::Device& device,
                                      const std::string& label,
                                      const char* src) {
  wgpu::ShaderSourceWGSL wgslDesc;
  wgslDesc.code = src;
  wgpu::ShaderModuleDescriptor desc{
      .nextInChain = &wgslDesc,
      .label = label.c_str(),
  };
  auto shader = device.CreateShaderModule(&desc);
  return shader;
}

}  // namespace dusk::webgpu
