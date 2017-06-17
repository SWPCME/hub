/******************************************************************************
 * $Id: rtk_tidectl.cpp 2017-05 $
 *
 * Project:  Rtk.
 * Purpose:  Rtk tide ctl.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017 Weiwei Huang
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

#include "rtk_tidectl.hpp"

// Rtklib.
#include "rtklib.h"

// Module.
#include "base_ctl.hpp"
#include "ctgy_ctl.hpp"
#include "earth_ctl.hpp"
#include "rtk_ctl.hpp"
#include "rtk_typectl.hpp"

/**
 * \brief Constructor.
 */
CRtkTideCtl::CRtkTideCtl()
{
}

/**
 * \brief Destructor.
 */
CRtkTideCtl::~CRtkTideCtl()
{
}

/**
 * \brief Initial.
 */
UErrCodeT CRtkTideCtl::Init()
{
    // Base.
    CBaseCtl *baseCtl = CBaseCtl::Base();
    CCtgyCtl *ctgyCtl = baseCtl->Ctgy();
    CEarthCtl *earthCtl = ctgyCtl->Earth();
    CRtkCtl *rtkCtl = earthCtl->Rtk();
    mType = rtkCtl->Type();

    return UErrFalse;
}

/**
 * \brief Solid.
 */
UErrCodeT CRtkTideCtl::Solid(BGeomCsEcefT *aOutEcef, const BGeomCsGdT *aInGd,
                             const BTimeTmT *aTm)
{
    gtime_t gtm;
    mType->BTmToGTm(&gtm, aTm);
    double ecef[3];
    mType->CsGdToCsEcef(ecef, aInGd);
    double outEcef[3];
    tidedisp(gtm, ecef, 1, NULL, NULL, outEcef);
    mType->ToCsEcef(aOutEcef, outEcef);

    return UErrFalse;
}
