/******************************************************************************
 * $Id: bsn_plp.hpp 2017-11 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test plp api implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-11 ~ 2017, Weiwei Huang
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

#include "bsn_plp.hpp"

// base
#include "base_macrodefn.hpp"

// plp
#include "plp_ctl.hpp"
#include "plp_corectl.hpp"
#include "plp_vporctl.hpp"
#include "plp_symctl.hpp"
#include "plp_linectl.hpp"

/**
 * \brief Constructor.
 */
CBsnPlp::CBsnPlp()
{
    BMD_POINTER_INIT(mPlp);
}

/**
 * \brief Destructor.
 */
CBsnPlp::~CBsnPlp()
{
    BMD_POINTER_INIT(mPlp);
}

/**
 * \brief Initialize.
 */
UErrCodeT CBsnPlp::Init()
{
    BMD_MODULE(mPlp, CPlpCtl, HubMPlp);

    return UErrFalse;
}

/**
 * \brief Test.
 */
UErrCodeT CBsnPlp::Test()
{
    ExportFile();

    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief Export file.
 */
UErrCodeT CBsnPlp::ExportFile()
{
    CPlpCoreCtl *coreCtl = mPlp->Core();
    CPlpVporCtl *vporCtl = mPlp->Vpor();
    CPlpSymCtl *symCtl = mPlp->Sym();
    CPlpLineCtl *lineCtl = mPlp->Line();

    PlpDevCodeT dev = PlpDevPng;
    coreCtl->InitOpt();

    UFloatT xMin = 0;
    UFloatT xMax = 1;
    UFloatT yMin = 0;
    UFloatT yMax = 100;
    UFloatT just = 0;
    UFloatT axis = 0;
    vporCtl->Env(xMin, xMax, yMin, yMax, just, axis);

    UStringT xLabel = "x";
    UStringT yLabel = "y";
    UStringT tLabel = "Test";
    symCtl->Lab(&xLabel, &yLabel, &tLabel);

    // lineCtl->Line();

    UIntT curStrm = 0;
    coreCtl->CurStrm(&curStrm);

    UIntT strm = 0;
    coreCtl->MkStrm(&strm);

    UStringT fileName = "../../data/core/plp/1.png";
    coreCtl->SetFName(&fileName);

    coreCtl->SetDev(dev);

    coreCtl->CpStrm(curStrm, 0);
    coreCtl->RePlot();
    coreCtl->EndCurStrm();
    coreCtl->SetStrm(curStrm);

    coreCtl->EndAllStrm();

    return UErrFalse;
}

/***** Private B *****/
