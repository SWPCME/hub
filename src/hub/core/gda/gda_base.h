/******************************************************************************
 * $Id: gda_base.h 2017-05 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Gda base info.
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
 *****************************************************************************/

#ifndef GDA_BASE_H_INCLUDED
#define GDA_BASE_H_INCLUDED

#include "hub_base.h"

#define GDA_LIB HUB_LIB

/* Gda raster formats. */
#define GDA_RASTER_FORMATS_COUNT 2
// AAIGrid: Arc/Info ASCII Grid (.asc).
#define GDA_RASTER_ASC_NAME    "AAIGrid"
#define GDA_RASTER_ASC_SUFFIX  "asc"
// LCP: FARSITE v.4 Landscape File (.lcp).
#define GDA_RASTER_LCP_NAME    "LCP"
#define GDA_RASTER_LCP_SUFFIX  "lcp"

/* Handle */
#define GdaDriverHT UHandleT
#define GdaDatasetHT UHandleT
#define GdaRasterBandHT UHandleT

#endif  /* GDA_BASE_H_INCLUDED */
