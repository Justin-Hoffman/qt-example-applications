# Define an executable
add_executable(ExampleTemplateApp src/main.cpp)

#target_sources(ExampleTemplateApp
#  PRIVATE
#    src/main.cpp
#  )

# Define the libraries this project depends upon
target_link_libraries(ExampleTemplateApp
    ExampleTemplateLib
  )

# 'make install' to the correct locations (provided by GNUInstallDirs).
install(TARGETS ExampleTemplateApp EXPORT ExampleTemplateAppConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# This makes the project importable from the install directory
# Put config file in per-project dir (name MUST match), can also
# just go into 'cmake'.
install(EXPORT ExampleTemplateAppConfig DESTINATION share/ExampleTemplateApp/cmake)

# This makes the project importable from the build directory
export(TARGETS ExampleTemplateApp FILE ExampleTemplateAppConfig.cmake)

