
#pragma once

#include "../LCommon.h"



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


    }




}



