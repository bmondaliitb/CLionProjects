cmake_minimum_required(VERSION 3.16)
project(ReadRootFile)
set(CMAKE_CXX_STANDARD 14)
find_package(ROOT 6.22 REQUIRED COMPONENTS Core Smatrix)
add_subdirectory(roofit)
add_executable(histfitter main.cpp)
target_link_libraries(histfitter PUBLIC
        ROOT::Core
        HistFactory
        RooFit
        RooFitCore
        RooFitMore
        RooStats
        )
target_include_directories(histfitter PUBLIC ${CMAKE_SOURCE_DIR}/roofit/histfactory)
target_include_directories(histfitter PUBLIC ${CMAKE_SOURCE_DIR}/roofit/histfactory/inc)
