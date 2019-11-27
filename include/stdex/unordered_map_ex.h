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

#include "traits_ex.h"

#include <unordered_map>

namespace stdex::traits {

template<typename _Tp>
struct is_unordered_map_raw : public std::integral_constant<bool, is_instantiation_of<std::unordered_map, _Tp>::value>
{};
template<typename _Tp>
struct is_unordered_multimap_raw
  : public std::integral_constant<bool, is_instantiation_of<std::unordered_multimap, _Tp>::value>
{};

template<typename _Tp>
using is_unordered_map = is_unordered_map_raw<typename raw<_Tp>::type>;
template<typename _Tp>
using is_unordered_multimap = is_unordered_multimap_raw<typename raw<_Tp>::type>;

} // namespace stdex::traits
