

#include "../../../include/cuda/testing/LCudaTesting.h"

using namespace std;


__global__ void kernel_test_rgb( float* d_Mat,
                                 int cols, int rows, 
                                 int channels )
{

    int x = threadIdx.x + blockIdx.x * blockDim.x;
    int y = threadIdx.y + blockIdx.y * blockDim.y;

    if ( x > cols - 1 ||
         y > rows - 1 )
    {
        return;
    }

    for ( int c = 0; c < channels; c++ )
    {
        if ( c == 0 )
        {
            d_Mat[ channels * ( x + y * cols ) + c ] = 1.0f;
        }
        else
        {
            d_Mat[ channels * ( x + y * cols ) + c ] = 0.0f;
        }
            
    }
}





namespace felix
{


    namespace cuda
    {


        core::LCudaMat LCudaTesting::test_gen_rgb( int rows, int cols, int channels )
        {

            // Calculate split size

            int _bx = ceil( ( float ) cols / CUDA_THREADS_SPLIT_2D );
            int _by = ceil( ( float ) rows / CUDA_THREADS_SPLIT_2D );

            core::LCudaMat _res( rows, cols, channels );
            _res.loadToGpu();

            const dim3 _blockSize( CUDA_THREADS_SPLIT_2D, CUDA_THREADS_SPLIT_2D );
            const dim3 _gridSize( _bx, _by );

            kernel_test_rgb<<< _gridSize, _blockSize >>>( _res.devGpuBuffer(),
                                                          _res.cols(), _res.rows(), 
                                                          _res.channels() );

            _res.loadFromGpu();

            return _res;
        }



    }





}