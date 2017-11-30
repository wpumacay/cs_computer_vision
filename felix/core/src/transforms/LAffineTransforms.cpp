
#include "../../include/transforms/LAffineTransforms.h"

#include <cmath>
#include <algorithm>

using namespace std;


namespace felix
{


    namespace transforms
    {


        float LAffineTransforms::_interpolate_nn( const core::LMatf& lmat,
                                                  float fx_c, float fy_c, int pChannel )
        {
            // 1. fx, fy are centric coordinates, transform the back to the original system
            float _fx = fx_c + 0.5 * lmat.cols();
            float _fy = 0.5 * lmat.rows() - fy_c;

            // 2. Apply nn interpolation
            int _x = round( _fx );
            int _y = round( _fy );

            if ( _x < 0 || _x >= lmat.cols() ||
                 _y < 0 || _y >= lmat.rows() )
            {
                return 0.0f;
            }

            //_x = max( min( _x, lmat.cols() ) , 0 );
            //_y = max( min( _y, lmat.rows() ) , 0 );

            return lmat.get( _x, _y, pChannel );
        }

        float LAffineTransforms::_interpolate_bl( const core::LMatf& lmat,
                                                  float fx, float fy, int channel )
        {
            return 0.0f;
        }

        float LAffineTransforms::_interpolate_bc( const core::LMatf& lmat,
                                                  float fx, float fy, int channel )
        {
            return 0.0f;
        }





        core::LMatf LAffineTransforms::warpAffine( const core::LMatf& lmat, 
                                                   int pCols, int pRows,
                                                   float* pMatrix3f,
                                                   interpolation::_interpolation pInterpolation )
        {
            core::LMatf _res( pRows, pCols, lmat.channels() );

            // Inverse by cofactors
            float _det = pMatrix3f[0] * pMatrix3f[4] - pMatrix3f[3] * pMatrix3f[1];

            //cout << "_det: " << _det << endl;

            float _c11 = pMatrix3f[4] / _det;
            float _c12 = -pMatrix3f[3] / _det;
            float _c13 = 0.0f;

            float _c21 = -pMatrix3f[1] / _det;
            float _c22 = pMatrix3f[0] / _det;
            float _c23 = 0.0f;            

            float _c31 = ( pMatrix3f[1] * pMatrix3f[5] - pMatrix3f[2] * pMatrix3f[4] ) / _det;
            float _c32 = -( pMatrix3f[0] * pMatrix3f[5] - pMatrix3f[2] * pMatrix3f[3] ) / _det;
            float _c33 = 1.0f;

            //float _pMatInv[9] = { _c11, _c21, _c31,
            //                      _c12, _c22, _c32,
            //                      _c13, _c23, _c33 };

            int _w = _res.cols();
            int _h = _res.rows();
            int _c = _res.channels();

            for ( int k = 0; k < _c; k++ )
            {
                for ( int x = 0; x < _w; x++ )
                {

#ifdef OPENMP_SUPPORT_ENABLED
                #pragma omp parallel for num_threads( OPENMP_NUM_THREADS )
#endif
                    for ( int y = 0; y < _h; y++ )
                    {
                        // 1. Transform it to image centric coordinates
                        float _xc = x - 0.5 * _w;
                        float _yc = 0.5 * _h - y;

                        // 2. Get source coordinates using the inverse transform
                        float _x = _c11 * _xc + _c21 * _yc + _c31;
                        float _y = _c12 * _xc + _c22 * _yc + _c32;

                        // 3. Apply interpolation of the pixel at _x, _y in the src image
                        float _v = LAffineTransforms::_interpolate_nn( lmat, _x, _y, k );

                        _res( x, y, k, _v );
                    }
                }
            }

            return _res;
        }


        core::LMatf LAffineTransforms::scale( const core::LMatf& lmat, 
                                              int pCols, int pRows, 
                                              float sx, float sy, 
                                              interpolation::_interpolation pInterpolation )
        {
            float* _matrix3f = new float[9];

            _matrix3f[0] = sx;   _matrix3f[1] = 0.0f; _matrix3f[2] = 0.0f;
            _matrix3f[3] = 0.0f; _matrix3f[4] = sy;   _matrix3f[5] = 0.0f;
            _matrix3f[6] = 0.0f; _matrix3f[7] = 0.0f; _matrix3f[8] = 1.0f;

            core::LMatf _res = LAffineTransforms::warpAffine( lmat, pCols, pRows, _matrix3f, pInterpolation );

            delete[] _matrix3f;

            return _res;
        }

        core::LMatf LAffineTransforms::rotate( const core::LMatf& lmat,
                                               int pCols, int pRows,
                                               float angle, 
                                               interpolation::_interpolation pInterpolation )
        {
            float* _matrix3f = new float[9];

            float _c = cos( angle );
            float _s = sin( angle );

            _matrix3f[0] = _c;   _matrix3f[1] = -_s;  _matrix3f[2] = 0.0f;
            _matrix3f[3] = _s;   _matrix3f[4] = _c;   _matrix3f[5] = 0.0f;
            _matrix3f[6] = 0.0f; _matrix3f[7] = 0.0f; _matrix3f[8] = 1.0f;

            core::LMatf _res = LAffineTransforms::warpAffine( lmat, pCols, pRows, _matrix3f, pInterpolation );

            delete[] _matrix3f;

            return _res;
        }

        core::LMatf LAffineTransforms::translate( const core::LMatf& lmat,
                                                  int pCols, int pRows,
                                                  float tx, float ty, 
                                                  interpolation::_interpolation pInterpolation )
        {
            float* _matrix3f = new float[9];

            _matrix3f[0] = 1.0f; _matrix3f[1] = 0.0f; _matrix3f[2] = tx;
            _matrix3f[3] = 0.0f; _matrix3f[4] = 1.0f; _matrix3f[5] = ty;
            _matrix3f[6] = 0.0f; _matrix3f[7] = 0.0f; _matrix3f[8] = 1.0f;

            core::LMatf _res = LAffineTransforms::warpAffine( lmat, pCols, pRows, _matrix3f, pInterpolation );

            delete[] _matrix3f;

            return _res;
        }






    }





}