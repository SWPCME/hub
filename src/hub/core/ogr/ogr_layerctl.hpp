/******************************************************************************
 * $Id: ogr_layerctl.hpp 2016-08 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.a
 * Purpose:  Ogr Layer Control.
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

#ifndef OGR_LAYERCTL_HPP_INCLUDED
#define OGR_LAYERCTL_HPP_INCLUDED

#include "ogr_base.h"

//Module
#include "ust/ust_stringtype.hpp"

class COgrDatasrcCtl;
class COgrFeatureDefnCtl;
class COgrFeaturesCtl;

class OGR_LIB COgrLayerCtl
{
  public:
    COgrLayerCtl(const UStringT *aName, UFileOperCodeT aCode,
                 COgrDatasrcCtl *aDsCtl);
    ~COgrLayerCtl();

    // Initialize.
    UErrCodeT Init();

    // Attribute.
    UStringT Name();
    OgrLayerHT Handle();

    // Framework.
    COgrDatasrcCtl *Up();

    // Handle.
    COgrFeatureDefnCtl* FeatureDefn();
    COgrFeaturesCtl* Features();

  protected:
  private:
    UErrCodeT SetHandle(const UStringT *aName, UFileOperCodeT aCode);

    OgrLayerHT mLayerH;

    COgrDatasrcCtl *mDs;
    COgrFeatureDefnCtl *mFeatureDefn;
    COgrFeaturesCtl *mFeatures;
};

#endif  // OGR_LAYERCTL_HPP_INCLUDED
