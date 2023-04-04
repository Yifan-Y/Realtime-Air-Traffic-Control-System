//
// Created by Yifan Yang on 2023-03-20.

#include "Utility.h"
#include "Constants.h"


int Utility::checkFlightNum(std::vector<Flight>& flights) {
    int sum = 0;
    for (auto & flight : flights) {
        sum++;
    }
    return sum;
}

bool Utility::checkLoc(Flight flight) {
    if (   flight.getPositionX() >= 0
        && flight.getPositionX() <= BORDER_X
        && flight.getPositionY() >= 0
        && flight.getPositionY() <= BORDER_Y
        && flight.getPositionZ() >= BOTTOM_HEIGHT
        && flight.getPositionZ() <= (BOTTOM_HEIGHT + BORDER_Z))
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

float Utility::fpmToFps(float fpm) {
    return fpm / 60;
}

float Utility::getRealDistance(Flight flight1, Flight flight2) {
    return sqrt(pow(flight1.getPositionX() - flight2.getPositionX(), 2) +
                pow(flight1.getPositionY() - flight2.getPositionY(), 2) +
                pow(flight1.getPositionZ() - flight2.getPositionZ(), 2));
}

std::vector<Flight> Utility::readFile(const std::string& path) {

    std::vector<Flight> flights;
    std::string line;

    std::ifstream inputFile(path);

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
    }

    while (std::getline(inputFile, line)) {

        float time;
        std::string id;
        float positionX, positionY, positionZ, speedX, speedY, speedZ;

        std::istringstream ss(line);

        ss >> time >> id >> positionX >> positionY >> positionZ >> speedX >> speedY >> speedZ;
        Flight flight(time, id, positionX, positionY, positionZ, speedX, speedY, speedZ);

        flights.push_back(flight);
    }
    // Close the file
    inputFile.close();

    return flights;
}

std::string Utility::getCurrentTime() {
    time_t now = time(nullptr);
    char timeBuffer[80];
    strftime(timeBuffer, 80, "%Y-%m-%d_%H-%M-%S", localtime(&now));
    return {timeBuffer};
}

void Utility::writeFile(std::vector<Flight>& flights) {
    std::string timeBuffer = Utility::getCurrentTime();
    std::string filename = std::string("../Output/") + std::string(timeBuffer) + ".cvs";
    std::ofstream outFile(filename.c_str(), std::ios::out);
    if (outFile.is_open()) {
        outFile << "FlightID  X_Position  Y_Position  Z_Position  X_Speed  Y_Speed  Z_Speed" << std::endl;
        for (auto &flight : flights) {
            outFile << flight << std::endl;
        }
        outFile << "-------------------------------------------------------------------------------------" << std::endl;
        outFile << "* This file was automatically generated at: " << timeBuffer << std::endl;
        outFile.close();
    }
}

int Utility::secondToMillisecond(float second) {
    int res = second * 1000;
    return res;
}

bool Utility::checkSpeed(Flight flight) {
    bool speedFlag = false;
    if (flight.getSpeedX() > MAX_SPEED ||
        flight.getSpeedY() > MAX_SPEED ||
        flight.getSpeedZ() > MAX_ALT_CHANGE_RATE ||
        flight.getSpeedX() < MIN_SPEED ||
        flight.getSpeedY() < MIN_SPEED)
        speedFlag = true;
    return speedFlag;
}

float Utility::knotToFps(float knot) {
    return knot * 1.68781;
}




