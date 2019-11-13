#pragma once

// This file is part of stdex library, stdex is an extension of the c++-standard library,
// especially the type traits for standard containers.
//
// Copyright (C) 2019 Vahid Dzanic <vdc@gmx.ch>
//
// stdex is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 3 of the License, or (at your option) any later version.
//
// Alternatively, you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// stdex is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License or the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License and a copy of the GNU General Public License along with
// stdex. If not, see <http://www.gnu.org/licenses/>.

#include <array>
#include <string>
#include <type_traits>
#include <vector>

namespace chili::stdex::traits {

template<template<typename...> class _Tp1, typename _Args>
struct is_instantiation_of : std::false_type
{};

template<template<typename...> class _Tp, typename... _Args>
struct is_instantiation_of<_Tp, _Tp<_Args...>> : std::true_type
{};

template<typename _Tp>
class raw
{
private:
  template<typename _Tp_ptr>
  using type_ptr_less = typename std::
    conditional<std::is_pointer<_Tp_ptr>::value, typename std::remove_pointer<_Tp_ptr>::type, _Tp_ptr>::type;
  template<typename _Tp_ref>
  using type_ref_less = typename std::
    conditional<std::is_reference<_Tp_ref>::value, typename std::remove_reference<_Tp_ref>::type, _Tp_ref>::type;
  template<typename _Tp_cv>
  using type_cv_less = typename std::remove_cv<_Tp_cv>::type;

public:
  using type = type_cv_less<type_ref_less<type_ptr_less<_Tp>>>;
};

} // namespace chili::stdex::traits
