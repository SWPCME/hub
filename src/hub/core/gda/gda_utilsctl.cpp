/******************************************************************************
 * $Id: gda_utilsctl.cpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Utils control implementation.
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

#include "gda_utilsctl.hpp"

// gda
#include "gda_utilsinfo.hpp"
#include "gda_utilstranslate.hpp"

/**
 * \brief Constructor.
 */
CGdaUtilsCtl::CGdaUtilsCtl()
{
    BMD_POINTER_INIT(mInfo);
    BMD_POINTER_INIT(mTranslate);
}

/**
 * \brief Destructor.
 */
CGdaUtilsCtl::~CGdaUtilsCtl()
{
    BMD_CLASS_DEL(mInfo);
    BMD_CLASS_DEL(mTranslate);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaUtilsCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Info controler.
 */
CGdaUtilsInfo *CGdaUtilsCtl::Info()
{
    BMD_CLASS_NEW(mInfo, CGdaUtilsInfo);

    return mInfo;
}

/**
 * \brief Translate controler.
 */
CGdaUtilsTranslate *CGdaUtilsCtl::Translate()
{
    BMD_CLASS_NEW(mTranslate, CGdaUtilsTranslate);

    return mTranslate;
}
