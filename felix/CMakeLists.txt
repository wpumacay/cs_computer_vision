cmake_minimum_required( VERSION 3.5.0 )
project( felix )

set( CMAKE_BUILD_TYPE Debug )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_FLAGS_DEBUG "-g -Wno-unused-parameter" )

find_package( CUDA )
find_package( OpenCL )
find_package( OpenMP )
#find_package( Threads REQUIRED ) # testing gtk with threads
find_package( PkgConfig REQUIRED )
pkg_search_module( GTK3 REQUIRED gtk+-3.0 )
pkg_search_module( GTKMM REQUIRED gtkmm-3.0 )

include_directories( ${GTK3_INCLUDE_DIRS} ${GTKMM_INCLUDE_DIRS} )
link_directories( ${GTKMM_LIBRARY_DIRS} )

if( CUDA_FOUND )

add_definitions( -DCUDA_SUPPORT_ENABLED )
include_directories( ${CUDA_INCLUDE_DIRS} )

message( "CUDA SUPPORT ENABLED" )

endif()

if( OpenCL_FOUND )

add_definitions( -DOPENCL_SUPPORT_ENABLED )
include_directories( ${OpenCL_INCLUDE_DIRS} )

message( "OPENCL SUPPORT ENABLED" )

endif()

if ( OPENMP_FOUND )

set( CMAKE_CXX_FLAGS_DEBUG "-g -Wno-unused-parameter ${OPENMP_CXX_FLAGS}" )
add_definitions( -DOPENMP_SUPPORT_ENABLED )
message( "OPENMP SUPPORT ENABLED" )

endif()

if ( GTK3_FOUND )

message( "GTK SUPPORT ENABLED" )
add_definitions( -DGTK_SUPPORT_ENABLED )

else ()

message( "NO VISUALIZATION SUPPORT FOUND, SORRY :(" )

endif()

add_subdirectory( core )
add_subdirectory( tests )

