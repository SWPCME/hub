/******************************************************************************
 * $Id: base_containerdefn.hpp 2017-09 $
 *
 * Project:  Base.
 * Purpose:  String definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-09 ~ 2017 Weiwei Huang
 *
 * This program is free software; you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by the Free 
 * Software Foundation, either version 3 of the License, or (at your option) 
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for 
 * more details.
 *
 * You should have received a copy of the GNU General Public License along 
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#ifndef BASE_CONTAINERDEFN_HPP_INCLUDED
#define BASE_CONTAINERDEFN_HPP_INCLUDED

#include "ust/ust_containertype.hpp"
#include "ust/ust_stringtype.hpp"

typedef UContainerT<UIntT> BCtnIntT;
typedef UIteratorT<UIntT> BCtnItIntT;
typedef UContainerT<UFloatT> BCtnFloatT;
typedef UContainerT<UStringT> BCtnStringT;

#endif  // BASE_CONTAINERDEFN_HPP_INCLUDED
