/******************************************************************************
 * $Id: cls_memoryctl.cpp 2016-08 $
 *
 * Project:  C language standard library.
 * Purpose:  Memory controler implementation.
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

#include "cls_memoryctl.hpp"

// C standard library.
#include <stdlib.h>
#include <string.h>

/**
 * \brief Constructor.
 */
CClsMemoryCtl::CClsMemoryCtl()
{
}

/**
 * \brief Destructor.
 */
CClsMemoryCtl::~CClsMemoryCtl()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsMemoryCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Debug.
 *
 * To support with mtrace.
 */
// UErrCodeT CClsMemoryCtl::Debug()
// {
//     return UErrFalse;
// }

/**
 * \brief Allocate.
 *
 * To allocate memory, and return the handle.
 *
 * @param aSize The size that you want to allocate.
 *
 * @return Handle of the memory that you just to allocate.
 */
UHandleT CClsMemoryCtl::Alloc(UIntT aSize)
{
    if (aSize <= 0)
    {
        return NULL;
    }
    UHandleT handle = (UHandleT) malloc((size_t) aSize);
    
    return handle;
}

/**
 * \brief To allocate the size of "aSize * aNMemB".
 *
 * @param aNMemB the size of memory bit that you to allocate.
 * @param aSize the num of amount that you to allocate.
 *
 * @return Handle of the memory that you just to allocate.
 */
UHandleT CClsMemoryCtl::CAlloc(UIntT aNMemB, UIntT aSize)
{
    if ((aNMemB <= 0) || (aSize <= 0))
    {
        return NULL;
    }
    UHandleT handle = (UHandleT) calloc(aNMemB, (size_t) aSize);

    return handle;
}

/**
 * \brief To allocate the new size of memory with old handle.
 *
 * @aHandle aHandle the old handle of memory.
 * @param aSize the size of memory that you want to allocate.
 *
 * @return Handle of memory with new size.
 */
UHandleT CClsMemoryCtl::Realloc(UHandleT aHandle, UIntT aSize, UErrCodeT *aErr)
{
    if (aSize <= 0)
    {
        if (aErr != NULL)
        {
            *aErr = UErrTrue;
        }
        return aHandle;
    }
    UHandleT handle = (UHandleT) realloc((void *) aHandle, (size_t) aSize);

    if (handle == NULL)
    {
        if (aErr != NULL)
        {
            *aErr = UErrTrue;
        }
        return aHandle;
    }

    if (aErr != NULL)
    {
        *aErr = UErrFalse;
    }

    return handle;
}

/**
 * \brief Copy "aSize" bytes of "aSrc" to "aDest".
 *
 * @param aDest The destination handle of memory.
 * @param aSrc The source handle of memory.
 * @param aSize The size of "aSrc".
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsMemoryCtl::Cpy(UHandleT aDest, UHandleT aSrc, UIntT aSize)
{
    if (aSize < 0)
    {
        return UErrTrue;
    }

    memcpy((void *) aDest, (void *) aSrc, (size_t) aSize);

    return UErrFalse;
}

/**
 * \brief To free the memory.
 *
 * @param aHandle The handle that you want to free.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsMemoryCtl::Free(UHandleT aHandle)
{
    if (aHandle == NULL)
    {
        return UErrFalse;
    }
    free((void *) aHandle);

    return UErrFalse;
}

/**
 * \brief To free the memory, and set NULL.
 *
 * @param aHandle The handle that you want to free.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CClsMemoryCtl::Free(UHandleT* aHandle)
{
    Free(*aHandle);
    *aHandle = NULL;

    return UErrFalse;
}

/***** Private A *****/

UErrCodeT CClsMemoryCtl::InitPointer()
{
    return UErrFalse;
}

/***** Private B *****/
