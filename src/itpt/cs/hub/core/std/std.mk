include file.lst

OUT_DIR = ../../../../../../out
CS_DIR = ../../../
CS_OUT_DIR = ${OUT_DIR}/cs
CS_TEST_DIR = ${CS_DIR}/../../test/cs
CS_MODULE = ${CS_OUT_DIR}/csstd.netmodule
CSC = mcs

cpl:
	${CSC} ${CS_OBJ} -t:module -out:${CS_MODULE}
