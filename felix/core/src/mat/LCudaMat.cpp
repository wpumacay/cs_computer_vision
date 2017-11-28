

#include "../../include/mat/LCudaMat.h"

namespace felix
{

    namespace core
    {
        void LCudaMat::loadToGpu()
        {
            std::cout << "loadToGpu" << std::endl;
            gpu::LGpuManager::instance->loadToDevice( this );
        }

        void LCudaMat::loadFromGpu()
        {
            std::cout << "loadFromGpu" << std::endl;
            gpu::LGpuManager::instance->loadFromDevice( this );
        }
    }


}