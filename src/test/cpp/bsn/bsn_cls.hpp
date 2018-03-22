/******************************************************************************
 * $Id: bsn_cls.hpp 2017-07 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test cls control api definition.
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

#ifndef BSN_CLS_HPP_INCLUDED
#define BSN_CLS_HPP_INCLUDED

#include "bsn_base.hpp"

// hub
class CHubCtl;
class CHubModuleCtl;
// cls
class CClsCtl;

class BSN_LIB CBsnCls
{
  public:
    CBsnCls();
    ~CBsnCls();

    UErrCodeT Init();
    UErrCodeT Test();

  protected:
  private:
    CHubCtl *mHub;
    CHubModuleCtl *mModule;
    CClsCtl *mCls;
};

#endif  // BSN_CLS_HPP_INCLUDED
