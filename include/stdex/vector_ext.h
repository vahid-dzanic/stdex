#pragma once

#include "traits_ext.h"

#include <vector>

namespace chili::stdex::traits {

template<typename _Tp>
struct is_vector_raw : public std::integral_constant<bool, is_instantiation_of<std::vector, _Tp>::value>
{};

template<typename _Tp>
using is_vector = is_vector_raw<typename raw<_Tp>::type>;

} // namespace chili::stdex::traits
