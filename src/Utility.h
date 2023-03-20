//
// Created by Yifan Yang on 2023-03-20.
//

#ifndef ATC_UTILITY_H
#define ATC_UTILITY_H

#include <cstdlib>
#include <vector>

#include "Flight.h"
#include "Constants.h"

class Utility {
public:
    static int checkCongestion(const std::vector<Flight>& flights);
    static bool checkLoc(Flight flight);
    static bool checkViolation(Flight flight1, Flight flight2);
};


#endif //ATC_UTILITY_H
