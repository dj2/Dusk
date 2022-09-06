---
layout: page
title: C API
parent: API Documentation
---

# C API Documentation
## Constants

| Value | Description |
|:------|:------------|
| `WGPU_ARRAY_LAYER_COUNT_UNDEFINED` | Undefined value for array layer count |
| `WGPU_COPY_STRIDE_UNDEFINED` | Undefined value for copy stride |
| `WGPU_LIMIT_U32_UNDEFINED` | Undefined U32 limit value |
| `WGPU_LIMIT_U64_UNDEFINED` | Undefined U64 limit value |
| `WGPU_MIP_LEVEL_COUNT_UNDEFINED` | Undefined MIP level count |
| `WGPU_STRIDE_UNDEFINED` | Undefined stride |
| `WGPU_WHOLE_MAP_SIZE` | Value representing size of entire map |
| `WGPU_WHOLE_SIZE` | Value representing the whole size value |

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

[WGPUInstance](c.html#class-Instance) wgpuCreateInstance([WGPUInstanceDescriptor](c.html#structure-InstanceDescriptor) const\* descriptor)
</div>

#### Returns

The created [WGPUInstance](c.html#class-Instance).

#### Arguments

* *descriptor*: The [WGPUInstanceDescriptor](c.html#structure-InstanceDescriptor) pointer. Maybe `NULL`.

</div>

</div>

<div class='function' markdown=1>

### wgpuGetProcAddress {#function-GetProcAddress}

<div class='content' markdown=1>

Returns the function pointer for the requested WebGPU API method *procName*.

<div class='signature' markdown=1>

[WGPUProc](c.html#function-pointer-Proc) wgpuGetProcAddress([WGPUDevice](c.html#class-Device) device, char const\* procName)
</div>

#### Returns

The [WGPUProc](c.html#function-pointer-Proc) function pointer.

#### Arguments

* *device*: The [WGPUDevice](c.html#class-Device) to retrieve the proc for
* *procName*: The name of the pointer to retrieve

</div>

</div>

## Function Pointers

<div class='function' markdown=1>

### WGPUBufferMapCallback {#function-pointer-BufferMapCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;WGPUBufferMapCallback)([WGPUBufferMapAsyncStatus](c.html#enum-BufferMapAsyncStatus) status, void \* userdata)
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

void (&#x2a;WGPUCompilationInfoCallback)([WGPUCompilationInfoRequestStatus](c.html#enum-CompilationInfoRequestStatus) status, [WGPUCompilationInfo](c.html#structure-CompilationInfo) const\* compilationInfo, void \* userdata)
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

void (&#x2a;WGPUCreateComputePipelineAsyncCallback)([WGPUCreatePipelineAsyncStatus](c.html#enum-CreatePipelineAsyncStatus) status, [WGPUComputePipeline](c.html#class-ComputePipeline) pipeline, char const\* message, void \* userdata)
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

void (&#x2a;WGPUCreateRenderPipelineAsyncCallback)([WGPUCreatePipelineAsyncStatus](c.html#enum-CreatePipelineAsyncStatus) status, [WGPURenderPipeline](c.html#class-RenderPipeline) pipeline, char const\* message, void \* userdata)
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

void (&#x2a;WGPUDeviceLostCallback)([WGPUDeviceLostReason](c.html#enum-DeviceLostReason) reason, char const\* message, void \* userdata)
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

void (&#x2a;WGPUErrorCallback)([WGPUErrorType](c.html#enum-ErrorType) type, char const\* message, void \* userdata)
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

void (&#x2a;WGPULoggingCallback)([WGPULoggingType](c.html#enum-LoggingType) type, char const\* message, void \* userdata)
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

void (&#x2a;WGPUQueueWorkDoneCallback)([WGPUQueueWorkDoneStatus](c.html#enum-QueueWorkDoneStatus) status, void \* userdata)
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

void (&#x2a;WGPURequestAdapterCallback)([WGPURequestAdapterStatus](c.html#enum-RequestAdapterStatus) status, [WGPUAdapter](c.html#class-Adapter) adapter, char const\* message, void \* userdata)
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

void (&#x2a;WGPURequestDeviceCallback)([WGPURequestDeviceStatus](c.html#enum-RequestDeviceStatus) status, [WGPUDevice](c.html#class-Device) device, char const\* message, void \* userdata)
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
| uint32_t vendorID | The ID for the adapter vendor |
| char const\* vendorName | The vendor name for the adapter |
| char const\* architecture | The architectue of the adapter |
| uint32_t deviceID | The device ID for the adapter |
| char const\* name | The name of the adapter |
| char const\* driverDescription | The driver description reported by the adapter |
| [WGPUAdapterType](c.html#enum-AdapterType) adapterType | The type of the adapter |
| [WGPUBackendType](c.html#enum-BackendType) backendType | The backend platform used by the adapter |

### struct WGPUBindGroupDescriptor {#structure-BindGroupDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUBindGroupLayout](c.html#class-BindGroupLayout) layout |  |
| uint32_t entryCount |  |
| [WGPUBindGroupEntry](c.html#structure-BindGroupEntry) const\* entries |  |

### struct WGPUBindGroupEntry {#structure-BindGroupEntry}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| uint32_t binding |  |
| [WGPUBuffer](c.html#class-Buffer) buffer |  |
| uint64_t offset |  |
| uint64_t size |  |
| [WGPUSampler](c.html#class-Sampler) sampler |  |
| [WGPUTextureView](c.html#class-TextureView) textureView |  |

#### Chainable Structures

 * [WGPUExternalTextureBindingEntry](c.html#structure-ExternalTextureBindingEntry)

### struct WGPUBindGroupLayoutDescriptor {#structure-BindGroupLayoutDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| uint32_t entryCount |  |
| [WGPUBindGroupLayoutEntry](c.html#structure-BindGroupLayoutEntry) const\* entries |  |

### struct WGPUBindGroupLayoutEntry {#structure-BindGroupLayoutEntry}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| uint32_t binding |  |
| [WGPUShaderStage](c.html#bitmask-ShaderStage) visibility |  |
| [WGPUBufferBindingLayout](c.html#structure-BufferBindingLayout) buffer |  |
| [WGPUSamplerBindingLayout](c.html#structure-SamplerBindingLayout) sampler |  |
| [WGPUTextureBindingLayout](c.html#structure-TextureBindingLayout) texture |  |
| [WGPUStorageTextureBindingLayout](c.html#structure-StorageTextureBindingLayout) storageTexture |  |

#### Chainable Structures

 * [WGPUExternalTextureBindingLayout](c.html#structure-ExternalTextureBindingLayout)

### struct WGPUBlendComponent {#structure-BlendComponent}

| Members | Description |
|:--------|:------------|
| [WGPUBlendOperation](c.html#enum-BlendOperation) operation |  |
| [WGPUBlendFactor](c.html#enum-BlendFactor) srcFactor |  |
| [WGPUBlendFactor](c.html#enum-BlendFactor) dstFactor |  |

### struct WGPUBlendState {#structure-BlendState}

| Members | Description |
|:--------|:------------|
| [WGPUBlendComponent](c.html#structure-BlendComponent) color |  |
| [WGPUBlendComponent](c.html#structure-BlendComponent) alpha |  |

### struct WGPUBufferBindingLayout {#structure-BufferBindingLayout}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUBufferBindingType](c.html#enum-BufferBindingType) type |  |
| bool hasDynamicOffset |  |
| uint64_t minBindingSize |  |

### struct WGPUBufferDescriptor {#structure-BufferDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUBufferUsage](c.html#bitmask-BufferUsage) usage |  |
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
| [WGPUTextureFormat](c.html#enum-TextureFormat) format |  |
| [WGPUBlendState](c.html#structure-BlendState) const\* blend |  |
| [WGPUColorWriteMask](c.html#bitmask-ColorWriteMask) writeMask |  |

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

 * [WGPUDawnEncoderInternalUsageDescriptor](c.html#structure-DawnEncoderInternalUsageDescriptor)

### struct WGPUCompilationInfo {#structure-CompilationInfo}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| uint32_t messageCount |  |
| [WGPUCompilationMessage](c.html#structure-CompilationMessage) const\* messages |  |

### struct WGPUCompilationMessage {#structure-CompilationMessage}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* message |  |
| [WGPUCompilationMessageType](c.html#enum-CompilationMessageType) type |  |
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
| [WGPUComputePassTimestampWrite](c.html#structure-ComputePassTimestampWrite) const\* timestampWrites |  |

### struct WGPUComputePassTimestampWrite {#structure-ComputePassTimestampWrite}

| Members | Description |
|:--------|:------------|
| [WGPUQuerySet](c.html#class-QuerySet) querySet |  |
| uint32_t queryIndex |  |
| [WGPUComputePassTimestampLocation](c.html#enum-ComputePassTimestampLocation) location |  |

### struct WGPUComputePipelineDescriptor {#structure-ComputePipelineDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUPipelineLayout](c.html#class-PipelineLayout) layout |  |
| [WGPUProgrammableStageDescriptor](c.html#structure-ProgrammableStageDescriptor) compute |  |

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
| [WGPUAlphaMode](c.html#enum-AlphaMode) srcAlphaMode |  |
| float const\* srcTransferFunctionParameters |  |
| float const\* conversionMatrix |  |
| float const\* dstTransferFunctionParameters |  |
| [WGPUAlphaMode](c.html#enum-AlphaMode) dstAlphaMode |  |
| bool internalUsage |  |

### struct WGPUDawnCacheDeviceDescriptor {#structure-DawnCacheDeviceDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| char const\* isolationKey |  |

#### Chain Parent Structures

 * [WGPUDeviceDescriptor](c.html#structure-DeviceDescriptor)

### struct WGPUDawnEncoderInternalUsageDescriptor {#structure-DawnEncoderInternalUsageDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| bool useInternalUsages |  |

#### Chain Parent Structures

 * [WGPUCommandEncoderDescriptor](c.html#structure-CommandEncoderDescriptor)

### struct WGPUDawnInstanceDescriptor {#structure-DawnInstanceDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| uint32_t additionalRuntimeSearchPathsCount |  |
| char const\*const\* additionalRuntimeSearchPaths |  |

#### Chain Parent Structures

 * [WGPUInstanceDescriptor](c.html#structure-InstanceDescriptor)

### struct WGPUDawnTextureInternalUsageDescriptor {#structure-DawnTextureInternalUsageDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| [WGPUTextureUsage](c.html#bitmask-TextureUsage) internalUsage |  |

#### Chain Parent Structures

 * [WGPUTextureDescriptor](c.html#structure-TextureDescriptor)

### struct WGPUDawnTogglesDeviceDescriptor {#structure-DawnTogglesDeviceDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| uint32_t forceEnabledTogglesCount |  |
| char const\*const\* forceEnabledToggles |  |
| uint32_t forceDisabledTogglesCount |  |
| char const\*const\* forceDisabledToggles |  |

#### Chain Parent Structures

 * [WGPUDeviceDescriptor](c.html#structure-DeviceDescriptor)

### struct WGPUDepthStencilState {#structure-DepthStencilState}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUTextureFormat](c.html#enum-TextureFormat) format |  |
| bool depthWriteEnabled |  |
| [WGPUCompareFunction](c.html#enum-CompareFunction) depthCompare |  |
| [WGPUStencilFaceState](c.html#structure-StencilFaceState) stencilFront |  |
| [WGPUStencilFaceState](c.html#structure-StencilFaceState) stencilBack |  |
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
| [WGPUFeatureName](c.html#enum-FeatureName) const\* requiredFeatures |  |
| [WGPURequiredLimits](c.html#structure-RequiredLimits) const\* requiredLimits |  |
| [WGPUQueueDescriptor](c.html#structure-QueueDescriptor) defaultQueue |  |

#### Chainable Structures

 * [WGPUDawnTogglesDeviceDescriptor](c.html#structure-DawnTogglesDeviceDescriptor)
 * [WGPUDawnCacheDeviceDescriptor](c.html#structure-DawnCacheDeviceDescriptor)

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
| [WGPUExternalTexture](c.html#class-ExternalTexture) externalTexture |  |

#### Chain Parent Structures

 * [WGPUBindGroupEntry](c.html#structure-BindGroupEntry)

### struct WGPUExternalTextureBindingLayout {#structure-ExternalTextureBindingLayout}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|

#### Chain Parent Structures

 * [WGPUBindGroupLayoutEntry](c.html#structure-BindGroupLayoutEntry)

### struct WGPUExternalTextureDescriptor {#structure-ExternalTextureDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUTextureView](c.html#class-TextureView) plane0 |  |
| [WGPUTextureView](c.html#class-TextureView) plane1 |  |
| bool doYuvToRgbConversionOnly |  |
| float const\* yuvToRgbConversionMatrix |  |
| float const\* srcTransferFunctionParameters |  |
| float const\* dstTransferFunctionParameters |  |
| float const\* gamutConversionMatrix |  |

### struct WGPUFragmentState {#structure-FragmentState}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUShaderModule](c.html#class-ShaderModule) module |  |
| char const\* entryPoint |  |
| uint32_t constantCount |  |
| [WGPUConstantEntry](c.html#structure-ConstantEntry) const\* constants |  |
| uint32_t targetCount |  |
| [WGPUColorTargetState](c.html#structure-ColorTargetState) const\* targets |  |

### struct WGPUImageCopyBuffer {#structure-ImageCopyBuffer}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUTextureDataLayout](c.html#structure-TextureDataLayout) layout |  |
| [WGPUBuffer](c.html#class-Buffer) buffer |  |

### struct WGPUImageCopyTexture {#structure-ImageCopyTexture}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUTexture](c.html#class-Texture) texture |  |
| uint32_t mipLevel |  |
| [WGPUOrigin3D](c.html#structure-Origin3D) origin |  |
| [WGPUTextureAspect](c.html#enum-TextureAspect) aspect |  |

### struct WGPUInstanceDescriptor {#structure-InstanceDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |

#### Chainable Structures

 * [WGPUDawnInstanceDescriptor](c.html#structure-DawnInstanceDescriptor)

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
| [WGPUBindGroupLayout](c.html#class-BindGroupLayout) const\* bindGroupLayouts |  |

### struct WGPUPrimitiveDepthClipControl {#structure-PrimitiveDepthClipControl}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| bool unclippedDepth |  |

#### Chain Parent Structures

 * [WGPUPrimitiveState](c.html#structure-PrimitiveState)

### struct WGPUPrimitiveState {#structure-PrimitiveState}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUPrimitiveTopology](c.html#enum-PrimitiveTopology) topology |  |
| [WGPUIndexFormat](c.html#enum-IndexFormat) stripIndexFormat |  |
| [WGPUFrontFace](c.html#enum-FrontFace) frontFace |  |
| [WGPUCullMode](c.html#enum-CullMode) cullMode |  |

#### Chainable Structures

 * [WGPUPrimitiveDepthClipControl](c.html#structure-PrimitiveDepthClipControl)

### struct WGPUProgrammableStageDescriptor {#structure-ProgrammableStageDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUShaderModule](c.html#class-ShaderModule) module |  |
| char const\* entryPoint |  |
| uint32_t constantCount |  |
| [WGPUConstantEntry](c.html#structure-ConstantEntry) const\* constants |  |

### struct WGPUQuerySetDescriptor {#structure-QuerySetDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUQueryType](c.html#enum-QueryType) type |  |
| uint32_t count |  |
| [WGPUPipelineStatisticName](c.html#enum-PipelineStatisticName) const\* pipelineStatistics |  |
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
| [WGPUTextureFormat](c.html#enum-TextureFormat) const\* colorFormats |  |
| [WGPUTextureFormat](c.html#enum-TextureFormat) depthStencilFormat |  |
| uint32_t sampleCount |  |
| bool depthReadOnly |  |
| bool stencilReadOnly |  |

### struct WGPURenderPassColorAttachment {#structure-RenderPassColorAttachment}

| Members | Description |
|:--------|:------------|
| [WGPUTextureView](c.html#class-TextureView) view |  |
| [WGPUTextureView](c.html#class-TextureView) resolveTarget |  |
| [WGPULoadOp](c.html#enum-LoadOp) loadOp |  |
| [WGPUStoreOp](c.html#enum-StoreOp) storeOp |  |
| [WGPUColor](c.html#structure-Color) clearColor |  |
| [WGPUColor](c.html#structure-Color) clearValue |  |

### struct WGPURenderPassDepthStencilAttachment {#structure-RenderPassDepthStencilAttachment}

| Members | Description |
|:--------|:------------|
| [WGPUTextureView](c.html#class-TextureView) view |  |
| [WGPULoadOp](c.html#enum-LoadOp) depthLoadOp |  |
| [WGPUStoreOp](c.html#enum-StoreOp) depthStoreOp |  |
| float clearDepth |  |
| float depthClearValue |  |
| bool depthReadOnly |  |
| [WGPULoadOp](c.html#enum-LoadOp) stencilLoadOp |  |
| [WGPUStoreOp](c.html#enum-StoreOp) stencilStoreOp |  |
| uint32_t clearStencil |  |
| uint32_t stencilClearValue |  |
| bool stencilReadOnly |  |

### struct WGPURenderPassDescriptor {#structure-RenderPassDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| uint32_t colorAttachmentCount |  |
| [WGPURenderPassColorAttachment](c.html#structure-RenderPassColorAttachment) const\* colorAttachments |  |
| [WGPURenderPassDepthStencilAttachment](c.html#structure-RenderPassDepthStencilAttachment) const\* depthStencilAttachment |  |
| [WGPUQuerySet](c.html#class-QuerySet) occlusionQuerySet |  |
| uint32_t timestampWriteCount |  |
| [WGPURenderPassTimestampWrite](c.html#structure-RenderPassTimestampWrite) const\* timestampWrites |  |

#### Chainable Structures

 * [WGPURenderPassDescriptorMaxDrawCount](c.html#structure-RenderPassDescriptorMaxDrawCount)

### struct WGPURenderPassDescriptorMaxDrawCount {#structure-RenderPassDescriptorMaxDrawCount}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| uint64_t maxDrawCount |  |

#### Chain Parent Structures

 * [WGPURenderPassDescriptor](c.html#structure-RenderPassDescriptor)

### struct WGPURenderPassTimestampWrite {#structure-RenderPassTimestampWrite}

| Members | Description |
|:--------|:------------|
| [WGPUQuerySet](c.html#class-QuerySet) querySet |  |
| uint32_t queryIndex |  |
| [WGPURenderPassTimestampLocation](c.html#enum-RenderPassTimestampLocation) location |  |

### struct WGPURenderPipelineDescriptor {#structure-RenderPipelineDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUPipelineLayout](c.html#class-PipelineLayout) layout |  |
| [WGPUVertexState](c.html#structure-VertexState) vertex |  |
| [WGPUPrimitiveState](c.html#structure-PrimitiveState) primitive |  |
| [WGPUDepthStencilState](c.html#structure-DepthStencilState) const\* depthStencil |  |
| [WGPUMultisampleState](c.html#structure-MultisampleState) multisample |  |
| [WGPUFragmentState](c.html#structure-FragmentState) const\* fragment |  |

### struct WGPURequestAdapterOptions {#structure-RequestAdapterOptions}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUSurface](c.html#class-Surface) compatibleSurface |  |
| [WGPUPowerPreference](c.html#enum-PowerPreference) powerPreference |  |
| bool forceFallbackAdapter |  |

### struct WGPURequiredLimits {#structure-RequiredLimits}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPULimits](c.html#structure-Limits) limits |  |

### struct WGPUSamplerBindingLayout {#structure-SamplerBindingLayout}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUSamplerBindingType](c.html#enum-SamplerBindingType) type |  |

### struct WGPUSamplerDescriptor {#structure-SamplerDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUAddressMode](c.html#enum-AddressMode) addressModeU |  |
| [WGPUAddressMode](c.html#enum-AddressMode) addressModeV |  |
| [WGPUAddressMode](c.html#enum-AddressMode) addressModeW |  |
| [WGPUFilterMode](c.html#enum-FilterMode) magFilter |  |
| [WGPUFilterMode](c.html#enum-FilterMode) minFilter |  |
| [WGPUFilterMode](c.html#enum-FilterMode) mipmapFilter |  |
| [WGPUMipmapFilterMode](c.html#enum-MipmapFilterMode) mipmapFilter |  |
| float lodMinClamp |  |
| float lodMaxClamp |  |
| [WGPUCompareFunction](c.html#enum-CompareFunction) compare |  |
| uint16_t maxAnisotropy |  |

### struct WGPUShaderModuleSPIRVDescriptor {#structure-ShaderModuleSPIRVDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| uint32_t codeSize |  |
| uint32_t const\* code |  |

#### Chain Parent Structures

 * [WGPUShaderModuleDescriptor](c.html#structure-ShaderModuleDescriptor)

### struct WGPUShaderModuleWGSLDescriptor {#structure-ShaderModuleWGSLDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| char const\* source |  |
| char const\* code |  |

#### Chain Parent Structures

 * [WGPUShaderModuleDescriptor](c.html#structure-ShaderModuleDescriptor)

### struct WGPUShaderModuleCompilationHint {#structure-ShaderModuleCompilationHint}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* entryPoint |  |
| [WGPUPipelineLayout](c.html#class-PipelineLayout) layout |  |

### struct WGPUShaderModuleDescriptor {#structure-ShaderModuleDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| uint32_t hintCount |  |
| [WGPUShaderModuleCompilationHint](c.html#structure-ShaderModuleCompilationHint) const\* hints |  |

#### Chainable Structures

 * [WGPUShaderModuleSPIRVDescriptor](c.html#structure-ShaderModuleSPIRVDescriptor)
 * [WGPUShaderModuleWGSLDescriptor](c.html#structure-ShaderModuleWGSLDescriptor)

### struct WGPUStencilFaceState {#structure-StencilFaceState}

| Members | Description |
|:--------|:------------|
| [WGPUCompareFunction](c.html#enum-CompareFunction) compare |  |
| [WGPUStencilOperation](c.html#enum-StencilOperation) failOp |  |
| [WGPUStencilOperation](c.html#enum-StencilOperation) depthFailOp |  |
| [WGPUStencilOperation](c.html#enum-StencilOperation) passOp |  |

### struct WGPUStorageTextureBindingLayout {#structure-StorageTextureBindingLayout}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUStorageTextureAccess](c.html#enum-StorageTextureAccess) access |  |
| [WGPUTextureFormat](c.html#enum-TextureFormat) format |  |
| [WGPUTextureViewDimension](c.html#enum-TextureViewDimension) viewDimension |  |

### struct WGPUSupportedLimits {#structure-SupportedLimits}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStructOut* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPULimits](c.html#structure-Limits) limits |  |

### struct WGPUSurfaceDescriptor {#structure-SurfaceDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |

#### Chainable Structures

 * [WGPUSurfaceDescriptorFromAndroidNativeWindow](c.html#structure-SurfaceDescriptorFromAndroidNativeWindow)
 * [WGPUSurfaceDescriptorFromCanvasHTMLSelector](c.html#structure-SurfaceDescriptorFromCanvasHTMLSelector)
 * [WGPUSurfaceDescriptorFromMetalLayer](c.html#structure-SurfaceDescriptorFromMetalLayer)
 * [WGPUSurfaceDescriptorFromWindowsHWND](c.html#structure-SurfaceDescriptorFromWindowsHWND)
 * [WGPUSurfaceDescriptorFromXcbWindow](c.html#structure-SurfaceDescriptorFromXcbWindow)
 * [WGPUSurfaceDescriptorFromXlibWindow](c.html#structure-SurfaceDescriptorFromXlibWindow)
 * [WGPUSurfaceDescriptorFromWaylandSurface](c.html#structure-SurfaceDescriptorFromWaylandSurface)
 * [WGPUSurfaceDescriptorFromWindowsCoreWindow](c.html#structure-SurfaceDescriptorFromWindowsCoreWindow)
 * [WGPUSurfaceDescriptorFromWindowsSwapChainPanel](c.html#structure-SurfaceDescriptorFromWindowsSwapChainPanel)

### struct WGPUSurfaceDescriptorFromAndroidNativeWindow {#structure-SurfaceDescriptorFromAndroidNativeWindow}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| void \* window |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor](c.html#structure-SurfaceDescriptor)

### struct WGPUSurfaceDescriptorFromCanvasHTMLSelector {#structure-SurfaceDescriptorFromCanvasHTMLSelector}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| char const\* selector |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor](c.html#structure-SurfaceDescriptor)

### struct WGPUSurfaceDescriptorFromMetalLayer {#structure-SurfaceDescriptorFromMetalLayer}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| void \* layer |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor](c.html#structure-SurfaceDescriptor)

### struct WGPUSurfaceDescriptorFromWaylandSurface {#structure-SurfaceDescriptorFromWaylandSurface}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| void \* display |  |
| void \* surface |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor](c.html#structure-SurfaceDescriptor)

### struct WGPUSurfaceDescriptorFromWindowsHWND {#structure-SurfaceDescriptorFromWindowsHWND}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| void \* hinstance |  |
| void \* hwnd |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor](c.html#structure-SurfaceDescriptor)

### struct WGPUSurfaceDescriptorFromWindowsCoreWindow {#structure-SurfaceDescriptorFromWindowsCoreWindow}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| void \* coreWindow |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor](c.html#structure-SurfaceDescriptor)

### struct WGPUSurfaceDescriptorFromWindowsSwapChainPanel {#structure-SurfaceDescriptorFromWindowsSwapChainPanel}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| void \* swapChainPanel |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor](c.html#structure-SurfaceDescriptor)

### struct WGPUSurfaceDescriptorFromXcbWindow {#structure-SurfaceDescriptorFromXcbWindow}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| void \* connection |  |
| uint32_t window |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor](c.html#structure-SurfaceDescriptor)

### struct WGPUSurfaceDescriptorFromXlibWindow {#structure-SurfaceDescriptorFromXlibWindow}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct chain` | | ChainedStruct base object|
| void \* display |  |
| uint32_t window |  |

#### Chain Parent Structures

 * [WGPUSurfaceDescriptor](c.html#structure-SurfaceDescriptor)

### struct WGPUSwapChainDescriptor {#structure-SwapChainDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUTextureUsage](c.html#bitmask-TextureUsage) usage |  |
| [WGPUTextureFormat](c.html#enum-TextureFormat) format |  |
| uint32_t width |  |
| uint32_t height |  |
| [WGPUPresentMode](c.html#enum-PresentMode) presentMode |  |
| uint64_t implementation |  |

### struct WGPUTextureBindingLayout {#structure-TextureBindingLayout}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUTextureSampleType](c.html#enum-TextureSampleType) sampleType |  |
| [WGPUTextureViewDimension](c.html#enum-TextureViewDimension) viewDimension |  |
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
| [WGPUTextureUsage](c.html#bitmask-TextureUsage) usage |  |
| [WGPUTextureDimension](c.html#enum-TextureDimension) dimension |  |
| [WGPUExtent3D](c.html#structure-Extent3D) size |  |
| [WGPUTextureFormat](c.html#enum-TextureFormat) format |  |
| uint32_t mipLevelCount |  |
| uint32_t sampleCount |  |
| uint32_t viewFormatCount |  |
| [WGPUTextureFormat](c.html#enum-TextureFormat) const\* viewFormats |  |

#### Chainable Structures

 * [WGPUDawnTextureInternalUsageDescriptor](c.html#structure-DawnTextureInternalUsageDescriptor)

### struct WGPUTextureViewDescriptor {#structure-TextureViewDescriptor}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| char const\* label |  |
| [WGPUTextureFormat](c.html#enum-TextureFormat) format |  |
| [WGPUTextureViewDimension](c.html#enum-TextureViewDimension) dimension |  |
| uint32_t baseMipLevel |  |
| uint32_t mipLevelCount |  |
| uint32_t baseArrayLayer |  |
| uint32_t arrayLayerCount |  |
| [WGPUTextureAspect](c.html#enum-TextureAspect) aspect |  |

### struct WGPUVertexAttribute {#structure-VertexAttribute}

| Members | Description |
|:--------|:------------|
| [WGPUVertexFormat](c.html#enum-VertexFormat) format |  |
| uint64_t offset |  |
| uint32_t shaderLocation |  |

### struct WGPUVertexBufferLayout {#structure-VertexBufferLayout}

| Members | Description |
|:--------|:------------|
| uint64_t arrayStride |  |
| [WGPUVertexStepMode](c.html#enum-VertexStepMode) stepMode |  |
| uint32_t attributeCount |  |
| [WGPUVertexAttribute](c.html#structure-VertexAttribute) const\* attributes |  |

### struct WGPUVertexState {#structure-VertexState}

| Members | Description |
|:--------|:------------|
| `WGPUChainedStruct const* nextInChain` | Pointer to next chained structure. Maybe `NULL`. |
| [WGPUShaderModule](c.html#class-ShaderModule) module |  |
| char const\* entryPoint |  |
| uint32_t constantCount |  |
| [WGPUConstantEntry](c.html#structure-ConstantEntry) const\* constants |  |
| uint32_t bufferCount |  |
| [WGPUVertexBufferLayout](c.html#structure-VertexBufferLayout) const\* buffers |  |

## Methods

<div class='object' markdown=1>

### Methods of WGPUAdapter {#class-Adapter}

An *adapter* identifies an implemention of WebGPU on the system.

See [Adapters](https://webgpu.dev/#adapters) for more information.

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUDevice](c.html#class-Device) wgpuAdapterCreateDevice([WGPUAdapter](c.html#class-Adapter) adapter, [WGPUDeviceDescriptor](c.html#structure-DeviceDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *adapter*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

size_t wgpuAdapterEnumerateFeatures([WGPUAdapter](c.html#class-Adapter) adapter, [WGPUFeatureName](c.html#enum-FeatureName) \* features)

</div>

#### Returns


#### Arguments

* *adapter*: 
* *features*: 

</div>

<div class='method' markdown=1>

Retrieves the limits which can be used with this adapter.

<div class='signature' markdown=1>

bool wgpuAdapterGetLimits([WGPUAdapter](c.html#class-Adapter) adapter, [WGPUSupportedLimits](c.html#structure-SupportedLimits) \* limits)

</div>

#### Returns

Returns true if the limits were successfully retrieved.
#### Arguments

* *adapter*: The [WGPUAdapter](c.html#class-Adapter) from which to query the limits.
* *limits*: The [WGPUSupportedLimits](c.html#structure-SupportedLimits) object to populate. Must not be NULL.

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuAdapterGetProperties([WGPUAdapter](c.html#class-Adapter) adapter, [WGPUAdapterProperties](c.html#structure-AdapterProperties) \* properties)

</div>

#### Arguments

* *adapter*: 
* *properties*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

bool wgpuAdapterHasFeature([WGPUAdapter](c.html#class-Adapter) adapter, [WGPUFeatureName](c.html#enum-FeatureName) feature)

</div>

#### Returns


#### Arguments

* *adapter*: 
* *feature*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuAdapterReference([WGPUAdapter](c.html#class-Adapter) adapter)

</div>

#### Arguments

* *adapter*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuAdapterRelease([WGPUAdapter](c.html#class-Adapter) adapter)

</div>

#### Arguments

* *adapter*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuAdapterRequestDevice([WGPUAdapter](c.html#class-Adapter) adapter, [WGPUDeviceDescriptor](c.html#structure-DeviceDescriptor) const\* descriptor, [WGPURequestDeviceCallback](c.html#function-pointer-RequestDeviceCallback) callback, void \* userdata)

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

void wgpuBindGroupReference([WGPUBindGroup](c.html#class-BindGroup) bindGroup)

</div>

#### Arguments

* *bindGroup*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBindGroupRelease([WGPUBindGroup](c.html#class-BindGroup) bindGroup)

</div>

#### Arguments

* *bindGroup*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBindGroupSetLabel([WGPUBindGroup](c.html#class-BindGroup) bindGroup, char const\* label)

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

void wgpuBindGroupLayoutReference([WGPUBindGroupLayout](c.html#class-BindGroupLayout) bindGroupLayout)

</div>

#### Arguments

* *bindGroupLayout*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBindGroupLayoutRelease([WGPUBindGroupLayout](c.html#class-BindGroupLayout) bindGroupLayout)

</div>

#### Arguments

* *bindGroupLayout*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBindGroupLayoutSetLabel([WGPUBindGroupLayout](c.html#class-BindGroupLayout) bindGroupLayout, char const\* label)

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

void wgpuBufferDestroy([WGPUBuffer](c.html#class-Buffer) buffer)

</div>

#### Arguments

* *buffer*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void const * wgpuBufferGetConstMappedRange([WGPUBuffer](c.html#class-Buffer) buffer, size_t offset, size_t size)

</div>

#### Returns


#### Arguments

* *buffer*: 
* *offset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void * wgpuBufferGetMappedRange([WGPUBuffer](c.html#class-Buffer) buffer, size_t offset, size_t size)

</div>

#### Returns


#### Arguments

* *buffer*: 
* *offset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint64_t wgpuBufferGetSize([WGPUBuffer](c.html#class-Buffer) buffer)

</div>

#### Returns


#### Arguments

* *buffer*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUBufferUsage](c.html#bitmask-BufferUsage) wgpuBufferGetUsage([WGPUBuffer](c.html#class-Buffer) buffer)

</div>

#### Returns


#### Arguments

* *buffer*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBufferMapAsync([WGPUBuffer](c.html#class-Buffer) buffer, [WGPUMapMode](c.html#bitmask-MapMode) mode, size_t offset, size_t size, [WGPUBufferMapCallback](c.html#function-pointer-BufferMapCallback) callback, void \* userdata)

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

void wgpuBufferReference([WGPUBuffer](c.html#class-Buffer) buffer)

</div>

#### Arguments

* *buffer*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBufferRelease([WGPUBuffer](c.html#class-Buffer) buffer)

</div>

#### Arguments

* *buffer*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBufferSetLabel([WGPUBuffer](c.html#class-Buffer) buffer, char const\* label)

</div>

#### Arguments

* *buffer*: 
* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuBufferUnmap([WGPUBuffer](c.html#class-Buffer) buffer)

</div>

#### Arguments

* *buffer*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUCommandBuffer {#class-CommandBuffer}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandBufferReference([WGPUCommandBuffer](c.html#class-CommandBuffer) commandBuffer)

</div>

#### Arguments

* *commandBuffer*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandBufferRelease([WGPUCommandBuffer](c.html#class-CommandBuffer) commandBuffer)

</div>

#### Arguments

* *commandBuffer*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandBufferSetLabel([WGPUCommandBuffer](c.html#class-CommandBuffer) commandBuffer, char const\* label)

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

[WGPUComputePassEncoder](c.html#class-ComputePassEncoder) wgpuCommandEncoderBeginComputePass([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder, [WGPUComputePassDescriptor](c.html#structure-ComputePassDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *commandEncoder*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPURenderPassEncoder](c.html#class-RenderPassEncoder) wgpuCommandEncoderBeginRenderPass([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder, [WGPURenderPassDescriptor](c.html#structure-RenderPassDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *commandEncoder*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderClearBuffer([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder, [WGPUBuffer](c.html#class-Buffer) buffer, uint64_t offset, uint64_t size)

</div>

#### Arguments

* *commandEncoder*: 
* *buffer*: 
* *offset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderCopyBufferToBuffer([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder, [WGPUBuffer](c.html#class-Buffer) source, uint64_t sourceOffset, [WGPUBuffer](c.html#class-Buffer) destination, uint64_t destinationOffset, uint64_t size)

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

void wgpuCommandEncoderCopyBufferToTexture([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder, [WGPUImageCopyBuffer](c.html#structure-ImageCopyBuffer) const\* source, [WGPUImageCopyTexture](c.html#structure-ImageCopyTexture) const\* destination, [WGPUExtent3D](c.html#structure-Extent3D) const\* copySize)

</div>

#### Arguments

* *commandEncoder*: 
* *source*: 
* *destination*: 
* *copySize*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderCopyTextureToBuffer([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder, [WGPUImageCopyTexture](c.html#structure-ImageCopyTexture) const\* source, [WGPUImageCopyBuffer](c.html#structure-ImageCopyBuffer) const\* destination, [WGPUExtent3D](c.html#structure-Extent3D) const\* copySize)

</div>

#### Arguments

* *commandEncoder*: 
* *source*: 
* *destination*: 
* *copySize*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderCopyTextureToTexture([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder, [WGPUImageCopyTexture](c.html#structure-ImageCopyTexture) const\* source, [WGPUImageCopyTexture](c.html#structure-ImageCopyTexture) const\* destination, [WGPUExtent3D](c.html#structure-Extent3D) const\* copySize)

</div>

#### Arguments

* *commandEncoder*: 
* *source*: 
* *destination*: 
* *copySize*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderCopyTextureToTextureInternal([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder, [WGPUImageCopyTexture](c.html#structure-ImageCopyTexture) const\* source, [WGPUImageCopyTexture](c.html#structure-ImageCopyTexture) const\* destination, [WGPUExtent3D](c.html#structure-Extent3D) const\* copySize)

</div>

#### Arguments

* *commandEncoder*: 
* *source*: 
* *destination*: 
* *copySize*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUCommandBuffer](c.html#class-CommandBuffer) wgpuCommandEncoderFinish([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder, [WGPUCommandBufferDescriptor](c.html#structure-CommandBufferDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *commandEncoder*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderInjectValidationError([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder, char const\* message)

</div>

#### Arguments

* *commandEncoder*: 
* *message*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderInsertDebugMarker([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder, char const\* markerLabel)

</div>

#### Arguments

* *commandEncoder*: 
* *markerLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderPopDebugGroup([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder)

</div>

#### Arguments

* *commandEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderPushDebugGroup([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder, char const\* groupLabel)

</div>

#### Arguments

* *commandEncoder*: 
* *groupLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderReference([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder)

</div>

#### Arguments

* *commandEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderRelease([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder)

</div>

#### Arguments

* *commandEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderResolveQuerySet([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder, [WGPUQuerySet](c.html#class-QuerySet) querySet, uint32_t firstQuery, uint32_t queryCount, [WGPUBuffer](c.html#class-Buffer) destination, uint64_t destinationOffset)

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

void wgpuCommandEncoderSetLabel([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder, char const\* label)

</div>

#### Arguments

* *commandEncoder*: 
* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuCommandEncoderWriteBuffer([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder, [WGPUBuffer](c.html#class-Buffer) buffer, uint64_t bufferOffset, uint8_t const\* data, uint64_t size)

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

void wgpuCommandEncoderWriteTimestamp([WGPUCommandEncoder](c.html#class-CommandEncoder) commandEncoder, [WGPUQuerySet](c.html#class-QuerySet) querySet, uint32_t queryIndex)

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

void wgpuComputePassEncoderBeginPipelineStatisticsQuery([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder, [WGPUQuerySet](c.html#class-QuerySet) querySet, uint32_t queryIndex)

</div>

#### Arguments

* *computePassEncoder*: 
* *querySet*: 
* *queryIndex*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderDispatch([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder, uint32_t workgroupCountX, uint32_t workgroupCountY, uint32_t workgroupCountZ)

</div>

#### Arguments

* *computePassEncoder*: 
* *workgroupCountX*: 
* *workgroupCountY*: 
* *workgroupCountZ*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderDispatchIndirect([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder, [WGPUBuffer](c.html#class-Buffer) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *computePassEncoder*: 
* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderDispatchWorkgroups([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder, uint32_t workgroupCountX, uint32_t workgroupCountY, uint32_t workgroupCountZ)

</div>

#### Arguments

* *computePassEncoder*: 
* *workgroupCountX*: 
* *workgroupCountY*: 
* *workgroupCountZ*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderDispatchWorkgroupsIndirect([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder, [WGPUBuffer](c.html#class-Buffer) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *computePassEncoder*: 
* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderEnd([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder)

</div>

#### Arguments

* *computePassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderEndPass([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder)

</div>

#### Arguments

* *computePassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderEndPipelineStatisticsQuery([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder)

</div>

#### Arguments

* *computePassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderInsertDebugMarker([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder, char const\* markerLabel)

</div>

#### Arguments

* *computePassEncoder*: 
* *markerLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderPopDebugGroup([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder)

</div>

#### Arguments

* *computePassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderPushDebugGroup([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder, char const\* groupLabel)

</div>

#### Arguments

* *computePassEncoder*: 
* *groupLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderReference([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder)

</div>

#### Arguments

* *computePassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderRelease([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder)

</div>

#### Arguments

* *computePassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderSetBindGroup([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder, uint32_t groupIndex, [WGPUBindGroup](c.html#class-BindGroup) group, uint32_t dynamicOffsetCount, uint32_t const\* dynamicOffsets)

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

void wgpuComputePassEncoderSetLabel([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder, char const\* label)

</div>

#### Arguments

* *computePassEncoder*: 
* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderSetPipeline([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder, [WGPUComputePipeline](c.html#class-ComputePipeline) pipeline)

</div>

#### Arguments

* *computePassEncoder*: 
* *pipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePassEncoderWriteTimestamp([WGPUComputePassEncoder](c.html#class-ComputePassEncoder) computePassEncoder, [WGPUQuerySet](c.html#class-QuerySet) querySet, uint32_t queryIndex)

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

[WGPUBindGroupLayout](c.html#class-BindGroupLayout) wgpuComputePipelineGetBindGroupLayout([WGPUComputePipeline](c.html#class-ComputePipeline) computePipeline, uint32_t groupIndex)

</div>

#### Returns


#### Arguments

* *computePipeline*: 
* *groupIndex*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePipelineReference([WGPUComputePipeline](c.html#class-ComputePipeline) computePipeline)

</div>

#### Arguments

* *computePipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePipelineRelease([WGPUComputePipeline](c.html#class-ComputePipeline) computePipeline)

</div>

#### Arguments

* *computePipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuComputePipelineSetLabel([WGPUComputePipeline](c.html#class-ComputePipeline) computePipeline, char const\* label)

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

[WGPUBindGroup](c.html#class-BindGroup) wgpuDeviceCreateBindGroup([WGPUDevice](c.html#class-Device) device, [WGPUBindGroupDescriptor](c.html#structure-BindGroupDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUBindGroupLayout](c.html#class-BindGroupLayout) wgpuDeviceCreateBindGroupLayout([WGPUDevice](c.html#class-Device) device, [WGPUBindGroupLayoutDescriptor](c.html#structure-BindGroupLayoutDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUBuffer](c.html#class-Buffer) wgpuDeviceCreateBuffer([WGPUDevice](c.html#class-Device) device, [WGPUBufferDescriptor](c.html#structure-BufferDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUCommandEncoder](c.html#class-CommandEncoder) wgpuDeviceCreateCommandEncoder([WGPUDevice](c.html#class-Device) device, [WGPUCommandEncoderDescriptor](c.html#structure-CommandEncoderDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUComputePipeline](c.html#class-ComputePipeline) wgpuDeviceCreateComputePipeline([WGPUDevice](c.html#class-Device) device, [WGPUComputePipelineDescriptor](c.html#structure-ComputePipelineDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceCreateComputePipelineAsync([WGPUDevice](c.html#class-Device) device, [WGPUComputePipelineDescriptor](c.html#structure-ComputePipelineDescriptor) const\* descriptor, [WGPUCreateComputePipelineAsyncCallback](c.html#function-pointer-CreateComputePipelineAsyncCallback) callback, void \* userdata)

</div>

#### Arguments

* *device*: 
* *descriptor*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUBuffer](c.html#class-Buffer) wgpuDeviceCreateErrorBuffer([WGPUDevice](c.html#class-Device) device)

</div>

#### Returns


#### Arguments

* *device*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUExternalTexture](c.html#class-ExternalTexture) wgpuDeviceCreateErrorExternalTexture([WGPUDevice](c.html#class-Device) device)

</div>

#### Returns


#### Arguments

* *device*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUTexture](c.html#class-Texture) wgpuDeviceCreateErrorTexture([WGPUDevice](c.html#class-Device) device, [WGPUTextureDescriptor](c.html#structure-TextureDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUExternalTexture](c.html#class-ExternalTexture) wgpuDeviceCreateExternalTexture([WGPUDevice](c.html#class-Device) device, [WGPUExternalTextureDescriptor](c.html#structure-ExternalTextureDescriptor) const\* externalTextureDescriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *externalTextureDescriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUPipelineLayout](c.html#class-PipelineLayout) wgpuDeviceCreatePipelineLayout([WGPUDevice](c.html#class-Device) device, [WGPUPipelineLayoutDescriptor](c.html#structure-PipelineLayoutDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUQuerySet](c.html#class-QuerySet) wgpuDeviceCreateQuerySet([WGPUDevice](c.html#class-Device) device, [WGPUQuerySetDescriptor](c.html#structure-QuerySetDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPURenderBundleEncoder](c.html#class-RenderBundleEncoder) wgpuDeviceCreateRenderBundleEncoder([WGPUDevice](c.html#class-Device) device, [WGPURenderBundleEncoderDescriptor](c.html#structure-RenderBundleEncoderDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPURenderPipeline](c.html#class-RenderPipeline) wgpuDeviceCreateRenderPipeline([WGPUDevice](c.html#class-Device) device, [WGPURenderPipelineDescriptor](c.html#structure-RenderPipelineDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceCreateRenderPipelineAsync([WGPUDevice](c.html#class-Device) device, [WGPURenderPipelineDescriptor](c.html#structure-RenderPipelineDescriptor) const\* descriptor, [WGPUCreateRenderPipelineAsyncCallback](c.html#function-pointer-CreateRenderPipelineAsyncCallback) callback, void \* userdata)

</div>

#### Arguments

* *device*: 
* *descriptor*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUSampler](c.html#class-Sampler) wgpuDeviceCreateSampler([WGPUDevice](c.html#class-Device) device, [WGPUSamplerDescriptor](c.html#structure-SamplerDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUShaderModule](c.html#class-ShaderModule) wgpuDeviceCreateShaderModule([WGPUDevice](c.html#class-Device) device, [WGPUShaderModuleDescriptor](c.html#structure-ShaderModuleDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUSwapChain](c.html#class-SwapChain) wgpuDeviceCreateSwapChain([WGPUDevice](c.html#class-Device) device, [WGPUSurface](c.html#class-Surface) surface, [WGPUSwapChainDescriptor](c.html#structure-SwapChainDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *surface*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUSwapChain](c.html#class-SwapChain) wgpuDeviceCreateSwapChain([WGPUDevice](c.html#class-Device) device, [WGPUSurface](c.html#class-Surface) surface, [WGPUSwapChainDescriptor](c.html#structure-SwapChainDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *surface*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUTexture](c.html#class-Texture) wgpuDeviceCreateTexture([WGPUDevice](c.html#class-Device) device, [WGPUTextureDescriptor](c.html#structure-TextureDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *device*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceDestroy([WGPUDevice](c.html#class-Device) device)

</div>

#### Arguments

* *device*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

size_t wgpuDeviceEnumerateFeatures([WGPUDevice](c.html#class-Device) device, [WGPUFeatureName](c.html#enum-FeatureName) \* features)

</div>

#### Returns


#### Arguments

* *device*: 
* *features*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceForceLoss([WGPUDevice](c.html#class-Device) device, [WGPUDeviceLostReason](c.html#enum-DeviceLostReason) type, char const\* message)

</div>

#### Arguments

* *device*: 
* *type*: 
* *message*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUAdapter](c.html#class-Adapter) wgpuDeviceGetAdapter([WGPUDevice](c.html#class-Device) device)

</div>

#### Returns


#### Arguments

* *device*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

bool wgpuDeviceGetLimits([WGPUDevice](c.html#class-Device) device, [WGPUSupportedLimits](c.html#structure-SupportedLimits) \* limits)

</div>

#### Returns


#### Arguments

* *device*: 
* *limits*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUQueue](c.html#class-Queue) wgpuDeviceGetQueue([WGPUDevice](c.html#class-Device) device)

</div>

#### Returns


#### Arguments

* *device*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

bool wgpuDeviceHasFeature([WGPUDevice](c.html#class-Device) device, [WGPUFeatureName](c.html#enum-FeatureName) feature)

</div>

#### Returns


#### Arguments

* *device*: 
* *feature*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceInjectError([WGPUDevice](c.html#class-Device) device, [WGPUErrorType](c.html#enum-ErrorType) type, char const\* message)

</div>

#### Arguments

* *device*: 
* *type*: 
* *message*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

bool wgpuDevicePopErrorScope([WGPUDevice](c.html#class-Device) device, [WGPUErrorCallback](c.html#function-pointer-ErrorCallback) callback, void \* userdata)

</div>

#### Returns


#### Arguments

* *device*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDevicePushErrorScope([WGPUDevice](c.html#class-Device) device, [WGPUErrorFilter](c.html#enum-ErrorFilter) filter)

</div>

#### Arguments

* *device*: 
* *filter*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceReference([WGPUDevice](c.html#class-Device) device)

</div>

#### Arguments

* *device*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceRelease([WGPUDevice](c.html#class-Device) device)

</div>

#### Arguments

* *device*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceSetDeviceLostCallback([WGPUDevice](c.html#class-Device) device, [WGPUDeviceLostCallback](c.html#function-pointer-DeviceLostCallback) callback, void \* userdata)

</div>

#### Arguments

* *device*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceSetLabel([WGPUDevice](c.html#class-Device) device, char const\* label)

</div>

#### Arguments

* *device*: 
* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceSetLoggingCallback([WGPUDevice](c.html#class-Device) device, [WGPULoggingCallback](c.html#function-pointer-LoggingCallback) callback, void \* userdata)

</div>

#### Arguments

* *device*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceSetUncapturedErrorCallback([WGPUDevice](c.html#class-Device) device, [WGPUErrorCallback](c.html#function-pointer-ErrorCallback) callback, void \* userdata)

</div>

#### Arguments

* *device*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuDeviceTick([WGPUDevice](c.html#class-Device) device)

</div>

#### Arguments

* *device*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUExternalTexture {#class-ExternalTexture}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuExternalTextureDestroy([WGPUExternalTexture](c.html#class-ExternalTexture) externalTexture)

</div>

#### Arguments

* *externalTexture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuExternalTextureReference([WGPUExternalTexture](c.html#class-ExternalTexture) externalTexture)

</div>

#### Arguments

* *externalTexture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuExternalTextureRelease([WGPUExternalTexture](c.html#class-ExternalTexture) externalTexture)

</div>

#### Arguments

* *externalTexture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuExternalTextureSetLabel([WGPUExternalTexture](c.html#class-ExternalTexture) externalTexture, char const\* label)

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

[WGPUSurface](c.html#class-Surface) wgpuInstanceCreateSurface([WGPUInstance](c.html#class-Instance) instance, [WGPUSurfaceDescriptor](c.html#structure-SurfaceDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *instance*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuInstanceProcessEvents([WGPUInstance](c.html#class-Instance) instance)

</div>

#### Arguments

* *instance*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuInstanceReference([WGPUInstance](c.html#class-Instance) instance)

</div>

#### Arguments

* *instance*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuInstanceRelease([WGPUInstance](c.html#class-Instance) instance)

</div>

#### Arguments

* *instance*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuInstanceRequestAdapter([WGPUInstance](c.html#class-Instance) instance, [WGPURequestAdapterOptions](c.html#structure-RequestAdapterOptions) const\* options, [WGPURequestAdapterCallback](c.html#function-pointer-RequestAdapterCallback) callback, void \* userdata)

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

void wgpuPipelineLayoutReference([WGPUPipelineLayout](c.html#class-PipelineLayout) pipelineLayout)

</div>

#### Arguments

* *pipelineLayout*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuPipelineLayoutRelease([WGPUPipelineLayout](c.html#class-PipelineLayout) pipelineLayout)

</div>

#### Arguments

* *pipelineLayout*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuPipelineLayoutSetLabel([WGPUPipelineLayout](c.html#class-PipelineLayout) pipelineLayout, char const\* label)

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

void wgpuQuerySetDestroy([WGPUQuerySet](c.html#class-QuerySet) querySet)

</div>

#### Arguments

* *querySet*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t wgpuQuerySetGetCount([WGPUQuerySet](c.html#class-QuerySet) querySet)

</div>

#### Returns


#### Arguments

* *querySet*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUQueryType](c.html#enum-QueryType) wgpuQuerySetGetType([WGPUQuerySet](c.html#class-QuerySet) querySet)

</div>

#### Returns


#### Arguments

* *querySet*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQuerySetReference([WGPUQuerySet](c.html#class-QuerySet) querySet)

</div>

#### Arguments

* *querySet*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQuerySetRelease([WGPUQuerySet](c.html#class-QuerySet) querySet)

</div>

#### Arguments

* *querySet*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQuerySetSetLabel([WGPUQuerySet](c.html#class-QuerySet) querySet, char const\* label)

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

void wgpuQueueCopyTextureForBrowser([WGPUQueue](c.html#class-Queue) queue, [WGPUImageCopyTexture](c.html#structure-ImageCopyTexture) const\* source, [WGPUImageCopyTexture](c.html#structure-ImageCopyTexture) const\* destination, [WGPUExtent3D](c.html#structure-Extent3D) const\* copySize, [WGPUCopyTextureForBrowserOptions](c.html#structure-CopyTextureForBrowserOptions) const\* options)

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

void wgpuQueueOnSubmittedWorkDone([WGPUQueue](c.html#class-Queue) queue, uint64_t signalValue, [WGPUQueueWorkDoneCallback](c.html#function-pointer-QueueWorkDoneCallback) callback, void \* userdata)

</div>

#### Arguments

* *queue*: 
* *signalValue*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQueueOnSubmittedWorkDone([WGPUQueue](c.html#class-Queue) queue, [WGPUQueueWorkDoneCallback](c.html#function-pointer-QueueWorkDoneCallback) callback, void \* userdata)

</div>

#### Arguments

* *queue*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQueueReference([WGPUQueue](c.html#class-Queue) queue)

</div>

#### Arguments

* *queue*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQueueRelease([WGPUQueue](c.html#class-Queue) queue)

</div>

#### Arguments

* *queue*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQueueSetLabel([WGPUQueue](c.html#class-Queue) queue, char const\* label)

</div>

#### Arguments

* *queue*: 
* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQueueSubmit([WGPUQueue](c.html#class-Queue) queue, uint32_t commandCount, [WGPUCommandBuffer](c.html#class-CommandBuffer) const\* commands)

</div>

#### Arguments

* *queue*: 
* *commandCount*: 
* *commands*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuQueueWriteBuffer([WGPUQueue](c.html#class-Queue) queue, [WGPUBuffer](c.html#class-Buffer) buffer, uint64_t bufferOffset, void const\* data, size_t size)

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

void wgpuQueueWriteTexture([WGPUQueue](c.html#class-Queue) queue, [WGPUImageCopyTexture](c.html#structure-ImageCopyTexture) const\* destination, void const\* data, size_t dataSize, [WGPUTextureDataLayout](c.html#structure-TextureDataLayout) const\* dataLayout, [WGPUExtent3D](c.html#structure-Extent3D) const\* writeSize)

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

void wgpuRenderBundleReference([WGPURenderBundle](c.html#class-RenderBundle) renderBundle)

</div>

#### Arguments

* *renderBundle*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleRelease([WGPURenderBundle](c.html#class-RenderBundle) renderBundle)

</div>

#### Arguments

* *renderBundle*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPURenderBundleEncoder {#class-RenderBundleEncoder}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderDraw([WGPURenderBundleEncoder](c.html#class-RenderBundleEncoder) renderBundleEncoder, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)

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

void wgpuRenderBundleEncoderDrawIndexed([WGPURenderBundleEncoder](c.html#class-RenderBundleEncoder) renderBundleEncoder, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance)

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

void wgpuRenderBundleEncoderDrawIndexedIndirect([WGPURenderBundleEncoder](c.html#class-RenderBundleEncoder) renderBundleEncoder, [WGPUBuffer](c.html#class-Buffer) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderDrawIndirect([WGPURenderBundleEncoder](c.html#class-RenderBundleEncoder) renderBundleEncoder, [WGPUBuffer](c.html#class-Buffer) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPURenderBundle](c.html#class-RenderBundle) wgpuRenderBundleEncoderFinish([WGPURenderBundleEncoder](c.html#class-RenderBundleEncoder) renderBundleEncoder, [WGPURenderBundleDescriptor](c.html#structure-RenderBundleDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *renderBundleEncoder*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderInsertDebugMarker([WGPURenderBundleEncoder](c.html#class-RenderBundleEncoder) renderBundleEncoder, char const\* markerLabel)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *markerLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderPopDebugGroup([WGPURenderBundleEncoder](c.html#class-RenderBundleEncoder) renderBundleEncoder)

</div>

#### Arguments

* *renderBundleEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderPushDebugGroup([WGPURenderBundleEncoder](c.html#class-RenderBundleEncoder) renderBundleEncoder, char const\* groupLabel)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *groupLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderReference([WGPURenderBundleEncoder](c.html#class-RenderBundleEncoder) renderBundleEncoder)

</div>

#### Arguments

* *renderBundleEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderRelease([WGPURenderBundleEncoder](c.html#class-RenderBundleEncoder) renderBundleEncoder)

</div>

#### Arguments

* *renderBundleEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderSetBindGroup([WGPURenderBundleEncoder](c.html#class-RenderBundleEncoder) renderBundleEncoder, uint32_t groupIndex, [WGPUBindGroup](c.html#class-BindGroup) group, uint32_t dynamicOffsetCount, uint32_t const\* dynamicOffsets)

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

void wgpuRenderBundleEncoderSetIndexBuffer([WGPURenderBundleEncoder](c.html#class-RenderBundleEncoder) renderBundleEncoder, [WGPUBuffer](c.html#class-Buffer) buffer, [WGPUIndexFormat](c.html#enum-IndexFormat) format, uint64_t offset, uint64_t size)

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

void wgpuRenderBundleEncoderSetLabel([WGPURenderBundleEncoder](c.html#class-RenderBundleEncoder) renderBundleEncoder, char const\* label)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderSetPipeline([WGPURenderBundleEncoder](c.html#class-RenderBundleEncoder) renderBundleEncoder, [WGPURenderPipeline](c.html#class-RenderPipeline) pipeline)

</div>

#### Arguments

* *renderBundleEncoder*: 
* *pipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderBundleEncoderSetVertexBuffer([WGPURenderBundleEncoder](c.html#class-RenderBundleEncoder) renderBundleEncoder, uint32_t slot, [WGPUBuffer](c.html#class-Buffer) buffer, uint64_t offset, uint64_t size)

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

void wgpuRenderPassEncoderBeginOcclusionQuery([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, uint32_t queryIndex)

</div>

#### Arguments

* *renderPassEncoder*: 
* *queryIndex*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderBeginPipelineStatisticsQuery([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, [WGPUQuerySet](c.html#class-QuerySet) querySet, uint32_t queryIndex)

</div>

#### Arguments

* *renderPassEncoder*: 
* *querySet*: 
* *queryIndex*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderDraw([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)

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

void wgpuRenderPassEncoderDrawIndexed([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance)

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

void wgpuRenderPassEncoderDrawIndexedIndirect([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, [WGPUBuffer](c.html#class-Buffer) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *renderPassEncoder*: 
* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderDrawIndirect([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, [WGPUBuffer](c.html#class-Buffer) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *renderPassEncoder*: 
* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderEnd([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder)

</div>

#### Arguments

* *renderPassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderEndOcclusionQuery([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder)

</div>

#### Arguments

* *renderPassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderEndPass([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder)

</div>

#### Arguments

* *renderPassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderEndPipelineStatisticsQuery([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder)

</div>

#### Arguments

* *renderPassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderExecuteBundles([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, uint32_t bundlesCount, [WGPURenderBundle](c.html#class-RenderBundle) const\* bundles)

</div>

#### Arguments

* *renderPassEncoder*: 
* *bundlesCount*: 
* *bundles*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderInsertDebugMarker([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, char const\* markerLabel)

</div>

#### Arguments

* *renderPassEncoder*: 
* *markerLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderPopDebugGroup([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder)

</div>

#### Arguments

* *renderPassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderPushDebugGroup([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, char const\* groupLabel)

</div>

#### Arguments

* *renderPassEncoder*: 
* *groupLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderReference([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder)

</div>

#### Arguments

* *renderPassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderRelease([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder)

</div>

#### Arguments

* *renderPassEncoder*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderSetBindGroup([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, uint32_t groupIndex, [WGPUBindGroup](c.html#class-BindGroup) group, uint32_t dynamicOffsetCount, uint32_t const\* dynamicOffsets)

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

void wgpuRenderPassEncoderSetBlendConstant([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, [WGPUColor](c.html#structure-Color) const\* color)

</div>

#### Arguments

* *renderPassEncoder*: 
* *color*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderSetIndexBuffer([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, [WGPUBuffer](c.html#class-Buffer) buffer, [WGPUIndexFormat](c.html#enum-IndexFormat) format, uint64_t offset, uint64_t size)

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

void wgpuRenderPassEncoderSetLabel([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, char const\* label)

</div>

#### Arguments

* *renderPassEncoder*: 
* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderSetPipeline([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, [WGPURenderPipeline](c.html#class-RenderPipeline) pipeline)

</div>

#### Arguments

* *renderPassEncoder*: 
* *pipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderSetScissorRect([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, uint32_t x, uint32_t y, uint32_t width, uint32_t height)

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

void wgpuRenderPassEncoderSetStencilReference([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, uint32_t reference)

</div>

#### Arguments

* *renderPassEncoder*: 
* *reference*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPassEncoderSetVertexBuffer([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, uint32_t slot, [WGPUBuffer](c.html#class-Buffer) buffer, uint64_t offset, uint64_t size)

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

void wgpuRenderPassEncoderSetViewport([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, float x, float y, float width, float height, float minDepth, float maxDepth)

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

void wgpuRenderPassEncoderWriteTimestamp([WGPURenderPassEncoder](c.html#class-RenderPassEncoder) renderPassEncoder, [WGPUQuerySet](c.html#class-QuerySet) querySet, uint32_t queryIndex)

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

[WGPUBindGroupLayout](c.html#class-BindGroupLayout) wgpuRenderPipelineGetBindGroupLayout([WGPURenderPipeline](c.html#class-RenderPipeline) renderPipeline, uint32_t groupIndex)

</div>

#### Returns


#### Arguments

* *renderPipeline*: 
* *groupIndex*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPipelineReference([WGPURenderPipeline](c.html#class-RenderPipeline) renderPipeline)

</div>

#### Arguments

* *renderPipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPipelineRelease([WGPURenderPipeline](c.html#class-RenderPipeline) renderPipeline)

</div>

#### Arguments

* *renderPipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuRenderPipelineSetLabel([WGPURenderPipeline](c.html#class-RenderPipeline) renderPipeline, char const\* label)

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

void wgpuSamplerReference([WGPUSampler](c.html#class-Sampler) sampler)

</div>

#### Arguments

* *sampler*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSamplerRelease([WGPUSampler](c.html#class-Sampler) sampler)

</div>

#### Arguments

* *sampler*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSamplerSetLabel([WGPUSampler](c.html#class-Sampler) sampler, char const\* label)

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

void wgpuShaderModuleGetCompilationInfo([WGPUShaderModule](c.html#class-ShaderModule) shaderModule, [WGPUCompilationInfoCallback](c.html#function-pointer-CompilationInfoCallback) callback, void \* userdata)

</div>

#### Arguments

* *shaderModule*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuShaderModuleReference([WGPUShaderModule](c.html#class-ShaderModule) shaderModule)

</div>

#### Arguments

* *shaderModule*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuShaderModuleRelease([WGPUShaderModule](c.html#class-ShaderModule) shaderModule)

</div>

#### Arguments

* *shaderModule*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuShaderModuleSetLabel([WGPUShaderModule](c.html#class-ShaderModule) shaderModule, char const\* label)

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

[WGPUTextureFormat](c.html#enum-TextureFormat) wgpuSurfaceGetPreferredFormat([WGPUSurface](c.html#class-Surface) surface, [WGPUAdapter](c.html#class-Adapter) adapter)

</div>

#### Returns


#### Arguments

* *surface*: 
* *adapter*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSurfaceReference([WGPUSurface](c.html#class-Surface) surface)

</div>

#### Arguments

* *surface*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSurfaceRelease([WGPUSurface](c.html#class-Surface) surface)

</div>

#### Arguments

* *surface*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUSwapChain {#class-SwapChain}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSwapChainConfigure([WGPUSwapChain](c.html#class-SwapChain) swapChain, [WGPUTextureFormat](c.html#enum-TextureFormat) format, [WGPUTextureUsage](c.html#bitmask-TextureUsage) allowedUsage, uint32_t width, uint32_t height)

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

[WGPUTextureView](c.html#class-TextureView) wgpuSwapChainGetCurrentTextureView([WGPUSwapChain](c.html#class-SwapChain) swapChain)

</div>

#### Returns


#### Arguments

* *swapChain*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSwapChainPresent([WGPUSwapChain](c.html#class-SwapChain) swapChain)

</div>

#### Arguments

* *swapChain*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSwapChainReference([WGPUSwapChain](c.html#class-SwapChain) swapChain)

</div>

#### Arguments

* *swapChain*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuSwapChainRelease([WGPUSwapChain](c.html#class-SwapChain) swapChain)

</div>

#### Arguments

* *swapChain*: 

</div>

</div>

<div class='object' markdown=1>

### Methods of WGPUTexture {#class-Texture}

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUTextureView](c.html#class-TextureView) wgpuTextureCreateView([WGPUTexture](c.html#class-Texture) texture, [WGPUTextureViewDescriptor](c.html#structure-TextureViewDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *texture*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuTextureDestroy([WGPUTexture](c.html#class-Texture) texture)

</div>

#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t wgpuTextureGetDepthOrArrayLayers([WGPUTexture](c.html#class-Texture) texture)

</div>

#### Returns


#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUTextureDimension](c.html#enum-TextureDimension) wgpuTextureGetDimension([WGPUTexture](c.html#class-Texture) texture)

</div>

#### Returns


#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUTextureFormat](c.html#enum-TextureFormat) wgpuTextureGetFormat([WGPUTexture](c.html#class-Texture) texture)

</div>

#### Returns


#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t wgpuTextureGetHeight([WGPUTexture](c.html#class-Texture) texture)

</div>

#### Returns


#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t wgpuTextureGetMipLevelCount([WGPUTexture](c.html#class-Texture) texture)

</div>

#### Returns


#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t wgpuTextureGetSampleCount([WGPUTexture](c.html#class-Texture) texture)

</div>

#### Returns


#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[WGPUTextureUsage](c.html#bitmask-TextureUsage) wgpuTextureGetUsage([WGPUTexture](c.html#class-Texture) texture)

</div>

#### Returns


#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t wgpuTextureGetWidth([WGPUTexture](c.html#class-Texture) texture)

</div>

#### Returns


#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuTextureReference([WGPUTexture](c.html#class-Texture) texture)

</div>

#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuTextureRelease([WGPUTexture](c.html#class-Texture) texture)

</div>

#### Arguments

* *texture*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuTextureSetLabel([WGPUTexture](c.html#class-Texture) texture, char const\* label)

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

void wgpuTextureViewReference([WGPUTextureView](c.html#class-TextureView) textureView)

</div>

#### Arguments

* *textureView*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuTextureViewRelease([WGPUTextureView](c.html#class-TextureView) textureView)

</div>

#### Arguments

* *textureView*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void wgpuTextureViewSetLabel([WGPUTextureView](c.html#class-TextureView) textureView, char const\* label)

</div>

#### Arguments

* *textureView*: 
* *label*: 

</div>

</div>

