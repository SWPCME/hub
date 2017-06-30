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

class FMD_LIB CFmdFileLoad
{
  public:
    CFmdFileLoad();
    ~CFmdFileLoad();

    UErrCodeT Init();
    // Load All file.
    UErrCodeT All(const char *aLandscape, const char *aInput,
                  const char *aIgnition, const char *aBarrier);
    // Load landscape file.
    UErrCodeT Landscape(const char *aFile);
    // Load input file.
    UErrCodeT Input(const char *aFile);
    // Load input error.
    UErrCodeT InputErr(int aErr);
    // Set ignition file.
    UErrCodeT Ignition(const char *aFile);
    // Set barrier file.
    UErrCodeT Barrier(const char *aFile);

  protected:
  private:
    FmdFarsiteHT mFarsiteH;
};

#endif  // FMD_FILELOAD_HPP_INCLUDED
