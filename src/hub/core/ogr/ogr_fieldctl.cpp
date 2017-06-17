/******************************************************************************
 * $Id: ogr_fieldctl.cpp 2016-08 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr field control implementation.
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

#include "ogr_fieldctl.hpp"

// Module
#include "ogr_api.h"

/**
 * \brief Constructor.
 */
COgrFieldCtl::COgrFieldCtl()
{
}

/**
 * \brief Destructor.
 */
COgrFieldCtl::~COgrFieldCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT COgrFieldCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Attach handle of feature.
 */
UErrCodeT COgrFieldCtl::Attach(OgrFieldHT aHandle)
{
    m_handle = aHandle;

    return UErrFalse;
}

/**
 * \brief Get value of field.
 *
 * @param aValue The value of this column.
 * @param aColumn The column in this feature.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrFieldCtl::Value(UStringT* aValue, UIntT aColumn)
{
    // aValue = OGR_F_GetFieldAsString(m_handle, (int) aColumn);

    return UErrFalse;
}

/**
 * \brief Get value of field.
 *
 * @param aValue The value of this column.
 * @param aName The name of column in this feature.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrFieldCtl::Value(UStringT* aValue, UStringT* aName)
{
    // aValue = OGR_F_GetFieldAsString(m_handle, aName->ToA());

    return UErrFalse;
}

/**
 * \brief Set feature value.
 *
 * Get feature value as string.
 *
 * @param aValue Get the value by the column in this feature.
 * @param aColumn The column in this feature.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrFieldCtl::SetValue(UStringT* aValue, UIntT aColumn)
{
    OGR_F_SetFieldString((OGRFeatureH) m_handle, (int) aColumn, aValue->ToA());

    return UErrFalse;
}
