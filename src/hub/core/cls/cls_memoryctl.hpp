/******************************************************************************
 * $Id: cls_memoryctl.hpp 2016-08 $
 *
 * Project:  C language standard library.
 * Purpose:  Memory controler definition.
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

#ifndef CLS_MEMORYCTL_HPP_INCLUDED
#define CLS_MEMORYCTL_HPP_INCLUDED

#include "cls_base.h"

class CLS_LIB CClsMemoryCtl
{
 public:
    CClsMemoryCtl();
    ~CClsMemoryCtl();

    UErrCodeT Init();

    UHandleT Alloc(UIntT aSize);
    UHandleT CAlloc(UIntT aNMemB, UIntT aSize);
    UHandleT Realloc(UHandleT aHandle, UIntT aSize);
    UErrCodeT Cpy(UHandleT aDest, const UHandleT aSrc, UIntT aSize);

    UErrCodeT Free(UHandleT aHandle);
    UErrCodeT Free(UHandleT* aHandle);

 protected:
 private:
};

#endif  /* CLS_MEMORYCTL_HPP_INCLUDED */
