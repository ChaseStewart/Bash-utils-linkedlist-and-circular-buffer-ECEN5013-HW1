
CC=gcc

CFLAGS= -g -std=c99 -Werror -Wall

IPATH = -I./inc

LIBS=

FILES  = test.c
FILES += src/circ_buff.c
FILES += src/double_linklist.c  

all:
	$(CC) $(CFLAGS) $(IPATH) $(FILES) $(LIBS) -o test
	@echo Test Build Complete!

.PHONY: clean

clean:
	@rm -vf test
	@echo Test Executable Removed!
