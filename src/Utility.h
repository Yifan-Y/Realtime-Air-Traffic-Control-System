//
// Created by Yifan Yang on 2023-03-20.
// Functions for utilities

#ifndef ATC_UTILITY_H
#define ATC_UTILITY_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <ctime>

#include "Constants.h"
#include "Flight.h"

class Utility {
public:
    static int checkFlightNum(std::vector<Flight>& flights);
    static bool checkLoc(Flight flight);
    static bool checkViolation(Flight flight1, Flight flight2);
    static bool checkSpeed(Flight flight);
    static float fpmToFps(float fpm);
    static float knotToFps(float knot);
    static float realSpeed(Flight flight);
    static float getRealDistance(Flight flight1, Flight flight2);

    static std::string getCurrentTime();
    static int secondToMillisecond(float second);

    static std::vector<Flight> readFile(const std::string& path);

private:

};


#endif //ATC_UTILITY_H
