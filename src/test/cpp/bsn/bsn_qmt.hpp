/******************************************************************************
 * $Id: bsn_qmt.hpp 2018-03 $
 *
 * Project:  Business Logic library.
 * Purpose:  Test qmt api definition.
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

#ifndef BSN_QMT_HPP_INCLUDED
#define BSN_QMT_HPP_INCLUDED

#include "bsn_base.hpp"

class CHubCtl;
class CHubModuleCtl;
class CQmtCtl;

class BSN_LIB CBsnQmt
{
  public:
    CBsnQmt();
    ~CBsnQmt();

    UErrCodeT Init();
    UErrCodeT Test();

  protected:
  private:
    CHubCtl *mHub;
    CHubModuleCtl *mModule;
    CQmtCtl *mQmt;
};

#endif  // BSN_QMT_HPP_INCLUDED
