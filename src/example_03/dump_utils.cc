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

#include "src/example_03/dump_utils.h"

#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>

namespace dusk::dump_utils {

std::string FeatureNameToString(wgpu::FeatureName f) {
  switch (f) {
    case wgpu::FeatureName::DepthClipControl:
      return "DepthClipControl";
    case wgpu::FeatureName::Depth32FloatStencil8:
      return "Depth32FloatStencil8";
    case wgpu::FeatureName::TimestampQuery:
      return "TimestampQuery";
    case wgpu::FeatureName::PipelineStatisticsQuery:
      return "PipelineStatisticsQuery";
    case wgpu::FeatureName::TextureCompressionBC:
      return "TextureCompressionBC";
    case wgpu::FeatureName::TextureCompressionETC2:
      return "TextureCompressionETC2";
    case wgpu::FeatureName::TextureCompressionASTC:
      return "TextureCompressionASTC";
    case wgpu::FeatureName::IndirectFirstInstance:
      return "IndirectFirstInstance";
    case wgpu::FeatureName::DawnShaderFloat16:
      return "DawnShaderFloat16";
    case wgpu::FeatureName::DawnInternalUsages:
      return "DawnInternalUsages";
    case wgpu::FeatureName::DawnMultiPlanarFormats:
      return "DawnMultiPlanarFormats";
    case wgpu::FeatureName::DawnNative:
      return "DawnNative";
    case wgpu::FeatureName::ChromiumExperimentalDp4a:
      return "ChromiumExperimentalDp4a";
    case wgpu::FeatureName::TimestampQueryInsidePasses:
      return "TimestampQueryInsidePasses";
    case wgpu::FeatureName::ShaderF16:
      return "ShaderF16";
    case wgpu::FeatureName::RG11B10UfloatRenderable:
      return "RG11B10UfloatRenderable";
    case wgpu::FeatureName::Undefined:
      break;
  }
  return "Undefined";
}

std::string AdapterTypeToString(wgpu::AdapterType type) {
  switch (type) {
    case wgpu::AdapterType::DiscreteGPU:
      return "discrete GPU";
    case wgpu::AdapterType::IntegratedGPU:
      return "integrated GPU";
    case wgpu::AdapterType::CPU:
      return "CPU";
    case wgpu::AdapterType::Unknown:
      break;
  }
  return "unknown";
}

std::string BackendTypeToString(wgpu::BackendType type) {
  switch (type) {
    case wgpu::BackendType::Null:
      return "Null";
    case wgpu::BackendType::WebGPU:
      return "WebGPU";
    case wgpu::BackendType::D3D11:
      return "D3D11";
    case wgpu::BackendType::D3D12:
      return "D3D12";
    case wgpu::BackendType::Metal:
      return "Metal";
    case wgpu::BackendType::Vulkan:
      return "Vulkan";
    case wgpu::BackendType::OpenGL:
      return "OpenGL";
    case wgpu::BackendType::OpenGLES:
      return "OpenGLES";
  }
  return "unknown";
}

std::string AdapterPropertiesToString(const wgpu::AdapterProperties& props) {
  assert(props.nextInChain == nullptr);

  std::stringstream out;
  out << "VendorID: " << props.vendorID << std::endl;
  out << "Vendor: " << props.vendorName << std::endl;
  out << "Architecture: " << props.architecture << std::endl;
  out << "DeviceID: " << props.deviceID << std::endl;
  out << "Name: " << props.name << std::endl;
  out << "Driver description: " << props.driverDescription << std::endl;
  out << "Adapter Type: " << AdapterTypeToString(props.adapterType)
      << std::endl;
  out << "Backend Type: " << BackendTypeToString(props.backendType)
      << std::endl;
  return out.str();
}

std::string FormatNumber(uint64_t num) {
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

std::string LimitsToString(const wgpu::Limits& limits,
                           const std::string& indent) {
  std::stringstream out;

  out << indent
      << "maxTextureDimension1D: " << FormatNumber(limits.maxTextureDimension1D)
      << std::endl;
  out << indent
      << "maxTextureDimension2D: " << FormatNumber(limits.maxTextureDimension2D)
      << std::endl;
  out << indent
      << "maxTextureDimension3D: " << FormatNumber(limits.maxTextureDimension3D)
      << std::endl;
  out << indent
      << "maxTextureArrayLayers: " << FormatNumber(limits.maxTextureArrayLayers)
      << std::endl;
  out << indent << "maxBindGroups: " << FormatNumber(limits.maxBindGroups)
      << std::endl;
  out << indent << "maxDynamicUniformBuffersPerPipelineLayout: "
      << FormatNumber(limits.maxDynamicUniformBuffersPerPipelineLayout)
      << std::endl;
  out << indent << "maxDynamicStorageBuffersPerPipelineLayout: "
      << FormatNumber(limits.maxDynamicStorageBuffersPerPipelineLayout)
      << std::endl;
  out << indent << "maxSampledTexturesPerShaderStage: "
      << FormatNumber(limits.maxSampledTexturesPerShaderStage) << std::endl;
  out << indent << "maxSamplersPerShaderStage: "
      << FormatNumber(limits.maxSamplersPerShaderStage) << std::endl;
  out << indent << "maxStorageBuffersPerShaderStage: "
      << FormatNumber(limits.maxStorageBuffersPerShaderStage) << std::endl;
  out << indent << "maxStorageTexturesPerShaderStage: "
      << FormatNumber(limits.maxStorageTexturesPerShaderStage) << std::endl;
  out << indent << "maxUniformBuffersPerShaderStage: "
      << FormatNumber(limits.maxUniformBuffersPerShaderStage) << std::endl;
  out << indent << "maxUniformBufferBindingSize: "
      << FormatNumber(limits.maxUniformBufferBindingSize) << std::endl;
  out << indent << "maxStorageBufferBindingSize: "
      << FormatNumber(limits.maxStorageBufferBindingSize) << std::endl;
  out << indent << "minUniformBufferOffsetAlignment: "
      << FormatNumber(limits.minUniformBufferOffsetAlignment) << std::endl;
  out << indent << "minStorageBufferOffsetAlignment: "
      << FormatNumber(limits.minStorageBufferOffsetAlignment) << std::endl;
  out << indent << "maxVertexBuffers: " << FormatNumber(limits.maxVertexBuffers)
      << std::endl;
  out << indent
      << "maxVertexAttributes: " << FormatNumber(limits.maxVertexAttributes)
      << std::endl;
  out << indent << "maxVertexBufferArrayStride: "
      << FormatNumber(limits.maxVertexBufferArrayStride) << std::endl;
  out << indent << "maxInterStageShaderComponents: "
      << FormatNumber(limits.maxInterStageShaderComponents) << std::endl;
  out << indent << "maxInterStageShaderVariables: "
      << FormatNumber(limits.maxInterStageShaderVariables) << std::endl;
  out << indent
      << "maxColorAttachments: " << FormatNumber(limits.maxColorAttachments)
      << std::endl;
  out << indent << "maxComputeWorkgroupStorageSize: "
      << FormatNumber(limits.maxComputeWorkgroupStorageSize) << std::endl;
  out << indent << "maxComputeInvocationsPerWorkgroup: "
      << FormatNumber(limits.maxComputeInvocationsPerWorkgroup) << std::endl;
  out << indent << "maxComputeWorkgroupSizeX: "
      << FormatNumber(limits.maxComputeWorkgroupSizeX) << std::endl;
  out << indent << "maxComputeWorkgroupSizeY: "
      << FormatNumber(limits.maxComputeWorkgroupSizeY) << std::endl;
  out << indent << "maxComputeWorkgroupSizeZ: "
      << FormatNumber(limits.maxComputeWorkgroupSizeZ) << std::endl;
  out << indent << "maxComputeWorkgroupsPerDimension: "
      << FormatNumber(limits.maxComputeWorkgroupsPerDimension) << std::endl;

  return out.str();
}

void DumpAdapterProperties(wgpu::Adapter& adapter) {
  wgpu::AdapterProperties properties;
  adapter.GetProperties(&properties);
  std::cerr << AdapterPropertiesToString(properties) << std::endl;
}

void DumpAdapterFeatures(wgpu::Adapter& adapter) {
  auto feature_count = adapter.EnumerateFeatures(nullptr);
  std::vector<wgpu::FeatureName> features(feature_count);
  adapter.EnumerateFeatures(features.data());
  std::cerr << "Adapter Extensions:" << std::endl;
  for (const auto& f : features) {
    std::cerr << "  " << FeatureNameToString(f) << std::endl;
  }
}

void DumpAdapterLimits(wgpu::Adapter& adapter) {
  wgpu::SupportedLimits adapterLimits;
  if (adapter.GetLimits(&adapterLimits)) {
    std::cerr << std::endl << "Adapter Limits:" << std::endl;
    std::cerr << LimitsToString(adapterLimits.limits, "  ") << std::endl;
  }
}

void DumpAdapter(wgpu::Adapter& adapter) {
  DumpAdapterProperties(adapter);
  DumpAdapterFeatures(adapter);
  DumpAdapterLimits(adapter);
}

void DumpDeviceFeatures(wgpu::Device& device) {
  auto feature_count = device.EnumerateFeatures(nullptr);
  std::vector<wgpu::FeatureName> features(feature_count);
  device.EnumerateFeatures(features.data());
  std::cerr << "Device Extensions:" << std::endl;
  for (const auto& f : features) {
    std::cerr << "  " << FeatureNameToString(f) << std::endl;
  }
}

void DumpDeviceLimits(wgpu::Device& device) {
  wgpu::SupportedLimits deviceLimits;
  if (device.GetLimits(&deviceLimits)) {
    std::cerr << std::endl << "Device Limits:" << std::endl;
    std::cerr << LimitsToString(deviceLimits.limits, "  ") << std::endl;
  }
}

void DumpDevice(wgpu::Device& device) {
  DumpDeviceFeatures(device);
  DumpDeviceLimits(device);
}

}  // namespace dusk::dump_utils
