CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = build/eval3

$(TARGET): build/eval3.o build/List.o build/Set.o build/PriorityQueue.o build/Map.o
	$(CC) $(CFLAGS) $^ -o $@

build/eval3.o: eval3.c data_structures/List.h data_structures/Set.h data_structures/common.h data_structures/PriorityQueue.h
	mkdir -p build
	$(CC) $(CFLAGS) -c eval3.c -o $@

build/List.o: data_structures/List.c data_structures/List.h data_structures/common.h
	mkdir -p build
	$(CC) $(CFLAGS) -c data_structures/List.c -o $@

build/Set.o: data_structures/Set.c data_structures/Set.h data_structures/common.h
	mkdir -p build
	$(CC) $(CFLAGS) -c data_structures/Set.c -o $@

build/PriorityQueue.o: data_structures/PriorityQueue.c data_structures/PriorityQueue.h data_structures/common.h
	mkdir -p build
	$(CC) $(CFLAGS) -c data_structures/PriorityQueue.c -o $@

build/Map.o: data_structures/Map.c data_structures/Map.h data_structures/common.h
	mkdir -p build
	$(CC) $(CFLAGS) -c data_structures/Map.c -o $@

clean:
	rm -rf build
