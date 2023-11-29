# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -std=gnu99

# Object files
OBJS = mem_alloc.o main.o

# Name of the executable
TARGET = mem_alloc_test

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

mem_alloc.o: mem_alloc.c mem_alloc.h
	$(CC) $(CFLAGS) -c mem_alloc.c

main.o: main.c mem_alloc.h
	$(CC) $(CFLAGS) -c main.c

# Clean target for cleaning up
clean:
	rm -f $(TARGET) *.o

.PHONY: all clean

