
#pragma once

#include <gtk/gtk.h>

#include "../LVisualizer.h"
#include "LWindowGtk.h"

using namespace std;

namespace felix
{

    namespace core
    {

        class LVisualizerGtk : public LVisualizer
        {

            private :



            public :

            LVisualizerGtk();
            ~LVisualizerGtk();


            virtual void requestWindowCreation( string swName ) override;

            virtual void requestWindowDisplay( string swName,
                                               int width,
                                               int height,
                                               int channels,
                                               u8* buffer ) override;

            virtual void requestSaveCurrentImage( string wName, const char* filename ) override;

            virtual void requestTrackbarCreation( string wName, string tName,
                                                  int min, int max, int tick, 
                                                  LFnPtr_trackbar callback ) override;

            virtual void requestButtonCreation( string wName, string tName,
                                                LFnPtr_button callback ) override;

            virtual void showAll() override;

        };







    }

}