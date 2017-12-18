/******************************************************************************
 * $Id: ogr_featuresctl.hpp 2016-08 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr features control.
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

#ifndef OGR_FEATURESCTL_HPP_INCLUDED
#define OGR_FEATURESCTL_HPP_INCLUDED

#include "ogr_base.h"
// ust
#include "ust/ust_stringtype.hpp"
#include "ust/ust_containertype.hpp"

// ogr
class COgrLayerCtl;
class COgrFeatureCtl;

class OGR_LIB COgrFeaturesCtl
{
  public:
    COgrFeaturesCtl(COgrLayerCtl *aLayer);
    ~COgrFeaturesCtl();

    UErrCodeT Init();
    OgrFeaturesHT Handle();
    COgrLayerCtl *Up();

    COgrFeatureCtl *Create();
    UErrCodeT Add(COgrFeatureCtl *aFeature);
    COgrFeatureCtl *Load(UIntT aRow);
    UIntT Count();
    UErrCodeT CloseAll();
    UErrCodeT Close(COgrFeatureCtl *aFeature);

  protected:
  private:
    typedef UContainerT<COgrFeatureCtl*, UIntT> MFeatureT;
    typedef UIteratorT<COgrFeatureCtl*, UIntT> MFeatureItT;

    UErrCodeT SetHandle(COgrLayerCtl *aLayer);
    COgrFeatureCtl *FeatureCtl(const UFileOperCodeT aOper, const UIntT aRow = 0);
    OgrLayerHT mLayerH;

    // Handle
    OgrFeaturesHT mFeaturesH;
    MFeatureT mMFeature;

    // ogr
    COgrLayerCtl *mLayer;
    COgrFeatureCtl *mFeature;
};

#endif  // OGR_FEATURESCTL_HPP_INCLUDED
