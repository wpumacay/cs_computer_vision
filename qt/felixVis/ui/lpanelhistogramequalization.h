
#pragma once

#include <QDialog>
#include <QImage>
#include <QtCore>
#include <mainwindow.h>
#include <qtWrappers/LWrapperGlobalProc.h>
#include <qwt_plot_curve.h>
#include <qwt_series_data.h>

namespace Ui 
{
    class LPanelHistogramEqualization;
}

namespace felix {
namespace qt {

    class LMainWindow;

    class LPanelHistogramEqualization : public QDialog
    {
        Q_OBJECT
        
        public :

        explicit LPanelHistogramEqualization( QWidget *parent = 0 );
        ~LPanelHistogramEqualization();

        void setMasterWindow( LMainWindow* pMasterWindow );

        void showHistogram();

        private slots :

        void slotApplyEqualization();
        
        private :

        Ui::LPanelHistogramEqualization *ui;
        LMainWindow* m_masterWindow;
        QwtPointSeriesData* m_histogramData;
        QwtPlotCurve* m_plotCurve;
    };


}}




