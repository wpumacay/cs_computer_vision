

#include "../../../include/cuda/transforms/LCudaAffineTransforms.h"

using namespace std;

__device__ float device_interpolate_nn( float* d_mat,
                                        int cols, int rows, int channels,
                                        float fx_c, float fy_c, int pChannel )
{

    // 1. fx, fy are centric coordinates, transform the back to the original system
    float _fx = fx_c + 0.5 * cols;
    float _fy = 0.5 * rows - fy_c;

    // 2. Apply nn interpolation
    int _x = __float2int_ru( _fx );
    int _y = __float2int_ru( _fy );

    if ( _x < 0 || _x > cols - 1 ||
         _y < 0 || _y > rows - 1 )
    {
        return 0.0f;
    }

    return d_mat[ channels * ( _x + _y * cols ) + pChannel ];
}



__global__ void kernel_warpAffine( float* d_srcMat,
                                   float* d_dstMat,
                                   int srcCols, int srcRows,
                                   int dstCols, int dstRows,
                                   int channels,
                                   float* d_matrix3f )
{

    int x = threadIdx.x + blockIdx.x * blockDim.x;
    int y = threadIdx.y + blockIdx.y * blockDim.y;

    if ( x > dstCols - 1 ||
         y > dstRows - 1 )
    {
        return;
    }

    // 1. Transform it to image centric coordinates
    float _xc = x - 0.5 * dstCols;
    float _yc = 0.5 * dstRows - y;

    // 2. Get source coordinates using the inverse transform
    float _x = d_matrix3f[0] * _xc + d_matrix3f[1] * _yc + d_matrix3f[2];
    float _y = d_matrix3f[3] * _xc + d_matrix3f[4] * _yc + d_matrix3f[5];

    // 3. Apply interpolation of the pixel at _x, _y ...
    // in the src image for each channel
    for ( int c = 0; c < channels; c++ )
    {
        float _v = device_interpolate_nn( d_srcMat, 
                                          srcCols, srcRows, channels,
                                          _x, _y, c );

        d_dstMat[ channels * ( x + y * dstCols ) + c ] = _v;
    }

}









namespace felix
{


    namespace cuda
    {


        core::LCudaMat LCudaAffineTransforms::warpAffine( core::LCudaMat& lmat,
                                                          int pDstCols, int pDstRows,
                                                          float* pMatrix3f )
        {

            // Calculate split size

            int _bx = ceil( ( float ) pDstCols / CUDA_THREADS_SPLIT_2D );
            int _by = ceil( ( float ) pDstRows / CUDA_THREADS_SPLIT_2D );

            //cout << "partition: " << _bx << " - " << _by << endl;

            core::LCudaMat _res( pDstRows, pDstCols, lmat.channels() );

            lmat.loadToGpu();
            _res.loadToGpu();

            const dim3 _blockSize( CUDA_THREADS_SPLIT_2D, CUDA_THREADS_SPLIT_2D );
            const dim3 _gridSize( _bx, _by );

            // Inverse by cofactors

            float _det = pMatrix3f[0] * pMatrix3f[4] - pMatrix3f[3] * pMatrix3f[1];

            float _c11 = pMatrix3f[4] / _det;
            float _c12 = -pMatrix3f[3] / _det;
            float _c13 = 0.0f;

            float _c21 = -pMatrix3f[1] / _det;
            float _c22 = pMatrix3f[0] / _det;
            float _c23 = 0.0f;            

            float _c31 = ( pMatrix3f[1] * pMatrix3f[5] - pMatrix3f[2] * pMatrix3f[4] ) / _det;
            float _c32 = -( pMatrix3f[0] * pMatrix3f[5] - pMatrix3f[2] * pMatrix3f[3] ) / _det;
            float _c33 = 1.0f;

            //cout << "_det: " << _det << endl;

            float _pMatInv[9] = { _c11, _c21, _c31,
                                  _c12, _c22, _c32,
                                  _c13, _c23, _c33 };

            // Send inverse to gpu
            float* d_matrix3f;
            cudaMalloc( ( void** ) &d_matrix3f, sizeof( float ) * 9 );
            cudaMemcpy( d_matrix3f, _pMatInv, sizeof( float ) * 9, cudaMemcpyHostToDevice );

            kernel_warpAffine<<< _gridSize, _blockSize >>>( lmat.devGpuBuffer(),
                                                            _res.devGpuBuffer(),
                                                            lmat.cols(), lmat.rows(), 
                                                            _res.cols(), _res.rows(),
                                                            lmat.channels(),
                                                            d_matrix3f );

            _res.loadFromGpu();

            cudaFree( d_matrix3f );

            return _res;
        }

        core::LCudaMat LCudaAffineTransforms::scale( core::LCudaMat& lCudaMat,
                                                     int pDstCols, int pDstRows,
                                                     float sx, float sy )
        {
            float* _matrix3f = new float[9];

            _matrix3f[0] = sx;   _matrix3f[1] = 0.0f; _matrix3f[2] = 0.0f;
            _matrix3f[3] = 0.0f; _matrix3f[4] = sy;   _matrix3f[5] = 0.0f;
            _matrix3f[6] = 0.0f; _matrix3f[7] = 0.0f; _matrix3f[8] = 1.0f;

            core::LCudaMat _res = LCudaAffineTransforms::warpAffine( lCudaMat, pDstCols, pDstRows, _matrix3f );

            delete[] _matrix3f;

            return _res;
        }

        core::LCudaMat LCudaAffineTransforms::rotate( core::LCudaMat& lCudaMat,
                                                     int pDstCols, int pDstRows,
                                                     float angle )
        {
            float* _matrix3f = new float[9];

            float _c = cos( angle );
            float _s = sin( angle );

            _matrix3f[0] = _c;   _matrix3f[1] = -_s;  _matrix3f[2] = 0.0f;
            _matrix3f[3] = _s;   _matrix3f[4] = _c;   _matrix3f[5] = 0.0f;
            _matrix3f[6] = 0.0f; _matrix3f[7] = 0.0f; _matrix3f[8] = 1.0f;

            core::LCudaMat _res = LCudaAffineTransforms::warpAffine( lCudaMat, pDstCols, pDstRows, _matrix3f );

            delete[] _matrix3f;

            return _res;
        }

        core::LCudaMat LCudaAffineTransforms::translate( core::LCudaMat& lCudaMat,
                                                     int pDstCols, int pDstRows,
                                                     float tx, float ty )
        {
            float* _matrix3f = new float[9];

            _matrix3f[0] = 1.0f; _matrix3f[1] = 0.0f; _matrix3f[2] = tx;
            _matrix3f[3] = 0.0f; _matrix3f[4] = 1.0f; _matrix3f[5] = ty;
            _matrix3f[6] = 0.0f; _matrix3f[7] = 0.0f; _matrix3f[8] = 1.0f;

            core::LCudaMat _res = LCudaAffineTransforms::warpAffine( lCudaMat, pDstCols, pDstRows, _matrix3f );

            delete[] _matrix3f;

            return _res;
        }

    }





}