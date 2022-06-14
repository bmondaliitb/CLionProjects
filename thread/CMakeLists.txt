cmake_minimum_required(VERSION 3.17)
project(thread)

set(CMAKE_CXX_STANDARD 14)

add_executable(thread main.cpp)
target_link_libraries(thread pthread)