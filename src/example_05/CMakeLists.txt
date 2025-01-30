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

add_executable(dusk_example_05 ${DUSK_SRCS})
dusk_compile_options(dusk_example_05)
target_sources(dusk_example_05 PRIVATE
  main.cc
)
target_link_libraries(dusk_example_05
  dusk::common
  webgpu_dawn
  webgpu_cpp
  webgpu_glfw
  glfw
)
