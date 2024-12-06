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

#include <iostream>
#include <vector>

#include "src/example_02/callbacks.h"
#include "src/example_02/dump_utils.h"
#include "src/example_02/webgpu_helpers.h"
#include "src/example_02/wgpu.h"

namespace {

constexpr uint32_t kWidth = 1024;
constexpr uint32_t kHeight = 768;

constexpr float vertex_data[24] = {
    0.f, .5f, 0.f, 1.f, 1.f, 0.f,  0.f, 1.f, -.5f, -.5f, 0.f, 1.f,
    0.f, 1.f, 0.f, 1.f, .5f, -.5f, 0.f, 1.f, 0.f,  0.f,  1.f, 1.f,
};

constexpr const char* kShader = R"(
struct VertexInput {
  @location(0) pos: vec4<f32>,
  @location(1) color: vec4<f32>,
}

struct VertexOutput {
  @builtin(position) pos: vec4<f32>,
  @location(0) color: vec4<f32>,
}

@vertex
fn vs_main(in : VertexInput) -> VertexOutput {
  return VertexOutput(in.pos, in.color);
}

@fragment
fn fs_main(in : VertexOutput) -> @location(0) vec4<f32> {
  return in.color;
}
)";

}  // namespace

int main() {
  glfwSetErrorCallback([](int code, const char* message) {
    std::cerr << "GLFW error: " << code << " - " << message << std::endl;
  });

  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW." << std::endl;
    return 1;
  }

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_FALSE);

  auto window = glfwCreateWindow(kWidth, kHeight, "dusk", nullptr, nullptr);
  if (!window) {
    return 1;
  }
  auto instance = wgpu::CreateInstance();

  // Get Adapter
  wgpu::Adapter adapter;
  instance.RequestAdapter(
      nullptr,
      [](WGPURequestAdapterStatus, WGPUAdapter adapterIn, WGPUStringView,
         void* userdata) {
        *static_cast<wgpu::Adapter*>(userdata) =
            wgpu::Adapter::Acquire(adapterIn);
      },
      &adapter);

  dusk::dump_utils::DumpAdapter(adapter);

  // Get device
  wgpu::DeviceDescriptor deviceDesc;
  deviceDesc.SetDeviceLostCallback(wgpu::CallbackMode::AllowSpontaneous,
                                   dusk::cb::DeviceLost);
  deviceDesc.SetUncapturedErrorCallback(dusk::cb::Error);
  auto device = adapter.CreateDevice(&deviceDesc);
  device.SetLabel("Primary Device");

  // Logging is enabled as soon as the callback is setup.
  device.SetLoggingCallback(dusk::cb::Logging, nullptr);

  dusk::dump_utils::DumpDevice(device);

  // Get surface
  auto surface = wgpu::glfw::CreateSurfaceForWindow(instance, window);

  // Set up surface for drawing and presenting
  wgpu::SurfaceCapabilities capabilities;
  surface.GetCapabilities(adapter, &capabilities);
  auto surfaceFormat = capabilities.formats[0];
  wgpu::SurfaceConfiguration config = {
      .device = device,
      .format = surfaceFormat,
      .width = kWidth,
      .height = kHeight,
      .presentMode = wgpu::PresentMode::Mailbox,
  };
  surface.Configure(&config);

  // Create buffers
  auto vertexBuffer = dusk::webgpu::createBufferFromData(
      device, "Vertex Buffer", vertex_data, sizeof(vertex_data),
      wgpu::BufferUsage::Vertex);

  // Shaders
  auto shader =
      dusk::webgpu::createShaderModule(device, "Main Shader Module", kShader);

  // Pipeline creation
  wgpu::VertexAttribute vertAttributes[2] = {
      {
          .format = wgpu::VertexFormat::Float32x4,
          .offset = 0,
          .shaderLocation = 0,
      },
      {
          .format = wgpu::VertexFormat::Float32x4,
          .offset = 4 * sizeof(float),
          .shaderLocation = 1,
      }};

  wgpu::VertexBufferLayout vertBufferLayout{
      .arrayStride = 8 * sizeof(float),
      .stepMode = wgpu::VertexStepMode::Vertex,
      .attributeCount = 2,
      .attributes = vertAttributes,
  };

  wgpu::ColorTargetState target{
      .format = surfaceFormat,
  };

  wgpu::FragmentState fragState{
      .module = shader,
      .entryPoint = "fs_main",
      .targetCount = 1,
      .targets = &target,
  };

  wgpu::RenderPipelineDescriptor pipelineDesc{
      .label = "Main Render Pipeline",
      .layout = nullptr,  // Automatic layout
      .vertex =
          {
              .module = shader,
              .entryPoint = "vs_main",
              .bufferCount = 1,
              .buffers = &vertBufferLayout,
          },
      .fragment = &fragState,
  };
  auto pipeline = device.CreateRenderPipeline(&pipelineDesc);

  // Per-frame method
  auto frame = [&]() {
    auto encoder = device.CreateCommandEncoder();
    encoder.SetLabel("Main command encoder");

    {
      wgpu::SurfaceTexture surfaceTexture;
      surface.GetCurrentTexture(&surfaceTexture);
      auto backbufferView = surfaceTexture.texture.CreateView();
      backbufferView.SetLabel("Back Buffer Texture View");

      wgpu::RenderPassColorAttachment attachment{
          .view = backbufferView,
          .loadOp = wgpu::LoadOp::Clear,
          .storeOp = wgpu::StoreOp::Store,
          .clearValue = {0., 0., 0., 1.},
      };

      wgpu::RenderPassDescriptor renderPass{
          .label = "Main Render Pass",
          .colorAttachmentCount = 1,
          .colorAttachments = &attachment,
      };

      auto pass = encoder.BeginRenderPass(&renderPass);
      pass.SetPipeline(pipeline);
      pass.SetVertexBuffer(0, vertexBuffer);
      pass.Draw(3);
      pass.End();
    }
    auto commands = encoder.Finish();

    device.GetQueue().Submit(1, &commands);
    surface.Present();
  };

  while (!glfwWindowShouldClose(window)) {
    frame();
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
