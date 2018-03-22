/******************************************************************************
 * $Id: ogr_geomsctl.cpp 2017-11 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr geometry set implementation.
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

#include "ogr_geomsctl.hpp"

// base
#include "base_macrodefn.hpp"

// ogr
#include "ogr_geomarctype.hpp"
#include "ogr_geomctl.hpp"

// GDAL/OGR
#include "ogr_api.h"

/**
 * \brief Constructor.
 */
COgrGeomsCtl::COgrGeomsCtl(OgrFeatureHT aFeatureH) : mLGeom(UContainerList)
{
    BMD_POINTER_INIT(mGeomsH);
    SetHandle(aFeatureH);
}

/**
 * \brief Destructor.
 */
COgrGeomsCtl::~COgrGeomsCtl()
{
    BMD_POINTER_INIT(mGeomsH);
}

/**
 * \brief Initialize.
 */
UErrCodeT COgrGeomsCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Create an empty geometry of desired type.
 *
 * This is lonely geometry, not belong to any feature.
 */
COgrGeomCtl *COgrGeomsCtl::Create(const OgrGeomTCodeT aCode)
{
    UFileOperCodeT oper = UFileOperCreate;

    return GeomCtl(oper, aCode);
}

/**
 * \brief Create arc.
 */
COgrGeomCtl *COgrGeomsCtl::CreateArc(const OgrGeomArcT *aArc)
{
    return GeomCtl(aArc);
}

/**
 * \brief Set geometry for this geometry set.
 */
UErrCodeT COgrGeomsCtl::Set(COgrGeomCtl *aGeom)
{
    OGR_F_SetGeometry((OGRFeatureH) mGeomsH, (OGRGeometryH) aGeom->Handle());

    return UErrFalse;
}

/**
 * \brief Load geometry from this geometry set.
 */
COgrGeomCtl *COgrGeomsCtl::Load()
{
    UFileOperCodeT oper = UFileOperLoad;

    return GeomCtl(oper);
}

/**
 * \brief Close geometry that specified.
 */
UErrCodeT COgrGeomsCtl::Close(COgrGeomCtl *aGeom)
{
    mLGeom.Del(aGeom);
    BMD_CLASS_DEL(aGeom);

    return UErrFalse;
}

/**
 * \brief Close all geometry that in this geometry set.
 */
UErrCodeT COgrGeomsCtl::CloseAll()
{
    LGeomItT *it = mLGeom.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        Close(it->Content());
    }

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Set handle.
 */
UErrCodeT COgrGeomsCtl::SetHandle(OgrFeatureHT aFeatureH)
{
    mGeomsH = (OgrGeomsHT) aFeatureH;

    return UErrFalse;
}

/**
 * \brief Geometry controler.
 */
COgrGeomCtl *COgrGeomsCtl::GeomCtl(const UFileOperCodeT aOper,
                                   const OgrGeomTCodeT aGeomT)
{
    COgrGeomCtl *geomCtl;
    BMD_POINTER_INIT(geomCtl);
    BMD_CLASS_NEW_A_3(geomCtl, COgrGeomCtl, aOper, aGeomT, mGeomsH);

    if (geomCtl != NULL)
    {
        mLGeom.Add(geomCtl);
    }

    return geomCtl;
}

/**
 * \brief Geometry controler.
 */
COgrGeomCtl *COgrGeomsCtl::GeomCtl(const OgrGeomArcT *aArc)
{
    COgrGeomCtl *geomCtl;
    BMD_POINTER_INIT(geomCtl);
    BMD_CLASS_NEW_A_2(geomCtl, COgrGeomCtl, aArc, mGeomsH);

    if (geomCtl != NULL)
    {
        mLGeom.Add(geomCtl);
    }

    return geomCtl;
}

/***** Private B *****/
