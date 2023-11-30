# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -std=gnu99
APP = mem_alloc

all: $(APP)

$(APP): main.c $(APP).c
	$(CC) $(CFLAGS) $^ -o $@

test: $(APP).c test_main.c
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c mem_alloc.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(APP) *.o


