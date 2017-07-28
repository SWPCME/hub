/******************************************************************************
 * $Id: gda_translateraster.hpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Translate raster definition.
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

#ifndef GDA_TRANSLATERASTER_HPP_INCLUDED
#define GDA_TRANSLATERASTER_HPP_INCLUDED

#include "gda_base.h"

// gda
#include "ust/ust_stringtype.hpp"

// gda
class CGdaTypeCtl;
class CGdaDatasetCtl;

class GDA_LIB CGdaTranslateRaster
{
  public:
    CGdaTranslateRaster();
    ~CGdaTranslateRaster();

    UErrCodeT Init();
    UErrCodeT ToRst(const UStringT *aDstPath, CGdaDatasetCtl *aSrcDsCtl,
                    const GdaTranslateRstOptT *aOpt);

 protected:
  private:
    UErrCodeT Translate(const UStringT *aFile, GdaDatasetHT aDsH,
                        const GdaTranslateRstOptT *aOpt);
    UErrCodeT NewRstOpt(GdaTranslateRstOptHT *aOpt,
                        const GdaTranslateRstOptT *aSrc);
    UErrCodeT DelRstOpt(const GdaTranslateRstOptHT aOpt);
    UErrCodeT ToRstOpt(UStringT *aDst, const GdaTranslateRstOptT *aSrc);

    CGdaTypeCtl *mType;
};

#endif  // GDA_TRANSLATERASTER_HPP_INCLUDED
