
#pragma once

#include <QDialog>
#include <mainwindow.h>
#include <QPushButton>
#include <QComboBox>
#include <windowWidgets/LKernelWidget.h>
#include <qtWrappers/LWrapperLocalProc.h>


namespace Ui 
{
    class LPanelConvolution;
}

namespace felix {
namespace qt {

    class LMainWindow;

    class LPanelConvolution : public QDialog
    {
        Q_OBJECT
        
        public :

        explicit LPanelConvolution( QWidget *parent = 0 );
        ~LPanelConvolution();

        void setMasterWindow( LMainWindow* pMasterWindow );
        
        private slots :

        void slotApplyKernel();
        void slotKernelType( int indx );

        private :

        Ui::LPanelConvolution *ui;

        LKernelWidget* m_kernelView;
        LMainWindow* m_masterWindow;
    };



}}

