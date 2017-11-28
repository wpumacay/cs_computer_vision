

#pragma once

#include "../../LCommon.h"

//#ifdef CUDA_SUPPORT_ENABLED
#include "LGpuCudaHandler.h"
//#endif

using namespace std;


namespace felix
{

    namespace core
    {
        class LGpuMat;
    }

    namespace gpu
    {

        class LGpuCudaHandler;

        class LGpuManager
        {

            private :

//#ifdef CUDA_SUPPORT_ENABLED

            LGpuCudaHandler* m_cudaHandler;
//#endif
            LGpuManager()
            {
                
            }

            public :


            static LGpuManager* instance;
            static void create();

            void init();
            void loadToDevice( core::LGpuMat* pMat );
            void loadFromDevice( core::LGpuMat* pMat );

        };




    }







}