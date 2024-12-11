#cmake_minimum_required(VERSION 3.21)
cmake_minimum_required(VERSION 3.19)

#Project name
project(TTGammaAnalysis VERSION 1.0)
#C++ Standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# This package uses ROOT
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
find_package(ROOT CONFIG REQUIRED )
#find_package(ROORARFIT CONFIG REQUIRED)


#---Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
include(${ROOT_USE_FILE})

# This is required for ROOT < 6.16
string(REPLACE "-L " "-L" ROOT_EXE_LINKER_FLAGS "${ROOT_EXE_LINKER_FLAGS}")

# This is required on if there is more than one flag 
separate_arguments(ROOT_EXE_LINKER_FLAGS)


root_generate_dictionary(G__Analysis 
  ${CMAKE_CURRENT_SOURCE_DIR}/RooMyPDF_BW.h
  #${CMAKE_CURRENT_SOURCE_DIR}/tree_class.h
  #${CMAKE_CURRENT_SOURCE_DIR}/define_hist.h
  #${CMAKE_CURRENT_SOURCE_DIR}/EventLoop.h
  #LINKDEF ${CMAKE_CURRENT_SOURCE_DIR}/LinkDef.h
  )

add_library(Analysis SHARED 
  ${CMAKE_CURRENT_SOURCE_DIR}/RooMyPDF_BW.C
  #${CMAKE_CURRENT_SOURCE_DIR}/tree_class.C
  #${CMAKE_CURRENT_SOURCE_DIR}/bin_boundary_program.C
  #${CMAKE_CURRENT_SOURCE_DIR}/define_hist.C
  #${CMAKE_CURRENT_SOURCE_DIR}/EventLoop.C
	G__Analysis)

target_link_libraries(Analysis PUBLIC 
  ${ROOT_LIBRARIES} ${ROOT_EXE_LINKER_FLAGS} ROOT::Physics ROOT::Core ROOT::RooFit)

target_include_directories(Analysis PUBLIC 
				"${CMAKE_CURRENT_SOURCE_DIR}/" 
				)


add_executable(Analysis_exe ${CMAKE_CURRENT_SOURCE_DIR}/main.C)
target_link_libraries(Analysis_exe Analysis)
