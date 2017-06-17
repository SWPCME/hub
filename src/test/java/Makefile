include file.lst

JAVA_OUTPUT_PATH = ../../../output/java
JAVA_MAIN = TestCtl

cpl:
	javac $(JAVA_OBJ) -cp ${JAVA_OUTPUT_PATH} -d ${JAVA_OUTPUT_PATH}

run: cpl
	cd ${JAVA_OUTPUT_PATH}; java $(JAVA_MAIN)
