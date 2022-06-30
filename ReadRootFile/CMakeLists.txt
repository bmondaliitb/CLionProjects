cmake_minimum_required(VERSION 3.20)
project(ReadRootFile)

set(CMAKE_CXX_STANDARD 14)

find_package(ROOT)

add_executable(ReadRootFile main.cpp)
target_link_libraries(ReadRootFile PUBLIC ROOT::RIO ROOT::Net ROOT::Physics ROOT::Tree ROOT::Core ${ROOT_LIBRARIES})
