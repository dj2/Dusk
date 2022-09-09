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

[Instance](cpp.html#class-Instance) CreateInstance([InstanceDescriptor](cpp.html#structure-InstanceDescriptor) const\* descriptor)
</div>

#### Returns

The created [Instance](cpp.html#class-Instance).

#### Arguments

* *descriptor*: The [InstanceDescriptor](cpp.html#structure-InstanceDescriptor) pointer. Maybe `nullptr` to create a default instance.

</div>

</div>

<div class='function' markdown=1>

### GetProcAddress {#function-GetProcAddress}

<div class='content' markdown=1>

Returns the function pointer for the requested WebGPU API method *procName*.

<div class='signature' markdown=1>

[Proc](cpp.html#function-pointer-Proc) GetProcAddress([Device](cpp.html#class-Device) device, char const\* procName)
</div>

#### Returns

The [Proc](cpp.html#function-pointer-Proc) function pointer if it exists, nullptr otherwise.

#### Arguments

* *device*: The [Device](cpp.html#class-Device) to retrieve the proc for
* *procName*: The name of the pointer to retrieve

</div>

</div>

## Function Pointers

<div class='function' markdown=1>

### BufferMapCallback {#function-pointer-BufferMapCallback}

<div class='content' markdown=1>

<div class='signature' markdown=1>

void (&#x2a;BufferMapCallback)([WGPUBufferMapAsyncStatus](c.html#enum-BufferMapAsyncStatus) status, void \* userdata)
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

void (&#x2a;CompilationInfoCallback)([WGPUCompilationInfoRequestStatus](c.html#enum-CompilationInfoRequestStatus) status, [WGPUCompilationInfo](c.html#structure-CompilationInfo) const\* compilationInfo, void \* userdata)
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

void (&#x2a;CreateComputePipelineAsyncCallback)([WGPUCreatePipelineAsyncStatus](c.html#enum-CreatePipelineAsyncStatus) status, [WGPUComputePipeline](c.html#class-ComputePipeline) pipeline, char const\* message, void \* userdata)
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

void (&#x2a;CreateRenderPipelineAsyncCallback)([WGPUCreatePipelineAsyncStatus](c.html#enum-CreatePipelineAsyncStatus) status, [WGPURenderPipeline](c.html#class-RenderPipeline) pipeline, char const\* message, void \* userdata)
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

void (&#x2a;DeviceLostCallback)([WGPUDeviceLostReason](c.html#enum-DeviceLostReason) reason, char const\* message, void \* userdata)
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

void (&#x2a;ErrorCallback)([WGPUErrorType](c.html#enum-ErrorType) type, char const\* message, void \* userdata)
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

void (&#x2a;LoggingCallback)([WGPULoggingType](c.html#enum-LoggingType) type, char const\* message, void \* userdata)
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

void (&#x2a;QueueWorkDoneCallback)([WGPUQueueWorkDoneStatus](c.html#enum-QueueWorkDoneStatus) status, void \* userdata)
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

void (&#x2a;RequestAdapterCallback)([WGPURequestAdapterStatus](c.html#enum-RequestAdapterStatus) status, [WGPUAdapter](c.html#class-Adapter) adapter, char const\* message, void \* userdata)
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

void (&#x2a;RequestDeviceCallback)([WGPURequestDeviceStatus](c.html#enum-RequestDeviceStatus) status, [WGPUDevice](c.html#class-Device) device, char const\* message, void \* userdata)
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
| [AdapterType](cpp.html#enum-AdapterType) adapterType |  | The type of the adapter |
| [BackendType](cpp.html#enum-BackendType) backendType |  | The backend platform used by the adapter |

### struct BindGroupDescriptor {#structure-BindGroupDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [BindGroupLayout](cpp.html#class-BindGroupLayout) layout |  |  |
| uint32_t entryCount |  |  |
| [BindGroupEntry](cpp.html#structure-BindGroupEntry) const\* entries |  |  |

### struct BindGroupEntry {#structure-BindGroupEntry}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| uint32_t binding |  |  |
| [Buffer](cpp.html#class-Buffer) buffer |  |  |
| uint64_t offset | `0` |  |
| uint64_t size |  |  |
| [Sampler](cpp.html#class-Sampler) sampler |  |  |
| [TextureView](cpp.html#class-TextureView) textureView |  |  |

#### Chainable Structures

 * [ExternalTextureBindingEntry](cpp.html#structure-ExternalTextureBindingEntry)

### struct BindGroupLayoutDescriptor {#structure-BindGroupLayoutDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| uint32_t entryCount |  |  |
| [BindGroupLayoutEntry](cpp.html#structure-BindGroupLayoutEntry) const\* entries |  |  |

### struct BindGroupLayoutEntry {#structure-BindGroupLayoutEntry}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| uint32_t binding |  |  |
| [ShaderStage](cpp.html#bitmask-ShaderStage) visibility |  |  |
| [BufferBindingLayout](cpp.html#structure-BufferBindingLayout) buffer |  |  |
| [SamplerBindingLayout](cpp.html#structure-SamplerBindingLayout) sampler |  |  |
| [TextureBindingLayout](cpp.html#structure-TextureBindingLayout) texture |  |  |
| [StorageTextureBindingLayout](cpp.html#structure-StorageTextureBindingLayout) storageTexture |  |  |

#### Chainable Structures

 * [ExternalTextureBindingLayout](cpp.html#structure-ExternalTextureBindingLayout)

### struct BlendComponent {#structure-BlendComponent}

| Members | Default | Description |
|:--------|:--------|:------------|
| [BlendOperation](cpp.html#enum-BlendOperation) operation | `BlendOperation::Add` |  |
| [BlendFactor](cpp.html#enum-BlendFactor) srcFactor | `BlendFactor::One` |  |
| [BlendFactor](cpp.html#enum-BlendFactor) dstFactor | `BlendFactor::Zero` |  |

### struct BlendState {#structure-BlendState}

| Members | Default | Description |
|:--------|:--------|:------------|
| [BlendComponent](cpp.html#structure-BlendComponent) color |  |  |
| [BlendComponent](cpp.html#structure-BlendComponent) alpha |  |  |

### struct BufferBindingLayout {#structure-BufferBindingLayout}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [BufferBindingType](cpp.html#enum-BufferBindingType) type | `BufferBindingType::Undefined` |  |
| bool hasDynamicOffset | `false` |  |
| uint64_t minBindingSize | `0` |  |

### struct BufferDescriptor {#structure-BufferDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [BufferUsage](cpp.html#bitmask-BufferUsage) usage |  |  |
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
| [TextureFormat](cpp.html#enum-TextureFormat) format |  |  |
| [BlendState](cpp.html#structure-BlendState) const\* blend |  |  |
| [ColorWriteMask](cpp.html#bitmask-ColorWriteMask) writeMask | `ColorWriteMask::All` |  |

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

 * [DawnEncoderInternalUsageDescriptor](cpp.html#structure-DawnEncoderInternalUsageDescriptor)

### struct CompilationInfo {#structure-CompilationInfo}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| uint32_t messageCount |  |  |
| [CompilationMessage](cpp.html#structure-CompilationMessage) const\* messages |  |  |

### struct CompilationMessage {#structure-CompilationMessage}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* message |  |  |
| [CompilationMessageType](cpp.html#enum-CompilationMessageType) type |  |  |
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
| [ComputePassTimestampWrite](cpp.html#structure-ComputePassTimestampWrite) const\* timestampWrites |  |  |

### struct ComputePassTimestampWrite {#structure-ComputePassTimestampWrite}

| Members | Default | Description |
|:--------|:--------|:------------|
| [QuerySet](cpp.html#class-QuerySet) querySet |  |  |
| uint32_t queryIndex |  |  |
| [ComputePassTimestampLocation](cpp.html#enum-ComputePassTimestampLocation) location |  |  |

### struct ComputePipelineDescriptor {#structure-ComputePipelineDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [PipelineLayout](cpp.html#class-PipelineLayout) layout |  |  |
| [ProgrammableStageDescriptor](cpp.html#structure-ProgrammableStageDescriptor) compute |  |  |

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
| [AlphaMode](cpp.html#enum-AlphaMode) srcAlphaMode | `AlphaMode::Unpremultiplied` |  |
| float const\* srcTransferFunctionParameters |  |  |
| float const\* conversionMatrix |  |  |
| float const\* dstTransferFunctionParameters |  |  |
| [AlphaMode](cpp.html#enum-AlphaMode) dstAlphaMode | `AlphaMode::Unpremultiplied` |  |
| bool internalUsage | `false` |  |

### struct DawnCacheDeviceDescriptor {#structure-DawnCacheDeviceDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::DawnCacheDeviceDescriptor` | Structure type |
| char const\* isolationKey | `""` |  |

#### Chain Parent Structures

 * [DeviceDescriptor](cpp.html#structure-DeviceDescriptor)

### struct DawnEncoderInternalUsageDescriptor {#structure-DawnEncoderInternalUsageDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::DawnEncoderInternalUsageDescriptor` | Structure type |
| bool useInternalUsages | `false` |  |

#### Chain Parent Structures

 * [CommandEncoderDescriptor](cpp.html#structure-CommandEncoderDescriptor)

### struct DawnInstanceDescriptor {#structure-DawnInstanceDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::DawnInstanceDescriptor` | Structure type |
| uint32_t additionalRuntimeSearchPathsCount | `0` |  |
| char const\*const\* additionalRuntimeSearchPaths |  |  |

#### Chain Parent Structures

 * [InstanceDescriptor](cpp.html#structure-InstanceDescriptor)

### struct DawnTextureInternalUsageDescriptor {#structure-DawnTextureInternalUsageDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::DawnTextureInternalUsageDescriptor` | Structure type |
| [TextureUsage](cpp.html#bitmask-TextureUsage) internalUsage | `TextureUsage::None` |  |

#### Chain Parent Structures

 * [TextureDescriptor](cpp.html#structure-TextureDescriptor)

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

 * [DeviceDescriptor](cpp.html#structure-DeviceDescriptor)

### struct DepthStencilState {#structure-DepthStencilState}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [TextureFormat](cpp.html#enum-TextureFormat) format |  |  |
| bool depthWriteEnabled | `false` |  |
| [CompareFunction](cpp.html#enum-CompareFunction) depthCompare | `CompareFunction::Always` |  |
| [StencilFaceState](cpp.html#structure-StencilFaceState) stencilFront |  |  |
| [StencilFaceState](cpp.html#structure-StencilFaceState) stencilBack |  |  |
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
| [FeatureName](cpp.html#enum-FeatureName) const\* requiredFeatures | `FeatureName::Nullptr` |  |
| [RequiredLimits](cpp.html#structure-RequiredLimits) const\* requiredLimits |  |  |
| [QueueDescriptor](cpp.html#structure-QueueDescriptor) defaultQueue |  |  |

#### Chainable Structures

 * [DawnTogglesDeviceDescriptor](cpp.html#structure-DawnTogglesDeviceDescriptor)
 * [DawnCacheDeviceDescriptor](cpp.html#structure-DawnCacheDeviceDescriptor)

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
| [ExternalTexture](cpp.html#class-ExternalTexture) externalTexture |  |  |

#### Chain Parent Structures

 * [BindGroupEntry](cpp.html#structure-BindGroupEntry)

### struct ExternalTextureBindingLayout {#structure-ExternalTextureBindingLayout}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::ExternalTextureBindingLayout` | Structure type |

#### Chain Parent Structures

 * [BindGroupLayoutEntry](cpp.html#structure-BindGroupLayoutEntry)

### struct ExternalTextureDescriptor {#structure-ExternalTextureDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [TextureView](cpp.html#class-TextureView) plane0 |  |  |
| [TextureView](cpp.html#class-TextureView) plane1 |  |  |
| bool doYuvToRgbConversionOnly | `false` |  |
| float const\* yuvToRgbConversionMatrix |  |  |
| float const\* srcTransferFunctionParameters |  |  |
| float const\* dstTransferFunctionParameters |  |  |
| float const\* gamutConversionMatrix |  |  |

### struct FragmentState {#structure-FragmentState}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [ShaderModule](cpp.html#class-ShaderModule) module |  |  |
| char const\* entryPoint |  |  |
| uint32_t constantCount | `0` |  |
| [ConstantEntry](cpp.html#structure-ConstantEntry) const\* constants |  |  |
| uint32_t targetCount |  |  |
| [ColorTargetState](cpp.html#structure-ColorTargetState) const\* targets |  |  |

### struct ImageCopyBuffer {#structure-ImageCopyBuffer}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [TextureDataLayout](cpp.html#structure-TextureDataLayout) layout |  |  |
| [Buffer](cpp.html#class-Buffer) buffer |  |  |

### struct ImageCopyTexture {#structure-ImageCopyTexture}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [Texture](cpp.html#class-Texture) texture |  |  |
| uint32_t mipLevel | `0` |  |
| [Origin3D](cpp.html#structure-Origin3D) origin |  |  |
| [TextureAspect](cpp.html#enum-TextureAspect) aspect | `TextureAspect::All` |  |

### struct InstanceDescriptor {#structure-InstanceDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |

#### Chainable Structures

 * [DawnInstanceDescriptor](cpp.html#structure-DawnInstanceDescriptor)

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
| [BindGroupLayout](cpp.html#class-BindGroupLayout) const\* bindGroupLayouts |  |  |

### struct PrimitiveDepthClipControl {#structure-PrimitiveDepthClipControl}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::PrimitiveDepthClipControl` | Structure type |
| bool unclippedDepth | `false` |  |

#### Chain Parent Structures

 * [PrimitiveState](cpp.html#structure-PrimitiveState)

### struct PrimitiveState {#structure-PrimitiveState}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [PrimitiveTopology](cpp.html#enum-PrimitiveTopology) topology | `PrimitiveTopology::TriangleList` |  |
| [IndexFormat](cpp.html#enum-IndexFormat) stripIndexFormat | `IndexFormat::Undefined` |  |
| [FrontFace](cpp.html#enum-FrontFace) frontFace | `FrontFace::CCW` |  |
| [CullMode](cpp.html#enum-CullMode) cullMode | `CullMode::None` |  |

#### Chainable Structures

 * [PrimitiveDepthClipControl](cpp.html#structure-PrimitiveDepthClipControl)

### struct ProgrammableStageDescriptor {#structure-ProgrammableStageDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [ShaderModule](cpp.html#class-ShaderModule) module |  |  |
| char const\* entryPoint |  |  |
| uint32_t constantCount | `0` |  |
| [ConstantEntry](cpp.html#structure-ConstantEntry) const\* constants |  |  |

### struct QuerySetDescriptor {#structure-QuerySetDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [QueryType](cpp.html#enum-QueryType) type |  |  |
| uint32_t count |  |  |
| [PipelineStatisticName](cpp.html#enum-PipelineStatisticName) const\* pipelineStatistics |  |  |
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
| [TextureFormat](cpp.html#enum-TextureFormat) const\* colorFormats |  |  |
| [TextureFormat](cpp.html#enum-TextureFormat) depthStencilFormat | `TextureFormat::Undefined` |  |
| uint32_t sampleCount | `1` |  |
| bool depthReadOnly | `false` |  |
| bool stencilReadOnly | `false` |  |

### struct RenderPassColorAttachment {#structure-RenderPassColorAttachment}

| Members | Default | Description |
|:--------|:--------|:------------|
| [TextureView](cpp.html#class-TextureView) view |  |  |
| [TextureView](cpp.html#class-TextureView) resolveTarget |  |  |
| [LoadOp](cpp.html#enum-LoadOp) loadOp |  |  |
| [StoreOp](cpp.html#enum-StoreOp) storeOp |  |  |
| [Color](cpp.html#structure-Color) clearColor | `Color::{NAN,NAN,NAN,NAN}` |  |
| [Color](cpp.html#structure-Color) clearValue |  |  |

### struct RenderPassDepthStencilAttachment {#structure-RenderPassDepthStencilAttachment}

| Members | Default | Description |
|:--------|:--------|:------------|
| [TextureView](cpp.html#class-TextureView) view |  |  |
| [LoadOp](cpp.html#enum-LoadOp) depthLoadOp | `LoadOp::Undefined` |  |
| [StoreOp](cpp.html#enum-StoreOp) depthStoreOp | `StoreOp::Undefined` |  |
| float clearDepth | `NAN` |  |
| float depthClearValue | `0` |  |
| bool depthReadOnly | `false` |  |
| [LoadOp](cpp.html#enum-LoadOp) stencilLoadOp | `LoadOp::Undefined` |  |
| [StoreOp](cpp.html#enum-StoreOp) stencilStoreOp | `StoreOp::Undefined` |  |
| uint32_t clearStencil | `0` |  |
| uint32_t stencilClearValue | `0` |  |
| bool stencilReadOnly | `false` |  |

### struct RenderPassDescriptor {#structure-RenderPassDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| uint32_t colorAttachmentCount |  |  |
| [RenderPassColorAttachment](cpp.html#structure-RenderPassColorAttachment) const\* colorAttachments |  |  |
| [RenderPassDepthStencilAttachment](cpp.html#structure-RenderPassDepthStencilAttachment) const\* depthStencilAttachment |  |  |
| [QuerySet](cpp.html#class-QuerySet) occlusionQuerySet |  |  |
| uint32_t timestampWriteCount | `0` |  |
| [RenderPassTimestampWrite](cpp.html#structure-RenderPassTimestampWrite) const\* timestampWrites |  |  |

#### Chainable Structures

 * [RenderPassDescriptorMaxDrawCount](cpp.html#structure-RenderPassDescriptorMaxDrawCount)

### struct RenderPassDescriptorMaxDrawCount {#structure-RenderPassDescriptorMaxDrawCount}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::RenderPassDescriptorMaxDrawCount` | Structure type |
| uint64_t maxDrawCount | `50000000` |  |

#### Chain Parent Structures

 * [RenderPassDescriptor](cpp.html#structure-RenderPassDescriptor)

### struct RenderPassTimestampWrite {#structure-RenderPassTimestampWrite}

| Members | Default | Description |
|:--------|:--------|:------------|
| [QuerySet](cpp.html#class-QuerySet) querySet |  |  |
| uint32_t queryIndex |  |  |
| [RenderPassTimestampLocation](cpp.html#enum-RenderPassTimestampLocation) location |  |  |

### struct RenderPipelineDescriptor {#structure-RenderPipelineDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [PipelineLayout](cpp.html#class-PipelineLayout) layout |  |  |
| [VertexState](cpp.html#structure-VertexState) vertex |  |  |
| [PrimitiveState](cpp.html#structure-PrimitiveState) primitive |  |  |
| [DepthStencilState](cpp.html#structure-DepthStencilState) const\* depthStencil |  |  |
| [MultisampleState](cpp.html#structure-MultisampleState) multisample |  |  |
| [FragmentState](cpp.html#structure-FragmentState) const\* fragment |  |  |

### struct RequestAdapterOptions {#structure-RequestAdapterOptions}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [Surface](cpp.html#class-Surface) compatibleSurface |  |  |
| [PowerPreference](cpp.html#enum-PowerPreference) powerPreference | `PowerPreference::Undefined` |  |
| bool forceFallbackAdapter | `false` |  |

### struct RequiredLimits {#structure-RequiredLimits}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [Limits](cpp.html#structure-Limits) limits |  |  |

### struct SamplerBindingLayout {#structure-SamplerBindingLayout}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [SamplerBindingType](cpp.html#enum-SamplerBindingType) type | `SamplerBindingType::Undefined` |  |

### struct SamplerDescriptor {#structure-SamplerDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [AddressMode](cpp.html#enum-AddressMode) addressModeU | `AddressMode::ClampToEdge` |  |
| [AddressMode](cpp.html#enum-AddressMode) addressModeV | `AddressMode::ClampToEdge` |  |
| [AddressMode](cpp.html#enum-AddressMode) addressModeW | `AddressMode::ClampToEdge` |  |
| [FilterMode](cpp.html#enum-FilterMode) magFilter | `FilterMode::Nearest` |  |
| [FilterMode](cpp.html#enum-FilterMode) minFilter | `FilterMode::Nearest` |  |
| [FilterMode](cpp.html#enum-FilterMode) mipmapFilter | `FilterMode::Nearest` |  |
| [MipmapFilterMode](cpp.html#enum-MipmapFilterMode) mipmapFilter | `MipmapFilterMode::Nearest` |  |
| float lodMinClamp | `0.0f` |  |
| float lodMaxClamp | `1000.0f` |  |
| [CompareFunction](cpp.html#enum-CompareFunction) compare | `CompareFunction::Undefined` |  |
| uint16_t maxAnisotropy | `1` |  |

### struct ShaderModuleSPIRVDescriptor {#structure-ShaderModuleSPIRVDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::ShaderModuleSPIRVDescriptor` | Structure type |
| uint32_t codeSize |  |  |
| uint32_t const\* code |  |  |

#### Chain Parent Structures

 * [ShaderModuleDescriptor](cpp.html#structure-ShaderModuleDescriptor)

### struct ShaderModuleWGSLDescriptor {#structure-ShaderModuleWGSLDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::ShaderModuleWGSLDescriptor` | Structure type |
| char const\* source |  |  |
| char const\* code |  |  |

#### Chain Parent Structures

 * [ShaderModuleDescriptor](cpp.html#structure-ShaderModuleDescriptor)

### struct ShaderModuleCompilationHint {#structure-ShaderModuleCompilationHint}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* entryPoint |  |  |
| [PipelineLayout](cpp.html#class-PipelineLayout) layout |  |  |

### struct ShaderModuleDescriptor {#structure-ShaderModuleDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| uint32_t hintCount | `0` |  |
| [ShaderModuleCompilationHint](cpp.html#structure-ShaderModuleCompilationHint) const\* hints |  |  |

#### Chainable Structures

 * [ShaderModuleSPIRVDescriptor](cpp.html#structure-ShaderModuleSPIRVDescriptor)
 * [ShaderModuleWGSLDescriptor](cpp.html#structure-ShaderModuleWGSLDescriptor)

### struct StencilFaceState {#structure-StencilFaceState}

| Members | Default | Description |
|:--------|:--------|:------------|
| [CompareFunction](cpp.html#enum-CompareFunction) compare | `CompareFunction::Always` |  |
| [StencilOperation](cpp.html#enum-StencilOperation) failOp | `StencilOperation::Keep` |  |
| [StencilOperation](cpp.html#enum-StencilOperation) depthFailOp | `StencilOperation::Keep` |  |
| [StencilOperation](cpp.html#enum-StencilOperation) passOp | `StencilOperation::Keep` |  |

### struct StorageTextureBindingLayout {#structure-StorageTextureBindingLayout}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [StorageTextureAccess](cpp.html#enum-StorageTextureAccess) access | `StorageTextureAccess::Undefined` |  |
| [TextureFormat](cpp.html#enum-TextureFormat) format | `TextureFormat::Undefined` |  |
| [TextureViewDimension](cpp.html#enum-TextureViewDimension) viewDimension | `TextureViewDimension::Undefined` |  |

### struct SupportedLimits {#structure-SupportedLimits}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStructOut const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [Limits](cpp.html#structure-Limits) limits |  |  |

### struct SurfaceDescriptor {#structure-SurfaceDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |

#### Chainable Structures

 * [SurfaceDescriptorFromAndroidNativeWindow](cpp.html#structure-SurfaceDescriptorFromAndroidNativeWindow)
 * [SurfaceDescriptorFromCanvasHTMLSelector](cpp.html#structure-SurfaceDescriptorFromCanvasHTMLSelector)
 * [SurfaceDescriptorFromMetalLayer](cpp.html#structure-SurfaceDescriptorFromMetalLayer)
 * [SurfaceDescriptorFromWindowsHWND](cpp.html#structure-SurfaceDescriptorFromWindowsHWND)
 * [SurfaceDescriptorFromXcbWindow](cpp.html#structure-SurfaceDescriptorFromXcbWindow)
 * [SurfaceDescriptorFromXlibWindow](cpp.html#structure-SurfaceDescriptorFromXlibWindow)
 * [SurfaceDescriptorFromWaylandSurface](cpp.html#structure-SurfaceDescriptorFromWaylandSurface)
 * [SurfaceDescriptorFromWindowsCoreWindow](cpp.html#structure-SurfaceDescriptorFromWindowsCoreWindow)
 * [SurfaceDescriptorFromWindowsSwapChainPanel](cpp.html#structure-SurfaceDescriptorFromWindowsSwapChainPanel)

### struct SurfaceDescriptorFromAndroidNativeWindow {#structure-SurfaceDescriptorFromAndroidNativeWindow}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromAndroidNativeWindow` | Structure type |
| void \* window |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor](cpp.html#structure-SurfaceDescriptor)

### struct SurfaceDescriptorFromCanvasHTMLSelector {#structure-SurfaceDescriptorFromCanvasHTMLSelector}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromCanvasHTMLSelector` | Structure type |
| char const\* selector |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor](cpp.html#structure-SurfaceDescriptor)

### struct SurfaceDescriptorFromMetalLayer {#structure-SurfaceDescriptorFromMetalLayer}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromMetalLayer` | Structure type |
| void \* layer |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor](cpp.html#structure-SurfaceDescriptor)

### struct SurfaceDescriptorFromWaylandSurface {#structure-SurfaceDescriptorFromWaylandSurface}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromWaylandSurface` | Structure type |
| void \* display |  |  |
| void \* surface |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor](cpp.html#structure-SurfaceDescriptor)

### struct SurfaceDescriptorFromWindowsHWND {#structure-SurfaceDescriptorFromWindowsHWND}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromWindowsHWND` | Structure type |
| void \* hinstance |  |  |
| void \* hwnd |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor](cpp.html#structure-SurfaceDescriptor)

### struct SurfaceDescriptorFromWindowsCoreWindow {#structure-SurfaceDescriptorFromWindowsCoreWindow}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromWindowsCoreWindow` | Structure type |
| void \* coreWindow |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor](cpp.html#structure-SurfaceDescriptor)

### struct SurfaceDescriptorFromWindowsSwapChainPanel {#structure-SurfaceDescriptorFromWindowsSwapChainPanel}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromWindowsSwapChainPanel` | Structure type |
| void \* swapChainPanel |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor](cpp.html#structure-SurfaceDescriptor)

### struct SurfaceDescriptorFromXcbWindow {#structure-SurfaceDescriptorFromXcbWindow}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromXcbWindow` | Structure type |
| void \* connection |  |  |
| uint32_t window |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor](cpp.html#structure-SurfaceDescriptor)

### struct SurfaceDescriptorFromXlibWindow {#structure-SurfaceDescriptorFromXlibWindow}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| `SType stype` | `SType::SurfaceDescriptorFromXlibWindow` | Structure type |
| void \* display |  |  |
| uint32_t window |  |  |

#### Chain Parent Structures

 * [SurfaceDescriptor](cpp.html#structure-SurfaceDescriptor)

### struct SwapChainDescriptor {#structure-SwapChainDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [TextureUsage](cpp.html#bitmask-TextureUsage) usage |  |  |
| [TextureFormat](cpp.html#enum-TextureFormat) format |  |  |
| uint32_t width |  |  |
| uint32_t height |  |  |
| [PresentMode](cpp.html#enum-PresentMode) presentMode |  |  |
| uint64_t implementation | `0` |  |

### struct TextureBindingLayout {#structure-TextureBindingLayout}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [TextureSampleType](cpp.html#enum-TextureSampleType) sampleType | `TextureSampleType::Undefined` |  |
| [TextureViewDimension](cpp.html#enum-TextureViewDimension) viewDimension | `TextureViewDimension::Undefined` |  |
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
| [TextureUsage](cpp.html#bitmask-TextureUsage) usage |  |  |
| [TextureDimension](cpp.html#enum-TextureDimension) dimension | `TextureDimension::2D` |  |
| [Extent3D](cpp.html#structure-Extent3D) size |  |  |
| [TextureFormat](cpp.html#enum-TextureFormat) format |  |  |
| uint32_t mipLevelCount | `1` |  |
| uint32_t sampleCount | `1` |  |
| uint32_t viewFormatCount | `0` |  |
| [TextureFormat](cpp.html#enum-TextureFormat) const\* viewFormats |  |  |

#### Chainable Structures

 * [DawnTextureInternalUsageDescriptor](cpp.html#structure-DawnTextureInternalUsageDescriptor)

### struct TextureViewDescriptor {#structure-TextureViewDescriptor}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| char const\* label |  |  |
| [TextureFormat](cpp.html#enum-TextureFormat) format | `TextureFormat::Undefined` |  |
| [TextureViewDimension](cpp.html#enum-TextureViewDimension) dimension | `TextureViewDimension::Undefined` |  |
| uint32_t baseMipLevel | `0` |  |
| uint32_t mipLevelCount | `WGPU_MIP_LEVEL_COUNT_UNDEFINED` |  |
| uint32_t baseArrayLayer | `0` |  |
| uint32_t arrayLayerCount | `WGPU_ARRAY_LAYER_COUNT_UNDEFINED` |  |
| [TextureAspect](cpp.html#enum-TextureAspect) aspect | `TextureAspect::All` |  |

### struct VertexAttribute {#structure-VertexAttribute}

| Members | Default | Description |
|:--------|:--------|:------------|
| [VertexFormat](cpp.html#enum-VertexFormat) format |  |  |
| uint64_t offset |  |  |
| uint32_t shaderLocation |  |  |

### struct VertexBufferLayout {#structure-VertexBufferLayout}

| Members | Default | Description |
|:--------|:--------|:------------|
| uint64_t arrayStride |  |  |
| [VertexStepMode](cpp.html#enum-VertexStepMode) stepMode | `VertexStepMode::Vertex` |  |
| uint32_t attributeCount |  |  |
| [VertexAttribute](cpp.html#structure-VertexAttribute) const\* attributes |  |  |

### struct VertexState {#structure-VertexState}

| Members | Default | Description |
|:--------|:--------|:------------|
| `ChainedStruct const* nextInChain` | `nullptr` | Pointer to next chained structure. Maybe `nullptr`. |
| [ShaderModule](cpp.html#class-ShaderModule) module |  |  |
| char const\* entryPoint |  |  |
| uint32_t constantCount | `0` |  |
| [ConstantEntry](cpp.html#structure-ConstantEntry) const\* constants |  |  |
| uint32_t bufferCount | `0` |  |
| [VertexBufferLayout](cpp.html#structure-VertexBufferLayout) const\* buffers |  |  |

## Classes

<div class='object' markdown=1>

### class Adapter {#class-Adapter}

An *adapter* identifies an implemention of WebGPU on the system.

See [Adapters](https://webgpu.dev/#adapters) for more information.

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Device](cpp.html#class-Device) CreateDevice([DeviceDescriptor](cpp.html#structure-DeviceDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

size_t EnumerateFeatures([FeatureName](cpp.html#enum-FeatureName) \* features)

</div>

#### Returns


#### Arguments

* *features*: 

</div>

<div class='method' markdown=1>

Retrieves the limits which can be used with this adapter.

<div class='signature' markdown=1>

bool GetLimits([SupportedLimits](cpp.html#structure-SupportedLimits) \* limits)

</div>

#### Returns

Returns true if the limits were successfully retrieved.
#### Arguments

* *limits*: The [SupportedLimits](cpp.html#structure-SupportedLimits) object to populate. Must not be nullptr.

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void GetProperties([AdapterProperties](cpp.html#structure-AdapterProperties) \* properties)

</div>

#### Arguments

* *properties*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

bool HasFeature([FeatureName](cpp.html#enum-FeatureName) feature)

</div>

#### Returns


#### Arguments

* *feature*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void RequestDevice([DeviceDescriptor](cpp.html#structure-DeviceDescriptor) const\* descriptor, [RequestDeviceCallback](cpp.html#function-pointer-RequestDeviceCallback) callback, void \* userdata)

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

[BufferUsage](cpp.html#bitmask-BufferUsage) GetUsage()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void MapAsync([MapMode](cpp.html#bitmask-MapMode) mode, size_t offset, size_t size, [BufferMapCallback](cpp.html#function-pointer-BufferMapCallback) callback, void \* userdata)

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

[ComputePassEncoder](cpp.html#class-ComputePassEncoder) BeginComputePass([ComputePassDescriptor](cpp.html#structure-ComputePassDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[RenderPassEncoder](cpp.html#class-RenderPassEncoder) BeginRenderPass([RenderPassDescriptor](cpp.html#structure-RenderPassDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void ClearBuffer([Buffer](cpp.html#class-Buffer) buffer, uint64_t offset, uint64_t size)

</div>

#### Arguments

* *buffer*: 
* *offset*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void CopyBufferToBuffer([Buffer](cpp.html#class-Buffer) source, uint64_t sourceOffset, [Buffer](cpp.html#class-Buffer) destination, uint64_t destinationOffset, uint64_t size)

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

void CopyBufferToTexture([ImageCopyBuffer](cpp.html#structure-ImageCopyBuffer) const\* source, [ImageCopyTexture](cpp.html#structure-ImageCopyTexture) const\* destination, [Extent3D](cpp.html#structure-Extent3D) const\* copySize)

</div>

#### Arguments

* *source*: 
* *destination*: 
* *copySize*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void CopyTextureToBuffer([ImageCopyTexture](cpp.html#structure-ImageCopyTexture) const\* source, [ImageCopyBuffer](cpp.html#structure-ImageCopyBuffer) const\* destination, [Extent3D](cpp.html#structure-Extent3D) const\* copySize)

</div>

#### Arguments

* *source*: 
* *destination*: 
* *copySize*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void CopyTextureToTexture([ImageCopyTexture](cpp.html#structure-ImageCopyTexture) const\* source, [ImageCopyTexture](cpp.html#structure-ImageCopyTexture) const\* destination, [Extent3D](cpp.html#structure-Extent3D) const\* copySize)

</div>

#### Arguments

* *source*: 
* *destination*: 
* *copySize*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void CopyTextureToTextureInternal([ImageCopyTexture](cpp.html#structure-ImageCopyTexture) const\* source, [ImageCopyTexture](cpp.html#structure-ImageCopyTexture) const\* destination, [Extent3D](cpp.html#structure-Extent3D) const\* copySize)

</div>

#### Arguments

* *source*: 
* *destination*: 
* *copySize*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[CommandBuffer](cpp.html#class-CommandBuffer) Finish([CommandBufferDescriptor](cpp.html#structure-CommandBufferDescriptor) const\* descriptor)

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

void ResolveQuerySet([QuerySet](cpp.html#class-QuerySet) querySet, uint32_t firstQuery, uint32_t queryCount, [Buffer](cpp.html#class-Buffer) destination, uint64_t destinationOffset)

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

void WriteBuffer([Buffer](cpp.html#class-Buffer) buffer, uint64_t bufferOffset, uint8_t const\* data, uint64_t size)

</div>

#### Arguments

* *buffer*: 
* *bufferOffset*: 
* *data*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void WriteTimestamp([QuerySet](cpp.html#class-QuerySet) querySet, uint32_t queryIndex)

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

void BeginPipelineStatisticsQuery([QuerySet](cpp.html#class-QuerySet) querySet, uint32_t queryIndex)

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

void DispatchIndirect([Buffer](cpp.html#class-Buffer) indirectBuffer, uint64_t indirectOffset)

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

void DispatchWorkgroupsIndirect([Buffer](cpp.html#class-Buffer) indirectBuffer, uint64_t indirectOffset)

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

void SetBindGroup(uint32_t groupIndex, [BindGroup](cpp.html#class-BindGroup) group, uint32_t dynamicOffsetCount, uint32_t const\* dynamicOffsets)

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

void SetPipeline([ComputePipeline](cpp.html#class-ComputePipeline) pipeline)

</div>

#### Arguments

* *pipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void WriteTimestamp([QuerySet](cpp.html#class-QuerySet) querySet, uint32_t queryIndex)

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

[BindGroupLayout](cpp.html#class-BindGroupLayout) GetBindGroupLayout(uint32_t groupIndex)

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

[BindGroup](cpp.html#class-BindGroup) CreateBindGroup([BindGroupDescriptor](cpp.html#structure-BindGroupDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[BindGroupLayout](cpp.html#class-BindGroupLayout) CreateBindGroupLayout([BindGroupLayoutDescriptor](cpp.html#structure-BindGroupLayoutDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Buffer](cpp.html#class-Buffer) CreateBuffer([BufferDescriptor](cpp.html#structure-BufferDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[CommandEncoder](cpp.html#class-CommandEncoder) CreateCommandEncoder([CommandEncoderDescriptor](cpp.html#structure-CommandEncoderDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[ComputePipeline](cpp.html#class-ComputePipeline) CreateComputePipeline([ComputePipelineDescriptor](cpp.html#structure-ComputePipelineDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void CreateComputePipelineAsync([ComputePipelineDescriptor](cpp.html#structure-ComputePipelineDescriptor) const\* descriptor, [CreateComputePipelineAsyncCallback](cpp.html#function-pointer-CreateComputePipelineAsyncCallback) callback, void \* userdata)

</div>

#### Arguments

* *descriptor*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Buffer](cpp.html#class-Buffer) CreateErrorBuffer()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[ExternalTexture](cpp.html#class-ExternalTexture) CreateErrorExternalTexture()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Texture](cpp.html#class-Texture) CreateErrorTexture([TextureDescriptor](cpp.html#structure-TextureDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[ExternalTexture](cpp.html#class-ExternalTexture) CreateExternalTexture([ExternalTextureDescriptor](cpp.html#structure-ExternalTextureDescriptor) const\* externalTextureDescriptor)

</div>

#### Returns


#### Arguments

* *externalTextureDescriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[PipelineLayout](cpp.html#class-PipelineLayout) CreatePipelineLayout([PipelineLayoutDescriptor](cpp.html#structure-PipelineLayoutDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[QuerySet](cpp.html#class-QuerySet) CreateQuerySet([QuerySetDescriptor](cpp.html#structure-QuerySetDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[RenderBundleEncoder](cpp.html#class-RenderBundleEncoder) CreateRenderBundleEncoder([RenderBundleEncoderDescriptor](cpp.html#structure-RenderBundleEncoderDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[RenderPipeline](cpp.html#class-RenderPipeline) CreateRenderPipeline([RenderPipelineDescriptor](cpp.html#structure-RenderPipelineDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void CreateRenderPipelineAsync([RenderPipelineDescriptor](cpp.html#structure-RenderPipelineDescriptor) const\* descriptor, [CreateRenderPipelineAsyncCallback](cpp.html#function-pointer-CreateRenderPipelineAsyncCallback) callback, void \* userdata)

</div>

#### Arguments

* *descriptor*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Sampler](cpp.html#class-Sampler) CreateSampler([SamplerDescriptor](cpp.html#structure-SamplerDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[ShaderModule](cpp.html#class-ShaderModule) CreateShaderModule([ShaderModuleDescriptor](cpp.html#structure-ShaderModuleDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[SwapChain](cpp.html#class-SwapChain) CreateSwapChain([Surface](cpp.html#class-Surface) surface, [SwapChainDescriptor](cpp.html#structure-SwapChainDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *surface*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[SwapChain](cpp.html#class-SwapChain) CreateSwapChain([Surface](cpp.html#class-Surface) surface, [SwapChainDescriptor](cpp.html#structure-SwapChainDescriptor) const\* descriptor)

</div>

#### Returns


#### Arguments

* *surface*: 
* *descriptor*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Texture](cpp.html#class-Texture) CreateTexture([TextureDescriptor](cpp.html#structure-TextureDescriptor) const\* descriptor)

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

size_t EnumerateFeatures([FeatureName](cpp.html#enum-FeatureName) \* features)

</div>

#### Returns


#### Arguments

* *features*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void ForceLoss([DeviceLostReason](cpp.html#enum-DeviceLostReason) type, char const\* message)

</div>

#### Arguments

* *type*: 
* *message*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Adapter](cpp.html#class-Adapter) GetAdapter()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

bool GetLimits([SupportedLimits](cpp.html#structure-SupportedLimits) \* limits)

</div>

#### Returns


#### Arguments

* *limits*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[Queue](cpp.html#class-Queue) GetQueue()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

bool HasFeature([FeatureName](cpp.html#enum-FeatureName) feature)

</div>

#### Returns


#### Arguments

* *feature*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void InjectError([ErrorType](cpp.html#enum-ErrorType) type, char const\* message)

</div>

#### Arguments

* *type*: 
* *message*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

bool PopErrorScope([ErrorCallback](cpp.html#function-pointer-ErrorCallback) callback, void \* userdata)

</div>

#### Returns


#### Arguments

* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void PushErrorScope([ErrorFilter](cpp.html#enum-ErrorFilter) filter)

</div>

#### Arguments

* *filter*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetDeviceLostCallback([DeviceLostCallback](cpp.html#function-pointer-DeviceLostCallback) callback, void \* userdata)

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

void SetLoggingCallback([LoggingCallback](cpp.html#function-pointer-LoggingCallback) callback, void \* userdata)

</div>

#### Arguments

* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetUncapturedErrorCallback([ErrorCallback](cpp.html#function-pointer-ErrorCallback) callback, void \* userdata)

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

[Surface](cpp.html#class-Surface) CreateSurface([SurfaceDescriptor](cpp.html#structure-SurfaceDescriptor) const\* descriptor)

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

void RequestAdapter([RequestAdapterOptions](cpp.html#structure-RequestAdapterOptions) const\* options, [RequestAdapterCallback](cpp.html#function-pointer-RequestAdapterCallback) callback, void \* userdata)

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

[QueryType](cpp.html#enum-QueryType) GetType()

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

void CopyTextureForBrowser([ImageCopyTexture](cpp.html#structure-ImageCopyTexture) const\* source, [ImageCopyTexture](cpp.html#structure-ImageCopyTexture) const\* destination, [Extent3D](cpp.html#structure-Extent3D) const\* copySize, [CopyTextureForBrowserOptions](cpp.html#structure-CopyTextureForBrowserOptions) const\* options)

</div>

#### Arguments

* *source*: 
* *destination*: 
* *copySize*: 
* *options*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void OnSubmittedWorkDone(uint64_t signalValue, [QueueWorkDoneCallback](cpp.html#function-pointer-QueueWorkDoneCallback) callback, void \* userdata)

</div>

#### Arguments

* *signalValue*: 
* *callback*: 
* *userdata*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void OnSubmittedWorkDone([QueueWorkDoneCallback](cpp.html#function-pointer-QueueWorkDoneCallback) callback, void \* userdata)

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

void Submit(uint32_t commandCount, [CommandBuffer](cpp.html#class-CommandBuffer) const\* commands)

</div>

#### Arguments

* *commandCount*: 
* *commands*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void WriteBuffer([Buffer](cpp.html#class-Buffer) buffer, uint64_t bufferOffset, void const\* data, size_t size)

</div>

#### Arguments

* *buffer*: 
* *bufferOffset*: 
* *data*: 
* *size*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void WriteTexture([ImageCopyTexture](cpp.html#structure-ImageCopyTexture) const\* destination, void const\* data, size_t dataSize, [TextureDataLayout](cpp.html#structure-TextureDataLayout) const\* dataLayout, [Extent3D](cpp.html#structure-Extent3D) const\* writeSize)

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

void DrawIndexedIndirect([Buffer](cpp.html#class-Buffer) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void DrawIndirect([Buffer](cpp.html#class-Buffer) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[RenderBundle](cpp.html#class-RenderBundle) Finish([RenderBundleDescriptor](cpp.html#structure-RenderBundleDescriptor) const\* descriptor)

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

void SetBindGroup(uint32_t groupIndex, [BindGroup](cpp.html#class-BindGroup) group, uint32_t dynamicOffsetCount, uint32_t const\* dynamicOffsets)

</div>

#### Arguments

* *groupIndex*: 
* *group*: 
* *dynamicOffsetCount*: 
* *dynamicOffsets*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetIndexBuffer([Buffer](cpp.html#class-Buffer) buffer, [IndexFormat](cpp.html#enum-IndexFormat) format, uint64_t offset, uint64_t size)

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

void SetPipeline([RenderPipeline](cpp.html#class-RenderPipeline) pipeline)

</div>

#### Arguments

* *pipeline*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetVertexBuffer(uint32_t slot, [Buffer](cpp.html#class-Buffer) buffer, uint64_t offset, uint64_t size)

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

void BeginPipelineStatisticsQuery([QuerySet](cpp.html#class-QuerySet) querySet, uint32_t queryIndex)

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

void DrawIndexedIndirect([Buffer](cpp.html#class-Buffer) indirectBuffer, uint64_t indirectOffset)

</div>

#### Arguments

* *indirectBuffer*: 
* *indirectOffset*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void DrawIndirect([Buffer](cpp.html#class-Buffer) indirectBuffer, uint64_t indirectOffset)

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

void ExecuteBundles(uint32_t bundlesCount, [RenderBundle](cpp.html#class-RenderBundle) const\* bundles)

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

void SetBindGroup(uint32_t groupIndex, [BindGroup](cpp.html#class-BindGroup) group, uint32_t dynamicOffsetCount, uint32_t const\* dynamicOffsets)

</div>

#### Arguments

* *groupIndex*: 
* *group*: 
* *dynamicOffsetCount*: 
* *dynamicOffsets*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetBlendConstant([Color](cpp.html#structure-Color) const\* color)

</div>

#### Arguments

* *color*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

void SetIndexBuffer([Buffer](cpp.html#class-Buffer) buffer, [IndexFormat](cpp.html#enum-IndexFormat) format, uint64_t offset, uint64_t size)

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

void SetPipeline([RenderPipeline](cpp.html#class-RenderPipeline) pipeline)

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

void SetVertexBuffer(uint32_t slot, [Buffer](cpp.html#class-Buffer) buffer, uint64_t offset, uint64_t size)

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

void WriteTimestamp([QuerySet](cpp.html#class-QuerySet) querySet, uint32_t queryIndex)

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

[BindGroupLayout](cpp.html#class-BindGroupLayout) GetBindGroupLayout(uint32_t groupIndex)

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

void GetCompilationInfo([CompilationInfoCallback](cpp.html#function-pointer-CompilationInfoCallback) callback, void \* userdata)

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

[TextureFormat](cpp.html#enum-TextureFormat) GetPreferredFormat([Adapter](cpp.html#class-Adapter) adapter)

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

void Configure([TextureFormat](cpp.html#enum-TextureFormat) format, [TextureUsage](cpp.html#bitmask-TextureUsage) allowedUsage, uint32_t width, uint32_t height)

</div>

#### Arguments

* *format*: 
* *allowedUsage*: 
* *width*: 
* *height*: 

</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[TextureView](cpp.html#class-TextureView) GetCurrentTextureView()

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

[TextureView](cpp.html#class-TextureView) CreateView([TextureViewDescriptor](cpp.html#structure-TextureViewDescriptor) const\* descriptor)

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

[TextureDimension](cpp.html#enum-TextureDimension) GetDimension()

</div>

#### Returns


</div>

<div class='method' markdown=1>

<div class='signature' markdown=1>

[TextureFormat](cpp.html#enum-TextureFormat) GetFormat()

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

[TextureUsage](cpp.html#bitmask-TextureUsage) GetUsage()

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

