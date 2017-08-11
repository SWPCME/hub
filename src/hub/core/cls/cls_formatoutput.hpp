/******************************************************************************
 * $Id: cls_formatoutput.hpp 2017-07 $
 *
 * Project:  C language standard library.
 * Purpose:  Format output definition.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017-07 ~ 2017 Weiwei Huang
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

#ifndef CLS_FORMATOUTPUT_HPP_INCLUDED
#define CLS_FORMATOUTPUT_HPP_INCLUDED

#include "cls_base.h"

class CLS_LIB CClsFormatOutput
{
  public:
    CClsFormatOutput();
    ~CClsFormatOutput();

    UErrCodeT Init();

    UErrCodeT ToStr(char *aStr, const char *aFormat, ...);
    UErrCodeT ToCon(const char *aFormat, ...);
    UErrCodeT ToFile(ClsFileHT aFile, const char *aFormat, ...);

  protected:
  private:
};

#endif  // CLS_FORMATOUTPUT_HPP_INCLUDED
