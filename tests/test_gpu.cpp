

#include <cuda/testing/LCudaTesting.h>
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

    cout << "testing gpu functionality" << endl;

    felix::core::LCudaMat _imgCuda = felix::cuda::LCudaTesting::test_gen_rgb( 100, 100, 3 );

    //felix::core::LMatf _imgf( _imgCuda.rows(), _imgCuda.cols(), _imgCuda.channels(),
    //                          _imgCuda.hostCpuBuffer() );

    felix::core::LMatf _imgf( _imgCuda.rows(), _imgCuda.cols(), _imgCuda.channels() );
    _imgf.copyFromBuffer( _imgCuda.hostCpuBuffer() );

    //felix::core::LMatf _imgf = felix::core::LMatf::testImg();

    CImg<u8> _img_cimg = felix::plugins::convert2CImg( felix::utils::toMatu( _imgf ) );

    CImgDisplay _window( _img_cimg, "test rgb gpu" );

    cout << "done" << endl;

    while ( !_window.is_closed() ) 
    {
        _window.wait();
    }

    return 0;
}