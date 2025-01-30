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

#include <cmath>

#pragma once

namespace dusk {

/// A vector in 3-space
class Vec3 {
 public:
  /// Creates a new vector with the given values
  Vec3(float x, float y, float z) : x_(x), y_(y), z_(z) {}

  /// Returns the length of the vector
  float length() const { return sqrtf((x_ * x_) + (y_ * y_) + (z_ * z_)); }

  /// Returns the normalized version of the vector
  Vec3 normalize() const {
    auto l = length();
    if (l == 0.0f) {
      return Vec3{0., 0., 0.};
    }

    auto inv = 1 / l;
    return Vec3{x_ * inv, y_ * inv, z_ * inv};
  }

  inline float x() const { return x_; }
  inline float y() const { return y_; }
  inline float z() const { return z_; }

 private:
  float x_ = 0;
  float y_ = 0;
  float z_ = 0;
};

}  // namespace dusk
