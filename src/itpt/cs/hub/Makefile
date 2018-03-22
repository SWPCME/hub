include file.lst

CS_HUB_DIR = ./
OUT_DIR = ../../../../out
CS_OUT_DIR = ${OUT_DIR}/cs
CS_LIB_DIR = ${CS_OUT_DIR}
#CS_WRAP_DIR = wrap
CS_TEST_DIR = ${CS_HUB_DIR}/../../test/cs
CS_HUB_MODULE = ${CS_OUT_DIR}/cshub.netmodule
CS_HUB_DLL = ${CS_OUT_DIR}/cshub.dll
CS_HUB_ADD_MODULE = base.netmodule,wrap.netmodule,ust.netmodule
DOC_DIR = doc
DOC_XML = ${DOC_DIR}/xml
DOC_HTML = ${DOC_DIR}/doc/html
HUB_XML = ${DOC_DIR}/hubcs.html

# Software.
CSC = mcs
MAKE = make

cs: cpl

cpl:
#	mcs ${CS_OBJ} -t:library -out:${CS_HUB_DLL} -doc:${HUB_XML} -addmodule:${CS_WRAP_MODULE}
#	${CSC} ${CS_OBJ} -t:library -out:${CS_HUB_DLL} -L ${CS_LIB_DIR} -addmodule:${CS_HUB_ADD_MODULE}
	${CSC} ${CS_OBJ} -t:library -out:${CS_HUB_DLL}

hub_c:
	${CSC} ${CS_OBJ} -t:module -out:${CS_HUB_MODULE} -L ${CS_LIB_DIR} -addmodule:${CS_HUB_ADD_MODULE}

wrap_c:
	${MAKE} -C ${CS_WRAP_DIR}

xml: cpl
	monodocer -assembly:${CS_DLL} -path:${DOC_XML}

html: xml
	mdoc export-html -o ${DOC_HTML} ${DOC_XML}

test: cpl
	cd ${CS_TEST_PATH}; make run
