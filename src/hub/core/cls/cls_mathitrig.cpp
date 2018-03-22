/******************************************************************************
 * $Id: cls_mathitrig.cpp 2017-11 $
 *
 * Project:  C language standard library.
 * Purpose:  Math inverse trigonometry implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-11 ~ 2017 Weiwei Huang
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

#include "cls_mathitrig.hpp"

#include "math.h"

/**
 * \brief Constructor.
 */
CClsMathITrig::CClsMathITrig()
{
}

/**
 * \brief Destructor.
 */
CClsMathITrig::~CClsMathITrig()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsMathITrig::Init()
{
    return UErrFalse;
}

/**
 * \brief Inverse of sine.
 */
UErrCodeT CClsMathITrig::ASin(UFloatT *aY, const UFloatT aX)
{
    *aY = asin(aX);

    return UErrFalse;
}

/**
 * \brief Inverse of cosine.
 */
UErrCodeT CClsMathITrig::ACos(UFloatT *aY, const UFloatT aX)
{
    *aY = acos(aX);

    return UErrFalse;
}

/**
 * \brief Inverse of tangent.
 */
UErrCodeT CClsMathITrig::ATan(UFloatT *aY, const UFloatT aX)
{
    *aY = atan(aX);

    return UErrFalse;
}
