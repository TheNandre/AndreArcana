cmake_minimum_required( VERSION 3.16 )
project( ink )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set( INK_HDRS
    include/arcanabase.h
    include/misfire.h
    )

set( INK_SRCS
    )

add_library( ${PROJECT_NAME} SHARED ${INK_HDRS} ${INK_SRCS} )

target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
