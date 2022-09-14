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

#include <cassert>
#include <chrono>
#include <cmath>
#include <iostream>
#include <numbers>
#include <string>
#include <vector>

#include "src/example_06/args.h"
#include "src/example_06/callbacks.h"
#include "src/example_06/mat4.h"
#include "src/example_06/webgpu_helpers.h"
#include "src/example_06/wgpu.h"

namespace {

constexpr uint32_t kWidth = 1024;
constexpr uint32_t kHeight = 768;

constexpr const char* kShader = R"(
struct Uniforms {
  modelViewProjectionMatrix : mat4x4<f32>,
}
@binding(0) @group(0) var<uniform> uniforms : Uniforms;

struct VertexInput {
  @location(0) pos: vec4<f32>,
}

struct VertexOutput {
  @builtin(position) vertex_pos : vec4<f32>,
  @location(0) frag_colour: vec4<f32>,
}

@vertex
fn vs_main(in : VertexInput) -> VertexOutput {
  let vert_pos = uniforms.modelViewProjectionMatrix * in.pos;
  let frag_colour = 0.5 * (in.pos + vec4(1));
  return VertexOutput(vert_pos, frag_colour);
}

@fragment
fn fs_main(in : VertexOutput) -> @location(0) vec4<f32> {
  return in.frag_colour;
}
)";

}  // namespace

int main(int argc, const char** argv) {
  dusk::Args args;
  auto ret =
      args.Parse({argv, argv + argc}, {{"h", dusk::Args::Type::kBoolean}});
  if (ret.has_value()) {
    std::cerr << ret.value() << std::endl;
    return 1;
  }

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
      [](WGPURequestAdapterStatus, WGPUAdapter adapterIn, const char*,
         void* userdata) {
        *static_cast<wgpu::Adapter*>(userdata) =
            wgpu::Adapter::Acquire(adapterIn);
      },
      &adapter);

  // Get device
  auto device = adapter.CreateDevice();
  device.SetLabel("Primary Device");

  device.SetUncapturedErrorCallback(dusk::cb::Error, nullptr);
  device.SetDeviceLostCallback(dusk::cb::DeviceLost, nullptr);
  device.SetLoggingCallback(dusk::cb::Logging, nullptr);

  // Get surface
  auto surface = wgpu::glfw::CreateSurfaceForWindow(instance, window);

  // Setup swapchain
  wgpu::SwapChainDescriptor swapchainDesc{
      .usage = wgpu::TextureUsage::RenderAttachment,
      .format = wgpu::TextureFormat::BGRA8Unorm,
      .width = kWidth,
      .height = kHeight,
      .presentMode = wgpu::PresentMode::Mailbox,
  };
  auto swapchain = device.CreateSwapChain(surface, &swapchainDesc);

  // Create buffers
  //  auto vertexBuffer = dusk::webgpu::createBufferFromData(
  //      device, "Cube Data Buffer", cube_data, sizeof(cube_data),
  //      wgpu::BufferUsage::Vertex);

  // Shaders
  auto shader =
      dusk::webgpu::createShaderModule(device, "Main Shader Module", kShader);

  // Pipeline creation
  //  wgpu::VertexAttribute vertAttributes[2] = {
  //      {
  //          .format = wgpu::VertexFormat::Float32x4,
  //          .offset = kPositionByteOffset,
  //          .shaderLocation = 0,
  //      },
  //      {
  //          .format = wgpu::VertexFormat::Float32x2,
  //          .offset = kUVByteOffset,
  //          .shaderLocation = 1,
  //      }};

  //  wgpu::VertexBufferLayout vertBufferLayout{
  //      .arrayStride = kCubeDataStride * sizeof(float),
  //      .attributeCount = 2,
  //      .attributes = vertAttributes,
  //  };

  wgpu::ColorTargetState target{
      .format = wgpu::TextureFormat::BGRA8Unorm,
  };

  wgpu::FragmentState fragState{
      .module = shader,
      .entryPoint = "fs_main",
      .targetCount = 1,
      .targets = &target,
  };

  wgpu::DepthStencilState depthState = {
      .format = wgpu::TextureFormat::Depth24Plus,
      .depthWriteEnabled = true,
      .depthCompare = wgpu::CompareFunction::Less,
  };

  wgpu::RenderPipelineDescriptor pipelineDesc{
      .label = "Main Render Pipeline",
      .layout = nullptr,
      .vertex =
          {
              .module = shader, .entryPoint = "vs_main", .bufferCount = 0,
              //              .buffers = &vertBufferLayout,
          },
      .primitive =
          {
              // Cube is solid, so the back faces can never be seen
              .cullMode = wgpu::CullMode::Back,
          },
      // Enable depth-testing so correct front ordering is maintained
      .depthStencil = &depthState,
      .fragment = &fragState,
  };
  auto pipeline = device.CreateRenderPipeline(&pipelineDesc);

  // Create depth texture
  auto depthTexture = dusk::webgpu::createTexture(
      device, "Depth texture",
      {
          .width = kWidth,
          .height = kHeight,
      },
      wgpu::TextureFormat::Depth24Plus, wgpu::TextureUsage::RenderAttachment);

  // Setup Uniform
  constexpr uint32_t matrix_element_count = 4 * 4;  // 4x4 matrix
  constexpr uint32_t matrix_byte_size = sizeof(float) * matrix_element_count;
  constexpr uint64_t uniformBufferSize = matrix_byte_size;
  auto uniformBuffer = dusk::webgpu::createBuffer(
      device, "Uniform buffer", uniformBufferSize, wgpu::BufferUsage::Uniform);

  wgpu::BindGroupEntry bindEntries[1] = {{
      .binding = 0,
      .buffer = uniformBuffer,
      .size = uniformBufferSize,
  }};

  wgpu::BindGroupDescriptor bindGroupDesc{
      .label = "Uniform bind group",
      .layout = pipeline.GetBindGroupLayout(0),
      .entryCount = 1,
      .entries = bindEntries,
  };
  auto uniformBindGroup = device.CreateBindGroup(&bindGroupDesc);

  auto aspect = float(kWidth) / float(kHeight);
  auto fov_y_radians = float((2.f * std::numbers::pi) / 5.f);
  auto projectionMatrix =
      dusk::Mat4::Perspective(fov_y_radians, aspect, 1.f, 100.f);

  auto transformation_matrix = [&projectionMatrix]() {
    auto now_s = std::chrono::time_point_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now());
    auto ms = float(now_s.time_since_epoch().count()) / 10000.f;

    auto viewMatrix = dusk::Mat4::Translation(dusk::Vec3(0, 0, -4));
    auto rotMatrix = dusk::Mat4::Rotation(1, dusk::Vec3(sinf(ms), cosf(ms), 0));

    return projectionMatrix * viewMatrix * rotMatrix;
  };

  wgpu::RenderPassColorAttachment attachment{
      .view = nullptr,
      .loadOp = wgpu::LoadOp::Clear,
      .storeOp = wgpu::StoreOp::Store,
      .clearValue = {.5, .5, .5, 1.},
  };

  wgpu::RenderPassDepthStencilAttachment depthStencilAttach{
      .view = depthTexture.CreateView(),
      .depthLoadOp = wgpu::LoadOp::Clear,
      .depthStoreOp = wgpu::StoreOp::Store,
      .depthClearValue = 1.0,
  };

  wgpu::RenderPassDescriptor renderPass{
      .label = "Main Render Pass",
      .colorAttachmentCount = 1,
      .colorAttachments = &attachment,
      .depthStencilAttachment = &depthStencilAttach,
  };

  // Per-frame method
  auto frame_number = 0;
  auto frame = [&]() {
    frame_number += 1;

    auto transform = transformation_matrix();
    device.GetQueue().WriteBuffer(uniformBuffer, 0, transform.Data(),
                                  uniformBufferSize);

    auto encoder = device.CreateCommandEncoder();
    encoder.SetLabel("Main Command Encoder");

    {
      auto backbufferView = swapchain.GetCurrentTextureView();
      backbufferView.SetLabel("Back Buffer Texture View");

      attachment.view = backbufferView;

      auto pass = encoder.BeginRenderPass(&renderPass);
      pass.SetPipeline(pipeline);
      pass.SetBindGroup(0, uniformBindGroup);
      //      pass.SetVertexBuffer(0, vertexBuffer);
      //      pass.Draw(kVertexCount, num_instances);
      pass.End();
    }
    auto commands = encoder.Finish();

    device.GetQueue().Submit(1, &commands);
    swapchain.Present();
  };

  auto start = std::chrono::time_point_cast<std::chrono::seconds>(
      std::chrono::steady_clock::now());

  auto last = 0ll;
  while (!glfwWindowShouldClose(window)) {
    frame();
    glfwPollEvents();

    auto now = std::chrono::time_point_cast<std::chrono::seconds>(
        std::chrono::steady_clock::now());
    auto dur = now - start;

    if (dur.count() > last) {
      std::cerr << "FPS: " << (frame_number / dur.count()) << std::endl;
      last = dur.count();
    }
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
