/******************************************************************************
 * $Id: cls_matharith.cpp 2017-11 $
 *
 * Project:  C language standard library.
 * Purpose:  Math arithmetic implementation.
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

#include "cls_matharith.hpp"

// cls
#include "cls_arithround.hpp"

// base
#include "base_macrodefn.hpp"

/**
 * \brief Constructor.
 */
CClsMathArith::CClsMathArith()
{
    BMD_POINTER_INIT(mRound);
}

/**
 * \brief Destructor.
 */
CClsMathArith::~CClsMathArith()
{
    BMD_CLASS_DEL(mRound);
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsMathArith::Init()
{
    return UErrFalse;
}

/**
 * \brief Rounding.
 */
CClsArithRound *CClsMathArith::Round()
{
    BMD_CLASS_NEW(mRound, CClsArithRound);

    return mRound;
}
