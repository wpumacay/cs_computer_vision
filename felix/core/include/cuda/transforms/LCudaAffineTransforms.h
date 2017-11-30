

#pragma once


#include "../../LCommon.h"

#include "../../mat/LCudaMat.h"

namespace felix
{

    namespace cuda
    {

        struct LCudaAffineTransforms
        {

            static core::LCudaMat warpAffine( core::LCudaMat& lCudaMat,
                                              int pDstCols, int pDstRows,
                                              float* pMatrix3f );

            static core::LCudaMat scale( core::LCudaMat& lCudaMat,
                                         int pDstCols, int pDstRows,
                                         float sx, float sy );

            static core::LCudaMat rotate( core::LCudaMat& lCudaMat,
                                          int pDstCols, int pDstRows,
                                          float angle );

            static core::LCudaMat translate( core::LCudaMat& lCudaMat,
                                             int pDstCols, int pDstRows,
                                             float tx, float ty );



        };


    }




}