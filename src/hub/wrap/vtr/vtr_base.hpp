/******************************************************************************
 * $Id: vector_base.hpp 2017-08 $
 *
 * Project:  Vector Info Process
 * Purpose:  Vector Base Info.
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

#ifndef VECTOR_BASE_H_INCLUDED
#define VECTOR_BASE_H_INCLUDED

#include "hub_base.h"

#define VTR_LIB HUB_LIB

// typedef GdaRasterSizeT VtrRasterSizeT;

/** 
 * \brief Vector field controler container.
 */
// typedef UContainerT<CVtrFieldCtl>(UContainerList) VtrFieldCtlCtn;

/** 
 * \brief To translate vector to raster with format of landscape.
 */
// class VtrFormatToRstLcpT
// {
// public:
//     VtrRasterSizeT size;        // Size of raster.
//     VtrFieldCtlCtn fieldCtn;    // Field of controlear.

//     VtrFormatToRstLcpT() : fieldCtn(UContainerList)
//     {
//         size = {0, 0};
//     }

//     ~VtrFormatToRstLcpT();
// };

#endif  /* VECTOR_BASE_H_INCLUDED */
