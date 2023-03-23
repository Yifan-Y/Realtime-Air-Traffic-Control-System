#include <iostream>
#include <thread>
#include <vector>

#include "src/Constants.h"
#include "src/Flight.h"
#include "src/Utility.h"
#include "src/Timer.h"
#include "src/Threads.h"


int main() {

    std::vector<Flight> flights = Utility::readFile("../input/example.txt");

    Timer t;

    for(auto & flight : flights) {
        std::cout << flight << std::endl;
    }

    Threads::execThreads(flights);

    std::cout << t.elapsed<float>() << "s" << std::endl;

    return 0;
}