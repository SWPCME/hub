/******************************************************************************
 * $Id: fmd_filecfg.hpp 2017-08 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  File config definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-06 ~ 2017, Weiwei Huang
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

#ifndef FMD_FILECFG_HPP_INCLUDED
#define FMD_FILECFG_HPP_INCLUDED

#include "fmd_base.hpp"

// ust
#include "ust/ust_stringtype.hpp"
#include "ust/ust_filetype.hpp"

// fmd
class CFmdCfgRead;
class CFmdCfgWrite;
// ust
class UFileT;

class FMD_LIB CFmdFileCfg
{
  public:
    CFmdFileCfg(const UStringT *aFileName, const FmdFileCfgCodeT aCfg);
    ~CFmdFileCfg();

    UErrCodeT Init();
    CFmdCfgRead *Read();
    CFmdCfgWrite *Write();

  protected:
  private:
    UErrCodeT InitPointer();
    UErrCodeT InitCfg(const UStringT *aFileName, const FmdFileCfgCodeT aCfg);
    UErrCodeT Create(const UStringT *aFileName);
    UErrCodeT Load(const UStringT *aFileName);

    UFileT mFile;
    CFmdCfgRead *mRead;
    CFmdCfgWrite *mWrite;
};

#endif  // FMD_FILECFG_HPP_INCLUDED
