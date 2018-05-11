/******************************************************************************
 * $Id: gda_ogrctrtype.cpp 2018-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Ogr coordinate transform type implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-05 ~ 2018, Weiwei Huang
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

#include "gda_ogrctrtype.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_typectl.hpp"
#include "gda_typeogr.hpp"
#include "gda_typeogrctr.hpp"

/**
 * \brief Constructor.
 */
GdaOgrCtrT::GdaOgrCtrT()
{
    Init();
}

/**
 * \brief Constructor.
 */
GdaOgrCtrT::GdaOgrCtrT(const GdaOgrSrsT *aSrc, const GdaOgrSrsT *aDst)
{
    Init();
    New(aSrc, aDst);
}

/**
 * \brief Destructor.
 */
GdaOgrCtrT::~GdaOgrCtrT()
{
    Destroy();
}

/**
 * \brief Transform.
 */
UErrCodeT GdaOgrCtrT::Tr(BMathCsC2dT *aDst, const BMathCsC2dT *aSrc)
{
    return mCtr->Tr(aDst, aSrc, mCtrH);
}

/***** Private A *****/

/**
 * \brief Initialize.
 */
UErrCodeT GdaOgrCtrT::Init()
{
    BMD_POINTER_INIT(mCtr);
    BMD_POINTER_INIT(mCtrH);
    CGdaTypeCtl *type = NULL;
    GDA_TYPE_CTL(type);
    CGdaTypeOgr *ogr = type->Ogr();
    mCtr = ogr->Ctr();

    return UErrFalse;
}

/**
 * \brief New.
 */
UErrCodeT GdaOgrCtrT::New(const GdaOgrSrsT *aSrc, const GdaOgrSrsT *aDst)
{
    return mCtr->New(&mCtrH, aSrc, aDst);
}

/**
 * \brief Destroy.
 */
UErrCodeT GdaOgrCtrT::Destroy()
{
    return mCtr->Destroy(mCtrH);
}

/***** Private B *****/
