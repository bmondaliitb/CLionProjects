# Copyright (C) 1995-2019, Rene Brun and Fons Rademakers.
# All rights reserved.
#
# For the licensing terms see $ROOTSYS/LICENSE.
# For the list of contributors see $ROOTSYS/README/CREDITS.

############################################################################
# CMakeLists.txt file for building ROOT rootfit/histfactory package
# @author Pere Mato, CERN
############################################################################
include(${ROOT_USE_FILE})
include_directories(${CMAKE_SOURCE_DIR}/roofit/histfactory) # this is very important this helps to include directories

#ROOT_STANDARD_LIBRARY_PACKAGE(HistFactory
root_generate_dictionary(G__HistFactory
  #HEADERS
    RooStats/HistFactory/Asimov.h
    RooStats/HistFactory/Channel.h
    RooStats/HistFactory/ConfigParser.h
    RooStats/HistFactory/Data.h
    RooStats/HistFactory/EstimateSummary.h
    RooStats/HistFactory/FlexibleInterpVar.h
    RooStats/HistFactory/HistFactoryException.h
    RooStats/HistFactory/HistFactoryModelUtils.h
    RooStats/HistFactory/HistFactoryNavigation.h
    RooStats/HistFactory/HistFactorySimultaneous.h
    RooStats/HistFactory/HistoToWorkspaceFactoryFast.h
    RooStats/HistFactory/HistoToWorkspaceFactory.h
    RooStats/HistFactory/HistRef.h
    RooStats/HistFactory/LinInterpVar.h
    RooStats/HistFactory/MakeModelAndMeasurementsFast.h
    RooStats/HistFactory/Measurement.h
    RooStats/HistFactory/ParamHistFunc.h
    RooStats/HistFactory/PiecewiseInterpolation.h
    RooStats/HistFactory/PreprocessFunction.h
    RooStats/HistFactory/RooBarlowBeestonLL.h
    RooStats/HistFactory/Sample.h
    RooStats/HistFactory/Systematics.h LINKDEF LinkDef.h)
#  SOURCES
add_library(HistFactory  SHARED  src/Asimov.cxx
    src/Channel.cxx
    src/ConfigParser.cxx
    src/Data.cxx
    src/EstimateSummary.cxx
    src/FlexibleInterpVar.cxx
    src/Helper.cxx
    src/Helper.h
    src/HistFactoryModelUtils.cxx
    src/HistFactoryNavigation.cxx
    src/HistFactorySimultaneous.cxx
    src/HistoToWorkspaceFactory.cxx
    src/HistoToWorkspaceFactoryFast.cxx
    src/HistRef.cxx
    src/LinInterpVar.cxx
    src/MakeModelAndMeasurements.cxx
    src/MakeModelAndMeasurementsFast.cxx
    src/Measurement.cxx
    src/ParamHistFunc.cxx
    src/PiecewiseInterpolation.cxx
    src/PreprocessFunction.cxx
    src/RooBarlowBeestonLL.cxx
    src/Sample.cxx
    src/Systematics.cxx G__HistFactory.cxx)
#  DICTIONARY_OPTIONS
#    "-writeEmptyRootPCM"
#  DEPENDENCIES
target_link_libraries(HistFactory PUBLIC
    RooFit
    RooFitCore
    ROOT::Tree
    ROOT::RIO
    ROOT::Hist
    ROOT::Matrix
    ROOT::MathCore
    ROOT::Graf
    ROOT::Gpad
    RooStats
    ROOT::XMLParser)

#)
#include(${CMAKE_SOURCE_DIR}/roofit/histfactory/inc)

target_include_directories(HistFactory PUBLIC ${CMAKE_SOURCE_DIR}/roofit/histfactory)

#ROOT_EXECUTABLE(hist2workspace
#add_executable(hist2workspace
#  src/MakeModelAndMeasurements.cxx
#  src/hist2workspace.cxx)
#  #LIBRARIES
#target_link_libraries(hist2workspace PUBLIC
#    HistFactory
#    RooStats
#    RooFit
#    RooFitCore
#    ROOT::RIO
#)
#target_include_directories(hist2workspace PUBLIC ${CMAKE_SOURCE_DIR}/roofit/histfactory/)

#---Createhist2workspaceCommandLineOptions------------------------------------------------------------------
#generateHeader(hist2workspace
#  ${CMAKE_CURRENT_SOURCE_DIR}/src/hist2workspace-argparse.py
#  ${CMAKE_BINARY_DIR}/ginclude/hist2workspaceCommandLineOptionsHelp.h
#)
#
#file(COPY config/prepareHistFactory DESTINATION  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
#install(FILES ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/prepareHistFactory
#                PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
#                            GROUP_EXECUTE GROUP_READ
#                            WORLD_EXECUTE WORLD_READ
#                DESTINATION ${CMAKE_INSTALL_BINDIR})

