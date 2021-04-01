#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "test_functions.hpp"

//PLEASE NOTE: If you are using valgrind to check for memory leaks, you must include "-g" arg (e.g. "g++ -std=c++11 -g -o main.cpp")

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

        std::cout << "a:" << a << " b:" << b << std::endl;
    }


    int test_int = std::atoi("200"); // converts a string of numerical characters to integers (must be integers or else it will throw an error!)
    std::cout << "test_int: " << test_int << std::endl;

    // verify c-string is valid
    const char* x = "0123"; // <-- string literal, also known as a constant string
    // below shows null terminator
    std::cout << static_cast<int>(x[4]) << std::endl; // It should return the integer 0 (check ASCII table)

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

    std::cout << "argc: " << argc << std::endl; // argc is always the size of the array, starting at 0. So if argc = 2, the array goes from 0 to 1 (inclusive).
    // loop through all the argument
    for (int i = 0; i < argc; ++i) {
        std::cout << i << ": " << argv[i] << std::endl;
    }

    int** table2 = new int*[5];

    // create a 2-d table which contains an array of structs
    TwoNumbers** table = new TwoNumbers*[5];
    // careful, indices are from 0 to 4 (inclusive)
    std::cout << sizeof(table) << " " << sizeof(*table) << " " << table << std::endl;
    for (int i = 0; i < 5; i++) {
        table[i] = new TwoNumbers[5];
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
    std::cout << "(" << std::setw(5) << value << ")" << std::endl; // (123  ) greater than
    std::cout << "(" << std::setw(2) << value << ")" << std::endl; // (123) equal 
    std::cout << "(" << std::setw(3) << value << ")" << std::endl; // (123) Less than

    double set_prec_value = 4.55555;

    std::cout << std::setprecision(1) << set_prec_value << std::endl; // 5
    std::cout << std::setprecision(2) << set_prec_value << std::endl; // 4.6
    std::cout << std::setprecision(3) << set_prec_value << std::endl; // 4.56
    std::cout << std::setprecision(4) << set_prec_value << std::endl; // 4.556
    std::cout << std::setprecision(5) << set_prec_value << std::endl; // 4.5556

    std::cout << std::fixed << std::setprecision(1) << set_prec_value << std::endl; // 4.6
    std::cout << std::fixed << std::setprecision(3) << set_prec_value << std::endl; // 4.556
    std::cout << std::fixed << std::setprecision(4) << set_prec_value << std::endl; // 4.5556
    std::cout << std::fixed << std::setprecision(5) << set_prec_value << std::endl; // 4.55556

    // define the default
    std::cout << std::fixed << std::showpoint << std::setprecision(2); // set this stream manipulation to a default

    std::cout << set_prec_value << std::endl; // the above default should change this

    std::cout << std::right << std::setw(5) << value << std::endl; // right justify it
    
    // how to make a struct (check "testfunctions.hpp" for definition)
    cart_coord obj1;
    // assign values
    obj1.x = 5;
    obj1.y = 2;

    // you can use an initialization list
    cart_coord obj2 = {0, 3};

    // you can also use a designated initilizer
    cart_coord obj3 = { .x = 2, .y = 20};

    // In addition, you can  create constructors for structs (modern C++ programming) LATER DESCRIBED IN COURSE

    cart_coord obj4 = input_data();
    print_data(obj4);

    return 0;
}