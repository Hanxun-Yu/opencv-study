//
// Created by wsyuhx on 2021/8/3.
//

#ifndef OPENCV_STUDY_TIMEHELPER_HPP
#define OPENCV_STUDY_TIMEHELPER_HPP

#include <chrono>

#ifdef __linux__
#include <sys/time.h>
#endif

#ifdef _WIN32
#include <sys/timeb.h>
#endif


using namespace std::chrono;

class TimeHelper {

public:
    static int64_t getMillisecond() {
#ifdef _WIN32
        struct timeb t;
        ftime(&t);
        return t.time*1000+t.millitm;
#endif

#ifdef __linux__
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return tv.tv_sec * 1000 + tv.tv_usec / 1000;
#endif

    }

    static int32_t getSecond() {
#ifdef _WIN32
        struct timeb t1;
        ftime(&t1);
        return t1.time;
#endif

#ifdef __linux__
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return tv.tv_sec;
#endif
    }

};

void test_time() {
    int64_t start = TimeHelper::getMillisecond();
    int64_t start2 = TimeHelper::getSecond();

    for(int i=0;i<1000000;i++) {
        int j;
    }

    int64_t start3 = TimeHelper::getMillisecond();


    printf("start:%lld\n",start);
    printf("start2:%lld\n",start2);
    printf("start3:%lld\n",start3);
}

#endif //OPENCV_STUDY_TIMEHELPER_HPP
