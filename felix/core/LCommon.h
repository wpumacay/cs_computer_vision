

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <cstring>


#ifdef OPENMP_SUPPORT_ENABLED

#define OPENMP_NUM_THREADS 4
#include <omp.h>

#endif

#define CUDA_MAX_THREADS_PER_BLOCK 1024
#define CUDA_THREADS_SPLIT_2D 32
#define _PI 3.141592653589793

#define RANDOM() ( ( float )rand() ) / RAND_MAX

typedef void ( *LFnPtr_trackbar )( float value );
typedef void ( *LFnPtr_button )();

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef char i8;
typedef signed short i16;
typedef signed int i32;

template<class T>
struct LPixelRGBA
{
    T r;
    T g;
    T b;
    T a;

    LPixelRGBA()
    {
        r = 0;
        g = 0;
        b = 0;
        a = 1;
    }
};

template<class T>
struct LPixelRGB
{
    T r;
    T g;
    T b;

    LPixelRGB()
    {
        r = 0;
        g = 0;
        b = 0;
    }
};

struct LVec2
{
    float x;
    float y;

    LVec2()
    {
        x = 0;
        y = 0;
    }

    LVec2( float x, float y )
    {
        this->x = x;
        this->y = y;
    }

    LVec2 operator + ( const LVec2& other )
    {
        return LVec2( this->x + other.x,
                      this->y + other.y );
    }

    LVec2 operator - ( const LVec2& other )
    {
        return LVec2( this->x - other.x,
                      this->y - other.y );
    }

    void operator * ( float val )
    {
        this->x *= val;
        this->y *= val;
    }

    void scale( float val )
    {
        this->x *= val;
        this->y *= val;
    }

    float length()
    {
        return sqrt( x * x + y * y );
    }

    float phase()
    {
        return atan2( y, x );
    }
};

typedef LPixelRGB<u8> LPixelRGBu;
typedef LPixelRGB<float> LPixelRGBf;