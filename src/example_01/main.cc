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

#include "src/example_01/dump_utils.h"
#include "src/example_01/wgpu.h"

namespace {

void adapter_request_cb(wgpu::RequestAdapterStatus status,
                        wgpu::Adapter a,
                        wgpu::StringView message,
                        wgpu::Adapter* data) {
  if (status != wgpu::RequestAdapterStatus::Success) {
    std::println(stderr, "Adapter request failed: {}",
                 std::string_view(message));
    exit(1);
  }
  *data = a;
}

void device_lost_cb([[maybe_unused]] const wgpu::Device& device,
                    wgpu::DeviceLostReason reason,
                    struct wgpu::StringView message) {
  std::print(stderr, "device lost: {}",
             dusk::dump_utils::DeviceLostReasonToString(reason));
  if (message.length > 0) {
    std::print(stderr, ": {}", std::string_view(message));
  }
  std::println(stderr, "");
}

void uncaptured_error_cb
    [[noreturn]] ([[maybe_unused]] const wgpu::Device& device,
                  wgpu::ErrorType type,
                  struct wgpu::StringView message) {
  std::print(stderr, "uncaptured error: {}",
             dusk::dump_utils::ErrorTypeToString(type));
  if (message.length > 0) {
    std::print(stderr, ": {}", std::string_view(message));
  }

  std::println(stderr, "");
  assert(false);
};

}  // namespace

int main() {
  auto instance = wgpu::CreateInstance();

  // Get Adapter
  wgpu::RequestAdapterOptions adapter_opts{
      .powerPreference = wgpu::PowerPreference::HighPerformance,
  };
  wgpu::Adapter adapter{};
  instance.RequestAdapter(&adapter_opts, wgpu::CallbackMode::AllowSpontaneous,
                          adapter_request_cb, &adapter);

  dusk::dump_utils::DumpAdapter(adapter);

  // Get device
  wgpu::DeviceDescriptor device_desc{};
  device_desc.label = "default device";
  device_desc.SetDeviceLostCallback(wgpu::CallbackMode::AllowProcessEvents,
                                    device_lost_cb);
  device_desc.SetUncapturedErrorCallback(uncaptured_error_cb);

  wgpu::Device device = adapter.CreateDevice(&device_desc);
  dusk::dump_utils::DumpDevice(device);

  return 0;
}
