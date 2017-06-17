/******************************************************************************
 * $Id: bsn_rtk.cpp 2017-05 $
 *
 * Project:  Bsn.
 * Purpose:  Rtk test.
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

#include "bsn_rtk.hpp"

// Base.
#include "base_mathtype.hpp"
#include "base_geomtype.hpp"

// Hub Module.
#include "hub_ctl.hpp"
// Cls.
#include "cls_ctl.hpp"
#include "cls_ioctl.hpp"
// Gsl.
#include "gsl_ctl.hpp"
// Rtk.
#include "rtk_ctl.hpp"
#include "rtk_convertctl.hpp"
#include "rtk_tidectl.hpp"

CBsnRtk::CBsnRtk()
{
}

CBsnRtk::~CBsnRtk()
{
}

UErrCodeT CBsnRtk::Init()
{
    mHub = CHubCtl::Hub();
    mHub->Register(HubMRtk);
    mRtk = (CRtkCtl*) mHub->Module(HubMRtk);
    mHub->Register(HubMCls);
    mHub->Register(HubMGsl);

    return UErrFalse;
}

UErrCodeT CBsnRtk::Test()
{
    CRtkConvertCtl *convertCtl = mRtk->Convert();
    CRtkTideCtl *tideCtl = mRtk->Tide();
    CClsCtl *cls = (CClsCtl*) mHub->Module(HubMCls);
    CClsIoCtl *ioCtl = cls->Io();
    CGslCtl *gslCtl = (CGslCtl*) mHub->Module(HubMGsl);

    BGeomCsGdT gd;
    // gd.lon = 113.23;
    // gd.lat = 23.16;
    gd.lon = 90;
    gd.lat = 0;
    // gd.h = -BGEOM_EARTH_R;
    gd.h = 0;
    BGeomCsEcefT inEcef;
    convertCtl->GdToEcef(&inEcef, &gd);
    ioCtl->PrintF("X_disp = %8.5lf, ", inEcef.x);
    ioCtl->PrintF("Y_disp = %8.5lf, ", inEcef.y);
    ioCtl->PrintF("Z_disp = %8.5lf\n", inEcef.z);
    ioCtl->PrintF("r = %8.5lf\n", BGEOM_EARTH_R);

    BTimeTmT tm;
    tm.year = 2017;
    tm.mon = 1;
    tm.mday = 1;
    tm.hour = 0;
    tm.min = 0;
    tm.sec = 0;

    const int num = 24;
    BGeomCsEcefT ecef[num];
    BGeomCsGdT outGd[num];
    for (int i = 0; i < num; i++)
    {
        tm.hour += i;
        tideCtl->Solid(&ecef[i], &gd, &tm);
        // ioCtl->PrintF("%d: ", i);
        // ioCtl->PrintF("X_disp = %8.5f, ", ecef[i].x * 1000);
        // ioCtl->PrintF("Y_disp = %8.5f, ", ecef[i].y * 1000);
        // ioCtl->PrintF("Z_disp = %8.5f\n", ecef[i].z * 1000);
        convertCtl->EcefToGd(&outGd[i], &ecef[i]);
        // ioCtl->PrintF("Lo_disp = %8.5f, ", outGd[i].lon);
        // ioCtl->PrintF("La_disp = %8.5f, ", outGd[i].lat);
        // ioCtl->PrintF("H_disp = %8.5f\n", outGd[i].h);
        if (i != 0)
        {
            UFloatT x = (ecef[i].x - ecef[i-1].x) * 1000;
            UFloatT y = (ecef[i].y - ecef[i-1].y) * 1000;
            UFloatT z = (ecef[i].z - ecef[i-1].z) * 1000;
            UFloatT a = 2 * (x * x + y * y + z * z);
            // ioCtl->PrintF("a = %lf \n", a);
        }
    }

    return UErrFalse;
}
