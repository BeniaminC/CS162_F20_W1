#ifndef __BEN_FUNCTIONS
#define __BEN_FUNCTIONS

void test_function();

// a struct is a sequence of data that can contain different data types
// C++ allows a set of variables to be combined together into a single unit called a structure.
struct TwoNumbers {
    int first; // 4 bytes
    int second; // 4 bytes
    // total: 8 bytes
}; // don't forget the semicolon!

struct cart_coord {
    double x; // 8 bytes
    double y; // 8 bytes
    // total 16 bytes
};


void passing_in_pointer(int* int_ptr);
void passing_in_const_pointer(int const* int_const_ptr);

void print_data(const cart_coord& data);
cart_coord input_data();

#endif