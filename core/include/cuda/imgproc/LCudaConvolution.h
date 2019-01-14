

#pragma once


#include "../../../LCommon.h"

#include "../../mat/LCudaMat.h"



namespace felix
{

    namespace cuda
    {

        struct LCudaConvolution
        {

            static core::LCudaMat warpAffine( core::LCudaMat& lCudaMat,
                                              int pDstCols, int pDstRows,
                                              float* pMatrix3f );
            
        };


    }

}