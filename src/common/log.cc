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

#include <algorithm>
#include <cassert>
#include <print>
#include <sstream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcovered-switch-default"
#include <webgpu/webgpu_cpp_print.h>
#pragma clang diagnostic pop

#include "src/common/expected.h"
#include "src/common/wgpu.h"

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

std::string to_str(wgpu::SubgroupMatrixComponentType type) {
  std::stringstream s;
  s << type;
  return s.str();
}

std::string to_str(wgpu::AdapterPropertiesD3D* props) {
  std::stringstream out;
  std::println(out, "  AdapterPropertiesD3D");
  std::println(out, "  ====================");
  std::println(out, "  ShaderModel: {}", props->shaderModel);
  return out.str();
}

std::string to_str(wgpu::AdapterPropertiesVk* props) {
  std::stringstream out;
  std::println(out, "  AdapterPropertiesVK");
  std::println(out, "  ===================");
  std::println(out, "  Driver version: {}", props->driverVersion);
  return out.str();
}

std::string to_str(wgpu::AdapterPropertiesSubgroupMatrixConfigs* props) {
  std::stringstream out;

  std::println(out, "  AdapterPropertiesSubgroupMatrixConfig");
  std::println(out, "  =====================================");
  for (size_t i = 0; i < props->configCount; ++i) {
    const wgpu::SubgroupMatrixConfig& cfg = props->configs[i];

    if (i > 0) {
      std::println("");
    }

    std::println(out, "  ComponentType: {}", to_str(cfg.componentType));
    std::println(out, "  ResultComponentType: {}",
                 to_str(cfg.resultComponentType));
    std::println(out, "  M: {}, N: {}, K: {}", cfg.M, cfg.N, cfg.K);
  }
  return out.str();
}

std::string to_str(wgpu::AdapterPropertiesMemoryHeaps* props) {
  std::stringstream out;
  std::println(out, "  AdapterPropertiesMemroyHeaps");
  std::println(out, "  ============================");

  std::println(out, "  Heap count: {}", props->heapCount);
  if (props->heapInfo) {
    std::println(out, "  Heap size: {}", props->heapInfo->size);
    std::println(out, "  Heap properties: {}",
                 to_str(props->heapInfo->properties));
  }
  return out.str();
}

std::string to_str(wgpu::DawnAdapterPropertiesPowerPreference* props) {
  std::stringstream out;
  std::println(out, "  DawnAdapterPropertiesPowerPreference");
  std::println(out, "  ====================================");
  std::println(out, "  Power preference: {}", to_str(props->powerPreference));
  return out.str();
}

std::string to_str(const wgpu::AdapterInfo& info) {
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

  wgpu::ChainedStructOut* next = info.nextInChain;
  while (next != nullptr) {
    std::println(out, "");

    switch (next->sType) {
      case wgpu::SType::AdapterPropertiesD3D:
        std::print(out, "{}",
                   to_str(static_cast<wgpu::AdapterPropertiesD3D*>(next)));
        break;

      case wgpu::SType::AdapterPropertiesVk:
        std::print(out, "{}",
                   to_str(static_cast<wgpu::AdapterPropertiesVk*>(next)));
        break;

      case wgpu::SType::AdapterPropertiesSubgroupMatrixConfigs:
        std::print(
            out, "{}",
            to_str(static_cast<wgpu::AdapterPropertiesSubgroupMatrixConfigs*>(
                next)));
        break;

      case wgpu::SType::AdapterPropertiesMemoryHeaps:
        std::print(
            out, "{}",
            to_str(static_cast<wgpu::AdapterPropertiesMemoryHeaps*>(next)));
        break;

      case wgpu::SType::DawnAdapterPropertiesPowerPreference:
        std::print(
            out, "{}",
            to_str(static_cast<wgpu::DawnAdapterPropertiesPowerPreference*>(
                next)));
        break;

      default:
        std::println(stderr, "Unknown stype: {}",
                     static_cast<uint32_t>(next->sType));
        break;
    }
    next = next->nextInChain;
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
  std::println(out, "{}maxImmediateSize: {}", indent,
               format_number(limits.maxImmediateSize));

  return out.str();
}

std::expected<void, std::string> emit_instance_language_features(
    wgpu::Instance& instance) {
  wgpu::SupportedWGSLLanguageFeatures supported_features;
  instance.GetWGSLLanguageFeatures(&supported_features);

  std::vector<std::string> names;
  names.reserve(supported_features.featureCount);
  for (size_t i = 0; i < supported_features.featureCount; ++i) {
    names.push_back(to_str(supported_features.features[i]));
  }
  std::sort(names.begin(), names.end());

  std::println(stderr, "Instance Language Features");
  for (auto& name : names) {
    std::println(stderr, "  {}", name);
  }
  std::println(stderr, "");
  return {};
}

std::expected<void, std::string> emit_adapter_info(wgpu::Adapter& adapter) {
  wgpu::DawnAdapterPropertiesPowerPreference power_props{};
  wgpu::AdapterPropertiesVk vk_props{};
  wgpu::AdapterPropertiesD3D d3d_props{};
  wgpu::AdapterPropertiesMemoryHeaps memory_props{};
  wgpu::AdapterPropertiesSubgroupMatrixConfigs subgroup_matrix_props{};

  wgpu::AdapterInfo info;
  info.nextInChain = &power_props;

  wgpu::ChainedStructOut* cur = info.nextInChain;

  auto hook = [&](wgpu::ChainedStructOut* s) {
    cur->nextInChain = s;
    cur = cur->nextInChain;
  };

  if (adapter.HasFeature(wgpu::FeatureName::AdapterPropertiesD3D)) {
    hook(&d3d_props);
  }
  if (adapter.HasFeature(wgpu::FeatureName::AdapterPropertiesVk)) {
    hook(&vk_props);
  }
  if (adapter.HasFeature(wgpu::FeatureName::AdapterPropertiesMemoryHeaps)) {
    hook(&memory_props);
  }
  if (adapter.HasFeature(
          wgpu::FeatureName::ChromiumExperimentalSubgroupMatrix)) {
    hook(&subgroup_matrix_props);
  }

  WGPU_TRY(adapter.GetInfo(&info));
  std::println(stderr, "{}", to_str(info));
  return {};
}

void emit_adapter_features(wgpu::Adapter& adapter) {
  wgpu::SupportedFeatures f;
  adapter.GetFeatures(&f);

  std::vector<std::string> feature_names;
  feature_names.reserve(f.featureCount);
  for (size_t i = 0; i < f.featureCount; ++i) {
    feature_names.push_back(to_str(f.features[i]));
  }
  std::sort(feature_names.begin(), feature_names.end());

  std::println(stderr, "Adapter Features:");
  for (auto& name : feature_names) {
    std::println(stderr, "  {}", name);
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
      if (next->sType == wgpu::SType::DawnTexelCopyBufferRowAlignmentLimits) {
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

  std::vector<std::string> names;
  names.reserve(f.featureCount);
  for (size_t i = 0; i < f.featureCount; ++i) {
    names.push_back(to_str(f.features[i]));
  }

  std::println(stderr, "Device Extensions:");
  for (auto& name : names) {
    std::println(stderr, "  {}", name);
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
