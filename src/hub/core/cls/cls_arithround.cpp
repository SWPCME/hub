/******************************************************************************
 * $Id: cls_arithround.cpp 2017-11 $
 *
 * Project:  C language standard library.
 * Purpose:  Math arithmetic rounding implementation.
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

#include "cls_arithround.hpp"

// libc
#include "math.h"

/**
 * \brief Constructor.
 */
CClsArithRound::CClsArithRound()
{
}

/**
 * \brief Destructor.
 */
CClsArithRound::~CClsArithRound()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsArithRound::Init()
{
    return UErrFalse;
}

/**
 * \brief Floor.
 */
UErrCodeT CClsArithRound::Floor(UFloatT *aY, UFloatT aX)
{
    *aY = floor(aX);

    return UErrFalse;
}
