/******************************************************************************
 * $Id: gsl_phyctl.hpp 2017-09 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Physical controler implementation.
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

#include "gsl_phyctl.hpp"
// base
#include "base_macrodefn.hpp"
// gsl
#include "gsl_phyconst.hpp"

/**
 * \brief Constructor.
 */
CGslPhyCtl::CGslPhyCtl()
{
    BMD_POINTER_INIT(mConst);
}

/**
 * \brief Destructor.
 */
CGslPhyCtl::~CGslPhyCtl()
{
    BMD_CLASS_DEL(mConst);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGslPhyCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Constants.
 */
CGslPhyConst *CGslPhyCtl::Const()
{
    BMD_CLASS_NEW(mConst, CGslPhyConst);

    return mConst;
}
