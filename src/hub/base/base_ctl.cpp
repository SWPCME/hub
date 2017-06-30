/******************************************************************************
 * $Id: base_ctl.hpp 2017-05 $
 *
 * Project:  Base.
 * Purpose:  Base control implemetation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017 Weiwei Huang
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
 *****************************************************************************/

#include "base_ctl.hpp"

// Module.
#include "core_ctl.hpp"
#include "wrap_ctl.hpp"
#include "ctgy_ctl.hpp"

// Base.
#include "base_macrodefn.hpp"

/**
 * \brief Static handle of base.
 */
CBaseCtl *CBaseCtl::mBase = NULL;

CBaseCtl *CBaseCtl::Base()
{
    BMD_CLASS_NEW(mBase, CBaseCtl);

    return mBase;
}

/**
 * \brief Initial.
 */
UErrCodeT CBaseCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Core controler.
 */
CCoreCtl *CBaseCtl::Core()
{
    BMD_CLASS_NEW(mCore, CCoreCtl);

    return mCore;
}

/**
 * \brief Wrap controler.
 */
CWrapCtl *CBaseCtl::Wrap()
{
    BMD_CLASS_NEW(mWrap, CWrapCtl);

    return mWrap;
}

/**
 * \brief Ctgy controler.
 */
CCtgyCtl *CBaseCtl::Ctgy()
{
    BMD_CLASS_NEW(mCtgy, CCtgyCtl);

    return mCtgy;
}

/***** Private A ******/

/**
 * \brief Constructor.
 */
CBaseCtl::CBaseCtl()
{
    BMD_POINTER_INIT(mCore);
    BMD_POINTER_INIT(mWrap);
    BMD_POINTER_INIT(mCore);
}

/**
 * \brief Destructor.
 */
CBaseCtl::~CBaseCtl()
{
    BMD_CLASS_DEL(mCore);
    BMD_CLASS_DEL(mWrap);
    BMD_CLASS_DEL(mCtgy);
}

/***** Private B ******/
