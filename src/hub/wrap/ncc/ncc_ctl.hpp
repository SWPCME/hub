/******************************************************************************
 * $Id: ncc_ctl.hpp 2017-06 $
 *
 * Project:  NCC (NCC: Numerical Computing Collection).
 * Purpose:  Ncc controler definition.
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

#ifndef NCC_CTL_HPP_INCLUDED
#define NCC_CTL_HPP_INCLUDED

#include "ncc_base.hpp"

class CNccVectorCtl;

class NCC_LIB CNccCtl
{
  public:
    CNccCtl();
    ~CNccCtl();

    UErrCodeT Init();
    CNccVectorCtl *Vector();

  protected:
  private:
    CNccVectorCtl *mVector;
};

#endif  // NCC_CTL_HPP_INCLUDED
