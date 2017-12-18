/******************************************************************************
 * $Id: gda_demproctype.cpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Dem(digital elevation model) processing type implementation.
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

#include "gda_demproctype.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_utilsctl.hpp"
#include "gda_utilsdem.hpp"
#include "gda_demprocctl.hpp"

/**
 * \brief Constructor.
 */
GdaDemProcT::GdaDemProcT() : mLOpt(UContainerList)
{
    BMD_POINTER_INIT(mProc);
    BMD_POINTER_INIT(mProcH);
    Init();
}

/**
 * \brief Destructor.
 */
GdaDemProcT::~GdaDemProcT()
{
    Clear();
    BMD_POINTER_INIT(mProc);
    BMD_POINTER_INIT(mProcH);
}

/**
 * \brief Set all options.
 */
UErrCodeT GdaDemProcT::SetAll(const GdaDemProcFrmtCodeT aFrmt,
                              const BCtnStringT *aOpt)
{
    SetFrmt(aFrmt);
    mProc->New(&mProcH, aOpt);

    return UErrFalse;
}

/**
 * \brief Set format.
 */
UErrCodeT GdaDemProcT::SetFrmt(const GdaDemProcFrmtCodeT aFrmt)
{
    mFrmt = aFrmt;

    return UErrFalse;
}

/**
 * \brief Get format.
 */
GdaDemProcFrmtCodeT GdaDemProcT::Frmt() const
{
    return mFrmt;
}

/**
 * \brief Get processing options handle.
 */
GdaDemProcHT GdaDemProcT::Handle() const
{
    return mProcH;
}

/***** Private A *****/

/**
 * \brief Initialize.
 */
UErrCodeT GdaDemProcT::Init()
{
    CGdaUtilsCtl *utilsCtl = NULL;
    GDA_UTILS_CTL(utilsCtl);
    CGdaUtilsDem *utilsDem = utilsCtl->Dem();
    mProc = utilsDem->ProcCtl();

    return UErrFalse;
}

/**
 * \brief Clear.
 */
UErrCodeT GdaDemProcT::Clear()
{
    mProc->Del(mProcH);

    return UErrFalse;
}

/***** Private B *****/
