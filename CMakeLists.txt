cmake_minimum_required( VERSION 3.16 )
project(AndreArcana)

add_subdirectory( ink )
add_subdirectory( arcana )
add_subdirectory( grimoire )

add_dependencies( grimoire ink )
