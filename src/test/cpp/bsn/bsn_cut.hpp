/******************************************************************************
 * $Id: bsn_cut.hpp 2017-06 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test cut control api definition.
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
 *****************************************************************************/

#ifndef BSN_CUT_HPP_INCLUED
#define BSN_CUT_HPP_INCLUED

#include "bsn_base.hpp"

// hub
class CHubCtl;
class CHubModuleCtl;
// cut
class CCutEasysCtl;
// cls
class CClsIoCommonCtl;
class CClsStreamFile;

class BSN_LIB CBsnCut
{
  public:
    CBsnCut();
    ~CBsnCut();

    UErrCodeT Init();
    UErrCodeT Test();

  protected:
  private:
    CHubCtl *mHub;
    CHubModuleCtl *mModule;
    CCutEasysCtl *mEasys;
    CClsIoCommonCtl *mIoCmn;
    CClsStreamFile *mFile;
};

#endif  // BSN_CUT_HPP_INCLUED
