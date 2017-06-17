/******************************************************************************
 * $Id: ogr_featurectl.cpp 2016-08 $
 *
 * Project:  Ogr(OpenGIS Simple Features Reference Implementation) library.
 * Purpose:  Ogr feature control.
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

#include "ogr_featurectl.hpp"

// Module.
#include "ogr_fieldctl.hpp"
#include "ogr_geometryctl.hpp"

/**
 * \brief Constructor.
 */
COgrFeatureCtl::COgrFeatureCtl()
{
    m_field = new COgrFieldCtl;
    m_geometry = new COgrGeometryCtl;
}

/**
 * \brief Destructor.
 */
COgrFeatureCtl::~COgrFeatureCtl()
{
    delete m_field;
    delete m_geometry;
}

/**
 * \brief Attach handle of ogr feature.
 */
UErrCodeT COgrFeatureCtl::Attach(OgrFeatureHT aHandle)
{
    m_handle = aHandle;

    return UErrFalse;
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT COgrFeatureCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Handle of field constrol.
 */
COgrFieldCtl* COgrFeatureCtl::Field()
{
    return m_field;
}

/**
 * \brief Handle of geometry control.
 */
COgrGeometryCtl* COgrFeatureCtl::Geometry()
{
    return m_geometry;
}
