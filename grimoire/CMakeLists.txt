cmake_minimum_required( VERSION 3.16 )
project( grimoire )

if( BUILD_LAB )
    add_compile_definitions( GRIMOIRE_LIBRARY )
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

include_directories( ../ink/include )

set( GRIMOIRE_HDRS
    src/grimoire.h
    src/processexitmanager.h
    src/misfiremanager.h
    src/cover.h
    src/grimoire_global.h
    )

set( GRIMOIRE_SRCS
    main/main.cpp
    src/grimoire.cpp
    src/processexitmanager.cpp
    src/misfiremanager.cpp
    src/cover.cpp
    )

if( BUILD_LAB )
    add_library( ${PROJECT_NAME} SHARED ${GRIMOIRE_HDRS} ${GRIMOIRE_SRCS} )
else()
    add_executable( ${PROJECT_NAME} ${GRIMOIRE_HDRS} ${GRIMOIRE_SRCS} )
endif()

target_link_libraries( ${PROJECT_NAME} ink )
target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
