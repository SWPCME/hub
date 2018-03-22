/******************************************************************************
 * $Id: base_graphtype.cpp 2017-12 $
 *
 * Project:  Base.
 * Purpose:  Base graph type implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017 Weiwei Huang
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

#include "base_graphtype.hpp"

/***** BGraphRgbaT A *****/

/**
 * \brief Constructor.
 */
BGraphRgbaT::BGraphRgbaT()
{
    Init();
}

/**
 * \brief Destructor.
 */
BGraphRgbaT::~BGraphRgbaT()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT BGraphRgbaT::Init()
{
    SetAll(0, 0, 0, 0.0);

    return UErrFalse;
}

/**
 * \brief Set all value.
 */
UErrCodeT BGraphRgbaT::SetAll(const UIntT aRed, const UIntT aGreen,
                              const UIntT aBlue, const UFloatT aAlpha)
{
    mRed = aRed;
    mGreen = aGreen;
    mBlue = aBlue;
    mAlpha = aAlpha;

    return UErrFalse;
}

/**
 * \brief Get all value.
 */
UErrCodeT BGraphRgbaT::All(UIntT *aRed, UIntT *aGreen, UIntT *aBlue,
                           UFloatT *aAlpha) const
{
    *aRed = mRed;
    *aGreen = mGreen;
    *aBlue = mBlue;
    *aAlpha = mAlpha;

    return UErrFalse;
}

/**
 * \brief Get red value.
 */
UIntT BGraphRgbaT::Red() const 
{
    return mRed;
}

/**
 * \brief Get green value.
 */
UIntT BGraphRgbaT::Green() const 
{
    return mGreen;
}

/**
 * \brief Get blue value.
 */
UIntT BGraphRgbaT::Blue() const 
{
    return mBlue;
}

/**
 * \brief Get alpha value.
 */
UFloatT BGraphRgbaT::Alpha() const 
{
    return mAlpha;
}

/***** BGraphRgbaT B *****/
