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

#include "src/common/mat4.h"

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
  auto r = angle.normalize();
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
  float r00 = at(0, 0) * o.at(0, 0) + at(1, 0) * o.at(0, 1) +
              at(2, 0) * o.at(0, 2) + at(3, 0) * o.at(0, 3);
  float r01 = at(0, 1) * o.at(0, 0) + at(1, 1) * o.at(0, 1) +
              at(2, 1) * o.at(0, 2) + at(3, 1) * o.at(0, 3);
  float r02 = at(0, 2) * o.at(0, 0) + at(1, 2) * o.at(0, 1) +
              at(2, 2) * o.at(0, 2) + at(3, 2) * o.at(0, 3);
  float r03 = at(0, 3) * o.at(0, 0) + at(1, 3) * o.at(0, 1) +
              at(2, 3) * o.at(0, 2) + at(3, 3) * o.at(0, 3);

  float r10 = at(0, 0) * o.at(1, 0) + at(1, 0) * o.at(1, 1) +
              at(2, 0) * o.at(1, 2) + at(3, 0) * o.at(1, 3);
  float r11 = at(0, 1) * o.at(1, 0) + at(1, 1) * o.at(1, 1) +
              at(2, 1) * o.at(1, 2) + at(3, 1) * o.at(1, 3);
  float r12 = at(0, 2) * o.at(1, 0) + at(1, 2) * o.at(1, 1) +
              at(2, 2) * o.at(1, 2) + at(3, 2) * o.at(1, 3);
  float r13 = at(0, 3) * o.at(1, 0) + at(1, 3) * o.at(1, 1) +
              at(2, 3) * o.at(1, 2) + at(3, 3) * o.at(1, 3);

  float r20 = at(0, 0) * o.at(2, 0) + at(1, 0) * o.at(2, 1) +
              at(2, 0) * o.at(2, 2) + at(3, 0) * o.at(2, 3);
  float r21 = at(0, 1) * o.at(2, 0) + at(1, 1) * o.at(2, 1) +
              at(2, 1) * o.at(2, 2) + at(3, 1) * o.at(2, 3);
  float r22 = at(0, 2) * o.at(2, 0) + at(1, 2) * o.at(2, 1) +
              at(2, 2) * o.at(2, 2) + at(3, 2) * o.at(2, 3);
  float r23 = at(0, 3) * o.at(2, 0) + at(1, 3) * o.at(2, 1) +
              at(2, 3) * o.at(2, 2) + at(3, 3) * o.at(2, 3);

  float r30 = at(0, 0) * o.at(3, 0) + at(1, 0) * o.at(3, 1) +
              at(2, 0) * o.at(3, 2) + at(3, 0) * o.at(3, 3);
  float r31 = at(0, 1) * o.at(3, 0) + at(1, 1) * o.at(3, 1) +
              at(2, 1) * o.at(3, 2) + at(3, 1) * o.at(3, 3);
  float r32 = at(0, 2) * o.at(3, 0) + at(1, 2) * o.at(3, 1) +
              at(2, 2) * o.at(3, 2) + at(3, 2) * o.at(3, 3);
  float r33 = at(0, 3) * o.at(3, 0) + at(1, 3) * o.at(3, 1) +
              at(2, 3) * o.at(3, 2) + at(3, 3) * o.at(3, 3);

  // clang-format off
  return Mat4{
    r00, r01, r02, r03,
    r10, r11, r12, r13,
    r20, r21, r22, r23,
    r30, r31, r32, r33};
  // clang-format on
}

}  // namespace dusk
