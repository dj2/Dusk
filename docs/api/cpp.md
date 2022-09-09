---
layout: page
title: C++ API
parent: API Documentation
---

# C++ API Documentation
## Constants

| Value | Description |
|:------|:------------|
| `kArrayLayerCountUndefined` | Undefined value for array layer count. Providing undefined will cause a default value to be used. |
| `kCopyStrideUndefined` | Undefined value for copy stride. Providing undefined will cause a default value to be used. |
| `kLimitU32Undefined` | Undefined U32 limit value. Providing undefined will cause a default value to be used. |
| `kLimitU64Undefined` | Undefined U64 limit value. Providing undefined will cause a default value to be used. |
| `kMipLevelCountUndefined` | Undefined mip level count. Providing undefined will cause a default value to be used. |
| `kStrideUndefined` | Undefined stride. Providing undefined will cause a default value to be used. |
| `kWholeMapSize` | Value representing size of entire map. Providing undefined will cause a default value to be used. |
| `kWholeSize` | Value representing the whole size value. Providing undefined will cause a default value to be used. |

## Enums

### enum class AdapterType {#enum-AdapterType}

Provides information on the type of adapter.


| Value | Description |
|:------|:------------|
| `DiscreteGPU` | A separate discrete GPU adapter |
| `IntegratedGPU` | An integrated GPU / CPU adapter |
| `CPU` | A CPU adapter |
| `Unknown` | A unknown adapter type |

### enum class AddressMode {#enum-AddressMode}

Describes the behaviour of the sampler if the sampler footprint extends beyond the bounds of the sampled texture.

See [GPUAddressMode](https://webgpu.dev/#enumdef-gpuaddressmode) for more information.


| Value | Description |
|:------|:------------|
| `Repeat` | Texture coordinates wrap to the other side of the texture |
| `MirrorRepeat` | Texture coordinates wrap to the other side of the texture, but the texture is flipped when the integer part of the coordinate is odd. |
| `ClampToEdge` | Texture coordinates are clamped between 0.0 and 1.0, inclusive. |

### enum class AlphaMode {#enum-AlphaMode}

Selects how the contents of the surface will be interpreted when read, when rendered to the screen or used as an image source.

See [GPUCanvasAlphaMode](https://webgpu.dev/#GPUCanvasAlphaMode) for more information.


| Value | Description |
|:------|:------------|
| `Premultiplied` | Read RBGA as premultipled: color values are premultipled by their alpha value. |
| `Unpremultiplied` | Read RGBA as not premulitipled: Color values are not premultipled by their alpha value |
| `Opaque` | Read RGB as opaque and ignore alpha value |

### enum class BackendType {#enum-BackendType}

Specifies the type of backend to use with Dawn.


| Value | Description |
|:------|:------------|
| `Null` | A null backend |
| `WebGPU` | The WebGPU backend |
| `D3D11` | The D3D11 backend |
| `D3D12` | The D3D12 backend |
| `Metal` | The Metal backend |
| `Vulkan` | The Vulkan backend |
| `OpenGL` | The OpenGL backend |
| `OpenGLES` | The OpenGL ES backend |

### enum class BlendFactor {#enum-BlendFactor}


| Value | Description |
|:------|:------------|
| `Zero` |  |
| `One` |  |
| `Src` |  |
| `OneMinusSrc` |  |
| `SrcAlpha` |  |
| `OneMinusSrcAlpha` |  |
| `Dst` |  |
| `OneMinusDst` |  |
| `DstAlpha` |  |
| `OneMinusDstAlpha` |  |
| `SrcAlphaSaturated` |  |
| `Constant` |  |
| `OneMinusConstant` |  |

### enum class BlendOperation {#enum-BlendOperation}


| Value | Description |
|:------|:------------|
| `Add` |  |
| `Subtract` |  |
| `ReverseSubtract` |  |
| `Min` |  |
| `Max` |  |

### enum class BufferBindingType {#enum-BufferBindingType}


| Value | Description |
|:------|:------------|
| `Undefined` |  |
| `Uniform` |  |
| `Storage` |  |
| `ReadOnlyStorage` |  |

### enum class BufferMapAsyncStatus {#enum-BufferMapAsyncStatus}


| Value | Description |
|:------|:------------|
| `Success` |  |
| `Error` |  |
| `Unknown` |  |
| `DeviceLost` |  |
| `DestroyedBeforeCallback` |  |
| `UnmappedBeforeCallback` |  |

### enum class CompareFunction {#enum-CompareFunction}


| Value | Description |
|:------|:------------|
| `Undefined` |  |
| `Never` |  |
| `Less` |  |
| `LessEqual` |  |
| `Greater` |  |
| `GreaterEqual` |  |
| `Equal` |  |
| `NotEqual` |  |
| `Always` |  |

### enum class CompilationInfoRequestStatus {#enum-CompilationInfoRequestStatus}


| Value | Description |
|:------|:------------|
| `Success` |  |
| `Error` |  |
| `DeviceLost` |  |
| `Unknown` |  |

### enum class CompilationMessageType {#enum-CompilationMessageType}


| Value | Description |
|:------|:------------|
| `Error` |  |
| `Warning` |  |
| `Info` |  |

### enum class ComputePassTimestampLocation {#enum-ComputePassTimestampLocation}


| Value | Description |
|:------|:------------|
| `Beginning` |  |
| `End` |  |

### enum class CreatePipelineAsyncStatus {#enum-CreatePipelineAsyncStatus}


| Value | Description |
|:------|:------------|
| `Success` |  |
| `Error` |  |
| `DeviceLost` |  |
| `DeviceDestroyed` |  |
| `Unknown` |  |

### enum class CullMode {#enum-CullMode}


| Value | Description |
|:------|:------------|
| `None` |  |
| `Front` |  |
| `Back` |  |

### enum class DeviceLostReason {#enum-DeviceLostReason}


| Value | Description |
|:------|:------------|
| `Undefined` |  |
| `Destroyed` |  |

### enum class ErrorFilter {#enum-ErrorFilter}


| Value | Description |
|:------|:------------|
| `Validation` |  |
| `OutOfMemory` |  |

### enum class ErrorType {#enum-ErrorType}


| Value | Description |
|:------|:------------|
| `NoError` |  |
| `Validation` |  |
| `OutOfMemory` |  |
| `Unknown` |  |
| `DeviceLost` |  |

### enum class FeatureName {#enum-FeatureName}


| Value | Description |
|:------|:------------|
| `Undefined` |  |
| `DepthClipControl` |  |
| `Depth32FloatStencil8` |  |
| `TimestampQuery` |  |
| `PipelineStatisticsQuery` |  |
| `TextureCompressionBC` |  |
| `TextureCompressionETC2` |  |
| `TextureCompressionASTC` |  |
| `IndirectFirstInstance` |  |
| `DawnShaderFloat16` |  |
| `DawnInternalUsages` |  |
| `DawnMultiPlanarFormats` |  |
| `DawnNative` |  |
| `ChromiumExperimentalDp4a` |  |

### enum class FilterMode {#enum-FilterMode}


| Value | Description |
|:------|:------------|
| `Nearest` |  |
| `Linear` |  |

### enum class FrontFace {#enum-FrontFace}


| Value | Description |
|:------|:------------|
| `CCW` |  |
| `CW` |  |

### enum class IndexFormat {#enum-IndexFormat}


| Value | Description |
|:------|:------------|
| `Undefined` |  |
| `Uint16` |  |
| `Uint32` |  |

### enum class LoadOp {#enum-LoadOp}


| Value | Description |
|:------|:------------|
| `Undefined` |  |
| `Clear` |  |
| `Load` |  |

### enum class LoggingType {#enum-LoggingType}


| Value | Description |
|:------|:------------|
| `Verbose` |  |
| `Info` |  |
| `Warning` |  |
| `Error` |  |

### enum class MipmapFilterMode {#enum-MipmapFilterMode}


| Value | Description |
|:------|:------------|
| `Nearest` |  |
| `Linear` |  |

### enum class PipelineStatisticName {#enum-PipelineStatisticName}


| Value | Description |
|:------|:------------|
| `VertexShaderInvocations` |  |
| `ClipperInvocations` |  |
| `ClipperPrimitivesOut` |  |
| `FragmentShaderInvocations` |  |
| `ComputeShaderInvocations` |  |

### enum class PowerPreference {#enum-PowerPreference}


| Value | Description |
|:------|:------------|
| `Undefined` |  |
| `LowPower` |  |
| `HighPerformance` |  |

### enum class PresentMode {#enum-PresentMode}


| Value | Description |
|:------|:------------|
| `Immediate` |  |
| `Mailbox` |  |
| `Fifo` |  |

### enum class PrimitiveTopology {#enum-PrimitiveTopology}


| Value | Description |
|:------|:------------|
| `PointList` |  |
| `LineList` |  |
| `LineStrip` |  |
| `TriangleList` |  |
| `TriangleStrip` |  |

### enum class QueryType {#enum-QueryType}


| Value | Description |
|:------|:------------|
| `Occlusion` |  |
| `PipelineStatistics` |  |
| `Timestamp` |  |

### enum class QueueWorkDoneStatus {#enum-QueueWorkDoneStatus}


| Value | Description |
|:------|:------------|
| `Success` |  |
| `Error` |  |
| `Unknown` |  |
| `DeviceLost` |  |

### enum class RenderPassTimestampLocation {#enum-RenderPassTimestampLocation}


| Value | Description |
|:------|:------------|
| `Beginning` |  |
| `End` |  |

### enum class RequestAdapterStatus {#enum-RequestAdapterStatus}


| Value | Description |
|:------|:------------|
| `Success` |  |
| `Unavailable` |  |
| `Error` |  |
| `Unknown` |  |

### enum class RequestDeviceStatus {#enum-RequestDeviceStatus}


| Value | Description |
|:------|:------------|
| `Success` |  |
| `Error` |  |
| `Unknown` |  |

### enum class SType {#enum-SType}


| Value | Description |
|:------|:------------|
| `Invalid` |  |
| `SurfaceDescriptorFromMetalLayer` |  |
| `SurfaceDescriptorFromWindowsHWND` |  |
| `SurfaceDescriptorFromXlibWindow` |  |
| `SurfaceDescriptorFromCanvasHTMLSelector` |  |
| `ShaderModuleSPIRVDescriptor` |  |
| `ShaderModuleWGSLDescriptor` |  |
| `PrimitiveDepthClipControl` |  |
| `SurfaceDescriptorFromWaylandSurface` |  |
| `SurfaceDescriptorFromAndroidNativeWindow` |  |
| `SurfaceDescriptorFromXcbWindow` |  |
| `SurfaceDescriptorFromWindowsCoreWindow` |  |
| `ExternalTextureBindingEntry` |  |
| `ExternalTextureBindingLayout` |  |
| `SurfaceDescriptorFromWindowsSwapChainPanel` |  |
| `RenderPassDescriptorMaxDrawCount` |  |
| `DawnTextureInternalUsageDescriptor` |  |
| `DawnTogglesDeviceDescriptor` |  |
| `DawnEncoderInternalUsageDescriptor` |  |
| `DawnInstanceDescriptor` |  |
| `DawnCacheDeviceDescriptor` |  |

### enum class SamplerBindingType {#enum-SamplerBindingType}


| Value | Description |
|:------|:------------|
| `Undefined` |  |
| `Filtering` |  |
| `NonFiltering` |  |
| `Comparison` |  |

### enum class StencilOperation {#enum-StencilOperation}


| Value | Description |
|:------|:------------|
| `Keep` |  |
| `Zero` |  |
| `Replace` |  |
| `Invert` |  |
| `IncrementClamp` |  |
| `DecrementClamp` |  |
| `IncrementWrap` |  |
| `DecrementWrap` |  |

### enum class StorageTextureAccess {#enum-StorageTextureAccess}


| Value | Description |
|:------|:------------|
| `Undefined` |  |
| `WriteOnly` |  |

### enum class StoreOp {#enum-StoreOp}


| Value | Description |
|:------|:------------|
| `Undefined` |  |
| `Store` |  |
| `Discard` |  |

### enum class TextureAspect {#enum-TextureAspect}


| Value | Description |
|:------|:------------|
| `All` |  |
| `StencilOnly` |  |
| `DepthOnly` |  |
| `Plane0Only` |  |
| `Plane1Only` |  |

### enum class TextureComponentType {#enum-TextureComponentType}


| Value | Description |
|:------|:------------|
| `Float` |  |
| `Sint` |  |
| `Uint` |  |
| `DepthComparison` |  |

### enum class TextureDimension {#enum-TextureDimension}


| Value | Description |
|:------|:------------|
| `1D` |  |
| `2D` |  |
| `3D` |  |

### enum class TextureFormat {#enum-TextureFormat}


| Value | Description |
|:------|:------------|
| `Undefined` |  |
| `R8Unorm` |  |
| `R8Snorm` |  |
| `R8Uint` |  |
| `R8Sint` |  |
| `R16Uint` |  |
| `R16Sint` |  |
| `R16Float` |  |
| `RG8Unorm` |  |
| `RG8Snorm` |  |
| `RG8Uint` |  |
| `RG8Sint` |  |
| `R32Float` |  |
| `R32Uint` |  |
| `R32Sint` |  |
| `RG16Uint` |  |
| `RG16Sint` |  |
| `RG16Float` |  |
| `RGBA8Unorm` |  |
| `RGBA8UnormSrgb` |  |
| `RGBA8Snorm` |  |
| `RGBA8Uint` |  |
| `RGBA8Sint` |  |
| `BGRA8Unorm` |  |
| `BGRA8UnormSrgb` |  |
| `RGB10A2Unorm` |  |
| `RG11B10Ufloat` |  |
| `RGB9E5Ufloat` |  |
| `RG32Float` |  |
| `RG32Uint` |  |
| `RG32Sint` |  |
| `RGBA16Uint` |  |
| `RGBA16Sint` |  |
| `RGBA16Float` |  |
| `RGBA32Float` |  |
| `RGBA32Uint` |  |
| `RGBA32Sint` |  |
| `Stencil8` |  |
| `Depth16Unorm` |  |
| `Depth24Plus` |  |
| `Depth24PlusStencil8` |  |
| `Depth32Float` |  |
| `Depth32FloatStencil8` |  |
| `BC1RGBAUnorm` |  |
| `BC1RGBAUnormSrgb` |  |
| `BC2RGBAUnorm` |  |
| `BC2RGBAUnormSrgb` |  |
| `BC3RGBAUnorm` |  |
| `BC3RGBAUnormSrgb` |  |
| `BC4RUnorm` |  |
| `BC4RSnorm` |  |
| `BC5RGUnorm` |  |
| `BC5RGSnorm` |  |
| `BC6HRGBUfloat` |  |
| `BC6HRGBFloat` |  |
| `BC7RGBAUnorm` |  |
| `BC7RGBAUnormSrgb` |  |
| `ETC2RGB8Unorm` |  |
| `ETC2RGB8UnormSrgb` |  |
| `ETC2RGB8A1Unorm` |  |
| `ETC2RGB8A1UnormSrgb` |  |
| `ETC2RGBA8Unorm` |  |
| `ETC2RGBA8UnormSrgb` |  |
| `EACR11Unorm` |  |
| `EACR11Snorm` |  |
| `EACRG11Unorm` |  |
| `EACRG11Snorm` |  |
| `ASTC4x4Unorm` |  |
| `ASTC4x4UnormSrgb` |  |
| `ASTC5x4Unorm` |  |
| `ASTC5x4UnormSrgb` |  |
| `ASTC5x5Unorm` |  |
| `ASTC5x5UnormSrgb` |  |
| `ASTC6x5Unorm` |  |
| `ASTC6x5UnormSrgb` |  |
| `ASTC6x6Unorm` |  |
| `ASTC6x6UnormSrgb` |  |
| `ASTC8x5Unorm` |  |
| `ASTC8x5UnormSrgb` |  |
| `ASTC8x6Unorm` |  |
| `ASTC8x6UnormSrgb` |  |
| `ASTC8x8Unorm` |  |
| `ASTC8x8UnormSrgb` |  |
| `ASTC10x5Unorm` |  |
| `ASTC10x5UnormSrgb` |  |
| `ASTC10x6Unorm` |  |
| `ASTC10x6UnormSrgb` |  |
| `ASTC10x8Unorm` |  |
| `ASTC10x8UnormSrgb` |  |
| `ASTC10x10Unorm` |  |
| `ASTC10x10UnormSrgb` |  |
| `ASTC12x10Unorm` |  |
| `ASTC12x10UnormSrgb` |  |
| `ASTC12x12Unorm` |  |
| `ASTC12x12UnormSrgb` |  |
| `R8BG8Biplanar420Unorm` |  |

### enum class TextureSampleType {#enum-TextureSampleType}


| Value | Description |
|:------|:------------|
| `Undefined` |  |
| `Float` |  |
| `UnfilterableFloat` |  |
| `Depth` |  |
| `Sint` |  |
| `Uint` |  |

### enum class TextureViewDimension {#enum-TextureViewDimension}


| Value | Description |
|:------|:------------|
| `Undefined` |  |
| `1D` |  |
| `2D` |  |
| `2DArray` |  |
| `Cube` |  |
| `CubeArray` |  |
| `3D` |  |

### enum class VertexFormat {#enum-VertexFormat}


| Value | Description |
|:------|:------------|
| `Undefined` |  |
| `Uint8x2` |  |
| `Uint8x4` |  |
| `Sint8x2` |  |
| `Sint8x4` |  |
| `Unorm8x2` |  |
| `Unorm8x4` |  |
| `Snorm8x2` |  |
| `Snorm8x4` |  |
| `Uint16x2` |  |
| `Uint16x4` |  |
| `Sint16x2` |  |
| `Sint16x4` |  |
| `Unorm16x2` |  |
| `Unorm16x4` |  |
| `Snorm16x2` |  |
| `Snorm16x4` |  |
| `Float16x2` |  |
| `Float16x4` |  |
| `Float32` |  |
| `Float32x2` |  |
| `Float32x3` |  |
| `Float32x4` |  |
| `Uint32` |  |
| `Uint32x2` |  |
| `Uint32x3` |  |
| `Uint32x4` |  |
| `Sint32` |  |
| `Sint32x2` |  |
| `Sint32x3` |  |
| `Sint32x4` |  |

### enum class VertexStepMode {#enum-VertexStepMode}


| Value | Description |
|:------|:------------|
| `Vertex` |  |
| `Instance` |  |
| `VertexBufferNotUsed` |  |

## Bitmasks

The Dawn WebGPU bitmasks, while `enum class`s support the various bitwise
operators in order to use them as bitmasks.
### enum class BufferUsage [bitmask] {#bitmask-BufferUsage}


| Value | Description |
|:------|:------------|
| `None` |  |
| `MapRead` |  |
| `MapWrite` |  |
| `CopySrc` |  |
| `CopyDst` |  |
| `Index` |  |
| `Vertex` |  |
| `Uniform` |  |
| `Storage` |  |
| `Indirect` |  |
| `QueryResolve` |  |

### enum class ColorWriteMask [bitmask] {#bitmask-ColorWriteMask}


| Value | Description |
|:------|:------------|
| `None` |  |
| `Red` |  |
| `Green` |  |
| `Blue` |  |
| `Alpha` |  |
| `All` |  |

### enum class MapMode [bitmask] {#bitmask-MapMode}


| Value | Description |
|:------|:------------|
| `None` |  |
| `Read` |  |
| `Write` |  |

### enum class ShaderStage [bitmask] {#bitmask-ShaderStage}


| Value | Description |
|:------|:------------|
| `None` |  |
| `Vertex` |  |
| `Fragment` |  |
| `Compute` |  |

### enum class TextureUsage [bitmask] {#bitmask-TextureUsage}

Determine how a GPUTexture maybe be used after creation.

See [GPUTextureUsage](https://webgpu.dev/#namespacedef-gputextureusage) for more information.


| Value | Description |
|:------|:------------|
| `None` | No usage specified. |
| `CopySrc` | The texture can be used as the source of a copy operation. |
| `CopyDst` | The texture can be used as the destination of a copy operation. |
| `TextureBinding` | The texture can be bound for use as a sampled texture in a shader. |
| `StorageBinding` | The texture can be bound for use as a storage texture in a shader. |
| `RenderAttachment` | The texture can be used as a colour or depth/stencil attachment in a render pass. |
| `Present` | The texture can be used to "present" the texture on screen. |

## Functions

<div class='function' markdown=1>

### CreateInstance {#function-CreateInstance}

<div class='content' markdown=1>

Creates an instance of the Dawn WebGPU system

<div class='signature' markdown=1>

[Instance]({{ '/api/cpp.html#class-Instance' | relative_url }}) CreateInstance([InstanceDescriptor]({{ '/api/cpp.html#structure-InstanceDescriptor' | relative_url }}) const\* descriptor)
</div>

#### Returns

The created [Instance]({{ '/api/cpp.html#class-Instance' | relative_url }}).

#### Arguments

* *descriptor*: The [InstanceDescriptor]({{ '/api/cpp.html#structure-InstanceDescriptor' | relative_url }}) pointer. Maybe `nullptr` to create a default instance.

</div>

</div>

<div class='function' markdown=1>

### GetProcAddress {#function-GetProcAddress}

<div class='content' markdown=1>

Returns the function pointer for the requested WebGPU API method *procName*.

<div class='signature' markdown=1>

[Proc]({{ '/api/cpp.html#function-pointer-Proc' | relative_url }}) GetProcAddress([Device]({{ '/api/cpp.html#class-Device' | relative_url }}) device, char const\* procName)
</div>

#### Returns

The [Proc]({{ '/api/cpp.html#function-pointer-Proc' | relative_url }}) function pointer if it exists, nullptr otherwise.

#### Arguments

* *device*: The [Device]({{ '/api/cpp.html#class-Device' | relative_url }}) to retrieve the proc for
* *procName*: The name of the pointer to retrieve

</div>

</div>

## Function Pointers

<div class='function' markdown=1>

### BufferMapCallback {#function-pointer-BufferMapCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;BufferMapCallback)([WGPUBufferMapAsyncStatus]({{ '/api/c.html#enum-BufferMapAsyncStatus' | relative_url }}) status, void \* userdata)
</div>

#### Arguments

* *status*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### CompilationInfoCallback {#function-pointer-CompilationInfoCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;CompilationInfoCallback)([WGPUCompilationInfoRequestStatus]({{ '/api/c.html#enum-CompilationInfoRequestStatus' | relative_url }}) status, [WGPUCompilationInfo]({{ '/api/c.html#structure-CompilationInfo' | relative_url }}) const\* compilationInfo, void \* userdata)
</div>

#### Arguments

* *status*: 
* *compilationInfo*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### CreateComputePipelineAsyncCallback {#function-pointer-CreateComputePipelineAsyncCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;CreateComputePipelineAsyncCallback)([WGPUCreatePipelineAsyncStatus]({{ '/api/c.html#enum-CreatePipelineAsyncStatus' | relative_url }}) status, [WGPUComputePipeline]({{ '/api/c.html#class-ComputePipeline' | relative_url }}) pipeline, char const\* message, void \* userdata)
</div>

#### Arguments

* *status*: 
* *pipeline*: 
* *message*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### CreateRenderPipelineAsyncCallback {#function-pointer-CreateRenderPipelineAsyncCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;CreateRenderPipelineAsyncCallback)([WGPUCreatePipelineAsyncStatus]({{ '/api/c.html#enum-CreatePipelineAsyncStatus' | relative_url }}) status, [WGPURenderPipeline]({{ '/api/c.html#class-RenderPipeline' | relative_url }}) pipeline, char const\* message, void \* userdata)
</div>

#### Arguments

* *status*: 
* *pipeline*: 
* *message*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### DeviceLostCallback {#function-pointer-DeviceLostCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;DeviceLostCallback)([WGPUDeviceLostReason]({{ '/api/c.html#enum-DeviceLostReason' | relative_url }}) reason, char const\* message, void \* userdata)
</div>

#### Arguments

* *reason*: 
* *message*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### ErrorCallback {#function-pointer-ErrorCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;ErrorCallback)([WGPUErrorType]({{ '/api/c.html#enum-ErrorType' | relative_url }}) type, char const\* message, void \* userdata)
</div>

#### Arguments

* *type*: 
* *message*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### LoggingCallback {#function-pointer-LoggingCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;LoggingCallback)([WGPULoggingType]({{ '/api/c.html#enum-LoggingType' | relative_url }}) type, char const\* message, void \* userdata)
</div>

#### Arguments

* *type*: 
* *message*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### Proc {#function-pointer-Proc}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;Proc)()
</div>

</div>

</div>

<div class='function' markdown=1>

### QueueWorkDoneCallback {#function-pointer-QueueWorkDoneCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;QueueWorkDoneCallback)([WGPUQueueWorkDoneStatus]({{ '/api/c.html#enum-QueueWorkDoneStatus' | relative_url }}) status, void \* userdata)
</div>

#### Arguments

* *status*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### RequestAdapterCallback {#function-pointer-RequestAdapterCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;RequestAdapterCallback)([WGPURequestAdapterStatus]({{ '/api/c.html#enum-RequestAdapterStatus' | relative_url }}) status, [WGPUAdapter]({{ '/api/c.html#class-Adapter' | relative_url }}) adapter, char const\* message, void \* userdata)
</div>

#### Arguments

* *status*: 
* *adapter*: 
* *message*: 
* *userdata*: 

</div>

</div>

<div class='function' markdown=1>

### RequestDeviceCallback {#function-pointer-RequestDeviceCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;RequestDeviceCallback)([WGPURequestDeviceStatus]({{ '/api/c.html#enum-RequestDeviceStatus' | relative_url }}) status, [WGPUDevice]({{ '/api/c.html#class-Device' | relative_url }}) device, char const\* message, void \* userdata)
</div>

#### Arguments

* *status*: 
* *device*: 
* *message*: 
* *userdata*: 

</div>

</div>

## Structures

### struct AdapterProperties {#structure-AdapterProperties}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStructOut const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| uint32_t vendorID |  | The PCIe ID if available but can be other values on systems which do not provide a PCIe ID. |
| char const\* vendorName |  | The name of the vendor of the adapter, if available. Empty string otherwise. |
| char const\* architecture |  | The name of the family or class of GPUs the adapter belongs to, if available. Empty string otherwise. |
| uint32_t deviceID |  | The vendor-specific device identifier. |
| char const\* name |  | A vendor-specific identifier for the adapter, if available. Empty string otherwise. |
| char const\* driverDescription |  | A human readable string describing the adapter as reported by the driver, if available. Empty string otherwise. |
| [AdapterType]({{ '/api/cpp.html#enum-AdapterType' | relative_url }}) adapterType |  | The type of the adapter |
| [BackendType]({{ '/api/cpp.html#enum-BackendType' | relative_url }}) backendType |  | The backend platform used by the adapter |

### struct BindGroupDescriptor {#structure-BindGroupDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [BindGroupLayout]({{ '/api/cpp.html#class-BindGroupLayout' | relative_url }}) layout |  |  |
| uint32_t entryCount |  |  |
| [BindGroupEntry]({{ '/api/cpp.html#structure-BindGroupEntry' | relative_url }}) const\* entries |  |  |

### struct BindGroupEntry {#structure-BindGroupEntry}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| uint32_t binding |  |  |
| [Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) buffer |  |  |
| uint64_t offset | `0` |  |
| uint64_t size |  |  |
| [Sampler]({{ '/api/cpp.html#class-Sampler' | relative_url }}) sampler |  |  |
| [TextureView]({{ '/api/cpp.html#class-TextureView' | relative_url }}) textureView |  |  |

#### Chainable Structures

 * [ExternalTextureBindingEntry]({{ '/api/cpp.html#structure-ExternalTextureBindingEntry' | relative_url }})

### struct BindGroupLayoutDescriptor {#structure-BindGroupLayoutDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| uint32_t entryCount |  |  |
| [BindGroupLayoutEntry]({{ '/api/cpp.html#structure-BindGroupLayoutEntry' | relative_url }}) const\* entries |  |  |

### struct BindGroupLayoutEntry {#structure-BindGroupLayoutEntry}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| uint32_t binding |  |  |
| [ShaderStage]({{ '/api/cpp.html#bitmask-ShaderStage' | relative_url }}) visibility |  |  |
| [BufferBindingLayout]({{ '/api/cpp.html#structure-BufferBindingLayout' | relative_url }}) buffer |  |  |
| [SamplerBindingLayout]({{ '/api/cpp.html#structure-SamplerBindingLayout' | relative_url }}) sampler |  |  |
| [TextureBindingLayout]({{ '/api/cpp.html#structure-TextureBindingLayout' | relative_url }}) texture |  |  |
| [StorageTextureBindingLayout]({{ '/api/cpp.html#structure-StorageTextureBindingLayout' | relative_url }}) storageTexture |  |  |

#### Chainable Structures

 * [ExternalTextureBindingLayout]({{ '/api/cpp.html#structure-ExternalTextureBindingLayout' | relative_url }})

### struct BlendComponent {#structure-BlendComponent}

| Members | Default | Description |
|:--------|:--------|:------------|
| [BlendOperation]({{ '/api/cpp.html#enum-BlendOperation' | relative_url }}) operation | `BlendOperation::Add` |  |
| [BlendFactor]({{ '/api/cpp.html#enum-BlendFactor' | relative_url }}) srcFactor | `BlendFactor::One` |  |
| [BlendFactor]({{ '/api/cpp.html#enum-BlendFactor' | relative_url }}) dstFactor | `BlendFactor::Zero` |  |

### struct BlendState {#structure-BlendState}

| Members | Default | Description |
|:--------|:--------|:------------|
| [BlendComponent]({{ '/api/cpp.html#structure-BlendComponent' | relative_url }}) color |  |  |
| [BlendComponent]({{ '/api/cpp.html#structure-BlendComponent' | relative_url }}) alpha |  |  |

### struct BufferBindingLayout {#structure-BufferBindingLayout}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [BufferBindingType]({{ '/api/cpp.html#enum-BufferBindingType' | relative_url }}) type | `BufferBindingType::Undefined` |  |
| bool hasDynamicOffset | `false` |  |
| uint64_t minBindingSize | `0` |  |

### struct BufferDescriptor {#structure-BufferDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [BufferUsage]({{ '/api/cpp.html#bitmask-BufferUsage' | relative_url }}) usage |  |  |
| uint64_t size |  |  |
| bool mappedAtCreation | `false` |  |

### struct Color {#structure-Color}

| Members | Default | Description |
|:--------|:--------|:------------|
| double r |  |  |
| double g |  |  |
| double b |  |  |
| double a |  |  |

### struct ColorTargetState {#structure-ColorTargetState}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [TextureFormat]({{ '/api/cpp.html#enum-TextureFormat' | relative_url }}) format |  |  |
| [BlendState]({{ '/api/cpp.html#structure-BlendState' | relative_url }}) const\* blend |  |  |
| [ColorWriteMask]({{ '/api/cpp.html#bitmask-ColorWriteMask' | relative_url }}) writeMask | `ColorWriteMask::All` |  |

### struct CommandBufferDescriptor {#structure-CommandBufferDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |

### struct CommandEncoderDescriptor {#structure-CommandEncoderDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |

#### Chainable Structures

 * [DawnEncoderInternalUsageDescriptor]({{ '/api/cpp.html#structure-DawnEncoderInternalUsageDescriptor' | relative_url }})

### struct CompilationInfo {#structure-CompilationInfo}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| uint32_t messageCount |  |  |
| [CompilationMessage]({{ '/api/cpp.html#structure-CompilationMessage' | relative_url }}) const\* messages |  |  |

### struct CompilationMessage {#structure-CompilationMessage}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* message |  |  |
| [CompilationMessageType]({{ '/api/cpp.html#enum-CompilationMessageType' | relative_url }}) type |  |  |
| uint64_t lineNum |  |  |
| uint64_t linePos |  |  |
| uint64_t offset |  |  |
| uint64_t length |  |  |

### struct ComputePassDescriptor {#structure-ComputePassDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| uint32_t timestampWriteCount | `0` |  |
| [ComputePassTimestampWrite]({{ '/api/cpp.html#structure-ComputePassTimestampWrite' | relative_url }}) const\* timestampWrites |  |  |

### struct ComputePassTimestampWrite {#structure-ComputePassTimestampWrite}

| Members | Default | Description |
|:--------|:--------|:------------|
| [QuerySet]({{ '/api/cpp.html#class-QuerySet' | relative_url }}) querySet |  |  |
| uint32_t queryIndex |  |  |
| [ComputePassTimestampLocation]({{ '/api/cpp.html#enum-ComputePassTimestampLocation' | relative_url }}) location |  |  |

### struct ComputePipelineDescriptor {#structure-ComputePipelineDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [PipelineLayout]({{ '/api/cpp.html#class-PipelineLayout' | relative_url }}) layout |  |  |
| [ProgrammableStageDescriptor]({{ '/api/cpp.html#structure-ProgrammableStageDescriptor' | relative_url }}) compute |  |  |

### struct ConstantEntry {#structure-ConstantEntry}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* key |  |  |
| double value |  |  |

### struct CopyTextureForBrowserOptions {#structure-CopyTextureForBrowserOptions}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| bool flipY | `false` |  |
| bool needsColorSpaceConversion | `false` |  |
| [AlphaMode]({{ '/api/cpp.html#enum-AlphaMode' | relative_url }}) srcAlphaMode | `AlphaMode::Unpremultiplied` |  |
| float const\* srcTransferFunctionParameters |  |  |
| float const\* conversionMatrix |  |  |
| float const\* dstTransferFunctionParameters |  |  |
| [AlphaMode]({{ '/api/cpp.html#enum-AlphaMode' | relative_url }}) dstAlphaMode | `AlphaMode::Unpremultiplied` |  |
| bool internalUsage | `false` |  |

### struct DawnCacheDeviceDescriptor {#structure-DawnCacheDeviceDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::DawnCacheDeviceDescriptor` | Structure type |
| char const\* isolationKey | `""` |  |

#### Chain Parent Structures

 * [DeviceDescriptor]({{ '/api/cpp.html#structure-DeviceDescriptor' | relative_url }})

### struct DawnEncoderInternalUsageDescriptor {#structure-DawnEncoderInternalUsageDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::DawnEncoderInternalUsageDescriptor` | Structure type |
| bool useInternalUsages | `false` |  |

#### Chain Parent Structures

 * [CommandEncoderDescriptor]({{ '/api/cpp.html#structure-CommandEncoderDescriptor' | relative_url }})

### struct DawnInstanceDescriptor {#structure-DawnInstanceDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::DawnInstanceDescriptor` | Structure type |
| uint32_t additionalRuntimeSearchPathsCount | `0` |  |
| char const\*const\* additionalRuntimeSearchPaths |  |  |

#### Chain Parent Structures

 * [InstanceDescriptor]({{ '/api/cpp.html#structure-InstanceDescriptor' | relative_url }})

### struct DawnTextureInternalUsageDescriptor {#structure-DawnTextureInternalUsageDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::DawnTextureInternalUsageDescriptor` | Structure type |
| [TextureUsage]({{ '/api/cpp.html#bitmask-TextureUsage' | relative_url }}) internalUsage | `TextureUsage::None` |  |

#### Chain Parent Structures

 * [TextureDescriptor]({{ '/api/cpp.html#structure-TextureDescriptor' | relative_url }})

### struct DawnTogglesDeviceDescriptor {#structure-DawnTogglesDeviceDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::DawnTogglesDeviceDescriptor` | Structure type |
| uint32_t forceEnabledTogglesCount | `0` |  |
| char const\*const\* forceEnabledToggles |  |  |
| uint32_t forceDisabledTogglesCount | `0` |  |
| char const\*const\* forceDisabledToggles |  |  |

#### Chain Parent Structures

 * [DeviceDescriptor]({{ '/api/cpp.html#structure-DeviceDescriptor' | relative_url }})

### struct DepthStencilState {#structure-DepthStencilState}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [TextureFormat]({{ '/api/cpp.html#enum-TextureFormat' | relative_url }}) format |  |  |
| bool depthWriteEnabled | `false` |  |
| [CompareFunction]({{ '/api/cpp.html#enum-CompareFunction' | relative_url }}) depthCompare | `CompareFunction::Always` |  |
| [StencilFaceState]({{ '/api/cpp.html#structure-StencilFaceState' | relative_url }}) stencilFront |  |  |
| [StencilFaceState]({{ '/api/cpp.html#structure-StencilFaceState' | relative_url }}) stencilBack |  |  |
| uint32_t stencilReadMask | `0xFFFFFFFF` |  |
| uint32_t stencilWriteMask | `0xFFFFFFFF` |  |
| int32_t depthBias | `0` |  |
| float depthBiasSlopeScale | `0.0f` |  |
| float depthBiasClamp | `0.0f` |  |

### struct DeviceDescriptor {#structure-DeviceDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| uint32_t requiredFeaturesCount | `0` |  |
| [FeatureName]({{ '/api/cpp.html#enum-FeatureName' | relative_url }}) const\* requiredFeatures | `FeatureName::Nullptr` |  |
| [RequiredLimits]({{ '/api/cpp.html#structure-RequiredLimits' | relative_url }}) const\* requiredLimits |  |  |
| [QueueDescriptor]({{ '/api/cpp.html#structure-QueueDescriptor' | relative_url }}) defaultQueue |  |  |

#### Chainable Structures

 * [DawnTogglesDeviceDescriptor]({{ '/api/cpp.html#structure-DawnTogglesDeviceDescriptor' | relative_url }})
 * [DawnCacheDeviceDescriptor]({{ '/api/cpp.html#structure-DawnCacheDeviceDescriptor' | relative_url }})

### struct Extent3D {#structure-Extent3D}

| Members | Default | Description |
|:--------|:--------|:------------|
| uint32_t width |  |  |
| uint32_t height | `1` |  |
| uint32_t depthOrArrayLayers | `1` |  |

### struct ExternalTextureBindingEntry {#structure-ExternalTextureBindingEntry}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::ExternalTextureBindingEntry` | Structure type |
| [ExternalTexture]({{ '/api/cpp.html#class-ExternalTexture' | relative_url }}) externalTexture |  |  |

#### Chain Parent Structures

 * [BindGroupEntry]({{ '/api/cpp.html#structure-BindGroupEntry' | relative_url }})

### struct ExternalTextureBindingLayout {#structure-ExternalTextureBindingLayout}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::ExternalTextureBindingLayout` | Structure type |

#### Chain Parent Structures

 * [BindGroupLayoutEntry]({{ '/api/cpp.html#structure-BindGroupLayoutEntry' | relative_url }})

### struct ExternalTextureDescriptor {#structure-ExternalTextureDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [TextureView]({{ '/api/cpp.html#class-TextureView' | relative_url }}) plane0 |  |  |
| [TextureView]({{ '/api/cpp.html#class-TextureView' | relative_url }}) plane1 |  |  |
| bool doYuvToRgbConversionOnly | `false` |  |
| float const\* yuvToRgbConversionMatrix |  |  |
| float const\* srcTransferFunctionParameters |  |  |
| float const\* dstTransferFunctionParameters |  |  |
| float const\* gamutConversionMatrix |  |  |

### struct FragmentState {#structure-FragmentState}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [ShaderModule]({{ '/api/cpp.html#class-ShaderModule' | relative_url }}) module |  |  |
| char const\* entryPoint |  |  |
| uint32_t constantCount | `0` |  |
| [ConstantEntry]({{ '/api/cpp.html#structure-ConstantEntry' | relative_url }}) const\* constants |  |  |
| uint32_t targetCount |  |  |
| [ColorTargetState]({{ '/api/cpp.html#structure-ColorTargetState' | relative_url }}) const\* targets |  |  |

### struct ImageCopyBuffer {#structure-ImageCopyBuffer}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [TextureDataLayout]({{ '/api/cpp.html#structure-TextureDataLayout' | relative_url }}) layout |  |  |
| [Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) buffer |  |  |

### struct ImageCopyTexture {#structure-ImageCopyTexture}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [Texture]({{ '/api/cpp.html#class-Texture' | relative_url }}) texture |  |  |
| uint32_t mipLevel | `0` |  |
| [Origin3D]({{ '/api/cpp.html#structure-Origin3D' | relative_url }}) origin |  |  |
| [TextureAspect]({{ '/api/cpp.html#enum-TextureAspect' | relative_url }}) aspect | `TextureAspect::All` |  |

### struct InstanceDescriptor {#structure-InstanceDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |

#### Chainable Structures

 * [DawnInstanceDescriptor]({{ '/api/cpp.html#structure-DawnInstanceDescriptor' | relative_url }})

### struct Limits {#structure-Limits}

| Members | Default | Description |
|:--------|:--------|:------------|
| uint32_t maxTextureDimension1D | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxTextureDimension2D | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxTextureDimension3D | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxTextureArrayLayers | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxBindGroups | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxBindingsPerBindGroup | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxDynamicUniformBuffersPerPipelineLayout | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxDynamicStorageBuffersPerPipelineLayout | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxSampledTexturesPerShaderStage | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxSamplersPerShaderStage | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxStorageBuffersPerShaderStage | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxStorageTexturesPerShaderStage | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxUniformBuffersPerShaderStage | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint64_t maxUniformBufferBindingSize | `WGPU_LIMIT_U64_UNDEFINED` |  |
| uint64_t maxStorageBufferBindingSize | `WGPU_LIMIT_U64_UNDEFINED` |  |
| uint32_t minUniformBufferOffsetAlignment | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t minStorageBufferOffsetAlignment | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxVertexBuffers | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxVertexAttributes | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxVertexBufferArrayStride | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxInterStageShaderComponents | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxInterStageShaderVariables | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxColorAttachments | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxComputeWorkgroupStorageSize | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxComputeInvocationsPerWorkgroup | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxComputeWorkgroupSizeX | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxComputeWorkgroupSizeY | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxComputeWorkgroupSizeZ | `WGPU_LIMIT_U32_UNDEFINED` |  |
| uint32_t maxComputeWorkgroupsPerDimension | `WGPU_LIMIT_U32_UNDEFINED` |  |

### struct MultisampleState {#structure-MultisampleState}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| uint32_t count | `1` |  |
| uint32_t mask | `0xFFFFFFFF` |  |
| bool alphaToCoverageEnabled | `false` |  |

### struct Origin3D {#structure-Origin3D}

| Members | Default | Description |
|:--------|:--------|:------------|
| uint32_t x | `0` |  |
| uint32_t y | `0` |  |
| uint32_t z | `0` |  |

### struct PipelineLayoutDescriptor {#structure-PipelineLayoutDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| uint32_t bindGroupLayoutCount |  |  |
| [BindGroupLayout]({{ '/api/cpp.html#class-BindGroupLayout' | relative_url }}) const\* bindGroupLayouts |  |  |

### struct PrimitiveDepthClipControl {#structure-PrimitiveDepthClipControl}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::PrimitiveDepthClipControl` | Structure type |
| bool unclippedDepth | `false` |  |

#### Chain Parent Structures

 * [PrimitiveState]({{ '/api/cpp.html#structure-PrimitiveState' | relative_url }})

### struct PrimitiveState {#structure-PrimitiveState}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [PrimitiveTopology]({{ '/api/cpp.html#enum-PrimitiveTopology' | relative_url }}) topology | `PrimitiveTopology::TriangleList` |  |
| [IndexFormat]({{ '/api/cpp.html#enum-IndexFormat' | relative_url }}) stripIndexFormat | `IndexFormat::Undefined` |  |
| [FrontFace]({{ '/api/cpp.html#enum-FrontFace' | relative_url }}) frontFace | `FrontFace::CCW` |  |
| [CullMode]({{ '/api/cpp.html#enum-CullMode' | relative_url }}) cullMode | `CullMode::None` |  |

#### Chainable Structures

 * [PrimitiveDepthClipControl]({{ '/api/cpp.html#structure-PrimitiveDepthClipControl' | relative_url }})

### struct ProgrammableStageDescriptor {#structure-ProgrammableStageDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [ShaderModule]({{ '/api/cpp.html#class-ShaderModule' | relative_url }}) module |  |  |
| char const\* entryPoint |  |  |
| uint32_t constantCount | `0` |  |
| [ConstantEntry]({{ '/api/cpp.html#structure-ConstantEntry' | relative_url }}) const\* constants |  |  |

### struct QuerySetDescriptor {#structure-QuerySetDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [QueryType]({{ '/api/cpp.html#enum-QueryType' | relative_url }}) type |  |  |
| uint32_t count |  |  |
| [PipelineStatisticName]({{ '/api/cpp.html#enum-PipelineStatisticName' | relative_url }}) const\* pipelineStatistics |  |  |
| uint32_t pipelineStatisticsCount | `0` |  |

### struct QueueDescriptor {#structure-QueueDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |

### struct RenderBundleDescriptor {#structure-RenderBundleDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |

### struct RenderBundleEncoderDescriptor {#structure-RenderBundleEncoderDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| uint32_t colorFormatsCount |  |  |
| [TextureFormat]({{ '/api/cpp.html#enum-TextureFormat' | relative_url }}) const\* colorFormats |  |  |
| [TextureFormat]({{ '/api/cpp.html#enum-TextureFormat' | relative_url }}) depthStencilFormat | `TextureFormat::Undefined` |  |
| uint32_t sampleCount | `1` |  |
| bool depthReadOnly | `false` |  |
| bool stencilReadOnly | `false` |  |

### struct RenderPassColorAttachment {#structure-RenderPassColorAttachment}

| Members | Default | Description |
|:--------|:--------|:------------|
| [TextureView]({{ '/api/cpp.html#class-TextureView' | relative_url }}) view |  |  |
| [TextureView]({{ '/api/cpp.html#class-TextureView' | relative_url }}) resolveTarget |  |  |
| [LoadOp]({{ '/api/cpp.html#enum-LoadOp' | relative_url }}) loadOp |  |  |
| [StoreOp]({{ '/api/cpp.html#enum-StoreOp' | relative_url }}) storeOp |  |  |
| [Color]({{ '/api/cpp.html#structure-Color' | relative_url }}) clearColor | `Color::{NAN,NAN,NAN,NAN}` |  |
| [Color]({{ '/api/cpp.html#structure-Color' | relative_url }}) clearValue |  |  |

### struct RenderPassDepthStencilAttachment {#structure-RenderPassDepthStencilAttachment}

| Members | Default | Description |
|:--------|:--------|:------------|
| [TextureView]({{ '/api/cpp.html#class-TextureView' | relative_url }}) view |  |  |
| [LoadOp]({{ '/api/cpp.html#enum-LoadOp' | relative_url }}) depthLoadOp | `LoadOp::Undefined` |  |
| [StoreOp]({{ '/api/cpp.html#enum-StoreOp' | relative_url }}) depthStoreOp | `StoreOp::Undefined` |  |
| float clearDepth | `NAN` |  |
| float depthClearValue | `0` |  |
| bool depthReadOnly | `false` |  |
| [LoadOp]({{ '/api/cpp.html#enum-LoadOp' | relative_url }}) stencilLoadOp | `LoadOp::Undefined` |  |
| [StoreOp]({{ '/api/cpp.html#enum-StoreOp' | relative_url }}) stencilStoreOp | `StoreOp::Undefined` |  |
| uint32_t clearStencil | `0` |  |
| uint32_t stencilClearValue | `0` |  |
| bool stencilReadOnly | `false` |  |

### struct RenderPassDescriptor {#structure-RenderPassDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| uint32_t colorAttachmentCount |  |  |
| [RenderPassColorAttachment]({{ '/api/cpp.html#structure-RenderPassColorAttachment' | relative_url }}) const\* colorAttachments |  |  |
| [RenderPassDepthStencilAttachment]({{ '/api/cpp.html#structure-RenderPassDepthStencilAttachment' | relative_url }}) const\* depthStencilAttachment |  |  |
| [QuerySet]({{ '/api/cpp.html#class-QuerySet' | relative_url }}) occlusionQuerySet |  |  |
| uint32_t timestampWriteCount | `0` |  |
| [RenderPassTimestampWrite]({{ '/api/cpp.html#structure-RenderPassTimestampWrite' | relative_url }}) const\* timestampWrites |  |  |

#### Chainable Structures

 * [RenderPassDescriptorMaxDrawCount]({{ '/api/cpp.html#structure-RenderPassDescriptorMaxDrawCount' | relative_url }})

### struct RenderPassDescriptorMaxDrawCount {#structure-RenderPassDescriptorMaxDrawCount}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::RenderPassDescriptorMaxDrawCount` | Structure type |
| uint64_t maxDrawCount | `50000000` |  |

#### Chain Parent Structures

 * [RenderPassDescriptor]({{ '/api/cpp.html#structure-RenderPassDescriptor' | relative_url }})

### struct RenderPassTimestampWrite {#structure-RenderPassTimestampWrite}

| Members | Default | Description |
|:--------|:--------|:------------|
| [QuerySet]({{ '/api/cpp.html#class-QuerySet' | relative_url }}) querySet |  |  |
| uint32_t queryIndex |  |  |
| [RenderPassTimestampLocation]({{ '/api/cpp.html#enum-RenderPassTimestampLocation' | relative_url }}) location |  |  |

### struct RenderPipelineDescriptor {#structure-RenderPipelineDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [PipelineLayout]({{ '/api/cpp.html#class-PipelineLayout' | relative_url }}) layout |  |  |
| [VertexState]({{ '/api/cpp.html#structure-VertexState' | relative_url }}) vertex |  |  |
| [PrimitiveState]({{ '/api/cpp.html#structure-PrimitiveState' | relative_url }}) primitive |  |  |
| [DepthStencilState]({{ '/api/cpp.html#structure-DepthStencilState' | relative_url }}) const\* depthStencil |  |  |
| [MultisampleState]({{ '/api/cpp.html#structure-MultisampleState' | relative_url }}) multisample |  |  |
| [FragmentState]({{ '/api/cpp.html#structure-FragmentState' | relative_url }}) const\* fragment |  |  |

### struct RequestAdapterOptions {#structure-RequestAdapterOptions}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [Surface]({{ '/api/cpp.html#class-Surface' | relative_url }}) compatibleSurface |  |  |
| [PowerPreference]({{ '/api/cpp.html#enum-PowerPreference' | relative_url }}) powerPreference | `PowerPreference::Undefined` |  |
| bool forceFallbackAdapter | `false` |  |

### struct RequiredLimits {#structure-RequiredLimits}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [Limits]({{ '/api/cpp.html#structure-Limits' | relative_url }}) limits |  |  |

### struct SamplerBindingLayout {#structure-SamplerBindingLayout}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [SamplerBindingType]({{ '/api/cpp.html#enum-SamplerBindingType' | relative_url }}) type | `SamplerBindingType::Undefined` |  |

### struct SamplerDescriptor {#structure-SamplerDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [AddressMode]({{ '/api/cpp.html#enum-AddressMode' | relative_url }}) addressModeU | `AddressMode::ClampToEdge` |  |
| [AddressMode]({{ '/api/cpp.html#enum-AddressMode' | relative_url }}) addressModeV | `AddressMode::ClampToEdge` |  |
| [AddressMode]({{ '/api/cpp.html#enum-AddressMode' | relative_url }}) addressModeW | `AddressMode::ClampToEdge` |  |
| [FilterMode]({{ '/api/cpp.html#enum-FilterMode' | relative_url }}) magFilter | `FilterMode::Nearest` |  |
| [FilterMode]({{ '/api/cpp.html#enum-FilterMode' | relative_url }}) minFilter | `FilterMode::Nearest` |  |
| [FilterMode]({{ '/api/cpp.html#enum-FilterMode' | relative_url }}) mipmapFilter | `FilterMode::Nearest` |  |
| [MipmapFilterMode]({{ '/api/cpp.html#enum-MipmapFilterMode' | relative_url }}) mipmapFilter | `MipmapFilterMode::Nearest` |  |
| float lodMinClamp | `0.0f` |  |
| float lodMaxClamp | `1000.0f` |  |
| [CompareFunction]({{ '/api/cpp.html#enum-CompareFunction' | relative_url }}) compare | `CompareFunction::Undefined` |  |
| uint16_t maxAnisotropy | `1` |  |

### struct ShaderModuleSPIRVDescriptor {#structure-ShaderModuleSPIRVDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::ShaderModuleSPIRVDescriptor` | Structure type |
| uint32_t codeSize |  |  |
| uint32_t const\* code |  |  |

#### Chain Parent Structures

 * [ShaderModuleDescriptor]({{ '/api/cpp.html#structure-ShaderModuleDescriptor' | relative_url }})

### struct ShaderModuleWGSLDescriptor {#structure-ShaderModuleWGSLDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::ShaderModuleWGSLDescriptor` | Structure type |
| char const\* source |  |  |
| char const\* code |  |  |

#### Chain Parent Structures

 * [ShaderModuleDescriptor]({{ '/api/cpp.html#structure-ShaderModuleDescriptor' | relative_url }})

### struct ShaderModuleCompilationHint {#structure-ShaderModuleCompilationHint}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* entryPoint |  |  |
| [PipelineLayout]({{ '/api/cpp.html#class-PipelineLayout' | relative_url }}) layout |  |  |

### struct ShaderModuleDescriptor {#structure-ShaderModuleDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| uint32_t hintCount | `0` |  |
| [ShaderModuleCompilationHint]({{ '/api/cpp.html#structure-ShaderModuleCompilationHint' | relative_url }}) const\* hints |  |  |

#### Chainable Structures

 * [ShaderModuleSPIRVDescriptor]({{ '/api/cpp.html#structure-ShaderModuleSPIRVDescriptor' | relative_url }})
 * [ShaderModuleWGSLDescriptor]({{ '/api/cpp.html#structure-ShaderModuleWGSLDescriptor' | relative_url }})

### struct StencilFaceState {#structure-StencilFaceState}

| Members | Default | Description |
|:--------|:--------|:------------|
| [CompareFunction]({{ '/api/cpp.html#enum-CompareFunction' | relative_url }}) compare | `CompareFunction::Always` |  |
| [StencilOperation]({{ '/api/cpp.html#enum-StencilOperation' | relative_url }}) failOp | `StencilOperation::Keep` |  |
| [StencilOperation]({{ '/api/cpp.html#enum-StencilOperation' | relative_url }}) depthFailOp | `StencilOperation::Keep` |  |
| [StencilOperation]({{ '/api/cpp.html#enum-StencilOperation' | relative_url }}) passOp | `StencilOperation::Keep` |  |

### struct StorageTextureBindingLayout {#structure-StorageTextureBindingLayout}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [StorageTextureAccess]({{ '/api/cpp.html#enum-StorageTextureAccess' | relative_url }}) access | `StorageTextureAccess::Undefined` |  |
| [TextureFormat]({{ '/api/cpp.html#enum-TextureFormat' | relative_url }}) format | `TextureFormat::Undefined` |  |
| [TextureViewDimension]({{ '/api/cpp.html#enum-TextureViewDimension' | relative_url }}) viewDimension | `TextureViewDimension::Undefined` |  |

### struct SupportedLimits {#structure-SupportedLimits}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStructOut const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [Limits]({{ '/api/cpp.html#structure-Limits' | relative_url }}) limits |  |  |

### struct SurfaceDescriptor {#structure-SurfaceDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |

#### Chainable Structures

 * [SurfaceDescriptorFromAndroidNativeWindow]({{ '/api/cpp.html#structure-SurfaceDescriptorFromAndroidNativeWindow' | relative_url }})
 * [SurfaceDescriptorFromCanvasHTMLSelector]({{ '/api/cpp.html#structure-SurfaceDescriptorFromCanvasHTMLSelector' | relative_url }})
 * [SurfaceDescriptorFromMetalLayer]({{ '/api/cpp.html#structure-SurfaceDescriptorFromMetalLayer' | relative_url }})
 * [SurfaceDescriptorFromWindowsHWND]({{ '/api/cpp.html#structure-SurfaceDescriptorFromWindowsHWND' | relative_url }})
 * [SurfaceDescriptorFromXcbWindow]({{ '/api/cpp.html#structure-SurfaceDescriptorFromXcbWindow' | relative_url }})
 * [SurfaceDescriptorFromXlibWindow]({{ '/api/cpp.html#structure-SurfaceDescriptorFromXlibWindow' | relative_url }})
 * [SurfaceDescriptorFromWaylandSurface]({{ '/api/cpp.html#structure-SurfaceDescriptorFromWaylandSurface' | relative_url }})
 * [SurfaceDescriptorFromWindowsCoreWindow]({{ '/api/cpp.html#structure-SurfaceDescriptorFromWindowsCoreWindow' | relative_url }})
 * [SurfaceDescriptorFromWindowsSwapChainPanel]({{ '/api/cpp.html#structure-SurfaceDescriptorFromWindowsSwapChainPanel' | relative_url }})

### struct SurfaceDescriptorFromAndroidNativeWindow {#structure-SurfaceDescriptorFromAndroidNativeWindow}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromAndroidNativeWindow` | Structure type |
| void \* window |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor]({{ '/api/cpp.html#structure-SurfaceDescriptor' | relative_url }})

### struct SurfaceDescriptorFromCanvasHTMLSelector {#structure-SurfaceDescriptorFromCanvasHTMLSelector}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromCanvasHTMLSelector` | Structure type |
| char const\* selector |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor]({{ '/api/cpp.html#structure-SurfaceDescriptor' | relative_url }})

### struct SurfaceDescriptorFromMetalLayer {#structure-SurfaceDescriptorFromMetalLayer}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromMetalLayer` | Structure type |
| void \* layer |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor]({{ '/api/cpp.html#structure-SurfaceDescriptor' | relative_url }})

### struct SurfaceDescriptorFromWaylandSurface {#structure-SurfaceDescriptorFromWaylandSurface}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromWaylandSurface` | Structure type |
| void \* display |  |  |
| void \* surface |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor]({{ '/api/cpp.html#structure-SurfaceDescriptor' | relative_url }})

### struct SurfaceDescriptorFromWindowsHWND {#structure-SurfaceDescriptorFromWindowsHWND}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromWindowsHWND` | Structure type |
| void \* hinstance |  |  |
| void \* hwnd |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor]({{ '/api/cpp.html#structure-SurfaceDescriptor' | relative_url }})

### struct SurfaceDescriptorFromWindowsCoreWindow {#structure-SurfaceDescriptorFromWindowsCoreWindow}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromWindowsCoreWindow` | Structure type |
| void \* coreWindow |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor]({{ '/api/cpp.html#structure-SurfaceDescriptor' | relative_url }})

### struct SurfaceDescriptorFromWindowsSwapChainPanel {#structure-SurfaceDescriptorFromWindowsSwapChainPanel}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromWindowsSwapChainPanel` | Structure type |
| void \* swapChainPanel |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor]({{ '/api/cpp.html#structure-SurfaceDescriptor' | relative_url }})

### struct SurfaceDescriptorFromXcbWindow {#structure-SurfaceDescriptorFromXcbWindow}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromXcbWindow` | Structure type |
| void \* connection |  |  |
| uint32_t window |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor]({{ '/api/cpp.html#structure-SurfaceDescriptor' | relative_url }})

### struct SurfaceDescriptorFromXlibWindow {#structure-SurfaceDescriptorFromXlibWindow}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromXlibWindow` | Structure type |
| void \* display |  |  |
| uint32_t window |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor]({{ '/api/cpp.html#structure-SurfaceDescriptor' | relative_url }})

### struct SwapChainDescriptor {#structure-SwapChainDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [TextureUsage]({{ '/api/cpp.html#bitmask-TextureUsage' | relative_url }}) usage |  |  |
| [TextureFormat]({{ '/api/cpp.html#enum-TextureFormat' | relative_url }}) format |  |  |
| uint32_t width |  |  |
| uint32_t height |  |  |
| [PresentMode]({{ '/api/cpp.html#enum-PresentMode' | relative_url }}) presentMode |  |  |
| uint64_t implementation | `0` |  |

### struct TextureBindingLayout {#structure-TextureBindingLayout}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [TextureSampleType]({{ '/api/cpp.html#enum-TextureSampleType' | relative_url }}) sampleType | `TextureSampleType::Undefined` |  |
| [TextureViewDimension]({{ '/api/cpp.html#enum-TextureViewDimension' | relative_url }}) viewDimension | `TextureViewDimension::Undefined` |  |
| bool multisampled | `false` |  |

### struct TextureDataLayout {#structure-TextureDataLayout}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| uint64_t offset | `0` |  |
| uint32_t bytesPerRow | `WGPU_COPY_STRIDE_UNDEFINED` |  |
| uint32_t rowsPerImage | `WGPU_COPY_STRIDE_UNDEFINED` |  |

### struct TextureDescriptor {#structure-TextureDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [TextureUsage]({{ '/api/cpp.html#bitmask-TextureUsage' | relative_url }}) usage |  |  |
| [TextureDimension]({{ '/api/cpp.html#enum-TextureDimension' | relative_url }}) dimension | `TextureDimension::2D` |  |
| [Extent3D]({{ '/api/cpp.html#structure-Extent3D' | relative_url }}) size |  |  |
| [TextureFormat]({{ '/api/cpp.html#enum-TextureFormat' | relative_url }}) format |  |  |
| uint32_t mipLevelCount | `1` |  |
| uint32_t sampleCount | `1` |  |
| uint32_t viewFormatCount | `0` |  |
| [TextureFormat]({{ '/api/cpp.html#enum-TextureFormat' | relative_url }}) const\* viewFormats |  |  |

#### Chainable Structures

 * [DawnTextureInternalUsageDescriptor]({{ '/api/cpp.html#structure-DawnTextureInternalUsageDescriptor' | relative_url }})

### struct TextureViewDescriptor {#structure-TextureViewDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [TextureFormat]({{ '/api/cpp.html#enum-TextureFormat' | relative_url }}) format | `TextureFormat::Undefined` |  |
| [TextureViewDimension]({{ '/api/cpp.html#enum-TextureViewDimension' | relative_url }}) dimension | `TextureViewDimension::Undefined` |  |
| uint32_t baseMipLevel | `0` |  |
| uint32_t mipLevelCount | `WGPU_MIP_LEVEL_COUNT_UNDEFINED` |  |
| uint32_t baseArrayLayer | `0` |  |
| uint32_t arrayLayerCount | `WGPU_ARRAY_LAYER_COUNT_UNDEFINED` |  |
| [TextureAspect]({{ '/api/cpp.html#enum-TextureAspect' | relative_url }}) aspect | `TextureAspect::All` |  |

### struct VertexAttribute {#structure-VertexAttribute}

| Members | Default | Description |
|:--------|:--------|:------------|
| [VertexFormat]({{ '/api/cpp.html#enum-VertexFormat' | relative_url }}) format |  |  |
| uint64_t offset |  |  |
| uint32_t shaderLocation |  |  |

### struct VertexBufferLayout {#structure-VertexBufferLayout}

| Members | Default | Description |
|:--------|:--------|:------------|
| uint64_t arrayStride |  |  |
| [VertexStepMode]({{ '/api/cpp.html#enum-VertexStepMode' | relative_url }}) stepMode | `VertexStepMode::Vertex` |  |
| uint32_t attributeCount |  |  |
| [VertexAttribute]({{ '/api/cpp.html#structure-VertexAttribute' | relative_url }}) const\* attributes |  |  |

### struct VertexState {#structure-VertexState}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [ShaderModule]({{ '/api/cpp.html#class-ShaderModule' | relative_url }}) module |  |  |
| char const\* entryPoint |  |  |
| uint32_t constantCount | `0` |  |
| [ConstantEntry]({{ '/api/cpp.html#structure-ConstantEntry' | relative_url }}) const\* constants |  |  |
| uint32_t bufferCount | `0` |  |
| [VertexBufferLayout]({{ '/api/cpp.html#structure-VertexBufferLayout' | relative_url }}) const\* buffers |  |  |

## Classes

<div class='object' markdown=1>

### class Adapter {#class-Adapter}

An *adapter* identifies an implemention of WebGPU on the system.

See [Adapters](https://webgpu.dev/#adapters) for more information.

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Device]({{ '/api/cpp.html#class-Device' | relative_url }}) CreateDevice([DeviceDescriptor]({{ '/api/cpp.html#structure-DeviceDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

size_t EnumerateFeatures([FeatureName]({{ '/api/cpp.html#enum-FeatureName' | relative_url }}) \* features)

</div>

#### Returns


#### Arguments

* *features*: 

</div>

<div class='method' markdown=1>

Retrieves the limits which can be used with this adapter.

<div class='signature' markdown=1>

bool GetLimits([SupportedLimits]({{ '/api/cpp.html#structure-SupportedLimits' | relative_url }}) \* limits)

</div>

#### Returns

Returns true if the limits were successfully retrieved.
#### Arguments

* *limits*: The [SupportedLimits]({{ '/api/cpp.html#structure-SupportedLimits' | relative_url }}) object to populate. Must not be nullptr.

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void GetProperties([AdapterProperties]({{ '/api/cpp.html#structure-AdapterProperties' | relative_url }}) \* properties)

</div>

#### Arguments

* *properties*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

bool HasFeature([FeatureName]({{ '/api/cpp.html#enum-FeatureName' | relative_url }}) feature)

</div>

#### Returns


#### Arguments

* *feature*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void RequestDevice([DeviceDescriptor]({{ '/api/cpp.html#structure-DeviceDescriptor' | relative_url }}) const\* descriptor, [RequestDeviceCallback]({{ '/api/cpp.html#function-pointer-RequestDeviceCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *descriptor*: 
* *callback*: 
* *userdata*: 

</div>

</div>

<div class='object' markdown=1>

### class BindGroup {#class-BindGroup}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

</div>

<div class='object' markdown=1>

### class BindGroupLayout {#class-BindGroupLayout}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

</div>

<div class='object' markdown=1>

### class Buffer {#class-Buffer}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void Destroy()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void const * GetConstMappedRange(size_t offset, size_t size)

</div>

#### Returns


#### Arguments

* *offset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void * GetMappedRange(size_t offset, size_t size)

</div>

#### Returns


#### Arguments

* *offset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint64_t GetSize()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[BufferUsage]({{ '/api/cpp.html#bitmask-BufferUsage' | relative_url }}) GetUsage()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void MapAsync([MapMode]({{ '/api/cpp.html#bitmask-MapMode' | relative_url }}) mode, size_t offset, size_t size, [BufferMapCallback]({{ '/api/cpp.html#function-pointer-BufferMapCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *mode*: 
* *offset*: 
* *size*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void Unmap()

</div>

</div>

</div>

<div class='object' markdown=1>

### class CommandBuffer {#class-CommandBuffer}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

</div>

<div class='object' markdown=1>

### class CommandEncoder {#class-CommandEncoder}

<div class='method' markdown=1>

<div class='signature' markdown=1>

[ComputePassEncoder]({{ '/api/cpp.html#class-ComputePassEncoder' | relative_url }}) BeginComputePass([ComputePassDescriptor]({{ '/api/cpp.html#structure-ComputePassDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[RenderPassEncoder]({{ '/api/cpp.html#class-RenderPassEncoder' | relative_url }}) BeginRenderPass([RenderPassDescriptor]({{ '/api/cpp.html#structure-RenderPassDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void ClearBuffer([Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) buffer, uint64_t offset, uint64_t size)

</div>

#### Arguments

* *buffer*: 
* *offset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void CopyBufferToBuffer([Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) source, uint64_t sourceOffset, [Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) destination, uint64_t destinationOffset, uint64_t size)

</div>

#### Arguments

* *source*: 
* *sourceOffset*: 
* *destination*: 
* *destinationOffset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void CopyBufferToTexture([ImageCopyBuffer]({{ '/api/cpp.html#structure-ImageCopyBuffer' | relative_url }}) const\* source, [ImageCopyTexture]({{ '/api/cpp.html#structure-ImageCopyTexture' | relative_url }}) const\* destination, [Extent3D]({{ '/api/cpp.html#structure-Extent3D' | relative_url }}) const\* copySize)

</div>

#### Arguments

* *source*: 
* *destination*: 
* *copySize*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void CopyTextureToBuffer([ImageCopyTexture]({{ '/api/cpp.html#structure-ImageCopyTexture' | relative_url }}) const\* source, [ImageCopyBuffer]({{ '/api/cpp.html#structure-ImageCopyBuffer' | relative_url }}) const\* destination, [Extent3D]({{ '/api/cpp.html#structure-Extent3D' | relative_url }}) const\* copySize)

</div>

#### Arguments

* *source*: 
* *destination*: 
* *copySize*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void CopyTextureToTexture([ImageCopyTexture]({{ '/api/cpp.html#structure-ImageCopyTexture' | relative_url }}) const\* source, [ImageCopyTexture]({{ '/api/cpp.html#structure-ImageCopyTexture' | relative_url }}) const\* destination, [Extent3D]({{ '/api/cpp.html#structure-Extent3D' | relative_url }}) const\* copySize)

</div>

#### Arguments

* *source*: 
* *destination*: 
* *copySize*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void CopyTextureToTextureInternal([ImageCopyTexture]({{ '/api/cpp.html#structure-ImageCopyTexture' | relative_url }}) const\* source, [ImageCopyTexture]({{ '/api/cpp.html#structure-ImageCopyTexture' | relative_url }}) const\* destination, [Extent3D]({{ '/api/cpp.html#structure-Extent3D' | relative_url }}) const\* copySize)

</div>

#### Arguments

* *source*: 
* *destination*: 
* *copySize*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[CommandBuffer]({{ '/api/cpp.html#class-CommandBuffer' | relative_url }}) Finish([CommandBufferDescriptor]({{ '/api/cpp.html#structure-CommandBufferDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void InjectValidationError(char const\* message)

</div>

#### Arguments

* *message*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void InsertDebugMarker(char const\* markerLabel)

</div>

#### Arguments

* *markerLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void PopDebugGroup()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void PushDebugGroup(char const\* groupLabel)

</div>

#### Arguments

* *groupLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void ResolveQuerySet([QuerySet]({{ '/api/cpp.html#class-QuerySet' | relative_url }}) querySet, uint32_t firstQuery, uint32_t queryCount, [Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) destination, uint64_t destinationOffset)

</div>

#### Arguments

* *querySet*: 
* *firstQuery*: 
* *queryCount*: 
* *destination*: 
* *destinationOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void WriteBuffer([Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) buffer, uint64_t bufferOffset, uint8_t const\* data, uint64_t size)

</div>

#### Arguments

* *buffer*: 
* *bufferOffset*: 
* *data*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void WriteTimestamp([QuerySet]({{ '/api/cpp.html#class-QuerySet' | relative_url }}) querySet, uint32_t queryIndex)

</div>

#### Arguments

* *querySet*: 
* *queryIndex*: 

</div>

</div>

<div class='object' markdown=1>

### class ComputePassEncoder {#class-ComputePassEncoder}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void BeginPipelineStatisticsQuery([QuerySet]({{ '/api/cpp.html#class-QuerySet' | relative_url }}) querySet, uint32_t queryIndex)

</div>

#### Arguments

* *querySet*: 
* *queryIndex*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void Dispatch(uint32_t workgroupCountX, uint32_t workgroupCountY, uint32_t workgroupCountZ)

</div>

#### Arguments

* *workgroupCountX*: 
* *workgroupCountY*: 
* *workgroupCountZ*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void DispatchIndirect([Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void DispatchWorkgroups(uint32_t workgroupCountX, uint32_t workgroupCountY, uint32_t workgroupCountZ)

</div>

#### Arguments

* *workgroupCountX*: 
* *workgroupCountY*: 
* *workgroupCountZ*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void DispatchWorkgroupsIndirect([Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void End()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void EndPass()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void EndPipelineStatisticsQuery()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void InsertDebugMarker(char const\* markerLabel)

</div>

#### Arguments

* *markerLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void PopDebugGroup()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void PushDebugGroup(char const\* groupLabel)

</div>

#### Arguments

* *groupLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetBindGroup(uint32_t groupIndex, [BindGroup]({{ '/api/cpp.html#class-BindGroup' | relative_url }}) group, uint32_t dynamicOffsetCount, uint32_t const\* dynamicOffsets)

</div>

#### Arguments

* *groupIndex*: 
* *group*: 
* *dynamicOffsetCount*: 
* *dynamicOffsets*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetPipeline([ComputePipeline]({{ '/api/cpp.html#class-ComputePipeline' | relative_url }}) pipeline)

</div>

#### Arguments

* *pipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void WriteTimestamp([QuerySet]({{ '/api/cpp.html#class-QuerySet' | relative_url }}) querySet, uint32_t queryIndex)

</div>

#### Arguments

* *querySet*: 
* *queryIndex*: 

</div>

</div>

<div class='object' markdown=1>

### class ComputePipeline {#class-ComputePipeline}

<div class='method' markdown=1>

<div class='signature' markdown=1>

[BindGroupLayout]({{ '/api/cpp.html#class-BindGroupLayout' | relative_url }}) GetBindGroupLayout(uint32_t groupIndex)

</div>

#### Returns


#### Arguments

* *groupIndex*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

</div>

<div class='object' markdown=1>

### class Device {#class-Device}

<div class='method' markdown=1>

<div class='signature' markdown=1>

[BindGroup]({{ '/api/cpp.html#class-BindGroup' | relative_url }}) CreateBindGroup([BindGroupDescriptor]({{ '/api/cpp.html#structure-BindGroupDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[BindGroupLayout]({{ '/api/cpp.html#class-BindGroupLayout' | relative_url }}) CreateBindGroupLayout([BindGroupLayoutDescriptor]({{ '/api/cpp.html#structure-BindGroupLayoutDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) CreateBuffer([BufferDescriptor]({{ '/api/cpp.html#structure-BufferDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[CommandEncoder]({{ '/api/cpp.html#class-CommandEncoder' | relative_url }}) CreateCommandEncoder([CommandEncoderDescriptor]({{ '/api/cpp.html#structure-CommandEncoderDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[ComputePipeline]({{ '/api/cpp.html#class-ComputePipeline' | relative_url }}) CreateComputePipeline([ComputePipelineDescriptor]({{ '/api/cpp.html#structure-ComputePipelineDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void CreateComputePipelineAsync([ComputePipelineDescriptor]({{ '/api/cpp.html#structure-ComputePipelineDescriptor' | relative_url }}) const\* descriptor, [CreateComputePipelineAsyncCallback]({{ '/api/cpp.html#function-pointer-CreateComputePipelineAsyncCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *descriptor*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) CreateErrorBuffer()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[ExternalTexture]({{ '/api/cpp.html#class-ExternalTexture' | relative_url }}) CreateErrorExternalTexture()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Texture]({{ '/api/cpp.html#class-Texture' | relative_url }}) CreateErrorTexture([TextureDescriptor]({{ '/api/cpp.html#structure-TextureDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[ExternalTexture]({{ '/api/cpp.html#class-ExternalTexture' | relative_url }}) CreateExternalTexture([ExternalTextureDescriptor]({{ '/api/cpp.html#structure-ExternalTextureDescriptor' | relative_url }}) const\* externalTextureDescriptor)

</div>

#### Returns


#### Arguments

* *externalTextureDescriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[PipelineLayout]({{ '/api/cpp.html#class-PipelineLayout' | relative_url }}) CreatePipelineLayout([PipelineLayoutDescriptor]({{ '/api/cpp.html#structure-PipelineLayoutDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[QuerySet]({{ '/api/cpp.html#class-QuerySet' | relative_url }}) CreateQuerySet([QuerySetDescriptor]({{ '/api/cpp.html#structure-QuerySetDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[RenderBundleEncoder]({{ '/api/cpp.html#class-RenderBundleEncoder' | relative_url }}) CreateRenderBundleEncoder([RenderBundleEncoderDescriptor]({{ '/api/cpp.html#structure-RenderBundleEncoderDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[RenderPipeline]({{ '/api/cpp.html#class-RenderPipeline' | relative_url }}) CreateRenderPipeline([RenderPipelineDescriptor]({{ '/api/cpp.html#structure-RenderPipelineDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void CreateRenderPipelineAsync([RenderPipelineDescriptor]({{ '/api/cpp.html#structure-RenderPipelineDescriptor' | relative_url }}) const\* descriptor, [CreateRenderPipelineAsyncCallback]({{ '/api/cpp.html#function-pointer-CreateRenderPipelineAsyncCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *descriptor*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Sampler]({{ '/api/cpp.html#class-Sampler' | relative_url }}) CreateSampler([SamplerDescriptor]({{ '/api/cpp.html#structure-SamplerDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[ShaderModule]({{ '/api/cpp.html#class-ShaderModule' | relative_url }}) CreateShaderModule([ShaderModuleDescriptor]({{ '/api/cpp.html#structure-ShaderModuleDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[SwapChain]({{ '/api/cpp.html#class-SwapChain' | relative_url }}) CreateSwapChain([Surface]({{ '/api/cpp.html#class-Surface' | relative_url }}) surface, [SwapChainDescriptor]({{ '/api/cpp.html#structure-SwapChainDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *surface*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[SwapChain]({{ '/api/cpp.html#class-SwapChain' | relative_url }}) CreateSwapChain([Surface]({{ '/api/cpp.html#class-Surface' | relative_url }}) surface, [SwapChainDescriptor]({{ '/api/cpp.html#structure-SwapChainDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *surface*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Texture]({{ '/api/cpp.html#class-Texture' | relative_url }}) CreateTexture([TextureDescriptor]({{ '/api/cpp.html#structure-TextureDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void Destroy()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

size_t EnumerateFeatures([FeatureName]({{ '/api/cpp.html#enum-FeatureName' | relative_url }}) \* features)

</div>

#### Returns


#### Arguments

* *features*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void ForceLoss([DeviceLostReason]({{ '/api/cpp.html#enum-DeviceLostReason' | relative_url }}) type, char const\* message)

</div>

#### Arguments

* *type*: 
* *message*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Adapter]({{ '/api/cpp.html#class-Adapter' | relative_url }}) GetAdapter()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

bool GetLimits([SupportedLimits]({{ '/api/cpp.html#structure-SupportedLimits' | relative_url }}) \* limits)

</div>

#### Returns


#### Arguments

* *limits*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Queue]({{ '/api/cpp.html#class-Queue' | relative_url }}) GetQueue()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

bool HasFeature([FeatureName]({{ '/api/cpp.html#enum-FeatureName' | relative_url }}) feature)

</div>

#### Returns


#### Arguments

* *feature*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void InjectError([ErrorType]({{ '/api/cpp.html#enum-ErrorType' | relative_url }}) type, char const\* message)

</div>

#### Arguments

* *type*: 
* *message*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

bool PopErrorScope([ErrorCallback]({{ '/api/cpp.html#function-pointer-ErrorCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Returns


#### Arguments

* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void PushErrorScope([ErrorFilter]({{ '/api/cpp.html#enum-ErrorFilter' | relative_url }}) filter)

</div>

#### Arguments

* *filter*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetDeviceLostCallback([DeviceLostCallback]({{ '/api/cpp.html#function-pointer-DeviceLostCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLoggingCallback([LoggingCallback]({{ '/api/cpp.html#function-pointer-LoggingCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetUncapturedErrorCallback([ErrorCallback]({{ '/api/cpp.html#function-pointer-ErrorCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void Tick()

</div>

</div>

</div>

<div class='object' markdown=1>

### class ExternalTexture {#class-ExternalTexture}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void Destroy()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

</div>

<div class='object' markdown=1>

### class Instance {#class-Instance}

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Surface]({{ '/api/cpp.html#class-Surface' | relative_url }}) CreateSurface([SurfaceDescriptor]({{ '/api/cpp.html#structure-SurfaceDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void ProcessEvents()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void RequestAdapter([RequestAdapterOptions]({{ '/api/cpp.html#structure-RequestAdapterOptions' | relative_url }}) const\* options, [RequestAdapterCallback]({{ '/api/cpp.html#function-pointer-RequestAdapterCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *options*: 
* *callback*: 
* *userdata*: 

</div>

</div>

<div class='object' markdown=1>

### class PipelineLayout {#class-PipelineLayout}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

</div>

<div class='object' markdown=1>

### class QuerySet {#class-QuerySet}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void Destroy()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t GetCount()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[QueryType]({{ '/api/cpp.html#enum-QueryType' | relative_url }}) GetType()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

</div>

<div class='object' markdown=1>

### class Queue {#class-Queue}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void CopyTextureForBrowser([ImageCopyTexture]({{ '/api/cpp.html#structure-ImageCopyTexture' | relative_url }}) const\* source, [ImageCopyTexture]({{ '/api/cpp.html#structure-ImageCopyTexture' | relative_url }}) const\* destination, [Extent3D]({{ '/api/cpp.html#structure-Extent3D' | relative_url }}) const\* copySize, [CopyTextureForBrowserOptions]({{ '/api/cpp.html#structure-CopyTextureForBrowserOptions' | relative_url }}) const\* options)

</div>

#### Arguments

* *source*: 
* *destination*: 
* *copySize*: 
* *options*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void OnSubmittedWorkDone(uint64_t signalValue, [QueueWorkDoneCallback]({{ '/api/cpp.html#function-pointer-QueueWorkDoneCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *signalValue*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void OnSubmittedWorkDone([QueueWorkDoneCallback]({{ '/api/cpp.html#function-pointer-QueueWorkDoneCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void Submit(uint32_t commandCount, [CommandBuffer]({{ '/api/cpp.html#class-CommandBuffer' | relative_url }}) const\* commands)

</div>

#### Arguments

* *commandCount*: 
* *commands*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void WriteBuffer([Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) buffer, uint64_t bufferOffset, void const\* data, size_t size)

</div>

#### Arguments

* *buffer*: 
* *bufferOffset*: 
* *data*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void WriteTexture([ImageCopyTexture]({{ '/api/cpp.html#structure-ImageCopyTexture' | relative_url }}) const\* destination, void const\* data, size_t dataSize, [TextureDataLayout]({{ '/api/cpp.html#structure-TextureDataLayout' | relative_url }}) const\* dataLayout, [Extent3D]({{ '/api/cpp.html#structure-Extent3D' | relative_url }}) const\* writeSize)

</div>

#### Arguments

* *destination*: 
* *data*: 
* *dataSize*: 
* *dataLayout*: 
* *writeSize*: 

</div>

</div>

<div class='object' markdown=1>

### class RenderBundle {#class-RenderBundle}

</div>

<div class='object' markdown=1>

### class RenderBundleEncoder {#class-RenderBundleEncoder}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void Draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)

</div>

#### Arguments

* *vertexCount*: 
* *instanceCount*: 
* *firstVertex*: 
* *firstInstance*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void DrawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance)

</div>

#### Arguments

* *indexCount*: 
* *instanceCount*: 
* *firstIndex*: 
* *baseVertex*: 
* *firstInstance*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void DrawIndexedIndirect([Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void DrawIndirect([Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[RenderBundle]({{ '/api/cpp.html#class-RenderBundle' | relative_url }}) Finish([RenderBundleDescriptor]({{ '/api/cpp.html#structure-RenderBundleDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void InsertDebugMarker(char const\* markerLabel)

</div>

#### Arguments

* *markerLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void PopDebugGroup()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void PushDebugGroup(char const\* groupLabel)

</div>

#### Arguments

* *groupLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetBindGroup(uint32_t groupIndex, [BindGroup]({{ '/api/cpp.html#class-BindGroup' | relative_url }}) group, uint32_t dynamicOffsetCount, uint32_t const\* dynamicOffsets)

</div>

#### Arguments

* *groupIndex*: 
* *group*: 
* *dynamicOffsetCount*: 
* *dynamicOffsets*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetIndexBuffer([Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) buffer, [IndexFormat]({{ '/api/cpp.html#enum-IndexFormat' | relative_url }}) format, uint64_t offset, uint64_t size)

</div>

#### Arguments

* *buffer*: 
* *format*: 
* *offset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetPipeline([RenderPipeline]({{ '/api/cpp.html#class-RenderPipeline' | relative_url }}) pipeline)

</div>

#### Arguments

* *pipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetVertexBuffer(uint32_t slot, [Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) buffer, uint64_t offset, uint64_t size)

</div>

#### Arguments

* *slot*: 
* *buffer*: 
* *offset*: 
* *size*: 

</div>

</div>

<div class='object' markdown=1>

### class RenderPassEncoder {#class-RenderPassEncoder}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void BeginOcclusionQuery(uint32_t queryIndex)

</div>

#### Arguments

* *queryIndex*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void BeginPipelineStatisticsQuery([QuerySet]({{ '/api/cpp.html#class-QuerySet' | relative_url }}) querySet, uint32_t queryIndex)

</div>

#### Arguments

* *querySet*: 
* *queryIndex*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void Draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)

</div>

#### Arguments

* *vertexCount*: 
* *instanceCount*: 
* *firstVertex*: 
* *firstInstance*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void DrawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance)

</div>

#### Arguments

* *indexCount*: 
* *instanceCount*: 
* *firstIndex*: 
* *baseVertex*: 
* *firstInstance*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void DrawIndexedIndirect([Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void DrawIndirect([Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void End()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void EndOcclusionQuery()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void EndPass()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void EndPipelineStatisticsQuery()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void ExecuteBundles(uint32_t bundlesCount, [RenderBundle]({{ '/api/cpp.html#class-RenderBundle' | relative_url }}) const\* bundles)

</div>

#### Arguments

* *bundlesCount*: 
* *bundles*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void InsertDebugMarker(char const\* markerLabel)

</div>

#### Arguments

* *markerLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void PopDebugGroup()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void PushDebugGroup(char const\* groupLabel)

</div>

#### Arguments

* *groupLabel*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetBindGroup(uint32_t groupIndex, [BindGroup]({{ '/api/cpp.html#class-BindGroup' | relative_url }}) group, uint32_t dynamicOffsetCount, uint32_t const\* dynamicOffsets)

</div>

#### Arguments

* *groupIndex*: 
* *group*: 
* *dynamicOffsetCount*: 
* *dynamicOffsets*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetBlendConstant([Color]({{ '/api/cpp.html#structure-Color' | relative_url }}) const\* color)

</div>

#### Arguments

* *color*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetIndexBuffer([Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) buffer, [IndexFormat]({{ '/api/cpp.html#enum-IndexFormat' | relative_url }}) format, uint64_t offset, uint64_t size)

</div>

#### Arguments

* *buffer*: 
* *format*: 
* *offset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetPipeline([RenderPipeline]({{ '/api/cpp.html#class-RenderPipeline' | relative_url }}) pipeline)

</div>

#### Arguments

* *pipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetScissorRect(uint32_t x, uint32_t y, uint32_t width, uint32_t height)

</div>

#### Arguments

* *x*: 
* *y*: 
* *width*: 
* *height*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetStencilReference(uint32_t reference)

</div>

#### Arguments

* *reference*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetVertexBuffer(uint32_t slot, [Buffer]({{ '/api/cpp.html#class-Buffer' | relative_url }}) buffer, uint64_t offset, uint64_t size)

</div>

#### Arguments

* *slot*: 
* *buffer*: 
* *offset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetViewport(float x, float y, float width, float height, float minDepth, float maxDepth)

</div>

#### Arguments

* *x*: 
* *y*: 
* *width*: 
* *height*: 
* *minDepth*: 
* *maxDepth*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void WriteTimestamp([QuerySet]({{ '/api/cpp.html#class-QuerySet' | relative_url }}) querySet, uint32_t queryIndex)

</div>

#### Arguments

* *querySet*: 
* *queryIndex*: 

</div>

</div>

<div class='object' markdown=1>

### class RenderPipeline {#class-RenderPipeline}

<div class='method' markdown=1>

<div class='signature' markdown=1>

[BindGroupLayout]({{ '/api/cpp.html#class-BindGroupLayout' | relative_url }}) GetBindGroupLayout(uint32_t groupIndex)

</div>

#### Returns


#### Arguments

* *groupIndex*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

</div>

<div class='object' markdown=1>

### class Sampler {#class-Sampler}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

</div>

<div class='object' markdown=1>

### class ShaderModule {#class-ShaderModule}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void GetCompilationInfo([CompilationInfoCallback]({{ '/api/cpp.html#function-pointer-CompilationInfoCallback' | relative_url }}) callback, void \* userdata)

</div>

#### Arguments

* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

</div>

<div class='object' markdown=1>

### class Surface {#class-Surface}

<div class='method' markdown=1>

<div class='signature' markdown=1>

[TextureFormat]({{ '/api/cpp.html#enum-TextureFormat' | relative_url }}) GetPreferredFormat([Adapter]({{ '/api/cpp.html#class-Adapter' | relative_url }}) adapter)

</div>

#### Returns


#### Arguments

* *adapter*: 

</div>

</div>

<div class='object' markdown=1>

### class SwapChain {#class-SwapChain}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void Configure([TextureFormat]({{ '/api/cpp.html#enum-TextureFormat' | relative_url }}) format, [TextureUsage]({{ '/api/cpp.html#bitmask-TextureUsage' | relative_url }}) allowedUsage, uint32_t width, uint32_t height)

</div>

#### Arguments

* *format*: 
* *allowedUsage*: 
* *width*: 
* *height*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[TextureView]({{ '/api/cpp.html#class-TextureView' | relative_url }}) GetCurrentTextureView()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void Present()

</div>

</div>

</div>

<div class='object' markdown=1>

### class Texture {#class-Texture}

<div class='method' markdown=1>

<div class='signature' markdown=1>

[TextureView]({{ '/api/cpp.html#class-TextureView' | relative_url }}) CreateView([TextureViewDescriptor]({{ '/api/cpp.html#structure-TextureViewDescriptor' | relative_url }}) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void Destroy()

</div>

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t GetDepthOrArrayLayers()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[TextureDimension]({{ '/api/cpp.html#enum-TextureDimension' | relative_url }}) GetDimension()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[TextureFormat]({{ '/api/cpp.html#enum-TextureFormat' | relative_url }}) GetFormat()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t GetHeight()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t GetMipLevelCount()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t GetSampleCount()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[TextureUsage]({{ '/api/cpp.html#bitmask-TextureUsage' | relative_url }}) GetUsage()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

uint32_t GetWidth()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

</div>

<div class='object' markdown=1>

### class TextureView {#class-TextureView}

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetLabel(char const\* label)

</div>

#### Arguments

* *label*: 

</div>

</div>

