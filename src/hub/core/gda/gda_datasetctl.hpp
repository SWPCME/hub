/******************************************************************************
 * $Id: gda_datasetctl.hpp 2017-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda dataset control.
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

#ifndef GDA_DATASETCTL_HPP_INCLUDED
#define GDA_DATASETCTL_HPP_INCLUDED

#include "gda_base.h"
#include "ust_containertype.hpp"
#include "ust_stringtype.hpp"

class CGdaTypeCtl;
class CGdaRasterbandCtl;

typedef UContainerT<CGdaRasterbandCtl*, UIntT> MGdaRasterBandCtlT;

class GDA_LIB CGdaDatasetCtl
{
  public:
    CGdaDatasetCtl(GdaDatasetHT aHandle);
    ~CGdaDatasetCtl();

    // Init
    UErrCodeT Init(UStringT *aFile, UAccessCodeT aCode);

    UErrCodeT Save();
    UErrCodeT AddBand(UDataTCodeT aDataT, UStringT *aOption);
    UErrCodeT Count(UIntT *aNum);
    CGdaRasterbandCtl *Band(UIntT aId);
    UErrCodeT XSize(UIntT *aNum);

  private:
  protected:
    UErrCodeT Close();

    // Handle.
    GdaDatasetHT mHandle;
    CGdaTypeCtl *mType;
    MGdaRasterBandCtlT mBandCtn;
};

#endif  // GDA_DATASETCTL_HPP_INCLUDED
