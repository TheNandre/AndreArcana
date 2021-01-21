cmake_minimum_required( VERSION 3.16 )
project( grimoire )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set( GRIMOIRE_HDR
    grimoire.h
    )

set( GRIMOIRE_SRC
    main/main.cpp
    grimoire.cpp
    )

add_executable( ${PROJECT_NAME} ${GRIMOIRE_HDR} ${GRIMOIRE_SRC} )

target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
