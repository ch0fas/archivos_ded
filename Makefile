CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = build/clase28

$(TARGET): build/clase28.o build/PriorityQueue.o
	$(CC) $(CFLAGS) $^ -o $@

build/clase28.o: clase28.c data_structures/PriorityQueue.h
	mkdir -p build
	$(CC) $(CFLAGS) -c clase28.c -o $@

build/PriorityQueue.o: data_structures/PriorityQueue.c data_structures/PriorityQueue.h
	mkdir -p build
	$(CC) $(CFLAGS) -c data_structures/PriorityQueue.c -o $@

clean:
	rm -rf build
