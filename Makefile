CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = build/clase16

$(TARGET): build/clase16.o build/Stack.o
	$(CC) $(CFLAGS) $^ -o $@

build/clase16.o: clase16.c data_structures/Stack.h
	mkdir -p build
	$(CC) $(CFLAGS) -c clase16.c -o $@

build/Stack.o: data_structures/Stack.c data_structures/Stack.h
	mkdir -p build
	$(CC) $(CFLAGS) -c data_structures/Stack.c -o $@

clean:
	rm -rf build
