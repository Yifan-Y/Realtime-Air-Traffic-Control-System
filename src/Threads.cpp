//
// Created by Yifan Yang on 2023-03-22.
//
#include <iostream>
#include <vector>

#include "Flight.h"
#include "Threads.h"
#include "Utility.h"



// The functions that will be executed by the thread
void Threads::enRoute(Flight &flight) {
    while (true) {
        Flight::enRoute(flight);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Threads::logEvery30Min(std::vector<Flight>& flights) {
    while (true) {
        Utility::writeFile(flights);
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
}

void Threads::showStatusEverySecond(std::vector<Flight>& flights) {
    while (true) {
        for(auto & flight : flights) {
            std::cout << flight << std::endl;
        }
        std::cout << "----------------------------------------------------------" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Threads::execThreads(std::vector<Flight> flights) {

    std::vector<std::thread> threads;
    std::thread logThread;

    // Add threads to the thread vector
    for (auto & flight : flights) {
        threads.emplace_back(enRoute, std::ref(flight));
    }
    threads.emplace_back(logEvery30Min, std::ref(flights));
    threads.emplace_back(showStatusEverySecond, std::ref(flights));

    // Wait for all threads to finish
    for (auto & thread : threads) {
        thread.join();
    }

}




