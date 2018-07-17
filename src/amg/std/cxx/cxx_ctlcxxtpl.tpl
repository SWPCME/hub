[+ AutoGen5 template tpl -*- mode: c++ -*-
################################################################################
# $Id: cxx_ctlcxxtpl.tpl 2018-06 $
#
# Project:  Hub.
# Purpose:  Cxx controler for cxx tpl template.
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
[+ Include "cxx_licencecxxtpl.tpl" +]

#include [+ cxx_include +]

/**
 * \brief Constructor.
 */
[+ class_name +]::[+ class_name +]()
{
}

/**
 * \brief Destructor.
 */
[+ class_name +]::~[+ class_name +]()
{
}

/**
 * \brief Initialize.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT [+ class_name +]::Init()
{
    return UErrFalse;
}

/***** Private A *****/

/**
 * \brief InitPointer.
 *
 * @return UErrFalse, if successful; UErrTrue, if failed.
 */
UErrCodeT [+ class_name +]::InitPointer()
{
    return UErrFalse;
}

/***** Private B *****/
