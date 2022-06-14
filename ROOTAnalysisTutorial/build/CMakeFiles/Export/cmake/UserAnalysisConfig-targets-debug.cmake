#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "UserAnalysis::MyAnalysisLib" for configuration "Debug"
set_property(TARGET UserAnalysis::MyAnalysisLib APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(UserAnalysis::MyAnalysisLib PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libMyAnalysisLib.so"
  IMPORTED_SONAME_DEBUG "libMyAnalysisLib.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS UserAnalysis::MyAnalysisLib )
list(APPEND _IMPORT_CHECK_FILES_FOR_UserAnalysis::MyAnalysisLib "${_IMPORT_PREFIX}/lib/libMyAnalysisLib.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
