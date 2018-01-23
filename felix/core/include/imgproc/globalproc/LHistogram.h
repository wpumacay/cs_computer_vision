

#pragma once

#include "../../mat/LMat.h"

using namespace std;

#define HISTOGRAM_BIN_SIZE 255

namespace felix
{

    struct LHist
    {
        u32 h[HISTOGRAM_BIN_SIZE];

        LHist();

        u32 cumsum( int i ) const;

        string toString() const;
    };

    struct LHistTransform
    {
        float f[HISTOGRAM_BIN_SIZE];

        LHistTransform();
        LHistTransform( const LHist& cumHist );

        string toString() const;
    };

    struct LHistogram
    {

        private :

        static LHist _computeHistogram( const core::LMatu& lmat );
        static LHistTransform _computeHistTransform( const LHist& histogram );


        public :

        static core::LMatu equalize( const core::LMatu& lmat );
    };



}