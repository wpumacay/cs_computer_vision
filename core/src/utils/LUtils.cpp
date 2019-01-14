

#include "../../core/include/utils/LUtils.h"

using namespace felix::core;

namespace felix
{

    namespace utils
    {


        LMatf toMatf( const LMatu& img )
        {
            LMatf _res( img.rows(), img.cols(), img.channels() );

            u8* _imgBuff = img.buffer();
            float* _resBuff = _res.buffer();

            int _nPixels = img.size();
            int _channels = img.channels();

            for ( int q = 0; q < _nPixels; q++ )
            {
                _resBuff[_channels * q + 0] = _imgBuff[_channels * q + 0] / 255.0f;
                _resBuff[_channels * q + 1] = _imgBuff[_channels * q + 1] / 255.0f;
                _resBuff[_channels * q + 2] = _imgBuff[_channels * q + 2] / 255.0f;
            }

            return _res;
        }

        LMatu toMatu( const LMatf& img )
        {
            LMatu _res( img.rows(), img.cols(), img.channels() );

            float* _imgBuff = img.buffer();
            u8* _resBuff = _res.buffer();

            int _nPixels = img.size();
            int _channels = img.channels();

            for ( int q = 0; q < _nPixels; q++ )
            {
                _resBuff[_channels * q + 0] = floor( _imgBuff[_channels * q + 0] * 255.0f );
                _resBuff[_channels * q + 1] = floor( _imgBuff[_channels * q + 1] * 255.0f );
                _resBuff[_channels * q + 2] = floor( _imgBuff[_channels * q + 2] * 255.0f );
            }

            return _res;
        }

        void addMats( LMatf& dst, const LMatf& other )
        {
            if ( dst.cols() != other.cols() ||
                 dst.rows() != other.rows() ||
                 dst.channels() != other.channels() )
            {
                cout << "addMats> dimensions mismatch" << endl;
                return;
            }

            float* _dstBuff = dst.buffer();
            float* _oBuff = other.buffer();

            int _w = dst.cols();
            int _h = dst.rows();
            int _c = dst.channels();

            for ( int i = 0; i < _h; i++ )
            {
                for ( int j = 0; j < _w; j++ )
                {
                    for ( int _ch = 0; _ch < _c; _ch++ )
                    {
                        int _p = j + i * _w;

                        _dstBuff[ _c * _p + _ch ] += _oBuff[ _c * _p + _ch ];
                        _dstBuff[ _c * _p + _ch ] = max( min( _dstBuff[ _c * _p + _ch ], 1.0f ), 0.0f );
                    }
                }
            }
        }

        void addNoiseSaltPepper( LMatf& lmat, float percent )
        {
            int _nPixels = lmat.size();

            float* _buff = lmat.buffer();

            for ( int q = 0; q < _nPixels; q++ )
            {
                if ( RANDOM() < percent )
                {
                    if ( RANDOM() < 0.5 )
                    {
                        for ( int _ch = 0; _ch < lmat.channels(); _ch++ )
                        {
                            _buff[ lmat.channels() * q + _ch ] = 1.0f;
                        }
                    }
                    else
                    {
                        for ( int _ch = 0; _ch < lmat.channels(); _ch++ )
                        {
                            _buff[ lmat.channels() * q + _ch ] = 0.0f;
                        }
                    }
                }
            }
        }

    }






}