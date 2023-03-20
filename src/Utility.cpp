//
// Created by Yifan Yang on 2023-03-20.

#include "Utility.h"

int Utility::checkCongestion(const std::vector<Flight>& flights) {
    int sum = 0;
    for (auto & flight : flights) {
        sum++;
    }
    return sum;
}

bool Utility::checkLoc(Flight flight) {
    if (flight.getPositionX() > 0 && flight.getPositionX() <= BORDER_X
        && flight.getPositionY() > 0 && flight.getPositionY() <= BORDER_Y
        && flight.getPositionZ() >= BOTTOM_HEIGHT && flight.getPositionZ() <= (BOTTOM_HEIGHT + BORDER_Z))
        return true;
    else
        return false;
}

bool Utility::checkViolation(Flight flight1, Flight flight2) {
    float deltaX = abs(flight1.getPositionX() - flight2.getPositionX());
    float deltaY = abs(flight1.getPositionY() - flight2.getPositionY());
    float deltaZ = abs(flight1.getPositionZ() - flight2.getPositionZ());

    if (deltaX < MINIMUM_X || deltaY < MINIMUM_Y || deltaZ < MINIMUM_Z)
        return true;
    else
        return false;
}

