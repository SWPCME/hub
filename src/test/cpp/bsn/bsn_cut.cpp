/******************************************************************************
 * $Id: bsn_cut.hpp 2017-06 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test cut control api definition.
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

#include "bsn_cut.hpp"

// Hub.
#include "hub_ctl.hpp"
// Cls.
#include "cls_ctl.hpp"
#include "cls_ioctl.hpp"
#include "cls_iocommonctl.hpp"
#include "cls_iostreamctl.hpp"
// Cut.
#include "cut_ctl.hpp"
#include "cut_easysctl.hpp"
#include "cut_easyctl.hpp"

static CClsIoCommonCtl *kIoCmn = NULL;

/***** C Definition A *****/

UErrCodeT cut_write_func(UStringT *aBuffer, UIntT aSize, UIntT aNumItems,
                         UHandleT aOutStream);

/***** C Definition B *****/

/**
 * \brief Constructor.
 */
CBsnCut::CBsnCut()
{
}

/**
 * \brief Destructor.
 */
CBsnCut::~CBsnCut()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CBsnCut::Init()
{
    CHubCtl *hubCtl = CHubCtl::Hub();

    hubCtl->Register(HubMCut);
    CCutCtl *cutCtl = (CCutCtl *) hubCtl->Module(HubMCut);
    mEasys = cutCtl->Easys();

    hubCtl->Register(HubMCls);
    CClsCtl *clsCtl = (CClsCtl *) hubCtl->Module(HubMCls);
    CClsIoCtl *ioCtl = clsCtl->Io();
    mIoCmn = ioCtl->Common();
    mIoStr = ioCtl->Stream();

    kIoCmn = mIoCmn;

    return UErrFalse;
}

/**
 * \brief Test.
 */
UErrCodeT CBsnCut::Test()
{
    UStringT name = "Test";
    CCutEasyCtl *easyCtl = mEasys->Open(&name);
    // UStringT url = "http://113.108.173.110:6080/arcgis/rest/services/maptask/LYXB/MapServer/0/query";
    UStringT url = "http://113.108.173.110:6080/arcgis/rest/services/maptask/LYXB/MapServer/0/query?where=1%3D1&text=&objectIds=&time=&geometry=&geometryType=esriGeometryEnvelope&inSR=&spatialRel=esriSpatialRelIntersects&relationParam=&outFields=&returnGeometry=true&maxAllowableOffset=&geometryPrecision=&outSR=&returnIdsOnly=false&returnCountOnly=false&orderByFields=&groupByFieldsForStatistics=&outStatistics=&returnZ=false&returnM=false&gdbVersion=&returnDistinctValues=false&f=pjson";
    easyCtl->SetUrl(&url);
    easyCtl->SetGet();
    // easyCtl->SetWriteFunc(&cut_write_func);
    UStringT file = "/home/swpcme/tmp/test.txt";
    ClsFileHT fileH = NULL;
    mIoStr->Open(&fileH, &file, ClsFileOperWba);
    easyCtl->SetWriteData(fileH);
    UErrCodeT code = easyCtl->Perform();
    mIoCmn->PrintF("%d\n", code);
    mIoStr->Close(&fileH);

    return UErrFalse;
}

/***** Private A *****/

/***** Private B *****/

/***** C Implementation A *****/
// typedef UErrCodeT (*cut_write_callback)(UStringT *aBuffer, UIntT aSize,
//                                         UIntT aNItems, UHandleT aOutStream);

UErrCodeT cut_write_func(UStringT *aBuffer, UIntT aSize, UIntT aNumItems,
                         UHandleT aOutStream)
{
    kIoCmn->PrintF("%d", aSize * aNumItems);

    return UErrFalse;
}

/***** C Implementation B *****/
