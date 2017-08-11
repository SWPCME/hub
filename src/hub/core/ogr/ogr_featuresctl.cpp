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
#include "ogr_featurectl.hpp"

COgrFeaturesCtl::COgrFeaturesCtl(OgrLayerHT aLayerH) : mMFeature(UContainerMap)
{
    BMD_POINTER_INIT(mFeaturesH);
    SetHandle(aLayerH);
    BMD_POINTER_INIT(mIt);
}

COgrFeaturesCtl::~COgrFeaturesCtl()
{
    CloseAll();
    BMD_CLASS_DEL(mIt);
    BMD_POINTER_INIT(mFeaturesH);
}

UErrCodeT COgrFeaturesCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Create feature.
 *
 * @return Handle of feature control, if successful; NULL, if failed.
 */
COgrFeatureCtl *COgrFeaturesCtl::Create()
{
    return FeatureCtl(0);
}

/**
 * \brief Load feature.
 *
 * @param aRow The row in this features.
 *
 * @return Handle of feature control, if successful; NULL, if failed.
 */
COgrFeatureCtl *COgrFeaturesCtl::Load(UIntT aRow)
{
    return FeatureCtl(aRow);
}

/**
 * \brief Close.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrFeaturesCtl::Close(COgrFeatureCtl *aFeature)
{
    return UErrFalse;
}

/**
 * \brief Close all.
 */
UErrCodeT COgrFeaturesCtl::CloseAll()
{
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

/**
 * \brief Iterator Type.
 */
COgrFeatureItCtl *COgrFeaturesCtl::Iterator()
{
    // BMD_CLASS_NEW(COgrFeatureItCtl);

    return mIt;
}

/***** Private A *****/

/**
 * \brief Set handle.
 */
UErrCodeT COgrFeaturesCtl::SetHandle(OgrLayerHT aLayerH)
{
    mFeaturesH = aLayerH;

    return UErrFalse;
}

/**
 * \brief Featrue controler.
 */
COgrFeatureCtl *COgrFeaturesCtl::FeatureCtl(UIntT aRow)
{
    MFeatureItT *it = mMFeature.Iterator();
    if (it->Goto(aRow) == UErrFalse)
    {
        return it->Content();
    }

    COgrFeatureCtl *featureCtl = NULL;
    BMD_CLASS_NEW_A_2(featureCtl, COgrFeatureCtl, aRow, mFeaturesH);
    if (featureCtl != NULL)
    {
        mMFeature.Add(featureCtl, aRow);
    }

    return featureCtl;
}

/***** Private B *****/
