
include(${ROOT_USE_FILE})
include_directories(${CMAKE_SOURCE_DIR}/roofit/histfactory/inc) # this is very important this helps to include directories
include_directories(${CMAKE_SOURCE_DIR}/roofit/roostats/inc)
root_generate_dictionary(G__HistFactory
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
    RooStats
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
target_include_directories(HistFactory PUBLIC ${CMAKE_SOURCE_DIR}/roofit/histfactory/)
