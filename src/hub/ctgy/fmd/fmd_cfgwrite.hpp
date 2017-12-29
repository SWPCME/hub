/******************************************************************************
 * $Id: fmd_cfgread.hpp 2017-08 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  Config write definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-08 ~ 2017, Weiwei Huang
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

#ifndef FMD_CFGWRITE_HPP_INCLUDED
#define FMD_CFGWRITE_HPP_INCLUDED

#include "fmd_base.hpp"

// ust
#include "ust/ust_stringtype.hpp"
#include "ust/ust_containertype.hpp"

// fmd
#include "fmd_cfgbase.hpp"

// ust
class UFileT;

class FMD_LIB CFmdCfgWrite
{
  public:
    CFmdCfgWrite(UFileT *aFile);
    ~CFmdCfgWrite();

    UErrCodeT Init();

    UErrCodeT SetAll(const FmdCfgBurnTimeT *aTime,
                     const FmdCfgWeatherCtnT *aWeatherCtn, const UFloatT aElev,
                     const FmdCfgFuelMoistureCtnT *aFmCtn);

    UErrCodeT SetBurnTime(const FmdCfgBurnTimeT *aTime);
    UErrCodeT SetWeather(const FmdCfgWeatherCtnT *aWeatherCtn);
    UErrCodeT SetElevation(const UFloatT aElev);
    UErrCodeT SetFuelMoisture(const FmdCfgFuelMoistureCtnT *aFmCtn);

    UErrCodeT Save();

    // Private.
    CFmdCfgWrite();

  protected:
  private:
    UErrCodeT InitPointer();

    UErrCodeT InitBurnTime();
    UErrCodeT InitWeather();
    UErrCodeT InitElevation();
    UErrCodeT InitFuelMoisture();

    UErrCodeT WriteBurnTime();
    UErrCodeT WriteWeather();
    UErrCodeT WriteElevation();
    UErrCodeT WriteFuelMoisture();

    UErrCodeT Field(const UStringT *aValue, const UStringT *aFiled = NULL);
    UErrCodeT ToTime(UStringT *aDst, const FmdCfgTimeT *aSrc,
                     const UFlagCodeT aFlag = UFlagOff);

    FmdCfgBurnTimeT mTime;
    FmdCfgWeatherCtnT mWeather;
    UFloatT mElev;
    FmdCfgFuelMoistureCtnT mFm;

    UFileT *mFile;
};

#endif  // FMD_CFGWRITE_HPP_INCLUDED
