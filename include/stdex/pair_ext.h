#pragma once

#include "traits_ext.h"

#include <utility>

namespace chili::stdex::traits {

template<typename _Tp>
struct is_pair_raw : public std::integral_constant<bool, is_instantiation_of<std::pair, _Tp>::value>
{};

template<typename _Tp>
using is_pair = is_pair_raw<typename raw<_Tp>::type>;

} // namespace chili::stdex::traits
