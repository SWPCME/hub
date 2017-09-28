# Makefile
# For ui library.

#
# Options.
#
# Directory.
SRC_DIR = $(WORK_DIR)/src
OBJ_DIR = $(TMP_DIR)/main
UI_DIR = $(HUB_DIR)/../test/cpp/ui
BSN_DIR = $(HUB_DIR)/../test/cpp/bsn
# Search.
INCLUDE_DIR = -I$(UI_DIR) -I$(BSN_DIR) -I$(HUB_DIR) -I$(CCS_DIR) -I$(UST_DIR) 

#
# Include.
#
OPT_LST = ../../opt.lst
include $(OPT_LST)

default: bin_file

clean: clean_obj target_dir_clean
