cmake_minimum_required(VERSION 3.31)
project(Cpp_static_inline)

set(CMAKE_CXX_STANDARD 20)

add_executable(Cpp_static_inline main.cpp
        my_utility.h
        file1.cpp
        file2.cpp)
