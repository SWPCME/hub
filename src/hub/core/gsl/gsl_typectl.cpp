/******************************************************************************
 * $Id: gsl_typectl.cpp 2017-09 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Type controler implementation.
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

#include "gsl_typectl.hpp"

// Gsl Module.
#include "gsl_vector.h"

/**
 * \brief Constructor.
 */
CGslTypeCtl::CGslTypeCtl()
{
}

/**
 * \brief Destructor.
 */

CGslTypeCtl::~CGslTypeCtl()
{
}

/**
 * \brief Initialize.
 */

UErrCodeT CGslTypeCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief To vector.
 */
UErrCodeT CGslTypeCtl::ToVector(GslVectorHT aDest, const GslVectorT *aSrc)
{
    gsl_vector *dest = (gsl_vector *) aDest;
    dest->size = aSrc->size;
    dest->stride = aSrc->stride;
    dest->data = aSrc->data;
    ToBlock((GslBlockHT) dest->block, aSrc->block);
    dest->owner = aSrc->owner;

    return UErrFalse;
}

/**
 * \brief To vector.
 */
UErrCodeT CGslTypeCtl::ToVector(GslVectorT *aDest, const GslVectorHT aSrc)
{
    gsl_vector *src = (gsl_vector *) aSrc;
    aDest->size = src->size;
    aDest->stride = src->stride;
    aDest->data = src->data;
    ToBlock(aDest->block, (GslBlockHT) src->block);
    aDest->owner = src->owner;

    return UErrFalse;
}

/**
 * \brief To Legendre.
 */
UErrCodeT CGslTypeCtl::ToSfLegendreAssocCode(gsl_sf_legendre_t *aDst,
                                             const GslSfLegendreAssocCodeT aSrc)
{
    switch (aSrc)
    {
    case GslSfLegendreAssocUnstd:
        *aDst = GSL_SF_LEGENDRE_NONE;
        break;
    case GslSfLegendreAssocSchmidt:
        *aDst = GSL_SF_LEGENDRE_SCHMIDT;
        break;
    case GslSfLegendreAssocSpharm:
        *aDst = GSL_SF_LEGENDRE_SPHARM;
        break;
    case GslSfLegendreAssocFull:
        *aDst = GSL_SF_LEGENDRE_FULL;
        break;
    default:
        break;
    }

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief To block.
 */
UErrCodeT CGslTypeCtl::ToBlock(GslBlockHT aDest, const GslBlockT *aSrc)
{
    gsl_block_struct *dest = (gsl_block_struct *) aDest;
    dest->size = aSrc->size;
    dest->data = aSrc->data;

    return UErrFalse;
}

/**
 * \brief To block.
 */
UErrCodeT CGslTypeCtl::ToBlock(GslBlockT *aDest, const GslBlockHT aSrc)
{
    gsl_block_struct *src = (gsl_block_struct *) aSrc;
    aDest->size = src->size;
    aDest->data = src->data;

    return UErrFalse;
}

/***** Private B *****/
