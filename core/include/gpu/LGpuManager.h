

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

#ifdef CUDA_SUPPORT_ENABLED

            LGpuCudaHandler* m_cudaHandler;
            cudaEvent_t m_evtStart;
            cudaEvent_t m_evtStop;
#endif
            LGpuManager()
            {
                
            }

            public :


            static LGpuManager* instance;
            static void create();

            void timerStart();
            void timerStop();
            float getElapsedTime(); 

            void init();
            void loadToDevice( core::LGpuMat* pMat );
            void loadFromDevice( core::LGpuMat* pMat );

        };




    }







}