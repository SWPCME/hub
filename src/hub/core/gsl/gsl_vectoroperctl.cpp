/******************************************************************************
 * $Id: gsl_vectoroperctl.hpp 2017-06 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Vector operator controler implementation.
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

#include "gsl_vectoroperctl.hpp"

// GSL Module.
#include "gsl_vector.h"

// Base.
#include "base_ctl.hpp"
// Core.
#include "core_ctl.hpp"
#include "gsl_ctl.hpp"
#include "gsl_vectorctl.hpp"
#include "gsl_vectormemctl.hpp"

/**
 * \brief Constructor.
 */
CGslVectorOperCtl::CGslVectorOperCtl()
{
    mMem = NULL;
}

/**
 * \brief Destructor.
 */
CGslVectorOperCtl::~CGslVectorOperCtl()
{  
}

/**
 * \brief Initialize.
 */
UErrCodeT CGslVectorOperCtl::Init()
{
    if (mMem == NULL)
    {
        CBaseCtl *baseCtl = CBaseCtl::Base();
        CCoreCtl *coreCtl = baseCtl->Core();
        CGslCtl *gslCtl = coreCtl->Gsl();
        CGslVectorCtl *vectorCtl = gslCtl->Vector();
        mMem = vectorCtl->Mem();
    }

    return UErrFalse;
}

/**
 * \brief Multiplication.
 */
UErrCodeT CGslVectorOperCtl::Mul(GslVectorHT *aC, const GslVectorHT aA,
                                 const GslVectorHT aB)
{
    mMem->Cpy(aC, aA);
    gsl_vector_mul((gsl_vector *) *aC, (gsl_vector *) aB);

    return UErrFalse;
}
