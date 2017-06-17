include file.lst

OUT_DIR = ../../../out
CS_HUB_DIR = ../../itpt/cs/hub
CS_OUT_DIR = ${OUT_DIR}/cs
CS_TEST_DIR = ../../test/cs
CS_HUB_LIB_DIR = ${CS_OUT_DIR}
CS_HUB_LIB = cshub.dll
CS_HUB_ADD_MODULE = ust.netmodule,wrap.netmodule
CS_TEST_NAME = TestCtl.exe
CS_TEST_OUT = ${CS_OUT_DIR}/${CS_TEST_NAME}
CSC = mcs
MAKE = make
CSRUN = mono

cpl: hub
#	${CSC} ${CS_OBJ} -t:exe -out:${CS_TEST_OUT} -L ${CS_HUB_LIB_DIR} \
	-r:${CS_HUB_LIB} -addmodule:${CS_HUB_ADD_MODULE}
	${CSC} ${CS_OBJ} -t:exe -out:${CS_TEST_OUT} -L ${CS_HUB_LIB_DIR} \
	-r:${CS_HUB_LIB}

hub:
	${MAKE} -C ${CS_HUB_DIR}

test: cpl
	cd ${CS_OUT_DIR}; ${CSRUN} ${CS_TEST_NAME} 
