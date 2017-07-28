/******************************************************************************
 * $Id: gda_translatevector.hpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Translate vector definition.
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

#ifndef GDA_TRANSLATEVECTOR_HPP_INCLUDED
#define GDA_TRANSLATEVECTOR_HPP_INCLUDED

#include "gda_base.h"

// ogr
#include "ogr_base.h"
// ust
#include "ust/ust_stringtype.hpp"

// gda
class CGdaBandCtl;
// ogr
class COgrLayerCtl;

class GDA_LIB CGdaTranslateVector
{
  public:
    CGdaTranslateVector();
    ~CGdaTranslateVector();

    UErrCodeT Init();

    // To vector.
    UErrCodeT ToVtr();

    // To raster.
    UErrCodeT ToRst(CGdaBandCtl *aBand, COgrLayerCtl *aLayer,
                    const UStringT *aFieldName);

  protected:
  private:
    UErrCodeT Rasterize(const UStringT *aDstDir, GdaDatasetHT aDstDsH,
                        GdaDatasetHT aSrcDsH, const GdaRasterizeOptHT aOpt);
};

#endif  // GDA_TRANSLATEVECTOR_HPP_INCLUDED
