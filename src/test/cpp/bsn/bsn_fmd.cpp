/******************************************************************************
 * $Id: bsn_fmd.hpp 2017-06 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test fmd control api implementation.
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

#include "bsn_fmd.hpp"

// base
#include "base_macrodefn.hpp"
// fmd
#include "fmd_ctl.hpp"
#include "fmd_filectl.hpp"
#include "fmd_fileload.hpp"
#include "fmd_filewrite.hpp"
#include "fmd_burnctl.hpp"
#include "fmd_burntime.hpp"

/**
 * \brief Constructor.
 */
CBsnFmd::CBsnFmd()
{
    BMD_POINTER_INIT(mFmd);
}

/**
 * \brief Destructor.
 */
CBsnFmd::~CBsnFmd()
{
    BMD_POINTER_INIT(mFmd);
}

/**
 * \brief Initilize.
 */
UErrCodeT CBsnFmd::Init()
{
    BMD_MODULE(mFmd, CFmdCtl, HubMFmd);

    return UErrFalse;
}

/**
 * \brief Test.
 */
UErrCodeT CBsnFmd::Test()
{
    CFmdFileCtl *fileCtl = mFmd->File();
    CFmdFileLoad *fileLoad = fileCtl->Load();
    CFmdFileWrite *fileWrite = fileCtl->Write();
    CFmdBurnCtl *burnCtl = mFmd->Burn();
    CFmdBurnTime *burnTime = burnCtl->Time();

    // fileLoad->All();
    // fileWrite->All();

    return UErrFalse;
}
