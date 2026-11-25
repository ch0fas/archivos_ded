CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = build/clase30

$(TARGET): build/clase30.o build/Stack.o
	$(CC) $(CFLAGS) $^ -o $@

build/clase30.o: clase30.c data_structures/Stack.h
	mkdir -p build
	$(CC) $(CFLAGS) -c clase30.c -o $@

build/Stack.o: data_structures/Stack.c data_structures/Stack.h
	mkdir -p build
	$(CC) $(CFLAGS) -c data_structures/Stack.c -o $@

clean:
	rm -rf build
