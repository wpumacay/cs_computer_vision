
#pragma once

#include "../../LCommon.h"

namespace felix
{

    namespace core
    {

        namespace type
        {
            enum _type
            {
                CUDA,
                OPENCL
            };
        }

        class LGpuMat
        {

            protected :

            type::_type m_type;

            float* m_host_cpuBuffer;

            int m_rows;// height
            int m_cols;// width
            int m_size;
            int m_channels;

            int m_bufferSize;

            public :


            LGpuMat()
            {
                m_host_cpuBuffer = NULL;

                m_rows = 0;
                m_cols = 0;
                m_size = 0;
                m_channels = 0;

                m_bufferSize = 0;

            }

            LGpuMat( int rows, int cols, int channels )
            {
                m_host_cpuBuffer = new float[rows * cols * channels];

                m_rows = rows;
                m_cols = cols;
                m_size = rows * cols;
                m_channels = channels;

                m_bufferSize = sizeof( float ) * rows * cols * channels;

                // Extend this
            }

            LGpuMat( int rows, int cols, int channels, float* pData )
            {
                m_host_cpuBuffer = new float[rows * cols * channels];

                m_rows = rows;
                m_cols = cols;
                m_size = rows * cols;
                m_channels = channels;

                m_bufferSize = sizeof( float ) * rows * cols * channels;

                memcpy( m_host_cpuBuffer, pData, m_bufferSize );

                // Extend this
            }

            void copyFromBuffer( float* pData )
            {
                memcpy( m_host_cpuBuffer, pData, m_bufferSize );
            }

            virtual void loadToGpu()
            {
                // Override this
                // Specs: 
                // cuda -> should memcpy to device / or maybe request singleton manager
                // opencl -> should request singleton manager and load buffer into device
            }

            virtual void loadFromGpu()
            {
                // Override this
                // Specs: 
                // cuda -> should memcpy from device / or maybe request singleton manager
                // opencl -> should request singleton manager and load buffer from device
            }

            virtual void releaseMemory()
            {
                // Override this
            }

            int rows() const
            {
                return m_rows;
            }

            int cols() const
            {
                return m_cols;
            }

            int size() const 
            {
                return m_size;
            }

            int channels() const
            {
                return m_channels;
            }

            float* hostCpuBuffer() { return m_host_cpuBuffer; }

            type::_type getGpuType() { return m_type; }

            int bufferSize() { return m_bufferSize; }



        };




    }




}