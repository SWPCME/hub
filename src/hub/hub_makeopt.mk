################################################################################
# $Id: hub_makeopt.mk 2017-06 $
#
# Project:  Hub.
# Purpose:  Make options.
# Author:   Weiwei Huang, 898687324@qq.com
#
################################################################################
# Copyright (c) 2016 ~ 2017 Weiwei Huang
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

#
# Options.
#
# Mode
DEBUG = yes
UNIX = yes
CYGWIN = 
# Version
VERSION = 0.01

# Tools.
# Compile tools.
ifeq ($(UNIX), yes)
CC = gcc
CXX = g++
LD = g++
endif
ifeq ($(MINGW), yes)
CC = x86_64-w64-mingw32-gcc
CXX = x86_64-w64-mingw32-g++
LD = x86_64-w64-mingw32-g++
endif
ifeq ($(CYGWIN), yes)
CC = gcc
CXX = g++
LD = g++
endif
AR = ar
RANLIB = ranlib
# Script tools.
MAKE = make
# File system tools.
MKDIR = mkdir
RMDIR = rmdir
RM = rm
CD = cd
CP = cp
MV = mv

# Suffix.
OBJ_EXT = o

# Compile flags.
# Diff:-fPIC, -fpic and -fPIE.
C_CXX_FLAG = -fpic -Wall
C_FLAG = $(C_CXX_FLAG)
CXX_STD = -std=c++11
CXX_WARNING = -Wno-delete-incomplete
CXX_FLAG = $(C_CXX_FLAG) $(CXX_STD) $(CXX_WARNING)
ifeq ($(DEBUG), yes)
C_FLAG += -g
CXX_FLAG += -g
endif
INCLUDE_PATH_FLAG = -I
LIB_PATH_FLAG = -L
LD_FLAG = -shared -fpic
STATIC_FLAG = -Wl,-Bstatic
DYNAMIC_FLAG = -Wl,-Bdynamic

# Directory
ifeq ($(WORK_DIR),)
WORK_DIR = .
endif
CURRENT_DIR = .
ifeq ($(HUB_DIR),)
HUB_DIR = .
endif
# Options file.
ifeq ($(FILE_DIR),)
FILE_DIR = .
endif
# Install directory.
INSTALL_DIR = $(HUB_DIR)/../..
INSTALL_H_DIR = $(INSTALL_DIR)/include
INSTALL_L_DIR = $(INSTALL_DIR)/lib
INSTALL_O_DIR = $(INSTALL_DIR)/out/cpp
INSTALL_O_TO_SRC_DIR = ../src
# Module directory.
# Base directory.
BASE_DIR = ${HUB_DIR}/base
# Core directory.
CORE_DIR = $(HUB_DIR)/core
CLS_DIR = $(CORE_DIR)/cls
CCS_DIR = $(CORE_DIR)/ccs
SYS_DIR = $(CORE_DIR)/sys
OGR_DIR = $(CORE_DIR)/ogr
GDA_DIR = ${CORE_DIR}/gda
GSL_DIR = ${CORE_DIR}/gsl
CUT_DIR = ${CORE_DIR}/cut
# Wrap directory.
WRAP_DIR = $(HUB_DIR)/wrap
UST_DIR = $(WRAP_DIR)/ust
VTR_DIR = $(WRAP_DIR)/vtr
NCC_DIR = $(WRAP_DIR)/ncc
# Ctgy directory.
CTGY_DIR = ${HUB_DIR}/ctgy
EARTH_DIR = ${CTGY_DIR}/earth
RTK_DIR = ${EARTH_DIR}/rtk
FMD_DIR = ${CTGY_DIR}/fmd

# Include
FILE_LIST = $(FILE_DIR)/file.lst
ifeq ($(FILE_LIST), $(wildcard $(FILE_LIST)))
include $(FILE_LIST)
endif

# Temporary directory.
TMP_DIR = $(INSTALL_O_DIR)/.tmp

# Compile.
# Generic library rules.
ifeq ($(OBJ_DIR),)
OBJ_DIR = $(TMP_DIR)
endif
OBJ_NAME = $(OBJ:.o=.$(OBJ_EXT))
OBJ_FILE = $(foreach file, $(OBJ_NAME), $(OBJ_DIR)/$(file))
ifeq ($(LIB_NAME),)
LIB_NAME =
endif
LIB_PREFIX = lib
# Static library.
LIB_A_NAME_TMP = $(foreach name, $(LIB_A_NAME), \
	$(addprefix $(LIB_PREFIX), $(name)))
LIB_A_SUFFIX = a
LIB_A = $(foreach lib, $(LIB_A_NAME_TMP), \
	$(addsuffix .$(LIB_A_SUFFIX), $(lib)))
LIB_A_ABS = $(foreach lib, $(LIB_A), \
	$(addprefix $(TMP_DIR)/, $(lib)))
IMPORT_LIB_A = $(foreach lib_a, $(LIB_A), \
	$(STATIC_FLAG) $(lib_a))
# Dynamic library.
LIB_SO_NAME_TMP = $(foreach name, $(LIB_SO_NAME), \
	$(addprefix $(LIB_PREFIX), $(name)))
ifeq ($(UNIX), yes)
LIB_SO_SUFFIX = so
else
LIB_SO_SUFFIX = dll
endif
LIB_SO = $(foreach lib, $(LIB_SO_NAME_TMP), \
	$(addsuffix .$(LIB_SO_SUFFIX), $(lib)))
LIB_SO_ABS = $(foreach lib, $(LIB_SO), \
	$(addprefix $(TMP_DIR)/, $(lib)))
ifeq ($(UNIX), yes)
IMPORT_LIB_SO = $(foreach lib_so, $(LIB_SO), \
	$(DYNAMIC_FLAG) $(lib_so))
else
IMPORT_LIB_SO = -L. -lgdal
endif

# Test for library.
ifneq ($(UNIX), yes)
LIB_OFF = yes
else # ifneq ($(UNIX), yes)
ifneq ($(LIB_A_NAME),)
ifneq ($(LIB_SO_NAME),)
LIB_A_SO_ON = yes
else # ifneq ($(LIB_A_NAME),)
LIB_A_ON = yes
endif # ifneq ($(LIB_SO_NAME),)
else # ifneq ($(LIB_A_NAME),)
ifneq ($(LIB_SO_NAME),)
LIB_SO_ON = yes
else # ifneq ($(LIB_SO_NAME),)
LIB_OFF = yes
endif # ifneq ($(LIB_SO_NAME),)
endif # ifneq ($(LIB_A_NAME),)
endif # ifneq ($(UNIX), yes)

# Subdirectories.
TARGET_DIR_DEFAULT = $(foreach dir, $(SUBDIRS), $(dir)_target_default)
TARGET_DIR_CLEAN = $(foreach dir, $(SUBDIRS), $(dir)_target_clean)
TARGET_DIR_INSTALL = $(foreach dir, $(SUBDIRS), $(dir)_target_install)

#
# Defalut target
#
default:

%.$(OBJ_EXT): %.c
	$(CC) $(INCLUDE_DIR) $(C_FLAG) -c $< -o $(OBJ_DIR)/$@

%.$(OBJ_EXT): %.cpp
	$(CXX) $(INCLUDE_DIR) $(CXX_FLAG) -c $< -o $(OBJ_DIR)/$@

# Default rules for handling subdirectories.
target_dir_default: $(TARGET_DIR_DEFAULT)

target_dir_clean: $(TARGET_DIR_CLEAN)

target_dir_install: $(TARGET_DIR_INSTALL)

%_target_default:
	$(MAKE) -C $*

%_target_clean:
	$(MAKE) -C $* clean

%_target_install:
	$(MAKE) -C $* install

#
# Create
#
# Create object out
create_obj: $(OBJ_NAME)

# Create directory
create_tmp:
	$(shell if [ ! -d $(OBJ_DIR) ]; then $(MKDIR) $(OBJ_DIR); fi)

#
# Clean
#
clean_obj: 
	$(RM) -f $(OBJ_FILE)

clean_tmp: clean_obj
	$(RMDIR) $(TMP_DIR)

clean_lib: clean_obj
	$(RM) -f $(LIB_A)
	$(RM) -f $(LIB_SO)

#
# Library.
#
ifeq ($(LIB_A_SO_ON),yes)
create_lib: create_tmp lib_a lib_so
endif
ifeq ($(LIB_A_ON),yes)
create_lib: create_tmp lib_a
endif
ifeq ($(LIB_SO_ON),yes)
create_lib: create_tmp lib_so
endif
ifeq ($(LIB_OFF),yes)
create_lib:
endif

lib_a: create_obj
	$(AR) r $(LIB_A) $(OBJ_DIR)/*.$(OBJ_EXT)
	$(RANLIB) $(LIB_A_ABS)

lib_so: create_obj
	$(LD) $(LD_FLAG) $(OBJ_DIR)/*.$(OBJ_EXT) $(EXTRA_LIB_DIR) $(EXTRA_LIB_SO) \
		  -o $(LIB_SO_ABS)

#
# Install
#

# Library.
ifeq ($(LIB_A_SO_ON),yes)
install_lib: install_a_lib install_so_lib
endif
ifeq ($(LIB_A_ON),yes)
install_lib: install_a_lib
endif
ifeq ($(LIB_SO_ON),yes)
install_lib: install_so_lib
endif
ifeq ($(LIB_OFF),yes)
install_lib: copy_obj
endif

install_a_lib: create_lib
	($(CP) $(LIB_A_ABS) $(INSTALL_O_DIR))

install_so_lib: create_lib
	($(CP) $(LIB_SO_ABS) $(INSTALL_O_DIR))

copy_obj: create_obj
	($(CP) $(OBJ_DIR)/*.$(OBJ_EXT) $(INSTALL_O_DIR))

# Include.
HUB_INSTALL_H_DIR = $(INSTALL_H_DIR)/hub
PRJ_INSTALL_H_DIR = $(HUB_INSTALL_H_DIR)/$(PRJ)
install_header:
	$(shell if [ ! -d $(HUB_INSTALL_H_DIR) ]; then $(MKDIR) $(HUB_INSTALL_H_DIR); fi)
	$(shell if [ ! -d $(PRJ_INSTALL_H_DIR) ]; then $(MKDIR) $(PRJ_INSTALL_H_DIR); fi)
	$(shell for file in $(HEADER); do $(CP) $$file $(PRJ_INSTALL_H_DIR); done)

#
# Binary file.
#
ifeq ($(UNIX), yes)
bin_file: create_tmp create_obj target_dir_install
	($(CD) $(INSTALL_O_DIR); \
		$(CXX) $(CXX_FLAG) $(OBJ_DIR)/*.$(OBJ_EXT) \
		-o $(BIN_FILE) -L$(LIB_DIR) $(IMPORT_LIB_A) $(IMPORT_LIB_SO))
else
bin_file: create_tmp create_obj target_dir_install
	($(CP) $(OBJ_DIR)/*.$(OBJ_EXT) $(INSTALL_O_DIR))
	($(CD) $(INSTALL_O_DIR); \
		$(CXX) $(CXX_FLAG) *.$(OBJ_EXT) -L$(LIB_DIR) $(IMPORT_LIB_A) \
		$(IMPORT_LIB_SO) -o $(BIN_FILE))
endif
