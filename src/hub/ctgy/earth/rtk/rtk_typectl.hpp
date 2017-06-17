/******************************************************************************
 * $Id: rtk_typectl.hpp 2017-05 $
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

#ifndef RTK_TYPECTL_HPP_INCLUDED
#define RTK_TYPECTL_HPP_INCLUDED

#include "rtk_base.hpp"
#include "rtklib.h"
// Base
#include "base_timetype.hpp"
#include "base_geomtype.hpp"

class RTK_LIB CRtkTypeCtl
{
  public:
    CRtkTypeCtl();
    ~CRtkTypeCtl();

    UErrCodeT Init();

    // Time.
    UErrCodeT ToTm(double *aTm, const BTimeTmT *aBTm);
    UErrCodeT BTmToGTm(gtime_t *aGTm, const BTimeTmT *aBTm);

    // Coordinate system.
    UErrCodeT ToCsEcef(double *aEcef, const BGeomCsEcefT *aBEcef);
    UErrCodeT ToCsEcef(BGeomCsEcefT *aBEcef, const double *aEcef);
    UErrCodeT ToCsGd(double *aGs, const BGeomCsGdT *aBGd);
    UErrCodeT ToCsGd(BGeomCsGdT *aBGd, const double *aGd);
    UErrCodeT CsGdToCsEcef(double *aEcef, const BGeomCsGdT *aGd);
    UErrCodeT CsGdToCsEcef(BGeomCsEcefT *aEcef, const BGeomCsGdT *aGd);
    UErrCodeT CsEcefToCsGd(double *aGd, const BGeomCsEcefT *aEcef);
    UErrCodeT CsEcefToCsGd(BGeomCsGdT *aGd, const BGeomCsEcefT *aEcef);

  protected:
  private:
};

#endif  // RTK_TYPECTL_HPP_INCLUDED
