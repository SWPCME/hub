/******************************************************************************
 * $Id: bsn_qmt.hpp 2018-03 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test qmt api implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-03 ~ 2018, Weiwei Huang
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

#include "bsn_qmt.hpp"

// hub
#include "hub_ctl.hpp"
#include "hub_modulectl.hpp"
// ust
#include "ust_stringtype.hpp"
// qmt
#include "qmt_ctl.hpp"
#include "qmt_terrtile.hpp"

/**
 * \brief Constructor.
 */
CBsnQmt::CBsnQmt()
{
    BMD_POINTER_INIT(mHub);
    BMD_POINTER_INIT(mModule);
    BMD_POINTER_INIT(mQmt);
    mHub = CHubCtl::Hub();
    mModule = mHub->RegModule();
    UStringT tmp = "./.tmp";
    mModule->SetTmpDir(&tmp);
}

/**
 * \brief Destructor.
 */
CBsnQmt::~CBsnQmt()
{
    BMD_POINTER_INIT(mQmt);
    mHub->DeregModule(mModule);
    BMD_POINTER_INIT(mModule);
    BMD_POINTER_INIT(mHub);
}

/**
 * \brief Initialize.
 */
UErrCodeT CBsnQmt::Init()
{
    mModule->Register(HubMQmt);
    mQmt = (CQmtCtl *) mModule->Module(HubMQmt);

    return UErrFalse;
}

/**
 * \brief Test.
 */
UErrCodeT CBsnQmt::Test()
{
    CQmtTerrTile *terrTile = mQmt->TerrTile();
    terrTile->Decode();

    return UErrFalse;
}
