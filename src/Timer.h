//
// Created by Yifan Yang on 3/19/2023.
//

#ifndef ATC_TIMER_H
#define ATC_TIMER_H
#include <chrono>

class Timer {
private:
    std::chrono::time_point<std::chrono::system_clock> t0;
public:
    Timer() { start(); }

    void start() { t0 = std::chrono::system_clock::now(); }
    void restart() { start(); }
    auto setIntervalSeconds(int i) {return std::chrono::seconds(i); }
    auto setIntervalMinutes(int i) {return std::chrono::minutes(i); }
    template <class T> T elapsed() {
        std::chrono::duration<T> elapsed_seconds = std::chrono::system_clock::now() - t0;
        return elapsed_seconds.count();
    }
};
#endif //ATC_TIMER_H
