/******************************************************************************
 * $Id: gda_utilsdem.cpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Utils dem(digital elevation model) implementation.
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

#include "gda_utilsdem.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_typectl.hpp"
#include "gda_corectl.hpp"
#include "gda_driversctl.hpp"
#include "gda_driverctl.hpp"
#include "gda_datasetctl.hpp"
#include "gda_demprocctl.hpp"

// GDAL
#include "gdal_utils.h"

/**
 * \brief Constructor.
 */
CGdaUtilsDem::CGdaUtilsDem()
{
    BMD_POINTER_INIT(mProc);
    BMD_POINTER_INIT(mType);
    BMD_POINTER_INIT(mCore);
}

/**
 * \brief Destructor.
 */
CGdaUtilsDem::~CGdaUtilsDem()
{
    BMD_CLASS_DEL(mProc);
    BMD_POINTER_INIT(mType);
    BMD_POINTER_INIT(mCore);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaUtilsDem::Init()
{
    GDA_TYPE_CTL(mType);
    GDA_CORE_CTL(mCore);

    return UErrFalse;
}

/**
 * \brief Process controler.
 */
CGdaDemProcCtl *CGdaUtilsDem::ProcCtl()
{
    BMD_CLASS_NEW(mProc, CGdaDemProcCtl);

    return mProc;
}

/**
 * \brief Process.
 */
UErrCodeT CGdaUtilsDem::Proc(const UStringT *aDst, const CGdaDatasetCtl *aSrc,
                             const GdaDemProcT *aProc)
{
    const char *dst = aDst->ToA();

    GDALDatasetH src = (GDALDatasetH) aSrc->Handle();

    UStringT frmt;
    mType->ToDemProcFrmt(&frmt, aProc->Frmt());

    const char *frmtColor = NULL;
    const GDALDEMProcessingOptions *procH = aProc->Handle();
    int err = FALSE;
    GDALDatasetH ds = GDALDEMProcessing(dst, src, frmt.ToA(), frmtColor, procH, &err);

    if (err == CE_None)
    {
        GDALClose(ds);
        return UErrFalse;
    }

    return UErrTrue;
}
