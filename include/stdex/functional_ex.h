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

#include <functional>

namespace stdex {

template<typename _Func>
struct std_func_sign
{
  static constexpr std::size_t arity = 0;
  using func_type = void;
  using result_type = void;
  using arguments = void;
  template<std::size_t _N>
  using argument = void;
};

template<typename _R, typename... _A>
struct std_func_sign<std::function<_R(_A...)>>
{
  static constexpr std::size_t arity = sizeof...(_A);
  using func_type = _R(_A...);
  using result_type = _R;
  using arguments = std::tuple<_A...>;
  template<std::size_t _N>
  using argument = typename std::tuple_element<_N, arguments>::type;
};

template<typename _Func>
class function;

template<typename _R, typename... _A>
class function<_R(_A...)>
{
public:
  static constexpr std::size_t arity = sizeof...(_A);
  using result_type = _R;
  using arguments = std::tuple<_A...>;
  using std_func_type = std::function<result_type(_A...)>;
  template<std::size_t _N>
  struct argument
  {
    static_assert(_N < arity, "invalid index");
    using type = typename std::tuple_element<_N, arguments>::type;
  };
  function(const std_func_type& func, const std::string& name = "")
    : func_(func)
    , name_(name)
  {}

  //TODO vadz: fix 'rule of five'

  //  function(const std_func_type& func, std::string&& name = "")
  //    : mFunc(func)
  //    , mName(std::move(name))
  //  {
  //  }

  //  function(std_func_type&& func, const std::string& name = "")
  //    : mFunc(std::move(func))
  //    , mName(name)
  //  {
  //  }

  explicit function(std_func_type&& func, std::string&& name = "")
    : func_(std::move(func))
    , name_(std::move(name))
  {}

  function(const function& rhs)
    : func_(rhs.func_)
    , name_(rhs.name_)
  {}

  explicit operator bool() const noexcept { return static_cast<bool>(func_); }

  _R operator()(_A... args) { return func_(args...); }

  _R operator()(arguments&& args) { return invoke(std::forward<arguments>(args), std::make_index_sequence<arity>{}); }

  const std::string& name() const noexcept { return name_; }

private:
  template<std::size_t... index>
  _R invoke(arguments&& args, std::index_sequence<index...>)
  {
    return operator()(std::get<index>(args)...);
  }

  std_func_type func_;
  std::string name_;
};

template<typename _R, typename... _A>
bool operator==(const function<_R(_A...)>& __f, std::nullptr_t) noexcept
{
  return !static_cast<bool>(__f);
}

template<typename _R, typename... _A>
bool operator==(std::nullptr_t, const function<_R(_A...)>& __f) noexcept
{
  return !static_cast<bool>(__f);
}

template<typename _R, typename... _A>
bool operator!=(const function<_R(_A...)>& __f, std::nullptr_t) noexcept
{
  return static_cast<bool>(__f);
}

template<typename _R, typename... _A>
bool operator!=(std::nullptr_t, const function<_R(_A...)>& __f) noexcept
{
  return static_cast<bool>(__f);
}

template<typename _Func>
struct func_sign
{
  static constexpr std::size_t arity = 0;
  using func_type = void;
  using class_type = void;
  using result_type = void;
  using arguments = void;
  template<std::size_t _N>
  using argument = void;
};

template<typename _R, typename... _A>
struct func_sign<_R (&)(_A...)>
{
  static constexpr std::size_t arity = sizeof...(_A);
  using func_type = _R(_A...);
  using class_type = void;
  using result_type = _R;
  using arguments = std::tuple<_A...>;
  template<std::size_t _N>
  using argument = typename std::tuple_element<_N, arguments>::type;
};

template<typename _R, typename _C, typename... _A>
struct func_sign<_R (_C::*)(_A...)>
{
  static constexpr std::size_t arity = sizeof...(_A);
  using func_type = _R(_A...);
  using class_type = _C;
  using result_type = _R;
  using arguments = std::tuple<_A...>;
  template<std::size_t _N>
  using argument = typename std::tuple_element<_N, arguments>::type;
};

namespace restricted {
std::string rm_ampersand(std::string&& name);

template<typename _Func, std::size_t... index>
decltype(auto) create_index(_Func&& func, std::string&& name, std::index_sequence<index...>)
{
  using __return_type = function<typename func_sign<_Func>::func_type>;
  return __return_type([pFunc = std::decay_t<_Func>(func)](
                         typename __return_type::template argument<index>::type... args) { return pFunc(args...); },
                       rm_ampersand(std::forward<std::string>(name)));
}

template<typename _Func, typename _Class, std::size_t... index>
decltype(auto) create_index_ptr(_Func&& func, std::string&& name, _Class* ptr2class, std::index_sequence<index...>)
{
  using __return_type = function<typename func_sign<_Func>::func_type>;
  return __return_type(
    [pFunc = std::decay_t<_Func>(func), ptr2class](typename __return_type::template argument<index>::type... args) {
      return (ptr2class->*pFunc)(args...);
    },
    rm_ampersand(std::forward<std::string>(name)));
}
} // namespace restricted

template<typename _Func>
decltype(auto) bind(_Func&& func, std::string&& name)
{
  using __return_type = function<typename func_sign<_Func>::func_type>;
  return __return_type(typename __return_type::std_func_type(std::bind(func)),
                       restricted::rm_ampersand(std::forward<std::string>(name)));
}

template<typename _Func, typename... _A>
decltype(auto) bind(_Func&& func, std::string&& name, _A&&... args)
{
  using __return_type = function<typename func_sign<_Func>::func_type>;
  return __return_type(typename __return_type::std_func_type(std::bind(func, args...)),
                       restricted::rm_ampersand(std::forward<std::string>(name)));
}

#define stdex_bind(FUNC, ...) bind(FUNC, #FUNC, ##__VA_ARGS__)

template<typename _Func>
decltype(auto) create(_Func&& func, std::string&& name)
{
  static_assert(std::is_void<typename func_sign<_Func>::class_type>::value,
                "missing pointer of the class which owns this member function");
  using __return_type = function<typename func_sign<_Func>::func_type>;

  return restricted::create_index(
    std::forward<_Func>(func), std::forward<std::string>(name), std::make_index_sequence<__return_type::arity>{});
}

template<typename _Func>
decltype(auto) create(_Func&& func, std::string&& name, typename func_sign<_Func>::class_type* ptr2class)
{
  static_assert(not std::is_void<typename func_sign<_Func>::class_type>::value,
                "void* are not allowed, it doesn't own the member function");
  using __return_type = function<typename func_sign<_Func>::func_type>;

  return restricted::create_index_ptr(std::forward<_Func>(func),
                                         std::forward<std::string>(name),
                                         ptr2class,
                                         std::make_index_sequence<__return_type::arity>{});
}

template<typename _Func, typename... _A>
decltype(auto) create(_Func&& func, std::string&& name, _A&&... args)
{
  static_assert(std::is_void<typename func_sign<_Func>::class_type>::value,
                "missing pointer of the class which owns this member function");
  static_assert(func_sign<_Func>::arity >= sizeof...(args),
                "too many arguments to function, please enter correct count of arguments or none");
  static_assert(func_sign<_Func>::arity <= sizeof...(args),
                "too few arguments to function, please enter correct count of arguments or none");
  using __return_type = function<typename func_sign<_Func>::result_type()>;

  return __return_type([pFunc = std::decay_t<_Func>(func), args...]() { return pFunc(args...); },
                       restricted::rm_ampersand(std::forward<std::string>(name)));
}

template<typename _Func, typename... _A>
decltype(auto) create(_Func&& func, std::string&& name, typename func_sign<_Func>::class_type* ptr2class, _A&&... args)
{
  static_assert(not std::is_void<typename func_sign<_Func>::class_type>::value,
                "void* are not allowed, it doesn't own the member function");
  static_assert(func_sign<_Func>::arity >= sizeof...(args),
                "too many arguments to function, please enter correct count of arguments or none");
  static_assert(func_sign<_Func>::arity <= sizeof...(args),
                "too few arguments to function, please enter correct count of arguments or none");
  using __return_type = function<typename func_sign<_Func>::result_type()>;

  return __return_type(
    [pFunc = std::decay_t<_Func>(func), ptr2class, args...]() { return (ptr2class->*pFunc)(args...); },
    restricted::rm_ampersand(std::forward<std::string>(name)));
}
#define stdex_create(FUNC, ...) create(FUNC, #FUNC, ##__VA_ARGS__)

template<typename _Tp>
struct is_function : public std::integral_constant<bool, stdex::traits::is_instantiation_of<function, _Tp>::value>
{};

template<typename _Tp>
struct is_std_function
  : public std::integral_constant<bool, stdex::traits::is_instantiation_of<std::function, _Tp>::value>
{};
} // namespace stdex
