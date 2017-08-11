/******************************************************************************
 * $Id: gda_bandcolor.hpp 2017-08 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Band color definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-05 ~ 2017, Weiwei Huang
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
 ****************************************************************************/

#ifndef GDA_BANDCOLOR_HPP_INCLUDED
#define GDA_BANDCOLOR_HPP_INCLUDED

#include "gda_base.h"

class GDA_LIB CGdaBandColor
{
  public:
    CGdaBandColor(GdaBandHT aBandH);
    ~CGdaBandColor();

    UErrCodeT Init();

    // Attribute.
    GdaBandColorHT Handle();

  protected:
  private:
    UErrCodeT InitPointer();
    UErrCodeT LoadColor(GdaBandHT aBand);

    GdaBandColorHT mColorH;
};

#endif  // GDA_BANDCOLOR_HPP_INCLUDED
