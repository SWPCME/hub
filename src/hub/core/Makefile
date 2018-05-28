# Makefile
# For core.

#
# Options.
#
# Directory.
SRC_DIR = ../..
# Search.
INCLUDE_DIR = -I$(HUB_DIR) -I$(BASE_DIR) -I$(CORE_DIR) -I$(CLS_DIR) \
	-I$(CCS_DIR) -I$(SYS_DIR) -I$(GDA_DIR) -I$(OGR_DIR) -I$(GSL_DIR) \
	-I$(CUT_DIR) -I$(PLP_DIR) -I$(PYC_DIR) -I$(WRAP_DIR) -I$(UST_DIR)

# Include.
OPT_LIST = $(SRC_DIR)/opt.lst
include $(OPT_LIST)

default: target_dir_default create_obj

clean: target_dir_clean clean_obj

install: target_dir_install
