/******************************************************************************
 * $Id: gda_warpreprjimagetype.hpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Abstraction Library) library.
 * Purpose:  Gda warp reproject image type definition.
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

#ifndef GDA_WARPREPROJIMAGETYPE_HPP_INCLUDED
#define GDA_WARPREPROJIMAGETYPE_HPP_INCLUDED

#include "gda_base.h"

// gda
#include "gda_ogrsrstype.hpp"

// gda
class CGdaWarpReprojImageCtl;
class CGdaDriverCtl;

class GDA_LIB GdaWarpReprojImageT
{
  public:
    GdaWarpReprojImageT();
    ~GdaWarpReprojImageT();

    UErrCodeT Init();

    // Set value.
    UErrCodeT SetAll(const GdaOgrSrsT *aDstSrs,
                     const GdaOgrSrsT *aSrcSrs,
                     const CGdaDriverCtl *aDstDr);
    UErrCodeT SetDstSrs(const GdaOgrSrsT *aDstSrs);
    UErrCodeT SetSrcSrs(const GdaOgrSrsT *aSrcSrs);
    UErrCodeT SetDstDr(const CGdaDriverCtl *aDstDr);

    // Get value.
    UErrCodeT All(GdaOgrSrsT *aDstSrs, GdaOgrSrsT *aSrcSrs,
                  CGdaDriverCtl **aDstDr) const;
    GdaOgrSrsT *DstSrs() const;
    GdaOgrSrsT *SrcSrs() const;
    CGdaDriverCtl *DstDr() const;

  protected:
  private:
    CGdaWarpReprojImageCtl *mReproj;

    GdaOgrSrsT mDstSrs;
    GdaOgrSrsT mSrcSrs;
    CGdaDriverCtl *mDstDr;
};

#endif  // GDA_WARPREPROJIMAGETYPE_HPP_INCLUDED
