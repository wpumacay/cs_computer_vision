
#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include <QPixmap>

#include <windowWidgets/LRenderArea.h>

#include <ui/lpanelconvolution.h>
#include <ui/lpanelaffinetransforms.h>

namespace Ui 
{
    class MainWindow;
}

namespace felix {
namespace qt {

    class LPanelConvolution;
    class LPanelAffineTransforms;

    class LMainWindow : public QMainWindow
    {
        Q_OBJECT

        private slots:

        void slotOpen();
        void slotSave();
        void slotQuit();
        
        void slotAffine();
        
        void slotConvolution();

        private:

        Ui::MainWindow *ui;

        LRenderArea* m_renderArea;

        LPanelConvolution* m_panelConvolution;
        LPanelAffineTransforms* m_panelAffineTransforms;

        void _setupActions();

        public:
            
        explicit LMainWindow( QWidget *parent = 0 );
        ~LMainWindow();
        
        QImage requestRenderImage();
        void setRenderImage( QImage image );
    };



}}



