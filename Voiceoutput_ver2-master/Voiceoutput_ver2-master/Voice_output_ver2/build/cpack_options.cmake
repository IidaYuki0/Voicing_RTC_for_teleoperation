set(CPACK_PACKAGE_NAME "Vouce_output_ver2")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "ModuleDescription")
set(CPACK_PACKAGE_VENDOR "IidaYuki")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "Vouce_output_ver2100")
set(CPACK_PACKAGE_FILE_NAME "Vouce_output_ver2-1.0.0")
set(CPACK_RESOURCE_FILE_LICENSE "C:/Users/robo-lab/Desktop/Voiceoutput_ver2-master/Voiceoutput_ver2-master/Voice_output_ver2/COPYING.LESSER")

set(CPACK_COMPONENTS_ALL component)
set(CPACK_COMPONENT_COMPONENT_DISPLAY_NAME "Applications")
set(CPACK_COMPONENT_COMPONENT_DESCRIPTION
    "Component library and stand-alone executable")
if(INSTALL_HEADERS)
    set(CPACK_COMPONENTS_ALL ${CPACK_COMPONENTS_ALL}  headers)
    set(CPACK_COMPONENT_HEADERS_DISPLAY_NAME "Header files")
    set(CPACK_COMPONENT_HEADERS_DESCRIPTION
        "Header files from the component.")
    set(CPACK_COMPONENT_HEADERS_DEPENDS component)
endif(INSTALL_HEADERS)
if(INSTALL_IDL)
    set(CPACK_COMPONENTS_ALL ${CPACK_COMPONENTS_ALL} idl)
    set(CPACK_COMPONENT_IDL_DISPLAY_NAME "IDL files")
    set(CPACK_COMPONENT_IDL_DESCRIPTION
        "IDL files for the component's services.")
    set(CPACK_COMPONENT_IDL_DEPENDS component)
endif(INSTALL_IDL)
set(INSTALL_EXAMPLES )
if(INSTALL_EXAMPLES)
    set(CPACK_COMPONENTS_ALL ${CPACK_COMPONENTS_ALL} examples)
    set(CPACK_COMPONENT_EXAMPLES_DISPLAY_NAME "Examples")
    set(CPACK_COMPONENT_EXAMPLES_DESCRIPTION
        "Sample configuration files and other component resources.")
    set(CPACK_COMPONENT_EXAMPLES_DEPENDS component)
endif(INSTALL_EXAMPLES)
set(INSTALL_DOCUMENTATION ON)
if(INSTALL_DOCUMENTATION)
    set(CPACK_COMPONENTS_ALL ${CPACK_COMPONENTS_ALL} documentation)
    set(CPACK_COMPONENT_DOCUMENTATION_DISPLAY_NAME "Documentation")
    set(CPACK_COMPONENT_DOCUMENTATION_DESCRIPTION
        "Component documentation")
    set(CPACK_COMPONENT_DOCUMENTATION_DEPENDS component)
endif(INSTALL_DOCUMENTATION)
if(INSTALL_SOURCES)
    set(CPACK_COMPONENTS_ALL ${CPACK_COMPONENTS_ALL} sources)
    set(CPACK_COMPONENT_SOURCES_DISPLAY_NAME "Source files")
    set(CPACK_COMPONENT_SOURCES_DESCRIPTION
        "Source files from the component.")
endif(INSTALL_SOURCES)

IF (WIN32)

    # Windows WiX package settings

    set(CPACK_WIX_XSL "C:/Users/robo-lab/Desktop/Voiceoutput_ver2-master/Voiceoutput_ver2-master/Voice_output_ver2/build/wix.xsl")
    set(CPACK_WIX_LANG "ja-jp")
    set(CPACK_RESOURCE_FILE_LICENSE
        "C:/Users/robo-lab/Desktop/Voiceoutput_ver2-master/Voiceoutput_ver2-master/Voice_output_ver2/cmake/License.rtf")
    configure_file(
        "C:/Users/robo-lab/Desktop/Voiceoutput_ver2-master/Voiceoutput_ver2-master/Voice_output_ver2/cmake/wix.xsl.in"
        "C:/Users/robo-lab/Desktop/Voiceoutput_ver2-master/Voiceoutput_ver2-master/Voice_output_ver2/build/wix.xsl" @ONLY)

    set(CPACK_PACKAGE_FILE_NAME
        "Vouce_output_ver2100")


    #
    #
    #
    set(CPACK_NSIS_MUI_ICON "C:/Users/robo-lab/Desktop/Voiceoutput_ver2-master/Voiceoutput_ver2-master/Voice_output_ver2/cmake\\rt_middleware_logo.ico")
    set(CPACK_NSIS_MUI_UNIICON "C:/Users/robo-lab/Desktop/Voiceoutput_ver2-master/Voiceoutput_ver2-master/Voice_output_ver2/cmake\\rt_middleware_logo.ico")
    set(CPACK_PACKAGE_ICON "C:/Users/robo-lab/Desktop/Voiceoutput_ver2-master/Voiceoutput_ver2-master/Voice_output_ver2/cmake\\rt_middleware_logo.bmp")
    set(CPACK_NSIS_HELP_LINK "http://www.openrtm.org")
    set(CPACK_NSIS_URL_INFO_ABOUT "http://www.openrtm.org")
    set(CPACK_NSIS_MODIFY_PATH ON)
    set(CPACK_PACKAGE_EXECUTABLES vouce_output_ver2Comp;vouce_output_ver2Comp)
    if(INSTALL_DOCUMENTATION)
        set(CPACK_NSIS_MENU_LINKS
            "C:/Program Files (x86)/Vouce_output_ver2/share/doc/vouce_output_ver2-1/html/index.html"
            "Component documentation")
    endif(INSTALL_DOCUMENTATION)
    string(REPLACE "/Vouce_output_ver2" "" install_prefix_root
        "C:/Program Files (x86)/Vouce_output_ver2")
    file(TO_NATIVE_PATH "${install_prefix_root}" install_prefix_root)
    set(CPACK_NSIS_INSTALL_ROOT "${install_prefix_root}")
    set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS
        "  Rename \"$INSTDIR\\share\\vouce_output_ver2-1\\vouce_output_ver2-config.cmake\" \"$INSTDIR\\vouce_output_ver2-config.cmake\"
  Rename \"$INSTDIR\\share\\vouce_output_ver2-1\\vouce_output_ver2-config-version.cmake\" \"$INSTDIR\\vouce_output_ver2-config-version.cmake\"")
    set(CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS
        "  Delete \"$INSTDIR\\vouce_output_ver2-config.cmake\"
  Delete \"$INSTDIR\\vouce_output_ver2-config-version.cmake\"")
ENDIF (WIN32)

