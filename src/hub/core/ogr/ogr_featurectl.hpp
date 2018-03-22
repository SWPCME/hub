/******************************************************************************
 * $Id: ogr_featurectl.hpp 2017-07 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr feature control.
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

#ifndef OGR_FEATURECTL_HPP_INCLUDED
#define OGR_FEATURECTL_HPP_INCLUDED

#include "ogr_base.h"

class COgrFeaturesCtl;
class COgrFieldCtl;
class COgrGeomsCtl;
class COgrFeatureDefn;

class OGR_LIB COgrFeatureCtl
{
  public:
    COgrFeatureCtl(const UFileOperCodeT aCode, const UIntT aId,
                   COgrFeaturesCtl *aFeatures);
    ~COgrFeatureCtl();

    UErrCodeT Init();
    OgrFeatureHT Handle();

    COgrFieldCtl *Field();
    COgrGeomsCtl *Geoms();

  protected:
  private:
    UErrCodeT SetHandle(const UFileOperCodeT aOper, const UIntT aId,
                        COgrFeaturesCtl *aFeatures);

    OgrFeatureHT mFeatureH;

    COgrFeaturesCtl *mFeatures;
    COgrFieldCtl *mField;
    COgrGeomsCtl *mGeoms;

    COgrFeatureDefn *mFeatureDefn;
};

#endif  // OGR_FEATURECTL_HPP_INCLUDED
