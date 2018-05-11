/******************************************************************************
 * $Id: gda_typeogr.cpp 2018-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda type ogr controler implementation.
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
 ****************************************************************************/

#include "gda_typeogr.hpp"

// gda
#include "gda_typeogrctr.hpp"

/**
 * \brief Constructor.
 */
CGdaTypeOgr::CGdaTypeOgr()
{
    BMD_POINTER_INIT(mCtr);
}

/**
 * \brief Destructor.
 */
CGdaTypeOgr::~CGdaTypeOgr()
{
    BMD_CLASS_DEL(mCtr);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaTypeOgr::Init()
{
    return UErrFalse;
}

/**
 * \brief Coordinate transform.
 */
CGdaTypeOgrCtr *CGdaTypeOgr::Ctr()
{
    BMD_CLASS_NEW(mCtr, CGdaTypeOgrCtr);

    return mCtr;
}
