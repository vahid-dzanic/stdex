#pragma once

#include "traits_ext.h"

#include <string>
#include <vector>

namespace chili::stdex {
namespace traits {

template<typename _Tp>
struct is_string_raw : public std::integral_constant<bool, std::is_same<_Tp, std::string>::value>
{};

template<typename _Tp>
using is_string = is_string_raw<typename raw<_Tp>::type>;

} // namespace traits

void push_back_nonempty_string(const std::string& str, std::vector<std::string>& lst);
std::vector<std::string> split(const std::string& text, const std::string& search_pattern);
void replace(std::string& text, const std::string& search_pattern, const std::string& replace_by);
bool starts_with(const std::string& text, const std::string& search_pattern);
bool ends_with(const std::string& text, const std::string& search_pattern);
void chop(std::string& text, std::size_t count);

} // namespace stdext::chili
