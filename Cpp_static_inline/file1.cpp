#include "my_utility.h" // Includes the static inline functions

void do_something_in_file1() {
    int value = 10;
    int new_value = add_one(value); // Calls the static inline function
    print_message("Hello from file1!"); // Calls another static inline function
    std::cout << "File1: new_value = " << new_value << std::endl;
}

// int main() { // Only one main is allowed in a program. This is for demonstration.
//     do_something_in_file1();
//     return 0;
// }