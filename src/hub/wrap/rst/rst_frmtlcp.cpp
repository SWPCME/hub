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
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_filesctl.hpp"
#include "cls_fileswork.hpp"
#include "cls_filescreate.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_corectl.hpp"
#include "gda_driversctl.hpp"
#include "gda_driverctl.hpp"
#include "gda_datasetctl.hpp"
#include "gda_bandctl.hpp"
#include "gda_utilsctl.hpp"
#include "gda_utilstr.hpp"
#include "gda_trrst.hpp"
#include "gda_trrsttorsttype.hpp"
#include "gda_utilsdem.hpp"
#include "gda_demproctype.hpp"

/**
 * \brief Constructor.
 */
CRstFrmtLcp::CRstFrmtLcp()
{
    InitPointer();
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
    CClsCtl *cls = NULL;
    CLS_CTL(cls);
    mFs = cls->Files();

    CGdaCoreCtl *core = NULL;
    GDA_CORE_CTL(core);
    mDrs = core->Drivers();

    CGdaUtilsCtl *utils = NULL;
    GDA_UTILS_CTL(utils);
    mDem = utils->Dem();
    mTr = utils->Tr();

    return UErrFalse;
}

/**
 * \brief Create with elevation, fuel model, and canopy with tree.
 */
UErrCodeT CRstFrmtLcp::Create(const UStringT *aLcp, const UStringT *aElev,
                              const UStringT *aFm, const UStringT *aCt)
{
    // Load tif.
    GdaFormatCodeT frmt = GdaFormatTif;
    mDrs->Register(frmt);
    CGdaDriverCtl *drTif = mDrs->Driver(frmt);

    // Prepare translate
    CGdaTrRst *trRst = mTr->Rst();
    BCtnStringT strR2rOpt(UContainerList);
    GdaTrRstToRstT r2rOpt;

    // Process elev for nodata value.
    UStringT elev = mTmpDir;
    elev += "/elevation.tif";
    CClsFilesCreate *fsCreate = mFs->Create();
    fsCreate->Copy(&elev, aElev);
    UAccessCodeT access = UAccessWrite;
    CGdaDatasetCtl *dsElev = drTif->Load(&elev, access);
    CGdaBandCtl *bandElev = dsElev->Band(1);
    UFloatT ndv = -9999;
    UStringT strNdv(ndv);
    UFloatT ndvElev = bandElev->NoDataVal();
    UDataTCodeT dataT = bandElev->DataT();
    UIntT xSize = 0;
    bandElev->XSize(&xSize);
    UIntT ySize = 0;
    bandElev->YSize(&ySize);
    BMathCsC2dT bdBegin(0, 0);
    BMathCsC2dT bdEnd(xSize, ySize);
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
    strR2rOpt.Clear();
    strR2rOpt.Add("-b");
    strR2rOpt.Add("1");
    strR2rOpt.Add("-b");
    strR2rOpt.Add("1");
    strR2rOpt.Add("-b");
    strR2rOpt.Add("1");
    strR2rOpt.Add("-b");
    strR2rOpt.Add("1");
    strR2rOpt.Add("-b");
    strR2rOpt.Add("1");
    strR2rOpt.Add("-a_nodata");
    strR2rOpt.Add(strNdv.ToA());
    strR2rOpt.Add("-ot");
    strR2rOpt.Add("Int16");
    r2rOpt.SetAll(frmt, &strR2rOpt);
    trRst->ToRst(&lcpTmp, dsElev, &r2rOpt);

    // Set band 1, 2, 3 for lcpTmp.
    CGdaDatasetCtl *dsLcpTmp = drTif->Load(&lcpTmp, access);
    CGdaBandCtl *bandSlope = dsSlope->Band(1);
    dsLcpTmp->SetBand(2, bandSlope);
    CGdaBandCtl *bandAspect = dsAspect->Band(1);
    dsLcpTmp->SetBand(3, bandAspect);

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
    strR2rOpt.Add("-b");
    strR2rOpt.Add("1");
    strR2rOpt.Add("-b");
    strR2rOpt.Add("2");
    strR2rOpt.Add("-b");
    strR2rOpt.Add("3");
    strR2rOpt.Add("-b");
    strR2rOpt.Add("4");
    strR2rOpt.Add("-b");
    strR2rOpt.Add("5");
    strR2rOpt.Add("-co");
    strR2rOpt.Add("LATITUDE=23");
    strR2rOpt.Add("-co");
    strR2rOpt.Add("LINEAR_UNIT=METER");
    r2rOpt.SetAll(frmt, &strR2rOpt);
    trRst->ToRst(aLcp, dsLcpTmp, &r2rOpt);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Initialize pointer.
 */
UErrCodeT CRstFrmtLcp::InitPointer()
{
    BMD_POINTER_INIT(mTr);
    BMD_POINTER_INIT(mDem);

    return UErrFalse;
}

/***** Private B *****/
