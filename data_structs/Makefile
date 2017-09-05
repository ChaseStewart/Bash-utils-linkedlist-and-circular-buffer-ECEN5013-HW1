
CC=gcc

CFLAGS= -g 

IPATH = -I./inc

LIBS=

FILES  = test.c
FILES += src/circ_buff.c
FILES += src/double_linklist.c  

all:
	$(CC) $(IPATH) $(FILES) $(LIBS) -o test
	@echo Test Build Complete!

.PHONY: clean

clean:
	@rm -vf test
	@echo Test Executable Removed!
