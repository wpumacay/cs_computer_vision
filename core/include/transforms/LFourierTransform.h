

#pragma once

#include "../mat/LMat.h"

#include <cstring>

using namespace std;



namespace felix
{

    namespace transforms
    {

        int _nextPow2( int v );

        class LComplexSignal1D
        {
            private :

            LVec2* m_buff;
            int m_len;

            public :

            LComplexSignal1D()
            {
                m_buff = NULL;
                m_len = 0;
            }

            LComplexSignal1D( int dim )
            {
                m_len = dim;
                m_buff = new LVec2[m_len];
            }

            LComplexSignal1D( const LComplexSignal1D& other )
            {
                m_len = other.m_len;
                m_buff = new LVec2[m_len];

                memcpy( m_buff, other.m_buff, sizeof( LVec2 ) * m_len );
            }

            LComplexSignal1D& operator=( const LComplexSignal1D& other )
            {
                if ( m_buff != NULL )
                {
                    delete m_buff;
                }

                m_len = other.m_len;
                m_buff = new LVec2[m_len];

                memcpy( m_buff, other.m_buff, sizeof( LVec2 ) * m_len );

                return *this;
            }

            ~LComplexSignal1D()
            {
                if ( m_buff != NULL )
                {
                    delete m_buff;
                    m_buff = NULL;
                }
            }

            void set( int indx, const LVec2& vec )
            {
                m_buff[indx] = vec;
            }

            LVec2 get( int indx )
            {
                return m_buff[indx];
            }

            int length() { return m_len; }
        };

        class LFourierTransform2D
        {

            private :

            LVec2* m_buffer;
            int m_width;
            int m_height;

            public :

            LFourierTransform2D();
            LFourierTransform2D( int w, int h );
            ~LFourierTransform2D();

            void set( int u, int v, const LVec2& vec );
            LVec2 get( int u, int v ) const;

            int width() const { return m_width; } 
            int height() const { return m_height; }

            void setColFrom1D( int col, const LComplexSignal1D& pComplexSignal1D );
            void setRowFrom1D( int row, const LComplexSignal1D& pComplexSignal1D );

        };

        void dft1d( const LComplexSignal1D& src, LComplexSignal1D& dst );
        void fft1d( const LComplexSignal1D& src, LComplexSignal1D& dst );

        LVec2 _dftGetComponent( const core::LMatf& lmat, int u, int v );
        float _dftInvGetValue( const LFourierTransform2D& ft, int i, int j );

        void _fft1d_mat2dft( LFourierTransform2D& ft, const core::LMatf& lmat, int row );
        void _fft1d_dft2dft( LFourierTransform2D& ftBase, LFourierTransform2D& ftRes );

        LFourierTransform2D fft2( const core::LMatf& lmat );
        core::LMatf fft2_inverse( const LFourierTransform2D& ft );

        LFourierTransform2D dft( core::LMatf lMat );
        core::LMatf dft_inverse( const LFourierTransform2D& ft );

        LFourierTransform2D shiftCenter( const LFourierTransform2D& ft );

        core::LMatf getTransformMagnitude( const LFourierTransform2D& ft );
        core::LMatf getTransformPhase( const LFourierTransform2D& ft );


        core::LMatf testSinusoidImage();

    }


}