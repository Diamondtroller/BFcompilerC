# -*- MakeFile -*-
#all goals that are not files
.PHONY: build
.DEFAULT_GOAL := build

BIN_DIR := bin
OBJ_DIR := obj
SRC_DIR := src

BINS := bfc
OBJS := bfc.o

CC := gcc
CPPFLAGS := 
CFLAGS := -std=c99 -O2 -g
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${CC} $^ ${CFLAGS} -c -o $@
${BIN_DIR}/%: ${OBJ_DIR}/%.o
	@${CC} $^ ${CFLAGS} -o $@
build: ${OBJ_DIR}/${OBJS} ${BIN_DIR}/${BINS}
#so that object files don't get deleted
clean:
	@rm -f ${OBJ_DIR}/* ${BIN_DIR}/*
