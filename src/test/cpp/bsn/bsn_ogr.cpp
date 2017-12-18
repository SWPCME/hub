/******************************************************************************
 * $Id: bsn_ogr.cpp 2017-07 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test ogr control api implemention.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-06 ~ 2017, Weiwei Huang
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

#include "bsn_ogr.hpp"

// base
#include "base_macrodefn.hpp"
// ogr
#include "ogr_ctl.hpp"
#include "ogr_driverctl.hpp"
#include "ogr_datasrcctl.hpp"
#include "ogr_layerctl.hpp"
#include "ogr_featuresctl.hpp"
#include "ogr_featurectl.hpp"
#include "ogr_fieldctl.hpp"
#include "ogr_geomsctl.hpp"
#include "ogr_geomctl.hpp"
#include "ogr_geombasic.hpp"
#include "ogr_geomvertex.hpp"
// ust
#include "ust_containertype.hpp"

/**
 * \brief Constructor.
 */
CBsnOgr::CBsnOgr()
{
    BMD_POINTER_INIT(mOgr);
}

/**
 * \brief Destructor.
 */
CBsnOgr::~CBsnOgr()
{
    BMD_POINTER_INIT(mOgr);
}

/**
 * \brief Initialize.
 */
UErrCodeT CBsnOgr::Init()
{
    BMD_MODULE(mOgr, COgrCtl, HubMOgr);

    return UErrFalse;
}

/**
 * \brief Test.
 */
UErrCodeT CBsnOgr::Test()
{
    mOgr->RegisterAll();
    // TestRead();
    TestWrite();
    // mOgr->DeregisterAll();

    return UErrFalse;
}

/***** Private A *****/

UErrCodeT CBsnOgr::TestRead()
{
    UStringT driverName = OGR_F_SHP;
    COgrDriverCtl *driverCtl = mOgr->Driver(&driverName);
    UStringT file = "/home/swpcme/file/source/swpcme/hub/data/core/ogr/t_write";
    COgrDatasrcCtl *dsCtl = driverCtl->Load(&file);
    UIntT layerId = 0;
    COgrLayerCtl *layerCtl = dsCtl->Load(layerId);
    UStringT name = layerCtl->Name();
    name.ToConsole();
    COgrFeaturesCtl *featuresCtl = layerCtl->Features();
    UIntT featureId = 0;
    COgrFeatureCtl *featureCtl = featuresCtl->Load(featureId);
    // field
    COgrFieldCtl *fieldCtl = featureCtl->Field();
    UStringT value;
    UIntT fieldId = 0;
    fieldCtl->Value(&value, fieldId);
    value.ToConsole();
    // geomerty
    COgrGeomsCtl *geomsCtl = featureCtl->Geoms();
    COgrGeomCtl *geomCtl = geomsCtl->Load();
    COgrGeomBasic *geomBasic = geomCtl->Basic();
    OgrGeomTCodeT geomT = OgrGeomTUnknown;
    geomBasic->Type(&geomT);
    UStringT strGeomT = geomT;
    strGeomT.ToConsole();
    COgrGeomVertex *geomVertex = geomCtl->Vertex();
    UIntT ptCount;
    geomVertex->PointCount(&ptCount);
    UStringT strPtCount = ptCount;
    strPtCount.ToConsole();
    BMathCsC2dT point;
    geomVertex->Point2D(&point, 1);
    UFloatT y = 0.0;
    geomVertex->Y(&y, 1);

    return UErrFalse;
}

UErrCodeT CBsnOgr::TestWrite()
{
    OgrFormatCodeT formatCode = OgrFormatShp;
    COgrDriverCtl *drCtl = mOgr->Driver(formatCode);
    UStringT file = "/home/swpcme/file/source/swpcme/hub/data/core/ogr/t_write";
    COgrDatasrcCtl *dsCtl = drCtl->Create(&file);
    UStringT layerName = "linestring";
    COgrLayerCtl *layerCtl = dsCtl->Create(&layerName);
    COgrFeaturesCtl *featuresCtl = layerCtl->Features();
    COgrFeatureCtl *featureCtl = featuresCtl->Create();
    COgrGeomsCtl *geomsCtl = featureCtl->Geoms();
    OgrGeomTCodeT geomT = OgrGeomTLineString;
    COgrGeomCtl *geomCtl = geomsCtl->Create(geomT);
    COgrGeomVertex *geomVertex = geomCtl->Vertex();
    BMathCsC2dT point(131, 47);
    geomVertex->AddPoint2D(&point);
    point.SetAll(4.5, 4.7);
    geomVertex->AddPoint2D(&point);
    geomsCtl->Set(geomCtl);
    featuresCtl->Add(featureCtl);
    COgrFeatureCtl *feature2 = featuresCtl->Create();
    COgrGeomsCtl *geoms2 = feature2->Geoms();
    COgrGeomCtl *geom2 = geoms2->Create(geomT);
    COgrGeomVertex *geomV2 = geom2->Vertex();
    point.SetAll(433, 572);
    geomV2->AddPoint2D(&point);
    point.SetAll(333, 123);
    geomV2->AddPoint2D(&point);
    geoms2->Set(geom2);
    featuresCtl->Add(feature2);
    dsCtl->CloseAll();

    return UErrFalse;
}

/***** Private B *****/
