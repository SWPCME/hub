/******************************************************************************
 * $Id: base_tmpctl.hpp 2017-12 $
 *
 * Project:  Base.
 * Purpose:  Base temporary control definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017 Weiwei Huang
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

#ifndef BASE_TMPCTL_HPP_INCLUDED
#define BASE_TMPCTL_HPP_INCLUDED

#include "hub_base.h"

// ust
#include "ust/ust_stringtype.hpp"

// hub
class CHubModuleCtl;
// cls
class CClsFsCtl;
class CClsTimeCtl;

class HUB_LIB CBaseTmpCtl
{
  public:
    CBaseTmpCtl();
    ~CBaseTmpCtl();

    UErrCodeT Init();

    UErrCodeT SetRootDir(const UStringT *aDir, CHubModuleCtl *aModule);
    UStringT Dir(HubCodeT aCode, CHubModuleCtl *aModule);

    UErrCodeT MkDir(HubCodeT aCode, CHubModuleCtl *aModule);
    UErrCodeT RmDir(HubCodeT aCode, CHubModuleCtl *aModule);
    UErrCodeT RmRootDir(CHubModuleCtl *aModule);

  private:
  protected:
    typedef UContainerT<UStringT, CHubModuleCtl*> MStringModuleT;
    typedef UIteratorT<UStringT, CHubModuleCtl*> MStringModuleItT;

    UErrCodeT CurDir(UStringT *aCur);
    UErrCodeT SetDefaultDir(CHubModuleCtl *aModule);
    UErrCodeT DelAllDir();

    MStringModuleT mMDir;
    CClsFsCtl *mFs;
    CClsTimeCtl *mTime;
};

#endif  // BASE_TMPCTL_HPP_INCLUDED
