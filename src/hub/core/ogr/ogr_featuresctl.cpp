/******************************************************************************
 * $Id: ogr_featuresctl.cpp 2016-08 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr features control.
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

#include "ogr_featuresctl.hpp"

// GDAL/OGR library.
#include "ogr_api.h"

// Module.
#include "ogr_featurectl.hpp"

COgrFeaturesCtl::COgrFeaturesCtl()
{
    m_feature = new COgrFeatureCtl;
}

COgrFeaturesCtl::~COgrFeaturesCtl()
{
    delete m_feature;
}

UErrCodeT COgrFeaturesCtl::Init()
{
    return UErrFalse;
}

UErrCodeT COgrFeaturesCtl::Attach(OgrLayerHT aHandle)
{
    m_handle = aHandle;

    return UErrFalse;
}

/**
 * \brief Create feature.
 *
 * @return Handle of feature control, if successful; NULL, if failed.
 */
COgrFeatureCtl* COgrFeaturesCtl::Create()
{
    OgrFeatureHT featureH = NULL;
    OGRErr err = OGR_L_CreateFeature((OGRLayerH) m_handle, (OGRFeatureH) featureH);
    if (err != OGRERR_NONE)
    {
        return NULL;
    }
    m_feature->Attach(featureH);

    return m_feature;
}

/**
 * \brief Load feature.
 *
 * @param aRow The row in this features.
 *
 * @return Handle of feature control, if successful; NULL, if failed.
 */
COgrFeatureCtl* COgrFeaturesCtl::Load(UIntT aRow)
{
    OgrFeatureHT featrueH = (OgrFeatureHT) OGR_L_GetFeature
        ((OGRLayerH) m_handle, (GIntBig) aRow);
    m_feature->Attach(featrueH);

    return m_feature;
}
