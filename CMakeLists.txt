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

cmake_minimum_required(VERSION 3.12)

project(dusk)
enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  message(STATUS "No build type selected, default to Debug")
  set(CMAKE_BUILD_TYPE "Debug")
endif()

if (NOT CLANG_FORMAT)
  find_program(CLANG_FORMAT "clang-format")
endif()
if (CLANG_FORMAT)
  message(STATUS "Found clang-format: ${CLANG_FORMAT}")
  file(GLOB_RECURSE
       ALL_CXX_SOURCE_FILES
       ${PROJECT_SOURCE_DIR}/src/*.h
       ${PROJECT_SOURCE_DIR}/src/*.cc
  )

  add_custom_target(
      format
      COMMAND ${CLANG_FORMAT} -i ${ALL_CXX_SOURCE_FILES})
  add_custom_target(
      format-ci
      COMMAND
        ! ${CLANG_FORMAT} -output-replacements-xml ${ALL_CXX_SOURCE_FILES}
            | grep -q "replacement offset"
  )
endif()

function(dusk_compile_options TARGET)
  target_include_directories(${TARGET} PRIVATE "${PROJECT_SOURCE_DIR}")
  target_include_directories(${TARGET} PRIVATE "${PROJECT_SOURCE_DIR}/third_party/dawn/include")

  target_compile_options(${TARGET} PRIVATE
    -O3
    -fno-rtti
    -fvisibility=hidden
    -Wall
    -Werror
    -Wextra
    -Wno-unknown-pragmas
    -Wpedantic
    -pedantic-errors
  )

  if (("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") OR
      ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang"))
    target_compile_options(${TARGET} PRIVATE
      -Weverything
      -Wno-c++98-compat
      -Wno-c++98-compat-pedantic
      -Wno-documentation
      -Wno-documentation-unknown-command
      -Wno-double-promotion
      -Wno-padded
      -Wno-poison-system-directories
      -Wno-shadow-field-in-constructor
      -Wno-zero-as-null-pointer-constant
    )
  elseif(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${TARGET} PRIVATE
      -Wno-missing-field-initializers
    )
  endif()

endfunction()

add_subdirectory(third_party)
add_subdirectory(src)
