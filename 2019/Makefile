CC = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
CPPFLAGS = -Isrc/

SRC = main.cc slide.cc parser.cc
OBJ = ${SRC:.cc=.o}
BIN = main

.PHONY: all clean

all: ${BIN}

${BIN}: ${OBJ}

gdb: CXXFLAGS += -g
gdb: all

clean:
	${RM} *.o main
