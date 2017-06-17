/******************************************************************************
 * $Id: ogr_ctl.hpp 2016-08 $
 *
 * Project:  Ogr (OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr Control.
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

#ifndef OGR_CTL_H_INCLUDED
#define OGR_CTL_H_INCLUDED

#include "ogr_base.h"
#include "ust_stringtype.hpp"
#include "ust_containertype.hpp"

class COgrDataSrcCtl;

typedef UContainerT<UHandleT, UStringT> MDriverHandleT;

class OGR_LIB COgrCtl
{
  public:
    COgrCtl();
    ~COgrCtl();

    /* Init and cleanup all. */
    UErrCodeT Init();
    UErrCodeT CleanupAll();

    // Attach
    UErrCodeT Attach(const UStringT* aDriverName);

    // Data source handle.
    COgrDataSrcCtl* Create(UStringT* aFile, const UStringT* aDriverName = NULL);
    COgrDataSrcCtl* Load(UStringT* aFile, const UStringT* aDriverName = NULL);
    UErrCodeT Close(OgrDataSrcHT aHandle);

  protected:
  private:
    /* Init driver */
    UErrCodeT InitDriver();
    UErrCodeT GetDriver(OgrDriverHT aHandle, UStringT* aName);

    // Driver
    OgrDriverHT m_driver;
    /* Map: driver handle with driver name. */
    MDriverHandleT m_mDHName;
    /* Map: driver handle with file suffix. */
    MDriverHandleT m_mDHSuffix;

    // Handle
    COgrDataSrcCtl* m_dataSrc;
};

#endif  /* OGR_CTL_H_INCLUDED */
