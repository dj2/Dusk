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

#include "src/example_01/dump_utils.h"
#include "src/example_01/wgpu.h"

int main() {
  auto instance = wgpu::CreateInstance();

  // Get Adapter
  wgpu::Adapter adapter;
  instance.RequestAdapter(
      nullptr,
      [](WGPURequestAdapterStatus, WGPUAdapter adapterIn, const char*,
         void* userdata) {
        *static_cast<wgpu::Adapter*>(userdata) =
            wgpu::Adapter::Acquire(adapterIn);
      },
      &adapter);

  dusk::dump_utils::DumpAdapter(adapter);

  // Get device
  auto device = adapter.CreateDevice();
  dusk::dump_utils::DumpDevice(device);

  return 0;
}
