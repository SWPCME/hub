/******************************************************************************
 * $Id: cut_easyctl.hpp 2017-06 $
 *
 * Project:  CUT (CUT: Client-side URL Transfer).
 * Purpose:  Easy controler definition.
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

#ifndef CUT_EASYCTL_HPP_INCLUDED
#define CUT_EASYCTL_HPP_INCLUDED

#include "cut_base.hpp"

// Cls.
#include "cls/cls_iostreamctl.hpp"
// Ust.
#include "ust/ust_stringtype.hpp"

class CCutTypeCtl;

class CUT_LIB CCutEasyCtl
{
  public:
    CCutEasyCtl(UStringT *aName);
    ~CCutEasyCtl();

    UErrCodeT Init();
    UStringT Name();
    // Set Option.
    UErrCodeT SetUrl(UStringT *aUrl);
    UErrCodeT SetGet();
    UErrCodeT SetPut();
    UErrCodeT SetWriteData(ClsFileHT aFileH);
    UErrCodeT SetWriteFunc(cut_write_callback aFunc = NULL);
    // Perform.
    UErrCodeT Perform();

 protected:
  private:
    UErrCodeT Handle(CutEasyHT *aHandle);
    UErrCodeT SetName(UStringT *aName);
    UErrCodeT SetOpt(CutOptCodeT aOpt, ...);
    UErrCodeT Cleanup();

    // Cut.
    CCutTypeCtl *mType;
    // Cls.
    CClsIoStreamCtl *mIoStr;

    UStringT mName;
    CutEasyHT mHandle;
    UStringT mUrl;
};

#endif  // CUT_EASYCTL_HPP_INCLUDED
