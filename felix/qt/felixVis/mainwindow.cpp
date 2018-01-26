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

        QImage _image( "../../res/lena.jpeg" );

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

        delete ui;
    }
    
    void LMainWindow::_setupActions()
    {
        connect( ui->qActionOpen, &QAction::triggered, this, &LMainWindow::slotOpen );
        connect( ui->qActionSave, &QAction::triggered, this, &LMainWindow::slotSave );
        connect( ui->qActionQuit, &QAction::triggered, this, &LMainWindow::slotQuit );

        connect( ui->qActionAffine, &QAction::triggered, this, &LMainWindow::slotAffine );
        connect( ui->qActionConvolution, &QAction::triggered, this, &LMainWindow::slotConvolution );

    }

    QImage LMainWindow::requestRenderImage()
    {
        assert( m_renderArea != NULL );
        
        return m_renderArea->getCurrentImage();
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



}}
