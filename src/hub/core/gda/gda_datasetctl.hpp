/******************************************************************************
 * $Id: gda_datasetctl.hpp 2017-08 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda dataset control.
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

#ifndef GDA_DATASETCTL_HPP_INCLUDED
#define GDA_DATASETCTL_HPP_INCLUDED

#include "gda_base.h"
#include "ust/ust_containertype.hpp"
#include "ust/ust_stringtype.hpp"

class CGdaTypeCtl;
class CGdaBandCtl;

class GDA_LIB CGdaDatasetCtl
{
  public:
    CGdaDatasetCtl(const UStringT *aFile, const GdaDatasetAttrT *aAttr,
                   const GdaDriverHT aDriver);
    CGdaDatasetCtl(const UStringT *aFile, UAccessCodeT aAccess);
    ~CGdaDatasetCtl();

    // Init
    UErrCodeT Init();

    // Attribute
    GdaDatasetHT Handle();
    UStringT Description();

    UErrCodeT Save();
    UErrCodeT Count(UIntT *aNum);
    UErrCodeT AddBand(UDataTCodeT aDataT, UStringT *aOption = NULL);
    CGdaBandCtl *Band(UIntT aId);
    UErrCodeT SetBand(UIntT aDstId, CGdaBandCtl *aSrcBand);
    UErrCodeT XSize(UIntT *aNum);
    UErrCodeT YSize(UIntT *aNum);

  private:
  protected:
    typedef UContainerT<CGdaBandCtl*, UIntT> MBandT;
    typedef UIteratorT<CGdaBandCtl*, UIntT> MBandItT;

    UErrCodeT InitPointer();
    UErrCodeT CreateDataset(const UStringT *aFile,
                            const GdaDatasetAttrT *aAttr,
                            const GdaDriverHT aDriver);
    UErrCodeT LoadDataset(const UStringT *aFile, UAccessCodeT aAccess);
    CGdaBandCtl *BandCtl(UIntT aId);
    UErrCodeT GdaClose();

    // Handle.
    GdaDatasetHT mDatasetH;
    CGdaTypeCtl *mType;
    MBandT mMBand;
};

#endif  // GDA_DATASETCTL_HPP_INCLUDED
