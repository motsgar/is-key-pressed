all:
	gcc -o isPressed $(shell pkg-config --libs x11) isPressed.c

install: all
	mkdir -p $(HOME)/.local/bin
	cp isPressed $(HOME)/.local/bin