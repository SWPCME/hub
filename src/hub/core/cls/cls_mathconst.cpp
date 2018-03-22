/******************************************************************************
 * $Id: cls_mathconst.hpp 2017-10 $
 *
 * Project:  C language standard library.
 * Purpose:  Math constants implementation.
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

#include "cls_mathconst.hpp"

// libc
#include "math.h"

/**
 * \brief Constructor.
 */
CClsMathConst::CClsMathConst()
{
}

/**
 * \brief Destructor.
 */
CClsMathConst::~CClsMathConst()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsMathConst::Init()
{
    return UErrFalse;
}

/**
 * \brief Pi.
 */
UFloatT CClsMathConst::Pi()
{
#ifdef OS_WINDOWS
#define M_PI 3.14159265358979323846
#endif  // OS_WINDOWS
    return M_PI;
}
