
#include "../../../include/visualizer/gtk/LVisualizerGtk.h"

#include <glib.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

using namespace std;

namespace felix
{


    namespace core
    {

        LVisualizerGtk::LVisualizerGtk()
        {
            gtk_init( 0, NULL );
        }


        LVisualizerGtk::~LVisualizerGtk()
        {
            map< string, LAbstractWindow* >::iterator _it;

            for ( _it = m_windows.begin(); _it != m_windows.end(); ++ _it )
            {
                delete _it->second;
            }
        }

        void LVisualizerGtk::requestWindowCreation( string swName )
        {
            LWindowGtk* _newWindow = new LWindowGtk( swName );
            m_windows[swName] = _newWindow;
        }

        void LVisualizerGtk::requestWindowDisplay( string swName,
                                                   int width,
                                                   int height,
                                                   int channels,
                                                   u8* buffer )
        {
            m_windows[swName]->showImage( buffer, width, height, channels );
        }
        
        void LVisualizerGtk::requestTrackbarCreation( string wName, string tName,
                                                      int min, int max, int tick, 
                                                      LFnPtr_trackbar callback ) 
        {
            m_windows[wName]->addTrackbar( tName, min, max, tick, callback );
        }

        void LVisualizerGtk::showAll()
        {
            map< string, LAbstractWindow* >::iterator _it;

            for ( _it = m_windows.begin(); _it != m_windows.end(); ++ _it )
            {
                reinterpret_cast<LWindowGtk*>( _it->second )->show();
            }

            gtk_main();
        }

    }



}