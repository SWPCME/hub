/******************************************************************************
 * $Id: rst_frmtlcp.hpp 2017-12 $
 *
 * Project:  RST (RST: Raster data process).
 * Purpose:  RST format landscape definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017, Weiwei Huang
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

#ifndef RST_FRMTLCP_HPP_INCLUDED
#define RST_FRMTLCP_HPP_INCLUDED

#include "rst_base.hpp"

// base
#include "ust/ust_stringtype.hpp"
#include "gda/gda_base.h"

// cls
class CClsFsCtl;
// gda
class CGdaDriversCtl;
class CGdaDriverCtl;
class CGdaBandCtl;
class CGdaWarpCtl;
class CGdaUtilsDem;
class CGdaUtilsTr;
class GdaTrRstToRstT;
class GdaOgrSrsT;
// rst
class CRstFrmtCtl;

class RST_LIB CRstFrmtLcp
{
  public:
    CRstFrmtLcp(CRstFrmtCtl *aFrmt);
    ~CRstFrmtLcp();

    UErrCodeT Init();
    CRstFrmtCtl *Up();
    UErrCodeT Create(const UStringT *aLcp, const UStringT *aElev,
                     const UStringT *aFm, const UStringT *aCt,
                     const GdaProjCsCodeT aCode);
    UErrCodeT Tr(const UStringT *aDst, const UStringT *aSrc,
                 const GdaTrRstToRstT *aOpt);

  protected:
  private:
    UErrCodeT InitPointer();

    // For create, contains init, translate, and so on.
    UErrCodeT CreateTif(const UStringT *aTif, const UStringT *aElev,
                        const GdaProjCsCodeT aCode);
    UErrCodeT CreateTifTmp(const UStringT *aTif, CGdaDatasetCtl *aDs,
                           const UFloatT aNdVal);
    UErrCodeT SetBandVal(CGdaBandCtl *aBand, UFloatT aVal,
                         UFlagCodeT aFlag);
    UErrCodeT DemProc(const UStringT *aDem, CGdaDatasetCtl *aDs,
                      const GdaDemProcFrmtCodeT aFrmt);
    UErrCodeT ToTif(const UStringT *aDst, const UStringT *aSrc);
    UErrCodeT Reproj(const UStringT *aDst, const UStringT *aSrc,
                     GdaOgrSrsT *aDstSrs);
    UErrCodeT ToLcp(const UStringT *aDst, const UStringT *aSrc);
    UErrCodeT TrTif2Lcp(const UStringT *aLcp, const UStringT *aTif);

    CRstFrmtCtl *mFrmt;
    CClsFsCtl *mFs;
    CGdaDriversCtl *mDrs;
    CGdaWarpCtl *mWarp;
    CGdaUtilsDem *mDem;
    CGdaUtilsTr *mTr;

    UStringT mTmpDir;
};

#endif  // RST_FRMTLCP_HPP_INCLUDED
