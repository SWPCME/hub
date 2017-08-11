/******************************************************************************
 * $Id: ogr_datasrcctl.cpp 2017-07 $
 *
 * Project:  Ogr (OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr Data Source Control.
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

#include "ogr_datasrcctl.hpp"

// module
#include "ogr_api.h"
// base
#include "base_macrodefn.hpp"
// ogr
#include "ogr_layerctl.hpp"

/**
 * \brief Constructor.
 */
COgrDatasrcCtl::COgrDatasrcCtl(const UStringT *aFile, UFileOperCodeT aCode,
                               const OgrDriverHT aDriverH) : mMLayer(UContainerMap)
{
    BMD_POINTER_INIT(mDsH);
    SetDs(aFile, aCode, aDriverH);
}

/**
 * \brief Destructor.
 */
COgrDatasrcCtl::~COgrDatasrcCtl()
{
    CloseAll();
    DestoryHandle();
    BMD_POINTER_INIT(mDsH);
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrDatasrcCtl::Init()
{
    if (mDsH == NULL)
    {
        return UErrTrue;
    }
    CloseAll();

    return UErrFalse;
}

/**
 * \brief Name of ogr data source.
 */
UStringT COgrDatasrcCtl::Name()
{
    UStringT name = OGR_DS_GetName(mDsH);

    return name;
}

/**
 * \brief Handle.
 */
OgrDatasrcHT COgrDatasrcCtl::Handle()
{
    return mDsH;
}

/**
 * \brief Count of layer.
 */
UIntT COgrDatasrcCtl::Count()
{
    UIntT n = OGR_DS_GetLayerCount(mDsH);

    return n;
}

/**
 * \brief Create Layer.
 *
 * @param aName The name of layer.
 *
 * @return Handle of layer control, if successful; NULL, if failed.
 */
COgrLayerCtl *COgrDatasrcCtl::Create(const UStringT* aName)
{
    return LayerCtl(aName, UFileOperCreate);
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
COgrLayerCtl *COgrDatasrcCtl::Load(const UStringT* aName)
{
    return LayerCtl(aName, UFileOperLoad);
}

/**
 * \brief Load layer.
 *
 * Get a handle of layer by the handle of datasource.
 *
 * @param aId The id of layer, begin from 0.
 *
 * @return Handle of ogr layer, if successful; NULL, if failed.
 */
COgrLayerCtl *COgrDatasrcCtl::Load(UIntT aId)
{
    if (aId < 0 || aId >= Count())
    {
        return NULL;
    }
    UStringT name;
    LayerName(&name, aId);

    return LayerCtl(&name, UFileOperLoad);
}

/**
 * \brief Delete layer by name.
 */
UErrCodeT COgrDatasrcCtl::Del(const UStringT* aName)
{
    UIntT id;
    if (LayerId(&id, aName) == UErrTrue)
    {
        return UErrTrue;
    }

    return Del(id);
}

/**
 * \brief Delete layer by id.
 */
UErrCodeT COgrDatasrcCtl::Del(UIntT aId)
{
    OGR_DS_DeleteLayer(mDsH, aId);

    return UErrFalse;
}

/**
 * \brief Close by name.
 */
UErrCodeT COgrDatasrcCtl::Close(const UStringT *aName)
{
    MLayerItT *it = mMLayer.Iterator();
    if (it->Goto(aName) == UErrTrue)
    {
        return UErrTrue;
    }
    delete it->Content();

    return UErrFalse;
}

/**
 * \brief Close by id.
 */
UErrCodeT COgrDatasrcCtl::Close(UIntT aId)
{
    MLayerItT *it = mMLayer.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        UStringT name = it->Key();
        UIntT id;
        LayerId(&id, &name);
        if (id == aId)
        {
            Close(&name);
            return UErrFalse;
        }
    }
    
    return UErrTrue;
}

/**
 * \brief Close all.
 */
UErrCodeT COgrDatasrcCtl::CloseAll()
{
    MLayerItT *it= mMLayer.Iterator();
    for (it->Head(); it->State() == UErrFalse; it->Next())
    {
        UStringT name = it->Key();
        Close(&name);
    }

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Set datasrc handle.
 */
UErrCodeT COgrDatasrcCtl::SetDs(const UStringT *aFile, UFileOperCodeT aCode,
                                const OgrDriverHT aDriverH)
{
    switch (aCode)
    {
    case UFileOperCreate:
    {
        char** options = NULL;
        mDsH = (OgrDatasrcHT) OGR_Dr_CreateDataSource
            ((OGRSFDriverH) aDriverH, aFile->ToA(), options);
        break;
    }
    case UFileOperLoad:
    {
        UIntT update = 0;
        mDsH = (OgrDatasrcHT) OGR_Dr_Open((OGRSFDriverH) aDriverH,
                                          aFile->ToA(), update);
        break;
    }
    default:
        return UErrTrue;
    }
    return UErrFalse;
}

/**
 * \brief Destroy handle of datasrc.
 */
UErrCodeT COgrDatasrcCtl::DestoryHandle()
{
    OGR_DS_Destroy((OGRDataSourceH) mDsH);

    return UErrFalse;
}

/**
 * \brief Layer controler.
 */
COgrLayerCtl *COgrDatasrcCtl::LayerCtl(const UStringT *aName, UFileOperCodeT aCode)
{
    MLayerItT *it = mMLayer.Iterator();
    if (it->Goto(aName) == UErrFalse)
    {
        return it->Content();
    }
    COgrLayerCtl *layerCtl = NULL;
    BMD_CLASS_NEW_A_3(layerCtl, COgrLayerCtl, aName, aCode, this);
    if (layerCtl != NULL)
    {
        mMLayer.Add(&layerCtl, aName);
    }

    return layerCtl;
}

/**
 * \brief Get id by name.
 *
 */
UErrCodeT COgrDatasrcCtl::LayerId(UIntT *aId, const UStringT *aName)
{
    OgrLayerHT layerH = NULL;
    if (OgrLayer(&layerH, aName) == UErrTrue)
    {
        return UErrTrue;
    }

    UIntT n = Count();
    for (UIntT i = 0; i < n; ++i)
    {
        OgrLayerHT tLayerH = NULL;
        if (OgrLayer(&tLayerH, i) == UErrTrue)
        {
            continue;
        }
        if (tLayerH == layerH)
        {
            *aId = i;
            return UErrFalse;
        }
    }

    return UErrTrue;
}

/**
 * \brief Get layer name by handle.
 */
UErrCodeT COgrDatasrcCtl::LayerName(UStringT *aName, const OgrLayerHT aLayerH)
{
    *aName = OGR_L_GetName(aLayerH);

    return UErrFalse;
}

/**
 * \brief Get layer name by id.
 */
UErrCodeT COgrDatasrcCtl::LayerName(UStringT *aName, UIntT aId)
{
    OgrLayerHT layerH = NULL;
    if (OgrLayer(&layerH, aId) == UErrTrue)
    {
        return UErrTrue;
    }
    LayerName(aName, layerH);

    return UErrFalse;
}

/**
 * \brief Get layer by name.
 */
UErrCodeT COgrDatasrcCtl::OgrLayer(OgrLayerHT *aLayerH, const UStringT *aName)
{
    *aLayerH = OGR_DS_GetLayerByName(mDsH, aName->ToA());

    if (aLayerH == NULL)
    {
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Get layer by id.
 */
UErrCodeT COgrDatasrcCtl::OgrLayer(OgrLayerHT *aLayerH, UIntT aId)
{
    *aLayerH = OGR_DS_GetLayer(mDsH, aId);

    if (aLayerH == NULL)
    {
        return UErrTrue;
    }

    return UErrFalse;
}

/***** Private B *****/
