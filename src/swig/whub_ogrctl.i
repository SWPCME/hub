/******************************************************************************
 * $Id: whub_ogrctl.i 2017-09 $
 *
 * Project:  whub (Wrap hub).
 * Purpose:  Api for ogr.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-09 ~ 2017, Weiwei Huang
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

%module "WHubOgr"
%{
#include "ogr/ogr_ctl.hpp"
#include "ogr/ogr_driverctl.hpp"
#include "ogr/ogr_datasrcctl.hpp"
#include "ogr/ogr_layerctl.hpp"
#include "ogr/ogr_featuredefn.hpp"
#include "ogr/ogr_featuresctl.hpp"
#include "ogr/ogr_featurectl.hpp"
#include "ogr/ogr_fieldctl.hpp"
#include "ogr/ogr_geomsctl.hpp"
#include "ogr/ogr_geomctl.hpp"
#include "ogr/ogr_geombasic.hpp"
#include "ogr/ogr_geomvertex.hpp"
%}

%pragma(java) jniclassimports=%{
import whub.*;
%}

typedef enum
{
    OgrFormatTab    = 1,
    OgrFormatShp    = 2,
    OgrFormatCsv    = 3,
    OgrFormatXls    = 4,
    OgrFormatXlsx   = 5,
    OgrFormatSqlite = 6,
    OgrFormatJson   = 7,
} OgrFormatCodeT;

typedef enum
{
    OgrGeomTUnknown    = 0,

    // Single.
    OgrGeomTPoint      = 1,
    OgrGeomTLineString = 2,
    OgrGeomTPolygon    = 3,

    // Multi
    OgrGeomTMPoint      = 11,
    OgrGeomTMLineString = 21,
    OgrGeomTMPloygon    = 22,
} OgrGeomTCodeT;

class COgrCtl
{
  public:
    COgrCtl(CHubModuleCtl *aModule);
    ~COgrCtl();

    // Init and cleanup all.
    UErrCodeT Init();

    COgrTypeCtl *Type();

    // Register and deregister driver.
    UErrCodeT RegisterAll();
    UErrCodeT DeregisterAll();
    UErrCodeT Register(const UStringT *aName);
    UErrCodeT Register(OgrFormatCodeT aFormat);
    UErrCodeT Deregister(const UStringT *aName);
    UErrCodeT Deregister(OgrFormatCodeT aFormat);

    // Get Driver.
    COgrDriverCtl *Driver(const UStringT *aName);
    COgrDriverCtl *Driver(OgrFormatCodeT aFormat);
};

class COgrDriverCtl
{
  public:
    COgrDriverCtl(const UStringT *aName);
    ~COgrDriverCtl();

    UErrCodeT Init();
    COgrDatasrcCtl *Create(const UStringT *aFile);
    COgrDatasrcCtl *Load(const UStringT *aFile);
    UErrCodeT Close(const UStringT *aFile);
    UErrCodeT CloseAll();
};

class COgrDatasrcCtl
{
  public:
    COgrDatasrcCtl(const UStringT *aName, UFileOperCodeT aCode,
                   const OgrDriverHT aDriverH);
    ~COgrDatasrcCtl();

    UErrCodeT Init();

    // Attribute.
    UStringT Name();
    OgrDatasrcHT Handle();
    UIntT Count();

    // Layer operator.
    COgrLayerCtl* Create(const UStringT* aName);
    COgrLayerCtl* Load(const UStringT* aName);
    COgrLayerCtl* Load(UIntT aId);
    UErrCodeT Del(const UStringT* aName);
    UErrCodeT Del(UIntT aId);
    UErrCodeT Close(const UStringT *aName);
    UErrCodeT Close(UIntT aId);
    UErrCodeT CloseAll();
};

class COgrLayerCtl
{
  public:
    COgrLayerCtl(const UStringT *aName, UFileOperCodeT aCode,
                 COgrDatasrcCtl *aDsCtl);
    ~COgrLayerCtl();

    // Initialize.
    UErrCodeT Init();

    // Attribute.
    UStringT Name();
    OgrLayerHT Handle();

    // Framework.
    COgrDatasrcCtl *Up();

    // Handle.
    COgrFeatureDefn* FeatureDefn();
    COgrFeaturesCtl* Features();
};

class COgrFeatureDefn
{
  public:
    COgrFeatureDefn(COgrLayerCtl *aLayer);
    ~COgrFeatureDefn();

    UErrCodeT Init();

    OgrFeatureDefnHT Handle();

    COgrFieldDefn* FieldDefn();
    COgrGeomFieldDefn* GeomFieldDefn();
};

class COgrFeaturesCtl
{
  public:
    COgrFeaturesCtl(COgrLayerCtl *aLayer);
    ~COgrFeaturesCtl();

    UErrCodeT Init();
    OgrFeaturesHT Handle();
    COgrLayerCtl *Up();

    COgrFeatureCtl *Create();
    UErrCodeT Add(COgrFeatureCtl *aFeature);
    COgrFeatureCtl *Load(UIntT aRow);
    UIntT Count();
    UErrCodeT CloseAll();
    UErrCodeT Close(COgrFeatureCtl *aFeature);
};

class COgrFeatureCtl
{
  public:
    COgrFeatureCtl(const UFileOperCodeT aOper, const UIntT aId,
                   COgrFeaturesCtl *aFeatures);
    ~COgrFeatureCtl();

    UErrCodeT Init();
    OgrFeatureHT Handle();

    COgrFieldCtl *Field();
    COgrGeomsCtl *Geoms();
};

class COgrFieldCtl
{
  public:
    COgrFieldCtl(OgrFeatureHT aFeatureH);
    ~COgrFieldCtl();

    UErrCodeT Init();
    UErrCodeT Value(UStringT* aValue, UIntT aColumn);
    UErrCodeT Value(UStringT* aValue, UStringT* aName);
    UErrCodeT SetValue(UStringT* aValue, UIntT aColumn);
};

class COgrGeomsCtl
{
  public:
    COgrGeomsCtl(OgrFeaturesHT aFeatureH);
    ~COgrGeomsCtl();

    UErrCodeT Init();

    COgrGeomCtl *Create(const OgrGeomTCodeT aCode);
    UErrCodeT Set(COgrGeomCtl *aGeom);
    COgrGeomCtl *Load();
    UErrCodeT Close(COgrGeomCtl *aGeom);
    UErrCodeT CloseAll();
};

class COgrGeomCtl
{
  public:
    COgrGeomCtl(const UFileOperCodeT aOper, const OgrGeomTCodeT aGeomT,
                OgrGeomsHT aGeomsH);
    ~COgrGeomCtl();

    UErrCodeT Init();
    OgrGeomHT Handle();

    COgrGeomBasic *Basic();
    COgrGeomVertex *Vertex();
};

class COgrGeomBasic
{
  public:
    COgrGeomBasic(OgrGeomHT aGeomH);
    ~COgrGeomBasic();

    UErrCodeT Init();

    UErrCodeT Type(OgrGeomTCodeT *aCode);
};

class COgrGeomVertex
{
  public:
    COgrGeomVertex(OgrGeomHT aGeomH);
    ~COgrGeomVertex();

    UErrCodeT Init();

    // Count.
    UErrCodeT PointCount(UIntT *aCount);

    // Get point.
    UErrCodeT Point2D(BMathCsC2dT *aPt, const UIntT aId);
    UErrCodeT Point3D(BMathCsC3dT *aPt, const UIntT aId);

    // Set point.
    UErrCodeT SetPoint2D(const BMathCsC2dT *aPt, const UIntT aId);
    UErrCodeT SetPoint3D(const BMathCsC3dT *aPt, const UIntT aId);

    // Add point.
    UErrCodeT AddPoint2D(const BMathCsC2dT *aPt);
    UErrCodeT AddPoint3D(const BMathCsC3dT *aPt);
};
