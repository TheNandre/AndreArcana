cmake_minimum_required( VERSION 3.16 )
project( grimoire )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set( GRIMOIRE_HDR
    )

set( GRIMOIRE_SRC
    main/main.cpp
    )

add_executable( ${PROJECT_NAME} ${GRIMOIRE_SRC} ${GRIMOIRE_HDR} )

target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
