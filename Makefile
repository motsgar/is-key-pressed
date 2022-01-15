all:
	gcc -o isPressed $(shell pkg-config --libs x11) isPressed.c