CC=gcc
CFLAGS= -g -c -O4 -Wall -std=c99

LIB_HEADERS=util.h test.h
LIB_OBJECTS=util.o test.o

NAME=libibur

.PHONY: clean all lib install

all: lib

lib: bin $(LIB_OBJECTS)
	cp $(LIB_HEADERS) bin/$(NAME)/
	ar -rs bin/lib$(NAME).a $(LIB_OBJECTS) 

test: bin $(TEST_OBJECTS)
	gcc $(TEST_OBJECTS) -o bin/test

.c.o:
	$(CC) $(CFLAGS) $< -o $@

bin:
	@mkdir bin
	@mkdir bin/$(NAME)
	
clean:
	rm -rf *.o 
	
remake: clean lib

install:
	cp bin/lib$(NAME).a /usr/local/lib/
	cp -r bin/$(NAME) /usr/local/include/
