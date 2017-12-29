# Makefile
# For wrap.

#
# Options.
#
# Directory.
SRC_DIR = ../..
# Search.
INCLUDE_DIR = -I$(HUB_DIR) -I$(BASE_DIR) -I$(VTR_DIR) -I$(UST_DIR) \
	-I$(RST_DIR) -I$(NCC_DIR) -I$(CORE_DIR) -I$(CLS_DIR) -I$(CCS_DIR)

# Include.
OPT_LIST = $(SRC_DIR)/opt.lst
include $(OPT_LIST)

default: target_dir_default create_obj

clean: target_dir_clean clean_obj

install: target_dir_install
