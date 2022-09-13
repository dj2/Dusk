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

#include "src/example_06/callbacks.h"

#include <iostream>

namespace dusk::cb {

void Error(WGPUErrorType type, const char* msg, void*) {
  switch (type) {
    case WGPUErrorType_OutOfMemory:
      std::cerr << "[Unhandled Error] Out Of Memory: " << msg << std::endl;
      abort();
    case WGPUErrorType_Validation:
      std::cerr << "[Unhandled Error] Validation: " << msg << std::endl;
      abort();
    case WGPUErrorType_NoError:
    case WGPUErrorType_Unknown:
    case WGPUErrorType_DeviceLost:
    case WGPUErrorType_Force32:
      std::cerr << msg << std::endl;
      break;
  }
}

void DeviceLost(WGPUDeviceLostReason reason, char const* msg, void*) {
  std::cerr << "[Device Lost]: ";
  switch (reason) {
    case WGPUDeviceLostReason_Undefined:
      std::cerr << "Undefined: " << msg << std::endl;
      break;
    case WGPUDeviceLostReason_Destroyed:
      std::cerr << "Destroyed: " << msg << std::endl;
      break;
    case WGPUDeviceLostReason_Force32:
      std::cerr << "Force32: " << msg << std::endl;
      break;
  }
}

void Logging(WGPULoggingType type, const char* msg, void*) {
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
  std::cerr << msg << std::endl;
}

}  // namespace dusk::cb
