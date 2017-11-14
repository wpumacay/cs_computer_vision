

#include <CImg.h>

using namespace cimg_library;

typedef unsigned char u8;


int main() 
{
    const u8 red[] = { 255, 0, 0 }, green[] = { 0, 255, 0 }, blue[] = { 0, 0, 255 };

    CImg<u8> image( "../res/lena.jpg" ), visu( 500, 400, 1, 3, 0 );
    image.blur( 2.5 );

    CImgDisplay main_disp( image, "Click a point" ), draw_disp( visu, "Intensity profile" );

    while ( !main_disp.is_closed() && !draw_disp.is_closed() ) 
    {
        main_disp.wait();
        if ( main_disp.button() && main_disp.mouse_y() >= 0 ) 
        {
            const int y = main_disp.mouse_y();
            visu.fill( 0 ).draw_graph( image.get_crop( 0, y, 0, 0, image.width() - 1, y, 0, 0 ), red, 1, 1, 0, 255, 0 );
            visu.draw_graph( image.get_crop( 0, y, 0, 1, image.width() - 1, y, 0, 1 ), green, 1, 1, 0, 255, 0 );
            visu.draw_graph( image.get_crop( 0, y, 0, 2, image.width() - 1, y, 0, 2 ), blue, 1, 1, 0, 255, 0 ).display( draw_disp );
        }
    }

    return 0;
}