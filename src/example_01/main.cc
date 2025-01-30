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

#include <print>

#include "src/common/callback.h"
#include "src/common/log.h"
#include "src/common/wgpu.h"

int main() {
  auto instance = wgpu::CreateInstance();

  // Get Adapter
  wgpu::RequestAdapterOptions adapter_opts{
      .powerPreference = wgpu::PowerPreference::HighPerformance,
  };
  wgpu::Adapter adapter{};
  instance.RequestAdapter(&adapter_opts, wgpu::CallbackMode::AllowSpontaneous,
                          dusk::cb::adapter_request, &adapter);

  dusk::log::emit(adapter);

  // Get device
  wgpu::DeviceDescriptor device_desc{};
  device_desc.label = "default device";
  device_desc.SetDeviceLostCallback(wgpu::CallbackMode::AllowProcessEvents,
                                    dusk::cb::device_lost);
  device_desc.SetUncapturedErrorCallback(dusk::cb::uncaptured_error);

  wgpu::Device device = adapter.CreateDevice(&device_desc);
  dusk::log::emit(device);

  return 0;
}
