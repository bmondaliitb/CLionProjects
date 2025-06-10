#include "my_utility.h" // Includes the static inline functions again

void do_something_in_file2() {
    int value = 20;
    int new_value = add_one(value); // Calls its own copy of the static inline function
    print_message("Greetings from file2!"); // Calls its own copy
    std::cout << "File2: new_value = " << new_value << std::endl;
}

// int main() { // Only one main is allowed in a program. This is for demonstration.
//     do_something_in_file2();
//     return 0;
// }
