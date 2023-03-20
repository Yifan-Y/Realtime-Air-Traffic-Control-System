#include <iostream>
#include <thread>
#include <vector>
#include <fstream>
#include <sstream>

#include "src/Constants.h"
#include "src/Flight.h"
#include "src/Utility.h"


// A function that will be executed by the thread
void myThreadFunction(Flight flight) {
    std::cout << "Hello from flight " << flight.getId() << "!" << std::endl;
}


int main() {

    std::vector<Flight> flights;
    std::string line;

    std::ifstream inputFile("../example.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
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

    for(auto & flight: flights) {
        std::cout << flight << std::endl;
    }


    std::vector<std::thread> threads;

    // Create 5 threads in a loop
    for (auto & flight : flights) {
            threads.push_back(std::thread(myThreadFunction, flight));
    }

    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}