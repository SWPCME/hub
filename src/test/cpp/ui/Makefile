# Makefile
# For ui library.

#
# Options.
#
# Directory.
SRC_DIR = ../../..
OBJ_DIR = $(TMP_DIR)/ui
BSN_DIR = $(SRC_DIR)/test/cpp/bsn
# Search.
INCLUDE_DIR = -I$(HUB_DIR) -I$(BASE_DIR) -I$(CORE_DIR) -I$(CCS_DIR) \
	-I$(WRAP_DIR) -I$(UST_DIR) -I$(BSN_DIR) \

# Include.
OPT_LST = $(SRC_DIR)/opt.lst
include $(OPT_LST)

default: create_lib

clean: clean_lib

install: default install_lib
