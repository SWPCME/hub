/******************************************************************************
 * $Id: rtk_convertctl.cpp 2017-05 $
 *
 * Project:  Rtk (Real time kinematic).
 * Purpose:  Rtk convert controler implementation.
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

#include "rtk_convertctl.hpp"

// Module.
#include "base_ctl.hpp"
#include "ctgy_ctl.hpp"
#include "earth_ctl.hpp"
#include "rtk_ctl.hpp"
#include "rtk_typectl.hpp"

/**
 * \brief Constructor.
 */
CRtkConvertCtl::CRtkConvertCtl()
{
}

/**
 * \brief Destructor.
 */
CRtkConvertCtl::~CRtkConvertCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CRtkConvertCtl::Init()
{
    CBaseCtl *baseCtl = CBaseCtl::Base();
    CCtgyCtl *ctgyCtl = baseCtl->Ctgy();
    CEarthCtl *earthCtl = ctgyCtl->Earth();
    CRtkCtl *rtkCtl = earthCtl->Rtk();
    mType = rtkCtl->Type();

    return UErrFalse;
}

/**
 * \brief Ecef To Gd.
 */
UErrCodeT CRtkConvertCtl::EcefToGd(BGeomCsGdT *aGd, const BGeomCsEcefT *aEcef)
{
    mType->CsEcefToCsGd(aGd, aEcef);

    return UErrFalse;
}

/**
 * \brief Gd To Ecef.
 */
UErrCodeT CRtkConvertCtl::GdToEcef(BGeomCsEcefT *aEcef, const BGeomCsGdT *aGd)
{
    mType->CsGdToCsEcef(aEcef, aGd);

    return UErrFalse;
}

/**
 * \brief Ecef To Vector.
 */
UErrCodeT CRtkConvertCtl::EcefToVector(NccVectorT *aVector,
                                       const BGeomCsEcefT *aEcef)
{
    UIntT size = 0;
    aVector->DimSize(&size);
    if (size != 3)
    {
        return UErrTrue;
    }

    aVector->SetValue(aEcef->x, 0);
    aVector->SetValue(aEcef->y, 1);
    aVector->SetValue(aEcef->z, 2);

    return UErrFalse;
}
