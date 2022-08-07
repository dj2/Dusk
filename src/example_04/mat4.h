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

#pragma once

#include <cstddef>

#include "src/example_04/vec3.h"

namespace dusk {

// Column major matrix
class Mat4 {
 public:
  Mat4() = default;
  // clang-format off
  Mat4(float a, float b, float c, float d,  // first-column
       float e, float f, float g, float h,  // second-column
       float i, float j, float k, float l,  // third-column
       float m, float n, float o, float p)  // fourth-column
      : data_{a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p} {}
  // clang-format on
  Mat4(Mat4&&) = default;
  ~Mat4() = default;

  Mat4& operator=(Mat4&&) = default;

  static Mat4 Identity();
  static Mat4 Perspective(float fov_y_radians,
                          float aspect,
                          float near,
                          float far);
  static Mat4 Translation(const Vec3& v);
  static Mat4 Rotation(float radians, const Vec3& angle);

  float At(size_t col, size_t row) const { return data_[(col * 4) + row]; }

  Mat4 operator*(const Mat4& o) const;

  float const* Data() const { return data_; }

 private:
  float data_[16] = {0};
};

}  // namespace dusk
