CC = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O3
CPPFLAGS = -I.

SRC = main.cc slide.cc parser.cc vertical.cc
OBJ = ${SRC:.cc=.o}
BIN = main

.PHONY: all clean

all: ${BIN}

${BIN}: ${OBJ}

gdb: CXXFLAGS += -g
gdb: all

clean:
	${RM} *.o main
