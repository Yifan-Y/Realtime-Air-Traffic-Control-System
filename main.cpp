#include <iostream>
#include <vector>

#include "src/Constants.h"
#include "src/Flight.h"
#include "src/Utility.h"
#include "src/Timer.h"
#include "src/Threads.h"


int main() {

    std::vector<Flight> flights = Utility::readFile("../input/example.txt");

    Threads::execThreads(flights);

    return 0;
}