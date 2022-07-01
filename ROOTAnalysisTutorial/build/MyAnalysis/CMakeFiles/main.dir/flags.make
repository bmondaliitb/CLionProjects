# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# compile CXX with /cvmfs/sft.cern.ch/lcg/releases/gcc/8.3.0-cebb0/x86_64-centos7/bin/g++
CXX_FLAGS = -g -Wall -Wno-long-long -Wno-deprecated -Wno-unused-local-typedefs -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wextra -Werror=return-type -fsanitize=undefined -pedantic   -pthread -std=c++17

CXX_DEFINES = -DATLAS -DHAVE_64_BITS -DHAVE_PRETTY_FUNCTION -DPACKAGE_VERSION=\"MyAnalysis-00-00-00\" -DPACKAGE_VERSION_UQ=MyAnalysis-00-00-00 -DROOTCORE -DROOTCORE_RELEASE_SERIES=25 -DXAOD_ANALYSIS -DXAOD_STANDALONE -D__IDENTIFIER_64BIT__

CXX_INCLUDES = -I/home/bmondal/CLionProjects/ROOTAnalysisTutorial/source/MyAnalysis -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/RootCore/include -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/PhysicsAnalysis/D3PDTools/AnaAlgorithm -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/PhysicsAnalysis/D3PDTools/RootCoreUtils -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Control/AthToolSupport/AsgTools -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Control/AthToolSupport/AsgMessaging -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Control/xAODRootAccessInterfaces -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Control/xAODRootAccess -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Control/CxxUtils -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Control/AthContainersInterfaces -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Control/AthContainers -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Control/AthLinksSA -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Event/xAOD/xAODCore -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Event/xAOD/xAODEventFormat -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Event/xAOD/xAODEventInfo -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Event/xAOD/xAODJet -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Event/xAOD/xAODBase -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Event/xAOD/xAODBTagging -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Event/xAOD/xAODTracking -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/DetectorDescription/GeoPrimitives -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Event/EventPrimitives -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Event/xAOD/xAODMuon -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Event/xAOD/xAODCaloEvent -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Calorimeter/CaloGeoHelpers -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Event/xAOD/xAODPrimitives -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/MuonSpectrometer/MuonIdHelpers -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Event/xAOD/xAODTrigger -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Event/xAOD/xAODPFlow -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/PhysicsAnalysis/Algorithms/SystematicsHandles -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/PhysicsAnalysis/AnalysisCommon/PATInterfaces -I/cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/src/Event/xAOD/xAODCutFlow -isystem /cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/../../../../AnalysisBaseExternals/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/include -isystem /cvmfs/atlas-nightlies.cern.ch/repo/sw/21.2_AnalysisBase_x86_64-centos7-gcc8-opt/2021-01-30T0353/AnalysisBase/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/../../../../AnalysisBaseExternals/21.2.158/InstallArea/x86_64-centos7-gcc8-opt/include/eigen3 
