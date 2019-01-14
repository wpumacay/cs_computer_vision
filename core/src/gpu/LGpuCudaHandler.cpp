
#include "../../include/gpu/LGpuCudaHandler.h"

using namespace std;


namespace felix
{

    namespace gpu
    {


        void LGpuCudaHandler::init()
        {
            // Do specific device configuration stuff here
        }


        void LGpuCudaHandler::loadToDevice( core::LCudaMat* pMat )
        {
            //cudaError_t _errorCode;

            //cout << "host: " << pMat->hostCpuBuffer() << endl;

            /*_errorCode = */cudaMemcpy( pMat->devGpuBuffer(), 
                                         pMat->hostCpuBuffer(), 
                                         pMat->bufferSize(),
                                         cudaMemcpyHostToDevice );

            //cout << "_errorCode_to: " << _errorCode << endl;
        }

        void LGpuCudaHandler::loadFromDevice( core::LCudaMat* pMat )
        {
            //cudaError_t _errorCode;

            /*_errorCode = */cudaMemcpy( pMat->hostCpuBuffer(), 
                                         pMat->devGpuBuffer(), 
                                         pMat->bufferSize(),
                                         cudaMemcpyDeviceToHost );

            //cout << "_errorCode_from: " << _errorCode << endl;
        }

    }





}