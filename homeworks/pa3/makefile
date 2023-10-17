CC = gcc
CFLAGS = -Wall -Werror -std=c99

all: div1

div1: div1.s main.c
	$(CC) $(CFLAGS) $^ -o $@

div2: div2.s main.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f div1

