/******************************************************************************
 * $Id: gda_warpreprjimagetype.hpp 2017-12 $
 *
 * Project:  Gda (GDAL: Geospatial Data Abstraction Library) library.
 * Purpose:  Gda warp reproject image type implementation.
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
 *****************************************************************************/

#include "gda_warpreprojimagetype.hpp"

/**
 * \brief Constructor.
 */
GdaWarpReprojImageT::GdaWarpReprojImageT()
{
}

/**
 * \brief Destructor.
 */
GdaWarpReprojImageT::~GdaWarpReprojImageT()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT GdaWarpReprojImageT::Init()
{
    return UErrFalse;
}

/**
 * \brief Set all values.
 */
UErrCodeT GdaWarpReprojImageT::SetAll(const GdaOgrSrsT *aDstSrs,
                                      const GdaOgrSrsT *aSrcSrs,
                                      const CGdaDriverCtl *aDstDr)
{
    SetDstSrs(aDstSrs);
    SetSrcSrs(aSrcSrs);
    SetDstDr(aDstDr);

    return UErrFalse;
}

/**
 * \brief Set destination spatial reference system.
 */
UErrCodeT GdaWarpReprojImageT::SetDstSrs(const GdaOgrSrsT *aDstSrs)
{
    mDstSrs = *aDstSrs;

    return UErrFalse;
}

/**
 * \brief Set source spatial reference system.
 */
UErrCodeT GdaWarpReprojImageT::SetSrcSrs(const GdaOgrSrsT *aSrcSrs)
{
    mSrcSrs = *aSrcSrs;

    return UErrFalse;
}

/**
 * \brief Set destination driver.
 */
UErrCodeT GdaWarpReprojImageT::SetDstDr(const CGdaDriverCtl *aDstDr)
{
    mDstDr = aDstDr;

    return UErrFalse;
}

/**
 * \brief Get all values.
 */
UErrCodeT GdaWarpReprojImageT::All(GdaOgrSrsT *aDstSrs, GdaOgrSrsT *aSrcSrs,
                                   CGdaDriverCtl **aDstDr) const
{
    aDstSrs = (GdaOgrSrsT *) &mDstSrs;
    aSrcSrs = (GdaOgrSrsT *) &mSrcSrs;
    *aDstDr = (CGdaDriverCtl *) mDstDr;

    return UErrFalse;
}

/**
 * \brief Get destination spatial reference system.
 */
GdaOgrSrsT *GdaWarpReprojImageT::DstSrs() const
{
    return (GdaOgrSrsT *) &mDstSrs;
}

/**
 * \brief Get source spatial reference system.
 */
GdaOgrSrsT *GdaWarpReprojImageT::SrcSrs() const
{
    return (GdaOgrSrsT *) &mSrcSrs;
}

/**
 * \brief Get destination driver.
 */
CGdaDriverCtl *GdaWarpReprojImageT::DstDr() const
{
    return mDstDr;
}
