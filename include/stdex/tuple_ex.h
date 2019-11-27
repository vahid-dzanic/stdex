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

#include <tuple>
#include <utility>

namespace stdex::traits {

template<typename _Tp>
struct is_tuple_raw : std::false_type
{};

template<typename... _Args>
struct is_tuple_raw<std::tuple<_Args...>> : std::true_type
{};

template<typename _Tp>
using is_tuple = is_tuple_raw<typename raw<_Tp>::type>;

class tuple_push
{
public:
  template<typename _Tp, typename _Tpl>
  static decltype(auto) front(const _Tp& entry, const _Tpl& tup)
  {
    return front_impl(entry, tup, std::make_index_sequence<std::tuple_size<_Tpl>::value>());
  }
  template<typename _Tp, typename _Tpl>
  static decltype(auto) back(const _Tp& entry, const _Tpl& tup)
  {
    return back_impl(entry, tup, std::make_index_sequence<std::tuple_size<_Tpl>::value>());
  }

private:
  template<typename _Tp, typename _Tpl, std::size_t... index>
  static decltype(auto) front_impl(const _Tp& entry, const _Tpl& tup, std::index_sequence<index...>)
  {
    return std::make_tuple(entry, std::get<index>(tup)...);
  }
  template<typename _Tp, typename _Tpl, std::size_t... index>
  static decltype(auto) back_impl(const _Tp& entry, const _Tpl& tup, std::index_sequence<index...>)
  {
    return std::make_tuple(std::get<index>(tup)..., entry);
  }
};

} // namespace stdex::traits
