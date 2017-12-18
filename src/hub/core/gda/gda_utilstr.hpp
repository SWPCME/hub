/******************************************************************************
 * $Id: gda_utilstr.hpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Utils translate definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-07 ~ 2017, Weiwei Huang
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

#ifndef GDA_UTILSTR_HPP_INCLUDED
#define GDA_UTILSTR_HPP_INCLUDED

#include "gda_base.h"

// gda
class CGdaTrVtr;
class CGdaTrRst;

class GDA_LIB CGdaUtilsTr
{
  public:
    CGdaUtilsTr();
    ~CGdaUtilsTr();

    UErrCodeT Init();
    CGdaTrVtr *Vtr();
    CGdaTrRst *Rst();

  protected:
  private:
    CGdaTrVtr *mVtr;
    CGdaTrRst *mRst;
};

#endif  // GDA_UTILSTR_HPP_INCLUDED
