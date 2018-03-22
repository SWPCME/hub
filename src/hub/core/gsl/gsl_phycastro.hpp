/******************************************************************************
 * $Id: gsl_phycastro.hpp 2017-09 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Physical const with astronomy and astrophysics definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-09 ~ 2017, Weiwei Huang
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

#ifndef GSL_PHYCASTRO_HPP_INCLUDED
#define GSL_PHYCASTRO_HPP_INCLUDED

#include "gsl_base.hpp"

class GSL_LIB CGslPhyCAstro
{
  public:
    CGslPhyCAstro();
    ~CGslPhyCAstro();

    UErrCodeT Init();
    UFloatT G();
    UFloatT Au();

  protected:
  private:
};

#endif  // GSL_PHYCASTRO_HPP_INCLUDED
