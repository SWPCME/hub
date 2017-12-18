/******************************************************************************
 * $Id: gda_trvtrtovtrtype.cpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Translate vector to vector type implementation.
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
 *****************************************************************************/

#include "gda_trvtrtorsttype.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_typectl.hpp"
#include "gda_trvtrprocctl.hpp"

/**
 * \brief Constructor.
 */
GdaTrVtrToRstT::GdaTrVtrToRstT() : mLOpt(UContainerList)
{
    Init();
}

/**
 * \brief Destructor.
 */
GdaTrVtrToRstT::~GdaTrVtrToRstT()
{
    BMD_POINTER_INIT(mGdaType);
    Clear();
}

/**
 * \brief Set all options.
 */
UErrCodeT GdaTrVtrToRstT::SetAll(const GdaFormatCodeT aFrmt,
                                 const BCtnStringT *aOpt)
{
    SetFrmt(aFrmt);
    mProc->New(&mProcH, aOpt, mFrmtFlag);
    mLOpt.Add(aOpt);

    return UErrFalse;
}

/**
 * \brief Set format.
 */
UErrCodeT GdaTrVtrToRstT::SetFrmt(const GdaFormatCodeT aFrmt)
{
    mFrmt = aFrmt;

    UStringT frmt;
    mFrmtFlag = GdaFrmtFlagRst;
    frmt = "-of ";
    UStringT frmtV;
    mGdaType->ToFormat(&frmtV, mFrmt);
    frmt += frmtV;

    // TODO: Change mLOpt from list to map.
    mLOpt.Add(frmt);

    return UErrFalse;
}

/**
 * \brief Get format.
 */
GdaFormatCodeT GdaTrVtrToRstT::Frmt() const
{
    return mFrmt;
}

/**
 * \brief Get options.
 */
GdaTrVtrProcHT GdaTrVtrToRstT::Handle() const
{
    return mProcH;
}

/***** Private A *****/

/**
 * \brief Initialize.
 */
UErrCodeT GdaTrVtrToRstT::Init()
{
    BMD_POINTER_INIT(mGdaType);
    GDA_TYPE_CTL(mGdaType);

    return UErrFalse;
}

/**
 * \brief Clear.
 */
UErrCodeT GdaTrVtrToRstT::Clear()
{
    mProc->Del(mProcH, mFrmtFlag);

    return UErrFalse;
}

/***** Private B *****/
