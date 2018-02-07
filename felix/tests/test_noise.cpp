
#include <loaders/LLoaderBitmap.h>
#include <transforms/LAffineTransforms.h>
#include <imgproc/localproc/LMedianFilter.h>
#include <utils/LUtils.h>
#include <visualizer/LVisualizerManager.h>

#include <iostream>
#include <string>

using namespace std;


int main()
{

    cout << "testing noise" << endl;

    auto _img = felix::core::LLoaderBitmap::load( string( "../res/leo.bmp" ) );
    auto _imgf = felix::utils::toMatf( *_img );

    felix::core::LVisualizerManager::create();

    felix::core::LVisualizerManager::instance->makeWindow( "sample original" );
    felix::core::LVisualizerManager::instance->showMat( "sample original",
                                                        *_img );

    //auto _noise = felix::core::makeNoiseSaltPepper<float>( _imgf.cols(), _imgf.rows(), _imgf.channels(), 0.1, 1.0 );

    //felix::utils::addMats( _imgf, _noise );
    felix::utils::addNoiseSaltPepper( _imgf, 0.1 );

    auto _imgNoise = felix::utils::toMatu( _imgf );

    felix::core::LVisualizerManager::instance->makeWindow( "sample noise" );
    felix::core::LVisualizerManager::instance->showMat( "sample noise",
                                                        _imgNoise );

    auto _imgDenoised = felix::medianFilter( _imgf, 5, 5 );
    auto _imgDenoisedU = felix::utils::toMatu( _imgDenoised );

    felix::core::LVisualizerManager::instance->makeWindow( "sample denoised" );
    felix::core::LVisualizerManager::instance->showMat( "sample denoised",
                                                        _imgDenoisedU );

    felix::core::LVisualizerManager::instance->show();

    cout << "done" << endl;

    return 0;
}