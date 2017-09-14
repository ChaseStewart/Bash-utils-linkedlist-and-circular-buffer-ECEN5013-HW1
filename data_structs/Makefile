
CC=gcc

CFLAGS= -g -std=c99 -Werror -Wall

IPATH  = -I./inc 
IPATH += -I../../Unity/src
IPATH += -I./test

LIBS=

FILES  = unit_test.c
FILES += src/circ_buff.c
FILES += src/double_linklist.c  
FILES += ../../Unity/src/unity.c
FILES += test/testCircBuff.c
FILES += test/testDoubleLinklist.c

all:
	$(CC) $(CFLAGS) $(IPATH) $(FILES) $(LIBS) -o unit_test
	@echo Test Build Complete!

.PHONY: clean

clean:
	@rm -vf unit_test
	@echo Test Executable Removed!
