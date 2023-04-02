//
// Created by Yifan Yang on 3/19/2023.

//
#include "Controller.h"
#include "Threads.h"
#include "Flight.h"

void Controller::showMenu() {
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Hello! Welcome to the real-time air traffic control system!" << std::endl;
    std::cout << "Please select from options provided below:" << std::endl;
    std::cout << "1 - Start Simulation (10 flights maximum)" << std::endl;
    std::cout << "2 - Start simulation (20 flights maximum)" << std::endl;
    std::cout << "3 - Start simulation (50 flights maximum)" << std::endl;
    int option;
    std::cin >> option;
    switch (option) {
        case 1: {
            startSimulation(1);
            break;
        }
        case 2: {
            startSimulation(2);
            break;
        }
        case 3: {
            startSimulation(3);
            break;
        }
        default:
            std::cout << "Invalid input!" << std::endl;
    }
}

void Controller::startSimulation(int i) {
    switch (i) {
        case 1:
        {
            std::vector<Flight> flights = Utility::readFile("../Input/Input1.txt");
            Threads::execThreads(flights);
            break;
        }
        case 2:
        {
            std::vector<Flight> flights = Utility::readFile("../Input/Input2.txt");
            Threads::execThreads(flights);
            break;
        }
        case 3: {
            std::vector<Flight> flights = Utility::readFile("../Input/Input3.txt");
            Threads::execThreads(flights);
            break;
        }
        default:
            break;
    }

}

void Controller::stopSimulation() {
    Threads::endAllThreads();
}

void Controller::restartSimulation() {

}

