# Dusk Example 01  -- Adapter and Device Information

This is a simple example to show retrieving information about the
Adapter and Device.

There are three items needed in order to create the `Device` object. First
an `Instance` is needed. From the `Instance` an `Adapter` can be requested.
Then, from the `Adapter` a `Device` can be created.

From the `Adapter` object the following are requested and dumped:
* Properties
* Features
* Limits

From the `Device` object the following are requested and dumped:
* Features
* Limits

## Setup
### Getting an Instance
Retrieval of the instance is done by calling `wgpu::CreateInstance`.

### Requesting an Adapter
The `RequestAdapter` method works through a callback. The callback will be
called with each available `Adapter` and can then choose which one to return.
The choice can use the `Properties`, `Features` and `Limits` of the adapter to
make the choice. For the examples, we just take whatever is provided.

Note, a lambda is being provided, but it can not capture anything as it will be
converted to a C-style function pointer. So, the `adapter` is provided as the
`userdata` parameter and casted back to an `Adapter` inside the callback.

When the `Adapter` is selected, it must be `Acquire`d in order to increase the
reference count and keep the object alive.

### Creating a Device
With the `Adapter` created calling `adapter.CreateDevice()` will create the
`Device` object.

## Adapter
### Properties
Retrieval of the `Adapter` `Properties` is done by calling:

```
wgpu::AdapterProperties properties;
adapter.GetProperties(&properties);
```

This will populate the provided `wgpu::AdapterProperties` object.

### Features
In order to retrieve the `Adapter` `Features` memory needs to be allocated first.
In order to allocate memory, the number of features needs to be know. Both of
these things are done through the `adapter.EnumerateFeatures` API.

`EnumerateFeatures` takes a single parameter which is the buffer to populate with
features and returns the number of features. In order to create the buffer an
initial call to `EnumerateFeatures(nullptr)` will return the count without writing
any of the features. A second call can then provide the correct buffer.

```
auto feature_count = adapter.EnumerateFeatures(nullptr);
std::vector<wgpu::FeatureName> features(feature_count);
adapter.EnumerateFeatures(features.data());
```

### Limits
`Adapter` `Limits` is similar to `Adapter` `Properties` in that we provide the
`wgpu::SupportedLimits` as a pointer to the API directly. The difference being,
the WebGPU API does not need to support `Adapter` `Limits`, so `adapterLimits`
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
The `Device` `Features` call works simliar to `Adapter` `Features` in that the
number of items is queried through `device.EnumerateFeatures(nullptr)`, the
buffer is created and then the call is done with the created buffer.

```
auto feature_count = device.EnumerateFeatures(nullptr);
std::vector<wgpu::FeatureName> features(feature_count);
device.EnumerateFeatures(features.data());
```

### Limits
The `Device` `Limits` API has similar semantics to the `Adapter` `Limits` API
in that WebGPU does not need to return the limits, so the result of calling
`device.GetLimits` needs to be checked.

```
wgpu::SupportedLimits deviceLimits;
if (device.GetLimits(&deviceLimits)) {
  // Use the provided limits
}
```
