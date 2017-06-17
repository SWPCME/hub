/******************************************************************************
 * $Id: vtr_layerread.cpp 2016-08 $
 *
 * Project:  Vector Info Process
 * Purpose:  Vector layer read.
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

#include "vtr_layerread.hpp"

// Module
#include "ogr_fieldctl.hpp"

/**
 * \brief Constructor.
 */
CVtrLayerRead::CVtrLayerRead(CVtrLayerBase* aBase)
{
    m_base = aBase;
}

/**
 * \brief Destructor.
 */
CVtrLayerRead::~CVtrLayerRead()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CVtrLayerRead::Init()
{
    return UErrFalse;
}

/**
 * \brief Get field by the number of column.
 *
 * @return UErrFalse, if successful; Others, if failed.
 */
UErrCodeT CVtrLayerRead::FieldDefn(VtrFieldDefnT* aField, UIntT aColumn)
{
    return UErrFalse;
}

/**
 * \brief Get field by the name of field.
 *
 * @return UErrFalse, if successful; Others, if failed.
 */
UErrCodeT CVtrLayerRead::FieldDefn(VtrFieldDefnT* aField, UStringT* aName)
{
    return UErrFalse;
}

/**
 * \brief Get value by the number of column in target row.
 *
 * @return UErrFalse, if successful; Others, if failed.
 */
UErrCodeT CVtrLayerRead::Value(UStringT* aValue, UIntT aRow, UIntT aColumn)
{
    COgrFieldCtl* field = m_base->Field(aRow);
    field->Value(aValue, aColumn);

    return UErrFalse;
}

/**
 * \brief Get value by the name of field in target row.
 *
 * @return Value of this column.
 */
UErrCodeT CVtrLayerRead::Value(UStringT* aValue, UIntT aRow, UStringT* aName)
{
    COgrFieldCtl* field = m_base->Field(aRow);
    field->Value(aValue, aName);

    return UErrFalse;
}

/***** Private A *****/

/***** Private B *****/
