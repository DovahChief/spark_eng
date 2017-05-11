//
// Created by jose on 10/05/17.
//
#pragma once
#include <sys/time.h>

namespace spark{

    class timer{

    private:
        timeval m_last;
        timeval now;

    public:
        timer(){}
        void reset(){
            gettimeofday(&m_last, nullptr);
        }
        double get_diff(){
            gettimeofday(&now, nullptr);
            return ((now.tv_sec - m_last.tv_sec));
        }
        double get_diff_ms(){
            gettimeofday(&now, nullptr);
            return ((now.tv_usec - m_last.tv_usec) / 1000);
        }

    };

}
