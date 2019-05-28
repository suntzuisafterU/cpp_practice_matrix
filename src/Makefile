
CC:=gcc

CPPFLAGS:=
CXXFLAGS:=-g -std=c++17
LDFLAGS:=

# SRCS:=Common.cpp

.PHONY: all clean

all: Common DestructorConstructor Matrix

Common: Common.cpp

DestructorConstructor: DestructorConstructor.cpp

Matrix: Matrix.cpp Utils.cpp

clean:
	rm -f Common
	rm -f DestructorConstructor
	rm -f Utils
	rm -f Matrix
	rm -rf Common.dSYM
	rm -rf DestructorConstructor.dSYM
	rm -rf Matrix.dSYM
	rm -rf Utils.dSYM


