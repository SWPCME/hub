/******************************************************************************
 * $Id: bsn_gda.hpp 2017-08 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test gda control api.
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
 *****************************************************************************/

#ifndef BSN_GDA_HPP_INCLUDED
#define BSN_GDA_HPP_INCLUDED

#include "bsn_base.hpp"

// ust
#include "ust/ust_stringtype.hpp"
// gda
#include "gda/gda_base.h"
// ogr
#include "ogr/ogr_base.h"

// hub
class CHubCtl;
class CHubModuleCtl;
// cls
class CClsIoCommonCtl;
// gda
class CGdaCtl;
class CGdaDriversCtl;
class CGdaDriverCtl;
class CGdaDatasetCtl;
class CGdaBandCtl;
class CGdaAlgCtl;
class CGdaWarpCtl;
class CGdaUtilsCtl;
// ogr
class COgrCtl;
class COgrLayerCtl;

class BSN_LIB CBsnGda
{
  public:
    CBsnGda();
    ~CBsnGda();

    UErrCodeT Init();
    UErrCodeT Test();

  protected:
  private:
    // core
    UErrCodeT TestCore();
    UErrCodeT CoreCreate();
    UErrCodeT CoreLoad();
    UErrCodeT CoreWrite();
    UErrCodeT CoreDataset();
    UErrCodeT DsPosToId(BMathCsC2dT *aId, const BMathCsC2dT *aPos,
                        CGdaDatasetCtl *aDs);
    UErrCodeT CoreBand();

    // ogr
    UErrCodeT TestOgr();
    UErrCodeT OgrCtr();

    // alg
    UErrCodeT TestAlg();

    // warp
    UErrCodeT TestWarp();
    UErrCodeT WarpReproj();

    // utils
    UErrCodeT TestUtils();
    UErrCodeT VtrToVtr();
    UErrCodeT UtilsR2R();
    UErrCodeT R2RTrFrmt(CGdaDatasetCtl *aDsSrc, const UStringT *aRstDst);
    UErrCodeT R2RTrSrcWin(CGdaDatasetCtl *aDsSrc, const UStringT *aRstDst);
    UErrCodeT Dem();
    UErrCodeT MergeRst();

    // rst
    CGdaDatasetCtl *CreateDataset(const UStringT *aFile, UIntT aNXSize,
                                  UIntT aNYSize, UIntT aNBand,
                                  UDataTCodeT aDataT, GdaFormatCodeT aFormat);
    CGdaDatasetCtl *LoadDataset(const UStringT *aFile, UAccessCodeT aAccess,
                                GdaFormatCodeT aFormat);
    CGdaBandCtl *LoadBand(const UStringT *aFile, UIntT aBandId,
                          UAccessCodeT aAccess, GdaFormatCodeT aFormat);
    // vtr
    COgrLayerCtl *Layer(const UStringT *aFile, UIntT aLayerId,
                        OgrFormatCodeT aFormat);
    
    // hub
    CHubCtl *mHub;
    CHubModuleCtl *mModule;
    // cls
    CClsIoCommonCtl *mIoCmn;
    // gda
    CGdaCtl *mGda;
    CGdaDriversCtl *mDrivers;
    CGdaAlgCtl *mAlg;
    CGdaWarpCtl *mWarp;
    CGdaUtilsCtl *mUtils;
    // ogr
    COgrCtl *mOgr;

    // variable
    UStringT mDataPath;
};

#endif  // BSN_GDA_HPP_INCLUDED
