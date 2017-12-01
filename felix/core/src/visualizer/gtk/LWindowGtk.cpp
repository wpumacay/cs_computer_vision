
#include "../../../include/visualizer/gtk/LWindowGtk.h"

using namespace std;


namespace felix
{


    namespace core
    {

        vector<LWindowGtk*> LWindowGtk::g_windows;

        LWindowGtk::LWindowGtk()
        {
            m_name = "sample window";
            m_window = gtk_window_new( GTK_WINDOW_TOPLEVEL );

            gtk_window_set_title( GTK_WINDOW( m_window ), m_name.c_str() );
            gtk_window_set_default_size( GTK_WINDOW( m_window ), 400, 400 );

            m_frame = gtk_box_new( GTK_ORIENTATION_VERTICAL, 5 );

            gtk_container_add( GTK_CONTAINER( m_window ), ( GtkWidget* ) m_frame );

            m_image = NULL;

            LWindowGtk::g_windows.push_back( this );
        }

        LWindowGtk::LWindowGtk( string wName )
        {
            m_name = wName;
            m_window = gtk_window_new( GTK_WINDOW_TOPLEVEL );

            gtk_window_set_title( GTK_WINDOW( m_window ), m_name.c_str() );
            gtk_window_set_default_size( GTK_WINDOW( m_window ), 400, 400 );

            m_frame = gtk_box_new( GTK_ORIENTATION_VERTICAL, 5 );

            gtk_container_add( GTK_CONTAINER( m_window ), ( GtkWidget* ) m_frame );

            m_image = NULL;

            LWindowGtk::g_windows.push_back( this );
        }

        void LWindowGtk::show()
        {
            gtk_widget_show_all( m_window );
        }

        void LWindowGtk::showImage( u8* buffer, int w, int h, int c )
        {

            int _buffSize = w * h * c;
            GBytes* _buff = g_bytes_new( buffer, 
                                         sizeof( unsigned char ) * _buffSize );

            GdkPixbuf* _pbuff = gdk_pixbuf_new_from_bytes( _buff, 
                                                           GDK_COLORSPACE_RGB, 
                                                           false, 
                                                           8, w, h,
                                                           c * w );
            if ( m_image == NULL )
            {
                m_image = ( GtkImage* ) gtk_image_new_from_pixbuf( _pbuff );
                //gtk_container_add( GTK_CONTAINER( m_frame ), ( GtkWidget* ) m_image );
                gtk_box_set_center_widget( ( GtkBox* ) m_frame, ( GtkWidget* ) m_image );
            }
            else
            {
                gtk_image_set_from_pixbuf( m_image, _pbuff );
            }

            gtk_widget_show_all( m_window );
        }

        void LWindowGtk::saveCurrentImage( const char* filename )
        {
            if ( m_image == NULL )
            {
                std::cout << "could not save the image, not defined yet" << std::endl;
                return;
            }

            GdkPixbuf* _pbuff = gtk_image_get_pixbuf( m_image );
            gdk_pixbuf_save( _pbuff, filename, "bmp", NULL, NULL );
            std::cout << "saved image to: " << filename << std::endl;
        }

        void LWindowGtk::addTrackbar( string tName, 
                                      int min, int max, int tick, 
                                      LFnPtr_trackbar callback )
        {
            trackbarCallbacks[tName] = callback;
            GtkRange* _trackbar = ( GtkRange* ) gtk_scale_new_with_range( GTK_ORIENTATION_HORIZONTAL, min, max, tick );
            gtk_widget_set_name( ( GtkWidget* ) _trackbar, tName.c_str() );
            gtk_scale_set_draw_value( GTK_SCALE( _trackbar ), TRUE );
            gtk_widget_set_size_request( ( GtkWidget* ) _trackbar, 150, -1 );

            gtk_container_add( GTK_CONTAINER( m_frame ), ( GtkWidget* ) _trackbar );

            g_signal_connect( _trackbar, "value-changed",
                              G_CALLBACK( LWindowGtk::callbackTrackbars ), NULL );

            gtk_widget_show_all( m_window );
        }


        void LWindowGtk::addButton( string bName,
                                    LFnPtr_button callback )
        {
            buttonCallbacks[bName] = callback;
            GtkWidget* _button = gtk_button_new_with_label( bName.c_str() );
            gtk_widget_set_name( _button, bName.c_str() );

            gtk_container_add( GTK_CONTAINER( m_frame ), _button );

            g_signal_connect( _button, "clicked",
                              G_CALLBACK( LWindowGtk::callbackButtons ), NULL );

            gtk_widget_show_all( m_window );
        }

        void LWindowGtk::callbackTrackbars( GtkRange* pTrackbar, gpointer _dummy )
        {
            vector<LWindowGtk*> _windows = LWindowGtk::g_windows;

            string _tName( gtk_widget_get_name( ( GtkWidget* ) pTrackbar ) );

            float _val = gtk_range_get_value( pTrackbar );

            for ( int q = 0; q < _windows.size(); q++ )
            {
                map< string, LFnPtr_trackbar > _trackbarCallbacks = _windows[q]->trackbarCallbacks;
                map< string, LFnPtr_trackbar >::iterator _it;

                _it = _trackbarCallbacks.find( _tName );

                if ( _it != _trackbarCallbacks.end() )
                {
                    LFnPtr_trackbar _callback = _it->second;

                    _callback( _val );
                    break;
                }

            }
        }


        void LWindowGtk::callbackButtons( GtkWidget* pButton, gpointer _dummy )
        {
            vector<LWindowGtk*> _windows = LWindowGtk::g_windows;

            string _tName( gtk_widget_get_name( pButton ) );

            for ( int q = 0; q < _windows.size(); q++ )
            {
                map< string, LFnPtr_button > _buttonCallbacks = _windows[q]->buttonCallbacks;
                map< string, LFnPtr_button >::iterator _it;

                _it = _buttonCallbacks.find( _tName );

                if ( _it != _buttonCallbacks.end() )
                {
                    LFnPtr_button _callback = _it->second;

                    _callback();
                    break;
                }

            }
        }

    }






}