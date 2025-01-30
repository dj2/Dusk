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

add_executable(dusk_example_03 ${DUSK_SRCS})
dusk_compile_options(dusk_example_03)
target_sources(dusk_example_03 PRIVATE
  ../common/callback.cc
  ../common/callback.h
  ../common/glfw.h
  ../common/log.cc
  ../common/log.h
  ../common/webgpu_helpers.cc
  ../common/webgpu_helpers.h
  ../common/wgpu.h
  main.cc
)
target_link_libraries(dusk_example_03
  webgpu_dawn
  webgpu_cpp
  webgpu_glfw
  glfw
)
