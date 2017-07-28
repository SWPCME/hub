# Makefile
# For core.

#
# Options.
#
# Directory.
HUB_DIR = ..
# Search.
INCLUDE_DIR = -I$(HUB_DIR) -I$(BASE_DIR) -I$(CORE_DIR) -I$(CLS_DIR) \
	-I$(CCS_DIR) -I$(SYS_DIR) -I$(GDA_DIR) -I$(OGR_DIR) -I$(GSL_DIR) \
	-I$(CUT_DIR) -I$(WRAP_DIR) -I$(UST_DIR)

# Include.
HUB_MAKEOPT = $(HUB_DIR)/hub_makeopt.mk
include $(HUB_MAKEOPT)

default: target_dir_default create_obj

clean: target_dir_clean clean_obj

install: target_dir_install
