/******************************************************************************
 * $Id: vtr_layerctl.cpp 2016-08 $
 *
 * Project:  Vector info process library.
 * Purpose:  Vector layer control.
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

#include "vtr_layerctl.hpp"

// Module.
#include "vtr_layerread.hpp"
#include "vtr_layerwrite.hpp"

/**
 * \brief Constructor
 *
 * Constructor the handles in "VectorLayerGroupT".
 */
CVtrLayerCtl::CVtrLayerCtl(COgrLayerCtl* aCtl)
{
    m_base = new CVtrLayerBase(aCtl);
    m_group.read = new CVtrLayerRead(m_base);
    m_group.write = new CVtrLayerWrite(m_base);
}

/**
 * \brief Destructor
 *
 * Destructor the handles in "VtrLayerGroupT".
 */
CVtrLayerCtl::~CVtrLayerCtl()
{
    delete m_base;
    delete m_group.read;
    delete m_group.write;
}

/**
 * \brief Initialize
 *
 * Initialize the handles in "VtrLayerGroupT".
 *
 * @return UErrFalse, if successful; UErrFalse, if failed.
 */
UErrCodeT CVtrLayerCtl::Init()
{
    m_base->Init();
    m_group.read->Init();
    m_group.write->Init();

    return UErrFalse;
}

/**
 * \brief Layer's name.
 */
UStringT* CVtrLayerCtl::Name()
{
    return m_base->Name();
}

/**
 * \brief Vector Group.
 *
 * @return The handle of "VtrLayerGroupT", if successful; NULL, if failed.
 */
// VtrLayerGroupT* CVtrLayerCtl::Group()
// {
//     return &m_group;
// }

/**
 * \brief Vector Read
 *
 * Get the handle of vector read.
 *
 * @return The handle of "CVectorRead", if successful; NULL, if failed.
 */
CVtrLayerRead* CVtrLayerCtl::Read()
{
    return m_group.read;
}

/**
 * \brief Vector Write.
 *
 * Get the handle of vector write.
 *
 * @return The handle of "CVectorWrite", if successful; NULL, if failed.
 */
CVtrLayerWrite* CVtrLayerCtl::Write()
{
    return m_group.write;
}

/**
 * \brief Vector Process.
 *
 * Get the handle of vector process.
 *
 * @return The handle of "CVectorProcess", if successful,; NULL, if failed.
 */
// CVectorProcess* CVtrLayerCtl::Process()
// {
//     return m_group.process;
// }

/***** Private A *****/

/***** Private B *****/
