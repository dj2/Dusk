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

#include "src/common/log.h"

#include <cassert>
#include <print>
#include <sstream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcovered-switch-default"
#include <webgpu/webgpu_cpp_print.h>
#pragma clang diagnostic pop

#include "src/common/expected.h"

namespace dusk::log {
namespace {

std::string format_number(uint64_t num) {
  auto s = std::to_string(num);
  std::stringstream ret;

  auto remainder = s.length() % 3;
  ret << s.substr(0, remainder);
  for (size_t i = remainder; i < s.length(); i += 3) {
    if (i > 0) {
      ret << ",";
    }
    ret << s.substr(i, 3);
  }
  return ret.str();
}

}  // namespace

std::string to_str(wgpu::FeatureName f) {
  std::stringstream s;
  s << f;
  return s.str();
}

std::string to_str(wgpu::WGSLLanguageFeatureName name) {
  std::stringstream s;
  s << name;
  return s.str();
}

std::string to_str(wgpu::AdapterType type) {
  std::stringstream s;
  s << type;
  return s.str();
}

std::string to_str(wgpu::BackendType type) {
  std::stringstream s;
  s << type;
  return s.str();
}

std::string to_str(wgpu::DeviceLostReason reason) {
  std::stringstream s;
  s << reason;
  return s.str();
}

std::string to_str(wgpu::ErrorType type) {
  std::stringstream s;
  s << type;
  return s.str();
}

std::string to_str(wgpu::HeapProperty props) {
  std::stringstream s;
  s << props;
  return s.str();
}

std::string to_str(wgpu::PowerPreference pref) {
  std::stringstream s;
  s << pref;
  return s.str();
}

std::string to_str(const wgpu::AdapterInfo& info) {
  assert(info.nextInChain == nullptr);

  std::stringstream out;
  std::println(out, "Adapter Info");
  std::println(out, "  Vendor: {}", std::string_view(info.vendor));
  std::println(out, "  Architecture: {}", std::string_view(info.architecture));
  std::println(out, "  Device: {}", std::string_view(info.device));
  std::println(out, "  Description: {}", std::string_view(info.description));
  std::println(out, "  Adapter Type: {}", to_str(info.adapterType));
  std::println(out, "  Backend Type: {}", to_str(info.backendType));
  std::println(out, "  Vendor ID: 0x{:x}", info.vendorID);
  std::println(out, "  Device ID: 0x{:x}", info.deviceID);
  std::println(out, "  Subgroup size: min: {}, max {}", info.subgroupMinSize,
               info.subgroupMaxSize);

  {
    wgpu::ChainedStructOut* next = info.nextInChain;
    while (next != nullptr) {
      if (next->sType == wgpu::SType::AdapterPropertiesD3D) {
        auto* l = static_cast<wgpu::AdapterPropertiesD3D*>(next);
        std::println(out, "  ShaderModel = {}", l->shaderModel);
      } else if (next->sType == wgpu::SType::AdapterPropertiesSubgroups) {
        auto* l = static_cast<wgpu::AdapterPropertiesSubgroups*>(next);
        std::println(out, "  SubgroupMinSize = {}", l->subgroupMinSize);
        std::println(out, "  SubgroupMaxSize = {}", l->subgroupMaxSize);
      } else if (next->sType == wgpu::SType::AdapterPropertiesVk) {
        auto* l = static_cast<wgpu::AdapterPropertiesVk*>(next);
        std::println(out, "  Driver version: {}", l->driverVersion);
      } else if (next->sType ==
                 wgpu::SType::DawnAdapterPropertiesPowerPreference) {
        auto* l =
            static_cast<wgpu::DawnAdapterPropertiesPowerPreference*>(next);
        std::println(out, "  Power preference: {}", to_str(l->powerPreference));
      } else if (next->sType == wgpu::SType::AdapterPropertiesMemoryHeaps) {
        auto* l = static_cast<wgpu::AdapterPropertiesMemoryHeaps*>(next);
        std::println(out, "  Heap count: {}", l->heapCount);
        if (l->heapInfo) {
          std::println(out, "  Heap size: {}", l->heapInfo->size);
          std::println(out, "  Heap properties: {}",
                       to_str(l->heapInfo->properties));
        }

      } else {
        std::println(stderr, "Unknown stype: {}",
                     static_cast<uint32_t>(next->sType));
      }
      next = next->nextInChain;
    }
  }
  return out.str();
}

std::string limits(const wgpu::Limits& limits, std::string_view indent) {
  std::stringstream out;
  std::println(out, "{}maxTextureDimension1D: {}", indent,
               format_number(limits.maxTextureDimension1D));
  std::println(out, "{}maxTextureDimension2D: {}", indent,
               format_number(limits.maxTextureDimension2D));
  std::println(out, "{}maxTextureDimension3D: {}", indent,
               format_number(limits.maxTextureDimension3D));
  std::println(out, "{}maxTextureArrayLayers: {}", indent,
               format_number(limits.maxTextureArrayLayers));
  std::println(out, "{}maxBindGroups: {}", indent,
               format_number(limits.maxBindGroups));
  std::println(out, "{}maxDynamicUniformBuffersPerPipelineLayout: {}", indent,
               format_number(limits.maxDynamicUniformBuffersPerPipelineLayout));
  std::println(out, "{}maxDynamicStorageBuffersPerPipelineLayout: {}", indent,
               format_number(limits.maxDynamicStorageBuffersPerPipelineLayout));
  std::println(out, "{}maxSampledTexturesPerShaderStage: {}", indent,
               format_number(limits.maxSampledTexturesPerShaderStage));
  std::println(out, "{}maxSamplersPerShaderStage: {}", indent,
               format_number(limits.maxSamplersPerShaderStage));
  std::println(out, "{}maxStorageBuffersPerShaderStage: {}", indent,
               format_number(limits.maxStorageBuffersPerShaderStage));
  std::println(out, "{}maxStorageTexturesPerShaderStage: {}", indent,
               format_number(limits.maxStorageTexturesPerShaderStage));
  std::println(out, "{}maxUniformBuffersPerShaderStage: {}", indent,
               format_number(limits.maxUniformBuffersPerShaderStage));
  std::println(out, "{}maxUniformBufferBindingSize: {}", indent,
               format_number(limits.maxUniformBufferBindingSize));
  std::println(out, "{}maxStorageBufferBindingSize: {}", indent,
               format_number(limits.maxStorageBufferBindingSize));
  std::println(out, "{}minUniformBufferOffsetAlignment: {}", indent,
               format_number(limits.minUniformBufferOffsetAlignment));
  std::println(out, "{}minStorageBufferOffsetAlignment: {}", indent,
               format_number(limits.minStorageBufferOffsetAlignment));
  std::println(out, "{}maxVertexBuffers: {}", indent,
               format_number(limits.maxVertexBuffers));
  std::println(out, "{}maxVertexAttributes: {}", indent,
               format_number(limits.maxVertexAttributes));
  std::println(out, "{}maxVertexBufferArrayStride: {}", indent,
               format_number(limits.maxVertexBufferArrayStride));
  std::println(out, "{}maxInterStageShaderComponents: {}", indent,
               format_number(limits.maxInterStageShaderVariables));
  std::println(out, "{}maxInterStageShaderVariables: {}", indent,
               format_number(limits.maxInterStageShaderVariables));
  std::println(out, "{}maxColorAttachments: {}", indent,
               format_number(limits.maxColorAttachments));
  std::println(out, "{}maxComputeWorkgroupStorageSize: {}", indent,
               format_number(limits.maxComputeWorkgroupStorageSize));
  std::println(out, "{}maxComputeInvocationsPerWorkgroup: {}", indent,
               format_number(limits.maxComputeInvocationsPerWorkgroup));
  std::println(out, "{}maxComputeWorkgroupSizeX: {}", indent,
               format_number(limits.maxComputeWorkgroupSizeX));
  std::println(out, "{}maxComputeWorkgroupSizeY: {}", indent,
               format_number(limits.maxComputeWorkgroupSizeY));
  std::println(out, "{}maxComputeWorkgroupSizeZ: {}", indent,
               format_number(limits.maxComputeWorkgroupSizeZ));
  std::println(out, "{}maxComputeWorkgroupsPerDimension: {}", indent,
               format_number(limits.maxComputeWorkgroupsPerDimension));

  return out.str();
}

void emit(wgpu::InstanceCapabilities& caps) {
  std::println(stderr, "Instance Capabilities:");
  std::println(stderr, "  timedWaitAnyEnable: {}",
               caps.timedWaitAnyEnable ? "true" : "false'");
  std::println(stderr, "  timedWaitAnyMaxCount: {}", caps.timedWaitAnyMaxCount);
  std::println(stderr, "");
}

std::expected<void, std::string> emit_instance_language_features(
    wgpu::Instance& instance) {
  wgpu::SupportedWGSLLanguageFeatures supported_features;
  WGPU_TRY(instance.GetWGSLLanguageFeatures(&supported_features));

  std::println(stderr, "Instance Language Features");
  for (size_t i = 0; i < supported_features.featureCount; ++i) {
    std::println(stderr, "  {}", to_str(supported_features.features[i]));
  }
  std::println(stderr, "");
  return {};
}

std::expected<void, std::string> emit_adapter_info(wgpu::Adapter& adapter) {
  wgpu::AdapterInfo info;
  WGPU_TRY(adapter.GetInfo(&info));
  std::println(stderr, "{}", to_str(info));
  return {};
}

void emit_adapter_features(wgpu::Adapter& adapter) {
  wgpu::SupportedFeatures f;
  adapter.GetFeatures(&f);

  std::println(stderr, "Adapter Features:");
  for (size_t i = 0; i < f.featureCount; ++i) {
    std::println(stderr, "  {}", to_str(f.features[i]));
  }
}

std::expected<void, std::string> emit_adapter_limits(wgpu::Adapter& adapter) {
  wgpu::Limits adapter_limits;
  WGPU_TRY(adapter.GetLimits(&adapter_limits));

  std::println(stderr, "");
  std::println(stderr, "Adapter Limits:");
  std::println(stderr, "{}", limits(adapter_limits, "  "));

  {
    wgpu::ChainedStructOut* next = adapter_limits.nextInChain;
    while (next != nullptr) {
      if (next->sType == wgpu::SType::DawnExperimentalImmediateDataLimits) {
        auto* l = static_cast<wgpu::DawnExperimentalImmediateDataLimits*>(next);
        std::println(stderr, "  maxImmediateDataRangeByteSize = {}",
                     l->maxImmediateDataRangeByteSize);
      } else if (next->sType ==
                 wgpu::SType::DawnTexelCopyBufferRowAlignmentLimits) {
        auto* l =
            static_cast<wgpu::DawnTexelCopyBufferRowAlignmentLimits*>(next);
        std::println(stderr, "  minTexelCopyBufferRowAlignment = {}",
                     l->minTexelCopyBufferRowAlignment);
      } else {
        std::print(stderr, "Unknown stype: {}",
                   static_cast<uint32_t>(next->sType));
      }
      next = next->nextInChain;
    }
  }
  return {};
}

std::expected<void, std::string> emit(wgpu::Adapter& adapter) {
  VALID_OR_PROPAGATE(emit_adapter_info(adapter));
  emit_adapter_features(adapter);
  VALID_OR_PROPAGATE(emit_adapter_limits(adapter));
  return {};
}

void emit_device_features(wgpu::Device& device) {
  wgpu::SupportedFeatures f;
  device.GetFeatures(&f);
  std::println(stderr, "Device Extensions:");

  for (size_t i = 0; i < f.featureCount; ++i) {
    std::println(stderr, "  {}", to_str(f.features[i]));
  }
}

std::expected<void, std::string> emit_device_limits(wgpu::Device& device) {
  wgpu::Limits deviceLimits;
  WGPU_TRY(device.GetLimits(&deviceLimits));
  std::println(stderr, "");
  std::println(stderr, "Device Limits:");
  std::println(stderr, "{}", limits(deviceLimits, "  "));
  return {};
}

std::expected<void, std::string> emit(wgpu::Device& device) {
  emit_device_features(device);
  VALID_OR_PROPAGATE(emit_device_limits(device));
  return {};
}

}  // namespace dusk::log
