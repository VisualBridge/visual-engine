#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "imguizmo::imguizmo" for configuration "Release"
set_property(TARGET imguizmo::imguizmo APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(imguizmo::imguizmo PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/imguizmo.lib"
  )

list(APPEND _cmake_import_check_targets imguizmo::imguizmo )
list(APPEND _cmake_import_check_files_for_imguizmo::imguizmo "${_IMPORT_PREFIX}/lib/imguizmo.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
