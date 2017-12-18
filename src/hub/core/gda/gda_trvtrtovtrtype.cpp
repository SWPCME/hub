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

#include "gda_trvtrtovtrtype.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_utilsctl.hpp"
#include "gda_utilstr.hpp"
#include "gda_trvtr.hpp"
#include "gda_trvtrprocctl.hpp"
// ogr
#include "ogr_ctl.hpp"
#include "ogr_typectl.hpp"

/**
 * \brief Constructor.
 */
GdaTrVtrToVtrT::GdaTrVtrToVtrT() : mLOpt(UContainerList)
{
    InitPointer();
    Init();
}

/**
 * \brief Destructor.
 */
GdaTrVtrToVtrT::~GdaTrVtrToVtrT()
{
    InitPointer();
    Clear();
}

/**
 * \brief Set all options.
 */
UErrCodeT GdaTrVtrToVtrT::SetAll(const OgrFormatCodeT aFrmt,
                                 const BCtnStringT *aOpt)
{
    SetFrmt(aFrmt);
    mLOpt.Add(aOpt);
    mProc->New(&mProcH, &mLOpt, mFrmtFlag);

    return UErrFalse;
}

/**
 * \brief Set format.
 */
UErrCodeT GdaTrVtrToVtrT::SetFrmt(const OgrFormatCodeT aFrmt)
{
    mFrmt = aFrmt;

    UStringT frmt;
    mFrmtFlag = GdaFrmtFlagVtr;
    UStringT frmtV;
    mOgrType->ToFormat(&frmtV, mFrmt);

    // TODO: Change mLOpt from list to map.
    mLOpt.Add("-f");
    mLOpt.Add(frmtV);

    return UErrFalse;
}

/**
 * \brief Get format.
 */
OgrFormatCodeT GdaTrVtrToVtrT::Frmt() const
{
    return mFrmt;
}

/**
 * \brief Get options.
 */
GdaTrVtrProcHT GdaTrVtrToVtrT::Handle() const
{
    return mProcH;
}

/***** Private A *****/

/**
 * \brief Initialize.
 */
UErrCodeT GdaTrVtrToVtrT::Init()
{
    CGdaUtilsCtl *utils = NULL;
    GDA_UTILS_CTL(utils);
    CGdaUtilsTr *tr = utils->Tr();
    CGdaTrVtr *vtr = tr->Vtr();
    mProc = vtr->ProcCtl();

    OGR_TYPE_CTL(mOgrType);

    return UErrFalse;
}

/**
 * \brief Init pointer.
 */
UErrCodeT GdaTrVtrToVtrT::InitPointer()
{
    BMD_POINTER_INIT(mOgrType);
    BMD_POINTER_INIT(mProc);

    return UErrFalse;
}

/**
 * \brief Clear.
 */
UErrCodeT GdaTrVtrToVtrT::Clear()
{
    mProc->Del(mProcH, mFrmtFlag);

    return UErrFalse;
}

/***** Private B *****/
