
#pragma once

#include <QDialog>
#include <mainwindow.h>
#include <qtWrappers/LWrapperAffineTransforms.h>

namespace Ui 
{
    class LPanelAffineTransforms;
}

namespace felix {
namespace qt {


    class LMainWindow;

    class LPanelAffineTransforms : public QDialog
    {
        Q_OBJECT
        
        private slots :
        
        void slotOnRotation( int angle );
        void slotOnTranslationX( int dx );
        void slotOnTranslationY( int dy );
        void slotOnScale( int scalePercent );
        
        public:

        explicit LPanelAffineTransforms();
        ~LPanelAffineTransforms();
        
        void setMasterWindow( LMainWindow* pMasterWindow );

        private:
        
        LMainWindow* m_masterWindow;

        void _setupSignals();
        void _setupRanges();

        
        
        Ui::LPanelAffineTransforms *ui;
    };




}}
