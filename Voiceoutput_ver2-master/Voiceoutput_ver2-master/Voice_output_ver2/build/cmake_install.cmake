# Install script for directory: C:/Users/robo-lab/Desktop/Voiceoutput_ver2-master/Voiceoutput_ver2-master/Voice_output_ver2

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Vouce_output_ver2")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES
    "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/redist/x86/Microsoft.VC140.CRT/msvcp140.dll"
    "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/redist/x86/Microsoft.VC140.CRT/vcruntime140.dll"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/robo-lab/Desktop/Voiceoutput_ver2-master/Voiceoutput_ver2-master/Voice_output_ver2/build/cmake/cmake_install.cmake")
  include("C:/Users/robo-lab/Desktop/Voiceoutput_ver2-master/Voiceoutput_ver2-master/Voice_output_ver2/build/doc/cmake_install.cmake")
  include("C:/Users/robo-lab/Desktop/Voiceoutput_ver2-master/Voiceoutput_ver2-master/Voice_output_ver2/build/idl/cmake_install.cmake")
  include("C:/Users/robo-lab/Desktop/Voiceoutput_ver2-master/Voiceoutput_ver2-master/Voice_output_ver2/build/include/cmake_install.cmake")
  include("C:/Users/robo-lab/Desktop/Voiceoutput_ver2-master/Voiceoutput_ver2-master/Voice_output_ver2/build/src/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/robo-lab/Desktop/Voiceoutput_ver2-master/Voiceoutput_ver2-master/Voice_output_ver2/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
