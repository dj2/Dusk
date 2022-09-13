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

#include <string>

#include "src/example_06/wgpu.h"

namespace dusk::webgpu {

wgpu::Buffer createBuffer(const wgpu::Device& device,
                          const std::string& label,
                          uint64_t size,
                          wgpu::BufferUsage usage);

wgpu::Buffer createBufferFromData(const wgpu::Device& device,
                                  const std::string& label,
                                  const void* data,
                                  uint64_t size,
                                  wgpu::BufferUsage usage);

wgpu::ShaderModule createShaderModule(const wgpu::Device& device,
                                      const std::string& label,
                                      const std::string& src);

wgpu::Texture createTexture(const wgpu::Device& device,
                            const std::string& label,
                            wgpu::Extent3D extent,
                            wgpu::TextureFormat format,
                            wgpu::TextureUsage usage);

}  // namespace dusk::webgpu
