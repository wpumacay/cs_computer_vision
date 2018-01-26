
#pragma once

#include <qtUtils/LQtUtils.h>
#include <imgproc/localproc/LConvolution.h>

namespace felix {
namespace qt {


    QImage fConvolution( QImage img, const LConvKernel& kernel );



}}