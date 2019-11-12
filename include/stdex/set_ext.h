#pragma once

#include "traits_ext.h"

#include <set>

namespace chili::stdex::traits {

template<typename _Tp>
struct is_set_raw : public std::integral_constant<bool, is_instantiation_of<std::set, _Tp>::value>
{};
template<typename _Tp>
struct is_multiset_raw : public std::integral_constant<bool, is_instantiation_of<std::multiset, _Tp>::value>
{};

template<typename _Tp>
using is_set = is_set_raw<typename raw<_Tp>::type>;
template<typename _Tp>
using is_multiset = is_multiset_raw<typename raw<_Tp>::type>;

} // namespace chili::stdex::traits
