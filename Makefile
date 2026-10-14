CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = build/clase17

$(TARGET): build/clase17.o build/Queue.o
	$(CC) $(CFLAGS) $^ -o $@

build/clase17.o: clase17.c data_structures/Queue.h
	mkdir -p build
	$(CC) $(CFLAGS) -c clase17.c -o $@

build/Queue.o: data_structures/Queue.c data_structures/Queue.h
	mkdir -p build
	$(CC) $(CFLAGS) -c data_structures/Queue.c -o $@

clean:
	rm -rf build
