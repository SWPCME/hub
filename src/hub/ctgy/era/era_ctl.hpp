/******************************************************************************
 * $Id: era_ctl.hpp 2017-11 $
 *
 * Project:  ERA (ERA: Essential Routines for Fundamental Astronomy).
 * Purpose:  Era controler definition.
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

#ifndef ERA_CTL_HPP_INCLUDED
#define ERA_CTL_HPP_INCLUDED

#include "era_base.hpp"

class CEraTscCtl;

class ERA_LIB CEraCtl
{
  public:
    CEraCtl();
    ~CEraCtl();

    UErrCodeT Init();
    CEraTscCtl *Tsc();

 protected:
  private:
    CEraTscCtl *mTsc;
};

#endif  // ERA_CTL_HPP_INCLUDED
