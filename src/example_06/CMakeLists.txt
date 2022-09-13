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

set(DUSK_LIB_SRCS
  args.cc
  args.h
  float_eq.cc
  float_eq.h
  mat4.cc
  mat4.h
  obj_parser.cc
  obj_parser.h
  vec3.h
  vec4.h
)

set(DUSK_SRCS
  callbacks.cc
  callbacks.h
  main.cc
  webgpu_helpers.cc
  webgpu_helpers.h
  wgpu.h
)

set(DUSK_TEST_SRCS
  args_test.cc
  obj_parser_test.cc
  ostream_helper.cc
  ostream_helper.h
)

add_library(libdusk_example_06 ${DUSK_LIB_SRCS})
dusk_compile_options(libdusk_example_06)

add_executable(dusk_example_06 ${DUSK_SRCS})
dusk_compile_options(dusk_example_06)

target_link_libraries(dusk_example_06
  libdusk_example_06
  webgpu_dawn
  webgpu_cpp
  webgpu_glfw
  glfw
)

add_executable(dusk_example_06_unittests ${DUSK_TEST_SRCS})
dusk_test_compile_options(dusk_example_06_unittests)

target_link_libraries(dusk_example_06_unittests
  libdusk_example_06
  gtest
  gtest_main
)

