/******************************************************************************
 * $Id: vtr_frmtgjson.hpp 2017-12 $
 *
 * Project:  Vector Info Process.
 * Purpose:  Format for GeoJSON definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017, Weiwei Huang
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

#ifndef VTR_FRMTGJSON_HPP_INCLUDED
#define VTR_FRMTGJSON_HPP_INCLUDED

#include "ust/ust_stringtype.hpp"

#include "vtr_base.hpp"

class VTR_LIB CVtrFrmtGjson
{
  public:
    CVtrFrmtGjson();
    ~CVtrFrmtGjson();

    UErrCodeT Init();
    UErrCodeT ToFile(const UStringT *aFile, const UStringT *aStr);
    UErrCodeT ToStr(UStringT *aStr, const UStringT *aFile);

  protected:
  private:
};

#endif  // VTR_FRMTGJSON_HPP_INCLUDED
