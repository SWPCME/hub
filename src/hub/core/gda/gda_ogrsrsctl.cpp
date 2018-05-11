/******************************************************************************
 * $Id: gda_ogrsrsctl.cpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Ogr spatial reference system control implementation.
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

#include "gda_ogrsrsctl.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_typectl.hpp"

// GDAL
#include "ogr_srs_api.h"

/**
 * \brief Constructor.
 */
CGdaOgrSrsCtl::CGdaOgrSrsCtl()
{
    New();
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Destructor.
 */
CGdaOgrSrsCtl::~CGdaOgrSrsCtl()
{
    Destroy();
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaOgrSrsCtl::Init()
{
    GDA_TYPE_CTL(mType);

    return UErrFalse;
}

/**
 * \brief Get handle.
 */
GdaOgrSrsHT CGdaOgrSrsCtl::Handle() const
{
    return mSrsH;
}

/**
 * \brief Import from well known text format string.
 */
UErrCodeT CGdaOgrSrsCtl::ImportFromWkt(const UStringT *aWkt)
{
    BCtnStringT srcWkt(UContainerList);
    srcWkt.Add(*aWkt);
    GdaArgvT dstWkt = NULL;
    mType->NewArgv(&dstWkt, &srcWkt);
    char **wkt = (char **) dstWkt;
    OGRErr err = OSRImportFromWkt((OGRSpatialReferenceH) mSrsH, wkt);
    UStringT test = wkt[0];
    if (test.IsNull() == UErrTrue)
    {
        mType->DelArgv(dstWkt);
    }

    if (err == OGRERR_NONE)
    {
        return UErrFalse;
    }

    return UErrFalse;
}

/**
 * \brief Set a projected coordinate system.
 */
UErrCodeT CGdaOgrSrsCtl::SetProjCs(const GdaProjCsCodeT aCode)
{
    UIntT num;
    mType->ToProjCs(&num, aCode);
    OGRErr err = OSRImportFromEPSG((OGRSpatialReferenceH) mSrsH, num);

    if (err == OGRERR_NONE)
    {
        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief Convert this SRS into WKT format.
 */
UErrCodeT CGdaOgrSrsCtl::ExportToWkt(UStringT *aWkt)
{
    char *wkt = NULL;
    OGRErr err = OSRExportToWkt((OGRSpatialReferenceH) mSrsH, &wkt);

    if (err == 0)
    {
        *aWkt = wkt;
        return UErrFalse;
    }

    return UErrTrue;
}

/***** Private A *****/

/**
 * \brief New.
 */
UErrCodeT CGdaOgrSrsCtl::New()
{
    const char *name = NULL;
    mSrsH = (GdaOgrSrsHT) OSRNewSpatialReference(name);

    return UErrFalse;
}

/**
 * \brief Destroy.
 */
UErrCodeT CGdaOgrSrsCtl::Destroy()
{
    OSRDestroySpatialReference((OGRSpatialReferenceH) mSrsH);

    return UErrFalse;
}

/***** Private B *****/
