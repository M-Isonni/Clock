CC=clang
CPPCHECK=C:\Program Files\Cppcheck\cppcheck.exe
CFLAGS=-Wall -Werror -Iinclude -Wno-pragma-pack
LDFLAGS=-L. -lSDL2
BINARY=clock
BINARY_TESTS=clock_tests

ifeq ($(OS),Windows_NT)
	BINARY:=$(BINARY).exe
	BINARY_TESTS:=$(BINARY_TESTS).exe
endif

clock: main.o math.o 
	$(CC) -o $(BINARY) $(LDFLAGS) $^

main.o: main.c
	$(CC) -c -o $@ $(CFLAGS) $^
	$(CPPCHECK) $^

tests.o: tests.c
	$(CC) -c -o $@ $(CFLAGS) $<
	$(CPPCHECK) $^

math.o: math.c clock.h
	$(CC) -c -o $@ $(CFLAGS) $<
	$(CPPCHECK) $^

test: tests.o math.o
	$(CC) -o $(BINARY_TESTS) $(LDFLAGS) $^
	./$(BINARY_TESTS)
