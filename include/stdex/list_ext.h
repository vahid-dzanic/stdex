#pragma once

#include "traits_ext.h"

#include <list>

namespace chili::stdex::traits {

template<typename _Tp>
struct is_list_raw : public std::integral_constant<bool, is_instantiation_of<std::list, _Tp>::value>
{};

template<typename _Tp>
using is_list = is_list_raw<typename raw<_Tp>::type>;

} // namespace chili::stdex::traits
