all: main.o linkedlist.o library.o
	gcc -o playlist main.o linkedlist.o library.o

main.o: main.c linkedlist.c library.c
	gcc -c main.c

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c

library.o: library.c library.h
	gcc -c library.c
run:
	./playlist
