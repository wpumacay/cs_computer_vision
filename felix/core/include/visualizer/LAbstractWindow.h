

#pragma once

#include "../../LCommon.h"

using namespace std;

namespace felix
{

    namespace core
    {

        class LAbstractWindow
        {
            protected :

            LPixelRGBA* m_currentBuffer;

            public :

            virtual void close();

            virtual void addButton() = 0;
            virtual void addTrackbar() = 0;

            virtual void drawRectangle() = 0;
            virtual void drawCircle() = 0;

            virtual void showImage( LPixelRGBA* pBuffer ) = 0;


        };





    }







}