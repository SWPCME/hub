/******************************************************************************
 * $Id: pyc_typeobjlist.hpp 2018-04 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc type object list definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-04 ~ 2018, Weiwei Huang
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
 ****************************************************************************/

#ifndef PYC_TYPEOBJLIST_HPP_INCLUDED
#define PYC_TYPEOBJLIST_HPP_INCLUDED

#include "pyc_base.hpp"

class PYC_LIB CPycTypeObjList
{
  public:
    CPycTypeObjList();
    ~CPycTypeObjList();

    UErrCodeT Init();

  protected:
  private:
};

#endif  // PYC_TYPEOBJLIST_HPP_INCLUDED
