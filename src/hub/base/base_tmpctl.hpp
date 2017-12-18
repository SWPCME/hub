/******************************************************************************
 * $Id: base_tmpctl.hpp 2017-12 $
 *
 * Project:  Base.
 * Purpose:  Base temporary control definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017 Weiwei Huang
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

#ifndef BASE_TMPCTL_HPP_INCLUDED
#define BASE_TMPCTL_HPP_INCLUDED

#include "hub_base.h"

// cls
#include "cls/cls_filesctl.hpp"
// ust
#include "ust/ust_stringtype.hpp"

class HUB_LIB CBaseTmpCtl
{
  public:
    CBaseTmpCtl();
    ~CBaseTmpCtl();

    UErrCodeT Init();

    UStringT Dir(HubCodeT aCode);

    UErrCodeT MkDir(HubCodeT aCode);
    UErrCodeT RmDir(HubCodeT aCode);

  private:
  protected:
    CClsFilesCtl *mFs;
    UStringT mDir;
};

#endif  // BASE_TMPCTL_HPP_INCLUDED
