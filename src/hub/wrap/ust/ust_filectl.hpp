/******************************************************************************
 * $Id: ust_filetype.hpp 2017-08 $
 *
 * Project:  Universal structrue library.
 * Purpose:  File controler definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-08 ~ 2017, Weiwei Huang
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

#ifndef UST_FILECTL_HPP_INCLUDED
#define UST_FILECTL_HPP_INCLUDED

#include "ust_filebase.hpp"

// cls
#include "cls/cls_base.h"
// ust
#include "ust_stringtype.hpp"

// cls
class CClsStreamFile;
class CClsFormatOutput;

class UST_LIB CUstFileCtl
{
  public:
    CUstFileCtl();
    ~CUstFileCtl();

    UErrCodeT Init();
    UErrCodeT Open(UstFileHT *aFileH, const UStringT *aFileName,
                   UstFileOperCodeT aOper);
    UErrCodeT Close(UstFileHT *aFileH);

    // Read.
    UErrCodeT ReadRow(UStringT *aStr, UstFileHT aFileH);

    // Write.
    UErrCodeT Write(const UStringT *aStr, UstFileHT aFileH);
    UErrCodeT WriteRow(const UStringT *aStr, UstFileHT aFileH);

  protected:
  private:
    UErrCodeT InitPointer();
    UErrCodeT ToFileOper(ClsFileOperCodeT *aDst,
                         const UstFileOperCodeT aSrc);

    CClsStreamFile *mFile;
    CClsFormatOutput *mFrmtOut;
};

#endif  // UST_FILECTL_HPP_INCLUDED
