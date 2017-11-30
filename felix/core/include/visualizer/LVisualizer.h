
#pragma once

#include "../../LCommon.h"
#include "LAbstractWindow.h"

using namespace std;

namespace felix
{

    namespace core
    {

        class LVisualizer
        {

            protected :

            map< string, LAbstractWindow* > m_windows;

            public :

            LVisualizer()
            {

            }

            ~LVisualizer()
            {

            }


            virtual void requestWindowCreation( string swName )
            {
                // Override this
            }

            virtual void requestWindowDisplay( string swName,
                                               int width,
                                               int height,
                                               int channels,
                                               u8* buffer )
            {
                // Override this
            }

            virtual void requestTrackbarCreation( string wName, string tName,
                                                  int min, int max, int tick, 
                                                  LFnPtr_trackbar callback )
            {
                // Override this
            }

            virtual void showAll()
            {
                // Override this
            }

        };

    }


}