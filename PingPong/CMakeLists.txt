cmake_minimum_required(VERSION 3.17)
project(PingPong)

set(CMAKE_CXX_STANDARD 14)

add_library(Ball SHARED Ball.h Ball.cpp)
add_library(Player SHARED Player.h Player.cpp)
add_library(setup SHARED setup.h setup.cpp Ball Player)
add_executable(PingPong main.cpp)
target_link_libraries(PingPong setup)