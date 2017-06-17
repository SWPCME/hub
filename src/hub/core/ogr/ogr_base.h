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

#define OGR_LIB HUB_LIB

/* Ogr vector formats. */
#define OGR_VECTOR_FORMATS_COUNT 6
#define OGR_VECTOR_TAB_NAME    "Mapinfo File"
#define OGR_VECTOR_TAB_SUFFIX  "tab"
#define OGR_VECTOR_SHP_NAME    "ESRI Shapefile"
#define OGR_VECTOR_SHP_SUFFIX  "shp"
#define OGR_VECTOR_CSV_NAME    "Comma Separated Value"
#define OGR_VECTOR_CSV_SUFFIX  "csv"
#define OGR_VECTOR_XLS_NAME    "MS Excel format"
#define OGR_VECTOR_XLS_SUFFIX  "xls"
#define OGR_VECTOR_XLSX_NAME   "MS Office Open XML spreadsheet"
#define OGR_VECTOR_XLSX_SUFFIX "xlsx"
#define OGR_VECTOR_SQLITE_NAME    "SQLite"
#define OGR_VECTOR_SQLITE_SUFFIX  "sql"

/* Handle */
#define OgrDriverHT UHandleT
#define OgrDataSrcHT UHandleT
#define OgrLayerHT UHandleT
#define OgrFeatureDefnHT UHandleT
#define OgrFieldDefnHT UHandleT
#define OgrGeomFieldDefnHT UHandleT
#define OgrFeatureHT UHandleT
#define OgrFieldHT UHandleT
#define OgrGeometryHT UHandleT

#endif  /* GDAL_BASE_H_INCLUDED */
