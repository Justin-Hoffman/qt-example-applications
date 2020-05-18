# Automatically run Qt build tools
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find the QtWidgets library
find_package(Qt5 REQUIRED COMPONENTS Widgets Qml Quick ) 

# Create Application 
add_executable(CustomListModel ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

set(CUSTOMLISTVIEW_QTSOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/src/exampleitemmodel.cpp
)
qt5_wrap_cpp(CUSTOMLISTVIEW_QTSOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/include/exampleitemmodel.h
)

target_sources(CustomListModel
 PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/src/resources.qrc
   ${CUSTOMLISTVIEW_QTSOURCES}
 )

# Add the Qt5 Widgets for linking
target_link_libraries(CustomListModel ExampleTemplateLib Qt5::Widgets Qt5::Qml Qt5::Quick)

target_include_directories(CustomListModel
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/res>
    ./src
  )
set_property(TARGET CustomListModel 
  PROPERTY 
    AUTOMOC ON
    AUTORCC ON 
    AUTOUIC ON)

target_compile_options(CustomListModel PRIVATE -Wall -Werror)
