cmake_minimum_required(VERSION 3.20)
project(ReadRootFile)

set(CMAKE_CXX_STANDARD 14)

find_package(ROOT 6.22 REQUIRED COMPONENTS Core HistFactory)

add_executable(ReadRootFile main.cpp)
target_link_libraries(ReadRootFile PUBLIC ROOT::RIO ROOT::Net ROOT::Physics ROOT::RooFit ROOT::Tree ROOT::Hist ROOT::Core ${ROOT_LIBRARIES})
target_include_directories(ReadRootFile PUBLIC ${ROOT_INCLUDE_DIRS})
