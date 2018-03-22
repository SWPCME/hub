/******************************************************************************
 * $Id: rst_frmtctl.hpp 2017-12 $
 *
 * Project:  RST (RST: Raster data process).
 * Purpose:  RST format controler definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017, Weiwei Huang
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

#ifndef RST_FRMTCTL_HPP_INCLUDED
#define RST_FRMTCTL_HPP_INCLUDED

#include "rst_base.hpp"

class CRstCtl;
class CRstFrmtLcp;

class RST_LIB CRstFrmtCtl
{
  public:
    CRstFrmtCtl(CRstCtl *aRst);
    ~CRstFrmtCtl();

    UErrCodeT Init();
    CRstCtl *Up();
    CRstFrmtLcp *Lcp();

  protected:
  private:
    CRstCtl *mRst;
    CRstFrmtLcp *mLcp;
};

#endif  // RST_FRMTCTL_HPP_INCLUDED
