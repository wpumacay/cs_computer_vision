
#include <loaders/LLoaderBitmap.h>
#include <transforms/LAffineTransforms.h>
#include <utils/LUtils.h>
#include <visualizer/LVisualizerManager.h>

#include <iostream>
#include <string>

using namespace std;

#define PI 3.1415926535897931

felix::core::LMatu* g_img;


void onTrackbarCallback( float value )
{
    //cout << "value: " << value << endl;

    float* _matTransform = new float[9];

    float _angle = value * PI / 180.0f;
    float _c = cos( _angle );
    float _s = sin( _angle );

    _matTransform[0] = _c; _matTransform[1] = -_s; _matTransform[2] = 0.0f;
    _matTransform[3] = _s; _matTransform[4] = _c; _matTransform[5] = 0.0f;
    _matTransform[6] = 0.0f; _matTransform[7] = 0.0f; _matTransform[8] = 1.0f;

    felix::core::LMatf _imgf = felix::utils::toMatf( *g_img );
    felix::core::LMatf _imgTransformed_f = felix::transforms::LAffineTransforms::warpAffine( _imgf,
                                                                                             _imgf.cols(),
                                                                                             _imgf.rows(),
                                                                                             _matTransform );


    felix::core::LMatu _imgTransformed_u = felix::utils::toMatu( _imgTransformed_f );
    felix::core::LVisualizerManager::instance->showMat( "sample transformed",
                                                        _imgTransformed_u );
}

int main()
{


    cout << "testing visualizer" << endl;

    g_img = felix::core::LLoaderBitmap::load( string( "../res/leo.bmp" ) );

    float* _matTransform = new float[9];

    float _angle = PI / 4;
    float _c = cos( _angle );
    float _s = sin( _angle );

    _matTransform[0] = _c; _matTransform[1] = -_s; _matTransform[2] = 0.0f;
    _matTransform[3] = _s; _matTransform[4] = _c; _matTransform[5] = 0.0f;
    _matTransform[6] = 0.0f; _matTransform[7] = 0.0f; _matTransform[8] = 1.0f;

    felix::core::LMatf _imgf = felix::utils::toMatf( *g_img );

    felix::core::LMatf _imgTransformed_f = felix::transforms::LAffineTransforms::warpAffine( _imgf,
                                                                                             _imgf.cols(),
                                                                                             _imgf.rows(),
                                                                                             _matTransform );

    felix::core::LMatu _imgTransformed_u = felix::utils::toMatu( _imgTransformed_f );

    felix::core::LVisualizerManager::create();

    felix::core::LVisualizerManager::instance->makeWindow( "sample original" );
    felix::core::LVisualizerManager::instance->makeWindow( "sample transformed" );

    felix::core::LVisualizerManager::instance->showMat( "sample original",
                                                        *g_img );
    felix::core::LVisualizerManager::instance->showMat( "sample transformed",
                                                        _imgTransformed_u );


    felix::core::LVisualizerManager::instance->addTrackbar( string( "sample original" ),
                                                            string( "rotation" ),
                                                            0, 360, 1,
                                                            onTrackbarCallback );

    felix::core::LVisualizerManager::instance->show();

    cout << "done" << endl;

    return 0;
}