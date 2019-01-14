

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

    QImage fMedianFilter( QImage img, int maskSize )
    {
        core::LMatf _srcMat = qImage2mat( img );

        core::LMatf _dstMat = medianFilter( _srcMat, maskSize, maskSize );

        return mat2qImage( _dstMat );
    }

    QImage fApplyNoise( QImage img )
    {
        core::LMatf _srcMat = qImage2mat( img );

        utils::addNoiseSaltPepper( _srcMat, 0.1 );

        return mat2qImage( _srcMat );
    }


}}