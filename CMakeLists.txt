cmake_minimum_required( VERSION 3.16 )
project(AndreArcana)

option( BUILD_LAB "Build Testing" ON )
if( BUILD_LAB )
    add_definitions( -DBUILD_LAB )
endif()

include_directories( include )

add_subdirectory( ink )
add_subdirectory( arcana )
add_subdirectory( grimoire )

add_dependencies( grimoire ink )

if( BUILD_LAB )
    add_subdirectory( laboratory )
    add_dependencies( laboratory ink )
    add_dependencies( laboratory grimoire )
endif()
