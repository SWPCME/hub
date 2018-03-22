/******************************************************************************
 * $Id: gda_algctl.cpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Alg control definition.
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

#include "gda_algctl.hpp"

// gda/alg
#include "gda_algbase.hpp"
#include "gda_algtransform.hpp"
#include "gda_algcontour.hpp"
#include "gda_algrasterizer.hpp"
#include "gda_alggridding.hpp"

/**
 * \brief Constructor.
 */
CGdaAlgCtl::CGdaAlgCtl()
{
    InitPointer();
}

/**
 * \brief Destructor.
 */
CGdaAlgCtl::~CGdaAlgCtl()
{
    BMD_CLASS_DEL(mBase);
    BMD_CLASS_DEL(mTransform);
    BMD_CLASS_DEL(mContour);
    BMD_CLASS_DEL(mRasterizer);
    BMD_CLASS_DEL(mGridding);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaAlgCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Base.
 */
CGdaAlgBase *CGdaAlgCtl::Base()
{
    BMD_CLASS_NEW(mBase, CGdaAlgBase);

    return mBase;
}

/**
 * \brief Transform.
 */
CGdaAlgTransform *CGdaAlgCtl::Transform()
{
    BMD_CLASS_NEW(mTransform, CGdaAlgTransform);

    return mTransform;
}

/**
 * \brief Contour line generation.
 */
CGdaAlgContour *CGdaAlgCtl::Contour()
{
    BMD_CLASS_NEW(mContour, CGdaAlgContour);

    return mContour;
}

/**
 * \brief Rasterizer.
 */
CGdaAlgRasterizer *CGdaAlgCtl::Rasterizer()
{
    BMD_CLASS_NEW(mRasterizer, CGdaAlgRasterizer);

    return mRasterizer;
}

/**
 * \brief Gridding.
 */
CGdaAlgGridding *CGdaAlgCtl::Gridding()
{
    BMD_CLASS_NEW(mGridding, CGdaAlgGridding);

    return mGridding;
}

/***** Private A *****/

UErrCodeT CGdaAlgCtl::InitPointer()
{
    BMD_POINTER_INIT(mBase);
    BMD_POINTER_INIT(mTransform);
    BMD_POINTER_INIT(mContour);
    BMD_POINTER_INIT(mRasterizer);
    BMD_POINTER_INIT(mGridding);

    return UErrFalse;
}

/***** Private B *****/
