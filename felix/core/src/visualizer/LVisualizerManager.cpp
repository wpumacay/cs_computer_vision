

#include "../../include/visualizer/LVisualizerManager.h"

#ifdef GTK_SUPPORT_ENABLED
#include "../../include/visualizer/gtk/LVisualizerGtk.h"
#endif

namespace felix
{

    namespace core
    {

        LVisualizerManager* LVisualizerManager::instance = NULL;

        LVisualizerManager::LVisualizerManager()
        {
        #ifdef GTK_SUPPORT_ENABLED
            m_visualizer = new LVisualizerGtk();
        #endif
        }

        void LVisualizerManager::create()
        {
            if ( LVisualizerManager::instance != NULL )
            {
                delete LVisualizerManager::instance;
            }

            LVisualizerManager::instance = new LVisualizerManager();
        }

        void LVisualizerManager::makeWindow( const char* wName )
        {
            if ( m_visualizer == NULL )
            {
                std::cout << "LVisualizerManager::makeWindow> no visualizer initialized" << std::endl;
                return;
            }

            m_visualizer->requestWindowCreation( string( wName ) );
        }

        void LVisualizerManager::showMat( const char* wName, LMatu& pMat )
        {
            if ( m_visualizer == NULL )
            {
                std::cout << "LVisualizerManager::showMat> no visualizer initialized" << std::endl;
                return;
            }

            m_visualizer->requestWindowDisplay( string( wName ), 
                                                pMat.cols(),
                                                pMat.rows(),
                                                pMat.channels(),
                                                pMat.buffer() );
        }

        void LVisualizerManager::showGpuMat( const char* wName, LGpuMat& pMat )
        {
            if ( m_visualizer == NULL )
            {
                std::cout << "LVisualizerManager::showGpuMat> no visualizer initialized" << std::endl;
                return;
            }

            // TODO: WIP
        }

        void LVisualizerManager::addTrackbar( string wName, string tName,
                                              int min, int max, int tick, 
                                              LFnPtr_trackbar callback )
        {
            if ( m_visualizer == NULL )
            {
                std::cout << "LVisualizerManager::addTrackbar> no visualizer initialized" << std::endl;
                return;
            }            

            m_visualizer->requestTrackbarCreation( wName, tName, 
                                                   min, max, tick, 
                                                   callback );
        }

        void LVisualizerManager::show()
        {
            if ( m_visualizer == NULL )
            {
                std::cout << "LVisualizerManager::makeWindow> no visualizer initialized" << std::endl;
                return;
            }

            m_visualizer->showAll();
        }

    }



}