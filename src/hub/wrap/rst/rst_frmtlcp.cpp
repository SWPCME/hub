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
    // Create tif with elevation.
    UStringT tif = mTmpDir;
    tif += "/create_tif.tif";
    CreateTif(&tif, aElev, aCode);

    // Translate to lcp.
    TrTif2Lcp(aLcp, &tif);

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
 * \brief Create tif.
 */
UErrCodeT CRstFrmtLcp::CreateTif(const UStringT *aTif, const UStringT *aElev,
                                 const GdaProjCsCodeT aCode)
{
    // Create initialize.
    GdaFormatCodeT frmtTif = GdaFormatTif;
    mDrs->Register(frmtTif);
    CGdaDriverCtl *drTif = mDrs->Driver(frmtTif);

    // Change the projection coordinate system.
    UStringT elev = mTmpDir;
    elev += "/elevation.tif";
    GdaOgrSrsT elevSrs;
    elevSrs.SetProjCs(aCode);
    Reproj(&elev, aElev, &elevSrs);

    // open elev tif
    UAccessCodeT access = UAccessWrite;
    CGdaDatasetCtl *dsElev = drTif->Load(&elev, access);

    // Process elev for nodata value.
    CGdaBandCtl *bandElev = dsElev->Band(1);
    UFloatT ndVal = -9999.0;
    SetBandVal(bandElev, ndVal, UFlagOn);

    // Dem process for slope.
    GdaDemProcFrmtCodeT demSlope = GdaDemProcFrmtSlope;
    UStringT slope = mTmpDir;
    slope += "/slope.tif";
    DemProc(&slope, dsElev, demSlope);

    // Dem process for aspect.
    GdaDemProcFrmtCodeT demAspect = GdaDemProcFrmtAspect;
    UStringT aspect = mTmpDir;
    aspect += "/aspect.tif";
    DemProc(&aspect, dsElev, demAspect);

    // Create tif with elev, conatains band 1.
    CreateTifTmp(aTif, dsElev, ndVal);

    // close elev tif
    drTif->Close(&elev);

    // open aTif
    CGdaDatasetCtl *dsTif = drTif->Load(aTif, access);

    // Set band 2 for tif.
    CGdaDatasetCtl *dsSlope = drTif->Load(&slope);
    CGdaBandCtl *bandSlope = dsSlope->Band(1);
    dsTif->SetBand(2, bandSlope);
    drTif->Close(&slope);

    // Set band 3 for tif.
    CGdaDatasetCtl *dsAspect = drTif->Load(&aspect);
    CGdaBandCtl *bandAspect = dsAspect->Band(1);
    dsTif->SetBand(3, bandAspect);
    drTif->Close(&aspect);

    // Set band 4 for tif.
    CGdaBandCtl *bandTif4 = dsTif->Band(4);
    UFloatT bandTifVal4 = 165;
    SetBandVal(bandTif4, bandTifVal4, UFlagOff);

    // Set band 5 for tif.
    CGdaBandCtl *bandTif5 = dsTif->Band(5);
    UFloatT bandTifVal5 = 80;
    SetBandVal(bandTif5, bandTifVal5, UFlagOff);

    // Close aTif.
    drTif->Close(aTif);

    return UErrFalse;
}

/**
 * \brief Create temporary tif.
 */
UErrCodeT CRstFrmtLcp::CreateTifTmp(const UStringT *aTif, CGdaDatasetCtl *aDs,
                                    const UFloatT aNdVal)
{
    GdaFormatCodeT frmtTif = GdaFormatTif;
    CGdaTrRst *trRst = mTr->Rst();
    BCtnStringT strR2rOpt(UContainerList);
    GdaTrRstToRstT r2rOpt;
    UStringT strNdVal(aNdVal);

    UIntT bandCount = 5;
    for (UIntT i = 1; i <= bandCount; ++i)
    {
        strR2rOpt.Add("-b");
        strR2rOpt.Add("1");
    }
    strR2rOpt.Add("-a_nodata");
    strR2rOpt.Add(strNdVal.ToA());
    strR2rOpt.Add("-ot");
    strR2rOpt.Add("Int16");
    r2rOpt.SetAll(frmtTif, &strR2rOpt);
    trRst->ToRst(aTif, aDs, &r2rOpt);

    return UErrFalse;
}

/**
 * \brief Set no data value.
 *
 * @param aDs, dataset controler.
 * @param aNdVal, no data value.
 */
UErrCodeT CRstFrmtLcp::SetBandVal(CGdaBandCtl *aBand, UFloatT aVal,
                                  UFlagCodeT aFlag)
{
    // Get band data.
    UDataTCodeT dataT = aBand->DataT();
    UIntT xSize = 0;
    aBand->XSize(&xSize);
    UIntT ySize = 0;
    aBand->YSize(&ySize);
    BMathCsC2dT bdBegin(0, 0);
    BMathCsC2dT bdEnd(xSize - 1, ySize - 1);
    GdaBandDataT bandData(dataT, &bdBegin, &bdEnd);
    aBand->Read(&bandData);

    // Set band data.
    UIntT size = xSize * ySize;
    if (aFlag == UFlagOn)
    {
        float *val = (float *) bandData.Handle();
        UFloatT ndVal = aBand->NoDataVal();
        for (UIntT i = 0; i < size; ++i)
        {
            if (val[i] == ndVal)
            {
                val[i] = aVal;
            }
        }
    }
    else
    {
        int16_t *val = (int16_t *) bandData.Handle();
        for (UIntT i = 0; i < size; ++i)
        {
            val[i] = aVal;
        }
    }

    // Write band data.
    aBand->Write(&bandData);

    if (aFlag == UFlagOn)
    {
        aBand->SetNoDataVal(aVal);
    }

    return UErrFalse;
}

/**
 * \brief Dem process.
 */
UErrCodeT CRstFrmtLcp::DemProc(const UStringT *aDem, CGdaDatasetCtl *aDs,
                               const GdaDemProcFrmtCodeT aFrmt)
{
    GdaDemProcT proc;
    BCtnStringT opt(UContainerList);
    opt.Add("-of");
    opt.Add("GTiff");
    proc.SetAll(aFrmt, &opt);
    mDem->Proc(aDem, aDs, &proc);

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
    if (dstSrs->Cmp(srcSrs) == UErrFalse)
    {
        CClsFsCreate *fsCreate = mFs->Create();
        fsCreate->Copy(aDst, aSrc);
    }
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

/**
 * \brief Translate tif to lcp.
 */
UErrCodeT CRstFrmtLcp::TrTif2Lcp(const UStringT *aLcp, const UStringT *aTif)
{
    // Load tif.
    GdaFormatCodeT frmtTif = GdaFormatTif;
    mDrs->Register(frmtTif);
    CGdaDriverCtl *drTif = mDrs->Driver(frmtTif);
    CGdaDatasetCtl *dsTif = drTif->Load(aTif);

    // Translate tif to lcp.
    CGdaTrRst *trRst = mTr->Rst();
    GdaFormatCodeT frmtLcp = GdaFormatLcp;
    UIntT bandCount = 5;
    BCtnStringT strR2rOpt(UContainerList);
    for (UIntT i = 1; i <= bandCount; ++i)
    {
        UStringT num = i;
        strR2rOpt.Add("-b");
        strR2rOpt.Add(num);
    }
    GdaTrRstToRstT r2rOpt;
    strR2rOpt.Add("-co");
    strR2rOpt.Add("LATITUDE=0");
    strR2rOpt.Add("-co");
    strR2rOpt.Add("LINEAR_UNIT=METER");
    r2rOpt.SetAll(frmtLcp, &strR2rOpt);
    trRst->ToRst(aLcp, dsTif, &r2rOpt);

    // Close tif.
    drTif->Close(aTif);

    return UErrFalse;
}

/***** Private B *****/
