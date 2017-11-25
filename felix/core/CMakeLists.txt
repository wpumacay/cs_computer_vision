

include_directories( include/ /usr/local/include )

add_library( felix_obj OBJECT
             src/transforms/LAffineTransforms.cpp
             src/utils/LUtils.cpp )

add_library( felix $<TARGET_OBJECTS:felix_obj> )