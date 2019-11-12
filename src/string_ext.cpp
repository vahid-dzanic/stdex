#include "stdex/string_ext.h"

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
