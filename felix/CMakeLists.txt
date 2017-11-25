cmake_minimum_required( VERSION 3.5.0 )
project( felix )

set( CMAKE_BUILD_TYPE Debug )

set( CMAKE_CXX_STANDARD 11 )

find_package( PkgConfig REQUIRED )
pkg_search_module( GTK3 REQUIRED gtk+-3.0 )

include_directories( ${GTK3_INCLUDE_DIRS} )



add_subdirectory( core )
add_subdirectory( tests )

