# Copyright (C) 1995-2019, Rene Brun and Fons Rademakers.
# All rights reserved.
#
# For the licensing terms see $ROOTSYS/LICENSE.
# For the list of contributors see $ROOTSYS/README/CREDITS.

############################################################################
# CMakeLists.txt file for building ROOT roofitmore package
# @author Lorenzo Moneta, CERN
############################################################################

#if(mathmore)
#  set(ROOT_MATHMORE_LIBRARY MathMore)
#endif()
include(${ROOT_USE_FILE})
include_directories(${CMAKE_SOURCE_DIR}/roofit/roofitmore) # this is very important this helps to include directories

#ROOT_STANDARD_LIBRARY_PACKAGE(RooFitMore
root_generate_dictionary(G__RooFitMore
  #HEADERS
    RooFitMoreLib.h
    RooAdaptiveGaussKronrodIntegrator1D.h
    RooGaussKronrodIntegrator1D.h
    RooLegendre.h
    RooMathMoreReg.h
    RooSpHarmonic.h
    RooNonCentralChiSquare.h
    RooHypatia2.h LINKDEF LinkDef.h)
  #SOURCES
add_library(RooFitMore SHARED src/RooFitMoreLib.cxx
    src/RooAdaptiveGaussKronrodIntegrator1D.cxx
    src/RooGaussKronrodIntegrator1D.cxx
    src/RooLegendre.cxx
    src/RooMathMoreReg.cxx
    src/RooSpHarmonic.cxx
    src/RooNonCentralChiSquare.cxx
    src/RooHypatia2.cxx G__RooFitMore)

target_link_libraries(RooFitMore PUBLIC
    ROOT::Core
    RooFitCore
    RooFit
    ROOT::Hist
    ROOT::Matrix
    ROOT::Tree
    ROOT::Minuit
    ROOT::RIO
    ROOT::MathCore
    ROOT::Foam
)

target_include_directories(RooFitMore PUBLIC ${CMAKE_SOURCE_DIR}/roofit/roofitmore)

#ROOT_ADD_TEST_SUBDIRECTORY(test)
