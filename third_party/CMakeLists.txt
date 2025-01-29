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

set(DAWN_THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/)
set(DAWN_SPIRV_HEADERS_DIR ${DAWN_THIRD_PARTY_DIR}/spirv-headers)
set(DAWN_SPIRV_TOOLS_DIR ${DAWN_THIRD_PARTY_DIR}/spirv-tools)
set(DAWN_VULKAN_HEADERS_DIR ${DAWN_THIRD_PARTY_DIR}/vulkan-headers)
set(DAWN_VULKAN_UTILITY_LIBRARIES_DIR ${DAWN_THIRD_PARTY_DIR}/vulkan-utility-libraries)
set(DAWN_JINJA2_DIR ${DAWN_THIRD_PARTY_DIR}/jinja/src/jinja2)
set(DAWN_MARKUPSAFE_DIR ${DAWN_THIRD_PARTY_DIR}/markupsafe/src/markupsafe)

set(DAWN_BUILD_GEN_DIR ${CMAKE_CURRENT_BINARY_DIR}/gen)
set(DAWN_ENABLE_DESKTOP_GL OFF)
set(DAWN_ENABLE_OPENGLES OFF)
set(DAWN_ENABLE_NULL OFF)
set(DAWN_BUILD_SAMPLES OFF)
set(TINT_BUILD_DOCS OFF)
set(TINT_BUILD_TESTS OFF)
set(TINT_BUILD_SAMPLES OFF)
set(TINT_BUILD_GLSL_VALIDATOR OFF)
set(TINT_BUILD_GLSL_WRITER OFF)
set(TINT_BUILD_SPV_READER OFF)

if(NOT APPLE)
  set(BUILD_SHARED_LIBS ON)
endif()

add_definitions(
  -Wno-deprecated-builtins     # From Abseil
  -Wno-nullability-extension   # From abseil
  -Wno-unknown-warning-option  # SPIRV-Tools
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/dawn EXCLUDE_FROM_ALL)
