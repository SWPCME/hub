/******************************************************************************
 * $Id: ncc_vectortype.cpp 2017-06 $
 *
 * Project:  NCC (NCC: Numerical Computing Collection).
 * Purpose:  Vector type implementation.
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

#include "ncc_vectortype.hpp"

// Base.
#include "base_ctl.hpp"
// Wrap.
#include "wrap_ctl.hpp"
// Ncc.
#include "ncc_ctl.hpp"
#include "ncc_vectorctl.hpp"

/**
 * \brief Constructor.
 */
NccVectorT::NccVectorT()
{
    mVector = NULL;
    mVtrHandle = NULL;

    Init();
}

/**
 * \brief Destructor.
 */
NccVectorT::~NccVectorT()
{
    Free();
}

/**
 * \brief Handle.
 */
NccVectorHT NccVectorT::Handle() const
{
    return mVtrHandle;
}

/**
 * \brief Set handle.
 */
UErrCodeT NccVectorT::SetHandle(NccVectorHT aHandle)
{
    mVtrHandle = aHandle;

    return UErrFalse;
}

/**
 * \brief Get size of dimension.
 *
 * @param aSize Size of dimension.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT NccVectorT::DimSize(UIntT *aSize)
{
    return mVector->DimSize(aSize, mVector);
}

/**
 * \brief Set size of dimension.
 *
 * @param aSize Size of dimension.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT NccVectorT::SetDimSize(UIntT aSize)
{
    if (aSize < 0)
    {
        return UErrTrue;
    }

    return mVector->SetDimSize(aSize, &mVtrHandle);
}

/**
 * \brief Get value by dimension.
 *
 * @param aVal Value.
 * @param aDim Dimension.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT NccVectorT::Value(UFloatT *aVal, UIntT aDim)
{
    return mVector->Value(aVal, mVtrHandle, aDim);
}

/**
 * \brief Set value by dimension.
 *
 * @param aVal Value.
 * @param aDim Dimension.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT NccVectorT::SetValue(UFloatT aVal, UIntT aDim)
{
    return mVector->SetValue(aVal, mVtrHandle, aDim);
}

/**
 * \brief Dot.
 */
UErrCodeT NccVectorT::Dot(UFloatT *aResult, const NccVectorT *aVector)
{
    NccVectorHT handle = aVector->Handle();

    return mVector->Dot(aResult, mVtrHandle, handle);
}

/**
 * \brief Multiplication.
 */
NccVectorT NccVectorT::operator *(const NccVectorT &aVector)
{
    NccVectorHT bH = aVector.Handle();
    NccVectorT c;
    NccVectorHT cH = aVector.Handle();
    mVector->Mul(&cH, mVtrHandle, bH);
    c.SetHandle(cH);

    return c;
}

/**
 * \brief Assign.
 */
UErrCodeT NccVectorT::operator =(const NccVectorT &aVector)
{
    NccVectorHT srcH = aVector.Handle();

    return mVector->Cpy(&mVtrHandle, srcH);
}

/***** Private A *****/

/**
 * \brief Initialize.
 */
UErrCodeT NccVectorT::Init()
{
    CBaseCtl *baseCtl = CBaseCtl::Base();
    CWrapCtl *wrapCtl = baseCtl->Wrap();
    CNccCtl *nccCtl = wrapCtl->Ncc();
    mVector = nccCtl->Vector();

    return UErrFalse;
}

/**
 * \brief Free.
 */
UErrCodeT NccVectorT::Free()
{
    return mVector->Free(mVtrHandle);
}

/***** Private B *****/
