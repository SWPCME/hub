# Makefile
# For bsn library.

#
# Options.
#
# Directory.
SRC_DIR = ../../..
OBJ_DIR = $(BUILD_DIR)/$(TARGET_OS)/bsn
# Search.
INCLUDE_DIR = -I$(HUB_DIR) -I$(BASE_DIR) -I$(CORE_DIR) -I$(CLS_DIR) \
	-I$(CCS_DIR) -I${GDA_DIR} -I$(OGR_DIR) -I$(GSL_DIR) -I$(CUT_DIR) \
	-I$(PLP_DIR) -I$(WRAP_DIR) -I$(UST_DIR) -I$(RST_DIR) -I$(VTR_DIR) \
	-I$(NCC_DIR) -I$(RTK_DIR) -I$(FMD_DIR) -I$(ERA_DIR)

# Include.
OPT_LST = $(SRC_DIR)/opt.lst
include $(OPT_LST)

default: create_lib

clean: clean_lib

install: default install_lib
