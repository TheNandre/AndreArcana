cmake_minimum_required( VERSION 3.16 )
project(AndreArcana)

add_subdirectory( ink )
add_subdirectory( arcana )
add_subdirectory( grimoire )

add_dependencies( grimoire ink )

if( BUILD_LAB )
    add_subdirectory( laboratory )
    add_dependencies( laboratory ink )
    add_dependencies( laboratory grimoire )
endif()
