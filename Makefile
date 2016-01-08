all:
	gcc -Wall -pedantic -std=c99 src/Main.c src/Draw.c src/Erase.c src/Output.c src/Moving.c -Iinclude -o bin/runMe -lncurses
