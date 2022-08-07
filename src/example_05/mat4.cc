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

#include "src/example_05/mat4.h"

#include <cmath>

namespace dusk {

// static
Mat4 Mat4::Identity() {
  // clang-format off
  return Mat4{
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1};
  // clang-format on
}

// static
Mat4 Mat4::Perspective(float fov_y_radians,
                       float aspect,
                       float near,
                       float far) {
  float tan_half_fov_y = 1.f / std::tan(fov_y_radians / 2.f);
  float dist = 1.f / (near - far);

  // clang-format off
  return Mat4{
    tan_half_fov_y / aspect, 0, 0, 0,
    0, tan_half_fov_y, 0, 0,
    0, 0, far * dist, -1,
    0, 0, (far * near) * dist, 0};
  // clang-format on
}

// static
Mat4 Mat4::Translation(const Vec3& v) {
  auto m = Mat4::Identity();
  m.data_[12] = v.x();
  m.data_[13] = v.y();
  m.data_[14] = v.z();
  return m;
}

// From https://ksuweb.kennesaw.edu/~plaval/math4490/rotgen.pdf
// Rotation about an arbitrary angle.
//
// static
Mat4 Mat4::Rotation(float radians, const Vec3& angle) {
  auto r = angle.Normalize();
  auto x = r.x();
  auto y = r.y();
  auto z = r.z();
  auto C = cosf(radians);
  auto S = sinf(radians);
  auto t = 1.f - C;

  auto txy = t * x * y;
  auto txz = t * z * z;
  auto tyz = t * y * z;
  auto Sz = S * z;
  auto Sy = S * y;
  auto Sx = S * x;

  // clang-format off
  return Mat4{
    (t * x * x) + C, txy + Sz, txz - Sy, 0,
    txy - Sz, (t * y * y) + C, tyz + Sx, 0,
    txz + Sy, tyz - Sx, (t * z * z) + C, 0,
    0, 0, 0, 1
  };
  // clang-format on
}

Mat4 Mat4::operator*(const Mat4& o) const {
  float r00 = At(0, 0) * o.At(0, 0) + At(1, 0) * o.At(0, 1) +
              At(2, 0) * o.At(0, 2) + At(3, 0) * o.At(0, 3);
  float r01 = At(0, 1) * o.At(0, 0) + At(1, 1) * o.At(0, 1) +
              At(2, 1) * o.At(0, 2) + At(3, 1) * o.At(0, 3);
  float r02 = At(0, 2) * o.At(0, 0) + At(1, 2) * o.At(0, 1) +
              At(2, 2) * o.At(0, 2) + At(3, 2) * o.At(0, 3);
  float r03 = At(0, 3) * o.At(0, 0) + At(1, 3) * o.At(0, 1) +
              At(2, 3) * o.At(0, 2) + At(3, 3) * o.At(0, 3);

  float r10 = At(0, 0) * o.At(1, 0) + At(1, 0) * o.At(1, 1) +
              At(2, 0) * o.At(1, 2) + At(3, 0) * o.At(1, 3);
  float r11 = At(0, 1) * o.At(1, 0) + At(1, 1) * o.At(1, 1) +
              At(2, 1) * o.At(1, 2) + At(3, 1) * o.At(1, 3);
  float r12 = At(0, 2) * o.At(1, 0) + At(1, 2) * o.At(1, 1) +
              At(2, 2) * o.At(1, 2) + At(3, 2) * o.At(1, 3);
  float r13 = At(0, 3) * o.At(1, 0) + At(1, 3) * o.At(1, 1) +
              At(2, 3) * o.At(1, 2) + At(3, 3) * o.At(1, 3);

  float r20 = At(0, 0) * o.At(2, 0) + At(1, 0) * o.At(2, 1) +
              At(2, 0) * o.At(2, 2) + At(3, 0) * o.At(2, 3);
  float r21 = At(0, 1) * o.At(2, 0) + At(1, 1) * o.At(2, 1) +
              At(2, 1) * o.At(2, 2) + At(3, 1) * o.At(2, 3);
  float r22 = At(0, 2) * o.At(2, 0) + At(1, 2) * o.At(2, 1) +
              At(2, 2) * o.At(2, 2) + At(3, 2) * o.At(2, 3);
  float r23 = At(0, 3) * o.At(2, 0) + At(1, 3) * o.At(2, 1) +
              At(2, 3) * o.At(2, 2) + At(3, 3) * o.At(2, 3);

  float r30 = At(0, 0) * o.At(3, 0) + At(1, 0) * o.At(3, 1) +
              At(2, 0) * o.At(3, 2) + At(3, 0) * o.At(3, 3);
  float r31 = At(0, 1) * o.At(3, 0) + At(1, 1) * o.At(3, 1) +
              At(2, 1) * o.At(3, 2) + At(3, 1) * o.At(3, 3);
  float r32 = At(0, 2) * o.At(3, 0) + At(1, 2) * o.At(3, 1) +
              At(2, 2) * o.At(3, 2) + At(3, 2) * o.At(3, 3);
  float r33 = At(0, 3) * o.At(3, 0) + At(1, 3) * o.At(3, 1) +
              At(2, 3) * o.At(3, 2) + At(3, 3) * o.At(3, 3);

  // clang-format off
  return Mat4{
    r00, r01, r02, r03,
    r10, r11, r12, r13,
    r20, r21, r22, r23,
    r30, r31, r32, r33};
  // clang-format on
}

}  // namespace dusk
