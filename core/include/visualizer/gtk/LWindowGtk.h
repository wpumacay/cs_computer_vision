
#pragma once

#include <gtk/gtk.h>

#include "../LAbstractWindow.h"
#include "LWindowGtk.h"

using namespace std;

namespace felix
{

    namespace core
    {

        class LWindowGtk : public LAbstractWindow
        {

            private :

            GtkWidget* m_window;
            GtkWidget* m_frame;
            GtkImage* m_image;
            string m_name;

            public :

            LWindowGtk();
            LWindowGtk( string wName );

            map< string, LFnPtr_trackbar > trackbarCallbacks; 
            map< string, LFnPtr_button > buttonCallbacks;
            static vector<LWindowGtk*> g_windows;

            void show();

            void addTrackbar( string tName, 
                              int min, int max, 
                              int tick, LFnPtr_trackbar callback ) override;

            void addButton( string bName,
                            LFnPtr_button callback ) override;

            void showImage( u8* buffer, int w, int h, int c ) override;
            void saveCurrentImage( const char* filename ) override;

            static void callbackTrackbars( GtkRange* pTrackbar, gpointer pWin );
            static void callbackButtons( GtkWidget* pButton, gpointer pData );
        };






    }



}