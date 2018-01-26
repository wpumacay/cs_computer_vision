
message( "Configuring felixVis edition tool ..." )

set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )

include_directories( include/ ui/ ../../core/include )

find_package( Qt5Core )
find_package( Qt5Widgets )
find_package( Qt5Gui )

add_executable( felixVis 
				main.cpp 
                src/windowWidgets/LRenderArea.cpp
                src/windowWidgets/LKernelWidget.cpp
                src/qtUtils/LQtUtils.cpp
                src/qtWrappers/LWrapperAffineTransforms.cpp
                src/qtWrappers/LWrapperLocalProc.cpp
                ui/lpanelaffinetransforms.cpp
                ui/lpanelconvolution.cpp
                mainwindow.cpp )

target_link_libraries( felixVis Qt5::Widgets felix ${GTK3_LIBRARIES} )

message( "Done configuring felixVis" )