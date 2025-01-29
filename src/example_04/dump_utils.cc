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

#include "src/example_04/dump_utils.h"

#include <cassert>
#include <print>
#include <sstream>

namespace dusk::dump_utils {

std::string_view FeatureNameToString(wgpu::FeatureName f) {
  switch (f) {
    case wgpu::FeatureName::DepthClipControl:
      return "DepthClipControl";
    case wgpu::FeatureName::Depth32FloatStencil8:
      return "Depth32FloatStencil8";
    case wgpu::FeatureName::TimestampQuery:
      return "TimestampQuery";
    case wgpu::FeatureName::TextureCompressionBC:
      return "TextureCompressionBC";
    case wgpu::FeatureName::TextureCompressionETC2:
      return "TextureCompressionETC2";
    case wgpu::FeatureName::TextureCompressionASTC:
      return "TextureCompressionASTC";
    case wgpu::FeatureName::IndirectFirstInstance:
      return "IndirectFirstInstance";
    case wgpu::FeatureName::ShaderF16:
      return "ShaderF16";
    case wgpu::FeatureName::RG11B10UfloatRenderable:
      return "RG11B10UfloatRenderable";
    case wgpu::FeatureName::BGRA8UnormStorage:
      return "BGRA8UnormStorage";
    case wgpu::FeatureName::Float32Filterable:
      return "Float32Filterable";
    case wgpu::FeatureName::Float32Blendable:
      return "Float32Blendable";
    case wgpu::FeatureName::Subgroups:
      return "Subgroups";
    case wgpu::FeatureName::SubgroupsF16:
      return "SubgroupsF16";
    case wgpu::FeatureName::DawnInternalUsages:
      return "DawnInternalUsages";
    case wgpu::FeatureName::DawnMultiPlanarFormats:
      return "DawnMultiPlanarFormats";
    case wgpu::FeatureName::DawnNative:
      return "DawnNative";
    case wgpu::FeatureName::ChromiumExperimentalTimestampQueryInsidePasses:
      return "ChromiumExperimentalTimestampQueryInsidePasses";
    case wgpu::FeatureName::ImplicitDeviceSynchronization:
      return "ImplicitDeviceSynchronization";
    case wgpu::FeatureName::ChromiumExperimentalImmediateData:
      return "ChromiumExperimentalImmediateData";
    case wgpu::FeatureName::TransientAttachments:
      return "TransientAttachments";
    case wgpu::FeatureName::MSAARenderToSingleSampled:
      return "MSAARenderToSingleSampled";
    case wgpu::FeatureName::DualSourceBlending:
      return "DualSourceBlending";
    case wgpu::FeatureName::D3D11MultithreadProtected:
      return "D3D11MultithreadProtected";
    case wgpu::FeatureName::ANGLETextureSharing:
      return "ANGLETextureSharing";
    case wgpu::FeatureName::PixelLocalStorageCoherent:
      return "PixelLocalStorageCoherent";
    case wgpu::FeatureName::PixelLocalStorageNonCoherent:
      return "PixelLocalStorageNonCoherent";
    case wgpu::FeatureName::Unorm16TextureFormats:
      return "Unorm16TextureFormats";
    case wgpu::FeatureName::Snorm16TextureFormats:
      return "Snorm16TextureFormats";
    case wgpu::FeatureName::MultiPlanarFormatExtendedUsages:
      return "MultiPlanarFormatExtendedUsages";
    case wgpu::FeatureName::MultiPlanarFormatP010:
      return "MultiPlanarFormatP010";
    case wgpu::FeatureName::HostMappedPointer:
      return "HostMappedPointer";
    case wgpu::FeatureName::MultiPlanarRenderTargets:
      return "MultiPlanarRenderTargets";
    case wgpu::FeatureName::MultiPlanarFormatNv12a:
      return "MultiPlanarFormatNv12a";
    case wgpu::FeatureName::FramebufferFetch:
      return "FramebufferFetch";
    case wgpu::FeatureName::BufferMapExtendedUsages:
      return "BufferMapExtendedUsages";
    case wgpu::FeatureName::AdapterPropertiesMemoryHeaps:
      return "AdapterPropertiesMemoryHeaps";
    case wgpu::FeatureName::AdapterPropertiesD3D:
      return "AdapterPropertiesD3D";
    case wgpu::FeatureName::AdapterPropertiesVk:
      return "AdapterPropertiesVk";
    case wgpu::FeatureName::R8UnormStorage:
      return "R8UnormStorage";
    case wgpu::FeatureName::DawnFormatCapabilities:
      return "DawnFormatCapabilities";
    case wgpu::FeatureName::DawnDrmFormatCapabilities:
      return "DawnDrmFormatCapabilities";
    case wgpu::FeatureName::Norm16TextureFormats:
      return "Norm16TextureFormats";
    case wgpu::FeatureName::MultiPlanarFormatNv16:
      return "MultiPlanarFormatNv16";
    case wgpu::FeatureName::MultiPlanarFormatNv24:
      return "MultiPlanarFormatNv24";
    case wgpu::FeatureName::MultiPlanarFormatP210:
      return "MultiPlanarFormatP210";
    case wgpu::FeatureName::MultiPlanarFormatP410:
      return "MultiPlanarFormatP410";
    case wgpu::FeatureName::SharedTextureMemoryVkDedicatedAllocation:
      return "SharedTextureMemoryVkDedicatedAllocation";
    case wgpu::FeatureName::SharedTextureMemoryAHardwareBuffer:
      return "SharedTextureMemoryAHardwareBuffer";
    case wgpu::FeatureName::SharedTextureMemoryDmaBuf:
      return "SharedTextureMemoryDmaBuf";
    case wgpu::FeatureName::SharedTextureMemoryOpaqueFD:
      return "SharedTextureMemoryOpaqueFD";
    case wgpu::FeatureName::SharedTextureMemoryZirconHandle:
      return "SharedTextureMemoryZirconHandle";
    case wgpu::FeatureName::SharedTextureMemoryDXGISharedHandle:
      return "SharedTextureMemoryDXGISharedHandle";
    case wgpu::FeatureName::SharedTextureMemoryD3D11Texture2D:
      return "SharedTextureMemoryD3D11Texture2D";
    case wgpu::FeatureName::SharedTextureMemoryIOSurface:
      return "SharedTextureMemoryIOSurface";
    case wgpu::FeatureName::SharedTextureMemoryEGLImage:
      return "SharedTextureMemoryEGLImage";
    case wgpu::FeatureName::SharedFenceVkSemaphoreOpaqueFD:
      return "SharedFenceVkSemaphoreOpaqueFD";
    case wgpu::FeatureName::SharedFenceSyncFD:
      return "SharedFenceSyncFD";
    case wgpu::FeatureName::SharedFenceVkSemaphoreZirconHandle:
      return "SharedFenceVkSemaphoreZirconHandle";
    case wgpu::FeatureName::SharedFenceDXGISharedHandle:
      return "SharedFenceDXGISharedHandle";
    case wgpu::FeatureName::SharedFenceMTLSharedEvent:
      return "SharedFenceMTLSharedEvent";
    case wgpu::FeatureName::SharedBufferMemoryD3D12Resource:
      return "SharedBufferMemoryD3D12Resource";
    case wgpu::FeatureName::StaticSamplers:
      return "StaticSamplers";
    case wgpu::FeatureName::YCbCrVulkanSamplers:
      return "YCbCrVulkanSamplers";
    case wgpu::FeatureName::ShaderModuleCompilationOptions:
      return "ShaderModuleCompilationOptions";
    case wgpu::FeatureName::DawnLoadResolveTexture:
      return "DawnLoadResolveTexture";
    case wgpu::FeatureName::DawnPartialLoadResolveTexture:
      return "DawnPartialLoadResolveTexture";
    case wgpu::FeatureName::MultiDrawIndirect:
      return "MultiDrawIndirect";
    case wgpu::FeatureName::ClipDistances:
      return "ClipDistances";
    case wgpu::FeatureName::DawnTexelCopyBufferRowAlignment:
      return "DawnTexelCopyBufferRowAlignment";
    case wgpu::FeatureName::FlexibleTextureViews:
      return "FlexibleTextureViews";
  }
  return "Unknown";
}

std::string_view AdapterTypeToString(wgpu::AdapterType type) {
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

std::string_view BackendTypeToString(wgpu::BackendType type) {
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
    case wgpu::BackendType::Undefined:
      return "Undefined";
  }
  return "unknown";
}

std::string_view DeviceLostReasonToString(wgpu::DeviceLostReason reason) {
  switch (reason) {
    case wgpu::DeviceLostReason::Destroyed:
      return "Destroyed";
    case wgpu::DeviceLostReason::InstanceDropped:
      return "InstanceDropped";
    case wgpu::DeviceLostReason::FailedCreation:
      return "FailedCreation";
    default:
      return "unknown";
  }
}

std::string_view ErrorTypeToString(wgpu::ErrorType type) {
  switch (type) {
    case wgpu::ErrorType::NoError:
      return "NoError";
    case wgpu::ErrorType::Validation:
      return "Validation";
    case wgpu::ErrorType::OutOfMemory:
      return "OutOfMemory";
    case wgpu::ErrorType::Internal:
      return "Internal";
    default:
      return "unknown";
  }
}

std::string AdapterInfoToString(const wgpu::AdapterInfo& info) {
  assert(info.nextInChain == nullptr);

  std::stringstream out;
  std::println(out, "Vendor: {}", std::string_view(info.vendor));
  std::println(out, "Architecture: {}", std::string_view(info.architecture));
  std::println(out, "Device: {}", std::string_view(info.device));
  std::println(out, "Description: {}", std::string_view(info.description));
  std::println(out, "Adapter Type: {}", AdapterTypeToString(info.adapterType));
  std::println(out, "Backend Type: {}", BackendTypeToString(info.backendType));
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
  std::println(out, "{}maxTextureDimension1D: {}", indent,
               FormatNumber(limits.maxTextureDimension1D));
  std::println(out, "{}maxTextureDimension2D: {}", indent,
               FormatNumber(limits.maxTextureDimension2D));
  std::println(out, "{}maxTextureDimension3D: {}", indent,
               FormatNumber(limits.maxTextureDimension3D));
  std::println(out, "{}maxTextureArrayLayers: {}", indent,
               FormatNumber(limits.maxTextureArrayLayers));
  std::println(out, "{}maxBindGroups: {}", indent,
               FormatNumber(limits.maxBindGroups));
  std::println(out, "{}maxDynamicUniformBuffersPerPipelineLayout: {}", indent,
               FormatNumber(limits.maxDynamicUniformBuffersPerPipelineLayout));
  std::println(out, "{}maxDynamicStorageBuffersPerPipelineLayout: {}", indent,
               FormatNumber(limits.maxDynamicStorageBuffersPerPipelineLayout));
  std::println(out, "{}maxSampledTexturesPerShaderStage: {}", indent,
               FormatNumber(limits.maxSampledTexturesPerShaderStage));
  std::println(out, "{}maxSamplersPerShaderStage: {}", indent,
               FormatNumber(limits.maxSamplersPerShaderStage));
  std::println(out, "{}maxStorageBuffersPerShaderStage: {}", indent,
               FormatNumber(limits.maxStorageBuffersPerShaderStage));
  std::println(out, "{}maxStorageTexturesPerShaderStage: {}", indent,
               FormatNumber(limits.maxStorageTexturesPerShaderStage));
  std::println(out, "{}maxUniformBuffersPerShaderStage: {}", indent,
               FormatNumber(limits.maxUniformBuffersPerShaderStage));
  std::println(out, "{}maxUniformBufferBindingSize: {}", indent,
               FormatNumber(limits.maxUniformBufferBindingSize));
  std::println(out, "{}maxStorageBufferBindingSize: {}", indent,
               FormatNumber(limits.maxStorageBufferBindingSize));
  std::println(out, "{}minUniformBufferOffsetAlignment: {}", indent,
               FormatNumber(limits.minUniformBufferOffsetAlignment));
  std::println(out, "{}minStorageBufferOffsetAlignment: {}", indent,
               FormatNumber(limits.minStorageBufferOffsetAlignment));
  std::println(out, "{}maxVertexBuffers: {}", indent,
               FormatNumber(limits.maxVertexBuffers));
  std::println(out, "{}maxVertexAttributes: {}", indent,
               FormatNumber(limits.maxVertexAttributes));
  std::println(out, "{}maxVertexBufferArrayStride: {}", indent,
               FormatNumber(limits.maxVertexBufferArrayStride));
  std::println(out, "{}maxInterStageShaderComponents: {}", indent,
               FormatNumber(limits.maxInterStageShaderComponents));
  std::println(out, "{}maxInterStageShaderVariables: {}", indent,
               FormatNumber(limits.maxInterStageShaderVariables));
  std::println(out, "{}maxColorAttachments: {}", indent,
               FormatNumber(limits.maxColorAttachments));
  std::println(out, "{}maxComputeWorkgroupStorageSize: {}", indent,
               FormatNumber(limits.maxComputeWorkgroupStorageSize));
  std::println(out, "{}maxComputeInvocationsPerWorkgroup: {}", indent,
               FormatNumber(limits.maxComputeInvocationsPerWorkgroup));
  std::println(out, "{}maxComputeWorkgroupSizeX: {}", indent,
               FormatNumber(limits.maxComputeWorkgroupSizeX));
  std::println(out, "{}maxComputeWorkgroupSizeY: {}", indent,
               FormatNumber(limits.maxComputeWorkgroupSizeY));
  std::println(out, "{}maxComputeWorkgroupSizeZ: {}", indent,
               FormatNumber(limits.maxComputeWorkgroupSizeZ));
  std::println(out, "{}maxComputeWorkgroupsPerDimension: {}", indent,
               FormatNumber(limits.maxComputeWorkgroupsPerDimension));

  return out.str();
}

void DumpAdapterInfo(wgpu::Adapter& adapter) {
  wgpu::AdapterInfo info;
  adapter.GetInfo(&info);
  std::println(stderr, "{}", AdapterInfoToString(info));
}

void DumpAdapterFeatures(wgpu::Adapter& adapter) {
  wgpu::SupportedFeatures f;
  adapter.GetFeatures(&f);
  std::println(stderr, "Adapter Extensions:");
  for (size_t i = 0; i < f.featureCount; ++i) {
    std::println(stderr, "  {}", FeatureNameToString(f.features[i]));
  }
}

void DumpAdapterLimits(wgpu::Adapter& adapter) {
  wgpu::SupportedLimits adapterLimits;
  if (adapter.GetLimits(&adapterLimits)) {
    std::println(stderr, "");
    std::println(stderr, "Adapter Limits:");
    std::println(stderr, "{}", LimitsToString(adapterLimits.limits, "  "));
  }
}

void DumpAdapter(wgpu::Adapter& adapter) {
  DumpAdapterInfo(adapter);
  DumpAdapterFeatures(adapter);
  DumpAdapterLimits(adapter);
}

void DumpDeviceFeatures(wgpu::Device& device) {
  wgpu::SupportedFeatures f;
  device.GetFeatures(&f);
  std::println(stderr, "Device Extensions:");

  for (size_t i = 0; i < f.featureCount; ++i) {
    std::println(stderr, "  {}", FeatureNameToString(f.features[i]));
  }
}

void DumpDeviceLimits(wgpu::Device& device) {
  wgpu::SupportedLimits deviceLimits;
  if (device.GetLimits(&deviceLimits)) {
    std::println(stderr, "");
    std::println(stderr, "Device Limits:");
    std::println(stderr, "{}", LimitsToString(deviceLimits.limits, "  "));
  }
}

void DumpDevice(wgpu::Device& device) {
  DumpDeviceFeatures(device);
  DumpDeviceLimits(device);
}

}  // namespace dusk::dump_utils
