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

/// Methods used to log various bits of data from WebGPU.
namespace dusk::log {

/// Creates a textual version of the feature name
///
/// @param f the feature name to convert
/// @returns the string name
std::string_view to_str(wgpu::FeatureName f);

/// Creates a textual version of the WGSL language feature name
///
/// @Parma f the language feature name to convert
/// @returns the string name
std::string_view to_str(wgpu::WGSLLanguageFeatureName f);

/// Creates a textual version of the adapter type
///
/// @param type the adapter type to convert
/// @returns the string name
std::string_view to_str(wgpu::AdapterType type);

/// Creates a textual version of the backend type
///
/// @param type the backend type to convert
/// @returns the string name
std::string_view to_str(wgpu::BackendType type);

/// Creates a textual version of the device lost reason
///
/// @param f the device lost reason to convert
/// @returns the string name
std::string_view to_str(wgpu::DeviceLostReason reason);

/// Creates a textual version of the error type
///
/// @param f the error type to convert
/// @returns the string name
std::string_view to_str(wgpu::ErrorType type);

/// Creates a textual version of the heap properties
///
/// @param prop the property to emit
/// @returns the string name
std::string_view to_str(wgpu::HeapProperty prop);

/// Creates a textual version of the power preference
///
/// @param prop the power preference to emit
/// @returns the string name
std::string_view to_str(wgpu::PowerPreference pref);

/// Creates a textual version of the adapter information
///
/// @param info the adapter info to convert
/// @returns the string representation
std::string to_str(const wgpu::AdapterInfo& info);

/// Creates a textual version of the limits
///
/// @param limits the limits to convert
/// @param indent the amount to indent each limit string
/// @returns the string representation
std::string limits(const wgpu::Limits& limits, std::string_view indent);

/// Emits the instance capability information
///
/// @param caps the instance capabilities
void emit(wgpu::InstanceCapabilities& caps);

/// Emits the language features known to the instance
///
/// @param instance the instance to retrieve the features from
std::expected<void, std::string> emit_instance_language_features(
    wgpu::Instance& instance);

/// Emits the adapter info to `stderr`
///
/// @param adapter the adapter to emit from
std::expected<void, std::string> emit_adapter_info(wgpu::Adapter& adapter);

/// Emits the adapter features to `stderr`
///
/// @param adapter the adapter to emit from
void emit_adapter_features(wgpu::Adapter& adapter);

/// Emits the adapter limits to `stderr`
///
/// @param adapter the adapter to emit from
std::expected<void, std::string> emit_adapter_limits(wgpu::Adapter& adapter);

/// Emits the adapter to `stderr`
///
/// @param adapter the adapter to emit
std::expected<void, std::string> emit(wgpu::Adapter& adapter);

/// Emits the device features to `stderr`
///
/// @param device the device to emit from
void emit_device_features(wgpu::Device& device);

/// Emits the device limits to `stderr`
///
/// @param device the device to emit from
std::expected<void, std::string> emit_device_limits(wgpu::Device& device);

/// Emits the device to `stderr`
///
/// @param device the device to emit
std::expected<void, std::string> emit(wgpu::Device& device);

}  // namespace dusk::log
