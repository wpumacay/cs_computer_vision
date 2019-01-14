

#include <qtWrappers/LWrapperAffineTransforms.h>

namespace felix {
namespace qt {


    QImage fAffineTransform( QImage img, float* pMatrix3f )
    {
        core::LMatf _srcMat = qImage2mat( img );

        core::LMatf _dstMat = transforms::LAffineTransforms::warpAffine( _srcMat,
                                                                         _srcMat.cols(),
                                                                         _srcMat.rows(),
                                                                         pMatrix3f );

        return mat2qImage( _dstMat );
    }


    QImage fRotationTransform( QImage img, float angle )
    {
        core::LMatf _srcMat = qImage2mat( img );

        core::LMatf _dstMat = transforms::LAffineTransforms::rotate( _srcMat,
                                                                     _srcMat.cols(),
                                                                     _srcMat.rows(),
                                                                     angle * _PI / 180.0 );

        return mat2qImage( _dstMat );
    }

    QImage fTranslationTransform( QImage img, float tx, float ty )
    {
        core::LMatf _srcMat = qImage2mat( img );

        core::LMatf _dstMat = transforms::LAffineTransforms::translate( _srcMat,
                                                                        _srcMat.cols(),
                                                                        _srcMat.rows(),
                                                                        tx, ty );

        return mat2qImage( _dstMat );
    }
    
    QImage fScaleTransform( QImage img, float scale )
    {
        core::LMatf _srcMat = qImage2mat( img );

        core::LMatf _dstMat = transforms::LAffineTransforms::scale( _srcMat,
                                                                    _srcMat.cols(),
                                                                    _srcMat.rows(),
                                                                    scale, scale );

        return mat2qImage( _dstMat );
    }


}}