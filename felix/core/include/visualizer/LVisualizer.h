
#pragma once

#include "../../LCommon.h"
#include "../mat/LMat.h"
#include "../mat/LGpuMat.h"

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

            LVisualizer();

            virtual void _requestWindowCreation( string swName )
            {
                // Override this
            }

            virtual void _requestWindowDisplay( string swName,
                                                int width,
                                                int height,
                                                int channels,
                                                u8* buffer )
            {
                // Override this
            }

            public :

            ~LVisualizer();

            static LVisualizer* instance;

            static void create()
            {
                // Override this
            }

            virtual void init()
            {
                // Override this
            }

            void makeWindow( const char* wName )
            {
                _requestWindowCreation( string( wName ) );
            }

            void showMat( const char* wName, LMat* pMat )
            {
                _requestWindowDisplay( string( wName ), 
                                       pMat->cols(),
                                       pMat->rows(),
                                       pMat->channels(),
                                       pMat->buffer() );
            }

            void showGpuMat( const char* wName, LGpuMat* pMat )
            {

            }


        };







    }




}