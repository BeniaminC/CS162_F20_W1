CC=g++
BIN=main
ARG= -std=c++11 -g

All: $(BIN)

$(BIN): main.cpp test_functions.o test_functions_two.o
	$(CC) $(ARG) main.cpp  test_functions.o test_functions_two.o -o $(BIN)

test_functions.o: test_functions.cpp test_functions.hpp
	$(CC) $(ARG) -c test_functions.cpp

test_functions_two.o: test_functions_two.cpp test_functions_two.hpp
	$(CC) $(ARG) -c test_functions_two.cpp

clean:
	rm -f *.o $(BIN)

