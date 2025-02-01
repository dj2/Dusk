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

std::string_view to_str(wgpu::FeatureName f) {
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

std::string_view to_str(wgpu::WGSLLanguageFeatureName name) {
  switch (name) {
    case wgpu::WGSLLanguageFeatureName::ReadonlyAndReadwriteStorageTextures:
      return "ReadonlyAndReadwriteStorageTextures";
    case wgpu::WGSLLanguageFeatureName::Packed4x8IntegerDotProduct:
      return "Packed4x8IntegerDotProduct";
    case wgpu::WGSLLanguageFeatureName::UnrestrictedPointerParameters:
      return "UnrestrictedPointerParameters";
    case wgpu::WGSLLanguageFeatureName::PointerCompositeAccess:
      return "PointerCompositeAccess";
    case wgpu::WGSLLanguageFeatureName::ChromiumTestingUnimplemented:
      return "ChromiumTestingUnimplemented";
    case wgpu::WGSLLanguageFeatureName::ChromiumTestingUnsafeExperimental:
      return "ChromiumTestingUnsafeExperimental";
    case wgpu::WGSLLanguageFeatureName::ChromiumTestingExperimental:
      return "ChromiumTestingExperimental";
    case wgpu::WGSLLanguageFeatureName::ChromiumTestingShippedWithKillswitch:
      return "ChromiumTestingShippedWithKillswitch";
    case wgpu::WGSLLanguageFeatureName::ChromiumTestingShipped:
      return "ChromiumTestingShipped";
  }
}

std::string_view to_str(wgpu::AdapterType type) {
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

std::string_view to_str(wgpu::BackendType type) {
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

std::string_view to_str(wgpu::DeviceLostReason reason) {
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

std::string_view to_str(wgpu::ErrorType type) {
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

std::string_view to_str(wgpu::HeapProperty props) {
  switch (props) {
    case wgpu::HeapProperty::DeviceLocal:
      return "device_local";
    case wgpu::HeapProperty::HostVisible:
      return "host_visible";
    case wgpu::HeapProperty::HostCoherent:
      return "host_coherent";
    case wgpu::HeapProperty::HostUncached:
      return "host_uncached";
    case wgpu::HeapProperty::HostCached:
      return "host_cached";
  }
}

std::string_view to_str(wgpu::PowerPreference pref) {
  switch (pref) {
    case wgpu::PowerPreference::LowPower:
      return "low";
    case wgpu::PowerPreference::HighPerformance:
      return "high";
    default:
      return "unknown";
  }
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
  std::println(out, "  Compat: {}",
               (info.compatibilityMode == 1) ? "yes" : "no");

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
               format_number(limits.maxInterStageShaderComponents));
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

void emit_adapter_info(wgpu::Adapter& adapter) {
  wgpu::AdapterInfo info;
  adapter.GetInfo(&info);
  std::println(stderr, "{}", to_str(info));
}

void emit_adapter_features(wgpu::Adapter& adapter) {
  wgpu::SupportedFeatures f;
  adapter.GetFeatures(&f);

  std::println(stderr, "Adapter Features:");
  for (size_t i = 0; i < f.featureCount; ++i) {
    std::println(stderr, "  {}", to_str(f.features[i]));
  }
}

void emit_adapter_limits(wgpu::Adapter& adapter) {
  wgpu::SupportedLimits adapter_limits;
  if (adapter.GetLimits(&adapter_limits)) {
    std::println(stderr, "");
    std::println(stderr, "Adapter Limits:");
    std::println(stderr, "{}", limits(adapter_limits.limits, "  "));
  }

  {
    wgpu::ChainedStructOut* next = adapter_limits.nextInChain;
    while (next != nullptr) {
      if (next->sType == wgpu::SType::DawnExperimentalImmediateDataLimits) {
        auto* l = static_cast<wgpu::DawnExperimentalImmediateDataLimits*>(next);
        std::println(stderr, "  maxImmediateDataRangeByteSize = {}",
                     l->maxImmediateDataRangeByteSize);
      } else if (next->sType == wgpu::SType::DawnExperimentalSubgroupLimits) {
        auto* l = static_cast<wgpu::DawnExperimentalSubgroupLimits*>(next);
        std::println(stderr, "  minSubgroupSize = {}", l->minSubgroupSize);
        std::println(stderr, "  maxSubgroupSize = {}", l->maxSubgroupSize);
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
}

void emit(wgpu::Adapter& adapter) {
  emit_adapter_info(adapter);
  emit_adapter_features(adapter);
  emit_adapter_limits(adapter);
}

void emit_device_features(wgpu::Device& device) {
  wgpu::SupportedFeatures f;
  device.GetFeatures(&f);
  std::println(stderr, "Device Extensions:");

  for (size_t i = 0; i < f.featureCount; ++i) {
    std::println(stderr, "  {}", to_str(f.features[i]));
  }
}

void emit_device_limits(wgpu::Device& device) {
  wgpu::SupportedLimits deviceLimits;
  if (device.GetLimits(&deviceLimits)) {
    std::println(stderr, "");
    std::println(stderr, "Device Limits:");
    std::println(stderr, "{}", limits(deviceLimits.limits, "  "));
  }
}

void emit(wgpu::Device& device) {
  emit_device_features(device);
  emit_device_limits(device);
}

}  // namespace dusk::log
