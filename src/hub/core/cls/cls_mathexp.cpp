/******************************************************************************
 * $Id: cls_mathexp.cpp 2017-06 $
 *
 * Project:  C language standard library.
 * Purpose:  Math exponentiation implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017 Weiwei Huang
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

#include "cls_mathexp.hpp"

// GLibC module.
#include "math.h"

/**
 * \brief Constructor.
 */
CClsMathExp::CClsMathExp()
{
}

/**
 * \brief Destructor.
 */
CClsMathExp::~CClsMathExp()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsMathExp::Init()
{
    return UErrFalse;
}

/**
 * \brief aY = Sqrt(aX).
 */
UErrCodeT CClsMathExp::Sqrt(UFloatT *aY, const UFloatT aX)
{
    *aY = sqrt(aX);

    return UErrFalse;
}

/**
 * \brief aY = aBase ^ aPower.
 */
UErrCodeT CClsMathExp::Pow(UFloatT *aY, const UFloatT aBase,
                           const UFloatT aPower)
{
    *aY = pow(aBase, aPower);

    return UErrFalse;
}
