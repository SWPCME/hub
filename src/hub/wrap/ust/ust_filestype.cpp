/******************************************************************************
 * $Id: ust_filestype.hpp 2016-08 $
 *
 * Project:  Universal structrue library.
 * Purpose:  File system structrue type implemention.
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

#include "ust_filestype.hpp"

// Module
#include "base_ctl.hpp"
#include "wrap_ctl.hpp"
#include "ust_ctl.hpp"
#include "ust_filesctl.hpp"

/**
 * \brief Constructor.
 */
UFilesT::UFilesT()
{
    Init();
}

/**
 * \brief Constructor.
 *
 * @param aPath the path of root.
 */
UFilesT::UFilesT(UStringT* aPath)
{
    Init();
    SetPath(aPath);
}

/**
 * \brief Constructor.
 *
 * @param aPath the path of root.
 */
UFilesT::UFilesT(UStringT& aPath)
{
    Init();
    SetPath(&aPath);
}

/**
 * \brief Destructor.
 */
UFilesT::~UFilesT()
{
}

/**
 * \brief Set the path of root.
 *
 * If you use the "UFilesT(UStringT*)" or "UFilesT(UStringT&)", 
 * this function is already to be used;
 * else must use this function first.
 *
 * @param aPath the path of the root for this class.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT UFilesT::SetPath(UStringT* aPath)
{
    m_files->Ftw(aPath);
    Begin();

    return UErrFalse;
}

/**
 * \brief Get count of the file and path elements.
 *
 * @return Number of the file and path elements, if successed; 0, if failed.
 */
UIntT UFilesT::Count()
{
    // return m_fileSysCtn.Count();
    return 0;
}

/**
 * \brief Set the current site to the begin.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT UFilesT::Begin()
{
    return UErrFalse;
}

/**
 * \brief Set the current site to the end.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT UFilesT::End()
{
    return UErrFalse;
}

/**
 * \brief Set the current site to next.
 */
UErrCodeT UFilesT::Next()
{
    return UErrFalse;
}

/**
 * \brief Set the current site to previous.
 */
UErrCodeT UFilesT::Prev()
{
    return UErrFalse;
}

/**
 * \brief Get complete directory by directory name.
 *
 * @param aName Name of directory, or NULL, means the current directory.
 *
 * @return Complete directory, if successful; NULL, if failed.
 */
UStringT UFilesT::Dir(UStringT* aName)
{
    UStringT str;

    return str;
}

/**
 * \brief Get complete file by the name of file and directory.
 *
 * @return Complete file that contains the path and directory, if successful; 
 * NULL, if failed.
 */
UStringT UFilesT::File(UStringT* aFileName, UStringT* aDirName)
{
    UStringT str;

    return str;
}

/**
 * \brief Get current
 */

/***** Private A *****/

/**
 * \brief Initialize.
 *
 * If you construct this class, this function must use before you use any other 
 * function in this class.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT UFilesT::Init()
{
    CBaseCtl *baseCtl = CBaseCtl::Base();
    CWrapCtl* wrapCtl = baseCtl->Wrap();
    CUstCtl* ustCtl = wrapCtl->Ust();
    m_files = ustCtl->Files();
    m_filesCtn.Init(UContainerMList);

    return UErrFalse;
}

/**
 * \brief Traversal directory. 
 *
 * To get the path and filename.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT UFilesT::Traversal()
{
    return UErrFalse;
}

/***** Private B *****/
