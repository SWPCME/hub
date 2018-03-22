/******************************************************************************
 * $Id: ust_fsfiletype.hpp 2018-01 $
 *
 * Project:  Universal structure library.
 * Purpose:  File system file type definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-01 ~ 2018, Weiwei Huang
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

#ifndef UST_FSFILETYPE_HPP_INCLUDED
#define UST_FSFILETYPE_HPP_INCLUDED

#include "ust_fsbase.hpp"

// base
#include "base_containerdefn.hpp"

// ust
class CUstFsFileCtl;

class UST_LIB UFsFileT
{
  public:
    UFsFileT();
    UFsFileT(const UStringT *aName,
             const UAccessCodeT aAccess = UAccessRead,
             const UFsFileTypeCodeT aType = UFsFileTypeDir);
    ~UFsFileT();

    // Initialize.
    UErrCodeT Init();

    // Set file name.
    UErrCodeT SetHandle(const UStringT *aName,
                        const UAccessCodeT aAccess = UAccessRead,
                        const UFsFileTypeCodeT aType = UFsFileTypeDir);
    // Attribute.
    UStringT Name();
    UStringT DirName();
    UStringT BaseName();
    UFsFileTypeCodeT Type();

    // List file.
    // BCtnStringT Ls(const UIntT aLv = 1);
    // BCtnFsFileT Ls(const UIntT aLv = 1);

    // Remove file.
    UErrCodeT Rm(const UIntT aLv = 1);

  protected:
  private:
    CUstFsFileCtl *mFile;
    UStringT mName;
    UFsFileTypeCodeT mType;
};

#endif  // CLS_FSFILETYPE_HPP_INCLUDED
