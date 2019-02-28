CC = g++
CXXFLAGS = -std=c++17
CPPFLAGS = -Isrc/

SRC = main.cc
OBJ = ${SRC:.cc=.o}
BIN = main

.PHONY: all clean

all: ${BIN}

${BIN}: ${OBJ}

gdb: CXXFLAGS += -g
gdb: all

clean:
	${RM} *.o main
