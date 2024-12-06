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

#include "src/example_03/callbacks.h"

#include <iostream>

namespace dusk::cb {

namespace {
std::string_view str(const WGPUStringView& s) {
  return {s.data, s.length};
}
}  // anonymous namespace

void Error(const wgpu::Device&, wgpu::ErrorType type, const char* msg) {
  switch (type) {
    case wgpu::ErrorType::OutOfMemory:
      std::cerr << "[Error] Out Of Memory: " << msg << std::endl;
      abort();
    case wgpu::ErrorType::Validation:
      std::cerr << "[Error Validation: " << msg << std::endl;
      abort();
    case wgpu::ErrorType::NoError:
    case wgpu::ErrorType::Unknown:
    case wgpu::ErrorType::DeviceLost:
    case wgpu::ErrorType::Internal:
      std::cerr << msg << std::endl;
      break;
  }
}

void DeviceLost(const wgpu::Device&,
                wgpu::DeviceLostReason reason,
                const char* msg) {
  std::cerr << "[Device Lost]: ";
  switch (reason) {
    case wgpu::DeviceLostReason::Unknown:
      std::cerr << "Undefined: " << msg << std::endl;
      break;
    case wgpu::DeviceLostReason::Destroyed:
      std::cerr << "Destroyed: " << msg << std::endl;
      break;
    case wgpu::DeviceLostReason::InstanceDropped:
      std::cerr << "InstanceDropped: " << msg << std::endl;
      break;
    case wgpu::DeviceLostReason::FailedCreation:
      std::cerr << "FailedCreation: " << msg << std::endl;
      break;
  }
}

void Logging(WGPULoggingType type, WGPUStringView msg, void*) {
  switch (type) {
    case WGPULoggingType_Verbose:
      std::cerr << "Log [Verbose]: ";
      break;
    case WGPULoggingType_Info:
      std::cerr << "Log [Info]: ";
      break;
    case WGPULoggingType_Warning:
      std::cerr << "Log [Warning]: ";
      break;
    case WGPULoggingType_Error:
      std::cerr << "Log [Error]: ";
      break;
    case WGPULoggingType_Force32:
      std::cerr << "Log [Force32]: ";
      break;
  }
  std::cerr << str(msg) << std::endl;
}

}  // namespace dusk::cb
