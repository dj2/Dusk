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
#include <chrono>
#include <cmath>
#include <numbers>
#include <print>

#include "src/example_04/dump_utils.h"
#include "src/example_04/mat4.h"
#include "src/example_04/webgpu_helpers.h"
#include "src/example_04/wgpu.h"

namespace {

constexpr uint32_t kWidth = 1024;
constexpr uint32_t kHeight = 768;

// clang-format off
constexpr const std::array<float, 216> cube_data{
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

constexpr const char* kShader = R"(
struct Uniforms {
  mvp : mat4x4f,
}
@binding(0) @group(0) var<uniform> uniforms : Uniforms;

struct VertexInput {
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
  let vert_pos = uniforms.mvp * in.pos;
  let frag_colour = 0.5 * (in.pos + vec4(1));
  return VertexOutput(vert_pos, in.uv, frag_colour);
}

@fragment
fn fs_main(in: VertexOutput) -> @location(0) vec4f {
  return in.frag_colour;
}
)";

void adapter_request_cb(wgpu::RequestAdapterStatus status,
                        wgpu::Adapter a,
                        wgpu::StringView message,
                        wgpu::Adapter* data) {
  if (status != wgpu::RequestAdapterStatus::Success) {
    std::println(stderr, "Adapter request failed: {}",
                 std::string_view(message));
    exit(1);
  }
  *data = a;
}

void device_lost_cb([[maybe_unused]] const wgpu::Device& device,
                    wgpu::DeviceLostReason reason,
                    struct wgpu::StringView message) {
  std::print(stderr, "device lost: {}",
             dusk::dump_utils::DeviceLostReasonToString(reason));
  if (message.length > 0) {
    std::print(stderr, ": {}", std::string_view(message));
  }
  std::println(stderr, "");
}

void uncaptured_error_cb
    [[noreturn]] ([[maybe_unused]] const wgpu::Device& device,
                  wgpu::ErrorType type,
                  struct wgpu::StringView message) {
  std::print(stderr, "uncaptured error: {}",
             dusk::dump_utils::ErrorTypeToString(type));
  if (message.length > 0) {
    std::print(stderr, ": {}", std::string_view(message));
  }

  std::println(stderr, "");
  assert(false);
};

void glfw_error_cb [[noreturn]] (int code, const char* message) {
  std::println(stderr, "GLFW error: {}: {}", code, message);
  assert(false);
}

}  // namespace

int main() {
  glfwSetErrorCallback(glfw_error_cb);

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
                          adapter_request_cb, &adapter);

  dusk::dump_utils::DumpAdapter(adapter);

  // Get device
  wgpu::DeviceDescriptor deviceDesc{};
  deviceDesc.label = "Primary Device";
  deviceDesc.SetDeviceLostCallback(wgpu::CallbackMode::AllowProcessEvents,
                                   device_lost_cb);
  deviceDesc.SetUncapturedErrorCallback(uncaptured_error_cb);
  auto device = adapter.CreateDevice(&deviceDesc);

  dusk::dump_utils::DumpDevice(device);

  // Setup surface for drawing and presenting
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
      device, "Cube Data Buffer", cube_data.data(),
      cube_data.size() * sizeof(float), wgpu::BufferUsage::Vertex);

  // Shaders
  auto shader =
      dusk::webgpu::createShaderModule(device, "Main Shader Module", kShader);

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
      }};

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
  auto depthTexture = dusk::webgpu::createTexture(
      device, "Depth texture",
      {
          .width = kWidth,
          .height = kHeight,
      },
      wgpu::TextureFormat::Depth24Plus, wgpu::TextureUsage::RenderAttachment);

  // Setup Uniforms
  constexpr uint64_t uniformBufferSize = 4 * 16;  // mat4x4<f32>
  auto uniformBuffer = dusk::webgpu::createBuffer(
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
  auto viewMatrix = dusk::Mat4::Translation(dusk::Vec3(0, 0, -4));

  auto projViewMatrix = projectionMatrix * viewMatrix;

  auto frame = 1.f;
  auto transformation_matrix = [&projViewMatrix, &frame]() -> dusk::Mat4 {
    frame += 1.f;

    auto rotMatrix = dusk::Mat4::Rotation(
        1, dusk::Vec3(sinf(frame / 32.f), cosf(frame / 32.f), 0));
    return projViewMatrix * rotMatrix;
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
    device.Tick();
    glfwPollEvents();

    auto transform = transformation_matrix();
    device.GetQueue().WriteBuffer(uniformBuffer, 0, transform.Data(),
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
      pass.Draw(kVertexCount);
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
