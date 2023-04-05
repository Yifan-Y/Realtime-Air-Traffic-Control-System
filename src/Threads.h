//
// Created by Yifan Yang on 2023-03-22.
// Functions for threads

#ifndef ATC_THREADS_H
#define ATC_THREADS_H

#include <thread>
#include "Flight.h"

class Threads{
public:
    static void enRoute(std::vector<Flight>& flights, int index);
    static void logEvery30Sec(std::vector<Flight>& flights);
    static void execThreads(std::vector<Flight>& flights);
    static void showStatusEvery5Second(std::vector<Flight>& flights);
    static void checkSpeed(std::vector<Flight>& flights);
    static void checkViolation(std::vector<Flight>& flights);
    static void endAllThreads();
};

#endif //ATC_THREADS_H
