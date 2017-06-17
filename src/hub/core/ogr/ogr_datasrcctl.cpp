/******************************************************************************
 * $Id: ogr_datasrcctl.cpp 2016-08 $
 *
 * Project:  Ogr (OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr Data Source Control.
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

#include "ogr_datasrcctl.hpp"

// Ogr library.
#include "ogr_api.h"

// Module
#include "ogr_layerctl.hpp"

/**
 * \brief Const Valuable.
 */
const int kLayerIdMin = 0;

/**
 * \brief Constructor.
 */
COgrDataSrcCtl::COgrDataSrcCtl()
{
    m_layer = new COgrLayerCtl;
}

/**
 * \brief Destructor.
 */
COgrDataSrcCtl::~COgrDataSrcCtl()
{
    delete m_layer;
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; HE_ERROR, if failed.
 */
UErrCodeT COgrDataSrcCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Attach handle of data source.
 *
 * @return UErrFalse, if successful; HE_ERROR, if failed.
 */
UErrCodeT COgrDataSrcCtl::Attach(OgrDataSrcHT aDataSrcH)
{
    m_handle = aDataSrcH;

    return UErrFalse;
}

/**
 * \brief Handle of ogr data source.
 */
OgrDataSrcHT COgrDataSrcCtl::Handle()
{
    return m_handle;
}

/**
 * \brief Name of ogr data source.
 */
UErrCodeT COgrDataSrcCtl::Name(UStringT* aName)
{
    *aName = OGR_DS_GetName(m_handle);

    return UErrFalse;
}

/**
 * \brief Create Layer.
 *
 * @param aName The name of layer.
 *
 * @return Handle of layer control, if successful; NULL, if failed.
 */
COgrLayerCtl* COgrDataSrcCtl::Create(UStringT* aName)
{
    OGRSpatialReferenceH spatialRef = NULL;
    OGRwkbGeometryType gType = wkbUnknown;
    char** options = NULL;
    OgrLayerHT layerH = (OgrLayerHT) OGR_DS_CreateLayer
        (m_handle, aName->ToA(), spatialRef, gType, options);
    m_layer->Attach(layerH);

    return m_layer;
}

/**
 * \brief Load layer.
 *
 * Get a handle of layer by the handle of datasource.
 *
 * @param aName The name of layer.
 *
 * @return Handle of ogr layer, if successful; NULL, if failed.
 */
COgrLayerCtl* COgrDataSrcCtl::Load(UStringT* aName)
{
    OgrLayerHT layerH;
    layerH = OGR_DS_GetLayerByName(m_handle, aName->ToA());

    m_layer->Attach(layerH);

    return m_layer;
}

/**
 * \brief Load layer.
 *
 * Get a handle of layer by the handle of datasource.
 *
 * @param aName The name of layer.
 *
 * @return Handle of ogr layer, if successful; NULL, if failed.
 */
COgrLayerCtl* COgrDataSrcCtl::Load(UIntT aId)
{
    OgrLayerHT layerH = (OgrLayerHT) OGR_DS_GetLayer(m_handle, kLayerIdMin);
    m_layer->Attach(layerH);

    return m_layer;
}

/**
 * \brief Delete layer by name.
 */
UErrCodeT COgrDataSrcCtl::Del(UStringT* aName)
{
    Load(aName);
    // TODO Cycle by id and compare the "aName".
    // Del(m_layer->Id());

    return UErrFalse;
}

/**
 * \brief Delete layer by id.
 */
UErrCodeT COgrDataSrcCtl::Del(UIntT aId)
{
    OGR_DS_DeleteLayer(m_handle, aId);

    return UErrFalse;
}
