//
// Created by Yifan Yang on 2023-03-20.
//

#ifndef ATC_UTILITY_H
#define ATC_UTILITY_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>

#include "Flight.h"
#include "Constants.h"

class Utility {
public:
    static int checkFlightNum(std::vector<Flight>& flights);
    static bool checkLoc(Flight flight);
    static bool checkViolation(Flight flight1, Flight flight2);
    static float kphToFps(float kph);
    static float fpsToKph(float fps);
    static float getRealDistance(Flight flight1, Flight flight2);

    static std::vector<Flight> readFile(std::string path);

private:

};


#endif //ATC_UTILITY_H
