#pragma once

#include "traits_ext.h"

#include <array>

namespace chili::stdex::traits {

template<class _Tp>
struct array_size_raw : public std::integral_constant<size_t, 0>
{};

template<class _Tp, size_t _Nm>
struct array_size_raw<std::array<_Tp, _Nm>> : public std::integral_constant<size_t, _Nm>
{};

template<typename _Tp>
struct is_array_raw : std::false_type
{};

template<typename _Tp, size_t _Nm>
struct is_array_raw<std::array<_Tp, _Nm>> : std::true_type
{};

template<typename _Tp>
using array_size = array_size_raw<typename raw<_Tp>::type>;

template<typename _Tp>
using is_array = is_array_raw<typename raw<_Tp>::type>;

} // namespace chili::stdex::traits
