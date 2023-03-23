//
// Created by Yifan Yang on 2023-03-22.
//

#ifndef ATC_THREADS_H
#define ATC_THREADS_H

#include <thread>
#include "Flight.h"

class Threads{
public:
    static void execThreads(std::vector<Flight> flights);
    void addThread();
    void removeThread();
};

#endif //ATC_THREADS_H
