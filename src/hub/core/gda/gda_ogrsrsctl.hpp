/******************************************************************************
 * $Id: gda_ogrsrsctl.hpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Ogr spatial reference system control definition.
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

#ifndef GDA_OGRSRSCTL_HPP_INCLUDED
#define GDA_OGRSRSCTL_HPP_INCLUDED

#include "gda_base.h"

// gda
class CGdaTypeCtl;
class GdaOgrSrsT;
// cls
class CClsMemoryCtl;

class GDA_LIB CGdaOgrSrsCtl
{
  public:
    CGdaOgrSrsCtl();
    ~CGdaOgrSrsCtl();

    UErrCodeT Init();
    GdaOgrSrsHT Handle() const;

    UErrCodeT ImportFromWkt(const UStringT *aWkt);
    UErrCodeT SetProjCs(const GdaProjCsCodeT aCode);
    UErrCodeT ProjCs(GdaProjCsCodeT *aCode);
    UErrCodeT ExportToWkt(UStringT *aWkt);
    UErrCodeT Cmp(const GdaOgrSrsT *aSrs);

  protected:
  private:
    UErrCodeT InitPointer();
    UErrCodeT New();
    UErrCodeT Destroy();

    // gda
    CGdaTypeCtl *mType;
    // cls
    CClsMemoryCtl *mMem;

    GdaOgrSrsHT mSrsH;
    GdaProjCsCodeT mCode;
};

#endif  // GDA_OGRSRSCTL_HPP_INCLUDED
