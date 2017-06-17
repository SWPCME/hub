/******************************************************************************
 * $Id: vtr_ctl.hpp 2016-08 $
 *
 * Project:  Vector Info Process
 * Purpose:  Vector control.
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

#ifndef VTR_CTL_HPP_INCLUDED
#define VTR_CTL_HPP_INCLUDED

#include "vtr_base.h"

// Module
#include "ust_stringtype.hpp"
#include "ust_containertype.hpp"

class COgrCtl;
class CVtrDataSrcCtl;

typedef UContainerT<CVtrDataSrcCtl*, UStringT> MVtrDataSrcT;

class VTR_LIB CVtrCtl
{
 public:
    CVtrCtl();
    ~CVtrCtl();

    /* Initialization */
    UErrCodeT Init();
    // Cleanup driver.
    UErrCodeT CleanupAll();

    /* Create */
    CVtrDataSrcCtl* Create(UStringT* aFile);
    /* Load */
    CVtrDataSrcCtl* Load(UStringT* aFile);
    /* Close */
    UErrCodeT Close(UStringT* aFile);
    UErrCodeT CloseAll();
    /* Signal Handle */
    CVtrDataSrcCtl* DataSrc(UStringT* File);

 protected:
 private:
    /* Handle */
    COgrCtl* m_ogr;
    MVtrDataSrcT* m_mDataSrc;
    int m_id;
};

#endif  /* VTR_CTL_HPP_INCLUDED */
