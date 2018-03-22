/******************************************************************************
 * $Id: vtr_layerwrite.cpp 2016-08 $
 *
 * Project:  Vector Info Process
 * Purpose:  Vector layer write.
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

#include "vtr_layerwrite.hpp"

// Module.
#include "ogr_fieldctl.hpp"

/**
 * \brief Constructor.
 */
CVtrLayerWrite::CVtrLayerWrite(CVtrLayerBase* aBase)
{
    m_base = aBase;
}

/**
 * \brief Destructor.
 */
CVtrLayerWrite::~CVtrLayerWrite()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CVtrLayerWrite::Init()
{
    return UErrFalse;
}

/**
 * \brief Set Value of "UStringT"
 *
 * Set value, and the type is "UStringT".
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CVtrLayerWrite::SetValue(UStringT* aValue, UIntT aRow, UIntT aColumn)
{
    COgrFieldCtl* field = m_base->Field(aRow);
    field->SetValue(aValue, aColumn);

    return UErrFalse;
}

/**
 * \brief Set Value of "UIntT".
 *
 * Set value, and the type is "UIntT".
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CVtrLayerWrite::SetValue(UIntT aValue, UIntT aRow, UIntT aColumn)
{
    // UStringT value = aValue;
    // SetValue(&value, aColumn);

    return UErrFalse;
}

/**
 * \brief Set Value of "UFloatT".
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CVtrLayerWrite::SetValue(UFloatT aValue, UIntT aRow, UIntT aColumn)
{
    // UStringT value = aValue;
    // SetValue(&value, aColumn);

    return UErrFalse;
}
