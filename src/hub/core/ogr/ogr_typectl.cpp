/******************************************************************************
 * $Id: ogr_typectl.cpp 2017-07 $
 *
 * Project:  Ogr (OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Type controler implementation.
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
 ****************************************************************************/

#include "ogr_typectl.hpp"

// GDAL/OGR
#include "ogr_api.h"

/**
 * \brief Constructor.
 */
COgrTypeCtl::COgrTypeCtl()
{
}

/**
 * \brief Destructor.
 */
COgrTypeCtl::~COgrTypeCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT COgrTypeCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief To format.
 */
UErrCodeT COgrTypeCtl::ToFormat(UStringT *aDst, const OgrFormatCodeT aSrc,
                                UFlagCodeT aFlag)
{
    *aDst = "";

    if (aFlag == UFlagOn)
    {
        *aDst += "\"";
    }

    switch (aSrc)
    {
    case OgrFormatTab:
        *aDst += OGR_F_TAB;
        break;
    case OgrFormatShp:
        *aDst += OGR_F_SHP;
        break;
    case OgrFormatCsv:
        *aDst += OGR_F_CSV;
        break;
    case OgrFormatXls:
        *aDst += OGR_F_XLS;
        break;
    case OgrFormatXlsx:
        *aDst += OGR_F_SQLITE;
        break;
    case OgrFormatJson:
        *aDst += OGR_F_JSON;
        break;
    default:
        *aDst = "";
        return UErrTrue;
    }

    if (aFlag == UFlagOn)
    {
        *aDst += "\"";
    }

    return UErrFalse;
}

/**
 * \brief To geometry type.
 */
UErrCodeT COgrTypeCtl::ToGeomT(OgrGeomTCodeT *aDst, const OgrGeomTHT aSrc)
{
    OGRwkbGeometryType *src = (OGRwkbGeometryType *) aSrc;

    switch (*src)
    {
    case wkbUnknown:
        *aDst = OgrGeomTUnknown;
        break;
    case wkbPoint:
        *aDst = OgrGeomTPoint;
        break;
    case wkbLineString:
        *aDst = OgrGeomTLineString;
        break;
    case wkbPolygon:
        *aDst = OgrGeomTPolygon;
        break;
    default:
        *aDst = OgrGeomTUnknown;
        return UErrTrue;
    }

    return UErrFalse;
}

/**
 * \brief To geometry type.
 */
UErrCodeT COgrTypeCtl::ToGeomT(OgrGeomTHT aDst, const OgrGeomTCodeT aSrc)
{
    OGRwkbGeometryType *dst = (OGRwkbGeometryType *) aDst;
    switch (aSrc)
    {
    case OgrGeomTUnknown:
        *dst = wkbUnknown;
        break;
    case OgrGeomTPoint:
        *dst = wkbPoint;
        break;
    case OgrGeomTLineString:
        *dst = wkbLineString;
        break;
    case OgrGeomTPolygon:
        *dst = wkbPolygon;
        break;
    default:
        *dst = wkbUnknown;
        return UErrTrue;
    }

    return UErrFalse;
}
