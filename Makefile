CC=g++
BIN=main
ARG=--std=c++11 -g

All: $(BIN)

$(BIN): main.cpp test_functions.o
	$(CC) $(ARG) main.cpp  test_functions.o -o main

test_functions.o: test_functions.cpp test_functions.hpp
	$(CC) $(ARG) -c test_functions.cpp

clean:
	rm -f *.o $(BIN)