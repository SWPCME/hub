/******************************************************************************
 * $Id: gsl_legendreassoc.cpp 2017-09 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Legendre associated controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-09 ~ 2017, Weiwei Huang
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

#include "gsl_legendreassoc.hpp"

// base
#include "base_macrodefn.hpp"
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// gsl
#include "gsl_ctl.hpp"
#include "gsl_typectl.hpp"
// GSL
#include "gsl_sf_legendre.h"

#define GSL_LEGENDREASSOC_CODE(aCode) \
    const gsl_sf_legendre_t aCode = *((const gsl_sf_legendre_t *) mCodeH);

/**
 * \brief Constructor.
 */
CGslLegendreAssoc::CGslLegendreAssoc(GslSfLegendreAssocCodeT aCode)
{
    InitPointer();
    InitCode(aCode);
}

/**
 * \brief Destructor.
 */
CGslLegendreAssoc::~CGslLegendreAssoc()
{
    BMD_POINTER_DELH(mCodeH, gsl_sf_legendre_t);
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGslLegendreAssoc::Init()
{
    GSL_TYPE_CTL(mType);

    return UErrFalse;
}

/**
 * \brief Array.
 *
 * @param aResultArray This size of array from "ArrayN(aLMax)", 
 *        e.g. UFloatT aResultArray[ArrayN(aLMax)].
 * @param aLMax Max value of l.
 * @param aX Available of x.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGslLegendreAssoc::Array(UFloatT *aResultArray, const UIntT aLMax,
                                   const UFloatT aX)
{
    GSL_LEGENDREASSOC_CODE(norm);
    gsl_sf_legendre_array(norm, aLMax, aX, aResultArray);

    return UErrFalse;
}

/**
 * \brief Array n.
 *
 * @param aN The n return by this.
 * @param aLMax The max value of l.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGslLegendreAssoc::ArrayN(UIntT *aN, const size_t aLMax)
{
    *aN = gsl_sf_legendre_array_n(aLMax);

    return UErrFalse;
}

/**
 * \brief Array index.
 *
 * @param aIndex The index that return by this.
 * @param aL The variable of l.
 * @param aM The variable of m.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGslLegendreAssoc::ArrayIndex(UIntT *aIndex, const size_t aL, const size_t aM)
{
    *aIndex = gsl_sf_legendre_array_index(aL, aM);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Init pointer.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGslLegendreAssoc::InitPointer()
{
    BMD_POINTER_INIT(mCodeH);
    BMD_POINTER_INIT(mType);

    return UErrFalse;
}

/**
 * \brief Init code.
 *
 * @param aCode, code of associated legendre polynomials.
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGslLegendreAssoc::InitCode(GslSfLegendreAssocCodeT aCode)
{
    BMD_POINTER_NEWH(mCodeH, gsl_sf_legendre_t, GslSfLegendreAssocCodeHT);
    mType->ToSfLegendreAssocCode((gsl_sf_legendre_t *)mCodeH, aCode);

    return UErrFalse;
}

/***** Private B *****/
