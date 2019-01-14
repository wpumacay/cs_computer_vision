
#pragma once

#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QSize>

#define MARGIN_WIDTH 20
#define MARGIN_HEIGHT 20

namespace felix  {
namespace qt {

    class LRenderArea : public QWidget
    {
        // Q_OBJECT

        public:

        LRenderArea( QWidget* parent = 0 );
        ~LRenderArea();

        void resetWithImage( QImage pImage );
        void setCurrentImage( QImage pImage );
        QImage getCurrentImage();
        QImage getShowingImage();

        protected :

        void paintEvent( QPaintEvent* pEvent ) override;

        // void resizeEvent( QResizeEvent* pEvent ) override;

        private:

        // The QImage is back buffered. Work only on ...
        // the m_currentInage and show only on the m_showImage
        QImage* m_workingImage;// work on this, buf just copy it
        QImage* m_showImage;
    };

} }

