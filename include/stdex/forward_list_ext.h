#pragma once

#include "traits_ext.h"

#include <forward_list>

namespace chili::stdex::traits {

template<typename _Tp>
struct is_forward_list_raw : public std::integral_constant<bool, is_instantiation_of<std::forward_list, _Tp>::value>
{};

template<typename _Tp>
using is_forward_list = is_forward_list_raw<typename raw<_Tp>::type>;

} // namespace chili::stdex::traits
