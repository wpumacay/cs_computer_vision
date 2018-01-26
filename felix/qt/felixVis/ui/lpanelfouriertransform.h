
#pragma once

#include <QDialog>
#include <QPixmap>
#include <mainwindow.h>
#include <qtWrappers/LWrapperFourierTransform.h>

namespace Ui 
{
    class LPanelFourierTransform;
}

namespace felix {
namespace qt {

    class LMainWindow;

    class LPanelFourierTransform : public QDialog
    {
        Q_OBJECT
        
        public :
        
        explicit LPanelFourierTransform( QWidget *parent = 0 );
        ~LPanelFourierTransform();
        
        void setMasterWindow( LMainWindow* pMasterWindow );

        void showFourierTransformMagnitude();

        private slots :

        void slotRefresh();

        private :
        
        Ui::LPanelFourierTransform *ui;

        LMainWindow* m_masterWindow;
    };




}}

