#include "stdex/string_ex.h"

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

namespace chili::stdex {

void push_back_nonempty_string(const std::string& str, std::vector<std::string>& lst)
{
  if (!str.empty())
  {
    lst.push_back(str);
  }
}

std::vector<std::string> split(const std::string& text, const std::string& search_pattern)
{
  std::vector<std::string> ret;
  if (!text.empty())
  {
    if (!search_pattern.empty())
    {
      std::size_t start = 0;
      auto end = text.find(search_pattern, start);
      while (end != std::string::npos)
      {
        push_back_nonempty_string(text.substr(start, end - start), ret);
        start = end + search_pattern.size();
        end = text.find(search_pattern, start);
      }
      push_back_nonempty_string(text.substr(start), ret);
    }
    else
    {
      ret.push_back(text);
    }
  }
  return ret;
}

void replace(std::string& text, const std::string& search_pattern, const std::string& replace_by)
{
  if (!text.empty())
  {
    auto found = text.find(search_pattern, 0);
    while (found != std::string::npos)
    {
      text.replace(found, search_pattern.size(), replace_by);
      found = text.find(search_pattern, found + replace_by.size());
    }
  }
}

bool starts_with(const std::string& text, const std::string& search_pattern)
{
  if (text.size() >= search_pattern.size())
  {
    return search_pattern == text.substr(0, search_pattern.size());
  }
  return false;
}

bool ends_with(const std::string& text, const std::string& search_pattern)
{
  if (text.size() >= search_pattern.size())
  {
    return search_pattern == text.substr(text.size() - search_pattern.size(), search_pattern.size());
  }
  return false;
}

void chop(std::string& text, std::size_t count)
{
  if (text.size() > count)
  {
    text.erase(text.size() - count, count);
  }
  else
  {
    text.clear();
  }
}

}  // namespace chili::stdex
