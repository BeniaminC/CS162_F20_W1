#include <iostream>
#include <iomanip>
#include <string>

#include "test_functions.hpp"
#include <stdlib.h>


// argc (argument count) is the number of arguments passed to the command
// argv (argument vector) is the argument in c-string format (rids the need of string header)
// a string is known as an array of characters (below is an array of character arrays)
// char* argv[] == char** argv
int main(int argc, char const** argv) {

    std::cout << "argc: " << argc << std::endl;
    // loop through all the argument
    for (int i = 0; i < argc; ++i) {
        std::cout << i << ": " << argv[i] << std::endl;
    }
    // create a 2-d table which contains an array of structs
    two_numbers** table = new two_numbers*[5];
    // careful, indices are from 0 to 4 (inclusive)
    std::cout << sizeof(table) << " " << sizeof(*table) << " " << table << std::endl;
    for (int i = 0; i < 5; i++) {
        table[i] = new two_numbers[5];
        for (int j = 0; j < 5; j++) {
            // careful, C++ starts at 0
            table[i][j].first = i + j;
            table[i][j].second = i - j;
            
            // print the values
            std::cout << std::setw(5) << "F" << table[i][j].first;
            std::cout << std::setw(5) << "S:" << table[i][j].second;
        }
        std::cout << std::endl;
    }
    // free the table at each index
    for (int i = 0; i < 5; i++) {
        delete[] table[i];
    }
    // free the outside table
    delete[] table;
    table = nullptr; // or NULL

    // to show linking is working properly
    test_function();
    

    return 0;
}