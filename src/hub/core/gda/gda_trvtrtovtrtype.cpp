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
#include "gda_ogrsrstype.hpp"
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
    mLOpt.Clear();
    SetFrmt(aFrmt);
    SetOpt(aOpt);

    return UErrFalse;
}

/**
 * \brief Set value with string.
 */
UErrCodeT GdaTrVtrToVtrT::SetOpt(const BCtnStringT *aOpt)
{
    mState = UStateOn;

    mLOpt.Add(aOpt);

    return UErrFalse;
}

/**
 * \brief Set format.
 */
UErrCodeT GdaTrVtrToVtrT::SetFrmt(const OgrFormatCodeT aFrmt)
{
    mState = UStateOn;

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
 * \brief Set spatial reference system.
 */
UErrCodeT GdaTrVtrToVtrT::SetSrs(const GdaOgrSrsT *aSrs)
{
    mState = UStateOn;
    BMD_CLASS_NEW(mSrs, GdaOgrSrsT);
    *mSrs = *aSrs;

    UStringT projCs;
    mSrs->ExportToWkt(&projCs);
    mLOpt.Add("-t_srs");
    mLOpt.Add(projCs);

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
 * \brief Get spatial reference system.
 */
GdaOgrSrsT *GdaTrVtrToVtrT::Srs() const
{
    return mSrs;
}

/**
 * \brief Get options.
 */
GdaTrVtrProcHT GdaTrVtrToVtrT::Handle() const
{
    ((GdaTrVtrToVtrT *) this)->Save();

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
    BMD_POINTER_INIT(mSrs);

    return UErrFalse;
}

/**
 * \brief Save.
 */
UErrCodeT GdaTrVtrToVtrT::Save()
{
    if (mState == UStateOff)
    {
        return UErrTrue;
    }

    mState = UStateOff;
    mProc->New(&mProcH, &mLOpt, mFrmtFlag);
    mLOpt.Clear();

    return UErrFalse;
}

/**
 * \brief Clear.
 */
UErrCodeT GdaTrVtrToVtrT::Clear()
{
    mProc->Del(mProcH, mFrmtFlag);
    BMD_CLASS_DEL(mSrs);

    return UErrFalse;
}

/***** Private B *****/
