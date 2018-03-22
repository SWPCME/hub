/******************************************************************************
 * $Id: ucc_typectl.hpp 2016-09 $
 *
 * Project:  C with class standard library.
 * Purpose:  Type control definition.
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

#ifndef CCS_TYPECTL_HPP_INCLUDED
#define CCS_TYPECTL_HPP_INCLUDED

#include "ccs_base.h"

// Compile library, as "GCC".
#include <typeinfo>

/**
 * \brief Type identity.
 *
 * Definition: type_info ucc_type_id(typename).
 *
 * @param typename Get "type_info" by this "type".
 *
 * @return type_info, if successful; NULL, if failed.
 */
#define ccs_type_id typeid

/**
 * \brief Type information.
 */
// typedef type_info TypeInfoT;

class CCS_LIB CCcsTypeCtl
{
  public:
    CCcsTypeCtl();
    ~CCcsTypeCtl();

    UErrCodeT Init();
    // TypeInfoT Info();

  protected:
  private:
};

#endif  // CCS_TYPECTL_HPP_INCLUDED
