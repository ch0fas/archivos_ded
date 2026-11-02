CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = build/clase23

$(TARGET): build/clase23.o build/Set.o
	$(CC) $(CFLAGS) $^ -o $@

build/clase23.o: clase23.c data_structures/Set.h
	mkdir -p build
	$(CC) $(CFLAGS) -c clase23.c -o $@

build/Set.o: data_structures/Set.c data_structures/Set.h
	mkdir -p build
	$(CC) $(CFLAGS) -c data_structures/Set.c -o $@

clean:
	rm -rf build
