CC = gcc
CFLAGS = -Wall -Wextra -g -pthread
OBJ = matrix_mult.o main.o
EXEC = main 

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

matrix_mult.o: matrix_mult.c matrix_mult.h
	$(CC) $(CFLAGS) -c matrix_mult.c

test_main.o: main.c matrix_mult.h
	$(CC) $(CFLAGS) -c test_main.c

clean:
	rm -f $(OBJ) $(EXEC)

