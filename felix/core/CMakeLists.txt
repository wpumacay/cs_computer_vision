

include_directories( include/ /usr/local/include )

#cuda_compile( KERNELS_CUDA 
#              src/cuda/transforms/LCudaAffineTransforms.cu
#              src/cuda/testing/LCudaTesting.cu )

## separate in both cpu and gpu libraries

cuda_add_library( felix
                  src/transforms/LAffineTransforms.cpp
                  src/utils/LUtils.cpp
                  src/mat/LCudaMat.cpp
                  src/gpu/LGpuManager.cpp
                  src/gpu/LGpuCudaHandler.cpp
                  src/cuda/transforms/LCudaAffineTransforms.cu
                  src/cuda/testing/LCudaTesting.cu )

#cuda_add_library( felix $<TARGET_OBJECTS:felix_obj> )