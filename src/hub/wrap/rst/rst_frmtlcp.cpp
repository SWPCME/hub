/******************************************************************************
 * $Id: rst_frmtlcp.hpp 2017-12 $
 *
 * Project:  RST (RST: Raster data process).
 * Purpose:  RST format landscape implementation.
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

#include "rst_frmtlcp.hpp"

// base
#include "base_ctl.hpp"
#include "base_tmpctl.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_fsctl.hpp"
#include "cls_fswork.hpp"
#include "cls_fscreate.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_corectl.hpp"
#include "gda_driversctl.hpp"
#include "gda_driverctl.hpp"
#include "gda_datasetctl.hpp"
#include "gda_bandctl.hpp"
#include "gda_warpctl.hpp"
#include "gda_warpreproj.hpp"
#include "gda_warpreprojimagetype.hpp"
#include "gda_utilsctl.hpp"
#include "gda_utilstr.hpp"
#include "gda_trrst.hpp"
#include "gda_trrsttorsttype.hpp"
#include "gda_utilsdem.hpp"
#include "gda_demproctype.hpp"
// rst
#include "rst_ctl.hpp"
#include "rst_frmtctl.hpp"

/**
 * \brief Constructor.
 */
CRstFrmtLcp::CRstFrmtLcp(CRstFrmtCtl *aFrmt)
{
    InitPointer();
    mFrmt = aFrmt;
}

/**
 * \brief Destructor.
 */
CRstFrmtLcp::~CRstFrmtLcp()
{
    InitPointer();
}

/**
 * \brief Initialize.
 */
UErrCodeT CRstFrmtLcp::Init()
{
    CRstFrmtCtl *frmt = Up();
    CRstCtl *rst = frmt->Up();
    CHubModuleCtl *module = rst->Up();
    CBaseCtl *base = CBaseCtl::Base();
    CBaseTmpCtl *tmp = base->Tmp();
    mTmpDir = tmp->Dir(HubMRst, module);

    CClsCtl *cls = NULL;
    CLS_CTL(cls);
    mFs = cls->Fs();

    CGdaCoreCtl *core = NULL;
    GDA_CORE_CTL(core);
    mDrs = core->Drivers();

    GDA_WARP_CTL(mWarp);

    CGdaUtilsCtl *utils = NULL;
    GDA_UTILS_CTL(utils);
    mDem = utils->Dem();
    mTr = utils->Tr();

    return UErrFalse;
}

/**
 * \brief Up.
 */
CRstFrmtCtl *CRstFrmtLcp::Up()
{
    return mFrmt;
}

/**
 * \brief Create with elevation, fuel model, and canopy with tree.
 */
UErrCodeT CRstFrmtLcp::Create(const UStringT *aLcp, const UStringT *aElev,
                              const UStringT *aFm, const UStringT *aCt,
                              const GdaProjCsCodeT aCode)
{
    // Load tif.
    GdaFormatCodeT frmt = GdaFormatTif;
    mDrs->Register(frmt);
    CGdaDriverCtl *drTif = mDrs->Driver(frmt);

    // Prepare translate
    CGdaTrRst *trRst = mTr->Rst();
    BCtnStringT strR2rOpt(UContainerList);
    GdaTrRstToRstT r2rOpt;

    // Change the projection coordinate system.
    UStringT elev = mTmpDir;
    elev += "/elevation.tif";
    // CClsFsCreate *fsCreate = mFs->Create();
    // fsCreate->Copy(&elev, aElev);
    GdaTrRstToRstT trR2r;
    GdaOgrSrsT elevSrs;
    elevSrs.SetProjCs(aCode);
    Reproj(&elev, aElev, &elevSrs);
    
    // UAccessCodeT access = UAccessRead;
    // CGdaDatasetCtl *dsSrcElev = drTif->Load(aElev, access);
    // GdaOgrSrsT *srcSrs = dsSrcElev->Srs();
    // GdaOgrSrsT dstSrs;
    // dstSrs.SetProjCs(GdaProjCsWgs1984);
    // GdaWarpReprojImageT reprojImage;
    // reprojImage.SetAll(&dstSrs, srcSrs, drTif);
    // CGdaWarpReproj *reproj = mWarp->Reproj();
    // reproj->ToImage(&elev, dsSrcElev, &reprojImage);
    // drTif->Close(aElev);

    // Process elev for nodata value.
    UAccessCodeT access = UAccessWrite;
    CGdaDatasetCtl *dsElev = drTif->Load(&elev, access);
    CGdaBandCtl *bandElev = dsElev->Band(1);
    UFloatT ndv = -9999.0;
    UStringT strNdv(ndv);
    UFloatT ndvElev = bandElev->NoDataVal();
    UDataTCodeT dataT = bandElev->DataT();
    UIntT xSize = 0;
    bandElev->XSize(&xSize);
    UIntT ySize = 0;
    bandElev->YSize(&ySize);
    BMathCsC2dT bdBegin(0, 0);
    BMathCsC2dT bdEnd(xSize - 1, ySize - 1);
    GdaBandDataT bandData(dataT, &bdBegin, &bdEnd);
    bandElev->Read(&bandData);
    UIntT size = xSize * ySize;
    float *val = (float *) bandData.Handle();
    for (UIntT i = 0; i < size; ++i)
    {
        if (val[i] == ndvElev)
        {
            val[i] = ndv;
        }
    }
    bandElev->Write(&bandData);
    bandElev->SetNoDataVal(ndv);

    // Dem.
    GdaDemProcT proc;
    GdaDemProcFrmtCodeT demFrmt = GdaDemProcFrmtSlope;
    BCtnStringT opt(UContainerList);
    opt.Add("-of");
    opt.Add("GTiff");
    proc.SetAll(demFrmt, &opt);
    UStringT slope = mTmpDir;
    slope += "/slope.tif";
    mDem->Proc(&slope, dsElev, &proc);
    CGdaDatasetCtl *dsSlope = drTif->Load(&slope);

    UStringT aspect = mTmpDir;
    aspect += "/aspect.tif";
    demFrmt = GdaDemProcFrmtAspect;
    proc.SetAll(demFrmt, &opt);
    mDem->Proc(&aspect, dsElev, &proc);
    CGdaDatasetCtl *dsAspect = drTif->Load(&aspect);

    // Create lcpTmp with elev.
    UStringT lcpTmp = mTmpDir;
    lcpTmp += "/lcptmp.tif";
    UIntT bandCount = 5;
    for (UIntT i = 1; i <= bandCount; ++i)
    {
        strR2rOpt.Add("-b");
        strR2rOpt.Add("1");
    }
    strR2rOpt.Add("-a_nodata");
    strR2rOpt.Add(strNdv.ToA());
    strR2rOpt.Add("-ot");
    strR2rOpt.Add("Int16");
    r2rOpt.SetAll(frmt, &strR2rOpt);
    trRst->ToRst(&lcpTmp, dsElev, &r2rOpt);
    drTif->Close(&elev);

    // Set band 1, 2, 3 for lcpTmp.
    CGdaDatasetCtl *dsLcpTmp = drTif->Load(&lcpTmp, access);
    CGdaBandCtl *bandSlope = dsSlope->Band(1);
    dsLcpTmp->SetBand(2, bandSlope);
    CGdaBandCtl *bandAspect = dsAspect->Band(1);
    dsLcpTmp->SetBand(3, bandAspect);
    drTif->Close(&slope);
    drTif->Close(&aspect);

    // Set band 4 for lcpTmp.
    CGdaBandCtl *bandLt4 = dsLcpTmp->Band(4);
    for (UIntT i = 0; i < size; ++i)
    {
        val[i] = 165;
    }
    bandLt4->Write(&bandData);

    // Set band 5 for lcpTmp.
    CGdaBandCtl *bandLt5 = dsLcpTmp->Band(5);
    for (UIntT i = 0; i < size; ++i)
    {
        val[i] = 80;
    }
    bandLt5->Write(&bandData);

    // Translate to lcp.
    frmt = GdaFormatLcp;
    strR2rOpt.Clear();
    for (UIntT i = 1; i <= bandCount; ++i)
    {
        UStringT num = i;
        strR2rOpt.Add("-b");
        strR2rOpt.Add(num);
    }
    strR2rOpt.Add("-co");
    strR2rOpt.Add("LATITUDE=0");
    strR2rOpt.Add("-co");
    strR2rOpt.Add("LINEAR_UNIT=METER");
    r2rOpt.SetAll(frmt, &strR2rOpt);
    trRst->ToRst(aLcp, dsLcpTmp, &r2rOpt);
    drTif->Close(&lcpTmp);

    return UErrFalse;
}

UErrCodeT CRstFrmtLcp::Tr(const UStringT *aDst, const UStringT *aSrc,
                          const GdaTrRstToRstT *aOpt)
{
    UStringT srcTif = mTmpDir;
    srcTif += "/rstfrmtlcp_tr_srctif.tif";
    ToTif(&srcTif, aSrc);
    UStringT dstTif = mTmpDir;
    dstTif += "/rstfrmtlcp_tr_dsttif.tif";
    GdaOgrSrsT *dstSrs = aOpt->Srs();
    Reproj(&dstTif, &srcTif, dstSrs);
    ToLcp(aDst, &dstTif);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Initialize pointer.
 */
UErrCodeT CRstFrmtLcp::InitPointer()
{
    BMD_POINTER_INIT(mFrmt);
    BMD_POINTER_INIT(mWarp);
    BMD_POINTER_INIT(mTr);
    BMD_POINTER_INIT(mDem);

    return UErrFalse;
}

/**
 * \brief Translate lcp to tif.
 */
UErrCodeT CRstFrmtLcp::ToTif(const UStringT *aDst, const UStringT *aSrc)
{
    UFloatT ndv = -9999.000;
    UStringT strNdv(ndv);

    GdaFormatCodeT frmt = GdaFormatLcp;
    mDrs->Register(frmt);
    CGdaDriverCtl *drLcp = mDrs->Driver(frmt);
    UAccessCodeT access = UAccessRead;
    CGdaDatasetCtl *dsLcp = drLcp->Load(aSrc, access);
    UIntT bandCount;
    dsLcp->Count(&bandCount);
    CGdaTrRst *trRst = mTr->Rst();
    BCtnStringT strR2rOpt(UContainerList);
    GdaTrRstToRstT r2rOpt;
    for (UIntT i = 1; i <= bandCount; ++i)
    {
        UStringT num = i;
        strR2rOpt.Add("-b");
        strR2rOpt.Add(num);
    }
    strR2rOpt.Add("-a_nodata");
    strR2rOpt.Add(strNdv.ToA());
    strR2rOpt.Add("-ot");
    strR2rOpt.Add("Int16");
    frmt = GdaFormatTif;
    r2rOpt.SetAll(frmt, &strR2rOpt);
    trRst->ToRst(aDst, dsLcp, &r2rOpt);

    return UErrFalse;
}

/**
 * \brief Reproject image.
 */
UErrCodeT CRstFrmtLcp::Reproj(const UStringT *aDst, const UStringT *aSrc,
                              GdaOgrSrsT *aDstSrs)
{
    GdaFormatCodeT frmt = GdaFormatTif;
    mDrs->Register(frmt);
    CGdaDriverCtl *drTif = mDrs->Driver(frmt);
    UAccessCodeT access = UAccessRead;
    CGdaDatasetCtl *srcDs = drTif->Load(aSrc, access);
    GdaOgrSrsT *srcSrs = srcDs->Srs();
    GdaOgrSrsT *dstSrs = aDstSrs;
    GdaWarpReprojImageT reprojImage;
    reprojImage.SetAll(dstSrs, srcSrs, drTif);
    CGdaWarpReproj *reproj = mWarp->Reproj();
    reproj->ToImage(aDst, srcDs, &reprojImage);
    drTif->Close(aSrc);

    return UErrFalse;
}

/**
 * \brief Translate tif to lcp.
 */
UErrCodeT CRstFrmtLcp::ToLcp(const UStringT *aDst, const UStringT *aSrc)
{
    GdaFormatCodeT frmt = GdaFormatTif;
    mDrs->Register(frmt);
    CGdaDriverCtl *drTif = mDrs->Driver(frmt);
    UAccessCodeT access = UAccessRead;
    CGdaDatasetCtl *dsTif = drTif->Load(aSrc, access);
    UIntT bandCount;
    dsTif->Count(&bandCount);
    frmt = GdaFormatLcp;

    CGdaTrRst *trRst = mTr->Rst();
    BCtnStringT strR2rOpt(UContainerList);
    for (UIntT i = 1; i <= bandCount; ++i)
    {
        UStringT num = i;
        strR2rOpt.Add("-b");
        strR2rOpt.Add(num);
    }
    strR2rOpt.Add("-co");
    strR2rOpt.Add("LATITUDE=0");
    strR2rOpt.Add("-co");
    strR2rOpt.Add("LINEAR_UNIT=METER");
    GdaTrRstToRstT r2rOpt;
    r2rOpt.SetAll(frmt, &strR2rOpt);
    trRst->ToRst(aDst, dsTif, &r2rOpt);
    drTif->Close(aSrc);

    return UErrFalse;
}

/***** Private B *****/
