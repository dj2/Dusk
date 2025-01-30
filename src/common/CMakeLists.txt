# Copyright 2025 The Dusk Authors
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

add_library(dusk-common)
add_library(dusk::common ALIAS dusk-common)
dusk_compile_options(dusk-common)
target_sources(dusk-common PRIVATE
  callback.cc
  callback.h
  glfw.h
  log.cc
  log.h
  mat4.cc
  mat4.h
  vec3.h
  webgpu_helpers.cc
  webgpu_helpers.h
  wgpu.h
)

target_link_libraries(dusk-common PRIVATE
  webgpu_cpp
)
