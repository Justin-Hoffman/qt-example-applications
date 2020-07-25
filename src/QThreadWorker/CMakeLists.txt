# Automatically run Qt build tools
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find the Qt libraries
find_package(Qt5 REQUIRED COMPONENTS Widgets Qml Quick ) 

# Create Application 
add_executable(QThreadWorker ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

set(CUSTOMLISTMODELEDITABLE_QTSOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/src/factorizer.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/primefactorsmodel.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/work_manager.cpp
)
qt5_wrap_cpp(CUSTOMLISTMODELEDITABLE_QTSOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/include/factorizer.h
   ${CMAKE_CURRENT_SOURCE_DIR}/include/primefactorsmodel.h
   ${CMAKE_CURRENT_SOURCE_DIR}/include/work_manager.h
)

target_sources(QThreadWorker
 PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/src/resources.qrc
   ${CUSTOMLISTMODELEDITABLE_QTSOURCES}
 )

# Add the Qt5 Widgets for linking
target_link_libraries(QThreadWorker ExampleTemplateLib Qt5::Widgets Qt5::Qml Qt5::Quick)

target_include_directories(QThreadWorker
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/res>
    ./src
  )
set_property(TARGET QThreadWorker 
  PROPERTY 
    AUTOMOC ON
    AUTORCC ON 
    AUTOUIC ON)

target_compile_options(QThreadWorker PRIVATE -Wall -Werror)
