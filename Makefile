CC = gcc
CFLAGS = -Wall

objects = *.o

all: compile
	./a.out < inp.txt

compile:
	clear
	gcc -Wall main.c matrixBag.h matrixBag.c matrix.h matrix.c row.h row.c node.h node.c

debug: 
	valgrind --leak-check=full ./a.out < inp.txt

clean:
	rm -rf $(objects)

purge: clean
	rm -f a.out