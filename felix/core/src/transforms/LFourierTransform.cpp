
#include "../../include/transforms/LFourierTransform.h"

#include <cmath>
#include <algorithm>

using namespace std;

namespace felix
{

    namespace transforms
    {


        LFourierTransform2D::LFourierTransform2D()
        {
            m_buffer = NULL;
            m_width = 0;
            m_height = 0;
        }

        LFourierTransform2D::LFourierTransform2D( int w, int h )
        {
            m_width = w;
            m_height = h;

            m_buffer = new LVec2[ w * h ];
        }

        LFourierTransform2D::~LFourierTransform2D()
        {
            // TODO: :(
        }

        void LFourierTransform2D::set( int u, int v, const LVec2& vec )
        {
            m_buffer[ v + u * m_width ] = vec;
        }

        LVec2 LFourierTransform2D::get( int u, int v ) const
        {
            return m_buffer[ v + u * m_width ];
        }


        LVec2 _dftGetComponent( const core::LMatf& lmat, int u, int v )
        {
            int _w = lmat.cols();
            int _h = lmat.rows();

            LVec2 _vec;

            for ( int i = 0; i < _h; i++ )
            {
                for ( int j = 0; j < _w; j++ )
                {
                    float _fij = lmat.get( j, i, 0 );
                    float _theta = -2 * _PI * ( ( u * i ) / ( ( float )_h ) + ( v * j ) / ( ( float )_w ) );
                    _vec = _vec + LVec2( _fij * cos( _theta ), 
                                         _fij * sin( _theta ) );
                }
            }

            return _vec;
        }

        float _dftInvGetValue( const LFourierTransform2D& ft, int i, int j )
        {
            int _uu = ft.height();
            int _vv = ft.width();

            LVec2 _vec;

            for ( int _u = 0; _u < _uu; _u++ )
            {
                for ( int _v = 0; _v < _vv; _v++ )
                {
                    LVec2 _Fuv = ft.get( _u, _v );
                    float _r = _Fuv.length();
                    float _phi = _Fuv.phase();
                    float _theta = 2 * _PI * ( ( _u * i ) / ( ( float )_uu ) + ( _v * j ) / ( ( float )_vv ) );
                    _vec = _vec + LVec2( _r * cos( _phi + _theta ), 
                                         _r * sin( _phi + _theta ) );
                }
            }

            return _vec.length() / ( _uu * _vv );
        }

        void _fft1d_mat2dft( LFourierTransform2D& ft, const core::LMatf& lmat, int row )
        {
            // Do fft1d along row 'row' of the image given by lmat

            
        }

        void _fft1d_dft2dft( LFourierTransform2D& ftBase, LFourierTransform2D& ftRes, int col )
        {

        }

        LFourierTransform2D fft2( const core::LMatf& lmat )
        {
            LFourierTransform2D _fftBase( lmat.cols(), lmat.rows() );
            LFourierTransform2D _fftRes( lmat.cols(), lmat.rows() );

            if ( lmat.channels() > 1 )
            {
                cout << "dft> just gray images supported for the moment" << endl;

                return _fftRes;
            }

            int _w = _fftRes.width();
            int _h = _fftRes.height();

            for ( int u = 0; u < _h; u++ )
            {
                _fft1d_mat2dft( _fftBase, lmat, u );
            }

            for ( int v = 0; v < _w; v++ )
            {
                _fft1d_dft2dft( _fftBase, _fftRes, v );
            }

            return _fftRes;
        }

        core::LMatf fft2_inverse( const LFourierTransform2D& ft )
        {

        }

        LFourierTransform2D dft( const core::LMatf& lmat )
        {
            LFourierTransform2D _res( lmat.cols(), lmat.rows() );

            if ( lmat.channels() > 1 )
            {
                cout << "dft> just gray images supported for the moment" << endl;

                return _res;
            }

            int _w = _res.width();
            int _h = _res.height();

            for ( int u = 0; u < _h; u++ )
            {
                for ( int v = 0; v < _w; v++ )
                {
                    _res.set( u, v, _dftGetComponent( lmat, u, v ) );
                }
            }


            return _res;
        }

        LFourierTransform2D shiftCenter( const LFourierTransform2D& ft )
        {
            LFourierTransform2D _res( ft.width(), ft.height() );

            int _uu = ft.height();
            int _vv = ft.width();

            for ( int _u = 0; _u < _uu; _u++ )
            {
                for ( int _v = 0; _v < _vv; _v++ )
                {
                    int _up = ( _u + ( _uu / 2 ) ) % _uu;
                    int _vp = ( _v + ( _vv / 2 ) ) % _vv;

                    auto _val = ft.get( _u, _v );

                    _res.set( _vp, _up, _val );
                }
            }

            return _res;
        }

        core::LMatf dft_inverse( const LFourierTransform2D& ft )
        {
            int _h = ft.height();
            int _w = ft.width();

            core::LMatf _res( _h, _w, 1 );

            for ( int i = 0; i < _h; i++ )
            {
                for ( int j = 0; j < _w; j++ )
                {
                    _res.set( j, i, 0, _dftInvGetValue( ft, i, j ) );
                }
            }

            return _res;
        }

        core::LMatf getTransformMagnitude( const LFourierTransform2D& ft )
        {
            float _min = 1000000.0f;
            float _max = -1000000.0f;

            int _uu = ft.height();
            int _vv = ft.width();

            core::LMatf _res( _uu, _vv, 1 );

            for ( int _u = 0; _u < _uu; _u++ )
            {
                for ( int _v = 0; _v < _vv; _v++ )
                {
                    float _val = log( 1 + ft.get( _u, _v ).length() );
                    _min = ( _val < _min ) ? _val : _min;
                    _max = ( _val > _max ) ? _val : _max;

                    _res.set( _v, _u, 0, _val );
                }
            }

            cout << "min: " << _min << " - max: " << _max << endl;

            _res.stretch( _min, _max, 0.0f, 1.0f );

            return _res;
        }

        core::LMatf getTransformPhase( const LFourierTransform2D& ft )
        {
            int _uu = ft.height();
            int _vv = ft.width();

            core::LMatf _res( _uu, _vv, 1 );


            return _res;
        }

        core::LMatf testSinusoidImage()
        {
            int _w = 50;
            int _h = 50;

            core::LMatf _img( _h, _w, 1 );

            for ( int i = 0; i < _h; i++ )
            {
                for ( int j = 0; j < _w; j++ )
                {
                    float _val = 0.5 * cos( 2 * _PI * ( i / 10.0 ) ) + 0.5;
                    _img.set( j, i, 0, _val );
                }
            }

            return _img;
        }

    }





}