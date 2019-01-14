
#pragma once

#include <qtUtils/LQtUtils.h>
#include <transforms/LAffineTransforms.h>

namespace felix {
namespace qt {


    QImage fAffineTransform( QImage img, float* pMatrix3f );


    QImage fRotationTransform( QImage img, float angle );
    QImage fTranslationTransform( QImage img, float tx, float ty );
    QImage fScaleTransform( QImage img, float scale );


}}