/******************************************************************************
 * $Id: vtr_datasrcctl.hpp 2016-08 $
 *
 * Project:  Vector Info Process
 * Purpose:  Vector data source control definition.
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

#ifndef VTR_DATASRCCTL_HPP_INCLUDED
#define VTR_DATASRCCTL_HPP_INCLUDED

#include "vtr_base.hpp"

// Module
#include "ogr_datasrcctl.hpp"
#include "ust_stringtype.hpp"
#include "ust_containertype.hpp"

class COgrLayerCtl;
class CVtrLayerCtl;

typedef UContainerT<CVtrLayerCtl*, UStringT> MVtrLayerByNameT;

class VTR_LIB CVtrDatasrcCtl
{
 public:
    CVtrDatasrcCtl(COgrDatasrcCtl* aCtl);
    ~CVtrDatasrcCtl();

    /* Initialize */
    UErrCodeT Init();
    /* Set handle. */
    CVtrLayerCtl* Create(UStringT* aName);
    CVtrLayerCtl* Load(UStringT* aName);
    CVtrLayerCtl* Load(UIntT aId);
    // Close layer form ram.
    UErrCodeT Close(UStringT* aName);
    UErrCodeT Close(UIntT aId);
    UErrCodeT CloseAll();
    // Delete layer from disk.
    UErrCodeT Del(UStringT* aName);
    UErrCodeT Del(UIntT aId);
    UErrCodeT DelAll();

 protected:
 private:
    CVtrLayerCtl* AddToMVLName(COgrLayerCtl* aLayer);
    UErrCodeT DelFromMVName(UStringT* aName);

    COgrDatasrcCtl* m_ogrDataSrc;
    OgrDatasrcHT m_handle;
    MVtrLayerByNameT m_mVLName;
};

#endif  /* VTR_DATASRCCTL_HPP_INCLUDED */
