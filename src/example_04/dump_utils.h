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

#pragma once

#include <string>
#include <string_view>

#include "src/example_01/wgpu.h"

namespace dusk::dump_utils {

std::string_view FeatureNameToString(wgpu::FeatureName f);
std::string_view AdapterTypeToString(wgpu::AdapterType type);
std::string_view BackendTypeToString(wgpu::BackendType type);
std::string_view DeviceLostReasonToString(wgpu::DeviceLostReason reason);
std::string_view ErrorTypeToString(wgpu::ErrorType type);

std::string AdapterInfoToString(const wgpu::AdapterInfo& info);
std::string FormatNumber(uint64_t num);

std::string LimitsToString(const wgpu::Limits& limits,
                           const std::string& indent);

void DumpAdapterInfo(wgpu::Adapter& adapter);
void DumpAdapterFeatures(wgpu::Adapter& adapter);
void DumpAdapterLimits(wgpu::Adapter& adapter);
void DumpAdapter(wgpu::Adapter& adapter);

void DumpDeviceFeatures(wgpu::Device& device);
void DumpDeviceLimits(wgpu::Device& device);
void DumpDevice(wgpu::Device& device);

}  // namespace dusk::dump_utils
