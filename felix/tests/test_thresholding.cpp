
#include <loaders/LLoaderBitmap.h>
#include <imgproc/globalproc/LThresholding.h>
#include <utils/LUtils.h>
#include <visualizer/LVisualizerManager.h>

#include <iostream>
#include <string>

using namespace std;

felix::core::LMatu g_img;
felix::core::LMatu g_imgBW;
felix::core::LMatu g_imgBWeroded;
felix::core::LMatu g_imgBWdilated;

u8 g_minValue = 0;
u8 g_maxValue = 255;

void onTrackbarCallbackMinRange( float minValue )
{
    g_minValue = ( u8 ) minValue;
    g_minValue = ( g_minValue > g_maxValue ) ? g_maxValue : g_minValue;

    g_imgBW = felix::threshRange( g_img, g_minValue, g_maxValue, 0 );

    auto _imgBW4display = felix::core::gray2rgb<u8>( g_imgBW );

    felix::core::LVisualizerManager::instance->showMat( "sample theshed",
                                                        _imgBW4display );
}

void onTrackbarCallbackMaxRange( float maxValue )
{
    g_maxValue = ( u8 ) maxValue;
    g_maxValue = ( g_maxValue < g_minValue ) ? g_minValue : g_maxValue;

    g_imgBW = felix::threshRange( g_img, g_minValue, g_maxValue, 0 );

    auto _imgBW4display = felix::core::gray2rgb<u8>( g_imgBW );

    felix::core::LVisualizerManager::instance->showMat( "sample theshed",
                                                        _imgBW4display );
}

void onTrackbarCallbackDilationSize( float newSize )
{
    int _size = newSize;

    auto _kernel = felix::makeBinKernel( _size, felix::binKernelType::SQUARE );

    auto _imgBW = felix::dilate( g_imgBW, _kernel );

    auto _imgBW4display = felix::core::gray2rgb<u8>( _imgBW );

    felix::core::LVisualizerManager::instance->showMat( "sample theshed dilated",
                                                        _imgBW4display );    
}

void onTrackbarCallbackErosionSize( float newSize )
{
    int _size = newSize;

    auto _kernel = felix::makeBinKernel( _size, felix::binKernelType::SQUARE );

    auto _imgBW = felix::erode( g_imgBW, _kernel );

    auto _imgBW4display = felix::core::gray2rgb<u8>( _imgBW );

    felix::core::LVisualizerManager::instance->showMat( "sample theshed eroded",
                                                        _imgBW4display );    
}

int main()
{

    cout << "testing visualizer" << endl;

    auto _img = felix::core::LLoaderBitmap::load( string( "../res/leo.bmp" ) );
    g_img = felix::core::rgb2gray<u8>( *_img );
    delete _img;

    felix::core::LVisualizerManager::create();

    felix::core::LVisualizerManager::instance->makeWindow( "sample original" );
    felix::core::LVisualizerManager::instance->makeWindow( "sample theshed" );
    felix::core::LVisualizerManager::instance->makeWindow( "sample theshed dilated" );
    felix::core::LVisualizerManager::instance->makeWindow( "sample theshed eroded" );

    felix::core::LVisualizerManager::instance->addTrackbar( string( "sample theshed" ),
                                                            string( "vMin" ),
                                                            0, 255, 1,
                                                            onTrackbarCallbackMinRange );
    felix::core::LVisualizerManager::instance->addTrackbar( string( "sample theshed" ),
                                                            string( "vMax" ),
                                                            0, 255, 1,
                                                            onTrackbarCallbackMaxRange );

    felix::core::LVisualizerManager::instance->addTrackbar( string( "sample theshed dilated" ),
                                                            string( "dilationSize" ),
                                                            3, 7, 2,
                                                            onTrackbarCallbackDilationSize );
    felix::core::LVisualizerManager::instance->addTrackbar( string( "sample theshed eroded" ),
                                                            string( "erosionSize" ),
                                                            3, 7, 2,
                                                            onTrackbarCallbackErosionSize );

    auto _img4display = felix::core::gray2rgb<u8>( g_img );

    felix::core::LVisualizerManager::instance->showMat( "sample original",
                                                        _img4display );

    felix::core::LVisualizerManager::instance->show();

    cout << "done" << endl;

    return 0;
}