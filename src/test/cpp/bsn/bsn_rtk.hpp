/******************************************************************************
 * $Id: bsn_rtk.hpp 2017-05 $
 *
 * Project:  Bsn.
 * Purpose:  Rtk test.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2016 ~ 2017 Weiwei Huang
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

#ifndef BSN_RTK_HPP_INCLUDED
#define BSN_RTK_HPP_INCLUDED

#include "bsn_base.hpp"

class CHubCtl;
class CRtkCtl;

class BSN_LIB CBsnRtk
{
  public:
    CBsnRtk();
    ~CBsnRtk();

    UErrCodeT Init();
    UErrCodeT Test();

  protected:
  private:
    // Hub.
    CHubCtl *mHub;

    // Rtk.
    CRtkCtl *mRtk;
};

#endif  // BSN_RTK_HPP_INCLUDED
