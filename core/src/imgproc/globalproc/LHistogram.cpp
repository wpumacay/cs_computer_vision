

#include "../../../include/imgproc/globalproc/LHistogram.h"

using namespace std;

namespace felix
{

    // Histogram helper struct ***************************
    LHist::LHist()
    {
        memset( h, 0, sizeof( u32 ) * HISTOGRAM_BIN_SIZE );
    }

    u32 LHist::cumsum( int i ) const
    {
        u32 _res = 0;

        for ( int q = 0; q < i; q++ )
        {
            _res += h[q];
        }

        return _res;
    }

    string LHist::toString() const
    {
        string _res = "{ ";

        for ( int q = 0; q < HISTOGRAM_BIN_SIZE; q++ )
        {
            _res += to_string( h[q] ); _res += " ";
        }

        _res += "}";

        return _res;
    }

    // Histogram Transformation helper struct ************
    LHistTransform::LHistTransform()
    {
        for ( int q = 0; q < HISTOGRAM_BIN_SIZE; q++ )
        {
            f[q] = 0.0f;
        }
    }

    LHistTransform::LHistTransform( const LHist& cumHist )
    {
        u32 _sum = cumHist.h[HISTOGRAM_BIN_SIZE - 1];

        for ( int q = 0; q < HISTOGRAM_BIN_SIZE; q++ )
        {
            f[q] = ( float ) cumHist.h[q] / _sum;
        }
    }

    string LHistTransform::toString() const
    {
        string _res = "{ ";

        for ( int q = 0; q < HISTOGRAM_BIN_SIZE; q++ )
        {
            _res += to_string( f[q] ); _res += " ";
        }

        _res += "}";

        return _res;
    }

    // Histogram helper methods **************************

    LHist LHistogram::_computeHistogram( const core::LMatu& lmat, int channel )
    {
        LHist _hist;

        if ( channel > lmat.channels() - 1 )
        {
            cout << "LHistogram::_computeHistogram> requested out of range channel" << endl;
            return _hist;
        }

        // if ( lmat.channels() > 1 )
        // {
        //     cout << "LHistogram::_computeHistogram> only single channel images supported" << endl;
        //     return _hist;
        // }

        for ( int i = 0; i < lmat.rows(); i++ )
        {
            for ( int j = 0; j < lmat.cols(); j++ )
            {
                _hist.h[lmat.get( j, i, channel )] += 1;
            }
        }

        return _hist;
    }

    LHistTransform LHistogram::_computeHistTransform( const LHist& hist, int channel )
    {
        LHist _cumHist;

        // TODO: Can save some calculations by using the fixed size of the image as maxCount ...
        // for the normalizer
        for ( int q = 0; q < 255; q++ )
        {
            _cumHist.h[q] = hist.cumsum( q );
        }

        LHistTransform _transform( _cumHist );

        return _transform;
    }

    core::LMatu LHistogram::equalize( const core::LMatu& lmat )
    {
        LHist _totalHist;

        for ( int q = 0; q < lmat.channels(); q++ )
        {
            if ( q == 3 )
            {
                // Dont compute for alpha channel
                continue;
            }

            LHist _hist = LHistogram::_computeHistogram( lmat, q );
            
            for ( int b = 0; b < HISTOGRAM_BIN_SIZE; b++ )
            {
                _totalHist.h[b] += _hist.h[b];
            }

        }

        for ( int b = 0; b < HISTOGRAM_BIN_SIZE; b++ )
        {
            _totalHist.h[b] = _totalHist.h[b] / 3;
        }

        //LHist _hist = LHistogram::_computeHistogram( lmat );
        LHistTransform _transform = LHistogram::_computeHistTransform( _totalHist );

        core::LMatu _res( lmat.rows(), lmat.cols(), lmat.channels() );

        int _nPixels = _res.size();
        int _channels = lmat.channels();

        u8* _srcBuffer = lmat.buffer();
        u8* _dstBuffer = _res.buffer();

        for ( int q = 0; q < _nPixels; q++ )
        {
            for ( int c = 0; c < lmat.channels(); c++ )
            {
                u8 _srcPixValue = _srcBuffer[_channels * q + c];
                _dstBuffer[_channels * q + c] = floor( _transform.f[_srcPixValue] * 255 );
            }
        }

        return _res;
    }

}