cmake_minimum_required(VERSION 3.11)
project(RootTObject)

set(CMAKE_CXX_STANDARD 14)

#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT REQUIRED COMPONENTS RIO Net)

#---Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
include(${ROOT_USE_FILE})

#add_library(libCustomClass SHARED CustomClass.h CustomClass.cpp )

add_executable(RootTObject main.cpp)
target_link_libraries(RootTObject ${ROOT_LIBRARIES} ROOT::Physics AnaAlgorithmLib)

atlas_add_library(RootTObject  xAOD::Core)

