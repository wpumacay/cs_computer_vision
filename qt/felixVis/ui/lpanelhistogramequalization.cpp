
#include "lpanelhistogramequalization.h"
#include "ui_lpanelhistogramequalization.h"

#include <iostream>
#include <cassert>

namespace felix {
namespace qt {


    LPanelHistogramEqualization::LPanelHistogramEqualization( QWidget *parent ) :
        QDialog( parent ),
        ui( new Ui::LPanelHistogramEqualization )
    {
        ui->setupUi( this );

        m_masterWindow = NULL;

        ui->mPlotHistogram->setAxisScale( QwtPlot::xBottom, 0, 255 );

        m_plotCurve = new QwtPlotCurve( "Histogram" );

        m_histogramData = new QwtPointSeriesData();

        QVector<QPointF> _samples;
        _samples.push_back( QPointF( 10, 10 ) );
        _samples.push_back( QPointF( 50, 20 ) );
        _samples.push_back( QPointF( 100, 30 ) );

        m_histogramData->setSamples( _samples );
        m_plotCurve->setData( m_histogramData );
        m_plotCurve->attach( ui->mPlotHistogram );
        ui->mPlotHistogram->replot();

        connect( ui->mButtonEqualize, &QPushButton::clicked, this, &LPanelHistogramEqualization::slotApplyEqualization );

        show();
    }

    LPanelHistogramEqualization::~LPanelHistogramEqualization()
    {
        delete ui;
    }

    void LPanelHistogramEqualization::setMasterWindow( LMainWindow* pMasterWindow )
    {
        m_masterWindow = pMasterWindow;
        showHistogram();
    }

    void LPanelHistogramEqualization::showHistogram()
    {
        assert( m_masterWindow != NULL );

        QImage _srcImage = m_masterWindow->requestRenderImage();

        if ( _srcImage.isNull() )        
        {
            return;
        }

        auto _hist = fHistogram( _srcImage );

        QVector<QPointF> _samples;
        for ( int q = 0; q < HISTOGRAM_BIN_SIZE; q++ )
        {
            _samples.push_back( QPointF( q, _hist.h[q] ) );
        }

        m_histogramData->setSamples( _samples );
        m_plotCurve->setData( m_histogramData );
        ui->mPlotHistogram->replot();
    }

    void LPanelHistogramEqualization::slotApplyEqualization()
    {
        assert( m_masterWindow != NULL );

        QImage _srcImage = m_masterWindow->requestRenderImage();

        if ( _srcImage.isNull() )        
        {
            return;
        }

        QImage _dstImage = fHistEqualization( _srcImage );

        m_masterWindow->setRenderImage( _dstImage );
        
        auto _hist = fHistogram( _dstImage );

        QVector<QPointF> _samples;
        for ( int q = 0; q < HISTOGRAM_BIN_SIZE; q++ )
        {
            _samples.push_back( QPointF( q, _hist.h[q] ) );
        }

        m_histogramData->setSamples( _samples );
        m_plotCurve->setData( m_histogramData );
        ui->mPlotHistogram->replot();
    }

}}