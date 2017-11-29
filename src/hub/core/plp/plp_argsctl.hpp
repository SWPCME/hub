/******************************************************************************
 * $Id: plp_argsctl.hpp 2017-11 $
 *
 * Project:  PLP (PLP: PL plot).
 * Purpose:  Plp arguments controler definition.
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

#ifndef PLP_ARGSCTL_HPP_INCLUDED
#define PLP_ARGSCTL_HPP_INCLUDED

#include "plp_base.hpp"

// base
#include "base_containerdefn.hpp"

class PLP_LIB CPlpArgsCtl
{
  public:
    CPlpArgsCtl();
    ~CPlpArgsCtl();

    UErrCodeT Init();
    UErrCodeT ParseOpts(BCtnStringT *aStrCtn, const PlpParseCodeT aCode);
    UErrCodeT SetOpt(const UStringT *aOpt, const UStringT *aArg);

  protected:
  private:
};

#endif  // PLP_ARGSCTL_HPP_INCLUDED
