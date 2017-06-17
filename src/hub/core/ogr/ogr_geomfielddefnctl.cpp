/******************************************************************************
 * $Id: ogr_geomfielddefnctl.hpp 2016-08 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr geometry field definition control implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016, Weiwei Huang
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ****************************************************************************/

#include "ogr_geomfielddefnctl.hpp"

// GDAL/OGR library.
#include "ogr_api.h"

/**
 * \brief Constructor.
 */
COgrGeomFieldDefnCtl::COgrGeomFieldDefnCtl()
{
}

/**
 * \brief Destructor.
 */
COgrGeomFieldDefnCtl::~COgrGeomFieldDefnCtl()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrGeomFieldDefnCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Attach handle for OGRGeometryDefnH.
 */
UErrCodeT COgrGeomFieldDefnCtl::Attach(OgrGeomFieldDefnHT aHandle)
{
    m_handle = (OGRGeomFieldDefnH)aHandle;
    return UErrFalse;
}

/**
 * \brief Get geometry name.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrGeomFieldDefnCtl::Name(UStringT* aName)
{
    *aName = OGR_GFld_GetNameRef((OGRGeomFieldDefnH) m_handle);

    return UErrFalse;
}

/**
 * \brief Set geometry name.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrGeomFieldDefnCtl::SetName(UStringT* aName)
{
    OGR_GFld_SetName((OGRGeomFieldDefnH) m_handle, aName->ToA());

    return UErrFalse;
}

/**
 * \brief Get geometry type.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrGeomFieldDefnCtl::Type(UGeometryTCodeT* aCode)
{
    OGRwkbGeometryType type = OGR_GFld_GetType((OGRGeomFieldDefnH) m_handle);
    *aCode = ToUGeometryTCodeT(type);

    return UErrFalse;
}

/**
 * \brief Set geometry type.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrGeomFieldDefnCtl::SetType(UGeometryTCodeT aCode)
{
    OGRwkbGeometryType type = ToOGRwkbGeometryType(aCode);
    OGR_GFld_SetType((OGRGeomFieldDefnH) m_handle, type);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Translate "OGRwkbGeometryType" to "UGeometryTCodeT".
 *
 * @return Code of "UGeometryTCodeT", if successful; -1, if failed.
 */
UGeometryTCodeT COgrGeomFieldDefnCtl::ToUGeometryTCodeT(OGRwkbGeometryType aCode)
{
    return (UGeometryTCodeT) aCode;
}

/**
 * \brief Translate "UGeometryTCodeT" to "OGRwkbGeometryType".
 *
 * @return Code of "OGRwkbGeometryType", if successful; -1, if failed.
 */
OGRwkbGeometryType COgrGeomFieldDefnCtl::ToOGRwkbGeometryType(UGeometryTCodeT aCode)
{
    return (OGRwkbGeometryType) aCode;
}

/***** Private B *****/
