project(example)

cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(HEADERS mainwindow.h)
set(SOURCES main.cpp mainwindow.cpp)
set(UI mainwindow.ui)

add_subdirectory("../" "qt-section-widget")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${UI})

# link against Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Widgets)

# link against qt-section-widget
target_include_directories(${PROJECT_NAME} PRIVATE "../")
target_link_libraries(${PROJECT_NAME} PRIVATE qt-section-widget)
