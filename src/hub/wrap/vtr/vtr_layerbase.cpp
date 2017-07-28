/******************************************************************************
 * $Id: vtr_layerbase.hpp 2016-08 $
 *
 * Project:  Vector info process library.
 * Purpose:  Vector layer base implementation.
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

#include "vtr_layerbase.hpp"

// Module.
#include "ogr_featuresctl.hpp"
#include "ogr_featurectl.hpp"
#include "ogr_fieldctl.hpp"

/**
 * \brief Constructor.
 */
CVtrLayerBase::CVtrLayerBase(COgrLayerCtl* aCtl)
{
    m_ogrLayer = aCtl;
    // m_handle = aCtl->Handle();
}

/**
 * \brief Destructor.
 */
CVtrLayerBase::~CVtrLayerBase()
{
}

/**
 * \brief Initialize
 */
UErrCodeT CVtrLayerBase::Init()
{
    return UErrFalse;
}

/**
 * \brief Layer's name.
 */
UStringT* CVtrLayerBase::Name()
{
    // m_ogrLayer->Name(&m_name);

    return &m_name;
}

/**
 * \brief Get field by row.
 */
COgrFieldCtl* CVtrLayerBase::Field(UIntT aRow)
{
    COgrFeaturesCtl* features = m_ogrLayer->Features();
    COgrFeatureCtl* feature = features->Load(aRow);

    return feature->Field();
}

/***** Private A *****/

/***** Private B *****/
