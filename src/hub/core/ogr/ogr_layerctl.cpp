/******************************************************************************
 * $Id: ogr_layerctl.hpp 2016-08 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr Layer Control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016, Weiwei Huang
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ****************************************************************************/

#include "ogr_layerctl.hpp"

// GDAL/OGR Library.
#include "ogr_api.h"
// base
#include "base_macrodefn.hpp"
// ogr
#include "ogr_datasrcctl.hpp"
#include "ogr_featuredefn.hpp"
#include "ogr_featuresctl.hpp"

/**
 * \brief Constructor.
 */
COgrLayerCtl::COgrLayerCtl(const UStringT *aName, UFileOperCodeT aCode,
                           COgrDatasrcCtl *aDsCtl)
{
    mDs = aDsCtl;
    BMD_POINTER_INIT(mFeatureDefn);
    BMD_POINTER_INIT(mFeatures);
    BMD_POINTER_INIT(mLayerH);
    SetHandle(aName, aCode);
}

/**
 * \brief Destructor.
 */
COgrLayerCtl::~COgrLayerCtl()
{
    BMD_CLASS_DEL(mFeatureDefn);
    BMD_CLASS_DEL(mFeatures);
    BMD_POINTER_INIT(mLayerH);
}

/**
 * \brief Initialize
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrLayerCtl::Init()
{
    if (mLayerH == NULL)
    {
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Name of layer.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UStringT COgrLayerCtl::Name()
{
    UStringT name = OGR_L_GetName(mLayerH);

    return name;
}

/**
 * \brief Handle.
 */
OgrLayerHT COgrLayerCtl::Handle()
{
    return mLayerH;
}

/**
 * \brief Up.
 */
COgrDatasrcCtl *COgrLayerCtl::Up()
{
    return mDs;
}

/**
 * \brief Save.
 * Synchronism the change for layer to disk.
 */
UErrCodeT COgrLayerCtl::Save()
{
    OGR_L_SyncToDisk((OGRLayerH) mLayerH);

    return UErrFalse;
}

/**
 * \brief Get handle of feature definition control.
 *
 * @return Handle of field definition
 */
COgrFeatureDefn* COgrLayerCtl::FeatureDefn()
{
    BMD_CLASS_NEW_A_1(mFeatureDefn, COgrFeatureDefn, this);

    return mFeatureDefn;
}

/**
 * \brief Get handle of features control.
 *
 * @return Handle of features control, if successful; NULL, if failed.
 */
COgrFeaturesCtl* COgrLayerCtl::Features()
{
    BMD_CLASS_NEW_A_1(mFeatures, COgrFeaturesCtl, this);

    return mFeatures;
}

/***** Private A *****/

UErrCodeT COgrLayerCtl::SetHandle(const UStringT *aName, UFileOperCodeT aCode)
{
    OgrDatasrcHT dsH = mDs->Handle();
    switch (aCode)
    {
    case UFileOperCreate:
    {
        OGRSpatialReferenceH spatialRef = NULL;
        OGRwkbGeometryType gType = wkbUnknown;
        char** options = NULL;
        mLayerH = (OgrLayerHT) OGR_DS_CreateLayer
            (dsH, aName->ToA(), spatialRef, gType, options);
        break;
    }
    case UFileOperLoad:
    {
        mLayerH = OGR_DS_GetLayerByName(dsH, aName->ToA());
        break;
    }
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/***** Private B *****/
