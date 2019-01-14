
#pragma once

#include "../../LCommon.h"

#include "../mat/LCudaMat.h"

#include <cuda.h>
#include <cuda_runtime.h>

namespace felix
{

    namespace core
    {
        class LCudaMat;
    }

    namespace gpu
    {


        class LGpuCudaHandler
        {
            private :

            // Device stuff


            public :

            LGpuCudaHandler()
            {

            }

            void init();
            void loadToDevice( core::LCudaMat* pMat );
            void loadFromDevice( core::LCudaMat* pMat );



        };






    }



}