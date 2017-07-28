/******************************************************************************
 * $Id: gda_typectl.hpp 2017-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda type control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017, Weiwei Huang
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

#ifndef GDA_TYPECTL_HPP_INCLUDED
#define GDA_TYPECTL_HPP_INCLUDED

#include "gda_base.h"
// GDAL
#include "gdal.h"
// ust
#include "ust/ust_stringtype.hpp"

// cls
class CClsStringCtl;
class CClsMemoryCtl;

class GDA_LIB CGdaTypeCtl
{
  public:
    CGdaTypeCtl();
    ~CGdaTypeCtl();

    UErrCodeT Init();
    UErrCodeT ToAccess(GDALAccess *aDest, const UAccessCodeT aSrc);
    UErrCodeT ToDataType(GDALDataType *aDest, UDataTCodeT aSrc);
    UErrCodeT ToFormat(UStringT *aDest, const GdaFormatCodeT aSrc);

    // argv
    UErrCodeT NewArgv(GdaArgvT *aDst, const UStringT *aSrc);
    UErrCodeT DelArgv(GdaArgvT aArgv);

  protected:
  private:
    CClsStringCtl *mStr;
    CClsMemoryCtl *mMem;
};

#endif  // GDA_TYPECTL_HPP_INCLUDED
