
#include "lpanelmedianfilter.h"
#include "ui_lpanelmedianfilter.h"

#include <cassert>

namespace felix {
namespace qt {


    LPanelMedianFilter::LPanelMedianFilter( QWidget *parent ) :
        QDialog( parent ),
        ui( new Ui::LPanelMedianFilter )
    {
        ui->setupUi( this );

        m_maskSize = 5;

        ui->mSpinboxMaskSize->setRange( 3, 10 );
        ui->mSpinboxMaskSize->setValue( m_maskSize );

        connect( ui->mButtonFilter, &QPushButton::clicked, this, &LPanelMedianFilter::slotApplyFilter );
        connect( ui->mButtonNoise, &QPushButton::clicked, this, &LPanelMedianFilter::slotApplyNoise );

        show();
    }

    LPanelMedianFilter::~LPanelMedianFilter()
    {
        delete ui;
    }

    void LPanelMedianFilter::setMasterWindow( LMainWindow* pMasterWindow )
    {
        m_masterWindow = pMasterWindow;
    }

    void LPanelMedianFilter::slotApplyFilter()
    {
        assert( m_masterWindow != NULL );

        m_maskSize = ui->mSpinboxMaskSize->value();

        QImage _srcImage = m_masterWindow->requestRenderImage( true );
        QImage _dstImage = fMedianFilter( _srcImage, m_maskSize );

        m_masterWindow->setRenderImage( _dstImage );

    }

    void LPanelMedianFilter::slotApplyNoise()
    {
        QImage _srcImage = m_masterWindow->requestRenderImage();
        QImage _dstImage = fApplyNoise( _srcImage );

        m_masterWindow->setRenderImage( _dstImage );
    }

}}

