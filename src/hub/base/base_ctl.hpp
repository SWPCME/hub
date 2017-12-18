/******************************************************************************
 * $Id: base_ctl.hpp 2017-05 $
 *
 * Project:  Base.
 * Purpose:  Base control definition.
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

#ifndef BASE_CTL_HPP_INCLUDED
#define BASE_CTL_HPP_INCLUDED

#include "hub_base.h"

class CCoreCtl;
class CWrapCtl;
class CCtgyCtl;
class CBaseTmpCtl;

class HUB_LIB CBaseCtl
{
  public:
    static CBaseCtl *Base();
    UErrCodeT Init();

    CCoreCtl *Core();
    CWrapCtl *Wrap();
    CCtgyCtl *Ctgy();
    CBaseTmpCtl *Tmp();

  protected:
  private:
    CBaseCtl();
    ~CBaseCtl();

    static CBaseCtl *mBase;
    CCoreCtl *mCore;
    CWrapCtl *mWrap;
    CCtgyCtl *mCtgy;
    CBaseTmpCtl *mTmp;
};

#endif  // BASE_CTL_HPP_INCLUDED
