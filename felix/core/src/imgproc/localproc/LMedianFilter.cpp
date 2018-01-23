

#include "../../../include/imgproc/localproc/LMedianFilter.h"

using namespace std;

namespace felix
{

    float _getMedianPixel( const core::LMatf& srcMat, int pCol, int pRow, int c, int sizeW, int sizeH )
    {
        vector<float> _values;

        int _hw = ( sizeW - 1 ) / 2;
        int _hh = ( sizeH - 1 ) / 2;

        int _w = sizeW;
        int _h = sizeH;

        int _matCols = srcMat.cols();
        int _matRows = srcMat.rows();

        for ( int i = 0; i < _h; i++ )
        {
            for ( int j = 0; j < _w; j++ )
            {
                int x = max( min( pCol + j - _hw, _matCols - 1 ), 0 );
                int y = max( min( pRow + i - _hh, _matRows - 1 ), 0 );

                _values.push_back( srcMat.get( x, y, c ) );
            }
        }

        sort( _values.begin(), _values.end() );

        float _res = _values[ ( _values.size() - 1 ) / 2 ];

        return _res;

    }

    core::LMatf medianFilter( const core::LMatf& srcMat, int sizeW, int sizeH )
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
                    _dstMat( j, i, c, _getMedianPixel( srcMat, j, i, c, sizeW, sizeH ) );
                }
            }
        }

        return _dstMat;
    }

}