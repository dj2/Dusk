// Copyright 2025 The Dusk Authors
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

#include "src/common/wgpu.h"

namespace dusk::log {

std::string_view to_str(wgpu::FeatureName f);
std::string_view to_str(wgpu::AdapterType type);
std::string_view to_str(wgpu::BackendType type);
std::string_view to_str(wgpu::DeviceLostReason reason);
std::string_view to_str(wgpu::ErrorType type);

std::string to_str(const wgpu::AdapterInfo& info);
std::string limits(const wgpu::Limits& limits, const std::string& indent);

void emit_adapter_info(wgpu::Adapter& adapter);
void emit_adapter_features(wgpu::Adapter& adapter);
void emit_adapter_limits(wgpu::Adapter& adapter);
void emit(wgpu::Adapter& adapter);

void emit_device_features(wgpu::Device& device);
void emit_device_limits(wgpu::Device& device);
void emit(wgpu::Device& device);

}  // namespace dusk::log
