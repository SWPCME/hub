/******************************************************************************
 * $Id: cls_mathctl.cpp 2017-05 $
 *
 * Project:  C language standard library.
 * Purpose:  Math controler implementation.
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

#include "cls_mathctl.hpp"

// base
#include "base_macrodefn.hpp"

// Cls: Math.
#include "cls_mathconst.hpp"
#include "cls_matharith.hpp"
#include "cls_mathtrig.hpp"
#include "cls_mathitrig.hpp"
#include "cls_mathexp.hpp"
#include "cls_mathlog.hpp"
#include "cls_mathtype.hpp"

/**
 * \brief Constructor.
 */
CClsMathCtl::CClsMathCtl()
{
    BMD_POINTER_INIT(mConst);
    BMD_POINTER_INIT(mArith);
    BMD_POINTER_INIT(mTrig);
    BMD_POINTER_INIT(mITrig);
    BMD_POINTER_INIT(mExp);
    BMD_POINTER_INIT(mLog);
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Destructor.
 */
CClsMathCtl::~CClsMathCtl()
{
    BMD_CLASS_DEL(mConst);
    BMD_CLASS_DEL(mArith);
    BMD_CLASS_DEL(mTrig);
    BMD_CLASS_DEL(mITrig);
    BMD_CLASS_DEL(mExp);
    BMD_CLASS_DEL(mLog);
    BMD_CLASS_DEL(mType);
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsMathCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Constants.
 */
CClsMathConst *CClsMathCtl::Const()
{
    BMD_CLASS_NEW(mConst, CClsMathConst);

    return mConst;
}

/**
 * \brief Arithmetic.
 */
CClsMathArith *CClsMathCtl::Arith()
{
    BMD_CLASS_NEW(mArith, CClsMathArith);

    return mArith;
}

/**
 * \brief Trigonometry.
 *
 * @return Handle of trigonometry, if successful; NULL, if failed.
 */
CClsMathTrig *CClsMathCtl::Trig()
{
    BMD_CLASS_NEW(mTrig, CClsMathTrig);

    return mTrig;
}

/**
 * \brief Inverse trigonometry.
 *
 * @return Handle of trigonometry, if successful; NULL, if failed.
 */
CClsMathITrig *CClsMathCtl::ITrig()
{
    BMD_CLASS_NEW(mITrig, CClsMathITrig);

    return mITrig;
}

/**
 * \brief Exponentiation.
 */
CClsMathExp *CClsMathCtl::Exp()
{
    BMD_CLASS_NEW(mExp, CClsMathExp);

    return mExp;
}

/**
 * \brief Logarithms.
 */
CClsMathLog *CClsMathCtl::Log()
{
    BMD_CLASS_NEW(mLog, CClsMathLog);

    return mLog;
}

/**
 * \brief Type translate.
 */
CClsMathType *CClsMathCtl::Type()
{
    BMD_CLASS_NEW(mType, CClsMathType);

    return mType;
}
