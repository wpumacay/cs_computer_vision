

#include <loaders/LLoaderBitmap.h>
#include <transforms/LAffineTransforms.h>
#include <utils/LUtils.h>

#include <iostream>
#include <string>

#include <CImg.h>
#include <plugins/felixMat.h>

using namespace std;

using namespace cimg_library;
using namespace felix;

#define PI 3.1415926535897931

int main()
{
    cout << "testing bitmap loader" << endl;

    felix::core::LMatu* _img = felix::core::LLoaderBitmap::load( string( "../res/leo.bmp" ) );

    float* _scaleMat = new float[9];

    float _angle = PI / 4;
    float _c = cos( _angle );
    float _s = sin( _angle );

    //_scaleMat[0] = 2.0f; _scaleMat[1] = 0.0f; _scaleMat[2] = 0.0f;
    //_scaleMat[3] = 0.0f; _scaleMat[4] = 2.0f; _scaleMat[5] = 0.0f;
    //_scaleMat[6] = 0.0f; _scaleMat[7] = 0.0f; _scaleMat[8] = 1.0f;

    _scaleMat[0] = _c; _scaleMat[1] = -_s; _scaleMat[2] = 0.0f;
    _scaleMat[3] = _s; _scaleMat[4] = _c; _scaleMat[5] = 0.0f;
    _scaleMat[6] = 0.0f; _scaleMat[7] = 0.0f; _scaleMat[8] = 1.0f;

    //_scaleMat[0] = 1.0f; _scaleMat[1] = 0.0f; _scaleMat[2] = -50.0f;
    //_scaleMat[3] = 0.0f; _scaleMat[4] = 1.0f; _scaleMat[5] = -50.0f;
    //_scaleMat[6] = 0.0f; _scaleMat[7] = 0.0f; _scaleMat[8] = 1.0f;

    felix::core::LMatf _imgf = felix::utils::toMatf( *_img );

    felix::core::LMatf _img_scaled = felix::transforms::LAffineTransforms::warpAffine( _imgf,
                                                                                       _imgf.cols(),
                                                                                       _imgf.rows(),
                                                                                       _scaleMat );

    cout << "w: " << _img_scaled.cols() << endl;
    cout << "h: " << _img_scaled.rows() << endl;

    cout << "_w: " << _imgf.cols() << endl;
    cout << "_h: " << _imgf.rows() << endl;

    CImg<u8> _img_cimg = felix::plugins::convert2CImg( felix::utils::toMatu( _img_scaled ) );
    CImg<u8> _img_cimg_original = felix::plugins::convert2CImg( *_img );

    CImgDisplay _window_original( _img_cimg_original, "loaded image" );
    CImgDisplay _window( _img_cimg, "loaded image" );

    cout << "done" << endl;



    while ( !_window.is_closed() ) 
    {
        _window.wait();
    }

    return 0;
}