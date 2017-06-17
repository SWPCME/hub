/******************************************************************************
 * $Id: gda_driverctl.cpp 2017-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda driver control.
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

#ifndef GDA_DRIVERCTL_HPP_INCLUDED
#define GDA_DRIVERCTL_HPP_INCLUDED

#include "gda_base.h"

// Hub.
#include "ust_stringtype.hpp"
#include "ust_containertype.hpp"

class CGdaDatasetCtl;
class CGdaTypeCtl;

typedef UContainerT<CGdaDatasetCtl*, UStringT> MDatasetCtlT;
typedef UIteratorT<CGdaDatasetCtl*, UStringT> MDatasetCtlItT;

class GDA_LIB CGdaDriverCtl
{
  public:
    CGdaDriverCtl(GdaDriverHT aHandle);
    ~CGdaDriverCtl();

    UErrCodeT Init();
    CGdaDatasetCtl *Create(const UStringT *aFile, UIntT aXSize, UIntT aYSize,
                           UIntT aNBands, UDataTCodeT aDataT, char **aOption);
    UErrCodeT Copy(const UStringT *aDest, const UStringT *aSrc);
    CGdaDatasetCtl *Open(const UStringT *aFile, const UAccessCodeT aAccess);
    UErrCodeT Close(const UStringT *aFile);
    UErrCodeT Delete(const UStringT *aFile);

  protected:
  private:
    UErrCodeT CloseAll();

    // Map: dataset control with file name.
    MDatasetCtlT mMDataset;
    GdaDriverHT mHandle;
    CGdaTypeCtl *mType;
};

#endif  // GDA_DRIVERCTL_HPP_INCLUDED
