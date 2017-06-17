/******************************************************************************
 * $Id: bsn_gda.hpp 2017-05 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test gda control api.
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
 *****************************************************************************/

#include "bsn_gda.hpp"

// Hub.
// Core.
#include "cls_ctl.hpp"
#include "cls_ioctl.hpp"
#include "gda_ctl.hpp"
#include "gda_driverctl.hpp"
#include "gda_datasetctl.hpp"
#include "gda_rasterbandctl.hpp"
// Wrap.
#include "ust_stringtype.hpp"

CBsnGda::CBsnGda()
{
}

CBsnGda::~CBsnGda()
{
}

UErrCodeT CBsnGda::Init()
{
    mHub = CHubCtl::Hub();
    mHub->Register(HubMGda);
    mHub->Register(HubMCls);

    return UErrFalse;
}

UErrCodeT CBsnGda::Test()
{
    // CClsCtl *cls = (CClsCtl*) mHub->Module(HubMCls);
    // CClsIoCtl *clsIo = cls->Io();

    // mGda = (CGdaCtl*) mHub->Module(HubMGda);
    // UStringT driverName = "asc";
    // UStringT file = "../../data/dem/test.asc";
    // CGdaDriverCtl *driverCtl = mGda->Driver(&driverName);
    // UAccessCodeT access = UAccessRead;
    // CGdaDatasetCtl *datasetCtl = driverCtl->Open(&file, access);
    // UIntT nBand = 0;
    // UIntT nXSize = 0;
    // datasetCtl->Count(&nBand);
    // datasetCtl->XSize(&nXSize);
    // CGdaRasterbandCtl *rasterBand = datasetCtl->Band(nBand);
    // UIntT nBandX = 0;
    // rasterBand->XSize(&nBandX);
    // UFloatT bandMax = 0;
    // rasterBand->Max(&bandMax);
    // // UDataT data = NULL;
    // // rasterBand->ReadBlock(data, 1, 0);
    // // UIntT* iData = (UIntT*) data;
    // clsIo->PrintF("%d, %d, %d, %d", nBand, nXSize, nBandX, bandMax);

    return UErrFalse;
}
