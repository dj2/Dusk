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
#include <cassert>
#include <cmath>
#include <numbers>
#include <print>
#include <string>

#include "src/common/callback.h"
#include "src/common/glfw.h"
#include "src/common/mat4.h"
#include "src/common/webgpu_helpers.h"
#include "src/common/wgpu.h"

namespace {

constexpr uint32_t kWidth = 1024;
constexpr uint32_t kHeight = 768;

// clang-format off
constexpr const std::array<float, 216> cube_data {
  // vec4<f32> position, vec2<f32> uv,
     1, -1,  1,  1,      1, 1,
    -1, -1,  1,  1,      0, 1,
    -1, -1, -1,  1,      0, 0,
     1, -1, -1,  1,      1, 0,
     1, -1,  1,  1,      1, 1,
    -1, -1, -1,  1,      0, 0,

     1,  1,  1,  1,      1, 1,
     1, -1,  1,  1,      0, 1,
     1, -1, -1,  1,      0, 0,
     1,  1, -1,  1,      1, 0,
     1,  1,  1,  1,      1, 1,
     1, -1, -1,  1,      0, 0,

    -1,  1,  1,  1,      1, 1,
     1,  1,  1,  1,      0, 1,
     1,  1, -1,  1,      0, 0,
    -1,  1, -1,  1,      1, 0,
    -1,  1,  1,  1,      1, 1,
     1,  1, -1,  1,      0, 0,

    -1, -1,  1,  1,      1, 1,
    -1,  1,  1,  1,      0, 1,
    -1,  1, -1,  1,      0, 0,
    -1, -1, -1,  1,      1, 0,
    -1, -1,  1,  1,      1, 1,
    -1,  1, -1,  1,      0, 0,

     1,  1,  1,  1,      1, 1,
    -1,  1,  1,  1,      0, 1,
    -1, -1,  1,  1,      0, 0,
    -1, -1,  1,  1,      0, 0,
     1, -1,  1,  1,      1, 0,
     1,  1,  1,  1,      1, 1,

     1, -1, -1,  1,      1, 1,
    -1, -1, -1,  1,      0, 1,
    -1,  1, -1,  1,      0, 0,
     1,  1, -1,  1,      1, 0,
     1, -1, -1,  1,      1, 1,
    -1,  1, -1,  1,      0, 0,
};
// clang-format on

constexpr uint32_t kVertexCount = 36;
constexpr uint32_t kPositionByteOffset = 0;
constexpr uint32_t kUVByteOffset = 4 * sizeof(float);
constexpr uint32_t kCubeDataStride = 6;

constexpr uint32_t kNumInstances = 1024 * 1024;

constexpr const char* kShader = R"(
struct Uniforms {
  pv : mat4x4f,
  num_instances: u32,
  frame: f32,
}
@binding(0) @group(0) var<uniform> uniforms : Uniforms;

struct VertexInput {
  @builtin(instance_index) instance_idx : u32,
  @location(0) pos: vec4f,
  @location(1) uv: vec2f,
}

struct VertexOutput {
  @builtin(position) vertex_pos: vec4f,
  @location(0) uv: vec2f,
  @location(1) frag_colour: vec4f,
}

const step = 2.f;

@vertex
fn vs_main(in: VertexInput) -> VertexOutput {
  let per_side = u32(sqrt(f32(uniforms.num_instances)));
  let half_side = (f32(per_side) / 2.f) + .5;

  let frame_step = uniforms.frame / 64;
  let amplitude = 6.f;

  let y = in.instance_idx % per_side;
  let x = in.instance_idx / per_side;

  let x_pos = step * (f32(x) - half_side);
  let y_pos = ((sin((f32(x) / 1.5) + frame_step) + cos((f32(y) / 1.5) + frame_step)) / 4) * amplitude;
  let z_pos = step * (f32(y) - half_side);
  
  let model = mat4x4f(1, 0, 0, 0,
                      0, 1, 0, 0,
                      0, 0, 1, 0,
                      x_pos, y_pos, z_pos, 1);


  let vert_pos = uniforms.pv * model * in.pos;
  let frag_colour = 0.5 * (in.pos + vec4(1));
  return VertexOutput(vert_pos, in.uv, frag_colour);
}

@fragment
fn fs_main(in : VertexOutput) -> @location(0) vec4f {
  return in.frag_colour;
}
)";

struct Uniforms {
  dusk::Mat4 projView;
  uint32_t numInstances;
  float frame;
  std::array<uint8_t, 8> padding_{};
};

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
    std::println(stderr, "Unable to create GLFW window");
    return 1;
  }

  auto instance = wgpu::CreateInstance();

  // Get surface
  auto surface = wgpu::glfw::CreateSurfaceForWindow(instance, window);

  // Get Adapter
  wgpu::Adapter adapter{};
  {
    wgpu::RequestAdapterOptions adapter_opts{
        .powerPreference = wgpu::PowerPreference::HighPerformance,
        .compatibleSurface = surface,
    };
    instance.RequestAdapter(&adapter_opts, wgpu::CallbackMode::AllowSpontaneous,
                            dusk::cb::adapter_request, &adapter);
  }

  // Get device
  wgpu::DeviceDescriptor deviceDesc{};
  deviceDesc.label = "Primary Device";
  deviceDesc.SetDeviceLostCallback(wgpu::CallbackMode::AllowProcessEvents,
                                   dusk::cb::device_lost);
  deviceDesc.SetUncapturedErrorCallback(dusk::cb::uncaptured_error);
  auto device = adapter.CreateDevice(&deviceDesc);

  // Setup surface for drawing and presenting
  wgpu::SurfaceCapabilities capabilities;
  surface.GetCapabilities(adapter, &capabilities);
  auto surfaceFormat = capabilities.formats[0];
  wgpu::SurfaceConfiguration config = {
      .device = device,
      .format = surfaceFormat,
      .usage = wgpu::TextureUsage::RenderAttachment,
      .width = kWidth,
      .height = kHeight,
      .presentMode = wgpu::PresentMode::Fifo,
  };
  surface.Configure(&config);

  // Create buffers
  auto vertexBuffer = dusk::webgpu::create_buffer(
      device, "Cube Data Buffer", cube_data.data(),
      cube_data.size() * sizeof(float), wgpu::BufferUsage::Vertex);

  // Shaders
  auto shader = dusk::webgpu::create_shader_module(device, "Main Shader Module",
                                                   std::string(kShader));

  // Pipeline creation
  std::array<wgpu::VertexAttribute, 2> vertAttributes{
      wgpu::VertexAttribute{
          .format = wgpu::VertexFormat::Float32x4,
          .offset = kPositionByteOffset,
          .shaderLocation = 0,
      },
      wgpu::VertexAttribute{
          .format = wgpu::VertexFormat::Float32x2,
          .offset = kUVByteOffset,
          .shaderLocation = 1,
      },
  };

  wgpu::VertexBufferLayout vertBufferLayout{
      .stepMode = wgpu::VertexStepMode::Vertex,
      .arrayStride = kCubeDataStride * sizeof(float),
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
              .module = shader,
              .entryPoint = "vs_main",
              .constants = nullptr,
              .bufferCount = 1,
              .buffers = &vertBufferLayout,
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
  auto depthTexture = dusk::webgpu::create_texture(
      device, "Depth texture",
      {
          .width = kWidth,
          .height = kHeight,
      },
      wgpu::TextureFormat::Depth24Plus, wgpu::TextureUsage::RenderAttachment);

  // Setup Uniforms
  constexpr uint64_t uniformBufferSize = sizeof(Uniforms);
  auto uniformBuffer = dusk::webgpu::create_buffer(
      device, "Uniform buffer", uniformBufferSize, wgpu::BufferUsage::Uniform);

  Uniforms uniforms{
      .projView = dusk::Mat4::Identity(),
      .numInstances = kNumInstances,
      .frame = 0.f,
  };

  std::array<wgpu::BindGroupEntry, 1> bindEntries{
      wgpu::BindGroupEntry{
          .binding = 0,
          .buffer = uniformBuffer,
          .size = uniformBufferSize,
      },
  };

  wgpu::BindGroupDescriptor bindGroupDesc{
      .label = "Uniform bind group",
      .layout = pipeline.GetBindGroupLayout(0),
      .entryCount = bindEntries.size(),
      .entries = bindEntries.data(),
  };
  auto uniformBindGroup = device.CreateBindGroup(&bindGroupDesc);

  auto aspect = float(kWidth) / float(kHeight);
  auto fov_y_radians = float((45.f * (std::numbers::pi_v<float>) / 180.f));
  auto projectionMatrix =
      dusk::Mat4::Perspective(fov_y_radians, aspect, 1.f, 1000.f);

  auto startPos = dusk::Mat4::Translation(dusk::Vec3(0, -75, -650));

  auto update_view_matrix = [&] {
    uniforms.frame += 1.f;
    auto viewMatrix = startPos * dusk::Mat4::Rotation(uniforms.frame / 2048.f,
                                                      dusk::Vec3(0., 1., 0.));

    uniforms.projView = projectionMatrix * viewMatrix;
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

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    device.Tick();

    update_view_matrix();
    device.GetQueue().WriteBuffer(uniformBuffer, 0, &uniforms,
                                  uniformBufferSize);

    auto encoder = device.CreateCommandEncoder();
    encoder.SetLabel("Main Command Encoder");

    {
      wgpu::SurfaceTexture surfaceTexture;
      surface.GetCurrentTexture(&surfaceTexture);

      auto backbufferView = surfaceTexture.texture.CreateView();
      backbufferView.SetLabel("Back Buffer Texture View");

      attachment.view = backbufferView;

      auto pass = encoder.BeginRenderPass(&renderPass);
      pass.SetPipeline(pipeline);
      pass.SetBindGroup(0, uniformBindGroup);
      pass.SetVertexBuffer(0, vertexBuffer);
      pass.Draw(kVertexCount, kNumInstances);
      pass.End();
    }
    auto commands = encoder.Finish();

    device.GetQueue().Submit(1, &commands);
    surface.Present();
  }

  vertexBuffer.Destroy();
  surface.Unconfigure();
  surface = nullptr;
  device.Destroy();

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
