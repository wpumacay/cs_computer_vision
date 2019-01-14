

#include <loaders/LLoaderBitmap.h>
#include <cuda/transforms/LCudaAffineTransforms.h>
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
    felix::gpu::LGpuManager::create();

    cout << "testing bitmap loader" << endl;

    felix::core::LMatu* _img = felix::core::LLoaderBitmap::load( string( "../res/leo.bmp" ) );

    float* _transformMat = new float[9];

    float _angle = PI / 4;
    float _c = cos( _angle );
    float _s = sin( _angle );

    //_transformMat[0] = 2.0f; _transformMat[1] = 0.0f; _transformMat[2] = 0.0f;
    //_transformMat[3] = 0.0f; _transformMat[4] = 2.0f; _transformMat[5] = 0.0f;
    //_transformMat[6] = 0.0f; _transformMat[7] = 0.0f; _transformMat[8] = 1.0f;

    _transformMat[0] = _c; _transformMat[1] = -_s; _transformMat[2] = 0.0f;
    _transformMat[3] = _s; _transformMat[4] = _c; _transformMat[5] = 0.0f;
    _transformMat[6] = 0.0f; _transformMat[7] = 0.0f; _transformMat[8] = 1.0f;

    //_transformMat[0] = 1.0f; _transformMat[1] = 0.0f; _transformMat[2] = -50.0f;
    //_transformMat[3] = 0.0f; _transformMat[4] = 1.0f; _transformMat[5] = -50.0f;
    //_transformMat[6] = 0.0f; _transformMat[7] = 0.0f; _transformMat[8] = 1.0f;

    felix::core::LMatf _imgf = felix::utils::toMatf( *_img );
    //felix::core::LMatf _imgf = felix::core::LMatf::testImg();
    felix::core::LCudaMat _imgCudaf( _imgf.rows(), _imgf.cols(), 
                                     _imgf.channels(), _imgf.buffer() );

    felix::core::LCudaMat _imgCuda_scaled = felix::cuda::LCudaAffineTransforms::warpAffine( _imgCudaf,
                                                                                            _imgCudaf.cols(),
                                                                                            _imgCudaf.rows(),
                                                                                            _transformMat );

    felix::core::LMatf _img_scaled( _imgCuda_scaled.rows(), _imgCuda_scaled.cols(), _imgCuda_scaled.channels(),
                                    _imgCuda_scaled.hostCpuBuffer() );

    CImg<u8> _img_cimg = felix::plugins::convert2CImg( felix::utils::toMatu( _img_scaled ) );
    CImg<u8> _img_cimg_original = felix::plugins::convert2CImg( *_img );
    //CImg<u8> _img_cimg_original = felix::plugins::convert2CImg( felix::core::LMatu::testImg() );

    CImgDisplay _window_original( _img_cimg_original, "original image" );
    CImgDisplay _window( _img_cimg, "transformed image" );

    cout << "done" << endl;

    while ( !_window.is_closed() ) 
    {
        _window.wait();
    }

    return 0;
}