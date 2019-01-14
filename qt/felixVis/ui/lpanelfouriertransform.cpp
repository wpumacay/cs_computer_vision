
#include "lpanelfouriertransform.h"
#include "ui_lpanelfouriertransform.h"


namespace felix {
namespace qt {

    LPanelFourierTransform::LPanelFourierTransform( QWidget *parent ) :
        QDialog( parent ),
        ui( new Ui::LPanelFourierTransform )
    {
        ui->setupUi( this );

        m_masterWindow = NULL;

        connect( ui->mButtonRefresh, &QPushButton::clicked, this, &LPanelFourierTransform::slotRefresh );

        show();
    }

    LPanelFourierTransform::~LPanelFourierTransform()
    {
        delete ui;
    }

    void LPanelFourierTransform::setMasterWindow( LMainWindow* pMasterWindow )
    {
        m_masterWindow = pMasterWindow;
        showFourierTransformMagnitude();
    }

    void LPanelFourierTransform::showFourierTransformMagnitude()
    {
        QImage _srcImage = m_masterWindow->requestRenderImage();
        QImage _dstImage = fFourierTranformMagnitude( _srcImage );

        ui->mLabelFourierTransform->setPixmap( QPixmap::fromImage( _dstImage.copy() ) );
    }

    void LPanelFourierTransform::slotRefresh()
    {
        showFourierTransformMagnitude();
    }

}}

