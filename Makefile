TARGET=singen

OUTPUT_DIR = ./OUTPUT

CPP=g++
CPPFLAGS=-std=c++11

SRC_DIRS=./src
INC_DIRS=./inc

SRC:=$(wildcard ${SRC_DIRS}/*.cpp)

compile: ${SRC}
	@ ${CPP} ${CPPFLAGS} $^ -o ${OUTPUT_DIR}/${TARGET}

${OUTPUT_DIR}:
	@ mkdir -p $@
	@ chmod u+w $@ 

all: ${OUTPUT_DIR} compile

clean:
ifneq ("$(wildcard $(OUTPUT_DIR))","")
	@ rmdir --ignore-fail-on-non-empty ${OUTPUT_DIR}
endif
	
