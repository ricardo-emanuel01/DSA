all: main

main: main.o avl_tree.o
	gcc main.o avl_tree.o -o main

avl_tree.o: avl_tree.c avl_tree.h
	gcc -std=c99 -Wall -Werror -Werror=vla -c avl_tree.c

main.o: main.c avl_tree.h
	gcc -std=c99 -Wall -Werror -Werror=vla -c main.c
