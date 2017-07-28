# Makefile
# For wrap.

#
# Options.
#
# Directory.
HUB_DIR = ..
# Search.
INCLUDE_DIR = -I$(HUB_DIR) -I$(VTR_DIR) -I$(CORE_DIR) -I$(CLS_DIR) \
	-I$(CCS_DIR) -I$(UST_DIR) -I$(NCC_DIR)

# Include.
HUB_MAKEOPT = $(HUB_DIR)/hub_makeopt.mk
include $(HUB_MAKEOPT)

default: target_dir_default create_obj

clean: target_dir_clean clean_obj

install: target_dir_install
