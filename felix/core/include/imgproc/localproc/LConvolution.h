

#pragma once

#include "../../mat/LMat.h"

using namespace std;


namespace felix
{

    class LConvKernel
    {
        private :

        float* m_buffer;
        int m_rows;
        int m_cols;

        public :

        LConvKernel();
        LConvKernel( int cols, int rows );
        ~LConvKernel();

        float operator() ( int col, int row ) const;
        void set ( int col, int row, float value );

        float* buffer() { return m_buffer; }

        int cols() const { return m_cols; }
        int rows() const { return m_rows; }

        int halfCols() const { return ( m_cols - 1 ) / 2; }
        int halfRows() const { return ( m_rows - 1 ) / 2; }
    };

    LConvKernel makeKernelAverage( int cols, int rows );
    core::LMatf convolve( const core::LMatf& srcMat, const LConvKernel& kernel );

    float _applyKernel( const core::LMatf& srcMat, int pCol, int pRow, int pChannel, const LConvKernel& kernel );


}