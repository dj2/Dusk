---
layout: page
title: Instance
parent: API Documentation
nav_order: 1000
---

# Instance

## C++
<!-- CPP-DEFINITION -->
```cpp
namespace wgpu {

class Instance {
  public:
    Surface CreateSurface(SurfaceDescriptor const* descriptor) const;
    void RequestAdapter(RequestAdapterOptions const* options,
                        RequestAdapterCallback callback,
                        void* userdata) const;
};
}  // namespace wgpu
```

## C
<!-- C-DEFINITION -->
```c
WGPUSurface wgpuInstanceCreateSurface(WGPUInstance instance,
                                      WGPUSurfaceDescriptor const* descriptor);
void wgpuInstanceRequestAdapter(WGPUInstance instance,
                                WGPURequestAdapterOptions const* options /* nullable */,
                                WGPURequestAdapterCallback callback,
                                void* userdata);
void wgpuInstanceReference(WGPUInstance instance);
void wgpuInstanceRelease(WGPUInstance instance);
```
