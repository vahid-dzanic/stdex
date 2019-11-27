#pragma once

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

#include "array_ex.h"
#include "deque_ex.h"
#include "forward_list_ex.h"
#include "list_ex.h"
#include "vector_ex.h"

namespace stdex::traits {

template<typename _Tp>
struct is_sequential_container
  : public std::integral_constant<bool,
                                  is_array<_Tp>::value || is_vector<_Tp>::value || is_deque<_Tp>::value ||
                                    is_forward_list<_Tp>::value || is_list<_Tp>::value>
{};

} // namespace stdex::traits

#include "queue_ex.h"
#include "stack_ex.h"

namespace stdex::traits {

template<typename _Tp>
struct is_adaptor_container
  : public std::integral_constant<bool, is_stack<_Tp>::value || is_queue<_Tp>::value || is_priority_queue<_Tp>::value>
{};

} // namespace stdex::traits

#include "map_ex.h"
#include "set_ex.h"

namespace stdex::traits {

template<typename _Tp>
struct is_ordered_associative_container : public std::integral_constant<bool,
                                                                        is_set<_Tp>::value || is_multiset<_Tp>::value ||
                                                                          is_map<_Tp>::value || is_multimap<_Tp>::value>
{};

} // namespace stdex::traits

#include "unordered_set_ex.h"

namespace stdex::traits {

template<typename _Tp>
struct is_set_container
  : public std::integral_constant<bool,
                                  is_set<_Tp>::value || is_multiset<_Tp>::value || is_unordered_set<_Tp>::value ||
                                    is_unordered_multiset<_Tp>::value>
{};

} // namespace stdex::traits

#include "unordered_map_ex.h"

namespace stdex::traits {

template<typename _Tp>
struct is_map_container
  : public std::integral_constant<bool,
                                  is_map<_Tp>::value || is_multimap<_Tp>::value || is_unordered_map<_Tp>::value ||
                                    is_unordered_multimap<_Tp>::value>
{};

template<typename _Tp>
struct is_unordered_associative_container
  : public std::integral_constant<bool,
                                  is_unordered_set<_Tp>::value || is_unordered_multiset<_Tp>::value ||
                                    is_unordered_map<_Tp>::value || is_unordered_multimap<_Tp>::value>
{};

template<typename _Tp>
struct is_associative_container : public std::integral_constant<bool,
                                                                is_ordered_associative_container<_Tp>::value ||
                                                                  is_unordered_associative_container<_Tp>::value>
{};

template<typename _Tp>
struct is_collection
  : public std::integral_constant<bool,
                                  is_sequential_container<_Tp>::value || is_adaptor_container<_Tp>::value ||
                                    is_associative_container<_Tp>::value>
{};

} // namespace stdex::traits

#include "pair_ex.h"
#include "tuple_ex.h"

namespace stdex::traits {

template<typename _Tp>
struct is_container
  : public std::integral_constant<bool, is_collection<_Tp>::value || is_pair<_Tp>::value || is_tuple<_Tp>::value>
{};

} // namespace stdex::traits

#include "string_ex.h"

namespace stdex::traits {

template<typename _Tp>
struct is_std_type
  : public std::integral_constant<bool,
                                  is_container<_Tp>::value || std::is_arithmetic<typename raw<_Tp>::type>::value ||
                                    is_string<_Tp>::value>
{};

} // namespace stdex::traits

namespace stdex::traits {

template<typename _Tp>
struct is_carray : public std::integral_constant<bool, std::is_array<_Tp>::value>
{};

template<typename _Tp>
struct is_not_carray : public std::integral_constant<bool, not is_carray<_Tp>::value>
{};

} // namespace stdex::traits
