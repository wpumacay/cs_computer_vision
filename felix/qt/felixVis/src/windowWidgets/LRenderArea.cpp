
#include <QPainter>
#include <windowWidgets/LRenderArea.h>

#include <iostream>

namespace felix {
namespace qt {


    LRenderArea::LRenderArea( QWidget* parent ) :
        QWidget( parent )
    {
        m_workingImage = NULL;
        m_showImage = NULL;
    }

    LRenderArea::~LRenderArea()
    {
        if ( m_workingImage != NULL )
        {
            delete m_workingImage;
            m_workingImage = NULL;
        }

        if ( m_showImage != NULL )
        {
            delete m_showImage;
            m_showImage = NULL;
        }
    }

    void LRenderArea::paintEvent( QPaintEvent* pEvent )
    {
        QPainter _painter( this );

        // std::cout << "painting" << std::endl;

        if ( m_showImage != NULL )
        {
            // std::cout << "painting image" << std::endl;

            int _iWidth  = m_showImage->width();
            int _iHeight = m_showImage->height();

            int _rAreaWidth  = width();
            int _rAreaHeight = height();

            int _renderImageX = ( _rAreaWidth - _iWidth ) / 2;
            int _renderImageY = ( _rAreaHeight - _iHeight ) / 2;

            _painter.drawImage( QPoint( _renderImageX, _renderImageY ),
                                *m_showImage );
        }
    }

    void LRenderArea::resetWithImage( QImage pImage )
    {
        if ( m_workingImage != NULL )
        {
            delete m_workingImage;
        }

        if ( m_showImage != NULL )
        {
            delete m_showImage;
        }

        m_showImage = new QImage( pImage.copy() );
        m_workingImage = new QImage( pImage.copy() );
    }

    void LRenderArea::setCurrentImage( QImage pImage )
    {
        // Keep a deep copy of the given image

        if ( !pImage.isNull() )
        {

            m_showImage = new QImage( pImage.copy() );
            if ( m_workingImage == NULL )
            {
                m_workingImage = new QImage( pImage.copy() );
            }

            // Recalculate renderarea size
            int _width  = m_workingImage->width();
            int _height = m_workingImage->height();

            int _minRenderAreaWidth  = _width + 2 * MARGIN_WIDTH;
            int _minRenderAreaHeight = _height + 2 * MARGIN_HEIGHT;

            this->setMinimumSize( _minRenderAreaWidth, _minRenderAreaHeight );

            this->update();
        }
    }

    QImage LRenderArea::getCurrentImage()
    {
        if ( m_workingImage == NULL )
        {
            return QImage();
        }

        return m_workingImage->copy();
    }

    QImage LRenderArea::getShowingImage()
    {
        if ( m_showImage == NULL )
        {
            return QImage();
        }

        return m_showImage->copy();
    }

}}
