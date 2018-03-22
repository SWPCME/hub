/******************************************************************************
 * $Id: rtk_ctl.hpp 2017-05 $
 *
 * Project:  Rtk (Real time kinematic).
 * Purpose:  Rtk ctl.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017 Weiwei Huang
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

#ifndef RTK_CTL_HPP_INCLUDED
#define RTK_CTL_HPP_INCLUDED

#include "rtk_base.hpp"

class CRtkTypeCtl;
class CRtkTideCtl;
class CRtkConvertCtl;

class RTK_LIB CRtkCtl
{
  public:
    CRtkCtl();
    ~CRtkCtl();

    UErrCodeT Init();
    CRtkTideCtl *Tide();
    CRtkConvertCtl *Convert();

    // Only to use in this library.
    CRtkTypeCtl *Type();

  protected:
  private:
    CRtkTideCtl *mTide;
    CRtkConvertCtl *mConvert;

    // Type control.
    CRtkTypeCtl *mType;
};

#endif  // RTK_CTL_HPP_INCLUDED
