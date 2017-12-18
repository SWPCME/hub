/******************************************************************************
 * $Id: gda_trvtrprocctl.cpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Translate vector processing controler implementation.
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
 *****************************************************************************/

#include "gda_trvtrprocctl.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_typectl.hpp"

// GDAL
#include "gdal_utils.h"

/**
 * \brief Constructor.
 */
CGdaTrVtrProcCtl::CGdaTrVtrProcCtl()
{
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Destructor.
 */
CGdaTrVtrProcCtl::~CGdaTrVtrProcCtl()
{
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaTrVtrProcCtl::Init()
{
    GDA_TYPE_CTL(mType);

    return UErrFalse;
}

/**
 * \brief New options.
 */
UErrCodeT CGdaTrVtrProcCtl::New(GdaTrVtrProcHT *aDst, BCtnStringT *aSrc,
                                const GdaFrmtFlagCodeT aFrmt)
{
    switch (aFrmt)
    {
    case GdaFrmtFlagRst:
        NewRst(aDst, aSrc);
        break;
    case GdaFrmtFlagVtr:
        NewVtr(aDst, aSrc);
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Delete options.
 */
UErrCodeT CGdaTrVtrProcCtl::Del(GdaTrVtrProcHT aProcH,
                                const GdaFrmtFlagCodeT aFrmt)
{
    switch (aFrmt)
    {
    case GdaFrmtFlagRst:
        DelRst(aProcH);
        break;
    case GdaFrmtFlagVtr:
        DelVtr(aProcH);
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Set progress for options.
 */
UErrCodeT CGdaTrVtrProcCtl::SetProg(GdaTrVtrProcHT aProcH, UHandleT aFunc,
                                    UHandleT aData,
                                    const GdaFrmtFlagCodeT aFrmt)
{
    switch (aFrmt)
    {
    case GdaFrmtFlagRst:
        SetProgRst(aProcH, aFunc, aData);
        break;
    case GdaFrmtFlagVtr:
        SetProgVtr(aProcH, aFunc, aData);
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief New raster options.
 */
UErrCodeT CGdaTrVtrProcCtl::NewRst(GdaTrVtrProcHT *aDst, BCtnStringT *aSrc)
{
    GdaArgvT argv = NULL;
    mType->NewArgv(&argv, aSrc);
    GDALRasterizeOptionsForBinary *optBin = NULL;
    *aDst = (GdaTrVtrProcHT) GDALRasterizeOptionsNew
        ((char **) argv, optBin);
    mType->DelArgv(argv);

    return UErrFalse;
}

/**
 * \brief Delete raster options.
 */
UErrCodeT CGdaTrVtrProcCtl::DelRst(GdaTrVtrProcHT aProcH)
{
    GDALRasterizeOptionsFree((GDALRasterizeOptions *) aProcH);

    return UErrFalse;
}

/**
 * \brief Set raster progress for options.
 */
UErrCodeT CGdaTrVtrProcCtl::SetProgRst(GdaTrVtrProcHT aProcH, UHandleT aFunc,
                                       UHandleT aData)
{
    return UErrFalse;
}

/**
 * \brief New vector options.
 */
UErrCodeT CGdaTrVtrProcCtl::NewVtr(GdaTrVtrProcHT *aDst, BCtnStringT *aSrc)
{
    GdaArgvT argv = NULL;
    mType->NewArgv(&argv, aSrc);
    GDALVectorTranslateOptionsForBinary *optBin = NULL;
    *aDst = (GdaTrVtrProcHT) GDALVectorTranslateOptionsNew
        ((char **) argv, optBin);
    mType->DelArgv(argv);

    return UErrFalse;
}

/**
 * \brief Delete vector options.
 */
UErrCodeT CGdaTrVtrProcCtl::DelVtr(GdaTrVtrProcHT aProcH)
{
    GDALVectorTranslateOptionsFree((GDALVectorTranslateOptions *) aProcH);

    return UErrFalse;
}

/**
 * \brief Set vector progress for options.
 */
UErrCodeT CGdaTrVtrProcCtl::SetProgVtr(GdaTrVtrProcHT aProcH, UHandleT aFunc,
                                       UHandleT aData)
{
    return UErrFalse;
}

/***** Private B *****/
