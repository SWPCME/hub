[+ AutoGen5 template tpl -*- mode: c++ -*-
################################################################################
# $Id: cxx_ctlhxxtpl.tpl 2018-06 $
#
# Project:  Hub.
# Purpose:  Cxx controler for hxx tpl template.
# Author:   Weiwei Huang, 898687324@qq.com
#
################################################################################
# Copyright (c) 2018-06 ~ 2018 Weiwei Huang
#
# This program is free software; you can redistribute it and/or modify it under 
# the terms of the GNU General Public License as published by the Free Software 
# Foundation, either version 3 of the License, or (at your option) any later 
# version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT 
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS 
# FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more 
# details.
#
# You should have received a copy of the GNU General Public License along with 
# this program.  If not, see <http://www.gnu.org/licenses/>.
################################################################################
+]
/* -*- mode: c++ -*- */
[+ Include "cxx_licencehxxtpl.tpl" +]

#ifndef [+ hxx_file_def +]
#define [+ hxx_file_def +]

#include [+ hxx_include +]

/**
 * \brief [+ class_desc +]
 */
class [+ lib +] [+ class_name +]
{
  public:
    [+ class_name +]();
    ~[+ class_name +]();

    UErrCodeT Init();

  protected:
  private:
    UErrCodeT InitPointer();
};

#endif  // [+ hxx_file_def +]
