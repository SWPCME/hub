/******************************************************************************
 * $Id: ogr_featurectl.cpp 2017-07 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr feature control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016-08 ~ 2017, Weiwei Huang
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

#include "ogr_featurectl.hpp"

// Ogr module.
#include "ogr_api.h"
// base
#include "base_macrodefn.hpp"
// ogr
#include "ogr_layerctl.hpp"
#include "ogr_featuresctl.hpp"
#include "ogr_featuredefn.hpp"
#include "ogr_fieldctl.hpp"
#include "ogr_geomsctl.hpp"

/**
 * \brief Constructor.
 */
COgrFeatureCtl::COgrFeatureCtl(const UFileOperCodeT aOper, const UIntT aId,
                               COgrFeaturesCtl *aFeatures)
{
    BMD_POINTER_INIT(mFeatures);
    BMD_POINTER_INIT(mFeatureH);
    SetHandle(aOper, aId, aFeatures);
    BMD_POINTER_INIT(mField);
    BMD_POINTER_INIT(mGeoms);
}


/**
 * \brief Destructor.
 */
COgrFeatureCtl::~COgrFeatureCtl()
{
    BMD_POINTER_INIT(mFeatureH);
    BMD_CLASS_DEL(mField);
    BMD_CLASS_DEL(mGeoms);
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrFeatureCtl::Init()
{
    if (mFeatureH == NULL)
    {
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Handle.
 */
OgrFeatureHT COgrFeatureCtl::Handle()
{
    return mFeatureH;
}

/**
 * \brief Handle of field constrol.
 */
COgrFieldCtl *COgrFeatureCtl::Field()
{
    BMD_CLASS_NEW_A_1(mField, COgrFieldCtl, mFeatureH);

    return mField;
}

/**
 * \brief Handle of geometry set control.
 */
COgrGeomsCtl *COgrFeatureCtl::Geoms()
{
    BMD_CLASS_NEW_A_1(mGeoms, COgrGeomsCtl, mFeatureH);

    return mGeoms;
}

/***** Private A *****/

/**
 * \brief Set handle.
 */
UErrCodeT COgrFeatureCtl::SetHandle(const UFileOperCodeT aOper,
                                    const UIntT aId,
                                    COgrFeaturesCtl *aFeatures)
{
    mFeatures = aFeatures;
    COgrLayerCtl *layerCtl = mFeatures->Up();
    mFeatureDefn = layerCtl->FeatureDefn();

    if (aOper == UFileOperCreate)
    {
        mFeatureH = (OgrFeatureHT) OGR_F_Create(
            (OGRFeatureDefnH) mFeatureDefn->Handle());
    }
    else if (aOper == UFileOperLoad)
    {
        mFeatureH = (OgrFeatureHT) OGR_L_GetFeature
            ((OGRLayerH) mFeatures->Handle(), (GIntBig) aId);
    }

    return UErrTrue;
}

/***** Private B *****/
