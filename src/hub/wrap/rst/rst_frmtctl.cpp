/******************************************************************************
 * $Id: rst_frmtctl.hpp 2017-12 $
 *
 * Project:  RST (RST: Raster data process).
 * Purpose:  RST format controler implementation.
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

#include "rst_frmtctl.hpp"

// base
#include "base_macrodefn.hpp"

// rst
#include "rst_frmtlcp.hpp"

/**
 * \brief Constructor.
 */
CRstFrmtCtl::CRstFrmtCtl(CRstCtl *aRst)
{
    BMD_POINTER_INIT(mRst);
    BMD_POINTER_INIT(mLcp);
    mRst = aRst;
}

/**
 * \brief Destructor.
 */
CRstFrmtCtl::~CRstFrmtCtl()
{
    BMD_CLASS_DEL(mLcp);
    BMD_POINTER_INIT(mRst);
}

/**
 * \brief Initialize.
 */
UErrCodeT CRstFrmtCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Up.
 */
CRstCtl *CRstFrmtCtl::Up()
{
    return mRst;
}

/**
 * \brief Landscape.
 */
CRstFrmtLcp *CRstFrmtCtl::Lcp()
{
    BMD_CLASS_NEW_A_1(mLcp, CRstFrmtLcp, this);

    return mLcp;
}
