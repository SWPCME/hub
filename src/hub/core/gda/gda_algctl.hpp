/******************************************************************************
 * $Id: gda_algctl.hpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Alg control definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-07 ~ 2017, Weiwei Huang
 *
 * This program is free software; you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by the Free 
 * Software Foundation, either version 3 of the License, or (at your option) 
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for 
 * more details.
 *
 * You should have received a copy of the GNU General Public License along 
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#ifndef GDA_ALGCTL_HPP_INCLUDED
#define GDA_ALGCTL_HPP_INCLUDED

#include "gda_base.h"

class CGdaAlgBase;
class CGdaAlgTransform;
class CGdaAlgContour;
class CGdaAlgRasterizer;
class CGdaAlgGridding;

class GDA_LIB CGdaAlgCtl
{
  public:
    CGdaAlgCtl();
    ~CGdaAlgCtl();

    UErrCodeT Init();

    CGdaAlgBase *Base();
    CGdaAlgTransform *Transform();
    CGdaAlgContour *Contour();
    CGdaAlgRasterizer *Rasterizer();
    CGdaAlgGridding *Gridding();

  protected:
  private:
    UErrCodeT InitPointer();

    CGdaAlgBase *mBase;
    CGdaAlgTransform *mTransform;
    CGdaAlgContour *mContour;
    CGdaAlgRasterizer *mRasterizer;
    CGdaAlgGridding *mGridding;
};

#endif  // GDA_ALGCTL_HPP_INCLUDED
