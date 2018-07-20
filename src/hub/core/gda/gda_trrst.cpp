/******************************************************************************
 * $Id: gda_trrst.hpp 2017-08 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Translate raster implementation.
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

#include "gda_trrst.hpp"

// GDAL
#include "gdal_utils.h"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_typectl.hpp"
#include "gda_datasetctl.hpp"
#include "gda_trrstprocctl.hpp"

/**
 * \brief Constructor.
 */
CGdaTrRst::CGdaTrRst()
{
    BMD_POINTER_INIT(mType);
    BMD_POINTER_INIT(mProc);
}

/**
 * \brief Destructor.
 */
CGdaTrRst::~CGdaTrRst()
{
    BMD_POINTER_INIT(mType);
    BMD_CLASS_DEL(mProc);
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGdaTrRst::Init()
{
    GDA_TYPE_CTL(mType);

    return UErrFalse;
}

/**
 * \brief Processing controler.
 */
CGdaTrRstProcCtl *CGdaTrRst::ProcCtl()
{
    BMD_CLASS_NEW(mProc, CGdaTrRstProcCtl);

    return mProc;
}

/**
 * \brief To raster.
 *
 * @param aFile Destination of file.
 * @param aSrcDsCtl Source dataset controler.
 * @param aOpt Gda translate raster options.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGdaTrRst::ToRst(const UStringT *aDst, CGdaDatasetCtl *aSrc,
                           const GdaTrRstToRstT *aOpt)
{
    GDALDatasetH srcDsH = (GDALDatasetH) aSrc->Handle();

    char *dst = (char *) aDst->ToA();
    GDALTranslateOptions *opt = (GDALTranslateOptions *) aOpt->Handle();

    int err = TRUE;
    GDALDatasetH ds = GDALTranslate(dst, srcDsH, opt, &err);

    if (err == CE_None)
    {
        GDALClose(ds);
        return UErrFalse;
    }

    return UErrTrue;
}

/***** Private A *****/
/***** Private B *****/
