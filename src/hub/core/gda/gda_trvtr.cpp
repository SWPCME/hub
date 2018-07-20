/******************************************************************************
 * $Id: gda_trvtr.cpp 2017-08 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Translate vector implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-07 ~ 2017, Weiwei Huang
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

#include "gda_trvtr.hpp"

// gda
#include "gda_datasetctl.hpp"
#include "gda_trvtrprocctl.hpp"
// ogr
#include "ogr_datasrcctl.hpp"

// GDAL
#include "gdal_utils.h"

/**
 * \brief Constructor.
 */
CGdaTrVtr::CGdaTrVtr()
{
    InitPointer();
}

/**
 * \brief Destructor.
 */
CGdaTrVtr::~CGdaTrVtr()
{
    BMD_CLASS_DEL(mProc);
    InitPointer();
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaTrVtr::Init()
{
    return UErrFalse;
}

/**
 * \brief Processing controler.
 */
CGdaTrVtrProcCtl *CGdaTrVtr::ProcCtl()
{
    BMD_CLASS_NEW(mProc, CGdaTrVtrProcCtl);

    return mProc;
}

/**
 * \brief To raster.
 */
UErrCodeT CGdaTrVtr::ToRst(const UStringT *aDst, const CGdaDatasetCtl *aSrc,
                           const GdaTrVtrToRstT *aProc)
{
    char *dst = NULL;
    if (aDst->IsNull() == UErrTrue)
    {
        dst = (char *) aDst->ToA();
    }

    GDALDatasetH dstDsH = NULL;
    GDALDatasetH srcDsH = (GDALDatasetH) aSrc->Handle();

    GDALRasterizeOptions *opt = NULL;
    if (aProc != NULL)
    {
        opt = (GDALRasterizeOptions *) aProc->Handle();
    }

    // The "err", default must be set "FALSE", because the code will set the
    // "err" only it has error.
    int err = FALSE;
    GDALDatasetH ds = GDALRasterize(dst, dstDsH, srcDsH, opt, &err);

    if (err == CE_None)
    {
        GDALClose(ds);

        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief To vector.
 */
UErrCodeT CGdaTrVtr::ToVtr(const UStringT *aDst, const OgrCtnDatasrcT *aSrc,
                           const GdaTrVtrToVtrT *aProc)
{
    const char *dst = NULL;
    if (aDst->IsNull() == UErrTrue)
    {
        dst = (char *) aDst->ToA();
    }

    GDALDatasetH dstDsH = NULL;

    const int kSrcCount = aSrc->Count();
    GDALDatasetH srcDsH[kSrcCount];
    for (UIntT i = 0; i < kSrcCount; ++i)
    {
        const COgrDatasrcCtl *srcDs = (*aSrc)[0];
        srcDsH[i] = (GDALDatasetH) srcDs->Handle();
    }

    GDALVectorTranslateOptions *opt =
        (GDALVectorTranslateOptions *) aProc->Handle();

    // The "err", default must be set "FALSE", because the code will set the
    // "err" only it has error.
    int err = FALSE;
    dstDsH = (GdaDatasetHT) GDALVectorTranslate(dst, dstDsH,
                                                kSrcCount, srcDsH,
                                                opt, &err);

    if (err == CE_None)
    {
        GDALClose(dstDsH);

        return UErrFalse;
    }

    return UErrTrue;
}

/***** Private A *****/

/**
 * \brief Init pointer.
 */
UErrCodeT CGdaTrVtr::InitPointer()
{
    BMD_POINTER_INIT(mProc);

    return UErrFalse;
}

/***** Private B *****/
