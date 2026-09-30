CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = build/clase14

$(TARGET): build/clase14.o build/Vec3.o
	$(CC) $(CFLAGS) $^ -o $@

build/clase14.o: clase14.c shapes/Vec3.h
	mkdir -p build
	$(CC) $(CFLAGS) -c clase14.c -o $@

build/Vec3.o: shapes/Vec3.c shapes/Vec3.h
	mkdir -p build
	$(CC) $(CFLAGS) -c shapes/Vec3.c -o $@

clean:
	rm -rf build
