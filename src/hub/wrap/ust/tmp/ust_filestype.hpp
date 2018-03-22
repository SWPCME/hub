/******************************************************************************
 * $Id: ust_filestype.hpp 2016-08 $
 *
 * Project:  Universal structrue library.
 * Purpose:  File system structrue type definition.
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

#ifndef UST_FILESTYPE_HPP_INCLUDED
#define UST_FILESTYPE_HPP_INCLUDED

#include "ust_filesbase.h"
#include "ust_containertype.hpp"
#include "ust_stringtype.hpp"

class CUstFilesCtl;

typedef UContainerT<UStringT*> FilesCtnT;

class UST_LIB UFilesT
{
  public:
    UFilesT();
    UFilesT(UStringT* aPath);
    UFilesT(UStringT& aPath);
    ~UFilesT();

    /* Init */
    UErrCodeT SetPath(UStringT* aPath);

    /* Conunt. */
    UIntT Count();
    UIntT CountDir();
    UIntT CountFile();

    // Traversal.
    UErrCodeT Begin();
    UErrCodeT End();
    UErrCodeT Next();
    UErrCodeT Prev();

    // Curent data.
    UStringT Dir(UStringT* aDirName = NULL);
    UStringT File(UStringT* aFileName = NULL, UStringT* aDirName = NULL);
    UIntT DirLv(UStringT* aDirName = NULL);
    UIntT FileLv(UStringT* aFileName = NULL);

    /* Operator */
  protected:
  private:
    // Init
    UErrCodeT Init();
    // Traversal.
    UErrCodeT Traversal();

    // Ust library.
    CUstFilesCtl* m_files;

    UStringT m_root;
    FilesCtnT m_filesCtn;
};

#endif  /* UST_FILESTYPE_HPP_INCLUDED */
