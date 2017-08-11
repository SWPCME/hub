/******************************************************************************
 * $Id: fmd_cfgread.hpp 2017-08 $
 *
 * Project:  FMD (FMD: Fire Model).
 * Purpose:  Config read definition.
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

#ifndef FMD_CFGREAD_HPP_INCLUDED
#define FMD_CFGREAD_HPP_INCLUDED

#include "fmd_base.hpp"

// ust
class UFileT;

class FMD_LIB CFmdCfgRead
{
  public:
    CFmdCfgRead(UFileT *aFile);
    ~CFmdCfgRead();

    UErrCodeT Init();

  protected:
  private:
    UErrCodeT InitPointer();

    UFileT *mFile;
};

#endif  // FMD_CFGREAD_HPP_INCLUDED
