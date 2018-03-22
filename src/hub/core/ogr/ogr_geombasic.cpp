/******************************************************************************
 * $Id: ogr_geombasic.cpp 2017-11 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr geometry basic implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-11 ~ 2017, Weiwei Huang
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

#include "ogr_geombasic.hpp"

// base
#include "base_ctl.hpp"
#include "base_macrodefn.hpp"
// core
#include "core_ctl.hpp"
// ogr
#include "ogr_ctl.hpp"
#include "ogr_typectl.hpp"

// GDAL/OGR
#include "ogr_api.h"

/**
 * \brief Constructor.
 */
COgrGeomBasic::COgrGeomBasic(OgrGeomHT aGeomH)
{
    BMD_POINTER_INIT(mGeomH);
    SetHandle(aGeomH);
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Destructor.
 */
COgrGeomBasic::~COgrGeomBasic()
{
    BMD_POINTER_INIT(mGeomH);
    BMD_POINTER_INIT(mType);
}

/**
 * \brief Initialize.
 */
UErrCodeT COgrGeomBasic::Init()
{
    OGR_TYPE_CTL(mType);

    return UErrFalse;
}

/**
 * \brief Get type.
 */
UErrCodeT COgrGeomBasic::Type(OgrGeomTCodeT *aCode)
{
    OGRwkbGeometryType code = OGR_G_GetGeometryType((OgrGeomHT) mGeomH);
    mType->ToGeomT(aCode, (OgrGeomTHT) &code);

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Set handle.
 */
UErrCodeT COgrGeomBasic::SetHandle(OgrGeomHT aGeomH)
{
    mGeomH = aGeomH;

    return UErrFalse;
}

/***** Private B *****/
