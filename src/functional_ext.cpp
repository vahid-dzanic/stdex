#include "stdex/functional_ex.h"

namespace chili::restricted {

std::string rm_ampersand(std::string&& name)
{
  return name.front() == '&' ? name.substr(1) : name;
}

} // namespace chili::chili_private
