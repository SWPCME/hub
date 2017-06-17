/******************************************************************************
 * $Id: gda_rasterbandctl.hpp 2017-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda raster band control.
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

#ifndef GDA_RASTERBANDCTL_HPP_INCLUDED
#define GDA_RASTERBANDCTL_HPP_INCLUDED

#include "gda_base.h"

class CGdaTypeCtl;

class GDA_LIB CGdaRasterbandCtl
{
  public:
    CGdaRasterbandCtl(GdaRasterBandHT aHandle);
    ~CGdaRasterbandCtl();

    // Init.
    UErrCodeT Init();

    // Size.
    UErrCodeT BlockSize(UIntT *aX, UIntT *aY);
    UErrCodeT Min(UFloatT *aVal);
    UErrCodeT Max(UFloatT *aVal);
    UErrCodeT XSize(UIntT *aSize);
    UErrCodeT YSize(UIntT *aSize);

    // Read and write.
    UErrCodeT Read(UIntT aXOff, UIntT aYOff, UIntT aXSize,
                   UIntT aYSize, void *aData, UIntT aBufXSize,
                   UIntT aBufYSize, UDataTCodeT aDataT,
                   UIntT aPixelSpace, UIntT aLineSpace);
    UErrCodeT ReadBlock(UDataT aData, UIntT aXOff, UIntT aYOff);
    UErrCodeT Write(UIntT aXOff, UIntT aYOff, UIntT aXSize,
                    UIntT aYSize, void *aData, UIntT aBufXSize,
                    UIntT aBufYSize, UDataTCodeT aDataT,
                    UIntT aPixelSpace, UIntT aLineSpace);

  protected:
  private:
    GdaRasterBandHT mHandle;
    CGdaTypeCtl *mType;
};

#endif  // GDA_RASTERBANDCTL_HPP_INCLUDED
