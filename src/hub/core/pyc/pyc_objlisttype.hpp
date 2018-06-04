/******************************************************************************
 * $Id: pyc_objlist.hpp 2018-03 $
 *
 * Project:  PYC(PYC: Python c library).
 * Purpose:  Pyc object list definition.
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
 ****************************************************************************/

#ifndef PYC_OBJLISTTYPE_HPP_INCLUDED
#define PYC_OBJLISTTYPE_HPP_INCLUDED

#include "pyc_base.hpp"

// ust
class UStringT;

// pyc
class CPycTypeObjList;
class PycObjT;

class PYC_LIB PycObjListT
{
  public:
    PycObjListT(PycObjT *aObj);
    ~PycObjListT();

    UErrCodeT Init();
    PycObjListHT Handle();
    UErrCodeT SetHandle(PycObjListHT aListH);
    UErrCodeT Item(UStringT *aVal, UIntT aId);

  protected:
  private:
    CPycTypeObjList *mList;
    PycObjListHT mListH;
};

#endif  // PYC_OBJLISTTYPE_HPP_INCLUDED
