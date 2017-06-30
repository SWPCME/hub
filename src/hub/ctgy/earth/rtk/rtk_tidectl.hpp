/******************************************************************************
 * $Id: rtk_tidectl.hpp 2017-05 $
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

#ifndef RTK_TIDECTL_HPP_INCLUDED
#define RTK_TIDECTL_HPP_INCLUDED

#include "rtk_base.hpp"
#include "base_timetype.hpp"
#include "base_geomtype.hpp"

class CRtkTypeCtl;

class RTK_LIB CRtkTideCtl
{
  public:
    CRtkTideCtl();
    ~CRtkTideCtl();

    UErrCodeT Init();
    UErrCodeT Solid(BGeomCsEcefT *aOutEcef, const BGeomCsGdT *aOutGd,
                    const BTimeTmT *aTm);
    UErrCodeT Ocean(BGeomCsEcefT *aOutEcef, const BGeomCsGdT *aOutGd,
                    const BTimeTmT *aTm);

  protected:
  private:
    typedef enum
    {
        RtkTideSolid = 1,
        RtkTideOcean = 2,
    } RtkTideCodeT;

    UErrCodeT Tide(BGeomCsEcefT *aOutEcef, const BGeomCsGdT *aOutGd,
                   const BTimeTmT *aTm, RtkTideCodeT aCode);

    CRtkTypeCtl *mType;
};

#endif  // RTK_TIDECTL_HPP_INCLUDED
