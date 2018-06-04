/******************************************************************************
 * $Id: bsn_pyc.hpp 2018-03 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test pyc api definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-03 ~ 2018, Weiwei Huang
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

#ifndef BSN_PYC_HPP_INCLUDED
#define BSN_PYC_HPP_INCLUDED

#include "bsn_base.hpp"

class CHubCtl;
class CHubModuleCtl;
class CPycCtl;

class BSN_LIB CBsnPyc
{
  public:
    CBsnPyc();
    ~CBsnPyc();

    UErrCodeT Init();
    UErrCodeT Test();

  protected:
  private:
    UErrCodeT InitPointer();

    UErrCodeT Mod();
    UErrCodeT Obj();
    UErrCodeT ObjList();

    CHubCtl *mHub;
    CHubModuleCtl *mModule;
    CPycCtl *mPyc;
};

#endif  // BSN_PYC_HPP_INCLUDED
