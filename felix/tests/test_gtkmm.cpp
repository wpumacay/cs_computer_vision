

#include <iostream>
#include <pthread.h>
#include <gtkmm.h>
#include <gdkmm/pixbuf.h>
#include <gtkmm/drawingarea.h>

using namespace std;

struct GtkAppInfo
{
    Glib::RefPtr<Gtk::Application> pApp;
    Gtk::Window* pWindow;
};

void* p_guiThread( void* pGtkAppInfo )
{
    GtkAppInfo* _appInfo = reinterpret_cast<GtkAppInfo*>( pGtkAppInfo );

    _appInfo->pApp->run( *( _appInfo->pWindow ) );

    return NULL;
}



int main( int argc, char *argv[] )
{
    auto app = Gtk::Application::create( argc, argv,
                                         "org.gtkmm.examples.base");

    Gtk::Window window;
    window.set_default_size(200, 200);

    pthread_t _threadHandle;

    GtkAppInfo _appInfo;
    _appInfo.pApp = app;
    _appInfo.pWindow = &window;

    pthread_create( &_threadHandle, NULL, p_guiThread, ( void* ) &_appInfo );

    while( true )
    {
        cout << "???" << endl;
    }

    pthread_join( _threadHandle, NULL );

    return 0;
}