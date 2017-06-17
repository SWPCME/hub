# Makefile
# For hub library.

#
# Options.
#
# Directory.
HUB_DIR = .
OBJ_DIR = $(TMP_DIR)
# Search.
INCLUDE_DIR = -I$(CURRENT_DIR) -I${BASE_DIR} -I$(CORE_DIR) -I$(CLS_DIR) \
	-I$(CCS_DIR) -I$(SYS_DIR) -I$(OGR_DIR) -I$(GDA_DIR) -I$(GSL_DIR) \
	-I$(UST_DIR) -I$(WRAP_DIR) -I$(VTR_DIR) -I$(CTGY_DIR) -I$(RTK_DIR) \
	-I${INSTALL_H_DIR}/gsl/unix

# Include.
HUB_MAKEOPT = $(HUB_DIR)/hub_makeopt.mk
include $(HUB_MAKEOPT)

# Target.
default: target_dir_default create_lib

clean: target_dir_clean clean_lib

install: default target_dir_install install_lib install_header
