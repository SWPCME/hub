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
#include "ogr_fieldctl.hpp"
#include "ogr_geometryctl.hpp"

/**
 * \brief Constructor.
 */
COgrFeatureCtl::COgrFeatureCtl(UIntT aId, OgrLayerHT aLayerH)
{
    BMD_POINTER_INIT(mFeatureH);
    SetHandle(aId, aLayerH);
    BMD_POINTER_INIT(mField);
    BMD_POINTER_INIT(mGeometry);
}


/**
 * \brief Destructor.
 */
COgrFeatureCtl::~COgrFeatureCtl()
{
    BMD_POINTER_INIT(mFeatureH);
    BMD_CLASS_DEL(mField);
    BMD_CLASS_DEL(mGeometry);
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
 * \brief Handle of field constrol.
 */
COgrFieldCtl* COgrFeatureCtl::Field()
{
    BMD_CLASS_NEW_A_1(mField, COgrFieldCtl, mFeatureH);

    return mField;
}

/**
 * \brief Handle of geometry control.
 */
COgrGeometryCtl* COgrFeatureCtl::Geometry()
{
    BMD_CLASS_NEW_A_1(mGeometry, COgrGeometryCtl, mFeatureH);

    return mGeometry;
}

/***** Private A *****/

/**
 * \brief Set handle.
 */
UErrCodeT COgrFeatureCtl::SetHandle(UIntT aId, OgrLayerHT aLayerH)
{
    if (aId == 0)
    {
        OGRErr err = OGR_L_CreateFeature((OGRLayerH) aLayerH, (OGRFeatureH) mFeatureH);
        if (err != OGRERR_NONE)
        {
            mFeatureH = NULL;
        }
    }
    else if (aId > 0)
    {
        mFeatureH = (OgrFeatureHT) OGR_L_GetFeature
            ((OGRLayerH) aLayerH, (GIntBig) aId);
    }

    return UErrTrue;
}

/***** Private B *****/
