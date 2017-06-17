/******************************************************************************
 * $Id: sys_ftwctl.cpp 2016-09 $
 *
 * Project:  System library.
 * Purpose:  File tree walk control implemention.
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

#include "sys_filetwctl.hpp"

// Module.
// Base.
#include "base_ctl.hpp"
// Core control.
#include "core_ctl.hpp"
// Cls control.
#include "cls_ctl.hpp"
#include "cls_ioctl.hpp"

// Static valuable.
CClsIoCtl* CSysFileTwCtl::m_io = NULL;

/**
 * \brief Constructor.
 */
CSysFileTwCtl::CSysFileTwCtl()
{
}

/**
 * \brief Destructor.
 */
CSysFileTwCtl::~CSysFileTwCtl()
{
}

/**
 * \brief Initialize.
 * 
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CSysFileTwCtl::Init()
{
    CBaseCtl *baseCtl = CBaseCtl::Base();
    CCoreCtl* coreCtl = baseCtl->Core();
    CClsCtl* clsCtl = coreCtl->Cls();
    m_io = clsCtl->Io();

    return UErrFalse;
}

/**
 * \brief Traversal.
 */
UErrCodeT CSysFileTwCtl::Traversal(const UStringT* aPath)
{
    int nOpenFD = 0;
    int flags = 0;
    nftw(aPath->ToA(), NFtw, nOpenFD, flags);

    return UErrFalse;
}

/**
 * \brief Callback function of new free tree walk.
 *
 * @param aFPath The pathname of the entry.
 * @param aSB A pointer to the stat structure.
 * @param aTFlag An integer that record the type of this file.
 * @param aFtwBuf A struct of "FTW".
 *
 * @return 0, if continue; -1, if stop.
 */
int CSysFileTwCtl::NFtw(const char* aFPath, const struct stat* aSB,
                     int aTFlag, struct FTW* aFtwBuf)
{
    m_io->PrintF("%-3s %2d %7jd   %-40s %d %s\n",
              (aTFlag == FTW_D) ?   "d"   : (aTFlag == FTW_DNR) ? "dnr" :
              (aTFlag == FTW_DP) ?  "dp"  : (aTFlag == FTW_F) ?   "f" :
              (aTFlag == FTW_NS) ?  "ns"  : (aTFlag == FTW_SL) ?  "sl" :
              (aTFlag == FTW_SLN) ? "sln" : "???",
              aFtwBuf->level, (intmax_t) aSB->st_size,
              aFPath, aFtwBuf->base, aFPath + aFtwBuf->base);

    return 0;               /* To tell nftw() to continue. */
}
