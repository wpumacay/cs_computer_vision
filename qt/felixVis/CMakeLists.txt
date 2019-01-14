
message( "Configuring felixVis edition tool ..." )

set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )

include_directories( include/ ui/ ../../core/include )

find_package( Qt5Core )
find_package( Qt5Widgets )
find_package( Qt5Gui )
find_package( Qwt )

message( 'qt inc dir: ${Qt5Widgets_INCLUDE_DIRS}' )

include_directories( ${QWT_INCLUDE_DIR} )

add_executable( felixVis 
	        main.cpp 
                src/windowWidgets/LRenderArea.cpp
                src/windowWidgets/LKernelWidget.cpp
                src/qtUtils/LQtUtils.cpp
                src/qtWrappers/LWrapperAffineTransforms.cpp
                src/qtWrappers/LWrapperLocalProc.cpp
                src/qtWrappers/LWrapperGlobalProc.cpp
                src/qtWrappers/LWrapperFourierTransform.cpp
                ui/lpanelaffinetransforms.cpp
                ui/lpanelconvolution.cpp
                ui/lpanelhistogramequalization.cpp
                ui/lpanelmedianfilter.cpp
                ui/lpanelfouriertransform.cpp
                mainwindow.cpp )

target_link_libraries( felixVis Qt5::Widgets felix ${GTK3_LIBRARIES} qwt )

message( "Done configuring felixVis" )