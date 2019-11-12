#pragma once

#include "traits_ext.h"

#include <tuple>
#include <utility>

namespace chili::stdex::traits {

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

} // namespace chili::stdex::traits
