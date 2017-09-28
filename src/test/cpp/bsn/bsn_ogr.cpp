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
    UStringT driverName = OGR_F_JSON;
    COgrDriverCtl *driverCtl = mOgr->Driver(&driverName);
    UStringT file = "/home/swpcme/file/source/swpcme/hub/data/geojson/tmp/forest.geojson";
    COgrDatasrcCtl *dsCtl = driverCtl->Load(&file);
    UIntT layerId = 0;
    COgrLayerCtl *layerCtl = dsCtl->Load(layerId);
    UStringT name = layerCtl->Name();
    name.ToConsole();
    COgrFeaturesCtl *featuresCtl = layerCtl->Features();
    UIntT featureId = 1;
    COgrFeatureCtl *featureCtl = featuresCtl->Load(featureId);
    COgrFieldCtl *fieldCtl = featureCtl->Field();
    UStringT value;
    UIntT fieldId = 0;
    fieldCtl->Value(&value, fieldId);
    value.ToConsole();
    // mOgr->DeregisterAll();

    return UErrFalse;
}
