/******************************************************************************
 * $Id: fmd_ctl.hpp 2017-06 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  Fmd controler definition.
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

#ifndef FMD_CTL_HPP_INCLUDED
#define FMD_CTL_HPP_INCLUDED

#include "fmd_base.hpp"

// hub
class CHubModuleCtl;
// Fmd.
class CFmdTypeCtl;
class CFmdMasterCtl;
class CFmdFileCtl;
class CFmdBurnCtl;

class FMD_LIB CFmdCtl
{
  public:
    CFmdCtl(CHubModuleCtl *aModule);
    ~CFmdCtl();

    // Init.
    UErrCodeT Init();
    CHubModuleCtl *Up();

    // Controler.
    CFmdMasterCtl *Master();
    CFmdFileCtl *File();
    CFmdBurnCtl *Burn();

    // Private.
    FmdFarsiteHT FarsiteH();
    CFmdTypeCtl *Type();

  protected:
  private:
    UErrCodeT InitPointer();

    CHubModuleCtl *mModule;
    FmdFarsiteHT mFarsiteH;
    CFmdTypeCtl *mType;
    CFmdMasterCtl *mMaster;
    CFmdFileCtl *mFile;
    CFmdBurnCtl *mBurn;
};

#endif  // FMD_CTL_HPP_INCLUDED
