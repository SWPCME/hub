/******************************************************************************
 * $Id: cut_ctl.hpp 2017-06 $
 *
 * Project:  CUT (CUT: Client-side URL Transfer).
 * Purpose:  Cut controler definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017, Weiwei Huang
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

#ifndef CUT_CTL_HPP_INCLUDED
#define CUT_CTL_HPP_INCLUDED

#include "cut_base.hpp"

class CCutTypeCtl;
class CCutEasysCtl;
class CCutMultisCtl;
class CCutSlistsCtl;

class CUT_LIB CCutCtl
{
  public:
    CCutCtl();
    ~CCutCtl();

    UErrCodeT Init();
    CCutTypeCtl *Type();
    CCutEasysCtl *Easys();
    CCutMultisCtl *Multis();
    CCutSlistsCtl *Slists();

  protected:
  private:
    UErrCodeT GInit();
    UErrCodeT GCleanup();

    CCutTypeCtl *mType;
    CCutEasysCtl *mEasys;
    CCutMultisCtl *mMultis;
    CCutSlistsCtl *mSlists;
};

#endif  // CUT_CTL_HPP_INCLUDED
