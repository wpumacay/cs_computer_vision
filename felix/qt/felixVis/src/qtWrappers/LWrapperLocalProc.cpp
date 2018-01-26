

#include <qtWrappers/LWrapperLocalProc.h>

namespace felix {
namespace qt {



    QImage fConvolution( QImage img, const LConvKernel& kernel )
    {
        core::LMatf _srcMat = qImage2mat( img );
        // _srcMat = core::rgb2gray<float>( core::LMatf::testImg() );

        core::LMatf _dstMat = convolve( _srcMat, kernel );

        _dstMat.normalize( 0.0f, 1.0f );

        // return mat2qImage( _srcMat );
        return mat2qImage( _dstMat );
    }


}}