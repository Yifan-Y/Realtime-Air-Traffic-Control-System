//
// Created by Yifan Yang on 2023-03-22.
//

#ifndef ATC_THREADS_H
#define ATC_THREADS_H

#include <thread>
#include "Flight.h"

class Threads{
public:
    static void enRoute(Flight& flight);
    static void logEvery30Min(std::vector<Flight>& flights);
    static void execThreads(std::vector<Flight> flights);
    static void showStatusEverySecond(std::vector<Flight>& flights);
};

#endif //ATC_THREADS_H
