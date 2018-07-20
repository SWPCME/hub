/******************************************************************************
 * $Id: gda_ogrsrstype.cpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Ogr spatial reference system type implementation.
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

#include "gda_ogrsrstype.hpp"

// gda
#include "gda_ogrsrsctl.hpp"

/**
 * \brief Constructor.
 */
GdaOgrSrsT::GdaOgrSrsT()
{
    InitPointer();
    Init();
}

/**
 * \brief Destructor.
 */
GdaOgrSrsT::~GdaOgrSrsT()
{
    BMD_CLASS_DEL(mSrs);
}

/**
 * \brief Get handle.
 */
GdaOgrSrsHT GdaOgrSrsT::Handle() const
{
    return mSrs->Handle();
}

/**
 * \brief Import from well known text format string.
 */
UErrCodeT GdaOgrSrsT::ImportFromWkt(const UStringT *aWkt)
{
    return mSrs->ImportFromWkt(aWkt);
}

/**
 * \brief Set a projected coordinate system.
 */
UErrCodeT GdaOgrSrsT::SetProjCs(const GdaProjCsCodeT aCode)
{
    return mSrs->SetProjCs(aCode);
}

/**
 * \brief Get a projected coordinate system.
 */
UErrCodeT GdaOgrSrsT::ProjCs(GdaProjCsCodeT *aCode)
{
    return mSrs->ProjCs(aCode);
}

/**
 * \brief Convert this SRS into WKT format.
 */
UErrCodeT GdaOgrSrsT::ExportToWkt(UStringT *aWkt)
{
    return mSrs->ExportToWkt(aWkt);
}

/**
 * \brief Compare wkt.
 */
UErrCodeT GdaOgrSrsT::Cmp(const GdaOgrSrsT *aSrs)
{
    return mSrs->Cmp(aSrs);
}

/**
 * \brief Operator =.
 */
UErrCodeT GdaOgrSrsT::operator =(const GdaOgrSrsT &aSrs)
{
    UStringT src;
    aSrs.ExportToWkt(&src);
    ImportFromWkt(&src);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Init pointer.
 */
UErrCodeT GdaOgrSrsT::InitPointer()
{
    BMD_POINTER_INIT(mSrs);

    return UErrFalse;
}

/**
 * \brief Initialize.
 */
UErrCodeT GdaOgrSrsT::Init()
{
    BMD_CLASS_NEW(mSrs, CGdaOgrSrsCtl);

    return UErrFalse;
}

/***** Private B *****/
