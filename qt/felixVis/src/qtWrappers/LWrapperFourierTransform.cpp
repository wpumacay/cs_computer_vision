
#include <qtWrappers/LWrapperFourierTransform.h>

#include <iostream>

using namespace std;

namespace felix {
namespace qt {


    QImage fFourierTranformMagnitude( QImage img )
    {
        // cout << "???? 1" << endl;

        core::LMatf _srcMat = core::rgb2gray( qImage2mat( img ) );

        // cout << "???? 2" << endl;

        auto _ft = transforms::dft( _srcMat );

        // cout << "???? 3" << endl;

        auto _ftCenter = transforms::shiftCenter( _ft );

        // cout << "???? 4" << endl;

        auto _ftMag = transforms::getTransformMagnitude( _ftCenter );

        return mat2qImage( core::gray2rgb( _ftMag ) );
        //return mat2qImage( _srcMat );
        // return img;
    }



}}