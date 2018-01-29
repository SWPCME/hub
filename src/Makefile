# Makefile
# For ui library.

#
# Options.
#
# Directory.
SRC_DIR = .
OBJ_DIR = $(TMP_DIR)/main
UI_DIR = $(HUB_DIR)/../ui
BSN_DIR = $(HUB_DIR)/../bsn
# Search.
INCLUDE_DIR = -I$(UI_DIR) -I$(BSN_DIR) -I$(HUB_DIR) -I$(CCS_DIR) -I$(UST_DIR) 

#
# Include.
#
OPT_LIST = $(SRC_DIR)/opt.lst
include $(OPT_LIST)

default:
	make -C ${NAME}

doc:
	make -C ${NAME} doc

clean:
	make -C ${NAME} clean

backup:
	7z a ../.backup/hub_src_$(VERSION).7z ../src
