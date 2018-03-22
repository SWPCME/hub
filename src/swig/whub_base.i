/******************************************************************************
 * $Id: whub_ctl.i 2017-11 $
 *
 * Project:  whub (Wrap hub).
 * Purpose:  Api for base.
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
 ****************************************************************************/

%module "WHubBase"
%{
#include "base_mathtype.hpp"
%}

class BMathCsC2dT
{
  public:
    BMathCsC2dT();
    BMathCsC2dT(const UFloatT aX, const UFloatT aY);
    ~BMathCsC2dT();

    UErrCodeT SetAll(const UFloatT aX, const UFloatT aY);

    UErrCodeT SetX(const UFloatT aX);
    UErrCodeT SetY(const UFloatT aY);

    UErrCodeT All(UFloatT *aX, UFloatT *aY) const;
    UFloatT X() const;
    UFloatT Y() const;
};

class BMathCsC3dT
{
  public:
    BMathCsC3dT();
    BMathCsC3dT(const UFloatT aX, const UFloatT aY, const UFloatT aZ);
    ~BMathCsC3dT();

    UErrCodeT SetAll(const UFloatT aX, const UFloatT aY, const UFloatT aZ);
    UErrCodeT SetX(const UFloatT aX);
    UErrCodeT SetY(const UFloatT aY);
    UErrCodeT SetZ(const UFloatT aZ);

    UErrCodeT All(UFloatT *aX, UFloatT *aY, UFloatT *aZ) const;
    UFloatT X() const;
    UFloatT Y() const;
    UFloatT Z() const;
};
