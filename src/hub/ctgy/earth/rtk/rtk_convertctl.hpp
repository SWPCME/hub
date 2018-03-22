/******************************************************************************
 * $Id: rtk_convertctl.hpp 2017-05 $
 *
 * Project:  Rtk (Real time kinematic).
 * Purpose:  Rtk convert controler definition.
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

#ifndef RTK_CONVERTCTL_HPP_INCLUDED
#define RTK_CONVERTCTL_HPP_INCLUDED

#include "rtk_base.hpp"

// Module.
#include "base_geomtype.hpp"
#include "ncc/ncc_vectortype.hpp"

class CRtkTypeCtl;

class RTK_LIB CRtkConvertCtl
{
  public:
    CRtkConvertCtl();
    ~CRtkConvertCtl();

    UErrCodeT Init();
    UErrCodeT EcefToGd(BGeomCsGdT *aGd, const BGeomCsEcefT *aEcef);
    UErrCodeT GdToEcef(BGeomCsEcefT *aEcef, const BGeomCsGdT *aGd);
    UErrCodeT EcefToVector(NccVectorT *aVector, const BGeomCsEcefT *aEcef);

  protected:
  private:
    CRtkTypeCtl *mType;
};

#endif  // RTK_CONVERTCTL_HPP_INCLUDED
