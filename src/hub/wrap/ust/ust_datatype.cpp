/******************************************************************************
 * $Id: ust_datatype.cpp 2018-05 $
 *
 * Project:  Universal struct library.
 * Purpose:  Universal data struct type.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-05 ~ 2018 Weiwei Huang
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

#include "ust_datatype.hpp"

/**
 * \brief Constructor.
 */
UDataT::UDataT()
{
}

/**
 * \brief Constructor.
 */
UDataT::UDataT(const UDataHT aDataH, const UDataTCodeT aCode)
{
    SetHandle(aDataH);
    SetCode(aCode);
}

/**
 * \brief Destructor.
 */
UDataT::~UDataT()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT UDataT::Init()
{
    return UErrFalse;
}

/**
 * \brief Set handle.
 */
UErrCodeT UDataT::SetHandle(UDataHT aDataH)
{
    mDataH = aDataH;

    return UErrFalse;
}

/**
 * \brief Set code.
 */
UErrCodeT UDataT::SetCode(UDataTCodeT aCode)
{
    mCode = aCode;

    return UErrFalse;
}

/**
 * \brief To float.
 */
UErrCodeT UDataT::ToS(UStringT *aStr)
{
    UFloatT val;
    ToF(&val);
    *aStr = val;

    return UErrFalse;
}

/**
 * \brief To float.
 */
UErrCodeT UDataT::ToF(UFloatT *aVal)
{
    UErrCodeT err = UErrTrue;

    if (mCode == UDataTFloat)
    {
        err = UErrFalse;
        *aVal = *((UFloatT *) mDataH);
    }
    else if (mCode == UDataTFloat32)
    {
        err = UErrFalse;
        *aVal = *((float *) mDataH);
    }
    else if (mCode == UDataTInt16)
    {
        *aVal = *((int16_t *) mDataH);
    }

    return err;
}

/***** Private A *****/
/***** Private B *****/
