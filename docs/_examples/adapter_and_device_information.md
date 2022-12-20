---
layout: page
title: Adapter and Device Information
order: 10
---

# Adapter and Device Information

* [Source](https://github.com/dj2/Dusk/tree/main/src/example_01)

This is a simple example to show retrieving information about the
Adapter and Device.

There are three items needed in order to create the
[Device]({{ '/api/cpp.html#class-Device' | relative_url }}) object. First
an [Instance]({{ '/api/cpp.html#class-Instance' | relative_url }}) is needed.
From the [Instance]({{ '/api/cpp.html#class-Instance' | relative_url }}) an
[Adapter]({{ '/api/cpp.html#class-Adapter' | relative_url }}) can be requested.
Then, from the [Adapter]({{ '/api/cpp.html#class-Adapter' | relative_url }}) a
[Device]({{ '/api/cpp.html#class-Device' | relative_url }}) can be created.

From the [Adapter]({{ '/api/cpp.html#class-Adapter' | relative_url }}) object
the following are requested and dumped:
* Properties
* Features
* Limits

From the [Device]({{ '/api/cpp.html#class-Device' | relative_url }}) object the
following are requested and dumped:
* Features
* Limits

## Setup
### Getting an Instance
Retrieval of the instance is done by calling
[wgpu::CreateInstance]({{ '/api/cpp.html#function-CreateInstance' | relative_url }})

### Requesting an Adapter
The [`instance.RequestAdapter`]({{ '/api/cpp.html#class-Instance-RequestAdapter' | relative_url }})
method works through a callback. The callback will be called with each available
[Adapter]({{ '/api/cpp.html#class-Adapter' | relative_url }}) and can then
choose which one to return.

Note, a lambda is being provided, but it can not capture anything as it will be
converted to a C-style function pointer. So, the `adapter` is provided as the
`userdata` parameter and casted back to an
[Adapter]({{ '/api/cpp.html#class-Adapter' | relative_url }}) inside the callback.

When the [Adapter]({{ '/api/cpp.html#class-Adapter' | relative_url }}) is selected,
it must be `Acquire`d in order to increase the reference count and keep the object alive.

### Creating a Device
With the [Adapter]({{ '/api/cpp.html#class-Adapter' | relative_url }}) created
calling [`adapter.CreateDevice()`]({{ '/api/cpp.html#class-Adapter-CreateDevice' | relative_url }})
will create the [Device]({{ '/api/cpp.html#class-Device' | relative_url }}) object.

## Adapter
### Properties
Retrieval of the
[AdapterProperties]({{ '/api/cpp.html#structure-AdapterProperties' | relative_url }})

```
wgpu::AdapterProperties properties;
adapter.GetProperties(&properties);
```

### Features
In order to retrieve the adapter
[Features]({{ '/api/cpp.html#enum-FeatureName' | relative_url }})
memory needs to be allocated first. In order to allocate memory, the number of
features needs to be know. Both of these things are done through the
[`adapter.EnumerateFeatures`]({{ '/api/cpp.html#class-Adapter-EnumerateFeatures' | relative_url }})
API.

[`EnumerateFeatures`]({{ '/api/cpp.html#class-Adapter-EnumerateFeatures' | relative_url }})
takes a single parameter which is the buffer to populate with features and returns
the number of features. In order to create the buffer an initial call to
`EnumerateFeatures(nullptr)` will return the count without writing
any of the features. A second call can then provide the correct buffer.

```
auto feature_count = adapter.EnumerateFeatures(nullptr);
std::vector<wgpu::FeatureName> features(feature_count);
adapter.EnumerateFeatures(features.data());
```

### Limits
The Adapter limits are similar to the adapter properties in that we provide the
[`wgpu::SupportedLimits`]({{ '/api/cpp.html#structure-SupportedLimits' | relative_url }})
as a pointer to the API directly. The difference being,
the WebGPU API does not need to support adapter limits, so
[`GetLimits`]({{ '/api/cpp.html#class-Adapter-GetLimits' | relative_url }})
returns a `boolean` which determines if the provided data object was filled out.
`true` if the limits are provided, `false` otherwise.

```
wgpu::SupportedLimits adapterLimits;
if (adapter.GetLimits(&adapterLimits)) {
  // Use the limits
}
```

## Device
### Features
The device features works similar to the adapter features in that the
number of items is queried through
[`device.EnumerateFeatures(nullptr)`]({{ '/api/cpp.html#class-Device-EnumerateFeatures' | relative_url }}),
the buffer is created and then the call is done with the created buffer.

```
auto feature_count = device.EnumerateFeatures(nullptr);
std::vector<wgpu::FeatureName> features(feature_count);
device.EnumerateFeatures(features.data());
```

### Limits
The device
[`GetLimits`]({{ '/api/cpp.html#class-Device-GetLimits' | relative_url }})
API has similar semantics to the adapter `GetLimits` API described above
in that WebGPU does not need to return the limits, so the result of calling
[`device.GetLimits`]({{ '/api/cpp.html#class-Device-GetLimits' | relative_url }})
needs to be checked.

```
wgpu::SupportedLimits deviceLimits;
if (device.GetLimits(&deviceLimits)) {
  // Use the provided limits
}
```
