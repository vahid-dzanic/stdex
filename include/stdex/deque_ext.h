#pragma once

#include "traits_ext.h"

#include <deque>

namespace chili::stdex::traits {

template<typename _Tp>
struct is_deque_raw : public std::integral_constant<bool, is_instantiation_of<std::deque, _Tp>::value>
{};

template<typename _Tp>
using is_deque = is_deque_raw<typename raw<_Tp>::type>;

} // namespace chili::stdex::traits
