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
#include "ogr/ogr_featuredefnctl.hpp"
#include "ogr/ogr_featuresctl.hpp"
#include "ogr/ogr_featurectl.hpp"
#include "ogr/ogr_fieldctl.hpp"
%}

%include "whub_ctl.i"
%include "whub_ustctl.i"

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

class COgrCtl
{
  public:
    COgrCtl();
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
    COgrFeatureDefnCtl* FeatureDefn();
    COgrFeaturesCtl* Features();
};

class COgrFeatureDefnCtl
{
  public:
    COgrFeatureDefnCtl(OgrLayerHT aLayerH);
    ~COgrFeatureDefnCtl();

    UErrCodeT Init();

    COgrFieldDefnCtl* FieldDefn();
    COgrGeomFieldDefnCtl* GeomFieldDefn();
};

class COgrFeaturesCtl
{
  public:
    COgrFeaturesCtl(OgrLayerHT aLayerH);
    ~COgrFeaturesCtl();

    UErrCodeT Init();
    COgrFeatureCtl *Create();
    COgrFeatureCtl *Load(UIntT aRow);
    UIntT Count();
    UErrCodeT CloseAll();
    UErrCodeT Close(COgrFeatureCtl *aFeature);
    COgrFeatureItCtl *Iterator();
};

class COgrFeatureCtl
{
  public:
    COgrFeatureCtl(UIntT aId, OgrLayerHT aLayerH);
    ~COgrFeatureCtl();

    UErrCodeT Init();
    COgrFieldCtl *Field();
    COgrGeometryCtl *Geometry();
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
