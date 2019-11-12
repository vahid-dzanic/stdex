#pragma once

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
