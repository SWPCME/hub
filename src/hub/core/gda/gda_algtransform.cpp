/******************************************************************************
 * $Id: gda_algtransform.cpp 2017-07 $
 *
 * Project:  Gda (GDAL: Geospatial Data Absraction Library) library.
 * Purpose:  Alg transform implementation.
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

#include "gda_algtransform.hpp"

// gda
#include "gda_algtrreprj.hpp"

/**
 * \brief Constructor.
 */
CGdaAlgTransform::CGdaAlgTransform()
{
    BMD_POINTER_INIT(mReprj);
}

/**
 * \brief Destructor.
 */
CGdaAlgTransform::~CGdaAlgTransform()
{
    BMD_CLASS_DEL(mReprj);
}

/**
 * \brief Initialize.
 */
UErrCodeT CGdaAlgTransform::Init()
{
    return UErrFalse;
}

/**
 * \brief Geo to geo reprojection transformer.
 */
CGdaAlgTrReprj *CGdaAlgTransform::Reprj()
{
    BMD_CLASS_NEW(mReprj, CGdaAlgTrReprj);

    return mReprj;
}
