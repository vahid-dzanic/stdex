#pragma once

#include "traits_ext.h"

#include <map>

namespace chili::stdex::traits {

template<typename _Tp>
struct is_map_raw : public std::integral_constant<bool, is_instantiation_of<std::map, _Tp>::value>
{};
template<typename _Tp>
struct is_multimap_raw : public std::integral_constant<bool, is_instantiation_of<std::multimap, _Tp>::value>
{};

template<typename _Tp>
using is_map = is_map_raw<typename raw<_Tp>::type>;
template<typename _Tp>
using is_multimap = is_multimap_raw<typename raw<_Tp>::type>;

} // namespace chili::stdex::traits
