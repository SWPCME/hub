/******************************************************************************
 * $Id: gda_trrstprocctl.cpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Translate raster processing controler implementation.
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

#include "gda_trrstprocctl.hpp"

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
CGdaTrRstProcCtl::CGdaTrRstProcCtl()
{
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Destructor.
 */
CGdaTrRstProcCtl::~CGdaTrRstProcCtl()
{
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaTrRstProcCtl::Init()
{
    GDA_TYPE_CTL(mType);

    return UErrFalse;
}

/**
 * \brief New options.
 */
UErrCodeT CGdaTrRstProcCtl::New(GdaTrRstProcHT *aDst, BCtnStringT *aSrc,
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
UErrCodeT CGdaTrRstProcCtl::Del(GdaTrRstProcHT aProcH,
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
UErrCodeT CGdaTrRstProcCtl::SetProg(GdaTrRstProcHT aProcH, UHandleT aFunc,
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
UErrCodeT CGdaTrRstProcCtl::NewRst(GdaTrRstProcHT *aDst, BCtnStringT *aSrc)
{
    GDALTranslateOptionsForBinary *optBin = NULL;
    GdaArgvT argv = NULL;
    mType->NewArgv(&argv, aSrc);

    *aDst = (GdaTrRstProcHT) GDALTranslateOptionsNew((char **) argv,
                                                     optBin);

    mType->DelArgv(argv);

    return UErrFalse;
}

/**
 * \brief Delete raster options.
 */
UErrCodeT CGdaTrRstProcCtl::DelRst(GdaTrRstProcHT aProcH)
{
    if (aProcH == NULL)
    {
        return UErrFalse;
    }

    GDALTranslateOptionsFree((GDALTranslateOptions *) aProcH);

    return UErrFalse;
}

/**
 * \brief Set raster progress for options.
 */
UErrCodeT CGdaTrRstProcCtl::SetProgRst(GdaTrRstProcHT aProcH, UHandleT aFunc,
                                       UHandleT aData)
{
    return UErrFalse;
}

/**
 * \brief New vector options.
 */
UErrCodeT CGdaTrRstProcCtl::NewVtr(GdaTrRstProcHT *aDst, BCtnStringT *aSrc)
{
    return UErrFalse;
}

/**
 * \brief Delete vector options.
 */
UErrCodeT CGdaTrRstProcCtl::DelVtr(GdaTrRstProcHT aProcH)
{
    return UErrFalse;
}

/**
 * \brief Set vector progress for options.
 */
UErrCodeT CGdaTrRstProcCtl::SetProgVtr(GdaTrRstProcHT aProcH, UHandleT aFunc,
                                       UHandleT aData)
{
    return UErrFalse;
}

/***** Private B *****/
