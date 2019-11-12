#pragma once

#include "array_ext.h"
#include "deque_ext.h"
#include "forward_list_ext.h"
#include "list_ext.h"
#include "vector_ext.h"

namespace chili::stdex::traits {

template<class _Tp>
struct is_sequential_container
  : public std::integral_constant<bool,
                                  is_array<_Tp>::value || is_vector<_Tp>::value || is_deque<_Tp>::value ||
                                    is_forward_list<_Tp>::value || is_list<_Tp>::value>
{};

} // namespace chili::stdex::traits

#include "queue_ext.h"
#include "stack_ext.h"

namespace chili::stdex::traits {

template<class _Tp>
struct is_adaptor_container
  : public std::integral_constant<bool, is_stack<_Tp>::value || is_queue<_Tp>::value || is_priority_queue<_Tp>::value>
{};

} // namespace chili::stdex::traits

#include "map_ext.h"
#include "set_ext.h"

namespace chili::stdex::traits {

template<class _Tp>
struct is_ordered_associative_container : public std::integral_constant<bool,
                                                                        is_set<_Tp>::value || is_multiset<_Tp>::value ||
                                                                          is_map<_Tp>::value || is_multimap<_Tp>::value>
{};

} // namespace chili::stdex::traits

#include "unordered_set_ext.h"

namespace chili::stdex::traits {

template<class _Tp>
struct is_set_container
  : public std::integral_constant<bool,
                                  is_set<_Tp>::value || is_multiset<_Tp>::value || is_unordered_set<_Tp>::value ||
                                    is_unordered_multiset<_Tp>::value>
{};

} // namespace chili::stdex::traits

#include "unordered_map_ext.h"

namespace chili::stdex::traits {

template<class _Tp>
struct is_map_container
  : public std::integral_constant<bool,
                                  is_map<_Tp>::value || is_multimap<_Tp>::value || is_unordered_map<_Tp>::value ||
                                    is_unordered_multimap<_Tp>::value>
{};

template<class _Tp>
struct is_unordered_associative_container
  : public std::integral_constant<bool,
                                  is_unordered_set<_Tp>::value || is_unordered_multiset<_Tp>::value ||
                                    is_unordered_map<_Tp>::value || is_unordered_multimap<_Tp>::value>
{};

template<class _Tp>
struct is_associative_container : public std::integral_constant<bool,
                                                                is_ordered_associative_container<_Tp>::value ||
                                                                  is_unordered_associative_container<_Tp>::value>
{};

template<class _Tp>
struct is_collection
  : public std::integral_constant<bool,
                                  is_sequential_container<_Tp>::value || is_adaptor_container<_Tp>::value ||
                                    is_associative_container<_Tp>::value>
{};

} // namespace chili::stdex::traits

#include "pair_ext.h"
#include "tuple_ext.h"

namespace chili::stdex::traits {

template<class _Tp>
struct is_container
  : public std::integral_constant<bool, is_collection<_Tp>::value || is_pair<_Tp>::value || is_tuple<_Tp>::value>
{};

} // namespace chili::stdex::traits

#include "string_ext.h"

namespace chili::stdex::traits {

template<class _Tp>
struct is_std_type
  : public std::integral_constant<bool,
                                  is_container<_Tp>::value || std::is_arithmetic<typename raw<_Tp>::type>::value ||
                                    is_string<_Tp>::value>
{};

} // namespace chili::stdex::traits

namespace chili::stdex::traits {

template<class _Tp>
struct is_carray : public std::integral_constant<bool, std::is_array<_Tp>::value>
{};

template<class _Tp>
struct is_not_carray : public std::integral_constant<bool, not is_carray<_Tp>::value>
{};

} // namespace chili::stdex::traits
