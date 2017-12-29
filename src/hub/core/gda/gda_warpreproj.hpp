/******************************************************************************
 * $Id: gda_warpreproj.hpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Abstraction Library) library.
 * Purpose:  Gda warp reprojection definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017, Weiwei Huang
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

#ifndef GDA_WARPREPROJ_HPP_INCLUDED
#define GDA_WARPREPROJ_HPP_INCLUDED

#include "gda_base.h"

// gda
#include "gda_warpreprojimagetype.hpp"

// gda
class CGdaTypeCtl;

class GDA_LIB CGdaWarpReproj
{
  public:
    CGdaWarpReproj();
    ~CGdaWarpReproj();

    UErrCodeT Init();
    UErrCodeT ToImage(CGdaDatasetCtl *aDst, CGdaDatasetCtl *aSrc,
                      const GdaWarpReprojImageT *aReproj);
    UErrCodeT ToImage(const UStringT *aDst, CGdaDatasetCtl *aSrc,
                      const GdaWarpReprojImageT *aReprj);

  protected:
  private:
    CGdaTypeCtl *mType;
};

#endif  // GDA_WARPREPROJ_HPP_INCLUDED
