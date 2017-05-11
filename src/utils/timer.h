//
// Created by jose on 10/05/17.
//
#pragma once
#include <sys/time.h>
#include <ctime>


namespace spark{

    class timer{

    private:
        timeval m_last;
        timeval now;
        std::time_t start;
    public:
        timer(){}
        void reset(){
            start = std::time(NULL);
            gettimeofday(&m_last, nullptr);
        }
        double get_diff(){
            return ((now.tv_sec - m_last.tv_sec) );
        }
        double get_sec(){
            return (std::difftime(std::time(NULL), start));
        }
    };

}
