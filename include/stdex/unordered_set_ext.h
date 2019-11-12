#pragma once

#include "traits_ext.h"

#include <unordered_set>

namespace chili::stdex::traits {

template<typename _Tp>
struct is_unordered_set_raw : public std::integral_constant<bool, is_instantiation_of<std::unordered_set, _Tp>::value>
{};
template<typename _Tp>
struct is_unordered_multiset_raw
  : public std::integral_constant<bool, is_instantiation_of<std::unordered_multiset, _Tp>::value>
{};

template<typename _Tp>
using is_unordered_set = is_unordered_set_raw<typename raw<_Tp>::type>;
template<typename _Tp>
using is_unordered_multiset = is_unordered_multiset_raw<typename raw<_Tp>::type>;

} // namespace chili::stdex::traits
