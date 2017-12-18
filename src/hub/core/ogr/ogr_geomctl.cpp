/******************************************************************************
 * $Id: ogr_geometryctl.cpp 2016-08 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr geometry control implementation.
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

#include "ogr_geomctl.hpp"

// base
#include "base_ctl.hpp"
#include "base_macrodefn.hpp"
// core
#include "core_ctl.hpp"
// ogr
#include "ogr_ctl.hpp"
#include "ogr_typectl.hpp"
#include "ogr_geombasic.hpp"
#include "ogr_geomvertex.hpp"

// GDAL
#include "ogr_api.h"

/**
 * \brief Constructor.
 */
COgrGeomCtl::COgrGeomCtl(const UFileOperCodeT aOper, const OgrGeomTCodeT aGeomT,
                         OgrGeomsHT aGeomsH)
{
    BMD_POINTER_INIT(mGeomH);
    SetHandle(aOper, aGeomT, aGeomsH);
    BMD_POINTER_INIT(mType);
    BMD_POINTER_INIT(mBasic);
    BMD_POINTER_INIT(mVertex);
}

/**
 * \brief Destructor.
 */
COgrGeomCtl::~COgrGeomCtl()
{
    DestroyHandle();
    BMD_POINTER_INIT(mType);
    BMD_CLASS_DEL(mBasic);
    BMD_CLASS_DEL(mVertex);
}

/**
 * \brief Initialize.
 */
UErrCodeT COgrGeomCtl::Init()
{
    OGR_TYPE_CTL(mType);

    return UErrFalse;
}

/**
 * \brief Handle.
 */
OgrGeomHT COgrGeomCtl::Handle()
{
    return mGeomH;
}

/**
 * \brief Basic.
 */
COgrGeomBasic *COgrGeomCtl::Basic()
{
    BMD_CLASS_NEW_A_1(mBasic, COgrGeomBasic, mGeomH);

    return mBasic;
}

/**
 * \brief Vertex.
 */
COgrGeomVertex *COgrGeomCtl::Vertex()
{
    BMD_CLASS_NEW_A_1(mVertex, COgrGeomVertex, mGeomH);

    return mVertex;
}

/***** Private A *****/

/**
 * \brief Set handle.
 */
UErrCodeT COgrGeomCtl::SetHandle(const UFileOperCodeT aOper,
                                 const OgrGeomTCodeT aGeomT,
                                 OgrGeomsHT aGeomsH)
{
    if (aOper == UFileOperLoad)
    {
        mGeomH = (OgrGeomHT) OGR_F_GetGeometryRef((OGRFeatureH) aGeomsH);

        return UErrFalse;
    }

    if (aOper == UFileOperCreate)
    {
        OGRwkbGeometryType geomT;
        mType->ToGeomT((OgrGeomTHT) &geomT, aGeomT);
        mGeomH = (OgrGeomHT) OGR_G_CreateGeometry(geomT);

        return UErrFalse;
    }

    return UErrTrue;
}

/**
 * \brief Destory handle.
 */
UErrCodeT COgrGeomCtl::DestroyHandle()
{
    OGR_G_DestroyGeometry((OGRGeometryH) mGeomH);

    return UErrFalse;
}

/***** Private B *****/
