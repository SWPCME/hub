/******************************************************************************
 * $Id: gsl_ctl.cpp 2017-09 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Gsl controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-05 ~ 2017, Weiwei Huang
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
 ****************************************************************************/

#include "gsl_ctl.hpp"

// base
#include "base_macrodefn.hpp"
// gsl
#include "gsl_typectl.hpp"
#include "gsl_vectorctl.hpp"
#include "gsl_blasctl.hpp"
#include "gsl_sfctl.hpp"
#include "gsl_phyctl.hpp"

/**
 * \brief Constructor.
 */
CGslCtl::CGslCtl()
{
    InitPointer();
}

/**
 * \brief Destructor.
 */
CGslCtl::~CGslCtl()
{
    BMD_CLASS_DEL(mType);
    BMD_CLASS_DEL(mVector);
    BMD_CLASS_DEL(mBlas);
    BMD_CLASS_DEL(mSf);
    BMD_CLASS_DEL(mPhy);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGslCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Type.
 */
CGslTypeCtl *CGslCtl::Type()
{
    BMD_CLASS_NEW(mType, CGslTypeCtl);

    return mType;
}

/**
 * \brief Vector.
 */
CGslVectorCtl *CGslCtl::Vector()
{
    BMD_CLASS_NEW(mVector, CGslVectorCtl);

    return mVector;
}

/**
 * \brief Blas.
 */
CGslBlasCtl *CGslCtl::Blas()
{
    BMD_CLASS_NEW(mBlas, CGslBlasCtl);

    return mBlas;
}

/**
 * \brief Special Functions.
 */
CGslSfCtl *CGslCtl::Sf()
{
    BMD_CLASS_NEW(mSf, CGslSfCtl);

    return mSf;
}

/**
 * \brief Physical controler.
 */
CGslPhyCtl *CGslCtl::Phy()
{
    BMD_CLASS_NEW(mPhy, CGslPhyCtl);

    return mPhy;
}

/***** Private A *****/

/**
 * \brief Init pointer.
 */
UErrCodeT CGslCtl::InitPointer()
{
    BMD_POINTER_INIT(mType);
    BMD_POINTER_INIT(mVector);
    BMD_POINTER_INIT(mBlas);
    BMD_POINTER_INIT(mSf);
    BMD_POINTER_INIT(mPhy);

    return UErrFalse;
}

/***** Private B *****/
