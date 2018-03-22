/******************************************************************************
 * $Id: gsl_vectorctl.cpp 2017-05 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Vector controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017, Weiwei Huang
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

#include "gsl_vectorctl.hpp"

// Gsl Module.
#include "gsl_vector.h"

// Base
#include "base_ctl.hpp"
// Core.
#include "core_ctl.hpp"
// Gsl.
#include "gsl_ctl.hpp"
#include "gsl_vectorbasectl.hpp"
#include "gsl_vectormemctl.hpp"
#include "gsl_vectoroperctl.hpp"

// Wrap.
// Ust.
#include "ust_stringtype.hpp"

/**
 * \brief Constructor.
 */
CGslVectorCtl::CGslVectorCtl()
{
    mBase = NULL;
    mMem = NULL;
    mOper = NULL;
}

/**
 * \brief Destructor.
 */
CGslVectorCtl::~CGslVectorCtl()
{
    if (mBase != NULL)
    {
        delete mBase;
    }

    if (mMem != NULL)
    {
        delete mMem;
    }

    if (mOper != NULL)
    {
        delete mOper;
    }
}

/**
 * \brief Initialize.
 */
UErrCodeT CGslVectorCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Base controler.
 */
CGslVectorBaseCtl *CGslVectorCtl::Base()
{
    if (mBase == NULL)
    {
        mBase = new CGslVectorBaseCtl;
        mBase->Init();
    }

    return mBase;
}

/**
 * \brief Memory controler.
 */
CGslVectorMemCtl *CGslVectorCtl::Mem()
{
    if (mMem == NULL)
    {
        mMem = new CGslVectorMemCtl;
        mMem->Init();
    }

    return mMem;
}

/**
 * \brief Oper controler.
 */
CGslVectorOperCtl *CGslVectorCtl::Oper()
{
    if (mOper == NULL)
    {
        mOper = new CGslVectorOperCtl;
        mOper->Init();
    }

    return mOper;
}

/***** Private A *****/

/***** Private B *****/
