# Makefile
# For ui library.

#
# Options.
#
# Directory.
HUB_DIR = ../../../hub
OBJ_DIR = $(TMP_DIR)/ui
BSN_DIR = $(HUB_DIR)/../test/cpp/bsn
# Search.
INCLUDE_DIR = -I$(HUB_DIR) -I$(BASE_DIR) -I$(CORE_DIR) -I$(CCS_DIR) \
	-I$(WRAP_DIR) -I$(UST_DIR) -I$(BSN_DIR) \

# Include.
HUB_MAKEOPT = $(HUB_DIR)/hub_makeopt.mk
include $(HUB_MAKEOPT)

default: create_lib

clean: clean_lib

install: default install_lib
