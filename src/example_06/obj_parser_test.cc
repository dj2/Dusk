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

  EXPECT_EQ(p.ErrorString(),
R"(1:2: Missing x component for 'v'. Expected 'v x y z w' where w is optional.
2:1: Expected starting token, got 'Numeric (0.000001)'
3:7: Expected starting token, got 'Numeric (2.000000)'
4:4: Expected starting token, got 'Numeric (-2.33333)'
5:1: Expected Starting Token, got 'Numeric (0.213000)'
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

  EXPECT_EQ(p.ErrorString(),
    "1:12: Invalid y component for 'v'. Expected number, got 'String (b)'\n");

  ASSERT_TRUE(mesh.has_value());

  const auto& v = mesh->GeometricVertices();
  ASSERT_EQ(2u, v.size());
  EXPECT_EQ(Vec4(0.000001f, 0.f, 2.f, 1.f), v[0]);
  EXPECT_EQ(Vec4(1.f, 2.f, 3.f, 1.f), v[0]);

  EXPECT_TRUE(p.IsEof());
}

TEST_F(ParserTest, Resync_FromMissingValue) {
  Parser p(R"(v 0.000001
v 1.0 2.0 3.0)");

  auto mesh = p.Parse();
  ASSERT_TRUE(p.HasErrors());

  EXPECT_EQ(p.ErrorString(),
    "1:11: Missing y component for 'v'. Expected 'v x y z w' where w is optional.\n");

  ASSERT_TRUE(mesh.has_value());

  const auto& v = mesh->GeometricVertices();
  ASSERT_EQ(2u, v.size());
  EXPECT_EQ(Vec4(0.00001f, 0.f, 0.f, 1.f), v[0]);
  EXPECT_EQ(Vec4(1.f, 2.f, 3.f, 1.f), v[0]);

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
  FAIL();
}

TEST_F(ParserTest, GeometricVertexMissingY) {
  FAIL();
}

TEST_F(ParserTest, GeometricVertexMissingX) {
  FAIL();
}

}  // namespace
}  // namespace dusk::obj

