//
// Created by Yifan Yang on 2023-03-20.
// Controller for the main menu

#ifndef ATC_CONTROLLER_H
#define ATC_CONTROLLER_H

#include "Flight.h"
#include "Utility.h"

class Controller {
public:
    static void showMenu();
    static void startSimulation(int i);
    static void stopSimulation();
    static void restartSimulation();

    void showRadar();
};
#endif //ATC_CONTROLLER_H
