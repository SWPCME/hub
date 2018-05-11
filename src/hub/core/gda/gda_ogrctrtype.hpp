/******************************************************************************
 * $Id: gda_ogrctrtype.hpp 2018-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Ogr coordinate transform type definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-05 ~ 2018, Weiwei Huang
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

#ifndef GDA_OGRCTRTYPE_HPP_INCLUDED
#define GDA_OGRCTRTYPE_HPP_INCLUDED

#include "gda_base.h"

// base
class BMathCsC2dT;
// gda
class CGdaTypeOgrCtr;
class GdaOgrSrsT;

class GDA_LIB GdaOgrCtrT
{
  public:
    GdaOgrCtrT();
    GdaOgrCtrT(const GdaOgrSrsT *aSrc, const GdaOgrSrsT *aDst);
    ~GdaOgrCtrT();

    UErrCodeT Tr(BMathCsC2dT *aDst, const BMathCsC2dT *aSrc);

  protected:
  private:
    UErrCodeT Init();
    UErrCodeT New(const GdaOgrSrsT *aSrc, const GdaOgrSrsT *aDst);
    UErrCodeT Destroy();

    CGdaTypeOgrCtr *mCtr;
    GdaOgrCtrHT mCtrH;
};

#endif  // GDA_OGRCTRTYPE_HPP_INCLUDED
