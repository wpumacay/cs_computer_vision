
#pragma once

#include <QDialog>
#include <mainwindow.h>

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

        explicit LPanelAffineTransforms( LMainWindow* parent );
        ~LPanelAffineTransforms();
        
        private:
        
        void _setupSignals();
        void _setupRanges();

        
        
        Ui::LPanelAffineTransforms *ui;
    };




}}
