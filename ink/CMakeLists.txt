cmake_minimum_required( VERSION 3.16 )
project( ink )

add_compile_definitions( INK_LIBRARY )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories( include )

set( INK_HDRS
    include/arcanabase.h
    src/inkdll_global.h
    include/scribe.h
    )

set( INK_SRCS
    src/scribe/scribe.cpp
    )

add_library( ${PROJECT_NAME} SHARED ${INK_HDRS} ${INK_SRCS} )

target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
