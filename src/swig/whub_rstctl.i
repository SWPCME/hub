/******************************************************************************
 * $Id: whub_rstctl.i 2017-12 $
 *
 * Project:  whub (Wrap hub).
 * Purpose:  Api for rst.
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

%module "WHubRst"
%{
#include "rst/rst_ctl.hpp"
#include "rst/rst_frmtctl.hpp"
#include "rst/rst_frmtlcp.hpp"
%}

class CRstCtl
{
  public:
    CRstCtl(CHubModuleCtl *aModule);
    ~CRstCtl();

    UErrCodeT Init();
    CRstUtilCtl *Util();
    CRstFrmtCtl *Frmt();
};

class CRstFrmtCtl
{
  public:
    CRstFrmtCtl(CRstCtl *aRst);
    ~CRstFrmtCtl();

    UErrCodeT Init();
    CRstFrmtLcp *Lcp();
};

class CRstFrmtLcp
{
  public:
    CRstFrmtLcp(CRstFrmtCtl *aFrmt);
    ~CRstFrmtLcp();

    UErrCodeT Init();
    UErrCodeT Create(const UStringT *aLcp, const UStringT *aElev,
                     const UStringT *aFm, const UStringT *aCt,
                     const GdaProjCsCodeT aCode);
};
