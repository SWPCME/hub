/******************************************************************************
 * $Id: gda_banddatatype.cpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda band data type implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017, Weiwei Huang
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

#include "gda_banddatatype.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_typectl.hpp"
#include "gda_banddatactl.hpp"

/**
 * \brief Constructor.
 */
GdaBandDataT::GdaBandDataT()
{
    Init();
}

/**
 * \brief Constructor with set all value.
 */
GdaBandDataT::GdaBandDataT(const UDataTCodeT aType, const BMathCsC2dT *aBegin,
                           const BMathCsC2dT *aEnd)
{
    Init();
    SetAll(aType, aBegin, aEnd);
}

/**
 * \brief Destructor.
 */
GdaBandDataT::~GdaBandDataT()
{
    mData->Del(&mDataH);
    BMD_POINTER_INIT(mData);
}

/**
 * \brief Set all.
 */
UErrCodeT GdaBandDataT::SetAll(const UDataTCodeT aType, const BMathCsC2dT *aBegin,
                               const BMathCsC2dT *aEnd)
{
    SetType(aType);
    SetBegin(aBegin);
    SetEnd(aEnd);
    SetHanle();

    return UErrFalse;
}

/**
 * \brief Set type.
 */
UErrCodeT GdaBandDataT::SetType(const UDataTCodeT aType)
{
    mState = UStateOn;
    mType = aType;

    return UErrFalse;
}

/**
 * \brief Set begin of region.
 */
UErrCodeT GdaBandDataT::SetBegin(const BMathCsC2dT *aBegin)
{
    mState = UStateOn;
    mBegin = *aBegin;

    return UErrFalse;
}

/**
 * \brief Set end of region.
 */
UErrCodeT GdaBandDataT::SetEnd(const BMathCsC2dT *aEnd)
{
    mState = UStateOn;
    mEnd = *aEnd;

    return UErrFalse;
}

/**
 * \brief Get data code type.
 */
UDataTCodeT GdaBandDataT::Type()
{
    return mType;
}

/**
 * \brief Get begin of region.
 */
BMathCsC2dT *GdaBandDataT::Begin()
{
    return &mBegin;
}

/**
 * \brief Get end of region.
 */
BMathCsC2dT *GdaBandDataT::End()
{
    return &mEnd;
}

/**
 * \brief Get handle.
 */
UDataT GdaBandDataT::Handle()
{
    SetHanle();

    return mDataH;
}

/***** Private A *****/

/**
 * \brief Initialize.
 */
UErrCodeT GdaBandDataT::Init()
{
    BMD_POINTER_INIT(mData);
    BMD_POINTER_INIT(mDataH);
    CGdaTypeCtl *type = NULL;
    GDA_TYPE_CTL(type);
    mData = type->BandData();
    mType = UDataTNone;

    return UErrFalse;
}

/**
 * \brief Set handle.
 */
UErrCodeT GdaBandDataT::SetHanle()
{
    if (mState == UStateOff)
    {
        return UErrFalse;
    }

    mData->Del(&mDataH);
    mData->New(&mDataH, mType, &mBegin, &mEnd);
    mState = UStateOff;

    return UErrFalse;
}

/***** Private B *****/
