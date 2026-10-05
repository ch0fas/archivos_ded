CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = build/clase15

$(TARGET): build/clase15.o build/Stack.o
	$(CC) $(CFLAGS) $^ -o $@

build/clase15.o: clase15.c data_structures/Stack.h
	mkdir -p build
	$(CC) $(CFLAGS) -c clase15.c -o $@

build/Stack.o: data_structures/Stack.c data_structures/Stack.h
	mkdir -p build
	$(CC) $(CFLAGS) -c data_structures/Stack.c -o $@

clean:
	rm -rf build
