CC = gcc
CFLAGS = -Wall -Werror -std=c99 -g

all: div1 div2

div1: div1.s main.c
	$(CC) $(CFLAGS) $^ -o $@

div2: div2.s main.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f div1
	rm -f div2
