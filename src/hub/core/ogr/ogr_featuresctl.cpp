/******************************************************************************
 * $Id: ogr_featuresctl.cpp 2017-07 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr features control.
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

#include "ogr_featuresctl.hpp"

// GDAL/OGR library.
#include "ogr_api.h"
// base
#include "base_macrodefn.hpp"
// ogr
#include "ogr_layerctl.hpp"
#include "ogr_featurectl.hpp"

/**
 * \brief Constructor.
 */
COgrFeaturesCtl::COgrFeaturesCtl(COgrLayerCtl *aLayer) : mMFeature(UContainerMap)
{
    BMD_POINTER_INIT(mLayer);
    BMD_POINTER_INIT(mFeaturesH);
    SetHandle(aLayer);
}

/**
 * \brief Destructor.
 */
COgrFeaturesCtl::~COgrFeaturesCtl()
{
    CloseAll();
    BMD_POINTER_INIT(mFeaturesH);
}

/**
 * \brief Initialize.
 */
UErrCodeT COgrFeaturesCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Handle.
 */
OgrFeaturesHT COgrFeaturesCtl::Handle()
{
    return mFeaturesH;
}

/**
 * \brief Up.
 */
COgrLayerCtl *COgrFeaturesCtl::Up()
{
    return mLayer;
}

/**
 * \brief Create feature.
 *
 * This feature is lonely, not belong to any layer.
 *
 * @return Handle of feature control, if successful; NULL, if failed.
 */
COgrFeatureCtl *COgrFeaturesCtl::Create()
{
    UFileOperCodeT oper = UFileOperCreate;

    return FeatureCtl(oper);
}

/**
 * \brief Add feature for this layer.
 */
UErrCodeT COgrFeaturesCtl::Add(COgrFeatureCtl *aFeature)
{
    OGRFeatureH featureH = (OGRFeatureH) aFeature->Handle();
    if (featureH == NULL)
    {
        return UErrTrue;
    }

    OGRErr err = OGR_L_CreateFeature((OGRLayerH) mFeaturesH, featureH);
    if (err != OGRERR_NONE)
    {
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Load feature.
 *
 * @param aRow The row in this features, begin from 0.
 *
 * @return Handle of feature control, if successful; NULL, if failed.
 */
COgrFeatureCtl *COgrFeaturesCtl::Load(UIntT aRow)
{
    UFileOperCodeT oper = UFileOperLoad;

    return FeatureCtl(oper, aRow);
}

/**
 * \brief Close.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrFeaturesCtl::Close(COgrFeatureCtl *aFeature)
{
    mMFeature.Del(aFeature);
    BMD_CLASS_DEL(aFeature);

    return UErrFalse;
}

/**
 * \brief Close all.
 */
UErrCodeT COgrFeaturesCtl::CloseAll()
{
    MFeatureItT *it = mMFeature.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        Close(it->Content());
    }

    return UErrFalse;
}

/**
 * \brief Count.
 */
UIntT COgrFeaturesCtl::Count()
{
    UIntT bForce = TRUE;
    UIntT count = OGR_L_GetFeatureCount((OGRLayerH) mFeaturesH, bForce);

    return count;
}

/***** Private A *****/

/**
 * \brief Set handle.
 */
UErrCodeT COgrFeaturesCtl::SetHandle(COgrLayerCtl *aLayer)
{
    mLayer = aLayer;
    mFeaturesH = (OgrFeaturesHT) mLayer->Handle();

    return UErrFalse;
}

/**
 * \brief Featrue controler.
 */
COgrFeatureCtl *COgrFeaturesCtl::FeatureCtl(const UFileOperCodeT aOper,
                                            const UIntT aRow)
{
    MFeatureItT *it = mMFeature.Iterator();
    if (it->Goto(aRow) == UErrFalse)
    {
        return it->Content();
    }

    COgrFeatureCtl *featureCtl = NULL;
    BMD_CLASS_NEW_A_3(featureCtl, COgrFeatureCtl, aOper, aRow, this);
    if (featureCtl != NULL)
    {
        mMFeature.Add(featureCtl, aRow);
    }

    return featureCtl;
}

/***** Private B *****/
