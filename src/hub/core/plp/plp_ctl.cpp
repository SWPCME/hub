/******************************************************************************
 * $Id: plp_ctl.hpp 2017-11 $
 *
 * Project:  PLP (PLP: PL plot).
 * Purpose:  Plp controler implementation.
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

#include "plp_ctl.hpp"

// base
#include "base_macrodefn.hpp"

// plp
#include "plp_typectl.hpp"
#include "plp_corectl.hpp"
#include "plp_argsctl.hpp"
#include "plp_vporctl.hpp"
#include "plp_symctl.hpp"
#include "plp_linectl.hpp"

/**
 * \brief Constructor.
 */
CPlpCtl::CPlpCtl()
{
    BMD_POINTER_INIT(mType);
    BMD_POINTER_INIT(mCore);
    BMD_POINTER_INIT(mArgs);
    BMD_POINTER_INIT(mVpor);
    BMD_POINTER_INIT(mSym);
    BMD_POINTER_INIT(mLine);
}

/**
 * \brief Destructor.
 */
CPlpCtl::~CPlpCtl()
{
    BMD_CLASS_DEL(mType);
    BMD_CLASS_DEL(mCore);
    BMD_CLASS_DEL(mArgs);
    BMD_CLASS_DEL(mVpor);
    BMD_CLASS_DEL(mSym);
    BMD_CLASS_DEL(mLine);
}

/**
 * \brief Initialize.
 */
UErrCodeT CPlpCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Type.
 */
CPlpTypeCtl *CPlpCtl::Type()
{
    BMD_CLASS_NEW(mType, CPlpTypeCtl);

    return mType;
}

/**
 * \brief Core.
 */
CPlpCoreCtl *CPlpCtl::Core()
{
    BMD_CLASS_NEW(mCore, CPlpCoreCtl);

    return mCore;
}

/**
 * \brief Arguments.
 * Extract & process command flags.
 */
CPlpArgsCtl *CPlpCtl::Args()
{
    BMD_CLASS_NEW(mArgs, CPlpArgsCtl);

    return mArgs;
}

/**
 * \brief Viewport.
 */
CPlpVporCtl *CPlpCtl::Vpor()
{
    BMD_CLASS_NEW(mVpor, CPlpVporCtl);

    return mVpor;
}

/**
 * \brief Symbol.
 */
CPlpSymCtl *CPlpCtl::Sym()
{
    BMD_CLASS_NEW(mSym, CPlpSymCtl);

    return mSym;
}

/**
 * \brief Line.
 */
CPlpLineCtl *CPlpCtl::Line()
{
    BMD_CLASS_NEW(mLine, CPlpLineCtl);

    return mLine;
}
