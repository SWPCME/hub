/******************************************************************************
 * $Id: ogr_featuredefnctl.cpp 2016-08 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.a
 * Purpose:  Ogr feature definition control.
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

#include "ogr_featuredefn.hpp"

// base
#include "base_macrodefn.hpp"
// ogr
#include "ogr_layerctl.hpp"
#include "ogr_fielddefn.hpp"
#include "ogr_geomfielddefn.hpp"

// GDAL/OGR
#include "ogr_api.h"

COgrFeatureDefn::COgrFeatureDefn(COgrLayerCtl *aLayer)
{
    BMD_POINTER_INIT(mLayer);
    BMD_POINTER_INIT(mFeatureDefnH);
    SetHandle(aLayer);
    BMD_POINTER_INIT(mFieldDefn);
    BMD_POINTER_INIT(mGeomFieldDefn);
}

COgrFeatureDefn::~COgrFeatureDefn()
{
    BMD_CLASS_DEL(mFieldDefn);
    BMD_CLASS_DEL(mGeomFieldDefn);
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrFeatureDefn::Init()
{
    return UErrFalse;
}

/**
 * \brief Get Handle.
 */
OgrFeatureDefnHT COgrFeatureDefn::Handle()
{
    return mFeatureDefnH;
}

/**
 * \brief Get handle of field definition control.
 */
COgrFieldDefn* COgrFeatureDefn::FieldDefn()
{
    BMD_CLASS_NEW(mFieldDefn, COgrFieldDefn);

    return mFieldDefn;
}

/**
 * \brief Get handle of geometry definition control.
 */
COgrGeomFieldDefn* COgrFeatureDefn::GeomFieldDefn()
{
    BMD_CLASS_NEW(mGeomFieldDefn, COgrGeomFieldDefn);

    return mGeomFieldDefn;
}

/***** Private A *****/

/**
 * \brief Set handle.
 */
UErrCodeT COgrFeatureDefn::SetHandle(COgrLayerCtl *aLayer)
{
    mLayer = aLayer;
    mFeatureDefnH = (OgrFeatureDefnHT) OGR_L_GetLayerDefn(
        (OGRLayerH) mLayer->Handle());

    return UErrFalse;
}

/***** Private B *****/
