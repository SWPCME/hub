include file.lst

CS_OUTPUT_PATH = ../../../output/cs
CS_TEST_PATH = ../../test/cs
CS_DLL = HubCs.dll
DOC_DIR = doc
DOC_XML = ${DOC_DIR}/xml
DOC_HTML = ${DOC_DIR}/doc/html
HUB_XML = ${DOC_DIR}/hubcs.html

cs: html

cpl:
	mcs ${CS_OBJ} -t:library -out:${CS_DLL} -doc:${HUB_XML}

xml: cpl
	monodocer -assembly:${CS_DLL} -path:${DOC_XML}

html: xml
	mdoc export-html -o ${DOC_HTML} ${DOC_XML}

test: cpl
	cd ${CS_TEST_PATH}; make run
