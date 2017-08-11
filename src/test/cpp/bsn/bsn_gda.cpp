/******************************************************************************
 * $Id: bsn_gda.hpp 2017-08 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test gda control api.
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
 *****************************************************************************/

#include "bsn_gda.hpp"

// hub
// cls
#include "cls_ctl.hpp"
#include "cls_ioctl.hpp"
#include "cls_iocommonctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_corectl.hpp"
#include "gda_driversctl.hpp"
#include "gda_driverctl.hpp"
#include "gda_datasetctl.hpp"
#include "gda_bandctl.hpp"
#include "gda_algctl.hpp"
#include "gda_algrasterizer.hpp"
#include "gda_utilsctl.hpp"
#include "gda_utilstranslate.hpp"
#include "gda_translatevector.hpp"
#include "gda_translateraster.hpp"
// ogr
#include "ogr_ctl.hpp"
#include "ogr_driverctl.hpp"
#include "ogr_datasrcctl.hpp"
#include "ogr_layerctl.hpp"
// wrap
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

    CClsCtl *cls = (CClsCtl*) mHub->Module(HubMCls);
    CClsIoCtl *clsIo = cls->Io();
    mIoCmn = clsIo->Common();

    mGda = (CGdaCtl *) mHub->Module(HubMGda);
    CGdaCoreCtl *coreCtl = mGda->Core();
    mDrivers = coreCtl->Drivers();
    mDrivers->RegisterAll();

    mAlg = mGda->Alg();
    mUtils = mGda->Utils();

    mHub->Register(HubMOgr);
    mOgr = (COgrCtl *) mHub->Module(HubMOgr);
    mOgr->RegisterAll();

    return UErrFalse;
}

UErrCodeT CBsnGda::Test()
{
    // TestCreate();
    // TestLoad();
    // TestAlg();
    TestUtils();

    return UErrFalse;
}

/***** Private A *****/

UErrCodeT CBsnGda::TestCreate()
{
    const UStringT file = "../../data/dem/test_create.vrt";
    CreateDataset(&file, 3000, 3000, 5, UDataTInt16, GdaFormatVrt);

    return UErrFalse;
}

UErrCodeT CBsnGda::TestLoad()
{
    const UStringT file = "../../data/dem/test2.asc";
    CGdaDatasetCtl *datasetCtl = LoadDataset(&file, UAccessRead, GdaFormatAsc);

    UStringT description = datasetCtl->Description();
    mIoCmn->PrintF("%s\n", description.ToA());
    UIntT nBand = 0;
    UIntT nXSize = 0;
    UIntT nYSize = 0;
    datasetCtl->Count(&nBand);
    datasetCtl->XSize(&nXSize);
    datasetCtl->YSize(&nYSize);
    mIoCmn->PrintF("nBand = %d, nXSize = %d, nYSize = %d\n", nBand, nXSize,
                   nYSize);

    CGdaBandCtl *bandCtl = datasetCtl->Band(1);

    UIntT nBandX = 0;
    UIntT nBandY = 0;
    bandCtl->XSize(&nBandX);
    bandCtl->YSize(&nBandY);
    mIoCmn->PrintF("nBandX = %d, nBandY = %d\n", nBandX, nBandY);

    UIntT nXBlockS = 0;
    UIntT nYBlockS = 0;
    bandCtl->BlockSize(&nXBlockS, &nYBlockS);
    mIoCmn->PrintF("nXBandS = %d, nYBandS = %d\n", nXBlockS, nYBlockS);

    return UErrFalse;
}

UErrCodeT CBsnGda::TestAlg()
{
    // CGdaAlgRasterizer *rasterizer = mAlg->Rasterizer();

    // // band
    // const UStringT tif = "../../data/geojson/tmp/forest_conver.tif";
    // CGdaBandCtl *bandCtl = Band(&tif, 1, UAccessWrite, GdaFormatTif);

    // // layer
    // UStringT json = "../../data/geojson/tmp/forest.geojson";
    // COgrLayerCtl *layerCtl = Layer(&json, 0, OgrFormatJson);

    // rasterizer->ToBand(bandCtl, layerCtl);

    return UErrFalse;
}

UErrCodeT CBsnGda::TestUtils()
{
    VtrToVtr();
    // VtrToRstEasy();
    // VtrToRstComplex();
    // MergeRst();

    return UErrFalse;
}

/**
 * \brief Vector to vector.
 */
UErrCodeT CBsnGda::VtrToVtr()
{
    CGdaUtilsTranslate *translate = mUtils->Translate();
    CGdaTranslateVector *vector = translate->Vector();

    GdaTranslateV2VOptT opt;
    opt.format = OgrFormatTab;

    UStringT vtr1 = "../../data/geojson/tmp/forest.geojson";
    COgrLayerCtl *layer = Layer(&vtr1, 0, OgrFormatJson);
    COgrDatasrcCtl *dataset = layer->Up();
    UStringT vtr2 = "../../data/geojson/tmp/forest_tab.tab";
    vector->ToVtr(&vtr2, dataset, &opt);

    return UErrFalse;
}

UErrCodeT CBsnGda::VtrToRstEasy()
{
    CGdaUtilsTranslate *translate = mUtils->Translate();

    CGdaTranslateVector *vector = translate->Vector();

    // Vector to raster.
    const UStringT tif = "../../data/geojson/tmp/forest_conver.tif";
    CGdaBandCtl *band = Band(&tif, 1, UAccessWrite, GdaFormatTif);
    UStringT json = "../../data/geojson/tmp/forest.geojson";
    COgrLayerCtl *layer = Layer(&json, 0, OgrFormatJson);
    UStringT fieldName = "YU_BI_DU";
    vector->ToRst(band, layer, &fieldName);

    CGdaTranslateRaster *raster = translate->Raster();
    const UStringT lcp = "../../data/geojson/tmp/forest.lcp";
    CGdaDatasetCtl *datasetCtl = band->Up();
    GdaTranslateR2ROptT opt;
    // const UIntT bandCount = 5;
    // UIntT bandList[bandCount] = {1, 1, 1, 1, 1};
    opt.format = GdaFormatLcp;
    opt.type = UDataTInt16;
    // opt.bandCount = bandCount;
    // opt.bandList = bandList;
    GdaR2RLcpCreateOptT *lcpCreateOpt = &opt.createOpt;
    lcpCreateOpt->latitude = 23;
    lcpCreateOpt->linearUnit = GdaLinearUnitMeter;
    raster->ToRst(&lcp, datasetCtl, &opt);

    return UErrFalse;
}

UErrCodeT CBsnGda::VtrToRstComplex()
{
    CGdaUtilsTranslate *translate = mUtils->Translate();

    CGdaTranslateVector *vector = translate->Vector();

    // Vector to raster.
    const UStringT kPath = "../../data/geojson/tmp/";
    const UStringT kJson = "../../data/geojson/tmp/forest.geojson";
    const UStringT kLcp = "../../data/geojson/tmp/forest.lcp";
    const UStringT kTif = "../../data/geojson/tmp/forest.tif";
    COgrLayerCtl *layer = Layer(&kJson, 0, OgrFormatJson);
    COgrDatasrcCtl *datasrc = layer->Up();
    const UStringT kLayerName = layer->Name();
    const UStringT kElevation = "HAIBA";
    const UStringT kSlope = "PODU";
    const UStringT kAspect = "POXIANG";
    const UStringT kFuel = "LIN_ZHONG";
    const UStringT kCanopyCover = "YU_BI_DU";
    const UIntT kElevationId = 1;
    const UIntT kSlopeId = 2;
    const UIntT kAspectId = 3;
    const UIntT kFuelId = 4;
    const UIntT kCanopyCoverId = 5;

    GdaV2RCreateOptT createOpt;
    createOpt.format = GdaFormatTif;
    createOpt.type = UDataTInt16;
    createOpt.size = {3000, 3000};

    GdaV2RVtrAttrT *vtrAttr = &createOpt.vtrAttr;
    UStringT elevation = kPath;
    elevation += "forest_elevation.tif";
    vtrAttr->layerName = kLayerName;
    vtrAttr->fieldName = kElevation;
    vector->ToRst(&elevation, datasrc, &createOpt);

    // vtrAttr.fieldName = kSlope;
    // vtrCtn->Add(vtrAttr);

    // vtrAttr.fieldName = kAspect;
    // vtrCtn->Add(vtrAttr);

    // vtrAttr.fieldName = kFuel;
    // vtrCtn->Add(vtrAttr);

    // vtrAttr.fieldName = kCanopyCover;
    // vtrCtn->Add(vtrAttr);

    GdaV2RLoadOptT opt;
    GdaV2RRstAttrCtnT *rstCtn = &opt.rstCtn;
    GdaV2RRstAttrT rstAttr;
    rstAttr.bandId = kElevationId;
    rstCtn->Add(rstAttr);

    rstAttr.bandId = kSlopeId;
    rstCtn->Add(rstAttr);

    rstAttr.bandId = kAspectId;
    rstCtn->Add(rstAttr);

    rstAttr.bandId = kFuelId;
    rstCtn->Add(rstAttr);

    rstAttr.bandId = kCanopyCoverId;
    rstCtn->Add(rstAttr);

    return UErrFalse;
}

UErrCodeT CBsnGda::MergeRst()
{
    // execlp("/bin/sh", "sh", "-c", "gdal_merge.py", NULL);
    const UStringT tif1 = "../../data/geojson/tmp/forest_conver.tif";
    const UStringT asc1 = "../../data/geojson/tmp/forest_conver.asc";
    const UStringT tif2 = "../../data/geojson/tmp/forest_z.tif";
    const UStringT tif = "../../data/geojson/tmp/forest.tif";
    CGdaDatasetCtl *tifDr1 = LoadDataset(&tif1, UAccessWrite, GdaFormatTif);
    // CGdaDatasetCtl *ascDr1 = LoadDataset(&asc1, UAccessRead, GdaFormatAsc);
    CGdaDatasetCtl *tifDr2 = LoadDataset(&tif2, UAccessRead, GdaFormatTif);
    // CGdaDatasetCtl *tifDr = LoadDataset(&tif, UAccessWrite, GdaFormatTif);
    UIntT bandId = 1;
    // CGdaBandCtl *band1 = tifDr1->Band(bandId);
    CGdaBandCtl *band2 = tifDr2->Band(bandId);
    // CGdaBandCtl *ascBand1 = ascDr1->Band(bandId);
    tifDr1->SetBand(1, band2);

    return UErrFalse;
}

CGdaDatasetCtl *CBsnGda::CreateDataset(const UStringT *aFile, UIntT aNXSize,
                                       UIntT aNYSize, UIntT aNBand,
                                       UDataTCodeT aDataT,
                                       GdaFormatCodeT aFormat)
{
    CGdaDriverCtl *dr = mDrivers->Driver(aFormat);
    CGdaDatasetCtl *ds = dr->Create(aFile, aNXSize, aNYSize, aNBand, aDataT,
                                    NULL);

    return ds;
}

CGdaDatasetCtl *CBsnGda::LoadDataset(const UStringT *aFile,
                                     UAccessCodeT aAccess,
                                     GdaFormatCodeT aFormat)
{
    CGdaDriverCtl *dr = mDrivers->Driver(aFormat);
    CGdaDatasetCtl *datasetCtl = dr->Load(aFile, aAccess);

    return datasetCtl;
}

CGdaBandCtl *CBsnGda::Band(const UStringT *aFile, UIntT aBandId,
                           UAccessCodeT aAccess, GdaFormatCodeT aFormat)
{
    CGdaDriverCtl *driverCtl = mDrivers->Driver(aFormat);
    CGdaDatasetCtl *datasetCtl = driverCtl->Load(aFile, aAccess);
    CGdaBandCtl *bandCtl = datasetCtl->Band(aBandId);

    return bandCtl;
}

COgrLayerCtl *CBsnGda::Layer(const UStringT *aFile, UIntT aLayerId,
                             OgrFormatCodeT aFormat)
{
    COgrDriverCtl *drCtl = mOgr->Driver(aFormat);
    COgrDatasrcCtl *dsCtl = drCtl->Load(aFile);
    COgrLayerCtl *layerCtl = dsCtl->Load(aLayerId);

    return layerCtl;
}

/***** Private B *****/
