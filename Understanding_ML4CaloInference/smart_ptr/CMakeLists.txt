cmake_minimum_required(VERSION 3.10)
project(SmartPtr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SmartPtr
    main.cxx
)

target_include_directories(SmartPtr PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
