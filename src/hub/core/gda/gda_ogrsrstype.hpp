/******************************************************************************
 * $Id: gda_ogrsrstype.hpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Ogr spatial reference system type definition.
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

#ifndef GDA_OGRSRSTYPE_HPP_INCLUDED
#define GDA_OGRSRSTYPE_HPP_INCLUDED

#include "gda_base.h"

// gda
class CGdaOgrSrsCtl;

class GDA_LIB GdaOgrSrsT
{
  public:
    GdaOgrSrsT();
    ~GdaOgrSrsT();

    UErrCodeT Init();
    GdaOgrSrsHT Handle() const;

    UErrCodeT ImportFromWkt(const UStringT *aWkt);
    UErrCodeT SetProjCs(const GdaProjCsCodeT aCode);
    UErrCodeT ExportToWkt(UStringT *aWkt);

    // Operator.
    UErrCodeT operator =(const GdaOgrSrsT &aSrs);

  protected:
  private:
    UErrCodeT InitPointer();

    CGdaOgrSrsCtl *mSrs;
};

#endif  // GDA_OGRSRSTYPE_HPP_INCLUDED
