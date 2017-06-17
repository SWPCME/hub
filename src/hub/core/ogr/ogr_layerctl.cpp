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

// Module.
#include "ogr_featuredefnctl.hpp"
#include "ogr_featuresctl.hpp"

COgrLayerCtl::COgrLayerCtl()
{
    m_featureDefn = new COgrFeatureDefnCtl;
    m_features = new COgrFeaturesCtl;
}

COgrLayerCtl::~COgrLayerCtl()
{
    delete m_featureDefn;
    delete m_features;
}

/**
 * \brief Initialize
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrLayerCtl::Init()
{
    m_handle = NULL;

    return UErrFalse;
}

/**
 * \brief Attach
 */
UErrCodeT COgrLayerCtl::Attach(OgrLayerHT aHandle)
{
    m_handle = aHandle;

    return UErrFalse;
}

/**
 * \brief Handle of layer.
 *
 * @return Handle of layer, if successful; NULL, if failed.
 */
OgrLayerHT COgrLayerCtl::Handle()
{
    return m_handle;
}

/**
 * \brief Name of layer.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrLayerCtl::Name(UStringT* aName)
{
    *aName = OGR_L_GetName(m_handle);

    return UErrFalse;
}

/**
 * \brief Get handle of feature definition control.
 *
 * @return Handle of field definition
 */
COgrFeatureDefnCtl* COgrLayerCtl::FeatureDefn()
{
    m_featureDefn->Attach(m_handle);

    return m_featureDefn;
}

/**
 * \brief Get handle of features control.
 *
 * @return Handle of features control, if successful; NULL, if failed.
 */
COgrFeaturesCtl* COgrLayerCtl::Features()
{
    m_features->Attach(m_handle);

    return m_features;
}

