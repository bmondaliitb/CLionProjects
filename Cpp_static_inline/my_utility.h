#ifndef MY_UTILITY_H
#define MY_UTILITY_H

#include <iostream>

// This function is defined in a header.
// 'static' ensures it has internal linkage (visible only within each .cpp that includes this header).
// 'inline' suggests to the compiler to inline it for performance.
static inline int add_one(int x) {
    return x + 1;
}

// Another static inline function
static inline void print_message(const std::string& msg) {
    std::cout << "Message: " << msg << std::endl;
}

#endif // MY_UTILITY_H