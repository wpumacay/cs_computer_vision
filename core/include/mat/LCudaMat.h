
#pragma once

#include "LGpuMat.h"

#include <cuda.h>
#include <cuda_runtime.h>

#include "../gpu/LGpuManager.h"

namespace felix
{

    namespace gpu
    {
        struct LGpuManager;
    }

    namespace core
    {


        class LCudaMat : public LGpuMat
        {

            private :

            float* m_dev_gpuBuffer;

            public :


            LCudaMat() : LGpuMat()
            {
                m_dev_gpuBuffer = NULL;
                m_type = type::CUDA;
                //std::cout << "no malloc!" << std::endl;
            }

            LCudaMat( int rows, int cols, int channels ) 
                : LGpuMat( rows, cols, channels )
            {
                //std::cout << "malloc! 1" << std::endl;

                //cudaError_t _errorCode;

                /*_errorCode = */cudaMalloc( ( void** ) &m_dev_gpuBuffer, m_bufferSize );

                //std::cout << "_errorCode_malloc: " << _errorCode << std::endl;
                //std::cout << "?: buffsize" << m_bufferSize << std::endl;

                m_type = type::CUDA;
            }

            LCudaMat( int rows, int cols, int channels, float* pData ) 
                : LGpuMat( rows, cols, channels, pData )
            {
                //std::cout << "malloc! 2" << std::endl;
                cudaMalloc( ( void** ) &m_dev_gpuBuffer, m_bufferSize );
                m_type = type::CUDA;
            }

            // TODO: Create copy constructors as there might be memory leaks both in gpu and cpu

            void releaseMemory()
            {
                cudaFree( m_dev_gpuBuffer );
                free( m_host_cpuBuffer );
            }

            float* devGpuBuffer() 
            { 
                //std::cout << "m_dev_gpuBuffer: " << m_dev_gpuBuffer << std::endl;
                return m_dev_gpuBuffer;
            }

            void loadToGpu();

            void loadFromGpu();
        };






    }






}