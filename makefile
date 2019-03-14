cflags = -Wall -Wextra -g

all: main.o pile.o file.o
	gcc *.o -o main

main.o: main.c
	gcc -c main.c $(cflags)

pile.o: pile.c
	gcc -c pile.c $(cflags)

file.o: file.c
	gcc -c file.c $(cflags)