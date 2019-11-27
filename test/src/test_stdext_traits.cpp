#include <gtest/gtest.h>
#include <stdex/std_type_sets.h>

// This file is part of stdex library, stdex is an extension of the c++-standard library,
// especially the type traits for standard containers.
//
// Copyright (C) 2019 Vahid Dzanic <vdc@gmx.ch>
//
// stdex is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 3 of the License, or (at your option) any later version.
//
// Alternatively, you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// stdex is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License or the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License and a copy of the GNU General Public License along with
// stdex. If not, see <http://www.gnu.org/licenses/>.

template<typename _Tp>
class test_fixture_raw : public ::testing::Test
{};

using raw_type = std::uint64_t;

typedef ::testing::Types<raw_type,
                         raw_type*,
                         raw_type&,
                         raw_type&&,
                         const raw_type,
                         const raw_type*,
                         const raw_type&,
                         const raw_type&&,
                         volatile raw_type,
                         volatile raw_type*,
                         volatile raw_type&,
                         volatile raw_type&&,
                         const volatile raw_type,
                         const volatile raw_type*,
                         const volatile raw_type&,
                         const volatile raw_type&&>
  types_to_test_raw;

TYPED_TEST_CASE(test_fixture_raw, types_to_test_raw);

TYPED_TEST(test_fixture_raw, test_expecting_true)
{
  bool bValue = std::is_same<raw_type, typename stdex::traits::raw<TypeParam>::type>::value;
  EXPECT_TRUE(bValue);
}

TEST(TestTraitsExt, test_raw_type)
{
  bool bValue = false;
  bValue = std::is_same<raw_type, typename stdex::traits::raw<raw_type>::type>::value;
  EXPECT_TRUE(bValue);
  bValue = std::is_same<raw_type, typename stdex::traits::raw<raw_type*>::type>::value;
  EXPECT_TRUE(bValue);
  bValue = std::is_same<raw_type, typename stdex::traits::raw<raw_type&>::type>::value;
  EXPECT_TRUE(bValue);
  bValue = std::is_same<raw_type, typename stdex::traits::raw<raw_type&&>::type>::value;
  EXPECT_TRUE(bValue);
  bValue = std::is_same<raw_type, typename stdex::traits::raw<const raw_type>::type>::value;
  EXPECT_TRUE(bValue);
  bValue = std::is_same<raw_type, typename stdex::traits::raw<const raw_type*>::type>::value;
  EXPECT_TRUE(bValue);
  bValue = std::is_same<raw_type, typename stdex::traits::raw<const raw_type&>::type>::value;
  EXPECT_TRUE(bValue);
  bValue = std::is_same<raw_type, typename stdex::traits::raw<const raw_type&&>::type>::value;
  EXPECT_TRUE(bValue);
  bValue = std::is_same<raw_type, typename stdex::traits::raw<volatile raw_type>::type>::value;
  EXPECT_TRUE(bValue);
  bValue = std::is_same<raw_type, typename stdex::traits::raw<volatile raw_type*>::type>::value;
  EXPECT_TRUE(bValue);
  bValue = std::is_same<raw_type, typename stdex::traits::raw<volatile raw_type&>::type>::value;
  EXPECT_TRUE(bValue);
  bValue = std::is_same<raw_type, typename stdex::traits::raw<volatile raw_type&&>::type>::value;
  EXPECT_TRUE(bValue);
  bValue = std::is_same<raw_type, typename stdex::traits::raw<const volatile raw_type>::type>::value;
  EXPECT_TRUE(bValue);
  bValue = std::is_same<raw_type, typename stdex::traits::raw<const volatile raw_type*>::type>::value;
  EXPECT_TRUE(bValue);
  bValue = std::is_same<raw_type, typename stdex::traits::raw<const volatile raw_type&>::type>::value;
  EXPECT_TRUE(bValue);
  bValue = std::is_same<raw_type, typename stdex::traits::raw<const volatile raw_type&&>::type>::value;
  EXPECT_TRUE(bValue);
}

template<typename _Tp>
class test_fixture_expect_true : public ::testing::Test
{};

typedef ::testing::Types<bool,
                         char,
                         wchar_t,
                         char16_t,
                         char32_t,
                         float,
                         double,
                         long double,
                         long long,
                         unsigned long long,
                         std::int8_t,
                         std::int16_t,
                         std::int32_t,
                         std::int64_t,
                         std::uint8_t,
                         std::uint16_t,
                         std::uint32_t,
                         std::uint64_t,
                         std::string,
                         std::array<char, 1>,
                         std::vector<char>,
                         std::deque<char>,
                         std::forward_list<char>,
                         std::list<char>,
                         std::stack<char>,
                         std::queue<char>,
                         std::priority_queue<char>,
                         std::set<char>,
                         std::multiset<char>,
                         std::unordered_set<char>,
                         std::unordered_multiset<char>,
                         std::map<char, char>,
                         std::multimap<char, char>,
                         std::unordered_map<char, char>,
                         std::unordered_multimap<char, char>,
                         std::pair<char, char>,
                         std::tuple<char, std::string, int>>
  builtin_and_std_types;

TYPED_TEST_CASE(test_fixture_expect_true, builtin_and_std_types);

TYPED_TEST(test_fixture_expect_true, test_is_std_type)
{
  EXPECT_TRUE(stdex::traits::is_std_type<TypeParam>::value);
  EXPECT_TRUE(stdex::traits::is_std_type<TypeParam*>::value);
  EXPECT_TRUE(stdex::traits::is_std_type<TypeParam&>::value);
  EXPECT_TRUE(stdex::traits::is_std_type<TypeParam&&>::value);
  EXPECT_TRUE(stdex::traits::is_std_type<const TypeParam>::value);
  EXPECT_TRUE(stdex::traits::is_std_type<const TypeParam*>::value);
  EXPECT_TRUE(stdex::traits::is_std_type<const TypeParam&>::value);
  EXPECT_TRUE(stdex::traits::is_std_type<const TypeParam&&>::value);
  EXPECT_TRUE(stdex::traits::is_std_type<volatile TypeParam>::value);
  EXPECT_TRUE(stdex::traits::is_std_type<volatile TypeParam*>::value);
  EXPECT_TRUE(stdex::traits::is_std_type<volatile TypeParam&>::value);
  EXPECT_TRUE(stdex::traits::is_std_type<volatile TypeParam&&>::value);
  EXPECT_TRUE(stdex::traits::is_std_type<const volatile TypeParam>::value);
  EXPECT_TRUE(stdex::traits::is_std_type<const volatile TypeParam*>::value);
  EXPECT_TRUE(stdex::traits::is_std_type<const volatile TypeParam&>::value);
  EXPECT_TRUE(stdex::traits::is_std_type<const volatile TypeParam&&>::value);
}

template<typename _Tp>
class test_fixture_expect_false : public ::testing::Test
{};

class A
{};
struct B
{};
union C
{};
enum D
{};
enum class E
{};

typedef ::testing::Types<A, B, C, D, E, void, A&, A*, A&&, const A, volatile A> not_builtin_and_std_types;

TYPED_TEST_CASE(test_fixture_expect_false, not_builtin_and_std_types);

TYPED_TEST(test_fixture_expect_false, test_is_not_std_type)
{
  EXPECT_FALSE(stdex::traits::is_std_type<TypeParam>::value);
}



//----------------------------------------------------------------------------------------------------------------------
// std::bitset is not implementable now
// std::tuple can't be accessed at dynamicaly at runtime

//#include <iostream>

// template<typename T>
// class A
//{
// public:
//  using value_type=int;
//};

// class B
//{
// public:
//  using value_type=int;
//};

// class C {};

// union E
//{
//  int a;
//  float b;
//};

// struct F {};

// class TestStdExt
//{
// public:
//  static void doTest()
//  {
//    std::cout << std::boolalpha << is_std_pair<C>::value << std::endl;
//    std::cout << std::boolalpha << is_std_pair<std::pair<int,float>>::value << std::endl;
//    std::cout << "------------------------------" << std::endl;
//    std::cout << std::boolalpha << is_sequential_container<C>::value << std::endl;
//    std::cout << std::boolalpha << is_sequential_container<B>::value << std::endl;
//    std::cout << std::boolalpha << is_sequential_container<A<int>>::value << std::endl;
//    std::cout << "------------------------------" << std::endl;
//    std::cout << std::boolalpha << is_sequential_container<std::array<int, 5>>::value << std::endl;
//    std::cout << std::boolalpha << is_sequential_container<std::vector<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_sequential_container<std::deque<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_sequential_container<std::list<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_sequential_container<std::forward_list<int>>::value << std::endl;
//    std::cout << "------------------------------" << std::endl;
//    std::cout << std::boolalpha << is_sequential_container<std::stack<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_sequential_container<std::queue<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_sequential_container<std::priority_queue<int>>::value << std::endl;
//    std::cout << "------------------------------" << std::endl;
//    std::cout << std::boolalpha << is_associative_container<C>::value << std::endl;
//    std::cout << std::boolalpha << is_associative_container<B>::value << std::endl;
//    std::cout << std::boolalpha << is_associative_container<A<int>>::value << std::endl;
//    std::cout << "------------------------------" << std::endl;
//    std::cout << std::boolalpha << is_associative_container<std::set<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_associative_container<std::map<int, int>>::value << std::endl;
//    std::cout << std::boolalpha << is_associative_container<std::multiset<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_associative_container<std::multimap<int, int>>::value << std::endl;
//    std::cout << std::boolalpha << is_associative_container<std::unordered_set<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_associative_container<std::unordered_map<int, int>>::value << std::endl;
//    std::cout << std::boolalpha << is_associative_container<std::unordered_multiset<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_associative_container<std::unordered_multimap<int, int>>::value << std::endl;
//    std::cout << "------------------------------" << std::endl;
//    std::cout << std::boolalpha << is_stl_container<C>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<B>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<A<int>>::value << std::endl;
//    std::cout << "------------------------------" << std::endl;
//    std::cout << std::boolalpha << is_stl_container<std::array<int, 5>>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<std::vector<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<std::deque<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<std::list<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<std::forward_list<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<std::stack<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<std::queue<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<std::priority_queue<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<std::set<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<std::map<int, int>>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<std::multiset<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<std::multimap<int, int>>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<std::unordered_set<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<std::unordered_map<int, int>>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<std::unordered_multiset<int>>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<std::unordered_multimap<int, int>>::value << std::endl;
//    std::cout << "------------------------------" << std::endl;
//    std::cout << std::boolalpha << is_stl_container<void>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<int>::value << std::endl;
//    //std::cout << std::boolalpha << is_stl_container<nullptr_t>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<E>::value << std::endl;
//    std::cout << std::boolalpha << is_stl_container<F>::value << std::endl;
//    std::cout << "------------------------------" << std::endl;
//  }
//};
