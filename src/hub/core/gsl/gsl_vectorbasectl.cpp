/******************************************************************************
 * $Id: gsl_vectorbasectl.cpp 2017-06 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Vector base controler implementation.
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

#include "gsl_vectorbasectl.hpp"

// Gsl Module.
#include "gsl_vector.h"

/**
 * \brief Constructor.
 */
CGslVectorBaseCtl::CGslVectorBaseCtl()
{
}

/**
 * \brief Destructor.
 */
CGslVectorBaseCtl::~CGslVectorBaseCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CGslVectorBaseCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Get value.
 *
 * @param aVal value.
 * @param aVtr vector.
 * @param aDim dimension.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGslVectorBaseCtl::Value(UFloatT *aVal, const GslVectorHT aVtr,
                                   const UIntT aDim)
{
    *aVal = gsl_vector_get((gsl_vector *) aVtr, aDim);

    return UErrFalse;
}

/**
 * \brief Set value.
 *
 * @param aVal value.
 * @param aVtr vector.
 * @param aDim dimension.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGslVectorBaseCtl::SetValue(const UFloatT aVal,
                                      const GslVectorHT aVtr,
                                      const UIntT aDim)
{
    gsl_vector_set((gsl_vector *) aVtr, aDim, aVal);

    return UErrFalse;
}

/**
 * \brief Get size of dimension.
 */
UErrCodeT CGslVectorBaseCtl::DimSize(UIntT *aSize, const GslVectorHT aVtr)
{
    *aSize = ((gsl_vector *)aVtr)->size;

    return UErrFalse;
}
