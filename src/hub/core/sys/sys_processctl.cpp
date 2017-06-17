/******************************************************************************
 * $Id: sys_processctl.cpp 2016-09 $
 *
 * Project:  System library.
 * Purpose:  Process control implemention.
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

#include "sys_processctl.hpp"

// Module
#include "sys_threadsctl.hpp"

/**
 * \brief Constructor.
 */
CSysProcessCtl::CSysProcessCtl()
{
    m_threadsCtn.Init(UContainerMList);
}

/**
 * \brief Destructor.
 */
CSysProcessCtl::~CSysProcessCtl()
{
}

/**
 * \brief Initialize.
 */
UErrCodeT CSysProcessCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Create thread.
 *
 * @param aHandle Handle of thread.
 *
 * @return Threads control, if successful; NULL, if failed.
 */
CSysThreadsCtl* CSysProcessCtl::Create()
{
    CSysThreadsCtl* threads = new CSysThreadsCtl();
    m_threadsCtn.Add(threads);

    return threads;
}

/**
 * \brief Exit thread.
 *
 * @param aHandle Handle of threads.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CSysProcessCtl::Exit(CSysThreadsCtl* aThreads)
{
    return m_threadsCtn.Del(aThreads);
}

/**
 * \brief Exit all thread.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CSysProcessCtl::ExitAll()
{
    return m_threadsCtn.Clear();
}
