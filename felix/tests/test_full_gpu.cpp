
#include <loaders/LLoaderBitmap.h>
#include <cuda/transforms/LCudaAffineTransforms.h>
#include <mat/LMat.h>
#include <utils/LUtils.h>
#include <visualizer/LVisualizerManager.h>

#include <iostream>
#include <string>

using namespace std;

#define PI 3.1415926535897931

felix::core::LMatu* g_img;
felix::core::LMatf g_imgf;
felix::core::LCudaMat g_imgCuda;

void onTrackbarCallbackRotation( float value )
{
    felix::core::LCudaMat _imgRes = felix::cuda::LCudaAffineTransforms::rotate( g_imgCuda,
                                                                                g_imgCuda.cols(),
                                                                                g_imgCuda.rows(),
                                                                                value * PI / 180.0f );
    felix::core::LMatf _imgResf( _imgRes.rows(), _imgRes.cols(), _imgRes.channels(),
                                 _imgRes.hostCpuBuffer() );
    felix::core::LMatu _imgResu = felix::utils::toMatu( _imgResf );
    felix::core::LVisualizerManager::instance->showMat( "sample rotated",
                                                        _imgResu );

    _imgRes.releaseMemory();
    _imgResf.releaseMemory();
    _imgResu.releaseMemory();
}

void onTrackbarCallbackTranslation( float value )
{
    felix::core::LCudaMat _imgRes = felix::cuda::LCudaAffineTransforms::translate( g_imgCuda,
                                                                                   g_imgCuda.cols(),
                                                                                   g_imgCuda.rows(),
                                                                                   value, value );
    felix::core::LMatf _imgResf( _imgRes.rows(), _imgRes.cols(), _imgRes.channels(),
                                 _imgRes.hostCpuBuffer() );
    felix::core::LMatu _imgResu = felix::utils::toMatu( _imgResf );
    felix::core::LVisualizerManager::instance->showMat( "sample translated",
                                                        _imgResu );

    _imgRes.releaseMemory();
    _imgResf.releaseMemory();
    _imgResu.releaseMemory();
}

void onTrackbarCallbackScale( float value )
{
    felix::core::LCudaMat _imgRes = felix::cuda::LCudaAffineTransforms::scale( g_imgCuda,
                                                                               g_imgCuda.cols(),
                                                                               g_imgCuda.rows(),
                                                                               value / 100.0f,
                                                                               value / 100.0f );
    felix::core::LMatf _imgResf( _imgRes.rows(), _imgRes.cols(), _imgRes.channels(),
                                 _imgRes.hostCpuBuffer() );
    felix::core::LMatu _imgResu = felix::utils::toMatu( _imgResf );
    felix::core::LVisualizerManager::instance->showMat( "sample scaled",
                                                        _imgResu );

    _imgRes.releaseMemory();
    _imgResf.releaseMemory();
    _imgResu.releaseMemory();
}

int main()
{
    felix::gpu::LGpuManager::create();

    cout << "testing visualizer" << endl;

    g_img = felix::core::LLoaderBitmap::load( string( "../res/leo.bmp" ) );
    g_imgf = felix::utils::toMatf( *g_img );
    g_imgCuda = felix::core::LCudaMat( g_imgf.rows(), g_imgf.cols(), 
                                       g_imgf.channels(), g_imgf.buffer()  );

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