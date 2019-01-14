
#include <windowWidgets/LKernelWidget.h>

#include <iostream>

namespace felix {
namespace qt {


    LKernelWidget::LKernelWidget( QWidget* parent ) :
        QGroupBox( parent )
    {
        setTitle( "Kernel Edition" );

        m_vLayout = new QVBoxLayout();
        m_hLayout = new QHBoxLayout();
        m_vFractionLayout = new QVBoxLayout();

        m_twMatrix = new QTableWidget();

        m_inDenominator = new QDoubleSpinBox();
        m_inDenominator->setRange( -1000000, 1000000 );
        m_inDenominator->setValue( 1 );

        auto _lblNumerator = new QLabel( "1" );
        _lblNumerator->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::Fixed );
        _lblNumerator->setAlignment( Qt::AlignHCenter );

        auto _lblLine = new QLabel( "____" );
        _lblLine->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::Fixed );
        _lblLine->setAlignment( Qt::AlignHCenter );

        m_vFractionLayout->addWidget( _lblNumerator );
        m_vFractionLayout->addWidget( _lblLine );
        m_vFractionLayout->addWidget( m_inDenominator );

        m_hLayout->addLayout( m_vFractionLayout );
        m_hLayout->addWidget( m_twMatrix );

        m_lblKernelSize = new QLabel( "Kernel size" );
        m_sbKernelSize  = new QSpinBox();

        m_vLayout->addLayout( m_hLayout );
        m_vLayout->addWidget( m_lblKernelSize );
        m_vLayout->addWidget( m_sbKernelSize );

        this->setLayout( m_vLayout );

        _init();

        this->show();
    }

    LKernelWidget::~LKernelWidget()
    {
        // TODO: Check if the widgets added as children to layouts ...
        // are actually erased. If not, modified this destructor to clean stuff

        // std::cout << "destroying the kernel panel" << std::endl;

        m_sbKernelSize = NULL;
        m_lblKernelSize = NULL;
        m_twMatrix = NULL;
        m_vLayout = NULL;
    }

    void LKernelWidget::_init()
    {
        // initialize default sizes, signal-slot connections and more

        m_kernelSize = MIN_KERNEL_SIZE;

        m_inDenominator->setValue( ( 2 * m_kernelSize + 1 ) * ( 2 * m_kernelSize + 1 ) );

        m_sbKernelSize->setRange( MIN_KERNEL_SIZE, MAX_KERNEL_SIZE );
        m_sbKernelSize->setValue( m_kernelSize );

        m_twMatrix->setColumnCount( 2 * m_kernelSize + 1 );
        m_twMatrix->setRowCount( 2 * m_kernelSize + 1 );

        for ( int i = 0; i < 2 * m_kernelSize + 1; i++ )
        {
            for ( int j = 0; j < 2 * m_kernelSize + 1; j++ )
            {
                auto _item = new QTableWidgetItem( tr( "1" ) );
                _item->setData( Qt::DisplayRole, 1.0f );

                m_twMatrix->setItem( i, j, _item );
            }
        }

        m_twMatrix->resizeColumnsToContents();
        m_twMatrix->resizeRowsToContents();

        connect( m_twMatrix, &QTableWidget::cellChanged, this, &LKernelWidget::onElementChanged );
        connect( m_sbKernelSize, static_cast< void ( QSpinBox::* )( int ) >( &QSpinBox::valueChanged ), 
                 this, &LKernelWidget::onDimensionsChanged );
    }


    void LKernelWidget::onDimensionsChanged( int newKernelSize )
    {
        int _oldKernelSize = m_kernelSize;
        m_kernelSize = newKernelSize;

        m_inDenominator->setValue( ( 2 * m_kernelSize + 1 ) * ( 2 * m_kernelSize + 1 ) );

        m_twMatrix->setColumnCount( 2 * m_kernelSize + 1 );
        m_twMatrix->setRowCount( 2 * m_kernelSize + 1 );

        if ( newKernelSize > _oldKernelSize  )
        {
            // std::cout << "new size: " << newKernelSize << std::endl;
            // std::cout << "old size: " << _oldKernelSize << std::endl;

            for ( int i = 0; i < 2 * newKernelSize + 1; i++ )
            {
                for ( int j = 0; j < 2 * newKernelSize + 1; j++ )
                {
                    if ( 2 * _oldKernelSize + 1 <= i && i < 2 * newKernelSize + 1 ||
                         2 * _oldKernelSize + 1 <= j && j < 2 * newKernelSize + 1 )
                    {
                        // std::cout << "i, j: " << i << " - " << j << std::endl;
                        auto _item = new QTableWidgetItem( tr( "1" ) );
                        _item->setData( Qt::DisplayRole, 1.0f );
                        
                        m_twMatrix->setItem( i, j, _item );
                    }
                }
            }
        }

        m_twMatrix->resizeColumnsToContents();
        m_twMatrix->resizeRowsToContents();
    }

    void LKernelWidget::onElementChanged( int row, int col )
    {
        // auto _item = m_twMatrix->item( row, col );
        // std::cout << "f: " << _item->text().toStdString() << std::endl;
        // std::cout << "fv: " << _item->data( Qt::DisplayRole ).toFloat() << std::endl;

        // _item->setData( _item->text().toFloat() );

        m_twMatrix->resizeColumnsToContents();
        m_twMatrix->resizeRowsToContents();
    }

    LConvKernel LKernelWidget::getKernel()
    {
        LConvKernel _res( 2 * m_kernelSize + 1, 2 * m_kernelSize + 1 );

        for ( int i = 0; i < 2 * m_kernelSize + 1; i++ )
        {
            for ( int j = 0; j < 2 * m_kernelSize + 1; j++ )
            {
                auto _item = m_twMatrix->item( i, j );
                float _value = _item->data( Qt::DisplayRole ).toFloat();
                _value = _value / m_inDenominator->value();
                _res.set( j, i, _value );
            }
        }

        _res.print();

        // sanity check
        // _res = makeKernelAverage( 2 * m_kernelSize + 1, 2 * m_kernelSize + 1 );

        return _res;
        // return makeKernelAverage( 15, 15 );

        // auto _res = makeKernelAverage( 5, 5 );

        // _res.print();

        // return _res;
    }

    void LKernelWidget::makeKernelByType( int type )
    {
        for ( int i = 0; i < 2 * m_kernelSize + 1; i++ )
        {
            for ( int j = 0; j < 2 * m_kernelSize + 1; j++ )
            {
                
                float _val = _getKernelValue( i, j, type );
                // std::cout << "val: " << _val << std::endl;
                auto _item = new QTableWidgetItem( QString::number( _val ) );
                _item->setData( Qt::DisplayRole, _val );
                    
                m_twMatrix->setItem( i, j, _item );
            }
        }
    }

    float LKernelWidget::_getKernelValue( int row, int col, int type )
    {
        float _val = 0.0f;

        if ( type == 0 )
        {
            // mean kernel
            _val = 1.0f;
        }
        else if ( type == 1 )
        {
            // gaussian kernel - naive way
            // element at "row" pos in pascal row
            float _rval = 1.0f;
            if ( row == 0 || row == 2 * m_kernelSize )
            {
                _rval = 1.0f;
            }
            else
            {
                for ( int q = 0; q < row; q++ )
                {
                    _rval *= ( 2.0f * m_kernelSize - q ) / ( q + 1.0f );
                }
            }

            float _cval = 1.0f;
            if ( col == 0 || col == 2 * m_kernelSize )
            {
                _cval = 1.0f;
            }
            else
            {
                for ( int q = 0; q < col; q++ )
                {
                    _cval *= ( 2.0f * m_kernelSize - q ) / ( q + 1.0f );
                }
            }

            _val = _rval * _cval;
        }
        else if ( type == 2 )
        {
            int i = row - m_kernelSize;
            int j = col - m_kernelSize;

            if ( i == 0 && j == 0 )
            {
                _val = 0.0f;
            }
            else
            {
                _val = ( ( float ) i ) / ( i * i + j * j );
            }
                
        }

        return _val;
    }

    std::vector<float> LKernelWidget::_getPascalRow( int n )
    {
        std::vector<float> _row;

        _row.push_back( 1.0f );

        for ( int q = 0; q < n; q++ )
        {
            _row.push_back( ( _row[ q ] * ( n - q ) ) / ( q + 1 ) );
        }

        return _row;
    }

}}
