/******************************************************************************
 * $Id: gsl_blasctl.cpp 2017-05 $
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

#include "gsl_blasctl.hpp"

// Blas.
#include "gsl_blasvopctl.hpp"
#include "gsl_blasmvopctl.hpp"
#include "gsl_blasmmopctl.hpp"

/**
 * \brief Constructor.
 */
CGslBlasCtl::CGslBlasCtl()
{
    mVop = NULL;
    mMvop = NULL;
    mMmop = NULL;
}

/**
 * \brief Destructor.
 */
CGslBlasCtl::~CGslBlasCtl()
{
    if (mVop != NULL)
    {
        delete mVop;
    }

    if (mMvop != NULL)
    {
        delete mMvop;
    }

    if (mMmop != NULL)
    {
        delete mMmop;
    }
}

/**
 * \brief Initialize.
 */
UErrCodeT CGslBlasCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Vector operations.
 */
CGslBlasVopCtl *CGslBlasCtl::Vop()
{
    if (mVop == NULL)
    {
        mVop = new CGslBlasVopCtl;
        mVop->Init();
    }
    return mVop;
}

/**
 * \brief Matrix-Vector operations.
 */
CGslBlasMvopCtl *CGslBlasCtl::Mvop()
{
    if (mMvop == NULL)
    {
        mMvop = new CGslBlasMvopCtl;
        mMvop->Init();
    }

    return mMvop;
}

/**
 * \brief Matrix-Matrix operator.
 */
CGslBlasMmopCtl *CGslBlasCtl::Mmop()
{
    if (mMmop == NULL)
    {
        mMmop = new CGslBlasMmopCtl;
        mMmop->Init();
    }

    return mMmop;
}
