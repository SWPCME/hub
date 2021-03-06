/******************************************************************************
 * $Id: ogr_base.h 2016-08 $
 *
 * Project:  Vector Info Process
 * Purpose:  Ogr Base Info.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016, Weiwei Huang
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ****************************************************************************/

#ifndef OGR_BASE_H_INCLUDED
#define OGR_BASE_H_INCLUDED

#include "hub_base.h"

// base.
#include "base_containerdefn.hpp"

#define OGR_LIB HUB_LIB

/**
 * \brief Container.
 */
class COgrDatasrcCtl;
typedef UContainerT<COgrDatasrcCtl*> OgrCtnDatasrcT;
typedef UIteratorT<COgrDatasrcCtl*> OgrItDatasrcT;

/** 
 * Ogr vector formats.
 * "F" means format. 
 */
#define OGR_F_COUNT 7
#define OGR_F_TAB         "Mapinfo File"
#define OGR_F_TAB_SUFFIX  "tab"
#define OGR_F_SHP         "ESRI Shapefile"
#define OGR_F_SHP_SUFFIX  "shp"
#define OGR_F_CSV         "Comma Separated Value"
#define OGR_F_CSV_SUFFIX  "csv"
#define OGR_F_XLS         "MS Excel format"
#define OGR_F_XLS_SUFFIX  "xls"
#define OGR_F_XLSX        "MS Office Open XML spreadsheet"
#define OGR_F_XLSX_SUFFIX "xlsx"
#define OGR_F_SQLITE      "SQLite"
#define OGR_F_SQLITE_SUFFIX  "sql"
#define OGR_F_JSON        "GeoJSON"
#define OGR_F_JSON_SUFFIX "json"
typedef enum
{
    // 0 ~ 99 for raster format.
    OgrFormatNone   = 100,
    OgrFormatTab    = 101,
    OgrFormatShp    = 102,
    OgrFormatCsv    = 103,
    OgrFormatXls    = 104,
    OgrFormatXlsx   = 105,
    OgrFormatSqlite = 106,
    OgrFormatJson   = 107,
} OgrFormatCodeT;

/* Geometry type code. */
typedef enum
{
    OgrGeomTUnknown    = 0,

    // Single.
    OgrGeomTPoint      = 1,
    OgrGeomTLineString = 2,
    OgrGeomTPolygon    = 3,

    // Multi
    OgrGeomTMPoint      = 11,
    OgrGeomTMLineString = 21,
    OgrGeomTMPloygon    = 22,
} OgrGeomTCodeT;

/* Handle */
#define OgrDriverHT UHandleT
#define OgrDatasrcHT UHandleT
#define OgrLayerHT UHandleT
#define OgrFeaturesHT UHandleT
#define OgrFeatureDefnHT UHandleT
#define OgrFieldDefnHT UHandleT
#define OgrGeomFieldDefnHT UHandleT
#define OgrFeatureHT UHandleT
#define OgrFieldHT UHandleT
#define OgrGeomsHT UHandleT
#define OgrGeomHT UHandleT
#define OgrGeomTHT UHandleT

/* Macro */
#define OGR_CTL(aCtl)                           \
    {                                           \
        BMD_CORE_CTL(coreCtl);                  \
        aCtl = coreCtl->Ogr();                  \
    }

/* Macro */
#define OGR_TYPE_CTL(aCtl)                       \
    if (aCtl == NULL)                            \
    {                                            \
        COgrCtl *ogrCtl = NULL;                  \
        OGR_CTL(ogrCtl);                         \
        aCtl = ogrCtl->Type();                   \
    }

#endif  /* OGR_BASE_H_INCLUDED */
