CC=gcc
CFLAGS= -g -c -O4 -Wall -std=c99

LIB_HEADERS=util.h test.h endian.h

NAME=libibur

.PHONY: clean all lib install

all: lib

lib: bin
	cp $(LIB_HEADERS) bin/$(NAME)/

bin:
	@mkdir bin
	@mkdir bin/$(NAME)
	
remake: clean lib

install:
	cp -r bin/$(NAME) /usr/local/include/
