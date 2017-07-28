/******************************************************************************
 * $Id: gda_driverctl.cpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda driver control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-05 ~ 2017, Weiwei Huang
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
#include "ust/ust_stringtype.hpp"
#include "ust/ust_containertype.hpp"

class CGdaDatasetCtl;
class CGdaTypeCtl;

class GDA_LIB CGdaDriverCtl
{
  public:
    CGdaDriverCtl(const UStringT *aName);
    ~CGdaDriverCtl();

    UErrCodeT Init();
    CGdaDatasetCtl *Create(const UStringT *aFile, UIntT aXSize, UIntT aYSize,
                           UIntT aNBands, UDataTCodeT aDataT, char **aOption);
    UErrCodeT Copy(const UStringT *aDest, const UStringT *aSrc);
    CGdaDatasetCtl *Load(const UStringT *aFile, const UAccessCodeT aAccess);
    UErrCodeT Close(const UStringT *aFile);
    UErrCodeT Delete(const UStringT *aFile);

  protected:
  private:
    typedef UContainerT<CGdaDatasetCtl*, UStringT> MDatasetT;
    typedef UIteratorT<CGdaDatasetCtl*, UStringT> MDatasetItT;

    UErrCodeT SetHandle(const UStringT *aName);
    CGdaDatasetCtl *DatasetCtl(const UStringT *aFile, UFileOperCodeT aFileOper,
                               const GdaDatasetAttrT *aAttr,
                               const UAccessCodeT *aAccess);
    UErrCodeT CloseAll();

    // Map: dataset control with file name.
    MDatasetT mMDataset;
    GdaDriverHT mDriverH;
    CGdaTypeCtl *mType;
};

#endif  // GDA_DRIVERCTL_HPP_INCLUDED
