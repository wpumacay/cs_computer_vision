
#pragma once

#include "../../LCommon.h"

#include <cstring>

using namespace std;

namespace felix
{

    namespace core
    {


        template<class T>
        class LMat
        {
            protected :

            T* m_buffer;

            int m_rows;// height
            int m_cols;// width
            int m_size;
            int m_channels;

            public :

            LMat()
            {
                m_buffer = NULL;
                m_rows = 0;
                m_cols = 0;
                m_size = 0;
                m_channels = 0;
            }

            LMat( int rows, int cols, int channels )
            {
                m_buffer = new T[rows * cols * channels];
                m_rows = rows;
                m_cols = cols;
                m_size = rows * cols;
                m_channels = channels;

                // Initialize with zeros
                for ( int q = 0; q < m_size; q++ )
                {
                    for ( int p = 0; p < m_channels; p++ )
                    {
                        m_buffer[m_channels * q + p] = 0;
                    }
                }
            }
            

            LMat( int rows, int cols, int channels, T* pData )
            {
                m_buffer = new T[rows * cols * channels];
                m_rows = rows;
                m_cols = cols;
                m_size = rows * cols;
                m_channels = channels;

                for ( int q = 0; q < m_size; q++ )
                {
                    for ( int c = 0; c < m_channels; c++ )
                    {
                        m_buffer[ m_channels * q + c ] = pData[ m_channels * q + c ];
                    }
                }
            }

            LMat( const LMat& other )
            {
                m_buffer = new T[ other.m_rows * other.m_cols * other.m_channels];
                m_rows = other.m_rows;
                m_cols = other.m_cols;
                m_size = other.m_rows * other.m_cols;
                m_channels = other.m_channels;

                memcpy( m_buffer, other.m_buffer, sizeof( T ) * m_rows * m_cols * m_channels );
            }

            void operator= ( const LMat& other )
            {
                if ( m_buffer != NULL )
                {
                    delete m_buffer;
                }

                m_buffer = new T[ other.m_rows * other.m_cols * other.m_channels];
                m_rows = other.m_rows;
                m_cols = other.m_cols;
                m_size = other.m_rows * other.m_cols;
                m_channels = other.m_channels;

                memcpy( m_buffer, other.m_buffer, sizeof( T ) * m_rows * m_cols * m_channels );
            }

            ~LMat()
            {
                if ( m_buffer != NULL )
                {
                    delete[] m_buffer;
                    m_buffer = NULL;
                }
            }

            void releaseMemory()
            {
                delete[] m_buffer;
            }

            void copyFromBuffer( T* pData )
            {
                memcpy( m_buffer, pData, sizeof( T ) * m_size * m_channels );
            }

            void operator() ( int col, int row, int c, T v )
            {
                int _pixIndx = col + row * m_cols;

                m_buffer[ m_channels * _pixIndx + c ] = v;
            }

            void set ( int col, int row, int c, T v )
            {
                int _pixIndx = col + row * m_cols;

                m_buffer[ m_channels * _pixIndx + c ] = v;
            }

            T operator() ( int col, int row, int channel )
            {
                int _pixIndx = col + row * m_cols;

                return m_buffer[ m_channels * _pixIndx + channel ];
            }

            T get ( int col, int row, int channel ) const
            {
                int _pixIndx = col + row * m_cols;

                return m_buffer[ m_channels * _pixIndx + channel ];
            }

            void stretch( T mMin, T mMax, T limitMin, T limitMax )
            {
                for ( int _row = 0; _row < m_rows; _row++ )
                {
                    for ( int _col = 0; _col < m_cols; _col++ )
                    {
                        int _pixIndx = _col + _row * m_cols;

                        for ( int _channel = 0; _channel < m_channels; _channel++ )
                        {
                            T _val = m_buffer[ m_channels * _pixIndx + _channel ];

                            _val = limitMin + ( limitMax - limitMin ) * ( _val - mMin ) / ( mMax - mMin );

                            m_buffer[ m_channels * _pixIndx + _channel ] = _val;
                        }
                    }
                }
            }

            void normalize( T limitMin, T limitMax )
            {
                float _min = 1000000.0f;
                float _max = -1000000.0f;

                for ( int _row = 0; _row < m_rows; _row++ )
                {
                    for ( int _col = 0; _col < m_cols; _col++ )
                    {
                        int _pixIndx = _col + _row * m_cols;

                        for ( int _channel = 0; _channel < m_channels; _channel++ )
                        {
                            if ( _channel == 3 )
                            {
                                // Skip alpha value
                                continue;
                            }

                            T _val = m_buffer[ m_channels * _pixIndx + _channel ];

                            _min = ( _val < _min ) ? _val : _min;
                            _max = ( _val > _max ) ? _val : _max;
                        }
                    }
                }

                std::cout << "min: " << _min << std::endl;
                std::cout << "max: " << _max << std::endl;

                for ( int _row = 0; _row < m_rows; _row++ )
                {
                    for ( int _col = 0; _col < m_cols; _col++ )
                    {
                        int _pixIndx = _col + _row * m_cols;

                        for ( int _channel = 0; _channel < m_channels; _channel++ )
                        {
                            if ( _channel == 3 )
                            {
                                // Skip alpha channel
                                continue;
                            }

                            T _val = m_buffer[ m_channels * _pixIndx + _channel ];

                            _val = limitMin + ( limitMax - limitMin ) * ( _val - _min ) / ( _max - _min );

                            m_buffer[ m_channels * _pixIndx + _channel ] = _val;
                        }
                    }
                }
            }

            void dump( int cutoff = 300 )
            {
                cout << "matDump" << endl;
                for ( int q = 0; q < m_channels * m_size; q++ )
                {
                    if ( q >= cutoff )
                    {
                        break;
                    }
                    cout << (int)m_buffer[q] << endl;
                }
            }

            int rows() const
            {
                return m_rows;
            }

            int cols() const
            {
                return m_cols;
            }

            int size() const 
            {
                return m_size;
            }

            int channels() const
            {
                return m_channels;
            }

            T* buffer() const
            {
                return m_buffer;
            }

            static LMat<T> testImg()
            {
                int _w = 100;
                int _h = 100;

                LMat<T> _img( _h, _w, 3 );

                T* _imgBuff = _img.buffer();

                for ( int k = 0; k < 3; k++ )
                {
                    T val = 0;

                    if ( k == 2 )
                    {
                        if ( sizeof( T ) == sizeof( u8 ) )
                        {
                            val = 255;
                        }
                        else
                        {
                            val = 1;
                        }
                    }

                    for ( int i = 0; i < _h; i++ )
                    {
                        for ( int j = 0; j < _w; j++ )
                        {
                            int _pixIndx = j + i * _w;

                            _imgBuff[ 3 * ( _pixIndx ) + k ] = val;
                        }
                    }
                }

        
                return _img;
            }

        };


        template<class T>
        LMat<T> rgb2gray( const LMat<T>& img )
        {
            // TODO: Error checking

            LMat<T> _res( img.rows(), img.cols(), 1 );

            int _nPixels = _res.size();
            
            T* _imgBuff = img.buffer();
            T* _resBuff = _res.buffer();

            for ( int q = 0; q < _nPixels; q++ )
            {
                _resBuff[q] = 0.299f * _imgBuff[ 3 * q + 0 ] +
                              0.587f * _imgBuff[ 3 * q + 1 ] +
                              0.114f * _imgBuff[ 3 * q + 2 ];
            }

            return _res;
        }

        template<class T>
        LMat<T> gray2rgb( const LMat<T>& img )
        {
            LMat<T> _res( img.rows(), img.cols(), 3 );

            int _nPixels = _res.size();
            
            T* _imgBuff = img.buffer();
            T* _resBuff = _res.buffer();

            for ( int q = 0; q < _nPixels; q++ )
            {
                _resBuff[ 3 * q + 0 ] = _imgBuff[q];
                _resBuff[ 3 * q + 1 ] = _imgBuff[q];
                _resBuff[ 3 * q + 2 ] = _imgBuff[q];
            }

            return _res;            
        }

        typedef LMat<u8> LMatu;
        typedef LMat<float> LMatf;


        template<class T>
        LMat<T> makeNoiseSaltPepper( int w, int h, int c, float percent, T vmax )
        {
            LMat<T> _res( h, w, c );

            int _nPixels = _res.size();

            T* _resBuff = _res.buffer();

            for ( int q = 0; q < _nPixels; q++ )
            {
                if ( RANDOM() < percent )
                {
                    for ( int _ch = 0; _ch < c; _ch++ )
                    {
                        _resBuff[ c * q + _ch ] = vmax;
                    }
                }
                else
                {
                    for ( int _ch = 0; _ch < c; _ch++ )
                    {
                        _resBuff[ c * q + _ch ] = 0;
                    }
                }
            }

            return _res;
        }

    }




}



