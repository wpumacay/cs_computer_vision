

#pragma once

#include "../../LCommon.h"

using namespace std;

namespace felix
{

    struct LImage
    {
        u8* buffer;
        int w;
        int h;
        int c;
    };

    namespace core
    {

        class LAbstractWindow
        {
            protected :

            LImage m_img;

            public :

            //virtual void close();

            virtual void addButton( string bName,
                                    LFnPtr_button callback ) = 0;
            virtual void addTrackbar( string tName, 
                                      int min, int max, int tick, 
                                      LFnPtr_trackbar callback ) = 0;


            //virtual void drawRectangle() = 0;
            //virtual void drawCircle() = 0;

            virtual void showImage( u8* buffer, int w, int h, int c ) = 0;
            virtual void saveCurrentImage( const char* filename ) = 0;


        };





    }







}