#include "stdex/functional_ex.h"

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

namespace stdex::restricted {

std::string rm_ampersand(std::string&& name) { return name.front() == '&' ? name.substr(1) : name; }

} // namespace stdex::restricted
