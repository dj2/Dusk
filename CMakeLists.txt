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

project(dusk
  VERSION 0.0.1
  LANGUAGES CXX
)

enable_testing()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  message(STATUS "No build type selected, default to Debug")
  set(CMAKE_BUILD_TYPE "Debug")
endif()

message(STATUS "")
message(STATUS "Build type...........: ${CMAKE_BUILD_TYPE}")
message(STATUS "CMake generator......: ${CMAKE_GENERATOR} ${CMAKE_VERSION}")
message(STATUS "CXX compiler.........: ${CMAKE_CXX_COMPILER}")
message(STATUS "")

if (NOT CLANG_FORMAT)
  find_program(CLANG_FORMAT "clang-format")
endif()
if (CLANG_FORMAT)
  message(STATUS "Clang-format.........: ${CLANG_FORMAT}")
  file(GLOB_RECURSE
       ALL_CXX_SOURCE_FILES
       ${PROJECT_SOURCE_DIR}/src/*.h
       ${PROJECT_SOURCE_DIR}/src/*.cc
  )

  add_custom_target(
      format
      COMMAND ${CLANG_FORMAT} -i ${ALL_CXX_SOURCE_FILES}
  )
endif()

message(STATUS "")

function(dusk_compile_options TARGET)
  target_include_directories(${TARGET} PRIVATE "${PROJECT_SOURCE_DIR}")

  target_compile_options(${TARGET} PRIVATE
    -O3
    -fno-rtti
    -fno-exceptions
    -fvisibility=hidden
    -Wall
    -Werror
    -Wextra
    -Wpedantic
    -pedantic-errors

    -Wno-unknown-pragmas
  )

  if (("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") OR
      ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang"))
    target_compile_options(${TARGET} PRIVATE
      -Weverything

      -Wno-switch-default
      -Wno-switch-enum
      -Wno-c++98-compat
      -Wno-c++98-compat-pedantic
      -Wno-documentation
      -Wno-documentation-unknown-command
      -Wno-poison-system-directories
      -Wno-unsafe-buffer-usage
    )
  elseif(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${TARGET} PRIVATE
      -Wno-missing-field-initializers
    )
  endif()
endfunction()

add_subdirectory(third_party)
add_subdirectory(src)
