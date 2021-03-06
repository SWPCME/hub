/******************************************************************************
 * $Id: bsn_era.hpp 2017-11 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test era api definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-06 ~ 2017, Weiwei Huang
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

#ifndef BSN_ERA_HPP_INCLUDED
#define BSN_ERA_HPP_INCLUDED

#include "bsn_base.hpp"

class CEraCtl;

class BSN_LIB CBsnEra
{
  public:
    CBsnEra();
    ~CBsnEra();

    UErrCodeT Init();
    UErrCodeT Test();

  protected:
  private:
    CEraCtl *mEra;
};

#endif  // BSN_ERA_HPP_INCLUDED
