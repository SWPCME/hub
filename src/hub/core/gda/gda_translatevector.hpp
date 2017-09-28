/******************************************************************************
 * $Id: gda_translatevector.hpp 2017-08 $
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
#include "ogr/ogr_base.h"
// ust
#include "ust/ust_stringtype.hpp"

// gda
class CGdaTypeCtl;
class CGdaDatasetCtl;
class CGdaBandCtl;
// ogr
class COgrTypeCtl;
class COgrDatasrcCtl;
class COgrLayerCtl;

class GDA_LIB CGdaTranslateVector
{
  public:
    CGdaTranslateVector();
    ~CGdaTranslateVector();

    UErrCodeT Init();

    // To vector.
    UErrCodeT ToVtr(const UStringT *aDstFile, COgrDatasrcCtl *aSrcDs,
                    const GdaTranslateV2VOptT *aOpt);

    // To raster.
    UErrCodeT ToRst(CGdaDatasetCtl *aDstDs, COgrDatasrcCtl *aSrcDs,
                    const GdaV2RLoadOptT *aOpt);
    UErrCodeT ToRst(const UStringT *aDstFile, COgrDatasrcCtl *aSrcDs,
                    const GdaV2RCreateOptT *aOpt);
    UErrCodeT ToRst(CGdaBandCtl *aDstBand, COgrLayerCtl *aSrcLayer,
                    const UStringT *aSrcFieldName);

  protected:
  private:
    // Init pointer.
    UErrCodeT InitPointer();

    // Translate vector to vector.
    UErrCodeT TranslateV2V(const UStringT *aDstFile, GdaDatasetHT aDstDs,
                           GdaDatasetHT aSrcDs,
                           const GdaTranslateV2VOptT *aOpt);
    UErrCodeT NewV2VOpt(GdaTranslateV2VOptHT *aDst,
                        const GdaTranslateV2VOptT *aSrc);
    UErrCodeT DelV2VOpt(const GdaTranslateV2VOptHT aOpt);
    UErrCodeT ToV2VOpt(UStringT *aDst, const GdaTranslateV2VOptT *aSrc);

    // Translate vector to raster.
    UErrCodeT TranslateV2R(const UStringT *aDstFile, GdaDatasetHT aDstDsH,
                           GdaDatasetHT aSrcDsH,
                           const GdaTranslateV2ROptT *aOpt);
    UErrCodeT NewV2ROpt(GdaTranslateV2ROptHT *aDst,
                        const GdaTranslateV2ROptT *aSrc);
    UErrCodeT DelV2ROpt(const GdaTranslateV2ROptHT aOpt);
    UErrCodeT ToV2ROpt(UStringT *aDst, const GdaTranslateV2ROptT *aSrc);
    UErrCodeT ToV2ROpt(GdaTranslateV2ROptT *aDst,
                       const GdaV2RCreateOptT *aSrc);
    UErrCodeT ToV2ROpt(GdaTranslateV2ROptT *aDst,
                       const GdaV2RLoadOptT *aSrc);

    CGdaTypeCtl *mGdaType;
    COgrTypeCtl *mOgrType;
};

#endif  // GDA_TRANSLATEVECTOR_HPP_INCLUDED
