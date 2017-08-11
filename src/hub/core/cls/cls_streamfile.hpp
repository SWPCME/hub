/******************************************************************************
 * $Id: cls_streamfile.hpp 2017-08 $
 *
 * Project:  C language standard library.
 * Purpose:  Stream file definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-08 ~ 2017 Weiwei Huang
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

#ifndef CLS_STREAMFILE_HPP_INCLUDED
#define CLS_STREAMFILE_HPP_INCLUDED

#include "cls_base.h"

// ust
#include "ust/ust_stringtype.hpp"

// cls
class CClsTypeCtl;
class CClsFileChar;
class CClsFileStr;
class CClsFileLine;
class CClsFileBlock;

class CLS_LIB CClsStreamFile
{
  public:
    CClsStreamFile();
    ~CClsStreamFile();

    UErrCodeT Init();

    // File handle.
    UErrCodeT Open(ClsFileHT *aFileH, const UStringT *aFile,
                   const ClsFileOperCodeT aOper);
    UErrCodeT Close(ClsFileHT *aFileH);
    UErrCodeT CloseAll();

    // File operator controler.
    CClsFileChar *Char();
    CClsFileStr *Str();
    CClsFileLine *Line();
    CClsFileBlock *Block();

    UErrCodeT Read(UIntT *aRealCount, UDataT aData, UIntT aSize,
                   UIntT aCount, ClsFileHT aFileH);
    UErrCodeT Write(const UDataT aData, UIntT aSize, UIntT aCount, 
                    ClsFileHT aFileH);

  protected:
  private:
    UErrCodeT InitPointer();

    CClsTypeCtl *mType;
    CClsFileChar *mChar;
    CClsFileStr *mStr;
    CClsFileLine *mLine;
    CClsFileBlock *mBlock;
};

#endif  // CLS_STREAMFILE_HPP_INCLUDED
