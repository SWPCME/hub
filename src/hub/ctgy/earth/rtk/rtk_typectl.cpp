/******************************************************************************
 * $Id: rtk_typectl.cpp 2017-05 $
 *
 * Project:  Rtk.
 * Purpose:  Rtk type ctl.
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

#include "rtk_typectl.hpp"
#include "rtklib.h"

/**
 * \brief Constructor.
 */
CRtkTypeCtl::CRtkTypeCtl()
{
}

/**
 * \brief Destructor.
 */
CRtkTypeCtl::~CRtkTypeCtl()
{
}

/**
 * \brief Initial.
 */
UErrCodeT CRtkTypeCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief To time.
 */
UErrCodeT CRtkTypeCtl::ToTm(double *aTm, const BTimeTmT *aBTm)
{
    aTm[0] = aBTm->year;
    aTm[1] = aBTm->mon;
    aTm[2] = aBTm->mday;
    aTm[3] = aBTm->hour;
    aTm[4] = aBTm->min;
    aTm[5] = aBTm->sec;

    return UErrFalse;
}

/**
 * \brief BTm to GTm.
 */
UErrCodeT CRtkTypeCtl::BTmToGTm(gtime_t *aGTm, const BTimeTmT *aBTm)
{
    double tm[6];
    ToTm(tm, aBTm);
    *aGTm = epoch2time(tm);

    return UErrFalse;
}

/**
 * \brief To ecef.
 */
UErrCodeT CRtkTypeCtl::ToCsEcef(double *aEcef, const BGeomCsEcefT *aBEcef)
{
    aEcef[0] = aBEcef->x;
    aEcef[1] = aBEcef->y;
    aEcef[2] = aBEcef->z;

    return UErrFalse;
}

/**
 * \brief To ecef.
 */
UErrCodeT CRtkTypeCtl::ToCsEcef(BGeomCsEcefT *aBEcef, const double *aEcef)
{
    aBEcef->x = aEcef[0];
    aBEcef->y = aEcef[1];
    aBEcef->z = aEcef[2];

    return UErrFalse;
}

/**
 * \brief To geodetic datum.
 */
UErrCodeT CRtkTypeCtl::ToCsGd(double *aGd, const BGeomCsGdT *aBGd)
{
    aGd[0] = aBGd->lat;
    aGd[1] = aBGd->lon;
    aGd[2] = aBGd->h;

    return UErrFalse;
}

/**
 * \brief To geodetic datum.
 */
UErrCodeT CRtkTypeCtl::ToCsGd(BGeomCsGdT *aBGd, const double *aGd)
{
    aBGd->lat = aGd[0];
    aBGd->lon = aGd[1];
    aBGd->h = aGd[2];

    return UErrFalse;
}

/**
 * \brief CsGd To CsEcef.
 */
UErrCodeT CRtkTypeCtl::CsGdToCsEcef(double *aEcef, const BGeomCsGdT *aGd)
{
    double gd[3];
    ToCsGd(gd, aGd);
    pos2ecef(gd, aEcef);

    return UErrFalse;
}

/**
 * \brief CsGd to CsEcef.
 */
UErrCodeT CRtkTypeCtl::CsGdToCsEcef(BGeomCsEcefT *aEcef, const BGeomCsGdT *aGd)
{
    double ecef[3];
    CsGdToCsEcef(ecef, aGd);
    ToCsEcef(aEcef, ecef);

    return UErrFalse;
}

/**
 * \brief CsEcef to CsGd.
 */
UErrCodeT CRtkTypeCtl::CsEcefToCsGd(double *aGd, const BGeomCsEcefT *aEcef)
{
    double ecef[3];
    ToCsEcef(ecef, aEcef);
    ecef2pos(ecef, aGd);

    return UErrFalse;
}

/**
 * \brief CsEcef to CsGd.
 */
UErrCodeT CRtkTypeCtl::CsEcefToCsGd(BGeomCsGdT *aGd, const BGeomCsEcefT *aEcef)
{
    double gd[3];
    CsEcefToCsGd(gd, aEcef);
    ToCsGd(aGd, gd);

    return UErrFalse;
}
