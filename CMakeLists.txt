cmake_minimum_required(VERSION 3.24)
project(ATC)

set(CMAKE_CXX_STANDARD 17)

add_executable(ATC main.cpp src/Flight.cpp src/Flight.h src/Constants.h src/Controller.cpp src/Timer.h src/Utility.cpp src/Utility.h src/Controller.h src/Threads.h src/Threads.cpp)
