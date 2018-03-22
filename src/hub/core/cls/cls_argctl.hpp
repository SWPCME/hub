/******************************************************************************
 * $Id: cls_argctl.hpp 2016-09 $
 *
 * Project:  C language standard library.
 * Purpose:  Argument control definition.
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

#ifndef CLS_ARGCTL_HPP_INCLUDED
#define CLS_ARGCTL_HPP_INCLUDED

#include "cls_base.h"

// C standard lib.
#include <stdarg.h>

/**
 * \brief Type which is a list of argument.
 */
typedef va_list ClsArgListT;

/**
 * \brief Start with a list of argument.
 *
 * typedef void (cls_argstart*) (ClsArgListT aList, const char* aFormat);
 */
#define cls_arg_start va_start

/**
 * \brief Copy ClsArgListT.
 *
 * Definition: void (cls_argcopy*) (ClsArgListT aDest, ClsArgListT aSrc);
 */
#define cls_arg_copy va_copy

/**
 * \brief Get value of argument, and move to next argument.
 *
 * Definition: ArgumentT (cls_argvalue*) (ClsArgListT aList, typename ArgumentT);
 */
#define cls_arg_value va_arg

/**
 * \brief End with a list argument.
 *
 * Definition: void (cls_argend*) (ClsArgListT aList);
 */
#define cls_arg_end va_end

#endif  // CLS_ARGCTL_HPP_INCLUDED
