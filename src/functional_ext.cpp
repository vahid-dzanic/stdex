#include "stdex/functional_ext.h"

namespace chili::chili_private {

std::string rm_ampersand(std::string&& name)
{
  return name.front() == '&' ? name.substr(1) : name;
}

} // namespace chili::chili_private
