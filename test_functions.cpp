#include <iostream>
#include "test_functions.hpp"

void test_function() {
    std::cout << "test_function\n";
}

// if the variable is constant, it must be passed to a const parameter
// if the variable is non-constant, it can be passed to a const parameter

// kinds of parameters: const pointers, const value, and both const
// int* a
// int* const b
// const int* c
// const int* const d

void passing_in_pointer(int* int_ptr) {
    std::cout << "passing_in_pointer: " << int_ptr << std::endl;
}

// we cannot change the pointer, but we can derefence and change the integer
void passing_in_const_pointer(int const* int_const_ptr) {
    std::cout << "passing_in_const_pointer: " << int_const_ptr << std::endl;
}

// a semi-useful function (better with a template we will learn later)
// what happens if we don't pass the pointer by reference?
void delete_ptr(int* &ptr) {
    delete ptr;
    ptr = nullptr;
}