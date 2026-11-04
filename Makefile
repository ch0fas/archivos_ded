CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = build/clase24

$(TARGET): build/clase24.o build/Set.o
	$(CC) $(CFLAGS) $^ -o $@

build/clase24.o: clase24.c data_structures/Set.h
	mkdir -p build
	$(CC) $(CFLAGS) -c clase24.c -o $@

build/Set.o: data_structures/Set.c data_structures/Set.h
	mkdir -p build
	$(CC) $(CFLAGS) -c data_structures/Set.c -o $@

clean:
	rm -rf build
