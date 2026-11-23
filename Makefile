CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = build/clase29

$(TARGET): build/clase29.o build/Map.o
	$(CC) $(CFLAGS) $^ -o $@

build/clase29.o: clase29.c data_structures/Map.h
	mkdir -p build
	$(CC) $(CFLAGS) -c clase29.c -o $@

build/Map.o: data_structures/Map.c data_structures/Map.h
	mkdir -p build
	$(CC) $(CFLAGS) -c data_structures/Map.c -o $@

clean:
	rm -rf build
