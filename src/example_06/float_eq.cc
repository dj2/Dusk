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

#include "src/example_06/float_eq.h"

#include <cmath>

namespace dusk {
namespace {

constexpr float kEpsilon = 0.0000001f;

}  // namespace

bool float_eq(float a, float b) {
  return std::fabs(a - b) < kEpsilon;
}

}  // namespace dusk
