/******************************************************************************
 * $Id: gda_utilstr.cpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Utils translate implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-07 ~ 2017, Weiwei Huang
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

#include "gda_utilstr.hpp"
#include "gda_trvtr.hpp"
#include "gda_trrst.hpp"

/**
 * \brief Constructor.
 */
CGdaUtilsTr::CGdaUtilsTr()
{
    BMD_POINTER_INIT(mVtr);
    BMD_POINTER_INIT(mRst);
}

/**
 * \brief Destructor.
 */
CGdaUtilsTr::~CGdaUtilsTr()
{
    BMD_CLASS_DEL(mVtr);
    BMD_CLASS_DEL(mRst);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaUtilsTr::Init()
{
    return UErrFalse;
}

/**
 * \brief Vector.
 */
CGdaTrVtr *CGdaUtilsTr::Vtr()
{
    BMD_CLASS_NEW(mVtr, CGdaTrVtr);

    return mVtr;
}

/**
 * \brief Raster.
 */
CGdaTrRst *CGdaUtilsTr::Rst()
{
    BMD_CLASS_NEW(mRst, CGdaTrRst);

    return mRst;
}
