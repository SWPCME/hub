/******************************************************************************
 * $Id: sys_threadsctl.cpp 2016-09 $
 *
 * Project:  System library.
 * Purpose:  Set of thread (have relation to routines) control implemention.
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

#include "sys_threadsctl.hpp"

// Posix thread library.
#include <pthread.h>

// Module.
#include "sys_threadctl.hpp"

/**
 * \brief Constructor.
 */
CSysThreadsCtl::CSysThreadsCtl() : m_threadCtn(UContainerList)
{
}

/**
 * \brief Destructor.
 */
CSysThreadsCtl::~CSysThreadsCtl()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT CSysThreadsCtl::Init()
{
    return UErrFalse;
}

/**
 * \brief Create thread.
 *
 * @param aHandle Handle of thread.
 *
 * @return Thread control, if successful; NULL, if failed.
 */
CSysThreadCtl* CSysThreadsCtl::Create(ThreadHandleT* aHandle)
{
    // pthread_t* id = (pthread_t*) &aHandle->id;
    // pthread_attr_t* attr = (pthread_attr_t*) aHandle->attr;
    // ThreadFuncT* func = &aHandle->func;
    // ThreadFuncHT funcH = func->handle;
    // ThreadFuncAT funcA = func->arg;
    // pthread_create(id, attr, funcH, funcA);
    // CSysThreadCtl* thread = new CSysThreadCtl(aHandle);
    // m_threadCtn.Add(thread);

    // return thread;
    return NULL;
}

/**
 * \brief Exit thread.
 */
UErrCodeT CSysThreadsCtl::Exit(CSysThreadCtl* aThread)
{
    // pthread_t* id = (pthread_t*) &aHandle->id;

    return UErrFalse;
}

/**
 * \brief Exit all thread.
 */
UErrCodeT CSysThreadsCtl::ExitAll()
{
    return UErrFalse;
}
