CC = g++
CXXFLAGS = -std=c++17
CPPFLAGS = -Isrc/

SRC = *.cc
OBJ = ${SRC:.cc=*.o}
BIN = main

.PHONY: all clean

all: main

main: *.o

clean:
	${RM} *.o main
