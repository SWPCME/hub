/******************************************************************************
 * $Id: gda_algrasterizer.hpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Alg rasterizer definition.
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

#ifndef GDA_ALGRASTERIZER_HPP_INCLUDED
#define GDA_ALGRASTERIZER_HPP_INCLUDED

#include "gda_base.h"

class CGdaBandCtl;
class COgrLayerCtl;

class GDA_LIB CGdaAlgRasterizer
{
  public:
    CGdaAlgRasterizer();
    ~CGdaAlgRasterizer();

    UErrCodeT Init();
    UErrCodeT ToBand(CGdaBandCtl *aBand, COgrLayerCtl *aLayer);

  protected:
  private:
};

#endif  // GDA_ALGRASTERIZER_HPP_INCLUDED
