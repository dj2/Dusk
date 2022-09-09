---
layout: page
title: C API
parent: API Documentation
---

# C API Documentation
## Constants

| Value | Description |
|:------|:------------|
| `WGPU_ARRAY_LAYER_COUNT_UNDEFINED` | Undefined value for array layer count. Providing undefined will cause a default value to be used. |
| `WGPU_COPY_STRIDE_UNDEFINED` | Undefined value for copy stride. Providing undefined will cause a default value to be used. |
| `WGPU_LIMIT_U32_UNDEFINED` | Undefined U32 limit value. Providing undefined will cause a default value to be used. |
| `WGPU_LIMIT_U64_UNDEFINED` | Undefined U64 limit value. Providing undefined will cause a default value to be used. |
| `WGPU_MIP_LEVEL_COUNT_UNDEFINED` | Undefined mip level count. Providing undefined will cause a default value to be used. |
| `WGPU_STRIDE_UNDEFINED` | Undefined stride. Providing undefined will cause a default value to be used. |
| `WGPU_WHOLE_MAP_SIZE` | Value representing size of entire map. Providing undefined will cause a default value to be used. |
| `WGPU_WHOLE_SIZE` | Value representing the whole size value. Providing undefined will cause a default value to be used. |

## Enums

### enum WGPUAdapterType {#enum-AdapterType}

Provides information on the type of adapter.


| Value | Description |
|:------|:------------|
| `WGPUAdapterType_DiscreteGPU` | A separate discrete GPU adapter |
| `WGPUAdapterType_IntegratedGPU` | An integrated GPU / CPU adapter |
| `WGPUAdapterType_CPU` | A CPU adapter |
| `WGPUAdapterType_Unknown` | A unknown adapter type |

### enum WGPUAddressMode {#enum-AddressMode}

Describes the behaviour of the sampler if the sampler footprint extends beyond the bounds of the sampled texture.

See [GPUAddressMode](https://webgpu.dev/#enumdef-gpuaddressmode) for more information.


| Value | Description |
|:------|:------------|
| `WGPUAddressMode_Repeat` | Texture coordinates wrap to the other side of the texture |
| `WGPUAddressMode_MirrorRepeat` | Texture coordinates wrap to the other side of the texture, but the texture is flipped when the integer part of the coordinate is odd. |
| `WGPUAddressMode_ClampToEdge` | Texture coordinates are clamped between 0.0 and 1.0, inclusive. |

### enum WGPUAlphaMode {#enum-AlphaMode}

Selects how the contents of the surface will be interpreted when read, when rendered to the screen or used as an image source.

See [GPUCanvasAlphaMode](https://webgpu.dev/#GPUCanvasAlphaMode) for more information.


| Value | Description |
|:------|:------------|
| `WGPUAlphaMode_Premultiplied` | Read RBGA as premultipled: color values are premultipled by their alpha value. |
| `WGPUAlphaMode_Unpremultiplied` | Read RGBA as not premulitipled: Color values are not premultipled by their alpha value |
| `WGPUAlphaMode_Opaque` | Read RGB as opaque and ignore alpha value |

### enum WGPUBackendType {#enum-BackendType}

Specifies the type of backend to use with Dawn.


| Value | Description |
|:------|:------------|
| `WGPUBackendType_Null` | A null backend |
| `WGPUBackendType_WebGPU` | The WebGPU backend |
| `WGPUBackendType_D3D11` | The D3D11 backend |
| `WGPUBackendType_D3D12` | The D3D12 backend |
| `WGPUBackendType_Metal` | The Metal backend |
| `WGPUBackendType_Vulkan` | The Vulkan backend |
| `WGPUBackendType_OpenGL` | The OpenGL backend |
| `WGPUBackendType_OpenGLES` | The OpenGL ES backend |

### enum WGPUBlendFactor {#enum-BlendFactor}


| Value | Description |
|:------|:------------|
| `WGPUBlendFactor_Zero` |  |
| `WGPUBlendFactor_One` |  |
| `WGPUBlendFactor_Src` |  |
| `WGPUBlendFactor_OneMinusSrc` |  |
| `WGPUBlendFactor_SrcAlpha` |  |
| `WGPUBlendFactor_OneMinusSrcAlpha` |  |
| `WGPUBlendFactor_Dst` |  |
| `WGPUBlendFactor_OneMinusDst` |  |
| `WGPUBlendFactor_DstAlpha` |  |
| `WGPUBlendFactor_OneMinusDstAlpha` |  |
| `WGPUBlendFactor_SrcAlphaSaturated` |  |
| `WGPUBlendFactor_Constant` |  |
| `WGPUBlendFactor_OneMinusConstant` |  |

### enum WGPUBlendOperation {#enum-BlendOperation}


| Value | Description |
|:------|:------------|
| `WGPUBlendOperation_Add` |  |
| `WGPUBlendOperation_Subtract` |  |
| `WGPUBlendOperation_ReverseSubtract` |  |
| `WGPUBlendOperation_Min` |  |
| `WGPUBlendOperation_Max` |  |

### enum WGPUBufferBindingType {#enum-BufferBindingType}


| Value | Description |
|:------|:------------|
| `WGPUBufferBindingType_Undefined` |  |
| `WGPUBufferBindingType_Uniform` |  |
| `WGPUBufferBindingType_Storage` |  |
| `WGPUBufferBindingType_ReadOnlyStorage` |  |

### enum WGPUBufferMapAsyncStatus {#enum-BufferMapAsyncStatus}


| Value | Description |
|:------|:------------|
| `WGPUBufferMapAsyncStatus_Success` |  |
| `WGPUBufferMapAsyncStatus_Error` |  |
| `WGPUBufferMapAsyncStatus_Unknown` |  |
| `WGPUBufferMapAsyncStatus_DeviceLost` |  |
| `WGPUBufferMapAsyncStatus_DestroyedBeforeCallback` |  |
| `WGPUBufferMapAsyncStatus_UnmappedBeforeCallback` |  |

### enum WGPUCompareFunction {#enum-CompareFunction}


| Value | Description |
|:------|:------------|
| `WGPUCompareFunction_Undefined` |  |
| `WGPUCompareFunction_Never` |  |
| `WGPUCompareFunction_Less` |  |
| `WGPUCompareFunction_LessEqual` |  |
| `WGPUCompareFunction_Greater` |  |
| `WGPUCompareFunction_GreaterEqual` |  |
| `WGPUCompareFunction_Equal` |  |
| `WGPUCompareFunction_NotEqual` |  |
| `WGPUCompareFunction_Always` |  |

### enum WGPUCompilationInfoRequestStatus {#enum-CompilationInfoRequestStatus}


| Value | Description |
|:------|:------------|
| `WGPUCompilationInfoRequestStatus_Success` |  |
| `WGPUCompilationInfoRequestStatus_Error` |  |
| `WGPUCompilationInfoRequestStatus_DeviceLost` |  |
| `WGPUCompilationInfoRequestStatus_Unknown` |  |

### enum WGPUCompilationMessageType {#enum-CompilationMessageType}


| Value | Description |
|:------|:------------|
| `WGPUCompilationMessageType_Error` |  |
| `WGPUCompilationMessageType_Warning` |  |
| `WGPUCompilationMessageType_Info` |  |

### enum WGPUComputePassTimestampLocation {#enum-ComputePassTimestampLocation}


| Value | Description |
|:------|:------------|
| `WGPUComputePassTimestampLocation_Beginning` |  |
| `WGPUComputePassTimestampLocation_End` |  |

### enum WGPUCreatePipelineAsyncStatus {#enum-CreatePipelineAsyncStatus}


| Value | Description |
|:------|:------------|
| `WGPUCreatePipelineAsyncStatus_Success` |  |
| `WGPUCreatePipelineAsyncStatus_Error` |  |
| `WGPUCreatePipelineAsyncStatus_DeviceLost` |  |
| `WGPUCreatePipelineAsyncStatus_DeviceDestroyed` |  |
| `WGPUCreatePipelineAsyncStatus_Unknown` |  |

### enum WGPUCullMode {#enum-CullMode}


| Value | Description |
|:------|:------------|
| `WGPUCullMode_None` |  |
| `WGPUCullMode_Front` |  |
| `WGPUCullMode_Back` |  |

### enum WGPUDeviceLostReason {#enum-DeviceLostReason}


| Value | Description |
|:------|:------------|
| `WGPUDeviceLostReason_Undefined` |  |
| `WGPUDeviceLostReason_Destroyed` |  |

### enum WGPUErrorFilter {#enum-ErrorFilter}


| Value | Description |
|:------|:------------|
| `WGPUErrorFilter_Validation` |  |
| `WGPUErrorFilter_OutOfMemory` |  |

### enum WGPUErrorType {#enum-ErrorType}


| Value | Description |
|:------|:------------|
| `WGPUErrorType_NoError` |  |
| `WGPUErrorType_Validation` |  |
| `WGPUErrorType_OutOfMemory` |  |
| `WGPUErrorType_Unknown` |  |
| `WGPUErrorType_DeviceLost` |  |

### enum WGPUFeatureName {#enum-FeatureName}


| Value | Description |
|:------|:------------|
| `WGPUFeatureName_Undefined` |  |
| `WGPUFeatureName_DepthClipControl` |  |
| `WGPUFeatureName_Depth32FloatStencil8` |  |
| `WGPUFeatureName_TimestampQuery` |  |
| `WGPUFeatureName_PipelineStatisticsQuery` |  |
| `WGPUFeatureName_TextureCompressionBC` |  |
| `WGPUFeatureName_TextureCompressionETC2` |  |
| `WGPUFeatureName_TextureCompressionASTC` |  |
| `WGPUFeatureName_IndirectFirstInstance` |  |
| `WGPUFeatureName_DawnShaderFloat16` |  |
| `WGPUFeatureName_DawnInternalUsages` |  |
| `WGPUFeatureName_DawnMultiPlanarFormats` |  |
| `WGPUFeatureName_DawnNative` |  |
| `WGPUFeatureName_ChromiumExperimentalDp4a` |  |

### enum WGPUFilterMode {#enum-FilterMode}


| Value | Description |
|:------|:------------|
| `WGPUFilterMode_Nearest` |  |
| `WGPUFilterMode_Linear` |  |

### enum WGPUFrontFace {#enum-FrontFace}


| Value | Description |
|:------|:------------|
| `WGPUFrontFace_CCW` |  |
| `WGPUFrontFace_CW` |  |

### enum WGPUIndexFormat {#enum-IndexFormat}


| Value | Description |
|:------|:------------|
| `WGPUIndexFormat_Undefined` |  |
| `WGPUIndexFormat_Uint16` |  |
| `WGPUIndexFormat_Uint32` |  |

### enum WGPULoadOp {#enum-LoadOp}


| Value | Description |
|:------|:------------|
| `WGPULoadOp_Undefined` |  |
| `WGPULoadOp_Clear` |  |
| `WGPULoadOp_Load` |  |

### enum WGPULoggingType {#enum-LoggingType}


| Value | Description |
|:------|:------------|
| `WGPULoggingType_Verbose` |  |
| `WGPULoggingType_Info` |  |
| `WGPULoggingType_Warning` |  |
| `WGPULoggingType_Error` |  |

### enum WGPUMipmapFilterMode {#enum-MipmapFilterMode}


| Value | Description |
|:------|:------------|
| `WGPUMipmapFilterMode_Nearest` |  |
| `WGPUMipmapFilterMode_Linear` |  |

### enum WGPUPipelineStatisticName {#enum-PipelineStatisticName}


| Value | Description |
|:------|:------------|
| `WGPUPipelineStatisticName_VertexShaderInvocations` |  |
| `WGPUPipelineStatisticName_ClipperInvocations` |  |
| `WGPUPipelineStatisticName_ClipperPrimitivesOut` |  |
| `WGPUPipelineStatisticName_FragmentShaderInvocations` |  |
| `WGPUPipelineStatisticName_ComputeShaderInvocations` |  |

### enum WGPUPowerPreference {#enum-PowerPreference}


| Value | Description |
|:------|:------------|
| `WGPUPowerPreference_Undefined` |  |
| `WGPUPowerPreference_LowPower` |  |
| `WGPUPowerPreference_HighPerformance` |  |

### enum WGPUPresentMode {#enum-PresentMode}


| Value | Description |
|:------|:------------|
| `WGPUPresentMode_Immediate` |  |
| `WGPUPresentMode_Mailbox` |  |
| `WGPUPresentMode_Fifo` |  |

### enum WGPUPrimitiveTopology {#enum-PrimitiveTopology}


| Value | Description |
|:------|:------------|
| `WGPUPrimitiveTopology_PointList` |  |
| `WGPUPrimitiveTopology_LineList` |  |
| `WGPUPrimitiveTopology_LineStrip` |  |
| `WGPUPrimitiveTopology_TriangleList` |  |
| `WGPUPrimitiveTopology_TriangleStrip` |  |

### enum WGPUQueryType {#enum-QueryType}


| Value | Description |
|:------|:------------|
| `WGPUQueryType_Occlusion` |  |
| `WGPUQueryType_PipelineStatistics` |  |
| `WGPUQueryType_Timestamp` |  |

### enum WGPUQueueWorkDoneStatus {#enum-QueueWorkDoneStatus}


| Value | Description |
|:------|:------------|
| `WGPUQueueWorkDoneStatus_Success` |  |
| `WGPUQueueWorkDoneStatus_Error` |  |
| `WGPUQueueWorkDoneStatus_Unknown` |  |
| `WGPUQueueWorkDoneStatus_DeviceLost` |  |

### enum WGPURenderPassTimestampLocation {#enum-RenderPassTimestampLocation}


| Value | Description |
|:------|:------------|
| `WGPURenderPassTimestampLocation_Beginning` |  |
| `WGPURenderPassTimestampLocation_End` |  |

### enum WGPURequestAdapterStatus {#enum-RequestAdapterStatus}


| Value | Description |
|:------|:------------|
| `WGPURequestAdapterStatus_Success` |  |
| `WGPURequestAdapterStatus_Unavailable` |  |
| `WGPURequestAdapterStatus_Error` |  |
| `WGPURequestAdapterStatus_Unknown` |  |

### enum WGPURequestDeviceStatus {#enum-RequestDeviceStatus}


| Value | Description |
|:------|:------------|
| `WGPURequestDeviceStatus_Success` |  |
| `WGPURequestDeviceStatus_Error` |  |
| `WGPURequestDeviceStatus_Unknown` |  |

### enum WGPUSType {#enum-SType}


| Value | Description |
|:------|:------------|
| `WGPUSType_Invalid` |  |
| `WGPUSType_SurfaceDescriptorFromMetalLayer` |  |
| `WGPUSType_SurfaceDescriptorFromWindowsHWND` |  |
| `WGPUSType_SurfaceDescriptorFromXlibWindow` |  |
| `WGPUSType_SurfaceDescriptorFromCanvasHTMLSelector` |  |
| `WGPUSType_ShaderModuleSPIRVDescriptor` |  |
| `WGPUSType_ShaderModuleWGSLDescriptor` |  |
| `WGPUSType_PrimitiveDepthClipControl` |  |
| `WGPUSType_SurfaceDescriptorFromWaylandSurface` |  |
| `WGPUSType_SurfaceDescriptorFromAndroidNativeWindow` |  |
| `WGPUSType_SurfaceDescriptorFromXcbWindow` |  |
| `WGPUSType_SurfaceDescriptorFromWindowsCoreWindow` |  |
| `WGPUSType_ExternalTextureBindingEntry` |  |
| `WGPUSType_ExternalTextureBindingLayout` |  |
| `WGPUSType_SurfaceDescriptorFromWindowsSwapChainPanel` |  |
| `WGPUSType_RenderPassDescriptorMaxDrawCount` |  |
| `WGPUSType_DawnTextureInternalUsageDescriptor` |  |
| `WGPUSType_DawnTogglesDeviceDescriptor` |  |
| `WGPUSType_DawnEncoderInternalUsageDescriptor` |  |
| `WGPUSType_DawnInstanceDescriptor` |  |
| `WGPUSType_DawnCacheDeviceDescriptor` |  |

### enum WGPUSamplerBindingType {#enum-SamplerBindingType}


| Value | Description |
|:------|:------------|
| `WGPUSamplerBindingType_Undefined` |  |
| `WGPUSamplerBindingType_Filtering` |  |
| `WGPUSamplerBindingType_NonFiltering` |  |
| `WGPUSamplerBindingType_Comparison` |  |

### enum WGPUStencilOperation {#enum-StencilOperation}


| Value | Description |
|:------|:------------|
| `WGPUStencilOperation_Keep` |  |
| `WGPUStencilOperation_Zero` |  |
| `WGPUStencilOperation_Replace` |  |
| `WGPUStencilOperation_Invert` |  |
| `WGPUStencilOperation_IncrementClamp` |  |
| `WGPUStencilOperation_DecrementClamp` |  |
| `WGPUStencilOperation_IncrementWrap` |  |
| `WGPUStencilOperation_DecrementWrap` |  |

### enum WGPUStorageTextureAccess {#enum-StorageTextureAccess}


| Value | Description |
|:------|:------------|
| `WGPUStorageTextureAccess_Undefined` |  |
| `WGPUStorageTextureAccess_WriteOnly` |  |

### enum WGPUStoreOp {#enum-StoreOp}


| Value | Description |
|:------|:------------|
| `WGPUStoreOp_Undefined` |  |
| `WGPUStoreOp_Store` |  |
| `WGPUStoreOp_Discard` |  |

### enum WGPUTextureAspect {#enum-TextureAspect}


| Value | Description |
|:------|:------------|
| `WGPUTextureAspect_All` |  |
| `WGPUTextureAspect_StencilOnly` |  |
| `WGPUTextureAspect_DepthOnly` |  |
| `WGPUTextureAspect_Plane0Only` |  |
| `WGPUTextureAspect_Plane1Only` |  |

### enum WGPUTextureComponentType {#enum-TextureComponentType}


| Value | Description |
|:------|:------------|
| `WGPUTextureComponentType_Float` |  |
| `WGPUTextureComponentType_Sint` |  |
| `WGPUTextureComponentType_Uint` |  |
| `WGPUTextureComponentType_DepthComparison` |  |

### enum WGPUTextureDimension {#enum-TextureDimension}


| Value | Description |
|:------|:------------|
| `WGPUTextureDimension_1D` |  |
| `WGPUTextureDimension_2D` |  |
| `WGPUTextureDimension_3D` |  |

### enum WGPUTextureFormat {#enum-TextureFormat}


| Value | Description |
|:------|:------------|
| `WGPUTextureFormat_Undefined` |  |
| `WGPUTextureFormat_R8Unorm` |  |
| `WGPUTextureFormat_R8Snorm` |  |
| `WGPUTextureFormat_R8Uint` |  |
| `WGPUTextureFormat_R8Sint` |  |
| `WGPUTextureFormat_R16Uint` |  |
| `WGPUTextureFormat_R16Sint` |  |
| `WGPUTextureFormat_R16Float` |  |
| `WGPUTextureFormat_RG8Unorm` |  |
| `WGPUTextureFormat_RG8Snorm` |  |
| `WGPUTextureFormat_RG8Uint` |  |
| `WGPUTextureFormat_RG8Sint` |  |
| `WGPUTextureFormat_R32Float` |  |
| `WGPUTextureFormat_R32Uint` |  |
| `WGPUTextureFormat_R32Sint` |  |
| `WGPUTextureFormat_RG16Uint` |  |
| `WGPUTextureFormat_RG16Sint` |  |
| `WGPUTextureFormat_RG16Float` |  |
| `WGPUTextureFormat_RGBA8Unorm` |  |
| `WGPUTextureFormat_RGBA8UnormSrgb` |  |
| `WGPUTextureFormat_RGBA8Snorm` |  |
| `WGPUTextureFormat_RGBA8Uint` |  |
| `WGPUTextureFormat_RGBA8Sint` |  |
| `WGPUTextureFormat_BGRA8Unorm` |  |
| `WGPUTextureFormat_BGRA8UnormSrgb` |  |
| `WGPUTextureFormat_RGB10A2Unorm` |  |
| `WGPUTextureFormat_RG11B10Ufloat` |  |
| `WGPUTextureFormat_RGB9E5Ufloat` |  |
| `WGPUTextureFormat_RG32Float` |  |
| `WGPUTextureFormat_RG32Uint` |  |
| `WGPUTextureFormat_RG32Sint` |  |
| `WGPUTextureFormat_RGBA16Uint` |  |
| `WGPUTextureFormat_RGBA16Sint` |  |
| `WGPUTextureFormat_RGBA16Float` |  |
| `WGPUTextureFormat_RGBA32Float` |  |
| `WGPUTextureFormat_RGBA32Uint` |  |
| `WGPUTextureFormat_RGBA32Sint` |  |
| `WGPUTextureFormat_Stencil8` |  |
| `WGPUTextureFormat_Depth16Unorm` |  |
| `WGPUTextureFormat_Depth24Plus` |  |
| `WGPUTextureFormat_Depth24PlusStencil8` |  |
| `WGPUTextureFormat_Depth32Float` |  |
| `WGPUTextureFormat_Depth32FloatStencil8` |  |
| `WGPUTextureFormat_BC1RGBAUnorm` |  |
| `WGPUTextureFormat_BC1RGBAUnormSrgb` |  |
| `WGPUTextureFormat_BC2RGBAUnorm` |  |
| `WGPUTextureFormat_BC2RGBAUnormSrgb` |  |
| `WGPUTextureFormat_BC3RGBAUnorm` |  |
| `WGPUTextureFormat_BC3RGBAUnormSrgb` |  |
| `WGPUTextureFormat_BC4RUnorm` |  |
| `WGPUTextureFormat_BC4RSnorm` |  |
| `WGPUTextureFormat_BC5RGUnorm` |  |
| `WGPUTextureFormat_BC5RGSnorm` |  |
| `WGPUTextureFormat_BC6HRGBUfloat` |  |
| `WGPUTextureFormat_BC6HRGBFloat` |  |
| `WGPUTextureFormat_BC7RGBAUnorm` |  |
| `WGPUTextureFormat_BC7RGBAUnormSrgb` |  |
| `WGPUTextureFormat_ETC2RGB8Unorm` |  |
| `WGPUTextureFormat_ETC2RGB8UnormSrgb` |  |
| `WGPUTextureFormat_ETC2RGB8A1Unorm` |  |
| `WGPUTextureFormat_ETC2RGB8A1UnormSrgb` |  |
| `WGPUTextureFormat_ETC2RGBA8Unorm` |  |
| `WGPUTextureFormat_ETC2RGBA8UnormSrgb` |  |
| `WGPUTextureFormat_EACR11Unorm` |  |
| `WGPUTextureFormat_EACR11Snorm` |  |
| `WGPUTextureFormat_EACRG11Unorm` |  |
| `WGPUTextureFormat_EACRG11Snorm` |  |
| `WGPUTextureFormat_ASTC4x4Unorm` |  |
| `WGPUTextureFormat_ASTC4x4UnormSrgb` |  |
| `WGPUTextureFormat_ASTC5x4Unorm` |  |
| `WGPUTextureFormat_ASTC5x4UnormSrgb` |  |
| `WGPUTextureFormat_ASTC5x5Unorm` |  |
| `WGPUTextureFormat_ASTC5x5UnormSrgb` |  |
| `WGPUTextureFormat_ASTC6x5Unorm` |  |
| `WGPUTextureFormat_ASTC6x5UnormSrgb` |  |
| `WGPUTextureFormat_ASTC6x6Unorm` |  |
| `WGPUTextureFormat_ASTC6x6UnormSrgb` |  |
| `WGPUTextureFormat_ASTC8x5Unorm` |  |
| `WGPUTextureFormat_ASTC8x5UnormSrgb` |  |
| `WGPUTextureFormat_ASTC8x6Unorm` |  |
| `WGPUTextureFormat_ASTC8x6UnormSrgb` |  |
| `WGPUTextureFormat_ASTC8x8Unorm` |  |
| `WGPUTextureFormat_ASTC8x8UnormSrgb` |  |
| `WGPUTextureFormat_ASTC10x5Unorm` |  |
| `WGPUTextureFormat_ASTC10x5UnormSrgb` |  |
| `WGPUTextureFormat_ASTC10x6Unorm` |  |
| `WGPUTextureFormat_ASTC10x6UnormSrgb` |  |
| `WGPUTextureFormat_ASTC10x8Unorm` |  |
| `WGPUTextureFormat_ASTC10x8UnormSrgb` |  |
| `WGPUTextureFormat_ASTC10x10Unorm` |  |
| `WGPUTextureFormat_ASTC10x10UnormSrgb` |  |
| `WGPUTextureFormat_ASTC12x10Unorm` |  |
| `WGPUTextureFormat_ASTC12x10UnormSrgb` |  |
| `WGPUTextureFormat_ASTC12x12Unorm` |  |
| `WGPUTextureFormat_ASTC12x12UnormSrgb` |  |
| `WGPUTextureFormat_R8BG8Biplanar420Unorm` |  |

### enum WGPUTextureSampleType {#enum-TextureSampleType}


| Value | Description |
|:------|:------------|
| `WGPUTextureSampleType_Undefined` |  |
| `WGPUTextureSampleType_Float` |  |
| `WGPUTextureSampleType_UnfilterableFloat` |  |
| `WGPUTextureSampleType_Depth` |  |
| `WGPUTextureSampleType_Sint` |  |
| `WGPUTextureSampleType_Uint` |  |

### enum WGPUTextureViewDimension {#enum-TextureViewDimension}


| Value | Description |
|:------|:------------|
| `WGPUTextureViewDimension_Undefined` |  |
| `WGPUTextureViewDimension_1D` |  |
| `WGPUTextureViewDimension_2D` |  |
| `WGPUTextureViewDimension_2DArray` |  |
| `WGPUTextureViewDimension_Cube` |  |
| `WGPUTextureViewDimension_CubeArray` |  |
| `WGPUTextureViewDimension_3D` |  |

### enum WGPUVertexFormat {#enum-VertexFormat}


| Value | Description |
|:------|:------------|
| `WGPUVertexFormat_Undefined` |  |
| `WGPUVertexFormat_Uint8x2` |  |
| `WGPUVertexFormat_Uint8x4` |  |
| `WGPUVertexFormat_Sint8x2` |  |
| `WGPUVertexFormat_Sint8x4` |  |
| `WGPUVertexFormat_Unorm8x2` |  |
| `WGPUVertexFormat_Unorm8x4` |  |
| `WGPUVertexFormat_Snorm8x2` |  |
| `WGPUVertexFormat_Snorm8x4` |  |
| `WGPUVertexFormat_Uint16x2` |  |
| `WGPUVertexFormat_Uint16x4` |  |
| `WGPUVertexFormat_Sint16x2` |  |
| `WGPUVertexFormat_Sint16x4` |  |
| `WGPUVertexFormat_Unorm16x2` |  |
| `WGPUVertexFormat_Unorm16x4` |  |
| `WGPUVertexFormat_Snorm16x2` |  |
| `WGPUVertexFormat_Snorm16x4` |  |
| `WGPUVertexFormat_Float16x2` |  |
| `WGPUVertexFormat_Float16x4` |  |
| `WGPUVertexFormat_Float32` |  |
| `WGPUVertexFormat_Float32x2` |  |
| `WGPUVertexFormat_Float32x3` |  |
| `WGPUVertexFormat_Float32x4` |  |
| `WGPUVertexFormat_Uint32` |  |
| `WGPUVertexFormat_Uint32x2` |  |
| `WGPUVertexFormat_Uint32x3` |  |
| `WGPUVertexFormat_Uint32x4` |  |
| `WGPUVertexFormat_Sint32` |  |
| `WGPUVertexFormat_Sint32x2` |  |
| `WGPUVertexFormat_Sint32x3` |  |
| `WGPUVertexFormat_Sint32x4` |  |

### enum WGPUVertexStepMode {#enum-VertexStepMode}


| Value | Description |
|:------|:------------|
| `WGPUVertexStepMode_Vertex` |  |
| `WGPUVertexStepMode_Instance` |  |
| `WGPUVertexStepMode_VertexBufferNotUsed` |  |

## Bitmasks

Each bitmask enum provides an associated `Flags` typedef for which is,
in effect, a uint32_t type. The `Flags` type is what is used in method
signatures.
### enum WGPUBufferUsage [bitmask] {#bitmask-BufferUsage}


| Value | Description |
|:------|:------------|
| `WGPUBufferUsage_None` |  |
| `WGPUBufferUsage_MapRead` |  |
| `WGPUBufferUsage_MapWrite` |  |
| `WGPUBufferUsage_CopySrc` |  |
| `WGPUBufferUsage_CopyDst` |  |
| `WGPUBufferUsage_Index` |  |
| `WGPUBufferUsage_Vertex` |  |
| `WGPUBufferUsage_Uniform` |  |
| `WGPUBufferUsage_Storage` |  |
| `WGPUBufferUsage_Indirect` |  |
| `WGPUBufferUsage_QueryResolve` |  |

`typedef WGPUFlags WGPUBufferUsageFlags`
### enum WGPUColorWriteMask [bitmask] {#bitmask-ColorWriteMask}


| Value | Description |
|:------|:------------|
| `WGPUColorWriteMask_None` |  |
| `WGPUColorWriteMask_Red` |  |
| `WGPUColorWriteMask_Green` |  |
| `WGPUColorWriteMask_Blue` |  |
| `WGPUColorWriteMask_Alpha` |  |
| `WGPUColorWriteMask_All` |  |

`typedef WGPUFlags WGPUColorWriteMaskFlags`
### enum WGPUMapMode [bitmask] {#bitmask-MapMode}


| Value | Description |
|:------|:------------|
| `WGPUMapMode_None` |  |
| `WGPUMapMode_Read` |  |
| `WGPUMapMode_Write` |  |

`typedef WGPUFlags WGPUMapModeFlags`
### enum WGPUShaderStage [bitmask] {#bitmask-ShaderStage}


| Value | Description |
|:------|:------------|
| `WGPUShaderStage_None` |  |
| `WGPUShaderStage_Vertex` |  |
| `WGPUShaderStage_Fragment` |  |
| `WGPUShaderStage_Compute` |  |

`typedef WGPUFlags WGPUShaderStageFlags`
### enum WGPUTextureUsage [bitmask] {#bitmask-TextureUsage}

Determine how a GPUTexture maybe be used after creation.

See [GPUTextureUsage](https://webgpu.dev/#namespacedef-gputextureusage) for more information.


| Value | Description |
|:------|:------------|
| `WGPUTextureUsage_None` | No usage specified. |
| `WGPUTextureUsage_CopySrc` | The texture can be used as the source of a copy operation. |
| `WGPUTextureUsage_CopyDst` | The texture can be used as the destination of a copy operation. |
| `WGPUTextureUsage_TextureBinding` | The texture can be bound for use as a sampled texture in a shader. |
| `WGPUTextureUsage_StorageBinding` | The texture can be bound for use as a storage texture in a shader. |
| `WGPUTextureUsage_RenderAttachment` | The texture can be used as a colour or depth/stencil attachment in a render pass. |
| `WGPUTextureUsage_Present` | The texture can be used to "present" the texture on screen. |

`typedef WGPUFlags WGPUTextureUsageFlags`
## Functions

<div class='function' markdown=1>

### wgpuCreateInstance {#function-CreateInstance}

<div class='content' markdown=1>

Creates an instance of the Dawn WebGPU system

<div class='signature' markdown=1>

[WGPUInstance]({{ '/api/c.html#class-Instance' | relative_url }}) wgpuCreateInstance([WGPUInstanceDescriptor]({{ '/api/c.html#structure-InstanceDescriptor' | relative_url }}) const\* descriptor)
</div>

#### Returns

The created [WGPUInstance]({{ '/api/c.html#class-Instance' | relative_url }}).

#### Arguments

* *descriptor*: The [WGPUInstanceDescriptor]({{ '/api/c.html#structure-InstanceDescriptor' | relative_url }}) pointer. Maybe `NULL` to create a default instance.

</div>

</div>

<div class='function' markdown=1>

### wgpuGetProcAddress {#function-GetProcAddress}

<div class='content' markdown=1>

Returns the function pointer for the requested WebGPU API method *procName*.

<div class='signature' markdown=1>

[WGPUProc]({{ '/api/c.html#function-pointer-Proc' | relative_url }}) wgpuGetProcAddress([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, char const\* procName)
</div>

#### Returns

The [WGPUProc]({{ '/api/c.html#function-pointer-Proc' | relative_url }}) function pointer if it exists, NULL otherwise.

#### Arguments

* *device*: The [WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) to retrieve the proc for
* *procName*: The name of the pointer to retrieve

</div>

</div>

## Function Pointers

<div class='function' markdown=1>

### WGPUBufferMapCallback {#function-pointer-BufferMapCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;WGPUBufferMapCallback)([WGPUBufferMapAsyncStatus]({{ '/api/c.html#enum-BufferMapAsyncStatus' | relative_url }}) status, void \* userdata)
</div>

#### Arguments

* *status*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### WGPUCompilationInfoCallback {#function-pointer-CompilationInfoCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;WGPUCompilationInfoCallback)([WGPUCompilationInfoRequestStatus]({{ '/api/c.html#enum-CompilationInfoRequestStatus' | relative_url }}) status, [WGPUCompilationInfo]({{ '/api/c.html#structure-CompilationInfo' | relative_url }}) const\* compilationInfo, void \* userdata)
</div>

#### Arguments

* *status*: 
* *compilationInfo*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### WGPUCreateComputePipelineAsyncCallback {#function-pointer-CreateComputePipelineAsyncCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;WGPUCreateComputePipelineAsyncCallback)([WGPUCreatePipelineAsyncStatus]({{ '/api/c.html#enum-CreatePipelineAsyncStatus' | relative_url }}) status, [WGPUComputePipeline]({{ '/api/c.html#class-ComputePipeline' | relative_url }}) pipeline, char const\* message, void \* userdata)
</div>

#### Arguments

* *status*: 
* *pipeline*: 
* *message*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### WGPUCreateRenderPipelineAsyncCallback {#function-pointer-CreateRenderPipelineAsyncCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;WGPUCreateRenderPipelineAsyncCallback)([WGPUCreatePipelineAsyncStatus]({{ '/api/c.html#enum-CreatePipelineAsyncStatus' | relative_url }}) status, [WGPURenderPipeline]({{ '/api/c.html#class-RenderPipeline' | relative_url }}) pipeline, char const\* message, void \* userdata)
</div>

#### Arguments

* *status*: 
* *pipeline*: 
* *message*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### WGPUDeviceLostCallback {#function-pointer-DeviceLostCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;WGPUDeviceLostCallback)([WGPUDeviceLostReason]({{ '/api/c.html#enum-DeviceLostReason' | relative_url }}) reason, char const\* message, void \* userdata)
</div>

#### Arguments

* *reason*: 
* *message*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### WGPUErrorCallback {#function-pointer-ErrorCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;WGPUErrorCallback)([WGPUErrorType]({{ '/api/c.html#enum-ErrorType' | relative_url }}) type, char const\* message, void \* userdata)
</div>

#### Arguments

* *type*: 
* *message*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### WGPULoggingCallback {#function-pointer-LoggingCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;WGPULoggingCallback)([WGPULoggingType]({{ '/api/c.html#enum-LoggingType' | relative_url }}) type, char const\* message, void \* userdata)
</div>

#### Arguments

* *type*: 
* *message*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### WGPUProc {#function-pointer-Proc}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;WGPUProc)()
</div>

</div>

</div>

<div class='function' markdown=1>

### WGPUQueueWorkDoneCallback {#function-pointer-QueueWorkDoneCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;WGPUQueueWorkDoneCallback)([WGPUQueueWorkDoneStatus]({{ '/api/c.html#enum-QueueWorkDoneStatus' | relative_url }}) status, void \* userdata)
</div>

#### Arguments

* *status*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### WGPURequestAdapterCallback {#function-pointer-RequestAdapterCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;WGPURequestAdapterCallback)([WGPURequestAdapterStatus]({{ '/api/c.html#enum-RequestAdapterStatus' | relative_url }}) status, [WGPUAdapter]({{ '/api/c.html#class-Adapter' | relative_url }}) adapter, char const\* message, void \* userdata)
</div>

#### Arguments

* *status*: 
* *adapter*: 
* *message*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### WGPURequestDeviceCallback {#function-pointer-RequestDeviceCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;WGPURequestDeviceCallback)([WGPURequestDeviceStatus]({{ '/api/c.html#enum-RequestDeviceStatus' | relative_url }}) status, [WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, char const\* message, void \* userdata)
</div>

#### Arguments

* *status*: 
* *device*: 
* *message*: 
* *userdata*: 

</div>

</div>

## Structures

### struct WGPUAdapterProperties {#structure-AdapterProperties}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStructOut* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| uint32_t vendorID | The PCIe ID if available but can be other values on systems which do not provide a PCIe ID. |
| char const\* vendorName | The name of the vendor of the adapter, if available. Empty string otherwise. |
| char const\* architecture | The name of the family or class of GPUs the adapter belongs to, if available. Empty string otherwise. |
| uint32_t deviceID | The vendor-specific device identifier. |
| char const\* name | A vendor-specific identifier for the adapter, if available. Empty string otherwise. |
| char const\* driverDescription | A human readable string describing the adapter as reported by the driver, if available. Empty string otherwise. |
| [WGPUAdapterType]({{ '/api/c.html#enum-AdapterType' | relative_url }}) adapterType | The type of the adapter |
| [WGPUBackendType]({{ '/api/c.html#enum-BackendType' | relative_url }}) backendType | The backend platform used by the adapter |

### struct WGPUBindGroupDescriptor {#structure-BindGroupDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUBindGroupLayout]({{ '/api/c.html#class-BindGroupLayout' | relative_url }}) layout |  |
| uint32_t entryCount |  |
| [WGPUBindGroupEntry]({{ '/api/c.html#structure-BindGroupEntry' | relative_url }}) const\* entries |  |

### struct WGPUBindGroupEntry {#structure-BindGroupEntry}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| uint32_t binding |  |
| [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer |  |
| uint64_t offset |  |
| uint64_t size |  |
| [WGPUSampler]({{ '/api/c.html#class-Sampler' | relative_url }}) sampler |  |
| [WGPUTextureView]({{ '/api/c.html#class-TextureView' | relative_url }}) textureView |  |

#### Chainable Structures

 * [WGPUExternalTextureBindingEntry]({{ '/api/c.html#structure-ExternalTextureBindingEntry' | relative_url }})

### struct WGPUBindGroupLayoutDescriptor {#structure-BindGroupLayoutDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| uint32_t entryCount |  |
| [WGPUBindGroupLayoutEntry]({{ '/api/c.html#structure-BindGroupLayoutEntry' | relative_url }}) const\* entries |  |

### struct WGPUBindGroupLayoutEntry {#structure-BindGroupLayoutEntry}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| uint32_t binding |  |
| [WGPUShaderStage]({{ '/api/c.html#bitmask-ShaderStage' | relative_url }}) visibility |  |
| [WGPUBufferBindingLayout]({{ '/api/c.html#structure-BufferBindingLayout' | relative_url }}) buffer |  |
| [WGPUSamplerBindingLayout]({{ '/api/c.html#structure-SamplerBindingLayout' | relative_url }}) sampler |  |
| [WGPUTextureBindingLayout]({{ '/api/c.html#structure-TextureBindingLayout' | relative_url }}) texture |  |
| [WGPUStorageTextureBindingLayout]({{ '/api/c.html#structure-StorageTextureBindingLayout' | relative_url }}) storageTexture |  |

#### Chainable Structures

 * [WGPUExternalTextureBindingLayout]({{ '/api/c.html#structure-ExternalTextureBindingLayout' | relative_url }})

### struct WGPUBlendComponent {#structure-BlendComponent}

| Members | Description |
|:--------|:------------|
| [WGPUBlendOperation]({{ '/api/c.html#enum-BlendOperation' | relative_url }}) operation |  |
| [WGPUBlendFactor]({{ '/api/c.html#enum-BlendFactor' | relative_url }}) srcFactor |  |
| [WGPUBlendFactor]({{ '/api/c.html#enum-BlendFactor' | relative_url }}) dstFactor |  |

### struct WGPUBlendState {#structure-BlendState}

| Members | Description |
|:--------|:------------|
| [WGPUBlendComponent]({{ '/api/c.html#structure-BlendComponent' | relative_url }}) color |  |
| [WGPUBlendComponent]({{ '/api/c.html#structure-BlendComponent' | relative_url }}) alpha |  |

### struct WGPUBufferBindingLayout {#structure-BufferBindingLayout}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUBufferBindingType]({{ '/api/c.html#enum-BufferBindingType' | relative_url }}) type |  |
| bool hasDynamicOffset |  |
| uint64_t minBindingSize |  |

### struct WGPUBufferDescriptor {#structure-BufferDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUBufferUsage]({{ '/api/c.html#bitmask-BufferUsage' | relative_url }}) usage |  |
| uint64_t size |  |
| bool mappedAtCreation |  |

### struct WGPUColor {#structure-Color}

| Members | Description |
|:--------|:------------|
| double r |  |
| double g |  |
| double b |  |
| double a |  |

### struct WGPUColorTargetState {#structure-ColorTargetState}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUTextureFormat]({{ '/api/c.html#enum-TextureFormat' | relative_url }}) format |  |
| [WGPUBlendState]({{ '/api/c.html#structure-BlendState' | relative_url }}) const\* blend |  |
| [WGPUColorWriteMask]({{ '/api/c.html#bitmask-ColorWriteMask' | relative_url }}) writeMask |  |

### struct WGPUCommandBufferDescriptor {#structure-CommandBufferDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |

### struct WGPUCommandEncoderDescriptor {#structure-CommandEncoderDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |

#### Chainable Structures

 * [WGPUDawnEncoderInternalUsageDescriptor]({{ '/api/c.html#structure-DawnEncoderInternalUsageDescriptor' | relative_url }})

### struct WGPUCompilationInfo {#structure-CompilationInfo}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| uint32_t messageCount |  |
| [WGPUCompilationMessage]({{ '/api/c.html#structure-CompilationMessage' | relative_url }}) const\* messages |  |

### struct WGPUCompilationMessage {#structure-CompilationMessage}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* message |  |
| [WGPUCompilationMessageType]({{ '/api/c.html#enum-CompilationMessageType' | relative_url }}) type |  |
| uint64_t lineNum |  |
| uint64_t linePos |  |
| uint64_t offset |  |
| uint64_t length |  |

### struct WGPUComputePassDescriptor {#structure-ComputePassDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| uint32_t timestampWriteCount |  |
| [WGPUComputePassTimestampWrite]({{ '/api/c.html#structure-ComputePassTimestampWrite' | relative_url }}) const\* timestampWrites |  |

### struct WGPUComputePassTimestampWrite {#structure-ComputePassTimestampWrite}

| Members | Description |
|:--------|:------------|
| [WGPUQuerySet]({{ '/api/c.html#class-QuerySet' | relative_url }}) querySet |  |
| uint32_t queryIndex |  |
| [WGPUComputePassTimestampLocation]({{ '/api/c.html#enum-ComputePassTimestampLocation' | relative_url }}) location |  |

### struct WGPUComputePipelineDescriptor {#structure-ComputePipelineDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUPipelineLayout]({{ '/api/c.html#class-PipelineLayout' | relative_url }}) layout |  |
| [WGPUProgrammableStageDescriptor]({{ '/api/c.html#structure-ProgrammableStageDescriptor' | relative_url }}) compute |  |

### struct WGPUConstantEntry {#structure-ConstantEntry}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* key |  |
| double value |  |

### struct WGPUCopyTextureForBrowserOptions {#structure-CopyTextureForBrowserOptions}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| bool flipY |  |
| bool needsColorSpaceConversion |  |
| [WGPUAlphaMode]({{ '/api/c.html#enum-AlphaMode' | relative_url }}) srcAlphaMode |  |
| float const\* srcTransferFunctionParameters |  |
| float const\* conversionMatrix |  |
| float const\* dstTransferFunctionParameters |  |
| [WGPUAlphaMode]({{ '/api/c.html#enum-AlphaMode' | relative_url }}) dstAlphaMode |  |
| bool internalUsage |  |

### struct WGPUDawnCacheDeviceDescriptor {#structure-DawnCacheDeviceDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| char const\* isolationKey |  |

#### Chain Parent Structures

 * [WGPUDeviceDescriptor]({{ '/api/c.html#structure-DeviceDescriptor' | relative_url }})

### struct WGPUDawnEncoderInternalUsageDescriptor {#structure-DawnEncoderInternalUsageDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| bool useInternalUsages |  |

#### Chain Parent Structures

 * [WGPUCommandEncoderDescriptor]({{ '/api/c.html#structure-CommandEncoderDescriptor' | relative_url }})

### struct WGPUDawnInstanceDescriptor {#structure-DawnInstanceDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| uint32_t additionalRuntimeSearchPathsCount |  |
| char const\*const\* additionalRuntimeSearchPaths |  |

#### Chain Parent Structures

 * [WGPUInstanceDescriptor]({{ '/api/c.html#structure-InstanceDescriptor' | relative_url }})

### struct WGPUDawnTextureInternalUsageDescriptor {#structure-DawnTextureInternalUsageDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| [WGPUTextureUsage]({{ '/api/c.html#bitmask-TextureUsage' | relative_url }}) internalUsage |  |

#### Chain Parent Structures

 * [WGPUTextureDescriptor]({{ '/api/c.html#structure-TextureDescriptor' | relative_url }})

### struct WGPUDawnTogglesDeviceDescriptor {#structure-DawnTogglesDeviceDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| uint32_t forceEnabledTogglesCount |  |
| char const\*const\* forceEnabledToggles |  |
| uint32_t forceDisabledTogglesCount |  |
| char const\*const\* forceDisabledToggles |  |

#### Chain Parent Structures

 * [WGPUDeviceDescriptor]({{ '/api/c.html#structure-DeviceDescriptor' | relative_url }})

### struct WGPUDepthStencilState {#structure-DepthStencilState}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUTextureFormat]({{ '/api/c.html#enum-TextureFormat' | relative_url }}) format |  |
| bool depthWriteEnabled |  |
| [WGPUCompareFunction]({{ '/api/c.html#enum-CompareFunction' | relative_url }}) depthCompare |  |
| [WGPUStencilFaceState]({{ '/api/c.html#structure-StencilFaceState' | relative_url }}) stencilFront |  |
| [WGPUStencilFaceState]({{ '/api/c.html#structure-StencilFaceState' | relative_url }}) stencilBack |  |
| uint32_t stencilReadMask |  |
| uint32_t stencilWriteMask |  |
| int32_t depthBias |  |
| float depthBiasSlopeScale |  |
| float depthBiasClamp |  |

### struct WGPUDeviceDescriptor {#structure-DeviceDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| uint32_t requiredFeaturesCount |  |
| [WGPUFeatureName]({{ '/api/c.html#enum-FeatureName' | relative_url }}) const\* requiredFeatures |  |
| [WGPURequiredLimits]({{ '/api/c.html#structure-RequiredLimits' | relative_url }}) const\* requiredLimits |  |
| [WGPUQueueDescriptor]({{ '/api/c.html#structure-QueueDescriptor' | relative_url }}) defaultQueue |  |

#### Chainable Structures

 * [WGPUDawnTogglesDeviceDescriptor]({{ '/api/c.html#structure-DawnTogglesDeviceDescriptor' | relative_url }})
 * [WGPUDawnCacheDeviceDescriptor]({{ '/api/c.html#structure-DawnCacheDeviceDescriptor' | relative_url }})

### struct WGPUExtent3D {#structure-Extent3D}

| Members | Description |
|:--------|:------------|
| uint32_t width |  |
| uint32_t height |  |
| uint32_t depthOrArrayLayers |  |

### struct WGPUExternalTextureBindingEntry {#structure-ExternalTextureBindingEntry}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| [WGPUExternalTexture]({{ '/api/c.html#class-ExternalTexture' | relative_url }}) externalTexture |  |

#### Chain Parent Structures

 * [WGPUBindGroupEntry]({{ '/api/c.html#structure-BindGroupEntry' | relative_url }})

### struct WGPUExternalTextureBindingLayout {#structure-ExternalTextureBindingLayout}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|

#### Chain Parent Structures

 * [WGPUBindGroupLayoutEntry]({{ '/api/c.html#structure-BindGroupLayoutEntry' | relative_url }})

### struct WGPUExternalTextureDescriptor {#structure-ExternalTextureDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUTextureView]({{ '/api/c.html#class-TextureView' | relative_url }}) plane0 |  |
| [WGPUTextureView]({{ '/api/c.html#class-TextureView' | relative_url }}) plane1 |  |
| bool doYuvToRgbConversionOnly |  |
| float const\* yuvToRgbConversionMatrix |  |
| float const\* srcTransferFunctionParameters |  |
| float const\* dstTransferFunctionParameters |  |
| float const\* gamutConversionMatrix |  |

### struct WGPUFragmentState {#structure-FragmentState}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUShaderModule]({{ '/api/c.html#class-ShaderModule' | relative_url }}) module |  |
| char const\* entryPoint |  |
| uint32_t constantCount |  |
| [WGPUConstantEntry]({{ '/api/c.html#structure-ConstantEntry' | relative_url }}) const\* constants |  |
| uint32_t targetCount |  |
| [WGPUColorTargetState]({{ '/api/c.html#structure-ColorTargetState' | relative_url }}) const\* targets |  |

### struct WGPUImageCopyBuffer {#structure-ImageCopyBuffer}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUTextureDataLayout]({{ '/api/c.html#structure-TextureDataLayout' | relative_url }}) layout |  |
| [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer |  |

### struct WGPUImageCopyTexture {#structure-ImageCopyTexture}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUTexture]({{ '/api/c.html#class-Texture' | relative_url }}) texture |  |
| uint32_t mipLevel |  |
| [WGPUOrigin3D]({{ '/api/c.html#structure-Origin3D' | relative_url }}) origin |  |
| [WGPUTextureAspect]({{ '/api/c.html#enum-TextureAspect' | relative_url }}) aspect |  |

### struct WGPUInstanceDescriptor {#structure-InstanceDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |

#### Chainable Structures

 * [WGPUDawnInstanceDescriptor]({{ '/api/c.html#structure-DawnInstanceDescriptor' | relative_url }})

### struct WGPULimits {#structure-Limits}

| Members | Description |
|:--------|:------------|
| uint32_t maxTextureDimension1D |  |
| uint32_t maxTextureDimension2D |  |
| uint32_t maxTextureDimension3D |  |
| uint32_t maxTextureArrayLayers |  |
| uint32_t maxBindGroups |  |
| uint32_t maxBindingsPerBindGroup |  |
| uint32_t maxDynamicUniformBuffersPerPipelineLayout |  |
| uint32_t maxDynamicStorageBuffersPerPipelineLayout |  |
| uint32_t maxSampledTexturesPerShaderStage |  |
| uint32_t maxSamplersPerShaderStage |  |
| uint32_t maxStorageBuffersPerShaderStage |  |
| uint32_t maxStorageTexturesPerShaderStage |  |
| uint32_t maxUniformBuffersPerShaderStage |  |
| uint64_t maxUniformBufferBindingSize |  |
| uint64_t maxStorageBufferBindingSize |  |
| uint32_t minUniformBufferOffsetAlignment |  |
| uint32_t minStorageBufferOffsetAlignment |  |
| uint32_t maxVertexBuffers |  |
| uint32_t maxVertexAttributes |  |
| uint32_t maxVertexBufferArrayStride |  |
| uint32_t maxInterStageShaderComponents |  |
| uint32_t maxInterStageShaderVariables |  |
| uint32_t maxColorAttachments |  |
| uint32_t maxComputeWorkgroupStorageSize |  |
| uint32_t maxComputeInvocationsPerWorkgroup |  |
| uint32_t maxComputeWorkgroupSizeX |  |
| uint32_t maxComputeWorkgroupSizeY |  |
| uint32_t maxComputeWorkgroupSizeZ |  |
| uint32_t maxComputeWorkgroupsPerDimension |  |

### struct WGPUMultisampleState {#structure-MultisampleState}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| uint32_t count |  |
| uint32_t mask |  |
| bool alphaToCoverageEnabled |  |

### struct WGPUOrigin3D {#structure-Origin3D}

| Members | Description |
|:--------|:------------|
| uint32_t x |  |
| uint32_t y |  |
| uint32_t z |  |

### struct WGPUPipelineLayoutDescriptor {#structure-PipelineLayoutDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| uint32_t bindGroupLayoutCount |  |
| [WGPUBindGroupLayout]({{ '/api/c.html#class-BindGroupLayout' | relative_url }}) const\* bindGroupLayouts |  |

### struct WGPUPrimitiveDepthClipControl {#structure-PrimitiveDepthClipControl}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| bool unclippedDepth |  |

#### Chain Parent Structures

 * [WGPUPrimitiveState]({{ '/api/c.html#structure-PrimitiveState' | relative_url }})

### struct WGPUPrimitiveState {#structure-PrimitiveState}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUPrimitiveTopology]({{ '/api/c.html#enum-PrimitiveTopology' | relative_url }}) topology |  |
| [WGPUIndexFormat]({{ '/api/c.html#enum-IndexFormat' | relative_url }}) stripIndexFormat |  |
| [WGPUFrontFace]({{ '/api/c.html#enum-FrontFace' | relative_url }}) frontFace |  |
| [WGPUCullMode]({{ '/api/c.html#enum-CullMode' | relative_url }}) cullMode |  |

#### Chainable Structures

 * [WGPUPrimitiveDepthClipControl]({{ '/api/c.html#structure-PrimitiveDepthClipControl' | relative_url }})

### struct WGPUProgrammableStageDescriptor {#structure-ProgrammableStageDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUShaderModule]({{ '/api/c.html#class-ShaderModule' | relative_url }}) module |  |
| char const\* entryPoint |  |
| uint32_t constantCount |  |
| [WGPUConstantEntry]({{ '/api/c.html#structure-ConstantEntry' | relative_url }}) const\* constants |  |

### struct WGPUQuerySetDescriptor {#structure-QuerySetDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUQueryType]({{ '/api/c.html#enum-QueryType' | relative_url }}) type |  |
| uint32_t count |  |
| [WGPUPipelineStatisticName]({{ '/api/c.html#enum-PipelineStatisticName' | relative_url }}) const\* pipelineStatistics |  |
| uint32_t pipelineStatisticsCount |  |

### struct WGPUQueueDescriptor {#structure-QueueDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |

### struct WGPURenderBundleDescriptor {#structure-RenderBundleDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |

### struct WGPURenderBundleEncoderDescriptor {#structure-RenderBundleEncoderDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| uint32_t colorFormatsCount |  |
| [WGPUTextureFormat]({{ '/api/c.html#enum-TextureFormat' | relative_url }}) const\* colorFormats |  |
| [WGPUTextureFormat]({{ '/api/c.html#enum-TextureFormat' | relative_url }}) depthStencilFormat |  |
| uint32_t sampleCount |  |
| bool depthReadOnly |  |
| bool stencilReadOnly |  |

### struct WGPURenderPassColorAttachment {#structure-RenderPassColorAttachment}

| Members | Description |
|:--------|:------------|
| [WGPUTextureView]({{ '/api/c.html#class-TextureView' | relative_url }}) view |  |
| [WGPUTextureView]({{ '/api/c.html#class-TextureView' | relative_url }}) resolveTarget |  |
| [WGPULoadOp]({{ '/api/c.html#enum-LoadOp' | relative_url }}) loadOp |  |
| [WGPUStoreOp]({{ '/api/c.html#enum-StoreOp' | relative_url }}) storeOp |  |
| [WGPUColor]({{ '/api/c.html#structure-Color' | relative_url }}) clearColor |  |
| [WGPUColor]({{ '/api/c.html#structure-Color' | relative_url }}) clearValue |  |

### struct WGPURenderPassDepthStencilAttachment {#structure-RenderPassDepthStencilAttachment}

| Members | Description |
|:--------|:------------|
| [WGPUTextureView]({{ '/api/c.html#class-TextureView' | relative_url }}) view |  |
| [WGPULoadOp]({{ '/api/c.html#enum-LoadOp' | relative_url }}) depthLoadOp |  |
| [WGPUStoreOp]({{ '/api/c.html#enum-StoreOp' | relative_url }}) depthStoreOp |  |
| float clearDepth |  |
| float depthClearValue |  |
| bool depthReadOnly |  |
| [WGPULoadOp]({{ '/api/c.html#enum-LoadOp' | relative_url }}) stencilLoadOp |  |
| [WGPUStoreOp]({{ '/api/c.html#enum-StoreOp' | relative_url }}) stencilStoreOp |  |
| uint32_t clearStencil |  |
| uint32_t stencilClearValue |  |
| bool stencilReadOnly |  |

### struct WGPURenderPassDescriptor {#structure-RenderPassDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| uint32_t colorAttachmentCount |  |
| [WGPURenderPassColorAttachment]({{ '/api/c.html#structure-RenderPassColorAttachment' | relative_url }}) const\* colorAttachments |  |
| [WGPURenderPassDepthStencilAttachment]({{ '/api/c.html#structure-RenderPassDepthStencilAttachment' | relative_url }}) const\* depthStencilAttachment |  |
| [WGPUQuerySet]({{ '/api/c.html#class-QuerySet' | relative_url }}) occlusionQuerySet |  |
| uint32_t timestampWriteCount |  |
| [WGPURenderPassTimestampWrite]({{ '/api/c.html#structure-RenderPassTimestampWrite' | relative_url }}) const\* timestampWrites |  |

#### Chainable Structures

 * [WGPURenderPassDescriptorMaxDrawCount]({{ '/api/c.html#structure-RenderPassDescriptorMaxDrawCount' | relative_url }})

### struct WGPURenderPassDescriptorMaxDrawCount {#structure-RenderPassDescriptorMaxDrawCount}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| uint64_t maxDrawCount |  |

#### Chain Parent Structures

 * [WGPURenderPassDescriptor]({{ '/api/c.html#structure-RenderPassDescriptor' | relative_url }})

### struct WGPURenderPassTimestampWrite {#structure-RenderPassTimestampWrite}

| Members | Description |
|:--------|:------------|
| [WGPUQuerySet]({{ '/api/c.html#class-QuerySet' | relative_url }}) querySet |  |
| uint32_t queryIndex |  |
| [WGPURenderPassTimestampLocation]({{ '/api/c.html#enum-RenderPassTimestampLocation' | relative_url }}) location |  |

### struct WGPURenderPipelineDescriptor {#structure-RenderPipelineDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUPipelineLayout]({{ '/api/c.html#class-PipelineLayout' | relative_url }}) layout |  |
| [WGPUVertexState]({{ '/api/c.html#structure-VertexState' | relative_url }}) vertex |  |
| [WGPUPrimitiveState]({{ '/api/c.html#structure-PrimitiveState' | relative_url }}) primitive |  |
| [WGPUDepthStencilState]({{ '/api/c.html#structure-DepthStencilState' | relative_url }}) const\* depthStencil |  |
| [WGPUMultisampleState]({{ '/api/c.html#structure-MultisampleState' | relative_url }}) multisample |  |
| [WGPUFragmentState]({{ '/api/c.html#structure-FragmentState' | relative_url }}) const\* fragment |  |

### struct WGPURequestAdapterOptions {#structure-RequestAdapterOptions}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUSurface]({{ '/api/c.html#class-Surface' | relative_url }}) compatibleSurface |  |
| [WGPUPowerPreference]({{ '/api/c.html#enum-PowerPreference' | relative_url }}) powerPreference |  |
| bool forceFallbackAdapter |  |

### struct WGPURequiredLimits {#structure-RequiredLimits}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPULimits]({{ '/api/c.html#structure-Limits' | relative_url }}) limits |  |

### struct WGPUSamplerBindingLayout {#structure-SamplerBindingLayout}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUSamplerBindingType]({{ '/api/c.html#enum-SamplerBindingType' | relative_url }}) type |  |

### struct WGPUSamplerDescriptor {#structure-SamplerDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUAddressMode]({{ '/api/c.html#enum-AddressMode' | relative_url }}) addressModeU |  |
| [WGPUAddressMode]({{ '/api/c.html#enum-AddressMode' | relative_url }}) addressModeV |  |
| [WGPUAddressMode]({{ '/api/c.html#enum-AddressMode' | relative_url }}) addressModeW |  |
| [WGPUFilterMode]({{ '/api/c.html#enum-FilterMode' | relative_url }}) magFilter |  |
| [WGPUFilterMode]({{ '/api/c.html#enum-FilterMode' | relative_url }}) minFilter |  |
| [WGPUFilterMode]({{ '/api/c.html#enum-FilterMode' | relative_url }}) mipmapFilter |  |
| [WGPUMipmapFilterMode]({{ '/api/c.html#enum-MipmapFilterMode' | relative_url }}) mipmapFilter |  |
| float lodMinClamp |  |
| float lodMaxClamp |  |
| [WGPUCompareFunction]({{ '/api/c.html#enum-CompareFunction' | relative_url }}) compare |  |
| uint16_t maxAnisotropy |  |

### struct WGPUShaderModuleSPIRVDescriptor {#structure-ShaderModuleSPIRVDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| uint32_t codeSize |  |
| uint32_t const\* code |  |

#### Chain Parent Structures

 * [WGPUShaderModuleDescriptor]({{ '/api/c.html#structure-ShaderModuleDescriptor' | relative_url }})

### struct WGPUShaderModuleWGSLDescriptor {#structure-ShaderModuleWGSLDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| char const\* source |  |
| char const\* code |  |

#### Chain Parent Structures

 * [WGPUShaderModuleDescriptor]({{ '/api/c.html#structure-ShaderModuleDescriptor' | relative_url }})

### struct WGPUShaderModuleCompilationHint {#structure-ShaderModuleCompilationHint}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* entryPoint |  |
| [WGPUPipelineLayout]({{ '/api/c.html#class-PipelineLayout' | relative_url }}) layout |  |

### struct WGPUShaderModuleDescriptor {#structure-ShaderModuleDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| uint32_t hintCount |  |
| [WGPUShaderModuleCompilationHint]({{ '/api/c.html#structure-ShaderModuleCompilationHint' | relative_url }}) const\* hints |  |

#### Chainable Structures

 * [WGPUShaderModuleSPIRVDescriptor]({{ '/api/c.html#structure-ShaderModuleSPIRVDescriptor' | relative_url }})
 * [WGPUShaderModuleWGSLDescriptor]({{ '/api/c.html#structure-ShaderModuleWGSLDescriptor' | relative_url }})

### struct WGPUStencilFaceState {#structure-StencilFaceState}

| Members | Description |
|:--------|:------------|
| [WGPUCompareFunction]({{ '/api/c.html#enum-CompareFunction' | relative_url }}) compare |  |
| [WGPUStencilOperation]({{ '/api/c.html#enum-StencilOperation' | relative_url }}) failOp |  |
| [WGPUStencilOperation]({{ '/api/c.html#enum-StencilOperation' | relative_url }}) depthFailOp |  |
| [WGPUStencilOperation]({{ '/api/c.html#enum-StencilOperation' | relative_url }}) passOp |  |

### struct WGPUStorageTextureBindingLayout {#structure-StorageTextureBindingLayout}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUStorageTextureAccess]({{ '/api/c.html#enum-StorageTextureAccess' | relative_url }}) access |  |
| [WGPUTextureFormat]({{ '/api/c.html#enum-TextureFormat' | relative_url }}) format |  |
| [WGPUTextureViewDimension]({{ '/api/c.html#enum-TextureViewDimension' | relative_url }}) viewDimension |  |

### struct WGPUSupportedLimits {#structure-SupportedLimits}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStructOut* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPULimits]({{ '/api/c.html#structure-Limits' | relative_url }}) limits |  |

### struct WGPUSurfaceDescriptor {#structure-SurfaceDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |

#### Chainable Structures

 * [WGPUSurfaceDescriptorFromAndroidNativeWindow]({{ '/api/c.html#structure-SurfaceDescriptorFromAndroidNativeWindow' | relative_url }})
 * [WGPUSurfaceDescriptorFromCanvasHTMLSelector]({{ '/api/c.html#structure-SurfaceDescriptorFromCanvasHTMLSelector' | relative_url }})
 * [WGPUSurfaceDescriptorFromMetalLayer]({{ '/api/c.html#structure-SurfaceDescriptorFromMetalLayer' | relative_url }})
 * [WGPUSurfaceDescriptorFromWindowsHWND]({{ '/api/c.html#structure-SurfaceDescriptorFromWindowsHWND' | relative_url }})
 * [WGPUSurfaceDescriptorFromXcbWindow]({{ '/api/c.html#structure-SurfaceDescriptorFromXcbWindow' | relative_url }})
 * [WGPUSurfaceDescriptorFromXlibWindow]({{ '/api/c.html#structure-SurfaceDescriptorFromXlibWindow' | relative_url }})
 * [WGPUSurfaceDescriptorFromWaylandSurface]({{ '/api/c.html#structure-SurfaceDescriptorFromWaylandSurface' | relative_url }})
 * [WGPUSurfaceDescriptorFromWindowsCoreWindow]({{ '/api/c.html#structure-SurfaceDescriptorFromWindowsCoreWindow' | relative_url }})
 * [WGPUSurfaceDescriptorFromWindowsSwapChainPanel]({{ '/api/c.html#structure-SurfaceDescriptorFromWindowsSwapChainPanel' | relative_url }})

### struct WGPUSurfaceDescriptorFromAndroidNativeWindow {#structure-SurfaceDescriptorFromAndroidNativeWindow}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| void \* window |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor]({{ '/api/c.html#structure-SurfaceDescriptor' | relative_url }})

### struct WGPUSurfaceDescriptorFromCanvasHTMLSelector {#structure-SurfaceDescriptorFromCanvasHTMLSelector}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| char const\* selector |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor]({{ '/api/c.html#structure-SurfaceDescriptor' | relative_url }})

### struct WGPUSurfaceDescriptorFromMetalLayer {#structure-SurfaceDescriptorFromMetalLayer}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| void \* layer |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor]({{ '/api/c.html#structure-SurfaceDescriptor' | relative_url }})

### struct WGPUSurfaceDescriptorFromWaylandSurface {#structure-SurfaceDescriptorFromWaylandSurface}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| void \* display |  |
| void \* surface |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor]({{ '/api/c.html#structure-SurfaceDescriptor' | relative_url }})

### struct WGPUSurfaceDescriptorFromWindowsHWND {#structure-SurfaceDescriptorFromWindowsHWND}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| void \* hinstance |  |
| void \* hwnd |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor]({{ '/api/c.html#structure-SurfaceDescriptor' | relative_url }})

### struct WGPUSurfaceDescriptorFromWindowsCoreWindow {#structure-SurfaceDescriptorFromWindowsCoreWindow}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| void \* coreWindow |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor]({{ '/api/c.html#structure-SurfaceDescriptor' | relative_url }})

### struct WGPUSurfaceDescriptorFromWindowsSwapChainPanel {#structure-SurfaceDescriptorFromWindowsSwapChainPanel}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| void \* swapChainPanel |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor]({{ '/api/c.html#structure-SurfaceDescriptor' | relative_url }})

### struct WGPUSurfaceDescriptorFromXcbWindow {#structure-SurfaceDescriptorFromXcbWindow}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| void \* connection |  |
| uint32_t window |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor]({{ '/api/c.html#structure-SurfaceDescriptor' | relative_url }})

### struct WGPUSurfaceDescriptorFromXlibWindow {#structure-SurfaceDescriptorFromXlibWindow}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| void \* display |  |
| uint32_t window |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor]({{ '/api/c.html#structure-SurfaceDescriptor' | relative_url }})

### struct WGPUSwapChainDescriptor {#structure-SwapChainDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUTextureUsage]({{ '/api/c.html#bitmask-TextureUsage' | relative_url }}) usage |  |
| [WGPUTextureFormat]({{ '/api/c.html#enum-TextureFormat' | relative_url }}) format |  |
| uint32_t width |  |
| uint32_t height |  |
| [WGPUPresentMode]({{ '/api/c.html#enum-PresentMode' | relative_url }}) presentMode |  |
| uint64_t implementation |  |

### struct WGPUTextureBindingLayout {#structure-TextureBindingLayout}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUTextureSampleType]({{ '/api/c.html#enum-TextureSampleType' | relative_url }}) sampleType |  |
| [WGPUTextureViewDimension]({{ '/api/c.html#enum-TextureViewDimension' | relative_url }}) viewDimension |  |
| bool multisampled |  |

### struct WGPUTextureDataLayout {#structure-TextureDataLayout}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| uint64_t offset |  |
| uint32_t bytesPerRow |  |
| uint32_t rowsPerImage |  |

### struct WGPUTextureDescriptor {#structure-TextureDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUTextureUsage]({{ '/api/c.html#bitmask-TextureUsage' | relative_url }}) usage |  |
| [WGPUTextureDimension]({{ '/api/c.html#enum-TextureDimension' | relative_url }}) dimension |  |
| [WGPUExtent3D]({{ '/api/c.html#structure-Extent3D' | relative_url }}) size |  |
| [WGPUTextureFormat]({{ '/api/c.html#enum-TextureFormat' | relative_url }}) format |  |
| uint32_t mipLevelCount |  |
| uint32_t sampleCount |  |
| uint32_t viewFormatCount |  |
| [WGPUTextureFormat]({{ '/api/c.html#enum-TextureFormat' | relative_url }}) const\* viewFormats |  |

#### Chainable Structures

 * [WGPUDawnTextureInternalUsageDescriptor]({{ '/api/c.html#structure-DawnTextureInternalUsageDescriptor' | relative_url }})

### struct WGPUTextureViewDescriptor {#structure-TextureViewDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUTextureFormat]({{ '/api/c.html#enum-TextureFormat' | relative_url }}) format |  |
| [WGPUTextureViewDimension]({{ '/api/c.html#enum-TextureViewDimension' | relative_url }}) dimension |  |
| uint32_t baseMipLevel |  |
| uint32_t mipLevelCount |  |
| uint32_t baseArrayLayer |  |
| uint32_t arrayLayerCount |  |
| [WGPUTextureAspect]({{ '/api/c.html#enum-TextureAspect' | relative_url }}) aspect |  |

### struct WGPUVertexAttribute {#structure-VertexAttribute}

| Members | Description |
|:--------|:------------|
| [WGPUVertexFormat]({{ '/api/c.html#enum-VertexFormat' | relative_url }}) format |  |
| uint64_t offset |  |
| uint32_t shaderLocation |  |

### struct WGPUVertexBufferLayout {#structure-VertexBufferLayout}

| Members | Description |
|:--------|:------------|
| uint64_t arrayStride |  |
| [WGPUVertexStepMode]({{ '/api/c.html#enum-VertexStepMode' | relative_url }}) stepMode |  |
| uint32_t attributeCount |  |
| [WGPUVertexAttribute]({{ '/api/c.html#structure-VertexAttribute' | relative_url }}) const\* attributes |  |

### struct WGPUVertexState {#structure-VertexState}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUShaderModule]({{ '/api/c.html#class-ShaderModule' | relative_url }}) module |  |
| char const\* entryPoint |  |
| uint32_t constantCount |  |
| [WGPUConstantEntry]({{ '/api/c.html#structure-ConstantEntry' | relative_url }}) const\* constants |  |
| uint32_t bufferCount |  |
| [WGPUVertexBufferLayout]({{ '/api/c.html#structure-VertexBufferLayout' | relative_url }}) const\* buffers |  |

## Methods

<div class='object' markdown=1>

### Methods of WGPUAdapter {#class-Adapter}

An *adapter* identifies an implemention of WebGPU on the system.

See [Adapters](https://webgpu.dev/#adapters) for more information.

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) wgpuAdapterCreateDevice([WGPUAdapter]({{ '/api/c.html#class-Adapter' | relative_url }}) adapter, [WGPUDeviceDescriptor]({{ '/api/c.html#structure-DeviceDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *adapter*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

size_t wgpuAdapterEnumerateFeatures([WGPUAdapter]({{ '/api/c.html#class-Adapter' | relative_url }}) adapter, [WGPUFeatureName]({{ '/api/c.html#enum-FeatureName' | relative_url }}) \* features)

</div>

#### Returns


#### Arguments

* *adapter*: 
* *features*: 

</div>

<div class='method' markdown=1>

Retrieves the limits which can be used with this adapter.

<div class='signature' markdown=1>

bool wgpuAdapterGetLimits([WGPUAdapter]({{ '/api/c.html#class-Adapter' | relative_url }}) adapter, [WGPUSupportedLimits]({{ '/api/c.html#structure-SupportedLimits' | relative_url }}) \* limits)

</div>

#### Returns

Returns true if the limits were successfully retrieved.
#### Arguments

* *adapter*: The [WGPUAdapter]({{ '/api/c.html#class-Adapter' | relative_url }}) from which to query the limits.
* *limits*: The [WGPUSupportedLimits]({{ '/api/c.html#structure-SupportedLimits' | relative_url }}) object to populate. Must not be NULL.

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuAdapterGetProperties([WGPUAdapter]({{ '/api/c.html#class-Adapter' | relative_url }}) adapter, [WGPUAdapterProperties]({{ '/api/c.html#structure-AdapterProperties' | relative_url }}) \* properties)

</div>

#### Arguments

* *adapter*: 
* *properties*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

bool wgpuAdapterHasFeature([WGPUAdapter]({{ '/api/c.html#class-Adapter' | relative_url }}) adapter, [WGPUFeatureName]({{ '/api/c.html#enum-FeatureName' | relative_url }}) feature)

</div>

#### Returns


#### Arguments

* *adapter*: 
* *feature*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuAdapterReference([WGPUAdapter]({{ '/api/c.html#class-Adapter' | relative_url }}) adapter)

</div>

#### Arguments

* *adapter*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuAdapterRelease([WGPUAdapter]({{ '/api/c.html#class-Adapter' | relative_url }}) adapter)

</div>

#### Arguments

* *adapter*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuAdapterRequestDevice([WGPUAdapter]({{ '/api/c.html#class-Adapter' | relative_url }}) adapter, [WGPUDeviceDescriptor]({{ '/api/c.html#structure-DeviceDescriptor' | relative_url }}) const\* descriptor, [WGPURequestDeviceCallback]({{ '/api/c.html#function-pointer-RequestDeviceCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *adapter*: 
* *descriptor*: 
* *callback*: 
* *userdata*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUBindGroup {#class-BindGroup}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBindGroupReference([WGPUBindGroup]({{ '/api/c.html#class-BindGroup' | relative_url }}) bindGroup)

</div>

#### Arguments

* *bindGroup*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBindGroupRelease([WGPUBindGroup]({{ '/api/c.html#class-BindGroup' | relative_url }}) bindGroup)

</div>

#### Arguments

* *bindGroup*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBindGroupSetLabel([WGPUBindGroup]({{ '/api/c.html#class-BindGroup' | relative_url }}) bindGroup, char const\* label)

</div>

#### Arguments

* *bindGroup*: 
* *label*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUBindGroupLayout {#class-BindGroupLayout}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBindGroupLayoutReference([WGPUBindGroupLayout]({{ '/api/c.html#class-BindGroupLayout' | relative_url }}) bindGroupLayout)

</div>

#### Arguments

* *bindGroupLayout*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBindGroupLayoutRelease([WGPUBindGroupLayout]({{ '/api/c.html#class-BindGroupLayout' | relative_url }}) bindGroupLayout)

</div>

#### Arguments

* *bindGroupLayout*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBindGroupLayoutSetLabel([WGPUBindGroupLayout]({{ '/api/c.html#class-BindGroupLayout' | relative_url }}) bindGroupLayout, char const\* label)

</div>

#### Arguments

* *bindGroupLayout*: 
* *label*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUBuffer {#class-Buffer}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBufferDestroy([WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer)

</div>

#### Arguments

* *buffer*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void const * wgpuBufferGetConstMappedRange([WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer, size_t offset, size_t size)

</div>

#### Returns


#### Arguments

* *buffer*: 
* *offset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void * wgpuBufferGetMappedRange([WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer, size_t offset, size_t size)

</div>

#### Returns


#### Arguments

* *buffer*: 
* *offset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint64_t wgpuBufferGetSize([WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer)

</div>

#### Returns


#### Arguments

* *buffer*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUBufferUsage]({{ '/api/c.html#bitmask-BufferUsage' | relative_url }}) wgpuBufferGetUsage([WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer)

</div>

#### Returns


#### Arguments

* *buffer*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBufferMapAsync([WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer, [WGPUMapMode]({{ '/api/c.html#bitmask-MapMode' | relative_url }}) mode, size_t offset, size_t size, [WGPUBufferMapCallback]({{ '/api/c.html#function-pointer-BufferMapCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *buffer*: 
* *mode*: 
* *offset*: 
* *size*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBufferReference([WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer)

</div>

#### Arguments

* *buffer*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBufferRelease([WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer)

</div>

#### Arguments

* *buffer*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBufferSetLabel([WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer, char const\* label)

</div>

#### Arguments

* *buffer*: 
* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBufferUnmap([WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer)

</div>

#### Arguments

* *buffer*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUCommandBuffer {#class-CommandBuffer}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandBufferReference([WGPUCommandBuffer]({{ '/api/c.html#class-CommandBuffer' | relative_url }}) commandBuffer)

</div>

#### Arguments

* *commandBuffer*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandBufferRelease([WGPUCommandBuffer]({{ '/api/c.html#class-CommandBuffer' | relative_url }}) commandBuffer)

</div>

#### Arguments

* *commandBuffer*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandBufferSetLabel([WGPUCommandBuffer]({{ '/api/c.html#class-CommandBuffer' | relative_url }}) commandBuffer, char const\* label)

</div>

#### Arguments

* *commandBuffer*: 
* *label*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUCommandEncoder {#class-CommandEncoder}

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) wgpuCommandEncoderBeginComputePass([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder, [WGPUComputePassDescriptor]({{ '/api/c.html#structure-ComputePassDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *commandEncoder*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) wgpuCommandEncoderBeginRenderPass([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder, [WGPURenderPassDescriptor]({{ '/api/c.html#structure-RenderPassDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *commandEncoder*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderClearBuffer([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder, [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer, uint64_t offset, uint64_t size)

</div>

#### Arguments

* *commandEncoder*: 
* *buffer*: 
* *offset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderCopyBufferToBuffer([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder, [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) source, uint64_t sourceOffset, [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) destination, uint64_t destinationOffset, uint64_t size)

</div>

#### Arguments

* *commandEncoder*: 
* *source*: 
* *sourceOffset*: 
* *destination*: 
* *destinationOffset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderCopyBufferToTexture([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder, [WGPUImageCopyBuffer]({{ '/api/c.html#structure-ImageCopyBuffer' | relative_url }}) const\* source, [WGPUImageCopyTexture]({{ '/api/c.html#structure-ImageCopyTexture' | relative_url }}) const\* destination, [WGPUExtent3D]({{ '/api/c.html#structure-Extent3D' | relative_url }}) const\* copySize)

</div>

#### Arguments

* *commandEncoder*: 
* *source*: 
* *destination*: 
* *copySize*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderCopyTextureToBuffer([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder, [WGPUImageCopyTexture]({{ '/api/c.html#structure-ImageCopyTexture' | relative_url }}) const\* source, [WGPUImageCopyBuffer]({{ '/api/c.html#structure-ImageCopyBuffer' | relative_url }}) const\* destination, [WGPUExtent3D]({{ '/api/c.html#structure-Extent3D' | relative_url }}) const\* copySize)

</div>

#### Arguments

* *commandEncoder*: 
* *source*: 
* *destination*: 
* *copySize*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderCopyTextureToTexture([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder, [WGPUImageCopyTexture]({{ '/api/c.html#structure-ImageCopyTexture' | relative_url }}) const\* source, [WGPUImageCopyTexture]({{ '/api/c.html#structure-ImageCopyTexture' | relative_url }}) const\* destination, [WGPUExtent3D]({{ '/api/c.html#structure-Extent3D' | relative_url }}) const\* copySize)

</div>

#### Arguments

* *commandEncoder*: 
* *source*: 
* *destination*: 
* *copySize*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderCopyTextureToTextureInternal([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder, [WGPUImageCopyTexture]({{ '/api/c.html#structure-ImageCopyTexture' | relative_url }}) const\* source, [WGPUImageCopyTexture]({{ '/api/c.html#structure-ImageCopyTexture' | relative_url }}) const\* destination, [WGPUExtent3D]({{ '/api/c.html#structure-Extent3D' | relative_url }}) const\* copySize)

</div>

#### Arguments

* *commandEncoder*: 
* *source*: 
* *destination*: 
* *copySize*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUCommandBuffer]({{ '/api/c.html#class-CommandBuffer' | relative_url }}) wgpuCommandEncoderFinish([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder, [WGPUCommandBufferDescriptor]({{ '/api/c.html#structure-CommandBufferDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *commandEncoder*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderInjectValidationError([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder, char const\* message)

</div>

#### Arguments

* *commandEncoder*: 
* *message*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderInsertDebugMarker([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder, char const\* markerLabel)

</div>

#### Arguments

* *commandEncoder*: 
* *markerLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderPopDebugGroup([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder)

</div>

#### Arguments

* *commandEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderPushDebugGroup([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder, char const\* groupLabel)

</div>

#### Arguments

* *commandEncoder*: 
* *groupLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderReference([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder)

</div>

#### Arguments

* *commandEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderRelease([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder)

</div>

#### Arguments

* *commandEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderResolveQuerySet([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder, [WGPUQuerySet]({{ '/api/c.html#class-QuerySet' | relative_url }}) querySet, uint32_t firstQuery, uint32_t queryCount, [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) destination, uint64_t destinationOffset)

</div>

#### Arguments

* *commandEncoder*: 
* *querySet*: 
* *firstQuery*: 
* *queryCount*: 
* *destination*: 
* *destinationOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderSetLabel([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder, char const\* label)

</div>

#### Arguments

* *commandEncoder*: 
* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderWriteBuffer([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder, [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer, uint64_t bufferOffset, uint8_t const\* data, uint64_t size)

</div>

#### Arguments

* *commandEncoder*: 
* *buffer*: 
* *bufferOffset*: 
* *data*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderWriteTimestamp([WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) commandEncoder, [WGPUQuerySet]({{ '/api/c.html#class-QuerySet' | relative_url }}) querySet, uint32_t queryIndex)

</div>

#### Arguments

* *commandEncoder*: 
* *querySet*: 
* *queryIndex*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUComputePassEncoder {#class-ComputePassEncoder}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderBeginPipelineStatisticsQuery([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder, [WGPUQuerySet]({{ '/api/c.html#class-QuerySet' | relative_url }}) querySet, uint32_t queryIndex)

</div>

#### Arguments

* *computePassEncoder*: 
* *querySet*: 
* *queryIndex*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderDispatch([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder, uint32_t workgroupCountX, uint32_t workgroupCountY, uint32_t workgroupCountZ)

</div>

#### Arguments

* *computePassEncoder*: 
* *workgroupCountX*: 
* *workgroupCountY*: 
* *workgroupCountZ*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderDispatchIndirect([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder, [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *computePassEncoder*: 
* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderDispatchWorkgroups([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder, uint32_t workgroupCountX, uint32_t workgroupCountY, uint32_t workgroupCountZ)

</div>

#### Arguments

* *computePassEncoder*: 
* *workgroupCountX*: 
* *workgroupCountY*: 
* *workgroupCountZ*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderDispatchWorkgroupsIndirect([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder, [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *computePassEncoder*: 
* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderEnd([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder)

</div>

#### Arguments

* *computePassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderEndPass([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder)

</div>

#### Arguments

* *computePassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderEndPipelineStatisticsQuery([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder)

</div>

#### Arguments

* *computePassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderInsertDebugMarker([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder, char const\* markerLabel)

</div>

#### Arguments

* *computePassEncoder*: 
* *markerLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderPopDebugGroup([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder)

</div>

#### Arguments

* *computePassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderPushDebugGroup([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder, char const\* groupLabel)

</div>

#### Arguments

* *computePassEncoder*: 
* *groupLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderReference([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder)

</div>

#### Arguments

* *computePassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderRelease([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder)

</div>

#### Arguments

* *computePassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderSetBindGroup([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder, uint32_t groupIndex, [WGPUBindGroup]({{ '/api/c.html#class-BindGroup' | relative_url }}) group, uint32_t dynamicOffsetCount, uint32_t const\* dynamicOffsets)

</div>

#### Arguments

* *computePassEncoder*: 
* *groupIndex*: 
* *group*: 
* *dynamicOffsetCount*: 
* *dynamicOffsets*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderSetLabel([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder, char const\* label)

</div>

#### Arguments

* *computePassEncoder*: 
* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderSetPipeline([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder, [WGPUComputePipeline]({{ '/api/c.html#class-ComputePipeline' | relative_url }}) pipeline)

</div>

#### Arguments

* *computePassEncoder*: 
* *pipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderWriteTimestamp([WGPUComputePassEncoder]({{ '/api/c.html#class-ComputePassEncoder' | relative_url }}) computePassEncoder, [WGPUQuerySet]({{ '/api/c.html#class-QuerySet' | relative_url }}) querySet, uint32_t queryIndex)

</div>

#### Arguments

* *computePassEncoder*: 
* *querySet*: 
* *queryIndex*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUComputePipeline {#class-ComputePipeline}

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUBindGroupLayout]({{ '/api/c.html#class-BindGroupLayout' | relative_url }}) wgpuComputePipelineGetBindGroupLayout([WGPUComputePipeline]({{ '/api/c.html#class-ComputePipeline' | relative_url }}) computePipeline, uint32_t groupIndex)

</div>

#### Returns


#### Arguments

* *computePipeline*: 
* *groupIndex*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePipelineReference([WGPUComputePipeline]({{ '/api/c.html#class-ComputePipeline' | relative_url }}) computePipeline)

</div>

#### Arguments

* *computePipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePipelineRelease([WGPUComputePipeline]({{ '/api/c.html#class-ComputePipeline' | relative_url }}) computePipeline)

</div>

#### Arguments

* *computePipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePipelineSetLabel([WGPUComputePipeline]({{ '/api/c.html#class-ComputePipeline' | relative_url }}) computePipeline, char const\* label)

</div>

#### Arguments

* *computePipeline*: 
* *label*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUDevice {#class-Device}

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUBindGroup]({{ '/api/c.html#class-BindGroup' | relative_url }}) wgpuDeviceCreateBindGroup([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUBindGroupDescriptor]({{ '/api/c.html#structure-BindGroupDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUBindGroupLayout]({{ '/api/c.html#class-BindGroupLayout' | relative_url }}) wgpuDeviceCreateBindGroupLayout([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUBindGroupLayoutDescriptor]({{ '/api/c.html#structure-BindGroupLayoutDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) wgpuDeviceCreateBuffer([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUBufferDescriptor]({{ '/api/c.html#structure-BufferDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUCommandEncoder]({{ '/api/c.html#class-CommandEncoder' | relative_url }}) wgpuDeviceCreateCommandEncoder([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUCommandEncoderDescriptor]({{ '/api/c.html#structure-CommandEncoderDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUComputePipeline]({{ '/api/c.html#class-ComputePipeline' | relative_url }}) wgpuDeviceCreateComputePipeline([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUComputePipelineDescriptor]({{ '/api/c.html#structure-ComputePipelineDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceCreateComputePipelineAsync([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUComputePipelineDescriptor]({{ '/api/c.html#structure-ComputePipelineDescriptor' | relative_url }}) const\* descriptor, [WGPUCreateComputePipelineAsyncCallback]({{ '/api/c.html#function-pointer-CreateComputePipelineAsyncCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *device*: 
* *descriptor*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) wgpuDeviceCreateErrorBuffer([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device)

</div>

#### Returns


#### Arguments

* *device*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUExternalTexture]({{ '/api/c.html#class-ExternalTexture' | relative_url }}) wgpuDeviceCreateErrorExternalTexture([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device)

</div>

#### Returns


#### Arguments

* *device*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUTexture]({{ '/api/c.html#class-Texture' | relative_url }}) wgpuDeviceCreateErrorTexture([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUTextureDescriptor]({{ '/api/c.html#structure-TextureDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUExternalTexture]({{ '/api/c.html#class-ExternalTexture' | relative_url }}) wgpuDeviceCreateExternalTexture([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUExternalTextureDescriptor]({{ '/api/c.html#structure-ExternalTextureDescriptor' | relative_url }}) const\* externalTextureDescriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *externalTextureDescriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUPipelineLayout]({{ '/api/c.html#class-PipelineLayout' | relative_url }}) wgpuDeviceCreatePipelineLayout([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUPipelineLayoutDescriptor]({{ '/api/c.html#structure-PipelineLayoutDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUQuerySet]({{ '/api/c.html#class-QuerySet' | relative_url }}) wgpuDeviceCreateQuerySet([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUQuerySetDescriptor]({{ '/api/c.html#structure-QuerySetDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPURenderBundleEncoder]({{ '/api/c.html#class-RenderBundleEncoder' | relative_url }}) wgpuDeviceCreateRenderBundleEncoder([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPURenderBundleEncoderDescriptor]({{ '/api/c.html#structure-RenderBundleEncoderDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPURenderPipeline]({{ '/api/c.html#class-RenderPipeline' | relative_url }}) wgpuDeviceCreateRenderPipeline([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPURenderPipelineDescriptor]({{ '/api/c.html#structure-RenderPipelineDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceCreateRenderPipelineAsync([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPURenderPipelineDescriptor]({{ '/api/c.html#structure-RenderPipelineDescriptor' | relative_url }}) const\* descriptor, [WGPUCreateRenderPipelineAsyncCallback]({{ '/api/c.html#function-pointer-CreateRenderPipelineAsyncCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *device*: 
* *descriptor*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUSampler]({{ '/api/c.html#class-Sampler' | relative_url }}) wgpuDeviceCreateSampler([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUSamplerDescriptor]({{ '/api/c.html#structure-SamplerDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUShaderModule]({{ '/api/c.html#class-ShaderModule' | relative_url }}) wgpuDeviceCreateShaderModule([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUShaderModuleDescriptor]({{ '/api/c.html#structure-ShaderModuleDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUSwapChain]({{ '/api/c.html#class-SwapChain' | relative_url }}) wgpuDeviceCreateSwapChain([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUSurface]({{ '/api/c.html#class-Surface' | relative_url }}) surface, [WGPUSwapChainDescriptor]({{ '/api/c.html#structure-SwapChainDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *surface*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUSwapChain]({{ '/api/c.html#class-SwapChain' | relative_url }}) wgpuDeviceCreateSwapChain([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUSurface]({{ '/api/c.html#class-Surface' | relative_url }}) surface, [WGPUSwapChainDescriptor]({{ '/api/c.html#structure-SwapChainDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *surface*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUTexture]({{ '/api/c.html#class-Texture' | relative_url }}) wgpuDeviceCreateTexture([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUTextureDescriptor]({{ '/api/c.html#structure-TextureDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceDestroy([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device)

</div>

#### Arguments

* *device*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

size_t wgpuDeviceEnumerateFeatures([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUFeatureName]({{ '/api/c.html#enum-FeatureName' | relative_url }}) \* features)

</div>

#### Returns


#### Arguments

* *device*: 
* *features*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceForceLoss([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUDeviceLostReason]({{ '/api/c.html#enum-DeviceLostReason' | relative_url }}) type, char const\* message)

</div>

#### Arguments

* *device*: 
* *type*: 
* *message*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUAdapter]({{ '/api/c.html#class-Adapter' | relative_url }}) wgpuDeviceGetAdapter([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device)

</div>

#### Returns


#### Arguments

* *device*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

bool wgpuDeviceGetLimits([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUSupportedLimits]({{ '/api/c.html#structure-SupportedLimits' | relative_url }}) \* limits)

</div>

#### Returns


#### Arguments

* *device*: 
* *limits*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUQueue]({{ '/api/c.html#class-Queue' | relative_url }}) wgpuDeviceGetQueue([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device)

</div>

#### Returns


#### Arguments

* *device*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

bool wgpuDeviceHasFeature([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUFeatureName]({{ '/api/c.html#enum-FeatureName' | relative_url }}) feature)

</div>

#### Returns


#### Arguments

* *device*: 
* *feature*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceInjectError([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUErrorType]({{ '/api/c.html#enum-ErrorType' | relative_url }}) type, char const\* message)

</div>

#### Arguments

* *device*: 
* *type*: 
* *message*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

bool wgpuDevicePopErrorScope([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUErrorCallback]({{ '/api/c.html#function-pointer-ErrorCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Returns


#### Arguments

* *device*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDevicePushErrorScope([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUErrorFilter]({{ '/api/c.html#enum-ErrorFilter' | relative_url }}) filter)

</div>

#### Arguments

* *device*: 
* *filter*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceReference([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device)

</div>

#### Arguments

* *device*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceRelease([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device)

</div>

#### Arguments

* *device*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceSetDeviceLostCallback([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUDeviceLostCallback]({{ '/api/c.html#function-pointer-DeviceLostCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *device*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceSetLabel([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, char const\* label)

</div>

#### Arguments

* *device*: 
* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceSetLoggingCallback([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPULoggingCallback]({{ '/api/c.html#function-pointer-LoggingCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *device*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceSetUncapturedErrorCallback([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, [WGPUErrorCallback]({{ '/api/c.html#function-pointer-ErrorCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *device*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceTick([WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device)

</div>

#### Arguments

* *device*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUExternalTexture {#class-ExternalTexture}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuExternalTextureDestroy([WGPUExternalTexture]({{ '/api/c.html#class-ExternalTexture' | relative_url }}) externalTexture)

</div>

#### Arguments

* *externalTexture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuExternalTextureReference([WGPUExternalTexture]({{ '/api/c.html#class-ExternalTexture' | relative_url }}) externalTexture)

</div>

#### Arguments

* *externalTexture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuExternalTextureRelease([WGPUExternalTexture]({{ '/api/c.html#class-ExternalTexture' | relative_url }}) externalTexture)

</div>

#### Arguments

* *externalTexture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuExternalTextureSetLabel([WGPUExternalTexture]({{ '/api/c.html#class-ExternalTexture' | relative_url }}) externalTexture, char const\* label)

</div>

#### Arguments

* *externalTexture*: 
* *label*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUInstance {#class-Instance}

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUSurface]({{ '/api/c.html#class-Surface' | relative_url }}) wgpuInstanceCreateSurface([WGPUInstance]({{ '/api/c.html#class-Instance' | relative_url }}) instance, [WGPUSurfaceDescriptor]({{ '/api/c.html#structure-SurfaceDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *instance*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuInstanceProcessEvents([WGPUInstance]({{ '/api/c.html#class-Instance' | relative_url }}) instance)

</div>

#### Arguments

* *instance*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuInstanceReference([WGPUInstance]({{ '/api/c.html#class-Instance' | relative_url }}) instance)

</div>

#### Arguments

* *instance*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuInstanceRelease([WGPUInstance]({{ '/api/c.html#class-Instance' | relative_url }}) instance)

</div>

#### Arguments

* *instance*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuInstanceRequestAdapter([WGPUInstance]({{ '/api/c.html#class-Instance' | relative_url }}) instance, [WGPURequestAdapterOptions]({{ '/api/c.html#structure-RequestAdapterOptions' | relative_url }}) const\* options, [WGPURequestAdapterCallback]({{ '/api/c.html#function-pointer-RequestAdapterCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *instance*: 
* *options*: 
* *callback*: 
* *userdata*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUPipelineLayout {#class-PipelineLayout}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuPipelineLayoutReference([WGPUPipelineLayout]({{ '/api/c.html#class-PipelineLayout' | relative_url }}) pipelineLayout)

</div>

#### Arguments

* *pipelineLayout*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuPipelineLayoutRelease([WGPUPipelineLayout]({{ '/api/c.html#class-PipelineLayout' | relative_url }}) pipelineLayout)

</div>

#### Arguments

* *pipelineLayout*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuPipelineLayoutSetLabel([WGPUPipelineLayout]({{ '/api/c.html#class-PipelineLayout' | relative_url }}) pipelineLayout, char const\* label)

</div>

#### Arguments

* *pipelineLayout*: 
* *label*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUQuerySet {#class-QuerySet}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQuerySetDestroy([WGPUQuerySet]({{ '/api/c.html#class-QuerySet' | relative_url }}) querySet)

</div>

#### Arguments

* *querySet*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t wgpuQuerySetGetCount([WGPUQuerySet]({{ '/api/c.html#class-QuerySet' | relative_url }}) querySet)

</div>

#### Returns


#### Arguments

* *querySet*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUQueryType]({{ '/api/c.html#enum-QueryType' | relative_url }}) wgpuQuerySetGetType([WGPUQuerySet]({{ '/api/c.html#class-QuerySet' | relative_url }}) querySet)

</div>

#### Returns


#### Arguments

* *querySet*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQuerySetReference([WGPUQuerySet]({{ '/api/c.html#class-QuerySet' | relative_url }}) querySet)

</div>

#### Arguments

* *querySet*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQuerySetRelease([WGPUQuerySet]({{ '/api/c.html#class-QuerySet' | relative_url }}) querySet)

</div>

#### Arguments

* *querySet*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQuerySetSetLabel([WGPUQuerySet]({{ '/api/c.html#class-QuerySet' | relative_url }}) querySet, char const\* label)

</div>

#### Arguments

* *querySet*: 
* *label*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUQueue {#class-Queue}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQueueCopyTextureForBrowser([WGPUQueue]({{ '/api/c.html#class-Queue' | relative_url }}) queue, [WGPUImageCopyTexture]({{ '/api/c.html#structure-ImageCopyTexture' | relative_url }}) const\* source, [WGPUImageCopyTexture]({{ '/api/c.html#structure-ImageCopyTexture' | relative_url }}) const\* destination, [WGPUExtent3D]({{ '/api/c.html#structure-Extent3D' | relative_url }}) const\* copySize, [WGPUCopyTextureForBrowserOptions]({{ '/api/c.html#structure-CopyTextureForBrowserOptions' | relative_url }}) const\* options)

</div>

#### Arguments

* *queue*: 
* *source*: 
* *destination*: 
* *copySize*: 
* *options*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQueueOnSubmittedWorkDone([WGPUQueue]({{ '/api/c.html#class-Queue' | relative_url }}) queue, uint64_t signalValue, [WGPUQueueWorkDoneCallback]({{ '/api/c.html#function-pointer-QueueWorkDoneCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *queue*: 
* *signalValue*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQueueOnSubmittedWorkDone([WGPUQueue]({{ '/api/c.html#class-Queue' | relative_url }}) queue, [WGPUQueueWorkDoneCallback]({{ '/api/c.html#function-pointer-QueueWorkDoneCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *queue*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQueueReference([WGPUQueue]({{ '/api/c.html#class-Queue' | relative_url }}) queue)

</div>

#### Arguments

* *queue*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQueueRelease([WGPUQueue]({{ '/api/c.html#class-Queue' | relative_url }}) queue)

</div>

#### Arguments

* *queue*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQueueSetLabel([WGPUQueue]({{ '/api/c.html#class-Queue' | relative_url }}) queue, char const\* label)

</div>

#### Arguments

* *queue*: 
* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQueueSubmit([WGPUQueue]({{ '/api/c.html#class-Queue' | relative_url }}) queue, uint32_t commandCount, [WGPUCommandBuffer]({{ '/api/c.html#class-CommandBuffer' | relative_url }}) const\* commands)

</div>

#### Arguments

* *queue*: 
* *commandCount*: 
* *commands*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQueueWriteBuffer([WGPUQueue]({{ '/api/c.html#class-Queue' | relative_url }}) queue, [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer, uint64_t bufferOffset, void const\* data, size_t size)

</div>

#### Arguments

* *queue*: 
* *buffer*: 
* *bufferOffset*: 
* *data*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQueueWriteTexture([WGPUQueue]({{ '/api/c.html#class-Queue' | relative_url }}) queue, [WGPUImageCopyTexture]({{ '/api/c.html#structure-ImageCopyTexture' | relative_url }}) const\* destination, void const\* data, size_t dataSize, [WGPUTextureDataLayout]({{ '/api/c.html#structure-TextureDataLayout' | relative_url }}) const\* dataLayout, [WGPUExtent3D]({{ '/api/c.html#structure-Extent3D' | relative_url }}) const\* writeSize)

</div>

#### Arguments

* *queue*: 
* *destination*: 
* *data*: 
* *dataSize*: 
* *dataLayout*: 
* *writeSize*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPURenderBundle {#class-RenderBundle}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleReference([WGPURenderBundle]({{ '/api/c.html#class-RenderBundle' | relative_url }}) renderBundle)

</div>

#### Arguments

* *renderBundle*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleRelease([WGPURenderBundle]({{ '/api/c.html#class-RenderBundle' | relative_url }}) renderBundle)

</div>

#### Arguments

* *renderBundle*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPURenderBundleEncoder {#class-RenderBundleEncoder}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderDraw([WGPURenderBundleEncoder]({{ '/api/c.html#class-RenderBundleEncoder' | relative_url }}) renderBundleEncoder, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *vertexCount*: 
* *instanceCount*: 
* *firstVertex*: 
* *firstInstance*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderDrawIndexed([WGPURenderBundleEncoder]({{ '/api/c.html#class-RenderBundleEncoder' | relative_url }}) renderBundleEncoder, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *indexCount*: 
* *instanceCount*: 
* *firstIndex*: 
* *baseVertex*: 
* *firstInstance*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderDrawIndexedIndirect([WGPURenderBundleEncoder]({{ '/api/c.html#class-RenderBundleEncoder' | relative_url }}) renderBundleEncoder, [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderDrawIndirect([WGPURenderBundleEncoder]({{ '/api/c.html#class-RenderBundleEncoder' | relative_url }}) renderBundleEncoder, [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPURenderBundle]({{ '/api/c.html#class-RenderBundle' | relative_url }}) wgpuRenderBundleEncoderFinish([WGPURenderBundleEncoder]({{ '/api/c.html#class-RenderBundleEncoder' | relative_url }}) renderBundleEncoder, [WGPURenderBundleDescriptor]({{ '/api/c.html#structure-RenderBundleDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *renderBundleEncoder*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderInsertDebugMarker([WGPURenderBundleEncoder]({{ '/api/c.html#class-RenderBundleEncoder' | relative_url }}) renderBundleEncoder, char const\* markerLabel)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *markerLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderPopDebugGroup([WGPURenderBundleEncoder]({{ '/api/c.html#class-RenderBundleEncoder' | relative_url }}) renderBundleEncoder)

</div>

#### Arguments

* *renderBundleEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderPushDebugGroup([WGPURenderBundleEncoder]({{ '/api/c.html#class-RenderBundleEncoder' | relative_url }}) renderBundleEncoder, char const\* groupLabel)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *groupLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderReference([WGPURenderBundleEncoder]({{ '/api/c.html#class-RenderBundleEncoder' | relative_url }}) renderBundleEncoder)

</div>

#### Arguments

* *renderBundleEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderRelease([WGPURenderBundleEncoder]({{ '/api/c.html#class-RenderBundleEncoder' | relative_url }}) renderBundleEncoder)

</div>

#### Arguments

* *renderBundleEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderSetBindGroup([WGPURenderBundleEncoder]({{ '/api/c.html#class-RenderBundleEncoder' | relative_url }}) renderBundleEncoder, uint32_t groupIndex, [WGPUBindGroup]({{ '/api/c.html#class-BindGroup' | relative_url }}) group, uint32_t dynamicOffsetCount, uint32_t const\* dynamicOffsets)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *groupIndex*: 
* *group*: 
* *dynamicOffsetCount*: 
* *dynamicOffsets*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderSetIndexBuffer([WGPURenderBundleEncoder]({{ '/api/c.html#class-RenderBundleEncoder' | relative_url }}) renderBundleEncoder, [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer, [WGPUIndexFormat]({{ '/api/c.html#enum-IndexFormat' | relative_url }}) format, uint64_t offset, uint64_t size)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *buffer*: 
* *format*: 
* *offset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderSetLabel([WGPURenderBundleEncoder]({{ '/api/c.html#class-RenderBundleEncoder' | relative_url }}) renderBundleEncoder, char const\* label)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderSetPipeline([WGPURenderBundleEncoder]({{ '/api/c.html#class-RenderBundleEncoder' | relative_url }}) renderBundleEncoder, [WGPURenderPipeline]({{ '/api/c.html#class-RenderPipeline' | relative_url }}) pipeline)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *pipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderSetVertexBuffer([WGPURenderBundleEncoder]({{ '/api/c.html#class-RenderBundleEncoder' | relative_url }}) renderBundleEncoder, uint32_t slot, [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer, uint64_t offset, uint64_t size)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *slot*: 
* *buffer*: 
* *offset*: 
* *size*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPURenderPassEncoder {#class-RenderPassEncoder}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderBeginOcclusionQuery([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, uint32_t queryIndex)

</div>

#### Arguments

* *renderPassEncoder*: 
* *queryIndex*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderBeginPipelineStatisticsQuery([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, [WGPUQuerySet]({{ '/api/c.html#class-QuerySet' | relative_url }}) querySet, uint32_t queryIndex)

</div>

#### Arguments

* *renderPassEncoder*: 
* *querySet*: 
* *queryIndex*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderDraw([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)

</div>

#### Arguments

* *renderPassEncoder*: 
* *vertexCount*: 
* *instanceCount*: 
* *firstVertex*: 
* *firstInstance*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderDrawIndexed([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance)

</div>

#### Arguments

* *renderPassEncoder*: 
* *indexCount*: 
* *instanceCount*: 
* *firstIndex*: 
* *baseVertex*: 
* *firstInstance*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderDrawIndexedIndirect([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *renderPassEncoder*: 
* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderDrawIndirect([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *renderPassEncoder*: 
* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderEnd([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder)

</div>

#### Arguments

* *renderPassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderEndOcclusionQuery([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder)

</div>

#### Arguments

* *renderPassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderEndPass([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder)

</div>

#### Arguments

* *renderPassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderEndPipelineStatisticsQuery([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder)

</div>

#### Arguments

* *renderPassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderExecuteBundles([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, uint32_t bundlesCount, [WGPURenderBundle]({{ '/api/c.html#class-RenderBundle' | relative_url }}) const\* bundles)

</div>

#### Arguments

* *renderPassEncoder*: 
* *bundlesCount*: 
* *bundles*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderInsertDebugMarker([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, char const\* markerLabel)

</div>

#### Arguments

* *renderPassEncoder*: 
* *markerLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderPopDebugGroup([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder)

</div>

#### Arguments

* *renderPassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderPushDebugGroup([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, char const\* groupLabel)

</div>

#### Arguments

* *renderPassEncoder*: 
* *groupLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderReference([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder)

</div>

#### Arguments

* *renderPassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderRelease([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder)

</div>

#### Arguments

* *renderPassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderSetBindGroup([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, uint32_t groupIndex, [WGPUBindGroup]({{ '/api/c.html#class-BindGroup' | relative_url }}) group, uint32_t dynamicOffsetCount, uint32_t const\* dynamicOffsets)

</div>

#### Arguments

* *renderPassEncoder*: 
* *groupIndex*: 
* *group*: 
* *dynamicOffsetCount*: 
* *dynamicOffsets*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderSetBlendConstant([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, [WGPUColor]({{ '/api/c.html#structure-Color' | relative_url }}) const\* color)

</div>

#### Arguments

* *renderPassEncoder*: 
* *color*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderSetIndexBuffer([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer, [WGPUIndexFormat]({{ '/api/c.html#enum-IndexFormat' | relative_url }}) format, uint64_t offset, uint64_t size)

</div>

#### Arguments

* *renderPassEncoder*: 
* *buffer*: 
* *format*: 
* *offset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderSetLabel([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, char const\* label)

</div>

#### Arguments

* *renderPassEncoder*: 
* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderSetPipeline([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, [WGPURenderPipeline]({{ '/api/c.html#class-RenderPipeline' | relative_url }}) pipeline)

</div>

#### Arguments

* *renderPassEncoder*: 
* *pipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderSetScissorRect([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, uint32_t x, uint32_t y, uint32_t width, uint32_t height)

</div>

#### Arguments

* *renderPassEncoder*: 
* *x*: 
* *y*: 
* *width*: 
* *height*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderSetStencilReference([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, uint32_t reference)

</div>

#### Arguments

* *renderPassEncoder*: 
* *reference*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderSetVertexBuffer([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, uint32_t slot, [WGPUBuffer]({{ '/api/c.html#class-Buffer' | relative_url }}) buffer, uint64_t offset, uint64_t size)

</div>

#### Arguments

* *renderPassEncoder*: 
* *slot*: 
* *buffer*: 
* *offset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderSetViewport([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, float x, float y, float width, float height, float minDepth, float maxDepth)

</div>

#### Arguments

* *renderPassEncoder*: 
* *x*: 
* *y*: 
* *width*: 
* *height*: 
* *minDepth*: 
* *maxDepth*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderWriteTimestamp([WGPURenderPassEncoder]({{ '/api/c.html#class-RenderPassEncoder' | relative_url }}) renderPassEncoder, [WGPUQuerySet]({{ '/api/c.html#class-QuerySet' | relative_url }}) querySet, uint32_t queryIndex)

</div>

#### Arguments

* *renderPassEncoder*: 
* *querySet*: 
* *queryIndex*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPURenderPipeline {#class-RenderPipeline}

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUBindGroupLayout]({{ '/api/c.html#class-BindGroupLayout' | relative_url }}) wgpuRenderPipelineGetBindGroupLayout([WGPURenderPipeline]({{ '/api/c.html#class-RenderPipeline' | relative_url }}) renderPipeline, uint32_t groupIndex)

</div>

#### Returns


#### Arguments

* *renderPipeline*: 
* *groupIndex*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPipelineReference([WGPURenderPipeline]({{ '/api/c.html#class-RenderPipeline' | relative_url }}) renderPipeline)

</div>

#### Arguments

* *renderPipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPipelineRelease([WGPURenderPipeline]({{ '/api/c.html#class-RenderPipeline' | relative_url }}) renderPipeline)

</div>

#### Arguments

* *renderPipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPipelineSetLabel([WGPURenderPipeline]({{ '/api/c.html#class-RenderPipeline' | relative_url }}) renderPipeline, char const\* label)

</div>

#### Arguments

* *renderPipeline*: 
* *label*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUSampler {#class-Sampler}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSamplerReference([WGPUSampler]({{ '/api/c.html#class-Sampler' | relative_url }}) sampler)

</div>

#### Arguments

* *sampler*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSamplerRelease([WGPUSampler]({{ '/api/c.html#class-Sampler' | relative_url }}) sampler)

</div>

#### Arguments

* *sampler*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSamplerSetLabel([WGPUSampler]({{ '/api/c.html#class-Sampler' | relative_url }}) sampler, char const\* label)

</div>

#### Arguments

* *sampler*: 
* *label*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUShaderModule {#class-ShaderModule}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuShaderModuleGetCompilationInfo([WGPUShaderModule]({{ '/api/c.html#class-ShaderModule' | relative_url }}) shaderModule, [WGPUCompilationInfoCallback]({{ '/api/c.html#function-pointer-CompilationInfoCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *shaderModule*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuShaderModuleReference([WGPUShaderModule]({{ '/api/c.html#class-ShaderModule' | relative_url }}) shaderModule)

</div>

#### Arguments

* *shaderModule*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuShaderModuleRelease([WGPUShaderModule]({{ '/api/c.html#class-ShaderModule' | relative_url }}) shaderModule)

</div>

#### Arguments

* *shaderModule*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuShaderModuleSetLabel([WGPUShaderModule]({{ '/api/c.html#class-ShaderModule' | relative_url }}) shaderModule, char const\* label)

</div>

#### Arguments

* *shaderModule*: 
* *label*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUSurface {#class-Surface}

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUTextureFormat]({{ '/api/c.html#enum-TextureFormat' | relative_url }}) wgpuSurfaceGetPreferredFormat([WGPUSurface]({{ '/api/c.html#class-Surface' | relative_url }}) surface, [WGPUAdapter]({{ '/api/c.html#class-Adapter' | relative_url }}) adapter)

</div>

#### Returns


#### Arguments

* *surface*: 
* *adapter*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSurfaceReference([WGPUSurface]({{ '/api/c.html#class-Surface' | relative_url }}) surface)

</div>

#### Arguments

* *surface*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSurfaceRelease([WGPUSurface]({{ '/api/c.html#class-Surface' | relative_url }}) surface)

</div>

#### Arguments

* *surface*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUSwapChain {#class-SwapChain}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSwapChainConfigure([WGPUSwapChain]({{ '/api/c.html#class-SwapChain' | relative_url }}) swapChain, [WGPUTextureFormat]({{ '/api/c.html#enum-TextureFormat' | relative_url }}) format, [WGPUTextureUsage]({{ '/api/c.html#bitmask-TextureUsage' | relative_url }}) allowedUsage, uint32_t width, uint32_t height)

</div>

#### Arguments

* *swapChain*: 
* *format*: 
* *allowedUsage*: 
* *width*: 
* *height*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUTextureView]({{ '/api/c.html#class-TextureView' | relative_url }}) wgpuSwapChainGetCurrentTextureView([WGPUSwapChain]({{ '/api/c.html#class-SwapChain' | relative_url }}) swapChain)

</div>

#### Returns


#### Arguments

* *swapChain*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSwapChainPresent([WGPUSwapChain]({{ '/api/c.html#class-SwapChain' | relative_url }}) swapChain)

</div>

#### Arguments

* *swapChain*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSwapChainReference([WGPUSwapChain]({{ '/api/c.html#class-SwapChain' | relative_url }}) swapChain)

</div>

#### Arguments

* *swapChain*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSwapChainRelease([WGPUSwapChain]({{ '/api/c.html#class-SwapChain' | relative_url }}) swapChain)

</div>

#### Arguments

* *swapChain*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUTexture {#class-Texture}

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUTextureView]({{ '/api/c.html#class-TextureView' | relative_url }}) wgpuTextureCreateView([WGPUTexture]({{ '/api/c.html#class-Texture' | relative_url }}) texture, [WGPUTextureViewDescriptor]({{ '/api/c.html#structure-TextureViewDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *texture*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuTextureDestroy([WGPUTexture]({{ '/api/c.html#class-Texture' | relative_url }}) texture)

</div>

#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t wgpuTextureGetDepthOrArrayLayers([WGPUTexture]({{ '/api/c.html#class-Texture' | relative_url }}) texture)

</div>

#### Returns


#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUTextureDimension]({{ '/api/c.html#enum-TextureDimension' | relative_url }}) wgpuTextureGetDimension([WGPUTexture]({{ '/api/c.html#class-Texture' | relative_url }}) texture)

</div>

#### Returns


#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUTextureFormat]({{ '/api/c.html#enum-TextureFormat' | relative_url }}) wgpuTextureGetFormat([WGPUTexture]({{ '/api/c.html#class-Texture' | relative_url }}) texture)

</div>

#### Returns


#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t wgpuTextureGetHeight([WGPUTexture]({{ '/api/c.html#class-Texture' | relative_url }}) texture)

</div>

#### Returns


#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t wgpuTextureGetMipLevelCount([WGPUTexture]({{ '/api/c.html#class-Texture' | relative_url }}) texture)

</div>

#### Returns


#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t wgpuTextureGetSampleCount([WGPUTexture]({{ '/api/c.html#class-Texture' | relative_url }}) texture)

</div>

#### Returns


#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUTextureUsage]({{ '/api/c.html#bitmask-TextureUsage' | relative_url }}) wgpuTextureGetUsage([WGPUTexture]({{ '/api/c.html#class-Texture' | relative_url }}) texture)

</div>

#### Returns


#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t wgpuTextureGetWidth([WGPUTexture]({{ '/api/c.html#class-Texture' | relative_url }}) texture)

</div>

#### Returns


#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuTextureReference([WGPUTexture]({{ '/api/c.html#class-Texture' | relative_url }}) texture)

</div>

#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuTextureRelease([WGPUTexture]({{ '/api/c.html#class-Texture' | relative_url }}) texture)

</div>

#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuTextureSetLabel([WGPUTexture]({{ '/api/c.html#class-Texture' | relative_url }}) texture, char const\* label)

</div>

#### Arguments

* *texture*: 
* *label*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUTextureView {#class-TextureView}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuTextureViewReference([WGPUTextureView]({{ '/api/c.html#class-TextureView' | relative_url }}) textureView)

</div>

#### Arguments

* *textureView*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuTextureViewRelease([WGPUTextureView]({{ '/api/c.html#class-TextureView' | relative_url }}) textureView)

</div>

#### Arguments

* *textureView*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuTextureViewSetLabel([WGPUTextureView]({{ '/api/c.html#class-TextureView' | relative_url }}) textureView, char const\* label)

</div>

#### Arguments

* *textureView*: 
* *label*: 

</div>

</div>

