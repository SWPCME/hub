include file.lst

OUT_DIR = ../../../../../out
CS_DIR = ../../
CS_HUB_DIR = ../
CS_OUT_DIR = ${OUT_DIR}/cs
CS_TEST_DIR = ${CS_DIR}/../../test/cs
CS_WRAP_MODULE = ${CS_OUT_DIR}/wrap.netmodule
CS_UST_DIR = ust
CS_WRAP_ADD_MODULE = ust.netmodule

# Sofware.
CSC = mcs
MAKE = make

cpl: ust
	${MAKE} -C ${CS_UST_DIR}
	${CSC} ${CS_OBJ} -t:module -out:${CS_WRAP_MODULE} -L ${CS_OUT_DIR} -addmodule:${CS_WRAP_ADD_MODULE}

ust:
	${MAKE} -C ${CS_UST_DIR}

test: cpl
	cd ${CS_TEST_PATH}; make run
