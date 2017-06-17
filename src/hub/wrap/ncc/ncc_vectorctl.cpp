/******************************************************************************
 * $Id: ncc_vectorctl.cpp 2017-06 $
 *
 * Project:  NCC (NCC: Numerical Computing Collection).
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

#include "ncc_vectorctl.hpp"

// Base.
#include "base_ctl.hpp"
// Core.
#include "core_ctl.hpp"
// Gsl.
#include "gsl_ctl.hpp"
#include "gsl_vectorctl.hpp"
#include "gsl_vectorbasectl.hpp"
#include "gsl_vectormemctl.hpp"
#include "gsl_vectoroperctl.hpp"

/**
 * \brief Constructor.
 */
CNccVectorCtl::CNccVectorCtl()
{
}

/**
 * \brief Destructor.
 */
CNccVectorCtl::~CNccVectorCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CNccVectorCtl::Init()
{
    CBaseCtl *baseCtl = CBaseCtl::Base();
    CCoreCtl *coreCtl = baseCtl->Core();
    CGslCtl *gslCtl = coreCtl->Gsl();
    CGslVectorCtl *vectorCtl = gslCtl->Vector();
    mBase = vectorCtl->Base();
    mMem = vectorCtl->Mem();
    mOper = vectorCtl->Oper();

    return UErrFalse;
}

/**
 * \brief Get dimension size.
 */
UErrCodeT CNccVectorCtl::DimSize(UIntT *aSize, NccVectorHT aVtrH)
{
    if (aVtrH == NULL)
    {
        *aSize = -1;
        return UErrTrue;
    }

    return mBase->DimSize(aSize, (GslVectorHT) aVtrH);
}

/**
 * \brief Set dimension size.
 */
UErrCodeT CNccVectorCtl::SetDimSize(const UIntT aSize, NccVectorHT *aVtrH)
{
    if (*aVtrH != NULL)
    {
        mMem->Free((GslVectorHT) *aVtrH);
    }

    return mMem->Alloc((GslVectorHT *) aVtrH, aSize);
}

/**
 * \brief Get dimension.
 */
UErrCodeT CNccVectorCtl::Value(UFloatT *aVal, NccVectorHT aVector, UIntT aDim)
{
    return mBase->Value(aVal, (GslVectorHT) aVector, aDim);
}

/**
 * \brief Set dimension.
 */
UErrCodeT CNccVectorCtl::SetValue(UFloatT aVal, NccVectorHT aVector,
                                  UIntT aDim)
{
    return mBase->SetValue(aVal, aVector, aDim);
}

/**
 * \brief Copy.
 */
UErrCodeT CNccVectorCtl::Cpy(NccVectorHT *aDest, const NccVectorHT aSrc)
{
    return mMem->Cpy(aDest, aSrc);
}

/**
 * \brief Multiplication.
 */
UErrCodeT CNccVectorCtl::Mul(NccVectorHT *aC, const NccVectorHT aA, const NccVectorHT aB)
{
    return mOper->Mul((GslVectorHT*) aC, (GslVectorHT) aA, (GslVectorHT) aB);
}

/**
 * \brief Free.
 */
UErrCodeT CNccVectorCtl::Free(NccVectorHT aVector)
{
    return mMem->Free((GslVectorHT) aVector);
}
