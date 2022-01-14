all:
	gcc -o isKeyPressed $(shell pkg-config --libs x11) main.c