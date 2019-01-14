

#pragma once

#include "../../mat/LMat.h"

using namespace std;


namespace felix
{

    float _getMedianPixel( const core::LMatf& srcMat, int i, int j, int c, int sizeW, int sizeH );
    core::LMatf medianFilter( const core::LMatf& srcMat, int sizeW, int sizeH );


}