/******************************************************************************
 * $Id: fmd_fileload.hpp 2017-06 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  File load definition.
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

#ifndef FMD_FILELOAD_HPP_INCLUDED
#define FMD_FILELOAD_HPP_INCLUDED

#include "fmd_base.hpp"
// ust
#include "ust/ust_stringtype.hpp"

class FMD_LIB CFmdFileLoad
{
  public:
    CFmdFileLoad();
    ~CFmdFileLoad();

    UErrCodeT Init();
    // Load All file.
    UErrCodeT All(const UStringT *aCfg, const UStringT *aLcp,
                  const UStringT *aIgnition, const UStringT *aBarrier);
    // Load configuration file.
    UErrCodeT Cfg(const UStringT *aFile);
    // Load landscape file.
    UErrCodeT Lcp(const UStringT *aFile);
    // Set ignition file.
    UErrCodeT Ignition(const UStringT *aFile);
    // Set barrier file.
    UErrCodeT Barrier(const UStringT *aFile);

  protected:
  private:
    // Load input error.
    UErrCodeT InputErr(UIntT aErr);

    FmdFarsiteHT mFarsiteH;
};

#endif  // FMD_FILELOAD_HPP_INCLUDED
