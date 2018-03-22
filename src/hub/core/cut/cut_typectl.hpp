/******************************************************************************
 * $Id: cut_typectl.hpp 2017-06 $
 *
 * Project:  CUT (CUT: Client-side URL Transfer).
 * Purpose:  Type controler definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017, Weiwei Huang
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

#ifndef CUT_TYPECTL_HPP_INCLUDED
#define CUT_TYPECTL_HPP_INCLUDED

#include "cut_base.hpp"

// Curl Module.
#include "curl.h"

class CUT_LIB CCutTypeCtl
{
  public:
    CCutTypeCtl();
    ~CCutTypeCtl();

    UErrCodeT Init();
    UErrCodeT ToErrCode(UErrCodeT *aDest, const CURLcode aSrc);
    UErrCodeT ToOpt(CURLoption *aDest, const CutOptCodeT aSrc);

  protected:
  private:
};

#endif  // CUT_TYPECTL_HPP_INCLUDED
