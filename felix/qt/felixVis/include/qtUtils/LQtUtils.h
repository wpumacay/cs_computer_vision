
#pragma once

#include <mat/LMat.h>
#include <utils/LUtils.h>

// #ifdef CUDA_SUPPORT_ENABLED
    
//     #include <mat/LGpuMat.h>

// #endif

#include <QImage>

namespace felix {
namespace qt {


    core::LMatf qImage2mat( QImage image );
    
    QImage mat2qImage( core::LMatf mat );


}}