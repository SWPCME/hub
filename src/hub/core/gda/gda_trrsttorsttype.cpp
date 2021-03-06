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
#include "base_stringdefn.hpp"
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
    Clear();
    InitPointer();
}

/**
 * \brief Set all options.
 *
 * It will reset all options before you setting.
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
    mState = UStateOn;

    BMD_CLASS_NEW(mSrs, GdaOgrSrsT);
    *mSrs = *aSrs;

    UStringT srs("-a_srs");
    mLOpt.Add(srs);

    UStringT wkt;
    mSrs->ExportToWkt(&wkt);
    mLOpt.Add(wkt);

    return UErrFalse;
}

/**
 * \brief Set subwindow for source. 
 *
 * Selects a subwindow from the source image for copying based on pixel/line
 * location.
 */
UErrCodeT GdaTrRstToRstT::SetSrcWin(const BMathCsC2dT *aOff,
                                    const BMathCsC2dT *aSize)
{
    mState = UStateOn;

    UStringT srcWin("-srcwin");
    mLOpt.Add(srcWin);

    UStringT offX(aOff->X());
    mLOpt.Add(offX);
    UStringT offY(aOff->Y());
    mLOpt.Add(offY);

    UStringT sizeX(aSize->X());
    mLOpt.Add(sizeX);
    UStringT sizeY(aSize->Y());
    mLOpt.Add(sizeY);
    
    return UErrFalse;
}

/**
 * \brief Set number of band.
 */
UErrCodeT GdaTrRstToRstT::SetBand(const BCtnIntT *aNumS)
{
    mState = UStateOn;

    UStringT band("-b");
    BItIntT *it = aNumS->Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        UStringT num = it->Content();
        mLOpt.Add(band);
        mLOpt.Add(num);
    }

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
    mFrmtFlag = GdaFrmtFlagRst;

    return UErrFalse;
}

/**
 * \brief Init pointer.
 */
UErrCodeT GdaTrRstToRstT::InitPointer()
{
    BMD_POINTER_INIT(mType);
    BMD_POINTER_INIT(mProc);
    BMD_POINTER_INIT(mProcH);
    BMD_POINTER_INIT(mSrs);

    return UErrFalse;
}

/**
 * \brief Save and reset all options.
 */
UErrCodeT GdaTrRstToRstT::Save()
{
    if (mState == UStateOff)
    {
        return UErrFalse;
    }

    mState = UStateOff;
    mProc->Del(mProcH, mFrmtFlag);
    mProc->New(&mProcH, &mLOpt, mFrmtFlag);
    mLOpt.Clear();

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
