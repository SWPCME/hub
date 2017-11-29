/******************************************************************************
 * $Id: gsl_phyconst.cpp 2017-09 $
 *
 * Project:  GSL (GSL: Gnu Scientific Library).
 * Purpose:  Physical const implementation.
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

#include "gsl_phyconst.hpp"
// base
#include "base_macrodefn.hpp"
// gsl
#include "gsl_phycastro.hpp"

/**
 * \brief Constructor.
 */
CGslPhyConst::CGslPhyConst()
{
    BMD_POINTER_INIT(mAstro);
}

/**
 * \brief Destructor.
 */
CGslPhyConst::~CGslPhyConst()
{
    BMD_CLASS_DEL(mAstro);
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CGslPhyConst::Init()
{
    return UErrFalse;
}

/**
 * \brief Astronomy and astrophysics.
 */
CGslPhyCAstro *CGslPhyConst::Astro()
{
    BMD_CLASS_NEW(mAstro, CGslPhyCAstro);

    return mAstro;
}
