# Automatically run Qt build tools
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find the QtWidgets library
find_package(Qt5 REQUIRED COMPONENTS Widgets Qml Quick ) 

# Create Application 
add_executable(CustomListModelEditable ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

set(CUSTOMLISTMODELEDITABLE_QTSOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/src/exampleitemmodeleditable.cpp
)
qt5_wrap_cpp(CUSTOMLISTMODELEDITABLE_QTSOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/include/exampleitemmodeleditable.h
)

target_sources(CustomListModelEditable
 PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/src/resources.qrc
   ${CUSTOMLISTMODELEDITABLE_QTSOURCES}
 )

# Add the Qt5 Widgets for linking
target_link_libraries(CustomListModelEditable ExampleTemplateLib Qt5::Widgets Qt5::Qml Qt5::Quick)

target_include_directories(CustomListModelEditable
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/res>
    ./src
  )
set_property(TARGET CustomListModelEditable 
  PROPERTY 
    AUTOMOC ON
    AUTORCC ON 
    AUTOUIC ON)

target_compile_options(CustomListModelEditable PRIVATE -Wall -Werror)
