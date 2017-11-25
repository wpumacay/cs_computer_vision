

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




    }






}