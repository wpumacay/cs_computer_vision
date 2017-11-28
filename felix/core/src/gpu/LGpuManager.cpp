

#include "../../include/gpu/LGpuManager.h"

using namespace std;


namespace felix
{

    namespace gpu
    {



        LGpuManager* LGpuManager::instance = NULL;

        void LGpuManager::create()
        {
            if ( LGpuManager::instance != NULL )
            {
                cout << "LGpuManager::create> warning, gpu manager already exists" << endl;
                delete LGpuManager::instance;
            }

            LGpuManager::instance = new LGpuManager();
            LGpuManager::instance->init();

            cout << "LGpuManager::create> created gpu manager" << endl;
        }



        void LGpuManager::init()
        {
//#ifdef CUDA_SUPPORT_ENABLED
            m_cudaHandler = new LGpuCudaHandler();
            m_cudaHandler->init();
//#endif

        }

        void LGpuManager::loadToDevice( core::LGpuMat* pMat )
        {
            // Check gpu mat type
            if ( pMat->getGpuType() == core::type::CUDA )
            {
#ifdef CUDA_SUPPORT_ENABLED
                cout << "pMat: " << pMat << endl;
                m_cudaHandler->loadToDevice( (core::LCudaMat*) pMat );
#else
                cout << "LGpuManager::loadToDevice> no support enabled for cuda :(" << endl;
#endif
            }
            else if ( pMat->getGpuType() == core::type::OPENCL )
            {
#ifdef OPENCL_SUPPORT_ENABLED
                cout << "LGpuManager::loadToDevice> WIP for opencl" << endl;
#else
                cout << "LGpuManager::loadToDevice> no support enabled for opencl :(" << endl;
#endif
            }
        }

        void LGpuManager::loadFromDevice( core::LGpuMat* pMat )
        {
            // Check gpu mat type
            if ( pMat->getGpuType() == core::type::CUDA )
            {
#ifdef CUDA_SUPPORT_ENABLED
                cout << "pMat2: " << pMat << endl;
                m_cudaHandler->loadFromDevice( (core::LCudaMat*) pMat );
#else
                cout << "LGpuManager::loadFromDevice> no support enabled for cuda :(" << endl;
#endif
            }
            else if ( pMat->getGpuType() == core::type::OPENCL )
            {
#ifdef OPENCL_SUPPORT_ENABLED
                cout << "LGpuManager::loadFromDevice> WIP for opencl" << endl;
#else
                cout << "LGpuManager::loadFromDevice> no support enabled for opencl :(" << endl;
#endif
            }
        }

    }



}


