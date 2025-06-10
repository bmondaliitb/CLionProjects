#include <iostream>

// Declare the functions from other files to call them
void do_something_in_file1();
void do_something_in_file2();

int main() {
    do_something_in_file1();
    do_something_in_file2();

    // You CANNOT call add_one or print_message directly here unless you include "my_utility.h"
    // and they would then be *another* independent copy within main.cpp's translation unit.
    // For example:
    // #include "my_utility.h"
    // int result = add_one(5); // This would be the third independent copy of add_one
    // std::cout << "Main: result = " << result << std::endl;

    return 0;
}