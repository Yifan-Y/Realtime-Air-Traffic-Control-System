//
// Created by Yifan Yang on 2023-03-20.
//

#ifndef ATC_CONTROLLER_H
#define ATC_CONTROLLER_H

#include "Flight.h"
#include "Utility.h"
#include "Timer.h"

class Controller {
public:
    static void showMenu();
    static void startSimulation(int i);
    static void stopSimulation();
    static void restartSimulation();

    void showRadar();
};
#endif //ATC_CONTROLLER_H
