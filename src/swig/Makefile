################################################################################
# $Id: Makefile 2017-08 $
#
# Project:  SWIG.
# Purpose:  Makefile.
# Author:   Weiwei Huang, 898687324@qq.com
#
################################################################################
# Copyright (c) 2017-08 ~ 2017 Weiwei Huang
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

# Directory.
SRC_DIR = ..
INCLUDE_DIR = -I$(JAVA_JDK_DIR)/include -I$(JAVA_JDK_DIR)/include/$(JAVA_OS) \
	-I$(PRJ_INSTALL_INCLUDE_DIR)/hub -I$(SRC_DIR)/bsngis

# Include.
OPT_LST = $(SRC_DIR)/opt.lst
include $(OPT_LST)

default: prj_create_swig_$(SWIG_DST_LANG)

clean: prj_clean_swig_obj

install: prj_install_lib_$(SWIG_DST_LANG)
