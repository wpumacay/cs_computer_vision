
#pragma once


#include "../../LCommon.h"
#include "../../core/include/mat/LMat.h"
#include <chrono>

using namespace felix::core;

using namespace std;

namespace felix
{

    namespace utils
    {

        LMatf toMatf( const LMatu& img );
        LMatu toMatu( const LMatf& img );
        void addMats( LMatf& dst, const LMatf& other );
        void addNoiseSaltPepper( LMatf& lmat, float percent );

        /** based in this post 
        *   https://stackoverflow.com/questions/17665314/c-get-elapsed-time-platform-independent 
        */
        class LCpuTimer
        {
            private :
            
            chrono::high_resolution_clock::time_point m_timeStart;
            chrono::high_resolution_clock::time_point m_timeStop;

            public :

            LCpuTimer()
            {
                start();
            }

            void start()
            {
                m_timeStart = chrono::high_resolution_clock::now();
            }

            float stop()
            {
                m_timeStop = chrono::high_resolution_clock::now();
                chrono::duration<float> _delta = 
                            chrono::duration_cast<chrono::duration<float>>( m_timeStop - m_timeStart );

                return _delta.count();
            }
        };
    }





}