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
#include "src/common/expected.h"
#include "src/common/glfw.h"
#include "src/common/log.h"
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

// 32 is the maximum we can use here without going over the max binding size
// of a uniform buffer which is 65,536
constexpr uint32_t x_count = 32;
constexpr uint32_t y_count = 32;
constexpr uint32_t num_instances = x_count * y_count;

constexpr const char* kShader = R"(
struct Uniforms {
  mvp : array<mat4x4f, {{NUM_INSTANCES}}>,
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

@vertex
fn vs_main(in: VertexInput) -> VertexOutput {
  let vert_pos = uniforms.mvp[in.instance_idx] * in.pos;
  let frag_colour = 0.5 * (in.pos + vec4(1));
  return VertexOutput(vert_pos, in.uv, frag_colour);
}

@fragment
fn fs_main(in : VertexOutput) -> @location(0) vec4f {
  return in.frag_colour;
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
    std::println(stderr, "Unable to create GLFW window");
    return 1;
  }

  auto instance = wgpu::CreateInstance();

  // Get surface
  auto surface = wgpu::glfw::CreateSurfaceForWindow(instance, window);

  // Get Adapter
  wgpu::RequestAdapterOptions adapter_opts{
      .compatibleSurface = surface,
      .powerPreference = wgpu::PowerPreference::HighPerformance,
  };
  wgpu::Adapter adapter{};
  instance.RequestAdapter(&adapter_opts, wgpu::CallbackMode::AllowSpontaneous,
                          dusk::cb::adapter_request, &adapter);

  dusk::valid_or_exit(dusk::log::emit(adapter));

  // Get device
  wgpu::DeviceDescriptor deviceDesc{};
  deviceDesc.label = "Primary Device";
  deviceDesc.SetDeviceLostCallback(wgpu::CallbackMode::AllowProcessEvents,
                                   dusk::cb::device_lost);
  deviceDesc.SetUncapturedErrorCallback(dusk::cb::uncaptured_error);
  auto device = adapter.CreateDevice(&deviceDesc);

  dusk::valid_or_exit(dusk::log::emit(device));

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
      .presentMode = wgpu::PresentMode::Mailbox,
  };
  surface.Configure(&config);

  // Create buffers
  auto vertexBuffer = dusk::webgpu::create_buffer(
      device, "Cube Data Buffer", cube_data.data(),
      cube_data.size() * sizeof(float), wgpu::BufferUsage::Vertex);

  // Shaders
  auto shader_data = std::string(kShader);
  auto key = std::string("{{NUM_INSTANCES}}");
  size_t pos = shader_data.find(key);
  assert(pos != std::string::npos);
  shader_data.replace(pos, key.size(), std::to_string(num_instances));

  auto shader = dusk::webgpu::create_shader_module(device, "Main Shader Module",
                                                   shader_data);

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
      .arrayStride = kCubeDataStride * sizeof(float),
      .stepMode = wgpu::VertexStepMode::Vertex,
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
  constexpr uint32_t matrix_element_count = 4 * 4;  // 4x4 matrix
  constexpr uint32_t matrix_byte_size = sizeof(float) * matrix_element_count;
  constexpr uint64_t uniformBufferSize = matrix_byte_size * num_instances;
  auto uniformBuffer = dusk::webgpu::create_buffer(
      device, "Uniform buffer", uniformBufferSize, wgpu::BufferUsage::Uniform);

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
  auto fov_y_radians = float((2.f * std::numbers::pi_v<float>) / 5.f);
  auto projectionMatrix =
      dusk::Mat4::Perspective(fov_y_radians, aspect, 1.f, 100.f);

  std::array<dusk::Mat4, num_instances> model_matrices;
  std::array<dusk::Mat4, num_instances> mvp_matrices;

  constexpr float step = 4.f;

  float half_x = (x_count / 2.f) + .5f;
  float half_y = (y_count / 2.f) + .5f;

  // Initialize matrix data for each cube instance
  for (size_t x = 0; x < x_count; x++) {
    for (size_t y = 0; y < y_count; y++) {
      model_matrices[(x * y_count) + y] = dusk::Mat4::Translation(dusk::Vec3(
          step * (float(x) - half_x), step * (float(y) - half_y), 0));
    }
  }

  auto viewMatrix = dusk::Mat4::Translation(dusk::Vec3(0, 3, -92));
  viewMatrix = viewMatrix * dusk::Mat4::Rotation(30, dusk::Vec3(1., 0., 0.));

  auto projViewMatrix = projectionMatrix * viewMatrix;

  auto frame = 1.f;
  auto update_transformation_matrices = [&]() {
    auto frame_step = frame / 512.f;
    frame += 1.f;

    for (size_t x = 0; x < x_count; x++) {
      for (size_t y = 0; y < y_count; y++) {
        auto rotMatrix = dusk::Mat4::Rotation(
            1, dusk::Vec3(sinf((float(x) + 2.5f) * frame_step),
                          cosf((float(y) + 2.5f) * frame_step), 0));

        auto movZ = dusk::Mat4::Translation(
            dusk::Vec3(0, 0, 3.f * sinf((float(x) + 2.5f) * frame_step)));

        auto idx = (x * y_count) + y;
        mvp_matrices[idx] =
            projViewMatrix * (model_matrices[idx] * movZ) * rotMatrix;
      }
    }
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

    update_transformation_matrices();
    device.GetQueue().WriteBuffer(uniformBuffer, 0, mvp_matrices.data(),
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
      pass.Draw(kVertexCount, num_instances);
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
