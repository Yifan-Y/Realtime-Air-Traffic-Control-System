//
// Created by Yifan Yang on 2023-03-22.
//
#include <iostream>
#include <vector>

#include "Flight.h"
#include "Threads.h"
#include "Utility.h"
#include "Controller.h"

// The functions that will be executed by the thread
void Threads::enRoute(std::vector<Flight>& flights, int index) {
    while (index < flights.size() && !flights[index].isTerminated()) {
        if (Utility::checkLoc(flights[index])) {
            Flight::enRoute(flights[index]);
        } else {
            flights[index].setTerminated();
            flights.erase(flights.begin() + index);
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Threads::logEvery30Sec(std::vector<Flight>& flights) {
    while (!flights.empty()) {
        Utility::writeFile(flights);
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
}

void Threads::showStatusEverySecond(std::vector<Flight>& flights) {
    //std::string input;
    while (!flights.empty()) {
        std::cout << "----------------------------------------------------------" << std::endl;
        for(const auto & flight : flights) {
                std::cout << flight << std::endl;
        }

        std::cout << "Currently " << Utility::checkFlightNum(flights) << " flight(s) in range" <<std::endl;
        //if (std::cin >> input) {
          //  break;
        //}
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "All flights are out of range. The simulation will be terminating soon." << std::endl;
    Controller::showMenu();

}

void Threads::checkViolation(std::vector<Flight>& flights) {
    while (!flights.empty()) {
        bool violationFlag = false;
        for (int i = 0; i < flights.size(); i++) {
            for (int j = 0; j < flights.size(); j++) {
                if (i == j) {
                    continue;
                } else {
                   if(Utility::checkViolation(flights[i], flights[j]))
                        std::cout << "Warning! " << flights[i].getId()
                            << " and "<< flights[j].getId() << " " <<std::endl;
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Threads::checkSpeed(std::vector<Flight> &flights) {
    while (!flights.empty()) {
        for (auto &flight : flights) {
            if(!Utility::checkSpeed(flight))
                std::cout << "Warning! Check flight: " << flight.getId() << "speed!" << std::endl;
            else
                continue;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Threads::execThreads(std::vector<Flight>& flights) {

    auto now = std::chrono::system_clock::now();

    std::vector<std::thread> flightThreads;
    std::thread logThread(logEvery30Sec, std::ref(flights));
    std::thread showStatusEverySecondThread(showStatusEverySecond, std::ref(flights));
    //std::thread checkViolationThread(checkViolation, std::ref(flights));
    //std::thread checkSpeedThread(checkSpeed, std::ref(flights));

    // Add flights to the thread vector
    for (int i = 0; i < flights.size(); i++) {
        float wait_time = flights[i].getTime();
        int wait_time_ms = Utility::secondToMillisecond(wait_time);
        auto start_time = now + std::chrono::milliseconds (wait_time_ms);
        std::this_thread::sleep_until(start_time);
        flightThreads.emplace_back(enRoute, std::ref(flights), i);
    }

    // Wait for all planes (threads) to finish
    for (auto & thread : flightThreads) {
        thread.join();
    }

    logThread.join();
    showStatusEverySecondThread.join();
    //checkViolationThread.join();
    //checkSpeedThread.join();

}

void Threads::endAllThreads() {
    std::terminate();
}

