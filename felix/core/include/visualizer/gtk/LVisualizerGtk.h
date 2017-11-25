
#pragma once

#include <gtk/gtk.h>

#include "../LVisualizer.h"


namespace felix
{

    namespace core
    {

        class LVisualizerGtk : public LVisualizer
        {

            private :

            GtkApplication* m_gtkApp;

            static void _onGtkAppActivated( GtkApplication* pApp, gpointer pUserData );

            public :

            static void create();


            LVisualizerGtk()
            {
                m_gtkApp = gtk_application_new( "felix.core", G_APPLICATION_FLAGS_NONE );
                g_signal_connect( m_gtkApp, "activate", G_CALLBACK( LVisualizerGtk::_onGtkAppActivated ), NULL );
            }

            ~LVisualizerGtk()
            {
                if ( m_gtkApp != NULL )
                {
                    delete m_gtkApp;
                    m_gtkApp = NULL;
                }
            }




        };







    }

}