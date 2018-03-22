/******************************************************************************
 * $Id: cls_streamline.cpp 2017-12 $
 *
 * Project:  C language standard library.
 * Purpose:  Stream line controler definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-12 ~ 2017 Weiwei Huang
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

#include "cls_streamline.hpp"

// base
#include "base_ctl.hpp"
// core
#include "core_ctl.hpp"
// cls
#include "cls_ctl.hpp"
#include "cls_memoryctl.hpp"

/**
 * \brief Constructor.
 */
CClsStreamLine::CClsStreamLine()
{
    InitPointer();
}

/**
 * \brief Destructor.
 */
CClsStreamLine::~CClsStreamLine()
{
    InitPointer();
}

/**
 * \brief Initialize.
 */
UErrCodeT CClsStreamLine::Init()
{
    CClsCtl *cls = NULL;
    CLS_CTL(cls);
    mMem = cls->Mem();

    return UErrFalse;
}

/**
 * \brief Get line from stream.
 *
 * This function reads an entire line from stream, storing the text 
 * (including the new-line and a terminating null character) in a buffer and 
 * storing the buffer address in *lineptr.
 *
 * @param
 */
UErrCodeT CClsStreamLine::Line(UStringT *aStr, ClsFileHT aFile)
{
#ifdef OS_UNIX
    char *str = NULL;
    size_t n = 0;
    int err = getline(&str, &n, (FILE *) aFile);
    if (err == -1)
    {
        mMem->Free((UHandleT *) &str);

        return UErrTrue;
    }

    *aStr = str;
    mMem->Free((UHandleT *) &str);
#endif  // OS_UNIX

#ifdef OS_WINDOWS
    // TODO Consider the n is less than the size of row.
    char str[kNMax];
    char *strErr = fgets(str , kNMax, (FILE *) aFile);
    *aStr = str;
#endif  // OS_WINDOWS

    return UErrFalse;
}


/***** Private A *****/

/**
 * \brief Initialize pointer.
 */
UErrCodeT CClsStreamLine::InitPointer()
{
    BMD_POINTER_INIT(mMem);

    return UErrFalse;
}

/***** Private B *****/
