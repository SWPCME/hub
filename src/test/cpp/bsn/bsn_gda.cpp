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
#include "hub_ctl.hpp"
#include "hub_modulectl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_ioctl.hpp"
#include "cls_iocommonctl.hpp"
// gda
#include "gda_ctl.hpp"
#include "gda_corectl.hpp"
#include "gda_ogrctrtype.hpp"
#include "gda_driversctl.hpp"
#include "gda_driverctl.hpp"
#include "gda_datasetctl.hpp"
#include "gda_bandctl.hpp"
#include "gda_banddatatype.hpp"
#include "gda_algctl.hpp"
#include "gda_algrasterizer.hpp"
#include "gda_utilsctl.hpp"
#include "gda_utilstr.hpp"
#include "gda_trvtr.hpp"
#include "gda_trrst.hpp"
#include "gda_utilsdem.hpp"
// ogr
#include "ogr_ctl.hpp"
#include "ogr_driverctl.hpp"
#include "ogr_datasrcctl.hpp"
#include "ogr_layerctl.hpp"
// wrap
#include "ust_stringtype.hpp"
#include "ust_datatype.hpp"

CBsnGda::CBsnGda()
{
    mHub = CHubCtl::Hub();
    mModule = mHub->RegModule();

    mModule->Register(HubMCls);
    CClsCtl *cls = (CClsCtl*) mModule->Module(HubMCls);
    CClsIoCtl *clsIo = cls->Io();
    mIoCmn = clsIo->Common();

    mModule->Register(HubMGda);
    mGda = (CGdaCtl *) mModule->Module(HubMGda);
    CGdaCoreCtl *coreCtl = mGda->Core();
    mDrivers = coreCtl->Drivers();
    mDrivers->RegisterAll();
    mAlg = mGda->Alg();
    mUtils = mGda->Utils();

    mModule->Register(HubMOgr);
    mOgr = (COgrCtl *) mModule->Module(HubMOgr);
    mOgr->RegisterAll();
}

CBsnGda::~CBsnGda()
{
    mHub->DeregModule(mModule);
}

UErrCodeT CBsnGda::Init()
{
    return UErrFalse;
}

UErrCodeT CBsnGda::Test()
{
    TestCore();
    // TestOgr();
    // TestUtils();

    return UErrFalse;
}

/***** Private A *****/

UErrCodeT CBsnGda::TestCore()
{
    // CoreCreate();
    // CoreLoad();
    // CoreWrite();
    // CoreDataset();
    CoreBand();

    return UErrFalse;
}

UErrCodeT CBsnGda::CoreCreate()
{
    const UStringT file = "../../data/dem/test_create.vrt";
    CreateDataset(&file, 3000, 3000, 5, UDataTInt16, GdaFormatVrt);

    return UErrFalse;
}

UErrCodeT CBsnGda::CoreLoad()
{
    // const UStringT file = "../../../data/core/gda/rst/testLoad.asc";
    // CGdaDatasetCtl *datasetCtl = LoadDataset(&file, UAccessRead, GdaFormatAsc);
    const UStringT file = "../../../data/ctgy/fmd/baiyun_m/baiyun_m.tif";
    CGdaDatasetCtl *datasetCtl = LoadDataset(&file, UAccessRead, GdaFormatTif);
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

    UDataTCodeT dataT = bandCtl->DataT();
    BMathCsC2dT bdBegin(0, 0);
    BMathCsC2dT bdEnd(nBandX - 1, 0);
    GdaBandDataT bandData(dataT, &bdBegin, &bdEnd);
    bandCtl->Read(&bandData);

    return UErrFalse;
}

UErrCodeT CBsnGda::CoreWrite()
{
    UStringT file = "../../data/core/gda/rst/testWrite.tif";
    GdaFormatCodeT frmt = GdaFormatVrt;
    mDrivers->Register(frmt);
    CGdaDriverCtl *dr = mDrivers->Driver(frmt);
    UAccessCodeT access = UAccessWrite;
    CGdaDatasetCtl *ds = dr->Load(&file, access);
    UDataTCodeT dataT = UDataTFloat32;
    CGdaBandCtl *band = ds->Band(1);
    UIntT xSize = 0;
    band->XSize(&xSize);
    UIntT ySize = 0;
    band->YSize(&ySize);
    BMathCsC2dT bdBegin(0, 0);
    BMathCsC2dT bdEnd(xSize, ySize);
    GdaBandDataT bandData(dataT, &bdBegin, &bdEnd);
    band->Read(&bandData);
    UIntT size = xSize * ySize;
    float *val = (float *) bandData.Handle();
    for (UIntT i = 0; i < size; ++i)
    {
        val[i] = 3333;
    }
    band->Write(&bandData);

    return UErrFalse;
}

UErrCodeT CBsnGda::CoreDataset()
{
    const UStringT file = "../../../data/ctgy/fmd/baiyun_m/baiyun_m.lcp";
    CGdaDatasetCtl *datasetCtl = LoadDataset(&file, UAccessRead, GdaFormatLcp);

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

    BCtnFloatT transform(UContainerList);
    datasetCtl->GeoTransform(&transform);
    BItFloatT *itTransform = transform.Iterator();
    itTransform->Head();
    for (UIntT i = 1; itTransform->State() == UErrFalse;
         itTransform->Next(), ++i)
    {
        mIoCmn->PrintF("Transform %d: %lf\n", i, itTransform->Content());
    }

    BMathCsC2dT srcId(nXSize, nYSize);
    BMathCsC2dT dstPos;
    datasetCtl->IdToPos(&dstPos, &srcId);
    mIoCmn->PrintF("srcId = (%lf, %lf), dstPos = (%lf, %lf)\n", srcId.X(),
                   srcId.Y(), dstPos.X(), dstPos.Y());

    GdaOgrSrsT srsSrc;
    srsSrc.SetProjCs(GdaProjCsWgs1984);
    UStringT wktSrc;
    srsSrc.ExportToWkt(&wktSrc);

    GdaOgrSrsT srsDst;
    srsDst.SetProjCs(GdaProjCsXian1980);
    UStringT wktDst;
    srsDst.ExportToWkt(&wktDst);

    GdaOgrCtrT ctr(&srsSrc, &srsDst);
    BMathCsC2dT ptSrc(113.501129, 23.166046);
    BMathCsC2dT ptDst;
    ctr.Tr(&ptDst, &ptSrc);

    BMathCsC2dT srcPos(ptDst.X(), ptDst.Y());
    BMathCsC2dT dstId;
    datasetCtl->PosToId(&dstId, &srcPos);
    mIoCmn->PrintF("srcPos = (%lf, %lf), dstId = (%lf, %lf)\n", srcPos.X(),
                   srcPos.Y(), dstId.X(), dstId.Y());

    return UErrFalse;
}

UErrCodeT CBsnGda::CoreBand()
{
    const UStringT file = "../../../data/ctgy/fmd/baiyun_m/baiyun_m.lcp";
    CGdaDatasetCtl *datasetCtl = LoadDataset(&file, UAccessRead, GdaFormatLcp);
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

    GdaOgrSrsT srsSrc;
    srsSrc.SetProjCs(GdaProjCsWgs1984);
    UStringT wktSrc;
    srsSrc.ExportToWkt(&wktSrc);
    GdaOgrSrsT srsDst;
    srsDst.SetProjCs(GdaProjCsXian1980);
    UStringT wktDst;
    srsDst.ExportToWkt(&wktDst);
    GdaOgrCtrT ctr(&srsSrc, &srsDst);
    BMathCsC2dT ptSrc(113.501129, 23.166046);
    BMathCsC2dT ptDst;
    ctr.Tr(&ptDst, &ptSrc);
    BMathCsC2dT srcPos(ptDst.X(), ptDst.Y());
    BMathCsC2dT dstId;
    UErrCodeT err = datasetCtl->PosToId(&dstId, &srcPos);
    if (err == UErrTrue)
    {
        return err;
    }

    UDataTCodeT dataT = bandCtl->DataT();
    GdaBandDataT bandData(dataT, &dstId);
    bandCtl->Read(&bandData);
    UDataT data;
    bandData.Data(&data);
    UFloatT dataVal = -1.0;
    data.ToF(&dataVal);
    UStringT strVal = dataVal;
    strVal.ToConsole();

    return UErrFalse;
}

UErrCodeT CBsnGda::TestOgr()
{
    OgrCtr();

    return UErrFalse;
}

UErrCodeT CBsnGda::OgrCtr()
{
    GdaOgrSrsT srsSrc;
    srsSrc.SetProjCs(GdaProjCsWgs1984);
    UStringT wktSrc;
    srsSrc.ExportToWkt(&wktSrc);
    wktSrc.ToConsole();

    GdaOgrSrsT srsDst;
    srsDst.SetProjCs(GdaProjCsXian1980);
    UStringT wktDst;
    srsDst.ExportToWkt(&wktDst);
    wktDst.ToConsole();

    GdaOgrCtrT ctr(&srsSrc, &srsDst);
    BMathCsC2dT ptSrc(113.2498169, 23.3335876);
    BMathCsC2dT ptDst;
    ctr.Tr(&ptDst, &ptSrc);

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
    // VtrToVtr();
    // VtrToRstEasy();
    // VtrToRstComplex();
    // RstToRst();
    // Dem();
    // MergeRst();

    return UErrFalse;
}

/**
 * \brief Vector to vector.
 */
UErrCodeT CBsnGda::VtrToVtr()
{
    CGdaUtilsTr *tr = mUtils->Tr();
    CGdaTrVtr *vtr = tr->Vtr();

    GdaTrVtrToVtrT opt;
    OgrFormatCodeT frmt = OgrFormatTab;
    BCtnStringT optV(UContainerList);
    opt.SetAll(frmt, &optV);

    OgrCtnDatasrcT ctnDs(UContainerList);
    UStringT vtr1 = "../../data/core/gda/tr/forest.geojson";
    OgrFormatCodeT frmtSrc = OgrFormatJson;
    COgrDriverCtl *dr = mOgr->Driver(frmtSrc);
    COgrDatasrcCtl *ds = dr->Load(&vtr1);
    ctnDs.Add(ds);

    UStringT vtr2 = "../../data/core/gda/tr/forest_tab.tab";

    vtr->ToVtr(&vtr2, &ctnDs, &opt);

    dr->Close(&vtr1);

    return UErrFalse;
}

UErrCodeT CBsnGda::RstToRst()
{
    CGdaUtilsTr *tr = mUtils->Tr();
    CGdaTrRst *rst = tr->Rst();

    GdaTrRstToRstT opt;
    GdaFormatCodeT frmt = GdaFormatAsc;
    BCtnStringT optV(UContainerList);
    optV.Add("-b 1");
    opt.SetAll(frmt, &optV);

    UStringT rstSrc = "../../data/core/gda/tr/forest.tif";
    GdaFormatCodeT frmtSrc = GdaFormatTif;
    CGdaCoreCtl *gdaCore = mGda->Core();
    CGdaDriversCtl *drs = gdaCore->Drivers();
    drs->Register(frmtSrc);
    CGdaDriverCtl *drSrc = drs->Driver(frmtSrc);
    CGdaDatasetCtl *dsSrc = drSrc->Load(&rstSrc);

    UStringT rstDst = "../../data/core/gda/tr/forest_asc.asc";

    rst->ToRst(&rstDst, dsSrc, &opt);

    drSrc->Close(&rstDst);

    return UErrFalse;
}

UErrCodeT CBsnGda::Dem()
{
    CGdaUtilsDem *dem = mUtils->Dem();

    UStringT dst = "../../data/core/gda/dem/dem1_slope.asc";

    GdaDemProcT proc;
    GdaDemProcFrmtCodeT frmt = GdaDemProcFrmtSlope;
    BCtnStringT opt(UContainerList);
    opt.Add("-of");
    opt.Add("AAIGrid");
    proc.SetAll(frmt, &opt);

    UStringT src = "../../data/core/gda/dem/dem1.tif";
    GdaFormatCodeT frmtSrc = GdaFormatTif;
    CGdaCoreCtl *gdaCore = mGda->Core();
    CGdaDriversCtl *drs = gdaCore->Drivers();
    drs->Register(frmtSrc);
    CGdaDriverCtl *drSrc = drs->Driver(frmtSrc);
    CGdaDatasetCtl *dsSrc = drSrc->Load(&src);

    dem->Proc(&dst, dsSrc, &proc);

    return UErrFalse;
}

UErrCodeT CBsnGda::MergeRst()
{
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

CGdaBandCtl *CBsnGda::LoadBand(const UStringT *aFile, UIntT aBandId,
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
