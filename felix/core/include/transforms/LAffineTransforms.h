

#pragma once

#include "../mat/LMat.h"
#include "../mat/LGpuMat.h"

using namespace std;

namespace felix
{

    namespace transforms
    {

        namespace interpolation
        {
            enum _interpolation
            {
                NEAREST_NEIGHBOR,
                BILINEAR,
                BICUBIC
            };
        }

        struct LAffineTransforms
        {

            static float _interpolate_nn( const core::LMatf& lmat,
                                          float fx, float fy, int channel );

            static float _interpolate_bl( const core::LMatf& lmat,
                                          float fx, float fy, int channel );

            static float _interpolate_bc( const core::LMatf& lmat,
                                          float fx, float fy, int channel );






            static core::LMatf warpAffine( const core::LMatf& lmat,
                                           int pCols, int pRows,
                                           float* pMatrix3f, 
                                           interpolation::_interpolation pInterpolation = interpolation::NEAREST_NEIGHBOR );

            static core::LMatf scale( const core::LMatf& lmat, 
                                      int pCols, int pRows, 
                                      float sx, float sy, 
                                      interpolation::_interpolation pInterpolation = interpolation::NEAREST_NEIGHBOR );

            static core::LMatf rotate( const core::LMatf& lmat,
                                       int pCols, int pRows,
                                       float angle, 
                                       interpolation::_interpolation pInterpolation = interpolation::NEAREST_NEIGHBOR );

            static core::LMatf translate( const core::LMatf& lmat,
                                          int pCols, int pRows,
                                          float tx, float ty, 
                                          interpolation::_interpolation pInterpolation = interpolation::NEAREST_NEIGHBOR );




        };



    }





}