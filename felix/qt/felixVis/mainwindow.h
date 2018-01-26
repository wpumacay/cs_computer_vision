
#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include <QPixmap>

#include <windowWidgets/LRenderArea.h>

#include <ui/lpanelconvolution.h>
#include <ui/lpanelaffinetransforms.h>
#include <ui/lpanelhistogramequalization.h>
#include <ui/lpanelmedianfilter.h>
#include <ui/lpanelfouriertransform.h>

namespace Ui 
{
    class MainWindow;
}

namespace felix {
namespace qt {

    class LPanelConvolution;
    class LPanelAffineTransforms;
    class LPanelHistogramEqualization;
    class LPanelMedianFilter;
    class LPanelFourierTransform;

    class LMainWindow : public QMainWindow
    {
        Q_OBJECT

        private slots:

        void slotOpen();
        void slotSave();
        void slotQuit();
        
        void slotAffine();
        void slotConvolution();
        void slotHistEqualization();
        void slotMedianFilter();
        void slotFourierTransform();

        private:

        Ui::MainWindow *ui;

        LRenderArea* m_renderArea;

        LPanelConvolution* m_panelConvolution;
        LPanelAffineTransforms* m_panelAffineTransforms;
        LPanelHistogramEqualization* m_panelHistogramEqualization;
        LPanelMedianFilter* m_panelMedianFilter;
        LPanelFourierTransform* m_panelFourierTransform;

        void _setupActions();

        public:
            
        explicit LMainWindow( QWidget *parent = 0 );
        ~LMainWindow();
        
        QImage requestRenderImage( bool requestedWorkingImage = true );
        void setRenderImage( QImage image );
    };



}}



