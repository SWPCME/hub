/******************************************************************************
 * $Id: bsn_uniqueid.cpp 2016-08 $
 *
 * Project:  Business logic library.
 * Purpose:  Unique identifier control implementation.
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

#include "bsn_uniqueid.hpp"

// Module
#include "ust_filestype.hpp"
#include "vtr_ctl.hpp"

// Global variable.
static const UIntT kGroup = 20;

/**
 * \brief Constructor
 *
 * Init the handle of "m_hub" and "m_common".
 */
CBsnUniqueId::CBsnUniqueId()
{
}

/**
 * \brief Destructor
 *
 * Release the handle of "m_hub".
 */
CBsnUniqueId::~CBsnUniqueId()
{
}

/**
 * \brief Initialize
 *
 * @return UErrFalse, if successed; UErrTrue, if failed.
 */
UErrCodeT CBsnUniqueId::Init()
{
    m_hub = CHubCtl::Hub();
    m_vtr = (CVtrCtl*) m_hub->Module(HubMVtr);

    return UErrFalse;
}

/**
 * \brief Set path.
 *
 * Set the path of input, output, and config.
 *
 * @return UErrFalse, if successed; UErrTrue, if failed.
 */
UErrCodeT CBsnUniqueId::SetPath(BsnUniqueIdPathT *aPath)
{
    const UStringT kCfgPath = "config";
    m_path.in = aPath->in;
    m_path.out = aPath->out;
    if (m_path.cfg.IsNull() == UErrFalse)
    {
        // m_files->Cwd(m_path.cfg);
        // m_path.cfg += kCfgPath;
    }

    return UErrFalse;
}

/**
 * \brief Main. 
 *
 * Main business logic for the unique id.
 *
 * @return UErrFalse, if successed; UErrTrue, if failed.
 */
UErrCodeT CBsnUniqueId::Main()
{
    // Traversal directory.
    m_path.in = "../../";
    UFilesT inFiles(m_path.in);
    // for (inFiles(m_path.in).Begin(); inFiles.Next() == UErrTrue; )
    // {
    //     if (inFiles.File() == STR_NULL)
    //     {
    //         continue;
    //     }

    //     // UStringT file = inFiles.File();
    //     // CVtrDataSrcCtl* dataSrc = m_vtr->Load(&file);
    // }

    // Init max id.
    InitMaxId();

    return UErrFalse;
}

/**
 * \brief Init max id from 
 */
UErrCodeT CBsnUniqueId::InitMaxId()
{
    // MMaxIdByGroupIdT* maxIdByGroupId = new MMaxIdByGroupIdT(UContainerMap);
    // m_gToMIdByName(maxIdByGroupId);

    return UErrFalse;
}

/**
 * \brief Get group id by grid id.
 */
UIntT CBsnUniqueId::GroupId(UIntT aGridId)
{
    UIntT groupId = aGridId % kGroup;

    return groupId;
}

/**
 * \brief Get max id by group id and layer name.
 */
UIntT CBsnUniqueId::NewId(UIntT aGroupId, UStringT* aLayerName)
{
    // m_MaxId[aGroupId] += kGroup;

    // return m_maxId[aGroupId];
    return 0;
}

/***** Private A *****/

/***** Private B *****/
