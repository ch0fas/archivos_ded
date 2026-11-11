CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = build/clase26

$(TARGET): build/clase26.o build/PriorityQueue.o
	$(CC) $(CFLAGS) $^ -o $@

build/clase26.o: clase26.c data_structures/PriorityQueue.h
	mkdir -p build
	$(CC) $(CFLAGS) -c clase26.c -o $@

build/PriorityQueue.o: data_structures/PriorityQueue.c data_structures/PriorityQueue.h
	mkdir -p build
	$(CC) $(CFLAGS) -c data_structures/PriorityQueue.c -o $@

clean:
	rm -rf build
