/******************************************************************************
 * $Id: gda_typectl.hpp 2017-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda type control.
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

#include "gda_typectl.hpp"

/**
 * \brief Constructor.
 */
CGdaTypeCtl::CGdaTypeCtl()
{
}

/**
 * \brief Destructor.
 */
CGdaTypeCtl::~CGdaTypeCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaTypeCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Translate UAccessCodeT to GDALAccess.
 */
UErrCodeT CGdaTypeCtl::ToAccess(GDALAccess *aDest, const UAccessCodeT aSrc)
{
    switch (aSrc)
    {
    case UAccessRead:
        *aDest = GA_ReadOnly;
        break;
    case UAccessWrite:
        *aDest = GA_Update;
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief Translate UDataTCodeT to GDALDataType.
 */
UErrCodeT CGdaTypeCtl::ToDataType(GDALDataType *aDest, UDataTCodeT aSrc)
{
    switch (aSrc)
    {
    case UDataTFloat:
        *aDest = GDT_Float64;
        break;
    default:
        return UErrTrue;
    }

    return UErrFalse;
}
