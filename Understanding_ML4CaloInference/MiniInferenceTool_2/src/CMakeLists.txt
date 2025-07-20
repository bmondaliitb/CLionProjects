cmake_minimum_required(VERSION 3.14)
project(MiniBasicInferenceTool LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all source files
set(SOURCES
    main.cpp
    Accessor.cpp
    InferenceTool.cpp
)

# Add executable target
add_executable(run_tool ${SOURCES})

# Include header directories
target_include_directories(run_tool PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

