################################################################################
# $Id: prj_optctl.mk 2017-08 $
#
# Project:  Prj.
# Purpose:  Option controler.
# Author:   Weiwei Huang, 898687324@qq.com
#
################################################################################
# Copyright (c) 2016-08 ~ 2017 Weiwei Huang
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

# Project name
PRJ_NAME = 

# Mode
DEBUG = yes
UNIX = yes
CYGWIN = 

# Version
VERSION = 

#
# For "file.lst"
#
# Sub project name
PRJ_SUB_NAME = $(PRJ)
# Sub directory
PRJ_SUB_DIRS = $(SUBDIRS)
# Object
PRJ_OBJ = $(OBJ)
# Header
PRJ_HEADER = $(HEADER)
# Library
PRJ_LIB_SO_NAME = $(LIB_SO_NAME)
PRJ_EXTRA_LIB_DIR = $(EXTRA_LIB_DIR)
PRJ_EXTRA_LIB_SO = $(EXTRA_LIB_SO)

# Directory
SRC_DIR = $(HUB_DIR)
PRJ_DIR = $(SRC_DIR)/../manage/mk
INSTALL_DIR = $(HUB_DIR)/../..

# File
PRJ_HEADER_FILE = $(SRC_DIR)/dir.lst
PRJ_CTL_FILE = $(PRJ_DIR)/prj_ctl.mk
include $(PRJ_CTL_FILE)
