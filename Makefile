CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = build/clase25

$(TARGET): build/clase25.o build/Set.o
	$(CC) $(CFLAGS) $^ -o $@

build/clase25.o: clase25.c data_structures/Set.h
	mkdir -p build
	$(CC) $(CFLAGS) -c clase25.c -o $@

build/Set.o: data_structures/Set.c data_structures/Set.h
	mkdir -p build
	$(CC) $(CFLAGS) -c data_structures/Set.c -o $@

clean:
	rm -rf build
