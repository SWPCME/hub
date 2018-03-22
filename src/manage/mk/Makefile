# Makefile
# For ui library.

#
# Options.
#
# Directory.
HUB_DIR = hub
OBJ_DIR = $(TMP_DIR)/main
UI_DIR = $(HUB_DIR)/../ui
BSN_DIR = $(HUB_DIR)/../bsn
# Search.
INCLUDE_DIR = -I$(UI_DIR) -I$(BSN_DIR) -I$(HUB_DIR) -I$(CCS_DIR) -I$(UST_DIR) 

#
# Include.
#
HUB_MAKEOPT = $(HUB_DIR)/hub_makeopt.mk
include $(HUB_MAKEOPT)

default: bin_file

clean: clean_obj target_dir_clean

backup:
	7z a ../.backup/hub_src_$(VERSION).7z ../src
