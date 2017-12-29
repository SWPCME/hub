/******************************************************************************
 * $Id: gda_ctl.cpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Abstraction Library) library.
 * Purpose:  Gda control implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-07 ~ 2017, Weiwei Huang
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

#include "gda_ctl.hpp"

// gda
#include "gda_corectl.hpp"
#include "gda_ogrctl.hpp"
#include "gda_algctl.hpp"
#include "gda_warpctl.hpp"
#include "gda_utilsctl.hpp"
#include "gda_typectl.hpp"

/**
 * \brief Constructor.
 */
CGdaCtl::CGdaCtl()
{
    BMD_POINTER_INIT(mType);
    BMD_POINTER_INIT(mCore);
    BMD_POINTER_INIT(mOgr);
    BMD_POINTER_INIT(mAlg);
    BMD_POINTER_INIT(mWarp);
    BMD_POINTER_INIT(mUtils);
}

/**
 * \brief Destructor.
 */
CGdaCtl::~CGdaCtl()
{
    BMD_CLASS_DEL(mType);
    BMD_CLASS_DEL(mCore);
    BMD_CLASS_DEL(mOgr);
    BMD_CLASS_DEL(mAlg);
    BMD_CLASS_DEL(mWarp);
    BMD_CLASS_DEL(mUtils);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Core.
 */
CGdaCoreCtl *CGdaCtl::Core()
{
    BMD_CLASS_NEW(mCore, CGdaCoreCtl);

    return mCore;
}

/**
 * \brief OpenGIS simple features reference implementation.
 */
CGdaOgrCtl *CGdaCtl::Ogr()
{
    return mOgr;
}

/**
 * \brief Image processing algorithms.
 */
CGdaAlgCtl *CGdaCtl::Alg()
{
    BMD_CLASS_NEW(mAlg, CGdaAlgCtl);

    return mAlg;
}

/**
 * \brief Warp.
 */
CGdaWarpCtl *CGdaCtl::Warp()
{
    BMD_CLASS_NEW(mWarp, CGdaWarpCtl);

    return mWarp;
}

/**
 * \brief Utilities.
 */
CGdaUtilsCtl *CGdaCtl::Utils()
{
    BMD_CLASS_NEW(mUtils, CGdaUtilsCtl);

    return mUtils;
}

/**
 * \brief Type.
 */
CGdaTypeCtl *CGdaCtl::Type()
{
    BMD_CLASS_NEW(mType, CGdaTypeCtl);

    return mType;
}
