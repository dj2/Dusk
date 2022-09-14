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

#include "src/example_06/obj_parser.h"

#include "gtest/gtest.h"
#include "src/example_06/ostream_helper.h"

namespace dusk::obj {
namespace {

using ParserTest = testing::Test;

TEST_F(ParserTest, Empty) {
  Parser p("");
  auto mesh = p.Parse();
  ASSERT_FALSE(p.HasErrors()) << p.ErrorString();
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();
  ASSERT_TRUE(mesh.has_value());

  const auto& g = mesh->Groups();
  ASSERT_EQ(1u, g.size());
  EXPECT_EQ("default", g[0].Name());
}

TEST_F(ParserTest, SkipsComments) {
  Parser p("# this is a comment");
  auto mesh = p.Parse();
  ASSERT_TRUE(mesh.has_value());

  EXPECT_TRUE(p.IsEof());
}

TEST_F(ParserTest, LineContinuation) {
  Parser p(R"(v \
0.000001 \
      2 \
   -2.33333 \
\
\
.213)");
  auto mesh = p.Parse();
  ASSERT_TRUE(mesh.has_value());

  const auto& v = mesh->GeometricVertices();
  ASSERT_EQ(1u, v.size());
  EXPECT_EQ(Vec4(0.000001f, 2.f, -2.33333f, .213f), v[0]);

  EXPECT_TRUE(p.IsEof());
}

TEST_F(ParserTest, LineOriented) {
  Parser p(R"(v
0.000001
      2
   -2.33333
.213)");
  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();

  EXPECT_EQ(p.ErrorString(),
            R"(1:2: Found the end of the line, expected the x component for 'v'.
    Format is 'v x y z w' where w is optional with default value of 1.
    Lines may be continued by adding a \ before the newline.

2:1: Expected starting token, got Numeric (0.000001)

3:7: Expected starting token, got Numeric (2.000000)

4:4: Expected starting token, got Numeric (-2.333330)

5:1: Expected starting token, got Numeric (0.213000)

)");

  ASSERT_TRUE(mesh.has_value());
  EXPECT_EQ(1u, mesh->GeometricVertices().size());
  EXPECT_EQ(Vec4(0.f, 0.f, 0.f, 1.f), mesh->GeometricVertices()[0]);
}

TEST_F(ParserTest, Resync_FromInvalidValue) {
  Parser p(R"(v 0.000001 b 2
v 1.0 2.0 3.0)");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();

  EXPECT_EQ(p.ErrorString(),
            R"(1:12: Invalid y component for 'v'.
    Expected number, got String (b).

)");

  ASSERT_TRUE(mesh.has_value());

  const auto& v = mesh->GeometricVertices();
  ASSERT_EQ(2u, v.size());
  EXPECT_EQ(Vec4(1e-6f, 0.f, 2.f, 1.f), v[0]);
  EXPECT_EQ(Vec4(1.f, 2.f, 3.f, 1.f), v[1]);

  EXPECT_TRUE(p.IsEof());
}

TEST_F(ParserTest, Resync_FromMissingValue) {
  Parser p(R"(v 0.000001
v 1.0 2.0 3.0)");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();

  EXPECT_EQ(
      p.ErrorString(),
      R"(1:11: Found the end of the line, expected the y component for 'v'.
    Format is 'v x y z w' where w is optional with default value of 1.
    Lines may be continued by adding a \ before the newline.

)");

  ASSERT_TRUE(mesh.has_value());

  const auto& v = mesh->GeometricVertices();
  ASSERT_EQ(2u, v.size());
  EXPECT_EQ(Vec4(1e-6f, 0.f, 0.f, 1.f), v[0]);
  EXPECT_EQ(Vec4(1.f, 2.f, 3.f, 1.f), v[1]);

  EXPECT_TRUE(p.IsEof());
}

TEST_F(ParserTest, GeometricVertexWithoutW) {
  Parser p("v 0.000001 2 -2.33333");
  auto mesh = p.Parse();
  ASSERT_TRUE(mesh.has_value());

  const auto& v = mesh->GeometricVertices();
  ASSERT_EQ(1u, v.size());
  EXPECT_EQ(Vec4(0.000001f, 2.f, -2.33333f, 1.f), v[0]);

  EXPECT_TRUE(p.IsEof());
}

TEST_F(ParserTest, GeometricVertexWithW) {
  Parser p("v 0.000001 2 -2.33333 .213");
  auto mesh = p.Parse();
  ASSERT_TRUE(mesh.has_value());

  const auto& v = mesh->GeometricVertices();
  ASSERT_EQ(1u, v.size());
  EXPECT_EQ(Vec4(0.000001f, 2.f, -2.33333f, .213f), v[0]);

  EXPECT_TRUE(p.IsEof());
}

TEST_F(ParserTest, GeometricVertexMissingZ) {
  Parser p("v 0.000001 1 ");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();

  EXPECT_EQ(
      p.ErrorString(),
      R"(1:13: Found the end of the line, expected the z component for 'v'.
    Format is 'v x y z w' where w is optional with default value of 1.
    Lines may be continued by adding a \ before the newline.

)");

  ASSERT_TRUE(mesh.has_value());

  const auto& v = mesh->GeometricVertices();
  ASSERT_EQ(1u, v.size());
  EXPECT_EQ(Vec4(1e-6f, 1.f, 0.f, 1.f), v[0]);

  EXPECT_TRUE(p.IsEof());
}

TEST_F(ParserTest, GeometricVertexInvalidZ) {
  Parser p("v 0.000001 1 z");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();

  EXPECT_EQ(p.ErrorString(),
            R"(1:14: Invalid z component for 'v'.
    Expected number, got String (z).

)");

  ASSERT_TRUE(mesh.has_value());

  const auto& v = mesh->GeometricVertices();
  ASSERT_EQ(1u, v.size());
  EXPECT_EQ(Vec4(1e-6f, 1.f, 0.f, 1.f), v[0]);

  EXPECT_TRUE(p.IsEof());
}

TEST_F(ParserTest, GeometricVertexMissingY) {
  Parser p("v 0.000001  ");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();

  EXPECT_EQ(
      p.ErrorString(),
      R"(1:11: Found the end of the line, expected the y component for 'v'.
    Format is 'v x y z w' where w is optional with default value of 1.
    Lines may be continued by adding a \ before the newline.

)");

  ASSERT_TRUE(mesh.has_value());

  const auto& v = mesh->GeometricVertices();
  ASSERT_EQ(1u, v.size());
  EXPECT_EQ(Vec4(1e-6f, 0.f, 0.f, 1.f), v[0]);

  EXPECT_TRUE(p.IsEof());
}

TEST_F(ParserTest, GeometricVertexInvalidY) {
  Parser p("v 0.000001 y 1");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();

  EXPECT_EQ(p.ErrorString(),
            R"(1:12: Invalid y component for 'v'.
    Expected number, got String (y).

)");

  ASSERT_TRUE(mesh.has_value());

  const auto& v = mesh->GeometricVertices();
  ASSERT_EQ(1u, v.size());
  EXPECT_EQ(Vec4(1e-6f, 0.f, 1.f, 1.f), v[0]);

  EXPECT_TRUE(p.IsEof());
}

TEST_F(ParserTest, GeometricVertexMissingX) {
  Parser p("v  ");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();

  EXPECT_EQ(p.ErrorString(),
            R"(1:2: Found the end of the line, expected the x component for 'v'.
    Format is 'v x y z w' where w is optional with default value of 1.
    Lines may be continued by adding a \ before the newline.

)");

  ASSERT_TRUE(mesh.has_value());

  const auto& v = mesh->GeometricVertices();
  ASSERT_EQ(1u, v.size());
  EXPECT_EQ(Vec4(0.f, 0.f, 0.f, 1.f), v[0]);

  EXPECT_TRUE(p.IsEof());
}

TEST_F(ParserTest, GeometricVertexInvalidX) {
  Parser p("v x 2 1");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();

  EXPECT_EQ(p.ErrorString(),
            R"(1:3: Invalid x component for 'v'.
    Expected number, got String (x).

)");

  ASSERT_TRUE(mesh.has_value());

  const auto& v = mesh->GeometricVertices();
  ASSERT_EQ(1u, v.size());
  EXPECT_EQ(Vec4(0.f, 2.f, 1.f, 1.f), v[0]);

  EXPECT_TRUE(p.IsEof());
}

TEST_F(ParserTest, ParameterPoint) {
  Parser p("vp 1.0 2.33 -3.4");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasWarnings());
  ASSERT_FALSE(p.HasErrors()) << p.ErrorString();

  EXPECT_EQ(p.WarningString(),
            R"(1:1: Unhandled command: vp. Skipping.

)");

  EXPECT_TRUE(p.IsEof());
}

TEST_F(ParserTest, ContinueAfterParameterPoint) {
  Parser p(R"(vp 1.0 2.33 -3.4
v .3 .4 .5)");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasWarnings());
  ASSERT_FALSE(p.HasErrors()) << p.ErrorString();

  EXPECT_EQ(p.WarningString(),
            R"(1:1: Unhandled command: vp. Skipping.

)");

  ASSERT_TRUE(mesh.has_value());

  const auto& v = mesh->GeometricVertices();
  ASSERT_EQ(1u, v.size());
  EXPECT_EQ(Vec4(0.3f, 0.4f, 0.5f, 1.0f), v[0]);

  EXPECT_TRUE(p.IsEof());
}

TEST_F(ParserTest, VertexNormal) {
  Parser p("vn 2.45 3.00005 2.9");

  auto mesh = p.Parse();
  ASSERT_FALSE(p.HasErrors()) << p.ErrorString();
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();
  ASSERT_TRUE(mesh.has_value());

  const auto& n = mesh->VertexNormals();
  ASSERT_EQ(1u, n.size());
  EXPECT_EQ(Vec3(2.45f, 3.00005f, 2.9f), n[0]);
}

TEST_F(ParserTest, VertexNormalMissingK) {
  Parser p("vn 2.45 3.00005 ");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();
  ASSERT_TRUE(mesh.has_value());

  EXPECT_EQ(
      p.ErrorString(),
      R"(1:16: Found the end of the line, expected the k component for 'vn'.
    Format is 'vn i j k'.
    Lines may be continued by adding a \ before the newline.

)");

  const auto& n = mesh->VertexNormals();
  ASSERT_EQ(1u, n.size());
  EXPECT_EQ(Vec3(2.45f, 3.00005f, 0.f), n[0]);
}

TEST_F(ParserTest, VertexNormalInvalidK) {
  Parser p("vn 2.45 3.00005 k");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();
  ASSERT_TRUE(mesh.has_value());

  EXPECT_EQ(p.ErrorString(),
            R"(1:17: Invalid k component for 'vn'.
    Expected number, got String (k).

)");

  const auto& n = mesh->VertexNormals();
  ASSERT_EQ(1u, n.size());
  EXPECT_EQ(Vec3(2.45f, 3.00005f, 0.f), n[0]);
}

TEST_F(ParserTest, VertexNormalMissingJ) {
  Parser p("vn 2.45");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();
  ASSERT_TRUE(mesh.has_value());

  EXPECT_EQ(
      p.ErrorString(),
      R"(1:8: Found the end of the line, expected the j component for 'vn'.
    Format is 'vn i j k'.
    Lines may be continued by adding a \ before the newline.

)");

  const auto& n = mesh->VertexNormals();
  ASSERT_EQ(1u, n.size());
  EXPECT_EQ(Vec3(2.45f, 0.f, 0.f), n[0]);
}

TEST_F(ParserTest, VertexNormalInvalidJ) {
  Parser p("vn 2.45 j -3.245");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();
  ASSERT_TRUE(mesh.has_value());

  EXPECT_EQ(p.ErrorString(),
            R"(1:9: Invalid j component for 'vn'.
    Expected number, got String (j).

)");

  const auto& n = mesh->VertexNormals();
  ASSERT_EQ(1u, n.size());
  EXPECT_EQ(Vec3(2.45f, 0.f, -3.245f), n[0]);
}

TEST_F(ParserTest, VertexNormalMissingI) {
  Parser p("vn ");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();
  ASSERT_TRUE(mesh.has_value());

  EXPECT_EQ(
      p.ErrorString(),
      R"(1:3: Found the end of the line, expected the i component for 'vn'.
    Format is 'vn i j k'.
    Lines may be continued by adding a \ before the newline.

)");

  const auto& n = mesh->VertexNormals();
  ASSERT_EQ(1u, n.size());
  EXPECT_EQ(Vec3(0.f, 0.f, 0.f), n[0]);
}

TEST_F(ParserTest, VertexNormalInvalidI) {
  Parser p("vn i 2.45 -3.245");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();
  ASSERT_TRUE(mesh.has_value());

  EXPECT_EQ(p.ErrorString(),
            R"(1:4: Invalid i component for 'vn'.
    Expected number, got String (i).

)");

  const auto& n = mesh->VertexNormals();
  ASSERT_EQ(1u, n.size());
  EXPECT_EQ(Vec3(0.f, 2.45f, -3.245f), n[0]);
}

TEST_F(ParserTest, TextureVertex) {
  Parser p("vt 2.45");

  auto mesh = p.Parse();
  ASSERT_FALSE(p.HasErrors()) << p.ErrorString();
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();
  ASSERT_TRUE(mesh.has_value());

  const auto& n = mesh->TextureVertices();
  ASSERT_EQ(1u, n.size());
  EXPECT_EQ(Vec3(2.45f, 0.f, 0.f), n[0]);
}

TEST_F(ParserTest, TextureVertexWithV) {
  Parser p("vt 2.45 -3.4");

  auto mesh = p.Parse();
  ASSERT_FALSE(p.HasErrors()) << p.ErrorString();
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();
  ASSERT_TRUE(mesh.has_value());

  const auto& n = mesh->TextureVertices();
  ASSERT_EQ(1u, n.size());
  EXPECT_EQ(Vec3(2.45f, -3.4f, 0.f), n[0]);
}

TEST_F(ParserTest, TextureVertexWithW) {
  Parser p("vt 2.45 -3.4 .0000004");

  auto mesh = p.Parse();
  ASSERT_FALSE(p.HasErrors()) << p.ErrorString();
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();
  ASSERT_TRUE(mesh.has_value());

  const auto& n = mesh->TextureVertices();
  ASSERT_EQ(1u, n.size());
  EXPECT_EQ(Vec3(2.45f, -3.4f, 4e-7f), n[0]);
}

TEST_F(ParserTest, TextureVertexMissingU) {
  Parser p("vt ");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();
  ASSERT_TRUE(mesh.has_value());

  EXPECT_EQ(
      p.ErrorString(),
      R"(1:3: Found the end of the line, expected the u component for 'vt'.
    Format is 'vt u v w' where v and w are optional with default values of 0.
    Lines may be continued by adding a \ before the newline.

)");

  const auto& n = mesh->TextureVertices();
  ASSERT_EQ(1u, n.size());
  EXPECT_EQ(Vec3(0.f, 0.f, 0.f), n[0]);
}

TEST_F(ParserTest, TextureVertexInvalidU) {
  Parser p("vt u 2.45 -3.4");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();
  ASSERT_TRUE(mesh.has_value());

  EXPECT_EQ(p.ErrorString(),
            R"(1:4: Invalid u component for 'vt'.
    Expected number, got String (u).

)");

  const auto& n = mesh->TextureVertices();
  ASSERT_EQ(1u, n.size());
  EXPECT_EQ(Vec3(0.f, 2.45f, -3.4f), n[0]);
}

TEST_F(ParserTest, TextureVertexInvalidV) {
  Parser p("vt 2.45 v -3.4");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();
  ASSERT_TRUE(mesh.has_value());

  EXPECT_EQ(p.ErrorString(),
            R"(1:9: Invalid v component for 'vt'.
    Expected number, got String (v).

)");

  const auto& n = mesh->TextureVertices();
  ASSERT_EQ(1u, n.size());
  EXPECT_EQ(Vec3(2.45f, 0.f, -3.4f), n[0]);
}

TEST_F(ParserTest, TextureVertexInvalidW) {
  Parser p("vt 2.45 -3.4 w");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());
  ASSERT_FALSE(p.HasWarnings()) << p.WarningString();
  ASSERT_TRUE(mesh.has_value());

  EXPECT_EQ(p.ErrorString(),
            R"(1:14: Invalid w component for 'vt'.
    Expected number, got String (w).

)");

  const auto& n = mesh->TextureVertices();
  ASSERT_EQ(1u, n.size());
  EXPECT_EQ(Vec3(2.45f, -3.4f, 0.f), n[0]);
}

}  // namespace
}  // namespace dusk::obj
