/******************************************************************************
 * $Id: vtr_layerbase.hpp 2016-08 $
 *
 * Project:  Vector info process library.
 * Purpose:  Vector layer base definition.
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

#ifndef VTR_LAYERBASE_HPP_INCLUDED
#define VTR_LAYERBASE_HPP_INCLUDED

#include "vtr_base.h"

// Module
#include "ust_stringtype.hpp"
#include "ogr_layerctl.hpp"

class COgrFieldCtl;

class VTR_LIB VtrFieldDefnT
{
 public:
    VtrFieldDefnT();
    ~VtrFieldDefnT();

    UErrCodeT SetInt(UStringT* aName);
    UErrCodeT SetFloat(UStringT* aName);
    UErrCodeT SetString(UStringT* aName, UIntT aSize);

    UDataTCodeT Code();
    UDataTCodeT Name();
    UIntT StringSize();

 protected:
 private:
    UDataTCodeT m_code();
    UStringT* m_name;
    UIntT m_size;
};

class VTR_LIB CVtrLayerBase
{
  public:
    CVtrLayerBase(COgrLayerCtl* aCtl);
    ~CVtrLayerBase();

    UErrCodeT Init();
    UStringT* Name();
    COgrFieldCtl* Field(UIntT aRow);

  protected:
  private:
    UErrCodeT Attach();

    COgrLayerCtl* m_ogrLayer;
    OgrLayerHT m_handle;
    UStringT m_name;
};

#endif  /* VTR_LAYERBASE_HPP_INCLUDED */
