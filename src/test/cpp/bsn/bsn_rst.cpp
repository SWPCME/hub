/******************************************************************************
 * $Id: bsn_rst.cpp 2017-12 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test rst api implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017, Weiwei Huang
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

#include "bsn_rst.hpp"

// hub
#include "hub_ctl.hpp"
#include "hub_modulectl.hpp"
// rst
#include "rst_ctl.hpp"
#include "rst_frmtctl.hpp"
#include "rst_frmtlcp.hpp"

CBsnRst::CBsnRst()
{
    mHub = CHubCtl::Hub();
    mModule = mHub->RegModule();
    mTmpPath = "/home/swpcme/tmp";
    mModule->SetTmpDir(&mTmpPath);

    mModule->Register(HubMRst);

    mRst = (CRstCtl*) mModule->Module(HubMRst);
}

CBsnRst::~CBsnRst()
{
    mHub->DeregModule(mModule);
}

UErrCodeT CBsnRst::Init()
{
    return UErrFalse;
}

UErrCodeT CBsnRst::Test()
{
    Frmt();

    return UErrFalse;
}

/***** Private A *****/

UErrCodeT CBsnRst::Frmt()
{
    FrmtLcp(mRst);
    // FrmtLcpMulti();

    return UErrFalse;
}

UErrCodeT CBsnRst::FrmtLcp(CRstCtl *aRst)
{
    UStringT mDataPath = "../../../../data";
    CRstFrmtCtl *frmtCtl = mRst->Frmt();
    CRstFrmtLcp *frmtLcp = frmtCtl->Lcp();
    UStringT lcp = mDataPath;
    UStringT elev = mDataPath;
    lcp += "/core/gda/dem/test.lcp";
    elev += "/core/gda/dem/dem1.tif";
    // lcp += "/ctgy/fmd/baiyun_m/baiyun_m.lcp";
    // elev += "/ctgy/fmd/baiyun_m/baiyun_m.tif";
    GdaProjCsCodeT projCs = GdaProjCsXian1980;
    frmtLcp->Create(&lcp, &elev, NULL, NULL, projCs);

    return UErrFalse;
}

UErrCodeT CBsnRst::FrmtLcpMulti()
{
    UIntT n = 2;
    for (int i = 0; i < n; ++i)
    {
        CHubModuleCtl *module = mHub->RegModule();
        module->SetTmpDir(&mTmpPath);
        module->Register(HubMRst);
        CRstCtl *rst = (CRstCtl*) mModule->Module(HubMRst);
        FrmtLcp(rst);
        mHub->DeregModule(module);
    }

    return UErrFalse;
}

/***** Private B *****/
