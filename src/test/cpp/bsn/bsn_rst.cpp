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
    CRstFrmtCtl *frmtCtl = mRst->Frmt();
    CRstFrmtLcp *frmtLcp = frmtCtl->Lcp();
    UStringT lcp = "../../../data/core/gda/dem/test.lcp";
    UStringT elev = "../../../data/core/gda/dem/dem1.tif";
    frmtLcp->Create(&lcp, &elev, NULL, NULL);

    return UErrFalse;
}
