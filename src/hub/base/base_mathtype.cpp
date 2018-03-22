/******************************************************************************
 * $Id: base_mathtype.hpp 2017-11 $
 *
 * Project:  Base.
 * Purpose:  Base math type implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016-08 ~ 2017 Weiwei Huang
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

#include "base_mathtype.hpp"

/***** BMathCsC2dT A *****/

/**
 * \brief Constructor.
 */
BMathCsC2dT::BMathCsC2dT()
{
    Init();
}

/**
 * \brief Constructor.
 */
BMathCsC2dT::BMathCsC2dT(const UFloatT aX, const UFloatT aY)
{
    Init();
    SetAll(aX, aY);
}

/**
 * \brief Destructor.
 */
BMathCsC2dT::~BMathCsC2dT()
{
}

/**
 * \brief Set all.
 */
UErrCodeT BMathCsC2dT::SetAll(const UFloatT aX, const UFloatT aY)
{
    mX = aX;
    mY = aY;

    return UErrFalse;
}

/**
 * \brief Set x.
 */
UErrCodeT BMathCsC2dT::SetX(const UFloatT aX)
{
    mX = aX;

    return UErrFalse;
}

/**
 * \brief Set y.
 */
UErrCodeT BMathCsC2dT::SetY(const UFloatT aY)
{
    mY = aY;

    return UErrFalse;
}

/**
 * \brief Get all.
 */
UErrCodeT BMathCsC2dT::All(UFloatT *aX, UFloatT *aY) const
{
    *aX = mX;
    *aY = mY;

    return UErrFalse;
}

/**
 * \brief Get x.
 */
UFloatT BMathCsC2dT::X() const
{
    return mX;
}

/**
 * \brief Get y.
 */
UFloatT BMathCsC2dT::Y() const
{
    return mY;
}

/***** BMathCsC2dT Private A *****/

/**
 * \brief Initialize.
 */
UErrCodeT BMathCsC2dT::Init()
{
    mX = 0.0;
    mY = 0.0;

    return UErrFalse;
}

/***** BMathCsC2dT Private B *****/
/***** BMathCsC2dT B *****/

/***** BMathCsC3dT A *****/
/**
 * \brief Constructor.
 */
BMathCsC3dT::BMathCsC3dT()
{
    Init();
}

/**
 * \brief Constructor.
 */
BMathCsC3dT::BMathCsC3dT(const UFloatT aX, const UFloatT aY, const UFloatT aZ)
{
    Init();
    SetAll(aX, aY, aZ);
}

/**
 * \brief Destructor.
 */
BMathCsC3dT::~BMathCsC3dT()
{
}

/**
 * \brief Set all.
 */
UErrCodeT BMathCsC3dT::SetAll(const UFloatT aX, const UFloatT aY, const UFloatT aZ)
{
    mX = aX;
    mY = aY;
    mZ = aZ;

    return UErrFalse;
}

/**
 * \brief Set x.
 */
UErrCodeT BMathCsC3dT::SetX(const UFloatT aX)
{
    mX = aX;

    return UErrFalse;
}

/**
 * \brief Set y.
 */
UErrCodeT BMathCsC3dT::SetY(const UFloatT aY)
{
    mY = aY;

    return UErrFalse;
}

/**
 * \brief Set z.
 */
UErrCodeT BMathCsC3dT::SetZ(const UFloatT aZ)
{
    mZ = aZ;

    return UErrFalse;
}

/**
 * \brief Get all.
 */
UErrCodeT BMathCsC3dT::All(UFloatT *aX, UFloatT *aY, UFloatT *aZ) const
{
    *aX = mX;
    *aY = mY;
    *aZ = mZ;

    return UErrFalse;
}

/**
 * \brief Get x.
 */
UFloatT BMathCsC3dT::X() const
{
    return mX;
}

/**
 * \brief Get y.
 */
UFloatT BMathCsC3dT::Y() const
{
    return mY;
}

/**
 * \brief Get z.
 */
UFloatT BMathCsC3dT::Z() const
{
    return mZ;
}

/***** BMathCsC3dT Private A *****/

/**
 * \brief Initialize.
 */
UErrCodeT BMathCsC3dT::Init()
{
    mX = 0.0;
    mY = 0.0;
    mZ = 0.0;

    return UErrFalse;
}

/***** BMathCsC3dT Private B *****/
/***** BMathCsC3dT B *****/
