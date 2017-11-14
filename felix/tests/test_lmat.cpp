

#include <iostream>

#include <CImg.h>
#include <LMat.h>
#include <plugins/felixMat.h>

using namespace std;

using namespace cimg_library;

typedef unsigned char u8;
typedef unsigned int  u32;


int main() 
{
    CImg<u8> image( "../res/lena.jpg" );

    felix::core::LMat<u8> _img( image.height(), 
                                image.width(), 
                                3, image.data() );

    felix::core::LMat<u8> _imgGray = felix::core::rgb2gray<u8>( _img );

    CImg<u8> imageGray = felix::plugins::convert2CImg( _imgGray );

    CImgDisplay main_disp( image, "original image" );
    CImgDisplay gray_disp( imageGray, "gray image" );

    cout << "w: " << imageGray.width() << endl;
    cout << "h: " << imageGray.height() << endl;
    cout << "d: " << imageGray.depth() << endl;
    cout << "c: " << imageGray.spectrum() << endl;

    cout << "_w: " << _imgGray.cols() << endl;
    cout << "_h: " << _imgGray.rows() << endl;

    cout << "__w: " << gray_disp.width() << endl;
    cout << "__h: " << gray_disp.height() << endl;

    while ( !main_disp.is_closed() ) 
    {
        main_disp.wait();
    }

    return 0;
}