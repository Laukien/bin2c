CC := gcc
CFLAGS += -ggdb3
CFLAGS += -Wall

all:
	mkdir -p bin
	$(CC) $(CFLAGS) -o bin/bin2c src/main.c
	strip bin/bin2c
