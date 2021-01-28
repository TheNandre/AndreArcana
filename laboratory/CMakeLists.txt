cmake_minimum_required( VERSION 3.16 )
project(laboratory)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories( ../grimoire/src
    ../ink/include )

find_package(Qt6 COMPONENTS Widgets Test REQUIRED)

set( LAB_HDRS
    laboratory.h)

set( LAB_SRCS
    main.cpp
    laboratory.cpp)

add_executable( ${PROJECT_NAME} ${LAB_HDRS} ${LAB_SRCS} )

target_link_libraries( ${PROJECT_NAME} ink grimoire )
target_link_libraries( ${PROJECT_NAME} Qt6::Widgets Qt6::Test )
