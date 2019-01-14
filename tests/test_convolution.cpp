

#include <mat/LMat.h>
#include <utils/LUtils.h>
#include <visualizer/LVisualizerManager.h>
#include <imgproc/localproc/LConvolution.h>

#include <CImg.h>
#include <plugins/felixMat.h>

#include <iostream>
#include <string>

using namespace cimg_library;
using namespace std;


int main()
{
    felix::core::LVisualizerManager::create();

    felix::core::LVisualizerManager::instance->makeWindow( "original - rgb" );
    felix::core::LVisualizerManager::instance->makeWindow( "original - blurred" );

    CImg<u8> _img( "../res/lena.jpg" );

    felix::core::LMatu _mat = felix::plugins::convert2LMat( _img );
    felix::core::LMatf _matf = felix::utils::toMatf( _mat );

    auto _kernel = felix::makeKernelAverage( 15, 15 );
    auto _matBlurredf = felix::convolve( _matf, _kernel );
    auto _matBlurredu = felix::utils::toMatu( _matBlurredf );

    felix::core::LVisualizerManager::instance->showMat( "original - rgb",
                                                        _mat );
    felix::core::LVisualizerManager::instance->showMat( "original - blurred",
                                                        _matBlurredu );

    felix::core::LVisualizerManager::instance->show();

    return 0;
}