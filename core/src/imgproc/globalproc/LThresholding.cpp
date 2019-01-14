
#include "../../../include/imgproc/globalproc/LThresholding.h"

#include <cmath>



namespace felix
{


    LBinKernel::LBinKernel()
    {
        m_buffer = NULL;
        m_rows = 0;
        m_cols = 0;
    }

    LBinKernel::LBinKernel( int cols, int rows )
    {
        m_buffer = new u8[ cols * rows ];
        m_rows = rows;
        m_cols = cols;
    }

    LBinKernel::LBinKernel( const LBinKernel& other )
    {
        m_buffer = new u8[ other.m_cols * other.m_rows ];
        m_rows = other.m_rows;
        m_cols = other.m_cols;

        memcpy( m_buffer, other.m_buffer, sizeof( u8 ) * m_rows * m_cols );
    }

    void LBinKernel::operator= ( const LBinKernel& other )
    {
        if ( m_buffer != NULL )
        {
            delete m_buffer;
        }

        m_buffer = new u8[ other.m_cols * other.m_rows ];
        m_rows = other.m_rows;
        m_cols = other.m_cols;

        memcpy( m_buffer, other.m_buffer, sizeof( u8 ) * m_rows * m_cols );
    }

    LBinKernel::~LBinKernel()
    {
        if ( m_buffer == NULL )
        {
            return;
        }

        delete[] m_buffer;
        m_buffer = NULL;
    }

    u8 LBinKernel::operator() ( int col, int row ) const
    {
        if ( col < 0 || col > m_cols - 1 )
        {
            cout << "LBinKernel> col out of range" << endl;
            return 0.0f;
        }

        if ( row < 0 || row > m_rows - 1 )
        {
            cout << "LBinKernel> row out of range" << endl;
            return 0.0f;
        }

        return m_buffer[ col + m_cols * row ];
    }

    void LBinKernel::set( int col, int row, u8 value )
    {
        if ( col < 0 || col > m_cols - 1 )
        {
            cout << "LBinKernel> col out of range" << endl;
            return;
        }

        if ( row < 0 || row > m_rows - 1 )
        {
            cout << "LBinKernel> row out of range" << endl;
            return;
        }

        m_buffer[ col + m_cols * row ] = value;
    }

    void LBinKernel::print()
    {
        std::cout << "[ ";

        for ( int p = 0; p < m_rows; p++ )
        {
            std::cout << "[ ";

            for ( int q = 0; q < m_cols; q++ )
            {
                std::cout << (int) m_buffer[ q + p * m_cols ];

                if ( q != m_cols - 1 )
                {
                    std::cout  << ", ";
                }
            }

            std::cout << "]";

            if ( p != m_rows - 1 )
            {
                std::cout << "," << std::endl << "  ";
            }
        }

        std::cout << "]" << std::endl;
    }




    core::LMatu threshRange( const core::LMatu& mat, u8 vMin, u8 vMax, int channel )
    {
        int _rows = mat.rows();
        int _cols = mat.cols();

        core::LMatu _res( mat.rows(), mat.cols(), 1 );

        for ( int x = 0; x < _cols; x++ )
        {
            for ( int y = 0; y < _rows; y++ )
            {
                u8 _pixVal = mat.get( x, y, channel );
                u8 _resVal = ( vMin < _pixVal && _pixVal < vMax ) ? 255 : 0;

                _res.set( x, y, 0, _resVal );
            }
        }

        return _res;
    }

    LBinKernel makeBinKernel( int size, binKernelType::_binKernelType kType )
    {
        LBinKernel _res( size, size );

        int _hcols = _res.halfCols();
        int _hrows = _res.halfRows();

        for ( int x = -_hcols; x <= _hcols; x++ )
        {
            for ( int y = -_hrows; y <= _hrows; y++ )
            {
                switch ( kType )
                {
                    case binKernelType::DIAMOND :
                        _res.set( x + _hcols, y + _hrows, ( ABS( x ) + ABS( y ) < 1 ) ? 1 : 0 );
                    break;

                    case binKernelType::SQUARE :
                        _res.set( x + _hcols, y + _hrows, 1 );
                    break;
                }
            }
        }


        return _res;
    }

    core::LMatu dilate( const core::LMatu& bwMat, const LBinKernel& kernel )
    {
        core::LMatu _res( bwMat );

        int _width  = bwMat.cols();
        int _height = bwMat.rows();

        for ( int x = 0; x < _width; x++ )
        {
            for ( int y = 0; y < _height; y++ )
            {
                _res.set( x, y, 0, _dilateAt( x, y, bwMat, kernel ) );
            }
        }

        return _res;
    }

    core::LMatu erode( const core::LMatu& bwMat, const LBinKernel& kernel )
    {
        core::LMatu _res( bwMat );

        int _width  = bwMat.cols();
        int _height = bwMat.rows();

        for ( int x = 0; x < _width; x++ )
        {
            for ( int y = 0; y < _height; y++ )
            {
                _res.set( x, y, 0, _erodeAt( x, y, bwMat, kernel ) );
            }
        }

        return _res;
    }

    u8 _dilateAt( int x, int y, const core::LMatu& bwMat, const LBinKernel& kernel )
    {
        u8 _res = 0;

        int _mHalfcols = kernel.halfCols();
        int _mHalfrows = kernel.halfRows();

        int _matCols = bwMat.cols();
        int _matRows = bwMat.rows();

        for ( int xm = -_mHalfcols; xm <= _mHalfcols; xm++ )
        {
            for ( int ym = -_mHalfrows; ym <= _mHalfrows; ym++ )
            {
                if ( ( x + xm ) < 0 || ( x + xm ) > _matCols - 1 )
                {
                    continue;
                }

                if ( ( y + ym ) < 0 || ( y + ym ) > _matRows - 1 )
                {
                    continue;
                }                

                if ( kernel( xm + _mHalfcols, ym + _mHalfrows ) == 1 && bwMat.get( x + xm, y + ym, 0 ) == 255 )
                {
                    // hit
                    return 255;
                }
            }
        }

        return _res;
    }

    u8 _erodeAt( int x, int y, const core::LMatu& bwMat, const LBinKernel& kernel )
    {
        u8 _res = 255;

        int _mHalfcols = kernel.halfCols();
        int _mHalfrows = kernel.halfRows();

        int _matCols = bwMat.cols();
        int _matRows = bwMat.rows();

        for ( int xm = -_mHalfcols; xm <= _mHalfcols; xm++ )
        {
            for ( int ym = -_mHalfrows; ym <= _mHalfrows; ym++ )
            {
                if ( ( x + xm ) < 0 || ( x + xm ) > _matCols - 1 )
                {
                    continue;
                }

                if ( ( y + ym ) < 0 || ( y + ym ) > _matRows - 1 )
                {
                    continue;
                }                

                if ( kernel( xm + _mHalfcols, ym + _mHalfrows ) == 1 && bwMat.get( x + xm, y + ym, 0 ) == 0 )
                {
                    // miss
                    return 0;
                }
            }
        }

        return _res;
    }


}