
#pragma once

#include <QDialog>
#include <mainwindow.h>
#include <qtWrappers/LWrapperLocalProc.h>

namespace Ui 
{
    class LPanelMedianFilter;
}

namespace felix {
namespace qt {

    class LMainWindow;

    class LPanelMedianFilter : public QDialog
    {
        Q_OBJECT
        
        public :
        
        explicit LPanelMedianFilter( QWidget *parent = 0 );
        ~LPanelMedianFilter();

        void setMasterWindow( LMainWindow* pMasterWindow );
        
        private slots :

        void slotApplyNoise();
        void slotApplyFilter();

        private :

        Ui::LPanelMedianFilter *ui;

        LMainWindow* m_masterWindow;

        int m_maskSize;
    };


}}

