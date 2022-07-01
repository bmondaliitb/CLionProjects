cmake_minimum_required(VERSION 3.20)
project(ReadRootFile)
set(CMAKE_CXX_STANDARD 14)
find_package(ROOT 6.22 REQUIRED COMPONENTS Core Smatrix)
add_subdirectory(roofit)
add_executable(ReadRootFile main.cpp)
target_link_libraries(ReadRootFile PUBLIC
        ROOT::RIO
        HistFactory
        RooFit
        RooFitCore
        RooFitMore
        RooStats
        ROOT::Tree
        ROOT::Hist
        ROOT::Core
        )
target_include_directories(ReadRootFile PUBLIC ${CMAKE_SOURCE_DIR}/roofit/histfactory)
target_include_directories(ReadRootFile PUBLIC ${CMAKE_SOURCE_DIR}/roofit/histfactory/inc)
