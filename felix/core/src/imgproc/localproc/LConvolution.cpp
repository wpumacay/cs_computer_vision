

#include "../../../include/imgproc/localproc/LConvolution.h"

using namespace std;

namespace felix
{

    LConvKernel::LConvKernel()
    {
        m_buffer = NULL;
        m_rows = 0;
        m_cols = 0;
    }

    LConvKernel::LConvKernel( int cols, int rows )
    {
        m_buffer = new float[ cols * rows ];
        m_rows = rows;
        m_cols = cols;
    }

    LConvKernel::~LConvKernel()
    {
        delete m_buffer;
    }

    float LConvKernel::operator() ( int col, int row ) const
    {
        if ( col < 0 || col > m_cols - 1 )
        {
            cout << "LConvKernel> col out of range" << endl;
            return 0.0f;
        }

        if ( row < 0 || row > m_rows - 1 )
        {
            cout << "LConvKernel> row out of range" << endl;
            return 0.0f;
        }

        return m_buffer[ col + m_cols * row ];
    }

    void LConvKernel::set( int col, int row, float value )
    {
        if ( col < 0 || col > m_cols - 1 )
        {
            cout << "LConvKernel> col out of range" << endl;
            return;
        }

        if ( row < 0 || row > m_rows - 1 )
        {
            cout << "LConvKernel> row out of range" << endl;
            return;
        }

        m_buffer[ col + m_cols * row ] = value;
    }


    LConvKernel makeKernelAverage( int cols, int rows )
    {
        LConvKernel _kernel( cols, rows );

        float _size = cols * rows;

        for ( int i = 0; i < rows; i++ )
        {
            for ( int j = 0; j < cols; j++ )
            {
                _kernel.set( j, i, 1.0f / _size );
            }
        }

        return _kernel;
    }

    float _applyKernel( const core::LMatf& srcMat, int pCol, int pRow, int pChannel, const LConvKernel& kernel )
    {
        int _hw = kernel.halfCols();
        int _hh = kernel.halfRows();

        int _w = kernel.cols();
        int _h = kernel.rows();

        int _matCols = srcMat.cols();
        int _matRows = srcMat.rows();

        float _res = 0.0f;

        for ( int i = 0; i < _h; i++ )
        {
            for ( int j = 0; j < _w; j++ )
            {
                int x = max( min( pCol + j - _hw, _matCols - 1 ), 0 );
                int y = max( min( pRow + i - _hh, _matRows - 1 ), 0 );

                _res += kernel( j, i ) * srcMat.get( x, y, pChannel );
            }
        }

        return _res;
    }

    core::LMatf convolve( const core::LMatf& srcMat, const LConvKernel& kernel )
    {
        core::LMatf _dstMat( srcMat.rows(), srcMat.cols(), srcMat.channels() );

        int _w = _dstMat.cols();
        int _h = _dstMat.rows();
        int _c = _dstMat.channels();

        for ( int i = 0; i < _h; i++ )
        {
            for ( int j = 0; j < _w; j++ )
            {
                for ( int c = 0; c < _c; c++ )
                {
                    _dstMat( j, i, c, _applyKernel( srcMat, j, i, c, kernel ) );
                }
            }
        }

        return _dstMat;
    }

}