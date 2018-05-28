/******************************************************************************
 * $Id: bsn_ust.hpp 2017-07 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test ust control api.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-05 ~ 2017, Weiwei Huang
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

#ifndef BSN_UST_HPP_INCLUDED
#define BSN_UST_HPP_INCLUDED

#include "bsn_base.hpp"
#include "ust/ust_stringtype.hpp"

// hub
class CHubCtl;
class CHubModuleCtl;

class BSN_LIB CBsnUst
{
  public:
    CBsnUst();
    ~CBsnUst();

    UErrCodeT Init();
    UErrCodeT Test();

  protected:
  private:
    UErrCodeT TestString();
    UErrCodeT NewStringArgv(UHandleT *aDst, const UStringT *aSrc);
    UErrCodeT TestStringFunc(UHandleT aArgv);
    UErrCodeT TestContainer();
    UErrCodeT TestCtnList();
    UErrCodeT TestCtnMap();
    UErrCodeT TestData();
    UErrCodeT TestFs();

    CHubCtl *mHub;
    CHubModuleCtl *mModule;
};

#endif  // BSN_UST_HPP_INCLUDED
