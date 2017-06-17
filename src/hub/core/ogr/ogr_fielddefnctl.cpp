/******************************************************************************
 * $Id: ogr_fielddefnctl.cpp 2016-08 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.a
 * Purpose:  Ogr field definition control implementation.
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

#include "ogr_fielddefnctl.hpp"

// GDAL/OGR library.
#include "ogr_api.h"

/**
 * \brief Constructor.
 */
COgrFieldDefnCtl::COgrFieldDefnCtl()
{
}

/**
 * \brief Destructor.
 */
COgrFieldDefnCtl::~COgrFieldDefnCtl()
{
}

/**
 * \brief Initialize
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrFieldDefnCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Set field name.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrFieldDefnCtl::SetName(UStringT* aName)
{
    OGR_Fld_SetName(m_handle, aName->ToA());

    return UErrFalse;
}

/**
 * \brief Get field name.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrFieldDefnCtl::Name(UStringT* aName)
{
    *aName = OGR_Fld_GetNameRef(m_handle);

    return UErrFalse;
}

/**
 * \brief Set field type.
 */
UErrCodeT COgrFieldDefnCtl::SetType(UDataTCodeT aCode)
{
    OGRFieldType fieldType = ToOGRFieldType(aCode);
    OGR_Fld_SetType(m_handle, fieldType);

    return UErrFalse;
}

/**
 * \brief Get field type.
 */
UErrCodeT COgrFieldDefnCtl::Type(UDataTCodeT* aCode)
{
    OGRFieldType fieldType = OGR_Fld_GetType(m_handle);
    *aCode = ToUDataTypeCodeT(fieldType);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Translate "UDataTypeCodeT" to "OGRFieldType".
 *
 * @return Code of "OGRFieldType", if successful; -1, if failed.
 */
OGRFieldType COgrFieldDefnCtl::ToOGRFieldType(UDataTCodeT aCode)
{
    return (OGRFieldType) aCode;
}

/**
 * \brief Translate "OGRFieldType" to "OGRFieldType"
 */
UDataTCodeT COgrFieldDefnCtl::ToUDataTypeCodeT(OGRFieldType aCode)
{
    return (UDataTCodeT) aCode;
}

/***** Private B *****/
