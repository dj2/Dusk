# Copyright 2022 The Dusk Authors
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set(DUSK_SRCS
  callbacks.cc
  callbacks.h
  dump_utils.cc
  dump_utils.h
  main.cc
  mat4.cc
  mat4.h
  vec3.h
  webgpu_helpers.cc
  webgpu_helpers.h
  wgpu.h
)

add_executable(dusk_example_04 ${DUSK_SRCS})
dusk_compile_options(dusk_example_04)

target_link_libraries(dusk_example_04
  webgpu_dawn
  webgpu_cpp
  webgpu_glfw
  glfw
)
