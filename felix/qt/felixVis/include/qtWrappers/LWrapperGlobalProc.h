
#pragma once

#include <qtUtils/LQtUtils.h>
#include <imgproc/globalproc/LHistogram.h>

namespace felix {
namespace qt {


    QImage fHistEqualization( QImage img );
    LHist fHistogram( QImage img );

}}