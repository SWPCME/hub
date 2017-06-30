/******************************************************************************
 * $Id: fmd_filewrite.hpp 2017-06 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  File write definition.
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

#ifndef FMD_FILEWRITE_HPP_INCLUDED
#define FMD_FILEWRITE_HPP_INCLUDED

#include "fmd_base.hpp"
// Base.
#include "base_timetype.hpp"
// Ust.
#include "ust/ust_stringtype.hpp"

class CFmdTypeCtl;

class FMD_LIB CFmdFileWrite
{
  public:
    CFmdFileWrite();
    ~CFmdFileWrite();

    UErrCodeT Init();
    UErrCodeT All(const char *aFile, UFlagCodeT aFlag = UFlagOff);
    // Map Environment.
    UErrCodeT MapEnv(UStringT *aFile, BTimeTmT *aTm,
                     FmdMapEnvIntervalCodeT aCode);
    // Special.
    UErrCodeT Special(const char *aFile, UFlagCodeT aFlag = UFlagOff);
    UErrCodeT CrownFireGrid(const char *aFile, UFlagCodeT aFlag = UFlagOff);
    UErrCodeT IntensityGrid(const char *aFile, UFlagCodeT aFlag = UFlagOff);
    UErrCodeT FlameLengthGrid(const char *aFile, UFlagCodeT aFlag = UFlagOff);
    UErrCodeT SpreadRateGrid(const char *aFile, UFlagCodeT aFlag = UFlagOff);
    UErrCodeT SpreadDirectionGrid(const char *aFile,
                                  UFlagCodeT aFlag = UFlagOff);
    UErrCodeT HeatPerUnitAreaGrid(const char *aFile,
                                  UFlagCodeT aFlag = UFlagOff);
    UErrCodeT ReactionIntensityGrid(const char *aFile,
                                    UFlagCodeT aFlag = UFlagOff);
    UErrCodeT ArrivalTimeGrid(const char *aFile, UFlagCodeT aFlag = UFlagOff);
    // Common.
    UErrCodeT Common(const char *aFile);
    UErrCodeT IgnitionGrid(const char *aFile);
    UErrCodeT PerimetersShape(const char *aFile);
    UErrCodeT SpotGrid(const char *aFile);
    UErrCodeT SpotData(const char *aFile);
    UErrCodeT SpotShape(const char *aFile);
    UErrCodeT Timings(const char *aFile);

  protected:
  private:
    FmdFarsiteHT mFarsiteH;
    CFmdTypeCtl *mType;
};

#endif  // FMD_FILEWRITE_HPP_INCLUDED
