
find_package( Threads REQUIRED )
find_package( X11 REQUIRED )
#message( STATUS "X11_LIBRARIES = ${X11_LIBRARIES}" )

include_directories( ../ext/CImg ../core/include )

# add_executable( test_cimg.out test_cimg.cpp )
# target_link_libraries( test_cimg.out ${CMAKE_THREAD_LIBS_INIT} ${X11_LIBRARIES} ${JPEG_LIBRARIES} )

#add_executable( test_lmat.out test_lmat.cpp )
#target_link_libraries( test_lmat.out ${CMAKE_THREAD_LIBS_INIT} ${X11_LIBRARIES} )

# add_executable( test_gtkmm.out test_gtkmm.cpp )
# target_link_libraries( test_gtkmm.out ${GTK3_LIBRARIES} ${GTKMM_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} )

# add_executable( test_gtk.out test_gtk.cpp )
# target_link_libraries( test_gtk.out ${GTK3_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} )

# add_executable( test_bmap.out test_bmap.cpp )
# target_link_libraries( test_bmap.out felix ${CMAKE_THREAD_LIBS_INIT} ${X11_LIBRARIES} )

# cuda_add_executable( test_bmap_gpu.out test_bmap_gpu.cpp )
# target_link_libraries( test_bmap_gpu.out felix ${CMAKE_THREAD_LIBS_INIT} ${X11_LIBRARIES} )

# cuda_add_executable( test_gpu.out test_gpu.cpp )
# target_link_libraries( test_gpu.out felix ${CMAKE_THREAD_LIBS_INIT} ${X11_LIBRARIES} )

# add_executable( test_visualizer.out test_visualizer.cpp )
# target_link_libraries( test_visualizer.out 
#                        felix 
#                        ${GTK3_LIBRARIES} 
#                        ${CMAKE_THREAD_LIBS_INIT} 
#                        ${X11_LIBRARIES} )

# add_executable( test_full.out test_full.cpp )
# target_link_libraries( test_full.out 
#                        felix 
#                        ${GTK3_LIBRARIES} 
#                        ${CMAKE_THREAD_LIBS_INIT} 
#                        ${X11_LIBRARIES} )

# cuda_add_executable( test_full_gpu.out test_full_gpu.cpp )
# target_link_libraries( test_full_gpu.out 
#                        felix 
#                        ${GTK3_LIBRARIES} 
#                        ${CMAKE_THREAD_LIBS_INIT} 
#                        ${X11_LIBRARIES} )

# add_executable( test_histogram.out test_histogram.cpp )
# target_link_libraries( test_histogram.out
#                        felix
#                        ${GTK3_LIBRARIES}
#                        ${CMAKE_THREAD_LIBS_INIT}
#                        ${X11_LIBRARIES} )

# add_executable( test_convolution.out test_convolution.cpp )
# target_link_libraries( test_convolution.out
#                        felix
#                        ${GTK3_LIBRARIES}
#                        ${CMAKE_THREAD_LIBS_INIT}
#                        ${X11_LIBRARIES} )

# add_executable( test_noise.out test_noise.cpp )
# target_link_libraries( test_noise.out
#                        felix
#                        ${GTK3_LIBRARIES}
#                        ${CMAKE_THREAD_LIBS_INIT}
#                        ${X11_LIBRARIES} )

# add_executable( test_fourier_transform.out test_fourier_transform.cpp )
# target_link_libraries( test_fourier_transform.out
#                        felix
#                        ${GTK3_LIBRARIES}
#                        ${CMAKE_THREAD_LIBS_INIT}
#                        ${X11_LIBRARIES} )

# add_executable( test_fourier_transform_2.out test_fourier_transform_2.cpp )
# target_link_libraries( test_fourier_transform_2.out
#                        felix
#                        ${GTK3_LIBRARIES}
#                        ${CMAKE_THREAD_LIBS_INIT}
#                        ${X11_LIBRARIES}
#                        ${JPEG_LIBRARIES} )

add_executable( test_thresholding.out test_thresholding.cpp )
target_link_libraries( test_thresholding.out
                       felix
                       ${GTK3_LIBRARIES}
                       ${CMAKE_THREAD_LIBS_INIT}
                       ${X11_LIBRARIES}
                       ${JPEG_LIBRARIES} )