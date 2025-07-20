cmake_minimum_required(VERSION 3.10)
project(SharedPtr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SharedPtr
    main.cxx
)

target_include_directories(SharedPtr PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
