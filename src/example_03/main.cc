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

#include <array>
#include <print>

#include "src/common/callback.h"
#include "src/common/glfw.h"
#include "src/common/webgpu_helpers.h"
#include "src/common/wgpu.h"

namespace {

constexpr uint32_t kWidth = 1024;
constexpr uint32_t kHeight = 768;

constexpr std::array<uint32_t, 3> index_data{0, 1, 2};
constexpr std::array<float, 24> vertex_data{
    0.f, .5f, 0.f, 1.f, 1.f, 0.f,  0.f, 1.f, -.5f, -.5f, 0.f, 1.f,
    0.f, 1.f, 0.f, 1.f, .5f, -.5f, 0.f, 1.f, 0.f,  0.f,  1.f, 1.f,
};

constexpr const char* kShader = R"(
struct VertexInput {
  @location(0) pos: vec4f,
  @location(1) colour: vec4f,
}

struct VertexOutput {
  @builtin(position) pos: vec4f,
  @location(0) colour: vec4f,
}

@vertex
fn vs_main(in: VertexInput) -> VertexOutput {
  return VertexOutput(in.pos, in.colour);
}

@fragment
fn fs_main(in: VertexOutput) -> @location(0) vec4f {
  return in.colour;
}
)";

}  // namespace

int main() {
  glfwSetErrorCallback(dusk::cb::glfw_error);

  if (!glfwInit()) {
    std::println(stderr, "Failed to initialize GLFW.");
    return 1;
  }

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_FALSE);

  auto window = glfwCreateWindow(kWidth, kHeight, "dusk", nullptr, nullptr);
  if (!window) {
    std::println(stderr, "Failed to create GLFW window");
    return 1;
  }

  auto instance = wgpu::CreateInstance();

  // Get surface
  auto surface = wgpu::glfw::CreateSurfaceForWindow(instance, window);

  // Get Adapter
  wgpu::RequestAdapterOptions adapter_opts{
      .powerPreference = wgpu::PowerPreference::HighPerformance,
      .compatibleSurface = surface,
  };
  wgpu::Adapter adapter{};
  instance.RequestAdapter(&adapter_opts, wgpu::CallbackMode::AllowSpontaneous,
                          dusk::cb::adapter_request, &adapter);

  // Get device
  wgpu::DeviceDescriptor deviceDesc{};
  deviceDesc.label = "Primary Device";
  deviceDesc.SetDeviceLostCallback(wgpu::CallbackMode::AllowProcessEvents,
                                   dusk::cb::device_lost);
  deviceDesc.SetUncapturedErrorCallback(dusk::cb::uncaptured_error);
  auto device = adapter.CreateDevice(&deviceDesc);

  // Set up surface for drawing and presenting
  wgpu::SurfaceCapabilities capabilities;
  surface.GetCapabilities(adapter, &capabilities);
  auto surfaceFormat = capabilities.formats[0];
  wgpu::SurfaceConfiguration config = {
      .device = device,
      .format = surfaceFormat,
      .width = kWidth,
      .height = kHeight,
      .presentMode = wgpu::PresentMode::Fifo,
  };
  surface.Configure(&config);

  // Create buffers
  auto indexBuffer = dusk::webgpu::create_buffer(
      device, "Index Buffer", index_data.data(),
      index_data.size() * sizeof(uint32_t), wgpu::BufferUsage::Index);
  auto vertexBuffer = dusk::webgpu::create_buffer(
      device, "Vertex Buffer", vertex_data.data(),
      vertex_data.size() * sizeof(float), wgpu::BufferUsage::Vertex);

  // Shaders
  auto shader =
      dusk::webgpu::create_shader_module(device, "Main Shader Module", kShader);

  // Pipeline creation
  std::array<wgpu::VertexAttribute, 2> vertAttributes{
      wgpu::VertexAttribute{
          .format = wgpu::VertexFormat::Float32x4,
          .offset = 0,
          .shaderLocation = 0,
      },
      wgpu::VertexAttribute{
          .format = wgpu::VertexFormat::Float32x4,
          .offset = 4 * sizeof(float),
          .shaderLocation = 1,
      }};

  wgpu::VertexBufferLayout vertBufferLayout{
      .stepMode = wgpu::VertexStepMode::Vertex,
      .arrayStride = 8 * sizeof(float),
      .attributeCount = vertAttributes.size(),
      .attributes = vertAttributes.data(),
  };

  wgpu::ColorTargetState target{
      .format = surfaceFormat,
  };

  wgpu::FragmentState fragState{
      .module = shader,
      .entryPoint = "fs_main",
      .constants = nullptr,
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
              .constants = nullptr,
              .bufferCount = 1,
              .buffers = &vertBufferLayout,
          },
      .fragment = &fragState,
  };

  auto pipeline = device.CreateRenderPipeline(&pipelineDesc);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    device.Tick();

    auto encoder = device.CreateCommandEncoder();
    encoder.SetLabel("Main Command Encoder");

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
      pass.SetIndexBuffer(indexBuffer, wgpu::IndexFormat::Uint32);
      pass.DrawIndexed(3);
      pass.End();
    }
    auto commands = encoder.Finish();

    device.GetQueue().Submit(1, &commands);
    surface.Present();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
