/******************************************************************************
 * $Id: ust_typectl.hpp 2018-05 $
 *
 * Project:  Common Library.
 * Purpose:  Universal type controler definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-05 ~ 2018 Weiwei Huang
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

#ifndef UST_TYPECTL_HPP_INCLUDED
#define UST_TYPECTL_HPP_INCLUDED

#include "ust_base.h"

class UST_LIB CUstTypeCtl
{
  public:
    CUstTypeCtl();
    ~CUstTypeCtl();

    UErrCodeT Init();
    UErrCodeT Size(UIntT *aSize, const UDataTCodeT aCode);

  protected:
  private:
};

#endif  // UST_TYPECTL_HPP_INCLUDED
