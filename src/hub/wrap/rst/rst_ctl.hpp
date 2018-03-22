/******************************************************************************
 * $Id: rst_ctl.hpp 2017-08 $
 *
 * Project:  RST (RST: Raster data process).
 * Purpose:  RST controler definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-08 ~ 2017, Weiwei Huang
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

#ifndef RST_CTL_HPP_INCLUDED
#define RST_CTL_HPP_INCLUDED

#include "rst_base.hpp"

// hub
class CHubModuleCtl;
// rst
class CRstUtilCtl;
class CRstFrmtCtl;

class RST_LIB CRstCtl
{
  public:
    CRstCtl(CHubModuleCtl *aModule);
    ~CRstCtl();

    UErrCodeT Init();
    CHubModuleCtl *Up();
    CRstUtilCtl *Util();
    CRstFrmtCtl *Frmt();

  protected:
  private:
    UErrCodeT InitPointer();

    CHubModuleCtl *mModule;
    CRstUtilCtl *mUtil;
    CRstFrmtCtl *mFrmt;
};

#endif  // RST_CTL_HPP_INCLUDED
