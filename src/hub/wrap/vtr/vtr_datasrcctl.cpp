/******************************************************************************
 * $Id: vtr_datasrcctl.cpp 2016-08 $
 *
 * Project:  Vector info process library.
 * Purpose:  Vector data source control implementation.
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

#include "vtr_datasrcctl.hpp"

// Module.
#include "ogr_layerctl.hpp"
#include "vtr_layerctl.hpp"

/**
 * \brief Constructor
 *
 * Construct the handle of layers in data source.
 */
CVtrDataSrcCtl::CVtrDataSrcCtl(COgrDataSrcCtl* aCtl)
{
    m_ogrDataSrc = aCtl;
    m_handle = aCtl->Handle();
}

/**
 * \brief Destructor
 *
 * Destruct the handle of layers in data source.
 */
CVtrDataSrcCtl::~CVtrDataSrcCtl()
{
    CloseAll();
}

/**
 * \brief Initialize
 *
 * Initialize the handles in "VectorLayerGroup".
 *
 * @return HE_NONE, if successful; Others, if failed.
 */
UErrCodeT CVtrDataSrcCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Create a new layer.
 *
 * @param aName The name of layer.
 *
 * @return Handle of "CVtrLayerCtl", if successful; NULL, if failed.
 */
CVtrLayerCtl* CVtrDataSrcCtl::Create(UStringT* aName)
{
    Attach();
    COgrLayerCtl* ogrLayer = m_ogrDataSrc->Create(aName);
    CVtrLayerCtl* layer = AddToMVLName(ogrLayer);

    return layer;
}

/**
 * \brief Load a layer.
 *
 * Load a layer by layer name.
 *
 * @param aName The name of layer.
 *
 * @return Handle of "CVtrLayerCtl", if successful; NULL, if failed.
 */
CVtrLayerCtl* CVtrDataSrcCtl::Load(UStringT* aName)
{
    Attach();
    COgrLayerCtl* ogrLayer = m_ogrDataSrc->Load(aName);
    CVtrLayerCtl* layer = AddToMVLName(ogrLayer);

    return layer;
}

/**
 * \brief Load a layer.
 *
 * Load a layer by identify of layer.
 *
 * @param aId The identify of layer.
 *
 * @return Handle of "CVtrLayerCtl", if successful; NULL, if failed.
 */
CVtrLayerCtl* CVtrDataSrcCtl::Load(UIntT aId)
{
    Attach();
    COgrLayerCtl* ogrLayer = m_ogrDataSrc->Load(aId);
    CVtrLayerCtl* layer = AddToMVLName(ogrLayer);

    return layer;
}

/**
 * \brief Close a layer.
 */
UErrCodeT CVtrDataSrcCtl::Close(UStringT* aName)
{
    DelFromMVName(aName);

    return UErrFalse;
}

/**
 * \brief Close all layer.
 */
UErrCodeT CVtrDataSrcCtl::CloseAll()
{
    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Attach handle of ogr data source.
 */
UErrCodeT CVtrDataSrcCtl::Attach()
{
    return m_ogrDataSrc->Attach(m_handle);
}

/**
 * \brief Add layer by name from "m_mVLName".
 */
CVtrLayerCtl* CVtrDataSrcCtl::AddToMVLName(COgrLayerCtl* aLayer)
{
    CVtrLayerCtl* layer = NULL;

    if (aLayer == NULL)
    {
        return layer;
    }

    UStringT name;
    aLayer->Name(&name);
    if (m_mVLName.FindByKey(name) == UErrFalse)
    {
        return layer;
    }

    layer = new CVtrLayerCtl(aLayer);
    m_mVLName.Add(layer, layer->Name()->ToA());

    return layer;
}

/**
 * \brief Del layer by name from "m_mVLName".
 */
UErrCodeT CVtrDataSrcCtl::DelFromMVName(UStringT* aName)
{
    return UErrFalse;
    // return m_mVLName.DelK(aName);
}

/***** Private B *****/
