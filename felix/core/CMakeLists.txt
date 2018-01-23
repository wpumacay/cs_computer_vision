

include_directories( include/ /usr/local/include )

#cuda_compile( KERNELS_CUDA 
#              src/cuda/transforms/LCudaAffineTransforms.cu
#              src/cuda/testing/LCudaTesting.cu )

## separate in both cpu and gpu libraries

cuda_add_library( felix
                  src/imgproc/localproc/LConvolution.cpp
                  src/imgproc/localproc/LMedianFilter.cpp
                  src/imgproc/globalproc/LHistogram.cpp
                  src/transforms/LAffineTransforms.cpp
                  src/transforms/LFourierTransform.cpp
                  src/utils/LUtils.cpp
                  src/visualizer/LVisualizerManager.cpp
                  src/visualizer/gtk/LVisualizerGtk.cpp
                  src/visualizer/gtk/LWindowGtk.cpp
                  src/mat/LCudaMat.cpp
                  src/gpu/LGpuManager.cpp
                  src/gpu/LGpuCudaHandler.cpp
                  src/cuda/transforms/LCudaAffineTransforms.cu
                  src/cuda/testing/LCudaTesting.cu )

#cuda_add_library( felix $<TARGET_OBJECTS:felix_obj> )