/******************************************************************************
 * $Id: plp_ctl.hpp 2017-11 $
 *
 * Project:  PLP (PLP: PL plot).
 * Purpose:  Plp controler definition.
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

#ifndef PLP_CTL_HPP_INCLUDED
#define PLP_CTL_HPP_INCLUDED

#include "plp_base.hpp"

class CPlpTypeCtl;
class CPlpCoreCtl;
class CPlpArgsCtl;
class CPlpVporCtl;
class CPlpSymCtl;
class CPlpLineCtl;

class PLP_LIB CPlpCtl
{
  public:
    CPlpCtl();
    ~CPlpCtl();

    UErrCodeT Init();
    CPlpTypeCtl *Type();
    CPlpCoreCtl *Core();
    CPlpArgsCtl *Args();
    CPlpVporCtl *Vpor();
    CPlpSymCtl *Sym();
    CPlpLineCtl *Line();

  protected:
  private:
    CPlpTypeCtl *mType;
    CPlpCoreCtl *mCore;
    CPlpArgsCtl *mArgs;
    CPlpVporCtl *mVpor;
    CPlpSymCtl *mSym;
    CPlpLineCtl *mLine;
};

#endif  // PLP_CTL_HPP_INCLUDED
