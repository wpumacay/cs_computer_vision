
#include <loaders/LLoaderBitmap.h>
#include <transforms/LAffineTransforms.h>
#include <utils/LUtils.h>
#include <visualizer/LVisualizerManager.h>

#include <iostream>
#include <string>

using namespace std;

#define PI 3.1415926535897931

felix::core::LMatu* g_img;
felix::core::LMatf g_imgf;

felix::utils::LCpuTimer g_cpuTimer;

void onTrackbarCallbackRotation( float value )
{
    g_cpuTimer.start();
    felix::core::LMatf _imgResf = felix::transforms::LAffineTransforms::rotate( g_imgf,
                                                                                g_imgf.cols(),
                                                                                g_imgf.rows(),
                                                                                value * PI / 180.0f );
    felix::core::LMatu _imgResu = felix::utils::toMatu( _imgResf );
    felix::core::LVisualizerManager::instance->showMat( "sample rotated",
                                                        _imgResu );

    _imgResf.releaseMemory();
    _imgResu.releaseMemory();

    float _duration = g_cpuTimer.stop();

    cout << "delta-rotation: " << _duration * 1000.0f << endl;
}

void onTrackbarCallbackTranslation( float value )
{
    g_cpuTimer.start();
    felix::core::LMatf _imgResf = felix::transforms::LAffineTransforms::translate( g_imgf,
                                                                                   g_imgf.cols(),
                                                                                   g_imgf.rows(),
                                                                                   value, value );
    felix::core::LMatu _imgResu = felix::utils::toMatu( _imgResf );
    felix::core::LVisualizerManager::instance->showMat( "sample translated",
                                                        _imgResu );

    _imgResf.releaseMemory();
    _imgResu.releaseMemory();

    float _duration = g_cpuTimer.stop();

    cout << "delta-translation: " << _duration * 1000.0f << endl;
}

void onTrackbarCallbackScale( float value )
{
    g_cpuTimer.start();
    felix::core::LMatf _imgResf = felix::transforms::LAffineTransforms::scale( g_imgf,
                                                                               g_imgf.cols(),
                                                                               g_imgf.rows(),
                                                                               value / 100.0f,
                                                                               value / 100.0f );
    felix::core::LMatu _imgResu = felix::utils::toMatu( _imgResf );
    felix::core::LVisualizerManager::instance->showMat( "sample scaled",
                                                        _imgResu );

    _imgResf.releaseMemory();
    _imgResu.releaseMemory();
    float _duration = g_cpuTimer.stop();

    cout << "delta-scale: " << _duration * 1000.0f << endl;
}

int main()
{

    cout << "testing visualizer" << endl;

    g_img = felix::core::LLoaderBitmap::load( string( "../res/leo.bmp" ) );
    g_imgf = felix::utils::toMatf( *g_img );

    felix::core::LVisualizerManager::create();

    felix::core::LVisualizerManager::instance->makeWindow( "sample original" );
    felix::core::LVisualizerManager::instance->makeWindow( "sample rotated" );
    felix::core::LVisualizerManager::instance->makeWindow( "sample translated" );
    felix::core::LVisualizerManager::instance->makeWindow( "sample scaled" );

    felix::core::LVisualizerManager::instance->showMat( "sample original",
                                                        *g_img );
    felix::core::LVisualizerManager::instance->addTrackbar( string( "sample original" ),
                                                            string( "rotation" ),
                                                            0, 360, 1,
                                                            onTrackbarCallbackRotation );
    felix::core::LVisualizerManager::instance->addTrackbar( string( "sample original" ),
                                                            string( "translation" ),
                                                            -100, 100, 1,
                                                            onTrackbarCallbackTranslation );
    felix::core::LVisualizerManager::instance->addTrackbar( string( "sample original" ),
                                                            string( "scale" ),
                                                            50, 200, 1,
                                                            onTrackbarCallbackScale );

    felix::core::LVisualizerManager::instance->showMat( "sample rotated",
                                                        *g_img );
    felix::core::LVisualizerManager::instance->showMat( "sample translated",
                                                        *g_img );
    felix::core::LVisualizerManager::instance->showMat( "sample scaled",
                                                        *g_img );

    felix::core::LVisualizerManager::instance->show();

    cout << "done" << endl;

    return 0;
}