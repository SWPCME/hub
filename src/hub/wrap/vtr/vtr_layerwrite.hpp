/******************************************************************************
 * $Id: vtr_layerwrite.h 2016-08 $
 *
 * Project:  Vector Info Process
 * Purpose:  Vector layer write.
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

#ifndef VTR_LAYERWRITE_H_INCLUDED
#define VTR_LAYERWRITE_H_INCLUDED

#include "vtr_layerbase.hpp"

class VTR_LIB CVtrLayerWrite
{
 public:
    CVtrLayerWrite(CVtrLayerBase* aBase);
    ~CVtrLayerWrite();

    // Initialize.
    UErrCodeT Init();
    UErrCodeT SetValue(UStringT* aValue, UIntT aRow, UIntT aColumn);
    UErrCodeT SetValue(UIntT aValue, UIntT aRow, UIntT aColumn);
    UErrCodeT SetValue(UFloatT aValue, UIntT aRow, UIntT aColumn);

 protected:
 private:
    CVtrLayerBase* m_base;
};

#endif  /* VTR_LAYERWRITE_H_INCLUDED */
