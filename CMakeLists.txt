cmake_minimum_required(VERSION 3.9)

project(Qt5Demo VERSION 1.0 DESCRIPTION "A Collection of Qt 5 Demos" LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 11)

include(GNUInstallDirs)

set(CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
    "${CMAKE_MODULE_PATH}"
    )

enable_testing()
add_subdirectory(src/ExampleTemplateLib)
add_subdirectory(src/ExampleTemplate)
add_subdirectory(src/CustomListModel)
add_subdirectory(src/CustomListModelEditable)
#add_subdirectory(src/QMLSingleton) TODO: Instantiate a C++ singleton via QML. Read/write Q_PROPERTY to singles from multiple forms
#add_subdirectory(src/DeviceLocalStorage) TODO: Store persistent application data in device local storage
#add_subdirectory(src/StackedEditForm) TODO: Based on custom list view above but stack an edit form to edit the application
#add_subdirectory(src/DynamicViewContainer) TODO: Split views across multiple containers dynamically when enough window real estate is available

find_package(Git)
if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
  execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
  OUTPUT_VARIABLE PACKAGE_GIT_VERSION
  ERROR_QUIET
  OUTPUT_STRIP_TRAILING_WHITESPACE)
else()
  set(PACKAGE_GIT_VERSION "none")
endif()

set(CPACK_PACKAGE_VERSION ${VERSION})
set(CPACK_PACKAGE_NAME "Qt5-Demos")
set(CPACK_PACKAGE_RELEASE 1)
set(CPACK_PACKAGE_CONTACT "Justin Hoffman")
set(CPACK_PACKAGE_VENDOR "None")
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_PACKAGE_RELEASE}-${PACKAGE_GIT_VERSION}.${CMAKE_SYSTEM_PROCESSOR}")
set(CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION 
  /etc /etc/init.d /usr /usr/share /usr/share/doc /usr/bin /usr/lib /usr/lib64 /usr/include /usr/local /usr/local/bin /usr/local/lib /usr/local/lib64 /usr/local/share)
include(CPack)
