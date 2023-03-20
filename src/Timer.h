//
// Created by Yifan Yang on 3/19/2023.
//

#ifndef ATC_TIMER_H
#define ATC_TIMER_H
#include <chrono>
#include <utility>

class Timer {
private:
    std::chrono::time_point<std::chrono::system_clock> t0;
public:
    Timer() { start(); }

    void start() { t0 = std::chrono::system_clock::now(); }
    void restart() { start(); }

    template <class T> T elapsed() {
        std::chrono::duration<T> elapsed_seconds = std::chrono::system_clock::now() - t0;
        return elapsed_seconds.count();
    }
};
#endif //ATC_TIMER_H
