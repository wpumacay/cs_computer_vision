#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <cassert>


#include <qtUtils/LQtUtils.h>
#include <utils/LUtils.h>
#include <visualizer/LVisualizerManager.h>

#include <iostream>

namespace felix {
namespace qt {



    LMainWindow::LMainWindow( QWidget *parent ) :
        QMainWindow( parent ),
        ui( new Ui::MainWindow )
    {
        ui->setupUi( this );

        m_renderArea = new LRenderArea();

        QImage _image( "../../res/leo.jpg" );

        setCentralWidget( m_renderArea );

        // test utils, sanity check

        auto _mat = qImage2mat( _image );
        // auto _mat = core::LMatf::testImg();
        auto _newImg = mat2qImage( _mat );
        // core::LMatu _matu = utils::toMatu( _mat );

        // felix::core::LVisualizerManager::create();

        // felix::core::LVisualizerManager::instance->makeWindow( "sample original" );
        // felix::core::LVisualizerManager::instance->showMat( "sample original",
        //                                                     _matu );

        // felix::core::LVisualizerManager::instance->show();

        //m_renderArea->setCurrentImage( _image );
        m_renderArea->resetWithImage( _newImg );
        m_renderArea->update();

        _setupActions();

        m_panelAffineTransforms = NULL;
        m_panelConvolution = NULL;
        m_panelHistogramEqualization = NULL;
        m_panelMedianFilter = NULL;
        m_panelFourierTransform = NULL;
    }

    LMainWindow::~LMainWindow()
    {
        if ( m_panelAffineTransforms != NULL )
        {
            delete m_panelAffineTransforms;
            m_panelAffineTransforms = NULL;
        }

        if ( m_panelConvolution != NULL )
        {
            delete m_panelConvolution;
            m_panelConvolution = NULL;
        }

        if ( m_panelHistogramEqualization != NULL )
        {
            delete m_panelHistogramEqualization;
            m_panelHistogramEqualization = NULL;
        }

        if ( m_panelMedianFilter != NULL )
        {
            delete m_panelMedianFilter;
            m_panelMedianFilter = NULL;
        }

        if ( m_panelFourierTransform != NULL )
        {
            delete m_panelFourierTransform;
            m_panelFourierTransform = NULL;
        }

        delete ui;
    }
    
    void LMainWindow::_setupActions()
    {
        connect( ui->qActionOpen, &QAction::triggered, this, &LMainWindow::slotOpen );
        connect( ui->qActionSave, &QAction::triggered, this, &LMainWindow::slotSave );
        connect( ui->qActionQuit, &QAction::triggered, this, &LMainWindow::slotQuit );

        connect( ui->qActionAffine, &QAction::triggered, this, &LMainWindow::slotAffine );
        connect( ui->qActionConvolution, &QAction::triggered, this, &LMainWindow::slotConvolution );
        connect( ui->qActionHistEqualization, &QAction::triggered, this, &LMainWindow::slotHistEqualization );
        connect( ui->qActionMedianFilter, &QAction::triggered, this, &LMainWindow::slotMedianFilter );
        connect( ui->qActionFourier, &QAction::triggered, this, &LMainWindow::slotFourierTransform );
    }

    QImage LMainWindow::requestRenderImage( bool requestedWorkingImage )
    {
        assert( m_renderArea != NULL );

        if ( requestedWorkingImage )
        {
            return m_renderArea->getCurrentImage();
        }

        return m_renderArea->getShowingImage();
    }
    
    void LMainWindow::setRenderImage( QImage image )
    {
        assert( m_renderArea != NULL );
        
        m_renderArea->setCurrentImage( image.copy() );
    }
    
    void LMainWindow::slotOpen()
    {
        std::cout << "LMainWindow::slotOpen> opening file" << std::endl;

        // TODO: Fix felix engine to support operations in png files
        QString _filename = QFileDialog::getOpenFileName( NULL, tr( "Open image" ), "./", tr( "Images (*.jpg *.jpeg)" ) );
        std::cout << "file to open: " << _filename.toStdString() << std::endl;
        
        m_renderArea->resetWithImage( QImage( _filename ) );
        m_renderArea->update();

        if ( m_panelHistogramEqualization != NULL )
        {
            m_panelHistogramEqualization->showHistogram();
        }
    }

    void LMainWindow::slotSave()
    {
        std::cout << "LMainWindow::slotSave> saving file" << std::endl;
    }

    void LMainWindow::slotQuit()
    {
        std::cout << "LMainWindow::slotQuit> quitting application" << std::endl;

        exit( 0 );
    }

    void LMainWindow::slotAffine()
    {
        if ( m_panelAffineTransforms != NULL )
        {
            m_panelAffineTransforms->show();
            return;
        }

        m_panelAffineTransforms = new LPanelAffineTransforms();
        m_panelAffineTransforms->setMasterWindow( this );
    }

    void LMainWindow::slotConvolution()
    {
        if ( m_panelConvolution != NULL )
        {
            m_panelConvolution->show();
            return;
        }

        m_panelConvolution = new LPanelConvolution( NULL );
        m_panelConvolution->setMasterWindow( this );
    }

    void LMainWindow::slotHistEqualization()
    {
        if ( m_panelHistogramEqualization != NULL )        
        {
            m_panelHistogramEqualization->show();
            return;
        }

        m_panelHistogramEqualization = new LPanelHistogramEqualization();
        m_panelHistogramEqualization->setMasterWindow( this );
    }


    void LMainWindow::slotMedianFilter()
    {
        if ( m_panelMedianFilter != NULL )        
        {
            m_panelMedianFilter->show();
            return;
        }

        m_panelMedianFilter = new LPanelMedianFilter();
        m_panelMedianFilter->setMasterWindow( this );
    }

    void LMainWindow::slotFourierTransform()
    {
        if ( m_panelFourierTransform != NULL )
        {
            m_panelFourierTransform->show();
            return;
        }

        m_panelFourierTransform = new LPanelFourierTransform();
        m_panelFourierTransform->setMasterWindow( this );
    }

}}
