/******************************************************************************
 * $Id: fmd_filectl.hpp 2017-06 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  File controler definition.
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

#ifndef FMD_FILECTL_HPP_INCLUDED
#define FMD_FILECTL_HPP_INCLUDED

#include "fmd_base.hpp"

// ust
#include "ust/ust_stringtype.hpp"

// fmd
class CFmdCtl;
class CFmdFileCfg;
class CFmdFileLoad;
class CFmdFileWrite;

class FMD_LIB CFmdFileCtl
{
  public:
    CFmdFileCtl(CFmdCtl *aFmd);
    ~CFmdFileCtl();

    UErrCodeT Init();
    CFmdCtl *Up();
    CFmdFileCfg *Cfg(const UStringT *aFileName,
                     const FmdFileCfgCodeT aCfg);

    CFmdFileLoad *Load();
    CFmdFileWrite *Write();

  protected:
  private:
    CFmdCtl *mFmd;
    CFmdFileCfg *mCfg;
    CFmdFileLoad *mLoad;
    CFmdFileWrite *mWrite;
};

#endif  // FMD_FILECTL_HPP_INCLUDED
