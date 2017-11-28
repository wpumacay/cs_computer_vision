

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>


#ifdef OPENMP_SUPPORT_ENABLED

#define OPENMP_NUM_THREADS 4
#include <omp.h>

#endif

#define CUDA_MAX_THREADS_PER_BLOCK 1024
#define CUDA_THREADS_SPLIT_2D 32


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

typedef LPixelRGB<u8> LPixelRGBu;
typedef LPixelRGB<float> LPixelRGBf;