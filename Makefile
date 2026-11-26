CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = build/eval3

$(TARGET): build/eval3.o build/List.o build/Set.o
	$(CC) $(CFLAGS) $^ -o $@

build/eval3.o: eval3.c data_structures/List.h data_structures/Set.h data_structures/common.h
	mkdir -p build
	$(CC) $(CFLAGS) -c eval3.c -o $@

build/List.o: data_structures/List.c data_structures/List.h data_structures/common.h
	mkdir -p build
	$(CC) $(CFLAGS) -c data_structures/List.c -o $@

build/Set.o: data_structures/Set.c data_structures/Set.h data_structures/common.h
	mkdir -p build
	$(CC) $(CFLAGS) -c data_structures/Set.c -o $@

clean:
	rm -rf build
