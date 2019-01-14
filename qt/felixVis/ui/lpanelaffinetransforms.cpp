
#include "lpanelaffinetransforms.h"
#include "ui_lpanelaffinetransforms.h"

#include <iostream>
#include <cassert>

namespace felix {
namespace qt {


    LPanelAffineTransforms::LPanelAffineTransforms() :
        QDialog( NULL ),
        ui( new Ui::LPanelAffineTransforms )
    {
        ui->setupUi( this );
        
        _setupRanges();
        _setupSignals();
        
        show();

        m_masterWindow = NULL;
        
        // std::cout << "created affine transforms panel" << std::endl;
    }

    LPanelAffineTransforms::~LPanelAffineTransforms()
    {
        // std::cout << "destroyed affine transforms panel" << std::endl;
        delete ui;
    }

    void LPanelAffineTransforms::_setupRanges()
    {
        ui->mSliderRotation->setRange( 0, 360 );
        ui->mSliderTranslationX->setRange( -100, 100 );
        ui->mSliderTranslationY->setRange( -100, 100 );
        ui->mSliderScale->setRange( 20, 500 );
    }
    
    void LPanelAffineTransforms::_setupSignals()
    {
        connect( ui->mSliderRotation, &QSlider::valueChanged, this, &LPanelAffineTransforms::slotOnRotation );
        connect( ui->mSliderTranslationX, &QSlider::valueChanged, this, &LPanelAffineTransforms::slotOnTranslationX );
        connect( ui->mSliderTranslationY, &QSlider::valueChanged, this, &LPanelAffineTransforms::slotOnTranslationY );
        connect( ui->mSliderScale, &QSlider::valueChanged, this, &LPanelAffineTransforms::slotOnScale );
    }

    // Slots
    
    // TODO: Correct leaks. It seems qimage destructor does not clean the image buffer

    void LPanelAffineTransforms::slotOnRotation( int angle )
    {
        assert( m_masterWindow != NULL );

        QImage _srcImage = m_masterWindow->requestRenderImage();
        QImage _dstImage = fRotationTransform( _srcImage, (float) angle );

        m_masterWindow->setRenderImage( _dstImage );
    }
    
    void LPanelAffineTransforms::slotOnTranslationX( int dx )
    {
        assert( m_masterWindow != NULL );

        QImage _srcImage = m_masterWindow->requestRenderImage();
        QImage _dstImage = fTranslationTransform( _srcImage, 
                                                  (float) dx,
                                                  ui->mSliderTranslationY->value() );

        m_masterWindow->setRenderImage( _dstImage );        
    }
    
    void LPanelAffineTransforms::slotOnTranslationY( int dy )
    {
        assert( m_masterWindow != NULL );

        QImage _srcImage = m_masterWindow->requestRenderImage();
        QImage _dstImage = fTranslationTransform( _srcImage, 
                                                  ui->mSliderTranslationX->value(),
                                                  (float) dy );

        m_masterWindow->setRenderImage( _dstImage );                
    }
    
    void LPanelAffineTransforms::slotOnScale( int scalePercent )
    {
        assert( m_masterWindow != NULL );

        float _scale = ( (float)scalePercent ) / 100.0f;
        // std::cout << "_scale" << _scale << std::endl;

        QImage _srcImage = m_masterWindow->requestRenderImage();
        QImage _dstImage = fScaleTransform( _srcImage, _scale );

        m_masterWindow->setRenderImage( _dstImage );                        
    }

    void LPanelAffineTransforms::setMasterWindow( LMainWindow* pMasterWindow )
    {
        m_masterWindow = pMasterWindow;
    }
    
}}
