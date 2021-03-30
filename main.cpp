#include <iostream>
#include <iomanip>
#include <string>

#include "test_functions.hpp"
#include <stdlib.h>

// argc (argument count) is the number of arguments passed to the command
// argv (argument vector) is the argument in c-string format (rids the need of string header)
// a string is known as an array of characters (below is an array of character arrays)
// char* argv[] == char** argv
int main(int argc, char** argv) {

    int a;
    int b;
    if (argc == 3) {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }


    int test_int = std::atoi("200"); // converts a string of numerical characters to integers (must be integers or else it will throw an error!)
    std::cout << "test_int: " << test_int << std::endl;

    // verify c-string is valid
    const char* x = "0123"; // <-- string literal, also known as a constant string
    // below shows null terminator
    std::cout << static_cast<int>(x[4]) << std::endl; // It should return the integer "0" (check ASCII table)

    // interestingly, you can cast a character to an int and an int to a character, this is because characters store integers
    int char_to_int = 'A'; // integer 65
    char int_to_char = 55; // character '7'
    std::cout << "char to int: " << char_to_int << std::endl;
    std::cout << "int to char: " << int_to_char << std::endl;

    // if our program requires two arguments
    if (argc == 2) {
        // run function here
    }
    else {
        // cerr = standard error stream, it is useful for redirecting error outputs to a different location
        std::cerr << "Incorrect number of arguments" << std::endl;
        exit(1);
    }

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
            std::cout << std::setw(3) << "F:" << std::left << std::setw(5) << table[i][j].first;
            std::cout << std::setw(3) << "S:" << std::left << std::setw(5) << table[i][j].second;
        }
        std::cout << std::endl;
    }
    // free the table at each index
    for (int i = 0; i < 5; i++) {
        delete[] table[i];
    }
    // free the outside table
    delete[] table;
    table = nullptr; // or NULL or 0

    // NOTE: do not use smart pointers for this class!

    // to show linking is working properly
    test_function();
    

    //formatting in-depth
    // std::setw(NUM)
    // std::setprecision(NUM): significant figures, NOT the number of digits after the decimal
    // std::fixed: prevents scientific notation AND in conjunction with std::setprecision, dictates number of digits after decimnal
    // std::showpoint: always show the point
    // left/right: left or right justify
    int value = 123;
    std::cout << "(" << std::setw(5) << value << ")" << std::endl;
    std::cout << "(" << std::setw(2) << value << ")" << std::endl;
    std::cout << "(" << std::setw(3) << value << ")" << std::endl;

    double set_prec_value = 4.55555;

    std::cout << std::setprecision(1) << set_prec_value << std::endl;
    std::cout << std::setprecision(2) << set_prec_value << std::endl;
    std::cout << std::setprecision(3) << set_prec_value << std::endl;
    std::cout << std::setprecision(4) << set_prec_value << std::endl;
    std::cout << std::setprecision(5) << set_prec_value << std::endl;

    std::cout << std::fixed << std::setprecision(1) << set_prec_value << std::endl;
    std::cout << std::fixed << std::setprecision(3) << set_prec_value << std::endl;
    std::cout << std::fixed << std::setprecision(4) << set_prec_value << std::endl;
    std::cout << std::fixed << std::setprecision(5) << set_prec_value << std::endl;

    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    std::cout << set_prec_value << std::endl;
    std::cout << set_prec_value << std::endl;
    std::cout << set_prec_value << std::endl;
    std::cout << set_prec_value << std::endl;
    std::cout << set_prec_value << std::endl;

    std::cout << std::right << std::setw(5) << value << std::endl;
    return 0;
}