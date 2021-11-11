CC = gcc
CFLAGS = -Wall

objects = *.o

all: compile
	./a.out < inp.txt

compile:
	clear
	gcc -Wall main.c matrix.h matrix.c row.h row.c node.h node.c

debug: CFLAGS += -g -DDEBUG
debug: all

clean:
	rm -rf $(objects)

purge: clean
	rm -f a.out