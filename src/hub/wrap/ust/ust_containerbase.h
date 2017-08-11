/******************************************************************************
 * $Id: ust_containerbase_cpp.hpp 2016-08 $
 *
 * Project:  Universal structure library.
 * Purpose:  Container base definition.
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

#ifndef UST_CONTAINERBASE_H_INCLUDED
#define UST_CONTAINERBASE_H_INCLUDED

#include "ust_base.h"

/**
 * \brief Code of container's operator.
 * If you need the container to automatically release the pointer, 
 * to use the UContainerM* instead of UContainer*.
 * For example, to UContainerMList instead of UContainerList, it will be 
 * releaset the handle by itselef.
 *
 * @param List
 * @param Vector
 * @param Set
 * @param Uset Unordered set.
 * @param Map
 * @param Umap Unordered map.
 * @param Sqlite
 */
typedef enum
{
    /** 
     * \brief Memory.
     */
    UContainerList    = 1,      /* Pointer: None. */
    UContainerVector  = 2,      /* Pointer: None. */
    UContainerSet     = 3,      /* Pointer: None. */
    UContainerUset    = 4,      /* Pointer: None. */
    UContainerMap     = 5,      /* Pointer: None. */
    UContainerUmap    = 6,      /* Pointer: None. */
    UContainerMList   = 11,     /* Pointer: ContentT. */
    UContainerMVector = 12,     /* Pointer: ContentT. */
    UContainerMSet    = 13,     /* Pointer: ContentT. */
    UContainerMUset   = 14,     /* Pointer: ContentT. */
    UContainerMcMap   = 15,     /* Pointer: ContentT. */
    UContainerMkMap   = 16,     /* Pointer: KeyT. */
    UContainerMMap    = 17,     /* Pointer: ContentT and KeyT. */
    UContainerMcUmap  = 18,     /* Pointer: ContentT. */

    /**
     * \brief Disk.
     */
    UContainerSqlite  = 51,     /* Pointer: None. */
} UContainerCodeT;

typedef UHandleT ContentHT;
typedef UHandleT KeyHT;
typedef UHandleT UstContainerHT;

#endif  /* UST_CONTAINERBASE_H_INCLUDED */
