# Makefile
# For ui library.

#
# Options.
#
# Directory.
# SRC_DIR = $(WORK_DIR)/src
SRC_DIR = ../..
OBJ_DIR = $(BUILD_DIR)/$(TARGET_OS)/main
UI_DIR = $(HUB_DIR)/../test/cpp/ui
BSN_DIR = $(HUB_DIR)/../test/cpp/bsn
# Search.
INCLUDE_DIR = -I$(UI_DIR) -I$(BSN_DIR) -I$(HUB_DIR) -I$(CCS_DIR) -I$(UST_DIR) 

#
# Include.
#
OPT_LIST = $(SRC_DIR)/opt.lst
include $(OPT_LIST)

default: bin_file

clean: clean_obj target_dir_clean
