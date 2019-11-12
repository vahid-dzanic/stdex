#pragma once

#include "traits_ext.h"

#include <unordered_map>

namespace chili::stdex::traits {

template<typename _Tp>
struct is_unordered_map_raw : public std::integral_constant<bool, is_instantiation_of<std::unordered_map, _Tp>::value>
{};
template<typename _Tp>
struct is_unordered_multimap_raw
  : public std::integral_constant<bool, is_instantiation_of<std::unordered_multimap, _Tp>::value>
{};

template<typename _Tp>
using is_unordered_map = is_unordered_map_raw<typename raw<_Tp>::type>;
template<typename _Tp>
using is_unordered_multimap = is_unordered_multimap_raw<typename raw<_Tp>::type>;

} // namespace chili::stdex::traits
