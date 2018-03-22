/******************************************************************************
 * $Id: cls_mathtype.hpp 2017-11 $
 *
 * Project:  C language standard library.
 * Purpose:  Math type translate implementation.
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

#include "cls_mathtype.hpp"
// base
#include "base_ctl.hpp"
#include "base_macrodefn.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_mathctl.hpp"
#include "cls_mathconst.hpp"

/**
 * \brief Constructor.
 */
CClsMathType::CClsMathType()
{
    BMD_POINTER_INIT(mConst);
}

/**
 * \brief Destructor.
 */
CClsMathType::~CClsMathType()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsMathType::Init()
{
    return UErrFalse;
}

/**
 * \brief Degree to radian.
 */
UErrCodeT CClsMathType::DegToRad(UFloatT *aRad, const UFloatT aDeg)
{
    UFloatT pi = mConst->Pi();
    *aRad = aDeg * pi / 180;

    return UErrFalse;
}
