/******************************************************************************
 * $Id: ogr_featuredefn.hpp 2016-08 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.a
 * Purpose:  Ogr feature definition definition.
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

#ifndef OGR_FEATUREDEFN_HPP_INCLUDED
#define OGR_FEATUREDEFN_HPP_INCLUDED

#include "ogr_base.h"

// ogr
class COgrLayerCtl;
class COgrFieldDefn;
class COgrGeomFieldDefn;

class OGR_LIB COgrFeatureDefn
{
  public:
    COgrFeatureDefn(COgrLayerCtl *aLayer);
    ~COgrFeatureDefn();

    UErrCodeT Init();

    OgrFeatureDefnHT Handle();

    COgrFieldDefn* FieldDefn();
    COgrGeomFieldDefn* GeomFieldDefn();

  protected:
  private:
    UErrCodeT SetHandle(COgrLayerCtl *aLayer);

    OgrFeatureDefnHT mFeatureDefnH;

    // Controler.
    COgrLayerCtl *mLayer;
    COgrFieldDefn *mFieldDefn;
    COgrGeomFieldDefn *mGeomFieldDefn;
};

#endif  // OGR_FEATUREDEFN_HPP_INCLUDED
