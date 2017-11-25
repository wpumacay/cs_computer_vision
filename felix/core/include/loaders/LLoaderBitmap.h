

#pragma once

#include "../../LCommon.h"

#include "../mat/LMat.h"

#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;

#define BMH_BITMAPCOREHEADER_SIZE 12
#define BMH_OS22XBITMAPHEADER_1 64
#define BMH_OS22XBITMAPHEADER_2 16
#define BMH_BITMAPINFOHEADER 40
#define BMH_BITMAPV2INFOHEADER 52
#define BMH_BITMAPV3INFOHEADER 56
#define BMH_BITMAPV4HEADER 108
#define BMH_BITMAPV5HEADER 124


namespace felix 
{ 

    namespace core
    {
        #pragma pack( push, 1 )
        struct LBitmapFileHeader
        {
            u16 bfType;
            u32 bfSize;
            u16 bfReserved1;
            u16 bfReserved2;
            u32 bfOffBits;
        };
        #pragma pack( pop )


        #pragma pack( push, 1 )
        struct LBitmapv5Header
        {
            u32 bV5Size;
            u32 bV5Width;
            u32 bV5Height;
            u16 bV5Planes;
            u16 bV5BitCount;
            u32 bV5Compression;
            u32 bV5SizeImage;
            u32 bV5XPelsPerMeter;
            u32 bV5YPelsPerMeter;
            u32 bV5ClrUsed;
            u32 bV5ClrImportant;
            u32 bV5RedMask;
            u32 bV5GreenMask;
            u32 bV5BlueMask;
            u32 bV5AlphaMask;
            u32 bV5CSType;
            u8 bV5Endpoints[36];
            u32 bV5GammaRed;
            u32 bV5GammaGreen;
            u32 bV5GammaBlue;
            u32 bV5Intent;
            u32 bV5ProfileData;
            u32 bV5ProfileSize;
            u32 bV5Reserved;
        };
        #pragma pack( pop )

        struct LLoaderBitmap
        {

            static LMat<u8>* load( const string& pImgPath )
            {
                FILE* _file = fopen( pImgPath.c_str(), "rb" );

                if ( _file != NULL )
                {
                    LBitmapFileHeader _bfh;
                    fread( &_bfh, sizeof( LBitmapFileHeader ), 1, _file );

                    //cout << "bfType: " << _bfh.bfType << endl;
                    //cout << "bfSize: " << _bfh.bfSize << endl;
                    //cout << "bfOffBits: " << _bfh.bfOffBits << endl;

                    int _headerBytes = _bfh.bfOffBits - 14;

                    if ( _headerBytes == BMH_BITMAPV5HEADER )
                    {
                        LBitmapv5Header _b5header;
                        fread( &_b5header, sizeof( LBitmapv5Header ), 1, _file );

                        //cout << "bv5.size : " << _b5header.bV5Size << endl;
                        //cout << "bv5.width : " << _b5header.bV5Width << endl;
                        //cout << "bv5.heigt : " << _b5header.bV5Height << endl;
                        //cout << "bv5.bitcount : " << _b5header.bV5BitCount << endl;
                        //cout << "bv5.bV5Compression : " << _b5header.bV5Compression << endl;

                        if ( _b5header.bV5BitCount != 24 )
                        {
                            cout << "unsupported bit count: " << _b5header.bV5BitCount << endl;
                            cout << "only 24 bitcount supported" << endl;
                            return NULL;
                        }

                        if ( _b5header.bV5ClrUsed != 0 )
                        {
                            cout << "using color table, not supported yet" << endl;
                            return NULL;
                        }

                        int _w = _b5header.bV5Width;
                        int _h = _b5header.bV5Height;
                        int _padding = 4 - ( 3 * _w ) % 4;

                        //cout << "padding: " << _padding << endl;
                        //cout << "buffSize: " << ( 3 * _w + _padding ) * _h << endl;

                        u8* _buffer = new u8[ ( 3 * _w + _padding ) * _h ];

                        fread( _buffer, sizeof( u8 ), ( 3 * _w + _padding ) * _h, _file );

                        LMatu* _res = new LMatu( _h, _w, 3 );

                        for ( int i = _h - 1; i >= 0; i-- )
                        {
                            for ( int j = 0; j < _w; j++ )
                            {
                                (*_res)( j, i, 2, _buffer[( 3 * j + 0 ) + ( _h - 1 - i ) * ( 3 * _w + _padding )] );
                                (*_res)( j, i, 1, _buffer[( 3 * j + 1 ) + ( _h - 1 - i ) * ( 3 * _w + _padding )] );
                                (*_res)( j, i, 0, _buffer[( 3 * j + 2 ) + ( _h - 1 - i ) * ( 3 * _w + _padding )] );
                            }
                        }                        


                        // Data is read in bgr, trasnform each pixel to rgb

                        delete[] _buffer;

                        fclose( _file );

                        return _res;
                    }
                    else
                    {
                        cout << "no support yet for this file type" << endl;

                        return NULL;
                    }

                    
                }

                return NULL;
            }

        };




    }


}




