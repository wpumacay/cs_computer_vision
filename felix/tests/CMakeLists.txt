
find_package( Threads REQUIRED )
find_package( X11 REQUIRED )
#message( STATUS "X11_LIBRARIES = ${X11_LIBRARIES}" )

include_directories( ../ext/CImg ../core )

add_executable( test_cimg.out
                test_cimg.cpp )

add_executable( test_lmat.out
                test_lmat.cpp )


target_link_libraries( test_cimg.out ${CMAKE_THREAD_LIBS_INIT} ${X11_LIBRARIES} )
target_link_libraries( test_lmat.out ${CMAKE_THREAD_LIBS_INIT} ${X11_LIBRARIES} )