/* -*- mode: c++ -*- */
/******************************************************************************
 * $Id: pyc_objbytestype.hpp 2018-06 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc object bytes type definitions.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-06 ~ 2018, Weiwei Huang
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

#ifndef PYC_OBJBYTESTYPE_HPP_INCLUDED
#define PYC_OBJBYTESTYPE_HPP_INCLUDED

#include "pyc_base.hpp"

/**
 * \brief Pyc object bytes type: The type of object bytes.
 */
class PYC_LIB PycObjBytesT
{
  public:
    PycObjBytesT();
    ~PycObjBytesT();

    UErrCodeT Init();

  protected:
  private:
    UErrCodeT InitPointer();
};

#endif  // PYC_OBJBYTESTYPE_HPP_INCLUDED
