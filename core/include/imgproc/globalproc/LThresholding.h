
#pragma once

#include "../../mat/LMat.h"

#include <iostream>

#define ABS( x ) ( x < 0 ) ? -x : x

namespace felix
{



    class LBinKernel
    {
        private :

        u8* m_buffer;
        int m_rows;
        int m_cols;

        public :

        LBinKernel();
        LBinKernel( int cols, int rows );
        LBinKernel( const LBinKernel& other );
        void operator= ( const LBinKernel& other );
        ~LBinKernel();

        u8 operator() ( int col, int row ) const;
        void set ( int col, int row, u8 value );

        u8* buffer() { return m_buffer; }

        int cols() const { return m_cols; }
        int rows() const { return m_rows; }

        int halfCols() const { return ( m_cols - 1 ) / 2; }
        int halfRows() const { return ( m_rows - 1 ) / 2; }

        void print();
    };

    namespace binKernelType
    {
        enum _binKernelType
        {
            DIAMOND = 0,
            SQUARE = 1
        };
    }

    core::LMatu threshRange( const core::LMatu& mat, u8 vMin, u8 vMax, int channel );

    LBinKernel makeBinKernel( int size, binKernelType::_binKernelType kType );
    core::LMatu dilate( const core::LMatu& bwMat, const LBinKernel& kernel );
    core::LMatu erode( const core::LMatu& bwMat, const LBinKernel& kernel );

    u8 _dilateAt( int x, int y, const core::LMatu& bwMat, const LBinKernel& kernel );
    u8 _erodeAt( int x, int y, const core::LMatu& bwMat, const LBinKernel& kernel );

}