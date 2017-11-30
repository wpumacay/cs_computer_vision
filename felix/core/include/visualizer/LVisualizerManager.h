

#pragma once

#include "LVisualizer.h"
#include "../mat/LMat.h"
#include "../mat/LGpuMat.h"

using namespace std;

namespace felix
{


    namespace core
    {



        class LVisualizerManager
        {

            private :

            LVisualizer* m_visualizer;

            LVisualizerManager();

            public :

            static LVisualizerManager* instance;

            static void create();

            void makeWindow( const char* wName );
            void showMat( const char* wName, LMatu& pMat );
            void showGpuMat( const char* wName, LGpuMat& pMat );

            void addTrackbar( string wName, string tName,
                              int min, int max, int tick, 
                              LFnPtr_trackbar callback );

            void show();

        };


    }









}