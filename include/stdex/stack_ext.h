#pragma once

#include "traits_ext.h"

#include <stack>

namespace chili::stdex::traits {

template<typename _Tp>
struct is_stack_raw : public std::integral_constant<bool, is_instantiation_of<std::stack, _Tp>::value>
{};

template<typename _Tp>
using is_stack = is_stack_raw<typename raw<_Tp>::type>;

} // namespace chili::stdex::traits
