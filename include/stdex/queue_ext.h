#pragma once

#include "traits_ext.h"

#include <queue>

namespace chili::stdex::traits {

template<typename _Tp>
struct is_queue_raw : public std::integral_constant<bool, is_instantiation_of<std::queue, _Tp>::value>
{};
template<typename _Tp>
struct is_priority_queue_raw : public std::integral_constant<bool, is_instantiation_of<std::priority_queue, _Tp>::value>
{};

template<typename _Tp>
using is_queue = is_queue_raw<typename raw<_Tp>::type>;
template<typename _Tp>
using is_priority_queue = is_priority_queue_raw<typename raw<_Tp>::type>;

} // namespace chili::stdex::traits
