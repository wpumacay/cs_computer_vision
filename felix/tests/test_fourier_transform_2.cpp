

#include <mat/LMat.h>
#include <transforms/LFourierTransform.h>
#include <utils/LUtils.h>
#include <visualizer/LVisualizerManager.h>

#define cimg_use_jpeg
#include <CImg.h>
#include <plugins/felixMat.h>

#include <iostream>
#include <string>

using namespace cimg_library;
using namespace std;


int main()
{
    felix::core::LVisualizerManager::create();

    felix::core::LVisualizerManager::instance->makeWindow( "test_image" );
    felix::core::LVisualizerManager::instance->makeWindow( "ft_magnitude" );
    felix::core::LVisualizerManager::instance->makeWindow( "ft_inverse" );

    CImg<u8> _img( "../res/lena_small.jpeg" );

    auto _matu = felix::plugins::convert2LMat( _img );
    auto _matgray = felix::core::rgb2gray( _matu );
    auto _matf = felix::utils::toMatf( _matgray );

    auto _ft = felix::transforms::dft( _matf );
    auto _ftCenter = felix::transforms::shiftCenter( _ft );

    auto _ftMag = felix::transforms::getTransformMagnitude( _ftCenter );
    //auto _ftMag = felix::transforms::getTransformMagnitude( _ft );

    auto _imgInv = felix::transforms::dft_inverse( _ft );

    auto _imgU = felix::core::gray2rgb( _matgray );
    auto _ftMagU = felix::core::gray2rgb( felix::utils::toMatu( _ftMag ) );
    auto _imgInvU = felix::core::gray2rgb( felix::utils::toMatu( _imgInv ) );

    felix::core::LVisualizerManager::instance->showMat( "test_image",
                                                        _imgU );
    felix::core::LVisualizerManager::instance->showMat( "ft_magnitude",
                                                        _ftMagU );
    felix::core::LVisualizerManager::instance->showMat( "ft_inverse",
                                                        _imgInvU );

    felix::core::LVisualizerManager::instance->show();

    return 0;
}