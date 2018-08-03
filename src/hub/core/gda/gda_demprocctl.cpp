/******************************************************************************
 * $Id: gda_demprocctl.cpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Dem(digital elevation model) processing controler implementation.
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

#include "gda_demprocctl.hpp"

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
CGdaDemProcCtl::CGdaDemProcCtl()
{
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Destructor.
 */
CGdaDemProcCtl::~CGdaDemProcCtl()
{
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaDemProcCtl::Init()
{
    GDA_TYPE_CTL(mType);

    return UErrFalse;
}

/**
 * \brief New option.
 */
UErrCodeT CGdaDemProcCtl::New(GdaDemProcHT *aDst, const BCtnStringT *aSrc)
{
    GdaArgvT argv = NULL;
    mType->NewArgv(&argv, aSrc);

    GDALDEMProcessingOptionsForBinary *bin = NULL;
    // SWPCME_A
    // *aDst = (GdaDemProcHT) GDALDEMProcessingOptionsNew((char **) argv, bin);
    // SWPCME_B

    mType->DelArgv(argv);

    return UErrFalse;
}

/**
 * \brief Delelte option.
 */
UErrCodeT CGdaDemProcCtl::Del(const GdaDemProcHT aProc)
{
    GDALDEMProcessingOptionsFree((GDALDEMProcessingOptions *) aProc);

    return UErrFalse;
}

/**
 * \brief Set progress for option.
 */
UErrCodeT CGdaDemProcCtl::SetProg(const GdaDemProcHT aProc,
                                  const UHandleT aFunc, const UHandleT aData)
{
    GDALDEMProcessingOptions *proc = (GDALDEMProcessingOptions *) aProc;
    GDALProgressFunc func = (GDALProgressFunc) aFunc;
    void *data = (void *) aData;
    GDALDEMProcessingOptionsSetProgress(proc, func, data);

    return UErrFalse;
}
