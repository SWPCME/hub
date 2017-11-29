/******************************************************************************
 * $Id: cls_mathtrig.cpp 2017-10 $
 *
 * Project:  C language standard library.
 * Purpose:  Math trigonometry implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-10 ~ 2017 Weiwei Huang
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

#include "cls_mathtrig.hpp"

// libc
#include "math.h"

/**
 * \brief Constructor.
 */
CClsMathTrig::CClsMathTrig()
{
}

/**
 * \brief Destructor.
 */
CClsMathTrig::~CClsMathTrig()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsMathTrig::Init()
{
    return UErrFalse;
}

/**
 * \brief Sine.
 *
 * @param aY The clacualte result.
 * @param aX The param of input.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsMathTrig::Sin(UFloatT *aY, const UFloatT aX)
{
    *aY = sin(aX);

    return UErrFalse;
}

/**
 * \brief Cosine.
 *
 * @param aY The clacualte result.
 * @param aX The param of input.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsMathTrig::Cos(UFloatT *aY, const UFloatT aX)
{
    *aY = cos(aX);

    return UErrFalse;
}

/**
 * \brief Tangent.
 *
 * @param aY The clacualte result.
 * @param aX The param of input.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsMathTrig::Tan(UFloatT *aY, const UFloatT aX)
{
    *aY = tan(aX);

    return UErrFalse;
}
