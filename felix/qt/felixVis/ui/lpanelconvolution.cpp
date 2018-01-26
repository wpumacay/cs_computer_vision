
#include "lpanelconvolution.h"
#include "ui_lpanelconvolution.h"

#include <iostream>
#include <cassert>

namespace felix {
namespace qt {


    LPanelConvolution::LPanelConvolution( QWidget *parent ) :
        QDialog( parent ),
        ui( new Ui::LPanelConvolution )
    {
        ui->setupUi( this );

        m_kernelView = new LKernelWidget();
        auto _cbKernelTypes = new QComboBox();
        _cbKernelTypes->addItem( "Mean kernel" );
        _cbKernelTypes->addItem( "Gaussian kernel" );
        _cbKernelTypes->addItem( "Sobel kernel" );
        auto _btnCalculate = new QPushButton( "Apply kernel" );

        ui->mLayoutContainer->addWidget( m_kernelView );
        ui->mLayoutContainer->addWidget( _cbKernelTypes );
        ui->mLayoutContainer->addWidget( _btnCalculate );

        connect( _btnCalculate, &QPushButton::clicked, this, &LPanelConvolution::slotApplyKernel );
        connect( _cbKernelTypes, static_cast< void ( QComboBox::* )( int )>( &QComboBox::currentIndexChanged ), this, &LPanelConvolution::slotKernelType );

        m_masterWindow = NULL;

        this->show();
    }


    LPanelConvolution::~LPanelConvolution()
    {
        delete ui;
    }

    void LPanelConvolution::setMasterWindow( LMainWindow* pMasterWindow )
    {
        m_masterWindow = pMasterWindow;
    }

    void LPanelConvolution::slotApplyKernel()
    {
        std::cout << "applying kernel" << std::endl;

        assert( m_masterWindow != NULL );

        auto _kernel = m_kernelView->getKernel();

        // std::cout << "_scale" << _scale << std::endl;

        QImage _srcImage = m_masterWindow->requestRenderImage();
        QImage _dstImage = fConvolution( _srcImage, _kernel );

        m_masterWindow->setRenderImage( _dstImage );
    }

    void LPanelConvolution::slotKernelType( int indx )
    {
        m_kernelView->makeKernelByType( indx );
    }

}}

