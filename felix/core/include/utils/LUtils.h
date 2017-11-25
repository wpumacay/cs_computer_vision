
#pragma once


#include "../../LCommon.h"
#include "../../core/include/mat/LMat.h"

using namespace felix::core;


namespace felix
{

    namespace utils
    {

        LMatf toMatf( const LMatu& img );
        LMatu toMatu( const LMatf& img );
    }





}