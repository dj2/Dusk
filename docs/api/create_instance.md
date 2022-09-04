---
layout: page
title: Create Instance
parent: API Documentation
nav_order: 2000
---

# Create Instance
Creates a new [Instance](./instance.md) of the WebGPU system.

## C++

<!-- CPP-DEFINITION -->
```cpp
namespace wgpu {
struct InstanceDescriptor {
  ChainedStruct const* nextInChain = nullptr;
};
struct DawnInstanceDescriptor : ChainedStruct {
  uint32_t additionalRuntimeSearchPathsCount = 0;
  const char* const* additionalRuntimeSearchPaths;
};
Instance CreateInstance(InstanceDescriptor const* descriptor = nullptr);
}  // namespace wgpu
```

### `CreateInstance`

Returns an [Instance](./instance.md) WebGPU object.

| Argument | Description |
|:---------|:------------|
| descriptor | The `InstanceDescriptor` with extra information for configuraing the instance. Maybe `nullptr`. |

The `InstanceDescriptor` is a **ChainedStruct**. A **ChainedStruct** allows extra
information, in this case the `DawnInstanceDescriptor` to be provided in the `nextInChain`
member. The `nextInChain` maybe `nullptr` if there is no further chained
structures.

### `DawnInstanceDescriptor`

| Member | Description |
|:-------|:------------|
| additionalRuntimeSearchPathsCount | The number of search paths in the `additionalRuntimeSearchPaths` |
| additionalRuntimeSearchPaths | Filesystem paths to to search for the Graphics API (e.g. Vulkan) library |

### Example

```cpp
{
  // Provide no arguments for default configuration
  auto i = wgpu::CreateInstance();
}

{
  std::vector<const char*> paths = {
    "some/search/path",
    "some/other/search/path",
  };

  // Chained struct to override configuration
  wgpu::DawnInstanceDescriptor desc = {
    .additionalRuntimeSearchPathsCount = uint32_t(paths.size()),
    .additionaRuntimeSearchPaths = paths.data();
  }

  auto i = wgpu::CreateInstance(InstanceDescriptor{
    .nextInChain = &desc,
  });
}
```



## C

<!-- C-DEFINITION -->
```c
typedef struct WGPUInstanceDescriptor {
    WGPUChainedStruct const * nextInChain;
} WGPUInstanceDescriptor;
typedef struct WGPUDawnInstanceDescriptor {
    WGPUChainedStruct chain;
    uint32_t additionalRuntimeSearchPathsCount;
    const char* const* additionalRuntimeSearchPaths;
} WGPUDawnInstanceDescriptor;
WGPUInstance wgpuCreateInstance(WGPUInstanceDescriptor const * descriptor);
```
