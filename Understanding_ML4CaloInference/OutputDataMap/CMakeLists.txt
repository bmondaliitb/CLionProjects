cmake_minimum_required(VERSION 3.10)
project(OutputDataMap LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OutputDataMap
    main.cxx
)

target_include_directories(OutputDataMap PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
