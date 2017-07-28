/******************************************************************************
 * $Id: ogr_datasrcctl.hpp 2016-08 $
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

#ifndef OGR_DATASRCCTL_HPP_INCLUDED
#define OGR_DATASRCCTL_HPP_INCLUDED

#include "ogr_base.h"
// ust
#include "ust/ust_stringtype.hpp"
#include "ust/ust_containertype.hpp"

class COgrLayerCtl;

class OGR_LIB COgrDatasrcCtl
{
  public:
    COgrDatasrcCtl(const UStringT *aName, UFileOperCodeT aCode,
                   const OgrDriverHT aDriverH);
    ~COgrDatasrcCtl();

    UErrCodeT Init();

    // Attribute.
    UStringT Name();
    OgrDatasrcHT Handle();
    UIntT Count();

    // Layer operator.
    COgrLayerCtl* Create(const UStringT* aName);
    COgrLayerCtl* Load(const UStringT* aName);
    COgrLayerCtl* Load(UIntT aId);
    // COgrLayerCtl* Copy(UIntT aId);
    // COgrLayerCtl* Copy(UStringT* aName);
    UErrCodeT Del(const UStringT* aName);
    UErrCodeT Del(UIntT aId);
    UErrCodeT Close(const UStringT *aName);
    UErrCodeT Close(UIntT aId);
    UErrCodeT CloseAll();

  protected:
  private:
    typedef UContainerT<COgrLayerCtl*, UStringT> MLayerT;
    typedef UIteratorT<COgrLayerCtl*, UStringT> MLayerItT;

    UErrCodeT SetDs(const UStringT *aFile, UFileOperCodeT aCode,
                    const OgrDriverHT aDriverH);
    UErrCodeT DestoryHandle();
    COgrLayerCtl *LayerCtl(const UStringT *aName, UFileOperCodeT aCode);
    UErrCodeT LayerId(UIntT *aId, const UStringT *aName);
    UErrCodeT LayerName(UStringT *aName, const OgrLayerHT aLayerH);
    UErrCodeT LayerName(UStringT *aName, UIntT aId);
    UErrCodeT OgrLayer(OgrLayerHT *aLayerH, const UStringT *aName);
    UErrCodeT OgrLayer(OgrLayerHT *aLayerH, UIntT aId);

    // Handle.
    OgrDatasrcHT mDsH;

    // Map: name to "COgrLayerCtl*".
    MLayerT mMLayer;
};

#endif  /* OGR_DATASRCCTL_HPP_INCLUDED */
