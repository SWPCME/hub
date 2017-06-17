/******************************************************************************
 * $Id: gsl_vectormemctl.hpp 2017-06 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Vector memory controler implementation.
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

#include "gsl_vectormemctl.hpp"

// GSL Module.
#include "gsl_vector.h"

// Base.
#include "base_ctl.hpp"
// Core.
#include "core_ctl.hpp"
// Gsl.
#include "gsl_ctl.hpp"

/**
 * \brief Constructor.
 */
CGslVectorMemCtl::CGslVectorMemCtl()
{
}

/**
 * \brief Destructor.
 */
CGslVectorMemCtl::~CGslVectorMemCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CGslVectorMemCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Allocate.
 */
UErrCodeT CGslVectorMemCtl::Alloc(GslVectorHT *aVector, const UIntT aSize)
{
    *aVector = (gsl_vector *) gsl_vector_alloc(aSize);

    return UErrFalse;
}

/**
 * \brief Copy.
 */
UErrCodeT CGslVectorMemCtl::Cpy(GslVectorHT *aDest, const GslVectorHT aSrc)
{
    Alloc(aDest, ((gsl_vector *) aSrc)->size);
    gsl_vector_memcpy((gsl_vector *) *aDest, (gsl_vector *) aSrc);

    return UErrFalse;
}

/**
 * \brief Free.
 */
UErrCodeT CGslVectorMemCtl::Free(GslVectorHT aVector)
{
    gsl_vector_free((gsl_vector *) aVector);

    return UErrFalse;
}
