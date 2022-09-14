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

class Vec4 {
 public:
  Vec4(float x, float y, float z, float w) : x_(x), y_(y), z_(z), w_(w) {}

  float Length() const {
    return sqrtf((x_ * x_) + (y_ * y_) + (z_ * z_) + (w_ * w_));
  }

  Vec4 Normalize() const {
    auto l = Length();
    if (l == 0.0f) {
      return Vec4{0., 0., 0., 0.};
    }

    auto inv = 1 / l;
    return Vec4{x_ * inv, y_ * inv, z_ * inv, w_ * inv};
  }

  bool operator==(const Vec4& o) const {
    return float_eq(x_, o.x_) && float_eq(y_, o.y_) && float_eq(z_, o.z_) &&
           float_eq(w_, o.w_);
  }

  inline float x() const { return x_; }
  inline float y() const { return y_; }
  inline float z() const { return z_; }
  inline float w() const { return w_; }

 private:
  float x_ = 0;
  float y_ = 0;
  float z_ = 0;
  float w_ = 1;
};

}  // namespace dusk
