/******************************************************************************
 * $Id: gda_trrsttorsttype.cpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Translate raster to raster type implementation.
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

#include "gda_trrsttorsttype.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_typectl.hpp"
#include "gda_ogrsrstype.hpp"
#include "gda_utilsctl.hpp"
#include "gda_utilstr.hpp"
#include "gda_trrst.hpp"
#include "gda_trrstprocctl.hpp"

/**
 * \brief Constructor.
 */
GdaTrRstToRstT::GdaTrRstToRstT() : mLOpt(UContainerList)
{
    InitPointer();
    Init();
}

/**
 * \brief Constructor.
 */
GdaTrRstToRstT::GdaTrRstToRstT(const GdaFormatCodeT aFrmt,
                               const BCtnStringT *aOpt) : mLOpt(UContainerList)
{
    InitPointer();
    Init();
    SetAll(aFrmt, aOpt);
}

/**
 * \brief Destructor.
 */
GdaTrRstToRstT::~GdaTrRstToRstT()
{
    InitPointer();
    Clear();
}

/**
 * \brief Set all options.
 */
UErrCodeT GdaTrRstToRstT::SetAll(const GdaFormatCodeT aFrmt,
                                 const BCtnStringT *aOpt)
{
    mState = UStateOn;
    mLOpt.Clear();
    SetFrmt(aFrmt);
    SetOpt(aOpt);

    return UErrFalse;
}

/**
 * \brief Set Options.
 */
UErrCodeT GdaTrRstToRstT::SetOpt(const BCtnStringT *aOpt)
{
    mState = UStateOn;
    mLOpt.Add(aOpt);

    return UErrFalse;
}

/**
 * \brief Set format.
 */
UErrCodeT GdaTrRstToRstT::SetFrmt(const GdaFormatCodeT aFrmt)
{
    mState = UStateOn;

    mFrmt = aFrmt;

    UStringT frmt;
    mFrmtFlag = GdaFrmtFlagRst;
    frmt = "-of";
    mLOpt.Add(frmt);
    UStringT frmtV;
    mType->ToFormat(&frmtV, mFrmt);
    mLOpt.Add(frmtV);

    return UErrFalse;
}

/**
 * \brief Set spatial reference system.
 */
UErrCodeT GdaTrRstToRstT::SetSrs(const GdaOgrSrsT *aSrs)
{
    BMD_CLASS_NEW(mSrs, GdaOgrSrsT);
    *mSrs = *aSrs;

    return UErrFalse;
}

/**
 * \brief Get format.
 */
GdaFormatCodeT GdaTrRstToRstT::Frmt() const
{
    return mFrmt;
}

/**
 * \brief Get spatial reference system.
 */
GdaOgrSrsT *GdaTrRstToRstT::Srs() const
{
    return mSrs;
}

/**
 * \brief Get options.
 */
GdaTrRstProcHT GdaTrRstToRstT::Handle() const
{
    ((GdaTrRstToRstT *) this)->Save();

    return mProcH;
}

/***** Private A *****/

/**
 * \brief Initialize.
 */
UErrCodeT GdaTrRstToRstT::Init()
{
    CGdaUtilsCtl *utils = NULL;
    GDA_UTILS_CTL(utils);
    CGdaUtilsTr *tr = utils->Tr();
    CGdaTrRst *rst = tr->Rst();
    mProc = rst->ProcCtl();

    GDA_TYPE_CTL(mType);

    return UErrFalse;
}

/**
 * \brief Init pointer.
 */
UErrCodeT GdaTrRstToRstT::InitPointer()
{
    BMD_POINTER_INIT(mType);
    BMD_POINTER_INIT(mProc);
    BMD_POINTER_INIT(mSrs);

    return UErrFalse;
}

/**
 * \brief Save.
 */
UErrCodeT GdaTrRstToRstT::Save()
{
    if (mState == UStateOff)
    {
        return UErrFalse;
    }

    mState = UStateOff;
    mProc->New(&mProcH, &mLOpt, mFrmtFlag);

    return UErrFalse;
}

/**
 * \brief Clear.
 */
UErrCodeT GdaTrRstToRstT::Clear()
{
    mProc->Del(mProcH, mFrmtFlag);
    BMD_CLASS_DEL(mSrs);

    return UErrFalse;
}

/***** Private B *****/
