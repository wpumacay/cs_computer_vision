

#include <mat/LMat.h>
#include <visualizer/LVisualizerManager.h>
#include <imgproc/globalproc/LHistogram.h>

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
    felix::core::LVisualizerManager::instance->makeWindow( "original - gray" );

    CImg<u8> _img( "../res/anas_dog.jpg" );

    felix::core::LMatu _mat = felix::plugins::convert2LMat( _img );

    cout << "c: " << _mat.channels() << endl;
    cout << "w: " << _mat.cols() << endl;
    cout << "h: " << _mat.rows() << endl;

    auto _matGray = felix::core::rgb2gray<u8>( _mat );

    auto _matEq = felix::LHistogram::equalize( _matGray );

    //auto _hist = felix::LHistogram::_computeHistogram( _matGray );
    //auto _histTransoform = felix::LHistogram::_computeHistTransform( _hist );

    //cout << "transform: " << _histTransoform.toString() << endl;

    auto _matRgbFromGray = felix::core::gray2rgb<u8>( _matEq );

    cout << "c: " << _matGray.channels() << endl;
    cout << "w: " << _matGray.cols() << endl;
    cout << "h: " << _matGray.rows() << endl;

    felix::core::LVisualizerManager::instance->showMat( "original - rgb",
                                                        _mat );
    felix::core::LVisualizerManager::instance->showMat( "original - gray",
                                                        _matRgbFromGray );

    felix::core::LVisualizerManager::instance->show();

    return 0;
}