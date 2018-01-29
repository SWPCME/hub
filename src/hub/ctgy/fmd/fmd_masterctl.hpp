/******************************************************************************
 * $Id: fmd_masterctl.hpp 2017-07 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  Master controler definition.
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

#ifndef FMD_MASTERCTL_HPP_INCLUDED
#define FMD_MASTERCTL_HPP_INCLUDED

#include "fmd_base.hpp"

// fmd
class CFmdCtl;

class FMD_LIB CFmdMasterCtl
{
  public:
    CFmdMasterCtl(CFmdCtl *aFmd);
    ~CFmdMasterCtl();

    UErrCodeT Init();
    CFmdCtl *Up();

    UErrCodeT Launch();
    UErrCodeT Cancel();

  protected:
  private:
    FmdFarsiteHT mFarsiteH;
    CFmdCtl *mFmd;
};

#endif  // FMD_MASTERCTL_HPP_INCLUDED
