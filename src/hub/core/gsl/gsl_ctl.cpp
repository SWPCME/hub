/******************************************************************************
 * $Id: gsl_ctl.cpp 2017-05 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Gsl controler implementation.
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

#include "gsl_ctl.hpp"

// Gsl.
#include "gsl_typectl.hpp"
#include "gsl_vectorctl.hpp"

/**
 * \brief Constructor.
 */
CGslCtl::CGslCtl()
{
    mType = new CGslTypeCtl;
}

/**
 * \brief Destructor.
 */
CGslCtl::~CGslCtl()
{
    delete mType;
}

/**
 * \brief Initialize.
 */
UErrCodeT CGslCtl::Init()
{
    mType->Init();

    return UErrFalse;
}

/**
 * \brief Type.
 */
CGslTypeCtl *CGslCtl::Type()
{
    return mType;
}

/**
 * \brief Vector.
 */
CGslVectorCtl *CGslCtl::Vector()
{
    if (mVector == NULL)
    {
        mVector = new CGslVectorCtl;
        mVector->Init();
    }

    return mVector;
}

/***** Private A *****/

/***** Private B *****/
