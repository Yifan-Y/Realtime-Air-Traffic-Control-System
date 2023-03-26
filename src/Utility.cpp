//
// Created by Yifan Yang on 2023-03-20.

#include "Utility.h"

int Utility::checkFlightNum(std::vector<Flight>& flights) {
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

float Utility::kphToFps(float kph) {
    float fps = kph * 3280.84 / 3600;
    return fps;
}

float Utility::fpsToKph(float fps) {
    float kph = fps * 0.0003048 * 3600 / 1000;
    return kph;
}

float Utility::getRealDistance(Flight flight1, Flight flight2) {
    return sqrt(pow(flight1.getPositionX() - flight2.getPositionX(), 2) +
                pow(flight1.getPositionY() - flight2.getPositionY(), 2) +
                pow(flight1.getPositionZ() - flight2.getPositionZ(), 2));
}

std::vector<Flight> Utility::readFile(std::string path) {

    std::vector<Flight> flights;
    std::string line;

    std::ifstream inputFile(path);

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
    }


    while (std::getline(inputFile, line)) {

        std::string id;
        float positionX, positionY, positionZ, speedX, speedY, speedZ;

        std::istringstream ss(line);

        ss >> id >> positionX >> positionY >> positionZ >> speedX >> speedY >> speedZ;
        Flight flight(id, positionX, positionY, positionZ, speedX, speedY, speedZ);

        if (Utility::checkLoc(flight))
            flights.push_back(flight);
    }
    // Close the file
    inputFile.close();

    return flights;
}

std::string Utility::getCurrentTime() {
    time_t now = time(0);
    char timeBuffer[80];
    strftime(timeBuffer, 80, "%Y-%m-%d_%H-%M-%S", localtime(&now));
    return {timeBuffer};
}

void Utility::writeFile(std::vector<Flight>& flights) {
    std::string timeBuffer = Utility::getCurrentTime();
    std::string filename = std::string("../Output/") + std::string(timeBuffer) + ".cvs";
    std::ofstream outFile(filename.c_str(), std::ios::out);
    if (outFile.is_open()) {
        for (auto &flight : flights) {
            outFile << flight << std::endl;
        }
        outFile.close();
    }
}




