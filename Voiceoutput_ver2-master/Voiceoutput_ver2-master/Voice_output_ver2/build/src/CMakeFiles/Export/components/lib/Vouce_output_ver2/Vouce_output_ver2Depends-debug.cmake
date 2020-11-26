#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Vouce_output_ver2" for configuration "Debug"
set_property(TARGET Vouce_output_ver2 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Vouce_output_ver2 PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/components/lib/Vouce_output_ver2.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "RTC112_vc14d;coil112_vc14d;omniORB421_rtd;omniDynamic421_rtd;omnithread40_rtd;advapi32;ws2_32;mswsock"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/components/bin/Vouce_output_ver2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Vouce_output_ver2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_Vouce_output_ver2 "${_IMPORT_PREFIX}/components/lib/Vouce_output_ver2.lib" "${_IMPORT_PREFIX}/components/bin/Vouce_output_ver2.dll" )

# Import target "Vouce_output_ver2Comp" for configuration "Debug"
set_property(TARGET Vouce_output_ver2Comp APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Vouce_output_ver2Comp PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/components/bin/Vouce_output_ver2Comp.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS Vouce_output_ver2Comp )
list(APPEND _IMPORT_CHECK_FILES_FOR_Vouce_output_ver2Comp "${_IMPORT_PREFIX}/components/bin/Vouce_output_ver2Comp.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
