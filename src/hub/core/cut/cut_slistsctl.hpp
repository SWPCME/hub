/******************************************************************************
 * $Id: cut_slistsctl.hpp 2017-06 $
 *
 * Project:  CUT (CUT: Client-side URL Transfer).
 * Purpose:  String to linked list set controler definition.
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

#ifndef CUT_SLISTSCTL_HPP_INCLUDED
#define CUT_SLISTSCTL_HPP_INCLUDED

#include "cut_base.hpp"

// Ust.
#include "ust/ust_stringtype.hpp"
#include "ust/ust_containertype.hpp"

class CCutSlistCtl;

class CUT_LIB CCutSlistsCtl
{
  public:
    CCutSlistsCtl();
    ~CCutSlistsCtl();

    UErrCodeT Init();
    CCutSlistCtl *Open(UStringT *aName);
    UErrCodeT Close(UStringT *aName);
    UErrCodeT CleanupAll();

  protected:
  private:
    typedef UContainerT<CCutSlistCtl*, UStringT> MSlistHT;
    typedef UIteratorT<CCutSlistCtl*, UStringT> SlistHItT;

    MSlistHT mMSlistH;
};

#endif  // CUT_SLISTSCTL_HPP_INCLUDED
