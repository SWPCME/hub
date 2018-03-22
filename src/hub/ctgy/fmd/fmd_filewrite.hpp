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

// class
class CGdaUtilsTr;
class COgrCtl;
class CVtrCtl;
class CFmdTypeCtl;
class CFmdFileCtl;

class FMD_LIB CFmdFileWrite
{
  public:
    CFmdFileWrite(CFmdFileCtl *aFile);
    ~CFmdFileWrite();

    UErrCodeT Init();
    CFmdFileCtl *Up();

    UErrCodeT All(const UStringT *aFile, UFlagCodeT aFlag = UFlagOff);
    // Map Environment.
    UErrCodeT MapEnv(const UStringT *aFile, BTimeTmT *aTm,
                     FmdMapEnvIntervalCodeT aCode);
    // Special.
    UErrCodeT Special(const UStringT *aFile, UFlagCodeT aFlag = UFlagOff);
    UErrCodeT CrownFireGrid(const UStringT *aFile, UFlagCodeT aFlag = UFlagOff);
    UErrCodeT IntensityGrid(const UStringT *aFile, UFlagCodeT aFlag = UFlagOff);
    UErrCodeT FlameLengthGrid(const UStringT *aFile, UFlagCodeT aFlag = UFlagOff);
    UErrCodeT SpreadRateGrid(const UStringT *aFile, UFlagCodeT aFlag = UFlagOff);
    UErrCodeT SpreadDirectionGrid(const UStringT *aFile,
                                  UFlagCodeT aFlag = UFlagOff);
    UErrCodeT HeatPerUnitAreaGrid(const UStringT *aFile,
                                  UFlagCodeT aFlag = UFlagOff);
    UErrCodeT ReactionIntensityGrid(const UStringT *aFile,
                                    UFlagCodeT aFlag = UFlagOff);
    UErrCodeT ArrivalTimeGrid(const UStringT *aFile, UFlagCodeT aFlag = UFlagOff);
    // Common.
    UErrCodeT Common(const UStringT *aFile);
    UErrCodeT IgnitionGrid(const UStringT *aFile);
    UErrCodeT PerimetersShape(const UStringT *aFile,
                              const UFlagCodeT aFlag = UFlagOff);
    UErrCodeT PerimetersGjson(UStringT *aStr);
    UErrCodeT SpotGrid(const UStringT *aFile);
    UErrCodeT SpotData(const UStringT *aFile);
    UErrCodeT SpotShape(const UStringT *aFile);
    UErrCodeT Timings(const UStringT *aFile);

  protected:
  private:
    UErrCodeT InitPointer();

    CFmdFileCtl *mFile;
    CGdaUtilsTr *mTr;
    COgrCtl *mOgr;
    CVtrCtl *mVtr;

    FmdFarsiteHT mFarsiteH;
    CFmdTypeCtl *mType;
    UStringT mTmpDir;
};

#endif  // FMD_FILEWRITE_HPP_INCLUDED
