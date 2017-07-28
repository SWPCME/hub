/******************************************************************************
 * $Id: cut_easyctl.hpp 2017-06 $
 *
 * Project:  CUT (CUT: Client-side URL Transfer).
 * Purpose:  Easy controler implementation.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017, Weiwei Huang
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
 ****************************************************************************/

#include "cut_easyctl.hpp"

// Curl.
#include "curl.h"
#include "easy.h"
// Base.
#include "base_ctl.hpp"
// Core.
#include "core_ctl.hpp"
// Cls.
#include "cls_ctl.hpp"
#include "cls_argctl.hpp"
#include "cls_ioctl.hpp"
// Cut.
#include "cut_ctl.hpp"
#include "cut_typectl.hpp"

// Callback Function.
static cut_write_callback kWriteFunc;
static CClsIoStreamCtl *kIoStr;

/***** C Definition A *****/

static size_t cut_write_func(char *aBuffer, size_t aSize, size_t aNumItems,
                             void *aOutStream);

/***** C Definition B *****/

/**
 * \brief Constructor.
 */
CCutEasyCtl::CCutEasyCtl(UStringT *aName)
{
    mType = NULL;
    mIoStr = NULL;
    mHandle = NULL;
    mName = kStrNull;
    mUrl = kStrNull;

    SetName(aName);
}

/**
 * \brief Destructor.
 */
CCutEasyCtl::~CCutEasyCtl()
{
    Cleanup();
}

/**
 * \brief Initialize.
 */
UErrCodeT CCutEasyCtl::Init()
{
    CBaseCtl *baseCtl = CBaseCtl::Base();
    CCoreCtl *coreCtl = baseCtl->Core();

    CCutCtl *cutCtl = coreCtl->Cut();
    mType = cutCtl->Type();

    CClsCtl *clsCtl = coreCtl->Cls();
    CClsIoCtl *ioCtl = clsCtl->Io();
    mIoStr = ioCtl->Stream();
    kIoStr = mIoStr;

    Handle(&mHandle);

    return UErrFalse;
}

/**
 * \brief Get Name.
 */
UStringT CCutEasyCtl::Name()
{
    return mName;
}

/**
 * \brief Set Url.
 */
UErrCodeT CCutEasyCtl::SetUrl(UStringT *aUrl)
{
    CutOptCodeT opt = CutOptUrl;
    SetOpt(opt, aUrl->ToA());

    return UErrFalse;
}

/**
 * \brief Http Get.
 */
UErrCodeT CCutEasyCtl::SetGet()
{
    CutOptCodeT opt = CutOptHttpGet;
    SetOpt(opt, 1);

    return UErrFalse;
}

/**
 * \brief Http Put.
 */
UErrCodeT CCutEasyCtl::SetPut()
{
    CutOptCodeT opt = CutOptHttpPut;
    SetOpt(opt, 1);

    return UErrFalse;
}

/**
 * \brief Write data.
 */
UErrCodeT CCutEasyCtl::SetWriteData(UFileT *aFile)
{
    CutOptCodeT opt = CutOptWriteData;
    SetOpt(opt, (UHandleT) aFile->Handle());

    return UErrFalse;
}

/**
 * \brief Callback Function: Write.
 */
UErrCodeT CCutEasyCtl::SetWriteFunc(cut_write_callback aFunc)
{
    CutOptCodeT opt = CutOptWriteFunc;
    kWriteFunc = aFunc;
    SetOpt(opt, cut_write_func);

    return UErrFalse;
}

/**
 * \brief Perform.
 */
UErrCodeT CCutEasyCtl::Perform()
{
    CURLcode curlCode = curl_easy_perform(mHandle);
    UErrCodeT code;
    mType->ToErrCode(&code, curlCode);

    return code;
}

/***** Private A *****/

/**
 * \brief Handle.
 */
UErrCodeT CCutEasyCtl::Handle(CutEasyHT *aHandle)
{
    *aHandle = (CutEasyHT) curl_easy_init();

    return UErrFalse;
}

/**
 * \brief Set Name.
 */
UErrCodeT CCutEasyCtl::SetName(UStringT *aName)
{
    mName = aName->ToA();

    return UErrFalse;
}

/**
 * \brief Set option.
 */
UErrCodeT CCutEasyCtl::SetOpt(CutOptCodeT aOpt, ...)
{
    CURLoption opt;
    mType->ToOpt(&opt, aOpt);

    ClsArgListT list;
    cls_arg_start(list, aOpt);
    curl_easy_setopt(mHandle, opt, list);
    cls_arg_end(list);

    return UErrFalse;
}

/**
 * \brief Clear.
 */
UErrCodeT CCutEasyCtl::Cleanup()
{
    if (mUrl.IsNull() == UErrTrue)
    {
        curl_easy_cleanup((CURL*) mHandle);
    }

    return UErrFalse;
}

/***** Private B *****/

/***** C Implementation A *****/

/**
 * \brief Callback Function: Write.
 */
static size_t cut_write_func(char *aBuffer, size_t aSize, size_t aNumItems,
                             void *aOutStream)
{
    UErrCodeT err = UErrTrue;
    if (kWriteFunc != NULL)
    {
        UStringT buffer = aBuffer;
        err = kWriteFunc(&buffer, (UIntT) aSize, (UIntT) aNumItems,
                         (UHandleT) aOutStream);
    }
    else
    {
        err = kIoStr->Write((UDataT) aBuffer, (UIntT) aSize,
                            (UIntT) aNumItems, (UHandleT) aOutStream);
    }

    return err;
}

/***** C Implementation B *****/
