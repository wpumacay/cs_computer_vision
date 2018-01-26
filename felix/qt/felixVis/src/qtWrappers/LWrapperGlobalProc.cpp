

#include <qtWrappers/LWrapperGlobalProc.h>

namespace felix {
namespace qt {



    QImage fHistEqualization( QImage img )
    {
        core::LMatu _srcMat = utils::toMatu( qImage2mat( img ) );

        core::LMatu _dstMat = LHistogram::equalize( _srcMat );

        return mat2qImage( utils::toMatf( _dstMat ) );
    }

    LHist fHistogram( QImage img )
    {
        core::LMatu _srcMat = utils::toMatu( qImage2mat( img ) );

        // return LHistogram::_computeHistogram( core::rgb2gray<u8>( _srcMat ) );
        return LHistogram::_computeHistogram( _srcMat );
    }

}}