BINFOLDER := bin/
INCFOLDER := include/
SRCFOLDER := source/
OBJFOLDER := obj/

CC := g++
CFLAGS := -Wall -ansi -std=c++11

SRCFILES := $(wildcard source/*.cpp)

all: $(SRCFILES:source/%.cpp=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/finalBinary

obj/%.o: source/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I./include

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*

run:
	cd bin
	./finalBinary
