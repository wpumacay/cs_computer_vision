
#pragma once

#include <qtUtils/LQtUtils.h>
#include <imgproc/localproc/LConvolution.h>
#include <imgproc/localproc/LMedianFilter.h>
#include <utils/LUtils.h>

namespace felix {
namespace qt {


    QImage fConvolution( QImage img, const LConvKernel& kernel );

    QImage fMedianFilter( QImage img, int maskSize );
    QImage fApplyNoise( QImage img );

}}