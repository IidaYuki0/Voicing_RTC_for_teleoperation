# Vouce_output_ver2 CMake config file
#
# This file sets the following variables:
# Vouce_output_ver2_FOUND - Always TRUE.
# Vouce_output_ver2_INCLUDE_DIRS - Directories containing the Vouce_output_ver2 include files.
# Vouce_output_ver2_IDL_DIRS - Directories containing the Vouce_output_ver2 IDL files.
# Vouce_output_ver2_LIBRARIES - Libraries needed to use Vouce_output_ver2.
# Vouce_output_ver2_DEFINITIONS - Compiler flags for Vouce_output_ver2.
# Vouce_output_ver2_VERSION - The version of Vouce_output_ver2 found.
# Vouce_output_ver2_VERSION_MAJOR - The major version of Vouce_output_ver2 found.
# Vouce_output_ver2_VERSION_MINOR - The minor version of Vouce_output_ver2 found.
# Vouce_output_ver2_VERSION_REVISION - The revision version of Vouce_output_ver2 found.
# Vouce_output_ver2_VERSION_CANDIDATE - The candidate version of Vouce_output_ver2 found.

message(STATUS "Found Vouce_output_ver2-1.0.0")
set(Vouce_output_ver2_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(Vouce_output_ver2_INCLUDE_DIRS
#    "C:/Program Files (x86)/Vouce_output_ver2/include/vouce_output_ver2-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(Vouce_output_ver2_IDL_DIRS
#    "C:/Program Files (x86)/Vouce_output_ver2/include/vouce_output_ver2-1/idl")
set(Vouce_output_ver2_INCLUDE_DIRS
    "C:/Program Files (x86)/Vouce_output_ver2/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(Vouce_output_ver2_IDL_DIRS
    "C:/Program Files (x86)/Vouce_output_ver2/include//idl")


if(WIN32)
    set(Vouce_output_ver2_LIBRARIES
        "C:/Program Files (x86)/Vouce_output_ver2/components/lib/vouce_output_ver2.lib"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(Vouce_output_ver2_LIBRARIES
        "C:/Program Files (x86)/Vouce_output_ver2/components/lib/vouce_output_ver2.dll"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(Vouce_output_ver2_DEFINITIONS ${<dependency>_DEFINITIONS})

set(Vouce_output_ver2_VERSION 1.0.0)
set(Vouce_output_ver2_VERSION_MAJOR 1)
set(Vouce_output_ver2_VERSION_MINOR 0)
set(Vouce_output_ver2_VERSION_REVISION 0)
set(Vouce_output_ver2_VERSION_CANDIDATE )

