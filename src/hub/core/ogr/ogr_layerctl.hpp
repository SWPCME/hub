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
#include "ust_stringtype.hpp"

class COgrFeatureDefnCtl;
class COgrFeaturesCtl;

class OGR_LIB COgrLayerCtl
{
  public:
    COgrLayerCtl();
    ~COgrLayerCtl();

    // Initialize.
    UErrCodeT Init();

    UErrCodeT Attach(OgrLayerHT aHandle);
    OgrLayerHT Handle();
    UErrCodeT Name(UStringT* aName);

    // Handle.
    COgrFeatureDefnCtl* FeatureDefn();
    COgrFeaturesCtl* Features();

  protected:
  private:
    OgrLayerHT m_handle;

    // Handle
    COgrFeatureDefnCtl* m_featureDefn;
    COgrFeaturesCtl* m_features;
};

#endif  // OGR_LAYERCTL_HPP_INCLUDED