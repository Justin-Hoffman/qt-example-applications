cmake_minimum_required(VERSION 3.9)

project(ExampleTemplateLib VERSION 1.0 DESCRIPTION "A CMake Build Template Library" LANGUAGES C CXX)

include(GNUInstallDirs)


add_library(ExampleTemplateLib SHARED)

target_sources(ExampleTemplateLib
 PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/src/ExampleTemplate.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/ExampleItem.cpp
 )

target_include_directories(ExampleTemplateLib 
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  PRIVATE src
  )

target_compile_options(ExampleTemplateLib PRIVATE -Wall -Werror)

# 'make install' to the correct locations (provided by GNUInstallDirs).
install(TARGETS ExampleTemplateLib EXPORT ExampleTemplateLibConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# This makes the project importable from the install directory
# Put config file in per-project dir (name MUST match), can also
# just go into 'cmake'.
install(EXPORT ExampleTemplateLibConfig DESTINATION share/ExampleTemplateLib/cmake)

# This makes the project importable from the build directory
export(TARGETS ExampleTemplateLib FILE ExampleTemplateLibConfig.cmake)


# options for testing the code using googletest
option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    add_subdirectory(test)
endif()

# check if Doxygen is installed and if so, set BUILD_DOCUMENTATION to ON
find_package(Doxygen)
option(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if (BUILD_DOCUMENTATION)
	if(NOT DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()
	
    set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${doxyfile_in} ${doxyfile} @ONLY)

    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "  -- Generating API documentation with Doxygen"
        VERBATIM)
	
else (BUILD_DOCUMENTATION)
  message("  -- Doxygen needs to be installed to generate the doxygen documentation.")
endif (BUILD_DOCUMENTATION)
