//
// Created by Yifan Yang on 2023-03-22.
//
#include <iostream>
#include <vector>

#include "Flight.h"
#include "Threads.h"

// A function that will be executed by the thread
void myThreadFunction(Flight flight) {
    std::cout << "Hello from flight " << flight.getId() << "!" << std::endl;
}

void Threads::execThreads(std::vector<Flight> flights) {
    std::vector<std::thread> threads;

    // Create 5 threads in a loop
    for (auto & flight : flights) {
        threads.emplace_back(myThreadFunction, flight);
    }

    // Wait for all threads to finish
    for (auto & thread : threads) {
        thread.join();
    }

}