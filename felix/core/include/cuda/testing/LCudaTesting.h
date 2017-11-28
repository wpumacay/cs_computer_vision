

#pragma once


#include "../../LCommon.h"

#include "../../mat/LCudaMat.h"

namespace felix
{

    namespace cuda
    {

        struct LCudaTesting
        {

            static core::LCudaMat test_gen_rgb( int rows, int cols, int channels );

        };


    }




}