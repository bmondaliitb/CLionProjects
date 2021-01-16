cmake_minimum_required(VERSION 3.17)
project(RootTObject)

set(CMAKE_CXX_STANDARD 14)

find_package(ROOT )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(RootTObject main.cpp)
target_compile_definitions(RootTObject ROOT::Physics)