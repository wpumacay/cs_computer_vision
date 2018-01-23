
#include "lpanelaffinetransforms.h"
#include "ui_lpanelaffinetransforms.h"

#include <qtWrappers/LWrapperAffineTransforms.h>

#include <iostream>

namespace felix {
namespace qt {


    LPanelAffineTransforms::LPanelAffineTransforms( LMainWindow* parent ) :
        QDialog(parent),
        ui( new Ui::LPanelAffineTransforms )
    {
        ui->setupUi( this );
        
        _setupRanges();
        _setupSignals();
        
        show();
        
        // std::cout << "created affine transforms panel" << std::endl;
    }

    LPanelAffineTransforms::~LPanelAffineTransforms()
    {
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
        auto _masterWindow = reinterpret_cast<LMainWindow*>( this->parentWidget() );
        
        QImage _srcImage = _masterWindow->requestRenderImage();
        QImage _dstImage = fRotationTransform( _srcImage, (float) angle );

        _masterWindow->setRenderImage( _dstImage );
    }
    
    void LPanelAffineTransforms::slotOnTranslationX( int dx )
    {
        auto _masterWindow = reinterpret_cast<LMainWindow*>( this->parentWidget() );
        
        QImage _srcImage = _masterWindow->requestRenderImage();
        QImage _dstImage = fTranslationTransform( _srcImage, 
                                                  (float) dx,
                                                  ui->mSliderTranslationY->value() );

        _masterWindow->setRenderImage( _dstImage );        
    }
    
    void LPanelAffineTransforms::slotOnTranslationY( int dy )
    {
        auto _masterWindow = reinterpret_cast<LMainWindow*>( this->parentWidget() );
        
        QImage _srcImage = _masterWindow->requestRenderImage();
        QImage _dstImage = fTranslationTransform( _srcImage, 
                                                  ui->mSliderTranslationX->value(),
                                                  (float) dy );

        _masterWindow->setRenderImage( _dstImage );                
    }
    
    void LPanelAffineTransforms::slotOnScale( int scalePercent )
    {
        auto _masterWindow = reinterpret_cast<LMainWindow*>( this->parentWidget() );
        
        float _scale = ( (float)scalePercent ) / 100.0f;
        std::cout << "_scale" << _scale << std::endl;

        QImage _srcImage = _masterWindow->requestRenderImage();
        QImage _dstImage = fScaleTransform( _srcImage, _scale );

        _masterWindow->setRenderImage( _dstImage );                        
    }
    
}}
