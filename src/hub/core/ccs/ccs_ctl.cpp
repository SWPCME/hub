/******************************************************************************
 * $Id: ccs_ctl.hpp 2016-09 $
 *
 * Project:  C with class standard library.
 * Purpose:  Control implementation.
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

#include "ccs_ctl.hpp"

// Module.
#include "ccs_typectl.hpp"

/**
 * \brief Constructor.
 */
CCcsCtl::CCcsCtl()
{
    m_group.type = new CCcsTypeCtl;
}

/**
 * \brief Destructor.
 */
CCcsCtl::~CCcsCtl()
{
    delete m_group.type;
}

/**
 * \brief Initialize.
 */
UErrCodeT CCcsCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Handle of type control.
 */
CCcsTypeCtl* CCcsCtl::Type()
{
    return m_group.type;
}
