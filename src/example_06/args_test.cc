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

#include "src/example_06/args.h"

#include "gtest/gtest.h"

namespace dusk {
namespace {

using ArgsTest = testing::Test;

TEST_F(ArgsTest, NoArgs) {
  Args a;
  auto ret = a.Parse(std::span<const char*>{}, {});
  EXPECT_FALSE(ret.has_value());
}

TEST_F(ArgsTest, OnlyName) {
  Args a;
  std::vector<const char*> argv = {"ProgName"};
  std::span<const char*> s(argv.data(), argv.size());
  auto ret = a.Parse(s, {});
  EXPECT_FALSE(ret.has_value());
  EXPECT_EQ(a.ExeName(), "ProgName");
}

TEST_F(ArgsTest, WithFiles) {
  Args a;
  std::vector<const char*> argv = {"ProgName", "File1", "File2"};
  std::span<const char*> s(argv.data(), argv.size());
  auto ret = a.Parse(s, {});
  EXPECT_FALSE(ret.has_value());
  EXPECT_EQ(a.Files().size(), 2);
  EXPECT_EQ(a.Files()[0], "File1");
  EXPECT_EQ(a.Files()[1], "File2");
}

TEST_F(ArgsTest, WithArgs) {
  Args a;
  std::vector<const char*> argv = {"ProgName", "--bool", "--str", "val"};
  std::span<const char*> s(argv.data(), argv.size());
  auto ret = a.Parse(
      s, {{"bool", Args::Type::kBoolean}, {"str", Args::Type::kString}});
  EXPECT_FALSE(ret.has_value());
  EXPECT_TRUE(a.Files().empty());
  EXPECT_TRUE(a.HasFlag("bool"));
  EXPECT_TRUE(a.HasFlag("str"));
  EXPECT_FALSE(a.HasFlag("other"));
  EXPECT_EQ(a.StringForFlag("str"), "val");
}

TEST_F(ArgsTest, UnknownArg) {
  Args a;
  std::vector<const char*> argv = {"ProgName", "--bool", "--str", "val"};
  std::span<const char*> s(argv.data(), argv.size());
  auto ret = a.Parse(s, {{"str", Args::Type::kString}});
  EXPECT_TRUE(ret.has_value());
  EXPECT_EQ("Unknown option: bool", ret.value());
}

TEST_F(ArgsTest, StringMissingValueEndOfArgs) {
  Args a;
  std::vector<const char*> argv = {"ProgName", "--bool", "--str"};
  std::span<const char*> s(argv.data(), argv.size());
  auto ret = a.Parse(
      s, {{"bool", Args::Type::kBoolean}, {"str", Args::Type::kString}});
  EXPECT_TRUE(ret.has_value());
  EXPECT_EQ("Missing value for: str", ret.value());
}

TEST_F(ArgsTest, StringMissingValue) {
  Args a;
  std::vector<const char*> argv = {"ProgName", "--str", "--bool"};
  std::span<const char*> s(argv.data(), argv.size());
  auto ret = a.Parse(
      s, {{"bool", Args::Type::kBoolean}, {"str", Args::Type::kString}});
  EXPECT_TRUE(ret.has_value());
  EXPECT_EQ("Missing value for: str", ret.value());
}

TEST_F(ArgsTest, ShortName) {
  Args a;
  std::vector<const char*> argv = {"ProgName", "-h", "--H"};
  std::span<const char*> s(argv.data(), argv.size());
  auto ret =
      a.Parse(s, {{"h", Args::Type::kBoolean}, {"H", Args::Type::kBoolean}});
  EXPECT_FALSE(ret.has_value());
  EXPECT_TRUE(a.Files().empty());
  EXPECT_TRUE(a.HasFlag("h"));
  EXPECT_TRUE(a.HasFlag("H"));
  EXPECT_FALSE(a.HasFlag("other"));
}

}  // namespace
}  // namespace dusk

