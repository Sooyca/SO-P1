main: main.c
	gcc main.c -pthread -std=c99 -Wall -Werror -o main

run: main
	./main
